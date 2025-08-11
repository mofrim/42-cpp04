/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:42:47 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/11 16:17:19 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "utils.hpp"

#include <iostream>

Animal::Animal(): _type("Animal")
{
  dbg_msg("Animal", "Default Constructor called");
}

Animal::Animal(const Animal& other): _type(other._type)
{
  dbg_msg("Animal", "Copy Constructor called");
}

Animal& Animal::operator=(const Animal& other)
{
  dbg_msg("Animal", "Copy-Assignment Constructor called");
  this->_type = other._type;
  return (*this);
}

Animal::~Animal() { dbg_msg("Animal", "Destructor called."); }

std::string Animal::getType() const { return (this->_type); }

void Animal::setType(const std::string& newType) { this->_type = newType; }

void Animal::makeSound() const
{
  std::cout << "(" << this->_type << ") " << "..." << std::endl;
}
