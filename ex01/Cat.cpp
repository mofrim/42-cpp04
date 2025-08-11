/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 22:11:42 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/07 11:48:33 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Cat.hpp"
#include "utils.hpp"

#include <iostream>

Cat::Cat(): Animal()
{
  dbg_msg("Cat", "Default Constructor called");
  this->type  = "Cat";
  this->brain = new Brain();
}

Cat::Cat(const Cat& other): Animal(other)
{
  dbg_msg("Cat", "Copy Constructor called");
  this->type   = other.type;
  *this->brain = *other.brain;
}

Cat& Cat::operator=(const Cat& other)
{
  dbg_msg("Cat", "Copy-Assignment Constructor called");
  this->type   = other.type;
  *this->brain = *other.brain;
  return (*this);
}

Cat::~Cat()
{
  delete this->brain;
  dbg_msg("Cat", "Destructor called.");
}

void Cat::makeSound() const
{
  std::cout << "(" << this->type << ") " << "miau! krrchch!" << std::endl;
}

void Cat::newIdea(const std::string& idea) { this->brain->addIdea(idea); }

void Cat::showIdeas() { this->brain->printIdeas(); };
