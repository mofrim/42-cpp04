/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 06:59:33 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/11 16:08:58 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "utils.hpp"

Character::Character(): ICharacter(), _name("noname"), _inv_idx(0), _gc_idx(0)
{
  dbg_msg("Character " + this->_name, "Default Constructor called.");
  this->_gc = NULL;
  for (size_t i = 0; i < 4; i++)
    this->_inv[i] = NULL;
}

Character::Character(const Character& other):
  ICharacter(other), _name(other._name), _inv_idx(other._inv_idx)
{
  dbg_msg("Character " + this->_name, "Copy Constructor called.");
  for (size_t i = 0; i < 4; i++)
  {
    if (other._inv[i])
      this->_inv[i] = other._inv[i]->clone();
    else
      this->_inv[i] = other._inv[i];
  }

  this->_gc     = this->_copyGC(other._gc, other._gc_idx);
  this->_gc_idx = other._gc_idx;
}

Character& Character::operator=(const Character& other)
{
  dbg_msg("Character " + this->_name, "Copy-Assignment Constructor called.");
  this->_name    = other._name;
  this->_inv_idx = other._inv_idx;
  for (size_t i = 0; i < 4; i++)
  {
    delete this->_inv[i];
    if (other._inv[i])
      this->_inv[i] = other._inv[i]->clone();
    else
      this->_inv[i] = NULL;
  }

  // delete and copy gc from other
  this->_collectGarbage();
  this->_gc     = this->_copyGC(other._gc, other._gc_idx);
  this->_gc_idx = other._gc_idx;

  return (*this);
}

Character::~Character()
{
  dbg_msg("Character " + this->_name, "Destructor called.");
  for (size_t i = 0; i < 4; i++)
    if (this->_inv[i])
    {
      delete this->_inv[i];
      this->_inv[i] = NULL;
    }
  this->_collectGarbage();
}

Character::Character(const std::string& cname):
  ICharacter(), _name(cname), _inv_idx(0), _gc_idx(0)
{
  dbg_msg("Character " + this->_name, "Default-Name Constructor called.");
  this->_gc = NULL;
  for (size_t i = 0; i < 4; i++)
    this->_inv[i] = NULL;
}

std::string const& Character::getName() const { return (this->_name); }

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
  if (m->isOwned())
    return;
  if (this->_inv_idx == 4)
  {
    for (size_t i = 0; i < 4; i++)
      if (this->_inv[i] == NULL)
      {
        this->_inv[i] = m;
        m->own();
        return;
      }
    this->_addGarbage(m);
    return;
  }
  this->_inv[_inv_idx] = m;
  m->own();
  this->_inv_idx++;
}

void Character::unequip(int idx)
{
  if (0 <= idx && idx <= 3 && this->_inv[idx] != NULL)
  {
    this->_addGarbage(this->_inv[idx]);
    this->_inv[idx] = NULL;
  }
}

void Character::use(int idx, ICharacter& target)
{
  if (0 <= idx && idx <= 3 && this->_inv[idx] != NULL)
    this->_inv[idx]->use(target);
}

// delete all garbage
void Character::_collectGarbage()
{
  if (this->_gc)
  {
    for (size_t i = 0; i < this->_gc_idx; i++)
      delete this->_gc[i];
    delete[] this->_gc;
    this->_gc = NULL;
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
  AMateria **new_gc = new AMateria *[this->_gc_idx + 1];
  size_t     i;

  for (i = 0; i < this->_gc_idx; i++)
    new_gc[i] = this->_gc[i];
  new_gc[i] = g;

  if (this->_gc)
    delete[] this->_gc;
  this->_gc = new_gc;
  this->_gc_idx++;
}
