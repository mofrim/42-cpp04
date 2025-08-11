/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:25:40 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/11 14:53:32 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "utils.hpp"

#include <iostream>

AMateria::AMateria(): type("none")
{
  dbg_msg("AMateria", "Default Constructor called.");
  this->_isOwned = false;
}

AMateria::AMateria(const AMateria& other)
{
  dbg_msg("AMateria", "Copy Constructor called.");
  this->_isOwned = other._isOwned;
}

AMateria& AMateria::operator=(const AMateria& other)
{
  dbg_msg("AMateria", "Copy-Assignment Constructor called.");
  this->_isOwned = other._isOwned;
  return (*this);
}

AMateria::~AMateria() { dbg_msg("AMateria", "Destructor called."); }

std::string const& AMateria::getType() const { return (type); }

void AMateria::use(ICharacter& target) { (void)target; }

void AMateria::own() { this->_isOwned = true; }

bool AMateria::isOwned() { return (this->_isOwned); }
