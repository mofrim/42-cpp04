/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:25:40 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/10 21:12:19 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "utils.hpp"

#include <iostream>

AMateria::AMateria(): type("none")
{
  dbg_msg("AMateria", "Default Constructor called.");
}

AMateria::AMateria(const AMateria& other): type(other.type)
{
  dbg_msg("AMateria", "Copy Constructor called.");
}

AMateria& AMateria::operator=(const AMateria& other)
{
  dbg_msg("AMateria", "Copy-Assignment Constructor called.");
  this->type = other.type;
  return (*this);
}

AMateria::~AMateria() { dbg_msg("AMateria", "Destructor called."); }

std::string const& AMateria::getType() const { return (type); }

void AMateria::use(ICharacter& target) { (void)target; }
