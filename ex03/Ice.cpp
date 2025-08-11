/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 21:48:17 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/11 16:04:43 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "utils.hpp"

#include <iostream>

Ice::Ice(): AMateria()
{
  this->_type = "ice";
  dbg_msg("Ice", "Default Construtor called.");
}

Ice::Ice(const Ice& other): AMateria(other)
{
  this->_type = other._type;
  dbg_msg("Ice", "Copy Construtor called.");
}

Ice& Ice::operator=(const Ice& other)
{
  this->_type = other._type;
  dbg_msg("Ice", "Copy-Assignment Construtor called.");
  return (*this);
}

Ice::~Ice() { dbg_msg("Ice", "Destructor called."); }

void Ice::use(ICharacter& target)
{
  std::cout << "  * shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}

AMateria *Ice::clone() const
{
  Ice *c = new Ice(*this);
  return (c);
}
