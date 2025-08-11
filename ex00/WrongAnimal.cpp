/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:42:47 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/06 20:50:45 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "utils.hpp"

#include <iostream>

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
  dbg_msg("WrongAnimal", "Default Constructor called");
}

WrongAnimal::WrongAnimal(const WrongAnimal& other): type(other.type)
{
  dbg_msg("WrongAnimal", "Copy Constructor called");
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
  dbg_msg("WrongAnimal", "Copy-Assignment Constructor called");
  this->type = other.type;
  return (*this);
}

WrongAnimal::~WrongAnimal() { dbg_msg("WrongAnimal", "Destructor called."); }

std::string WrongAnimal::getType() const { return (this->type); }

void WrongAnimal::setType(const std::string& newType) { this->type = newType; }

void WrongAnimal::makeSound() const
{
  std::cout << "(" << this->type << ") " << "..." << std::endl;
}
