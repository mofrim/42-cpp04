/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:42:47 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/06 20:48:47 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "AAnimal.hpp"
#include "utils.hpp"

AAnimal::AAnimal(): _brain(NULL), _type("AAnimal")
{
  dbg_msg("AAnimal", "Default Constructor called");
}

AAnimal::AAnimal(const AAnimal& other): _type(other._type)
{
  dbg_msg("AAnimal", "Copy Constructor called");
  // if (other.brain != NULL)
  // {
  //   if (this->brain != NULL)
  //     *this->brain = *other.brain;
  //   else
  //     this->brain = new Brain(*other.brain);
  // }
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
  dbg_msg("AAnimal", "Copy-Assignment Constructor called");
  this->_type = other._type;
  // if (other.brain != NULL)
  // {
  //   if (this->brain != NULL)
  //     *this->brain = *other.brain;
  //   else
  //     this->brain = new Brain(*other.brain);
  // }
  return (*this);
}

AAnimal::~AAnimal()
{
  dbg_msg("AAnimal", "Destructor called.");
  // if (this->brain != NULL)
  //   delete this->brain;
}

std::string AAnimal::getType() const { return (this->_type); }

void AAnimal::setType(const std::string& newType) { this->_type = newType; }

// void AAnimal::makeSound() const
// {
//   std::cout << "(" << this->type << ") " << "..." << std::endl;
// }
//
// void AAnimal::newIdea(const std::string& idea) { this->brain->addIdea(idea);
// }
//
// void AAnimal::showIdeas() { this->brain->printIdeas(); };
