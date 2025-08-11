/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 21:48:17 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/11 14:42:18 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "utils.hpp"

#include <iostream>

Cure::Cure(): AMateria()
{
  this->type = "cure";
  dbg_msg("Cure", "Default Construtor called.");
}

Cure::Cure(const Cure& other): AMateria(other)
{
  dbg_msg("Cure", "Copy Construtor called.");
}

Cure& Cure::operator=(const Cure& other)
{
  (void)other;
  dbg_msg("Cure", "Copy-Assignment Construtor called.");
  return (*this);
}

Cure::~Cure() { dbg_msg("Cure", "Destructor called."); }

void Cure::use(ICharacter& target)
{
  std::cout << "  * heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria *Cure::clone() const
{
  Cure *c = new Cure(*this);
  return (c);
}
