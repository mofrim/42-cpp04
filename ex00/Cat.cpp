/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 22:11:42 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/06 20:47:42 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "utils.hpp"

#include <iostream>

Cat::Cat(): Animal()
{
  dbg_msg("Cat", "Default Constructor called");
  this->type  = "Cat";
}

Cat::Cat(const Cat& other): Animal(other)
{
  dbg_msg("Cat", "Copy Constructor called");
  this->type  = other.type;
}

Cat& Cat::operator=(const Cat& other)
{
  dbg_msg("Cat", "Copy-Assignment Constructor called");
  this->type  = other.type;
  return (*this);
}

Cat::~Cat() { dbg_msg("Cat", "Destructor called."); }

void Cat::makeSound() const
{
  std::cout << "(" << this->type << ") " << "miau! krrchch!" << std::endl;
}
