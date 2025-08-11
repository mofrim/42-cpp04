/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 22:11:42 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/06 20:45:39 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "utils.hpp"

#include <iostream>

Dog::Dog(): Animal()
{
  dbg_msg("Dog", "Default Constructor called");
  this->type  = "Dog";
}

Dog::Dog(const Dog& other): Animal(other)
{
  dbg_msg("Dog", "Copy Constructor called");
  this->type  = other.type;
}

Dog& Dog::operator=(const Dog& other)
{
  dbg_msg("Dog", "Copy-Assignment Constructor called");
  this->type  = other.type;
  return (*this);
}

Dog::~Dog() { dbg_msg("Dog", "Destructor called."); }

void Dog::makeSound() const
{
  std::cout << "(" << this->type << ") " << "woof! woof!" << std::endl;
}
