/* ************************************************************************** */ /*                                                                            */
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

Animal::Animal(): brain(NULL), type("Animal")
{
  dbg_msg("Animal", "Default Constructor called");
}

Animal::Animal(const Animal& other): type(other.type)
{
  dbg_msg("Animal", "Copy Constructor called");
  // if (other.brain != NULL)
  // {
  //   if (this->brain != NULL)
  //     *this->brain = *other.brain;
  //   else
  //     this->brain = new Brain(*other.brain);
  // }
}

Animal& Animal::operator=(const Animal& other)
{
  dbg_msg("Animal", "Copy-Assignment Constructor called");
  this->type = other.type;
  // if (other.brain != NULL)
  // {
  //   if (this->brain != NULL)
  //     *this->brain = *other.brain;
  //   else
  //     this->brain = new Brain(*other.brain);
  // }
  return (*this);
}

Animal::~Animal()
{
  dbg_msg("Animal", "Destructor called.");
  // if (this->brain != NULL)
  //   delete this->brain;
}

std::string Animal::getType() const { return (this->type); }

void Animal::setType(const std::string& newType) { this->type = newType; }

// void Animal::makeSound() const
// {
//   std::cout << "(" << this->type << ") " << "..." << std::endl;
// }
//
// void Animal::newIdea(const std::string& idea) { this->brain->addIdea(idea); }
//
// void Animal::showIdeas() { this->brain->printIdeas(); };
