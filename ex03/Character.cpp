/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 06:59:33 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/11 15:42:21 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "utils.hpp"

Character::Character(): ICharacter(), name("noname"), inv_idx(0), gc_idx(0)
{
  dbg_msg("Character " + this->name, "Default Constructor called.");
  this->gc = NULL;
  for (size_t i = 0; i < 4; i++)
    this->inv[i] = NULL;
}

Character::Character(const Character& other):
  ICharacter(other), inv_idx(other.inv_idx)
{
  dbg_msg("Character " + this->name, "Copy Constructor called.");
  this->name = other.name;
  for (size_t i = 0; i < 4; i++)
  {
    if (other.inv[i])
      this->inv[i] = other.inv[i]->clone();
    else
      this->inv[i] = other.inv[i];
  }

  // delete and copy gc from other
  this->_collectGarbage();
  this->gc     = this->_copyGC(other.gc, other.gc_idx);
  this->gc_idx = other.gc_idx;
}

Character& Character::operator=(const Character& other)
{
  dbg_msg("Character " + this->name, "Copy-Assignment Constructor called.");
  this->name    = other.name;
  this->inv_idx = other.inv_idx;
  for (size_t i = 0; i < 4; i++)
  {
    delete this->inv[i];
    if (other.inv[i])
      this->inv[i] = other.inv[i]->clone();
    else
      this->inv[i] = NULL;
  }

  // delete and copy gc from other
  this->_collectGarbage();
  this->gc     = this->_copyGC(other.gc, other.gc_idx);
  this->gc_idx = other.gc_idx;

  return (*this);
}

Character::~Character()
{
  dbg_msg("Character " + this->name, "Destructor called.");
  for (size_t i = 0; i < 4; i++)
    if (this->inv[i])
    {
      delete this->inv[i];
      this->inv[i] = NULL;
    }
  this->_collectGarbage();
}

Character::Character(const std::string& cname):
  ICharacter(), name(cname), inv_idx(0), gc_idx(0)
{
  dbg_msg("Character " + this->name, "Default-Name Constructor called.");
  this->gc = NULL;
  for (size_t i = 0; i < 4; i++)
    this->inv[i] = NULL;
}

std::string const& Character::getName() const { return (this->name); }

// again the leakiness... either we clone the Materias to our inventory: the
// address is lost if it not kept in the outer scope. or we simply store the
// Materias address in the inventory, but then the deletion has to be hanled in
// outer scope. How can we do it about right here?
// The Version with cloning:
//
//    void Character::equip(AMateria *m)
//    {
//      if (this->inv_idx == 4)
//      {
//        for (size_t i = 0; i < 4; i++)
//          if (this->inv[i] == NULL)
//            this->inv[i] = m->clone();
//        return;
//      }
//      this->inv[inv_idx] = m->clone();
//      this->inv_idx++;
//    }
//
// The version running smoother with the example code:
void Character::equip(AMateria *m)
{
  if (this->inv_idx == 4)
  {
    for (size_t i = 0; i < 4; i++)
      if (this->inv[i] == NULL)
      {
        this->inv[i] = m;
        return;
      }
    this->_addGarbage(m);
    return;
  }
  this->inv[inv_idx] = m;
  this->inv_idx++;
}

void Character::unequip(int idx)
{
  if (0 <= idx && idx <= 3 && this->inv[idx] != NULL)
  {
    this->_addGarbage(this->inv[idx]);
    this->inv[idx] = NULL;
  }
}

void Character::use(int idx, ICharacter& target)
{
  if (0 <= idx && idx <= 3 && this->inv[idx] != NULL)
    this->inv[idx]->use(target);
}

// delete all garbage
void Character::_collectGarbage()
{
  if (this->gc)
  {
    for (size_t i = 0; i < this->gc_idx; i++)
      delete this->gc[i];
    delete[] this->gc;
    this->gc = NULL;
  }
}

// copy the other gc by cloneing every gc entry. through this the other gc will
// not be touched if this goes out of scope before the other. this function is
// also used in the gc update process.
AMateria **Character::_copyGC(AMateria **other_gc, size_t other_gcidx)
{
  if (other_gc == NULL)
    return (NULL);
  AMateria **gc_copy = new AMateria *[other_gcidx];
  for (size_t i = 0; i < other_gcidx; i++)
    gc_copy[i] = other_gc[i]->clone();
  return (gc_copy);
}

// add a new AMateria pointer to the end of GC array. would have been nicer with
// vector.
void Character::_addGarbage(AMateria *g)
{
  AMateria **new_gc = new AMateria *[this->gc_idx + 1];
  size_t     i;

  for (i = 0; i < this->gc_idx; i++)
    new_gc[i] = this->gc[i];
  new_gc[i] = g;

  if (this->gc)
    delete[] this->gc;
  this->gc = new_gc;
  this->gc_idx++;
}
