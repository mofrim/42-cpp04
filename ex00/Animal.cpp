/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:42:47 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/06 20:48:47 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "utils.hpp"

#include <iostream>

Animal::Animal(): type("Animal")
{
  dbg_msg("Animal", "Default Constructor called");
}

Animal::Animal(const Animal& other): type(other.type)
{
  dbg_msg("Animal", "Copy Constructor called");
}

Animal& Animal::operator=(const Animal& other)
{
  dbg_msg("Animal", "Copy-Assignment Constructor called");
  this->type = other.type;
  return (*this);
}

Animal::~Animal() { dbg_msg("Animal", "Destructor called."); }

std::string Animal::getType() const { return (this->type); }

void Animal::setType(const std::string& newType) { this->type = newType; }

void Animal::makeSound() const
{
  std::cout << "(" << this->type << ") " << "..." << std::endl;
}
