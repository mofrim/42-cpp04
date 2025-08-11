/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 06:59:33 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/11 09:38:44 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "utils.hpp"

Character::Character(): ICharacter(), name("noname"), inv_idx(0)
{
  dbg_msg("Character " + this->name, "Default Constructor called.");
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
  }
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
}

Character::Character(const std::string& cname):
  ICharacter(), name(cname), inv_idx(0)
{
  dbg_msg("Character " + this->name, "Default-Name Constructor called.");
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
        this->inv[i] = m;
    return;
  }
  this->inv[inv_idx] = m;
  this->inv_idx++;
}

void Character::unequip(int idx)
{
  if (0 <= idx && idx <= 3)
    this->inv[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
  if (0 <= idx && idx <= 3 && this->inv[idx] != NULL)
    this->inv[idx]->use(target);
}
