/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 22:11:42 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/07 12:38:38 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "utils.hpp"

#include <iostream>

Dog::Dog(): Animal()
{
  dbg_msg("Dog", "Default Constructor called");
  this->type  = "Dog";
  this->brain = new Brain();
}

Dog::Dog(const Dog& other): Animal(other)
{
  dbg_msg("Dog", "Copy Constructor called");
  this->type   = other.type;
  *this->brain = *other.brain;
}

Dog& Dog::operator=(const Dog& other)
{
  dbg_msg("Dog", "Copy-Assignment Constructor called");
  this->type   = other.type;
  *this->brain = *other.brain;
  return (*this);
}

Dog::~Dog()
{
  delete this->brain;
  dbg_msg("Dog", "Destructor called.");
}

void Dog::makeSound() const
{
  std::cout << "(" << this->type << ") " << "woof! woof!" << std::endl;
}

void Dog::newIdea(const std::string& idea) { this->brain->addIdea(idea); }

void Dog::showIdeas() { this->brain->printIdeas(); };
