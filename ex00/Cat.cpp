/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 22:11:42 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/11 16:17:19 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "utils.hpp"

#include <iostream>

Cat::Cat(): Animal()
{
  dbg_msg("Cat", "Default Constructor called");
  this->_type = "Cat";
}

Cat::Cat(const Cat& other): Animal(other)
{
  dbg_msg("Cat", "Copy Constructor called");
  this->_type = other._type;
}

Cat& Cat::operator=(const Cat& other)
{
  dbg_msg("Cat", "Copy-Assignment Constructor called");
  this->_type = other._type;
  return (*this);
}

Cat::~Cat() { dbg_msg("Cat", "Destructor called."); }

void Cat::makeSound() const
{
  std::cout << "(" << this->_type << ") " << "miau! krrchch!" << std::endl;
}
