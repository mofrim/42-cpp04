/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 09:13:56 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/07 12:41:02 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "utils.hpp"

#include <iostream>

Brain::Brain()
{
  dbg_msg("Brain", "Default Constructor called.");
  this->idx = 0;
}

Brain::Brain(const Brain& other)
{
  if (this != &other)
  {
    for (int i = 0; i < 100; i++)
      this->ideas[i] = other.ideas[i];
    this->idx = other.idx;
  }
  dbg_msg("Brain", "Copy Constructor called.");
}

Brain& Brain::operator=(const Brain& other)
{
  if (this != &other)
  {
    for (int i = 0; i < 100; i++)
      this->ideas[i] = other.ideas[i];
    this->idx = other.idx;
  }
  return (*this);
  dbg_msg("Brain", "Copy-Assignment Constructor called.");
}

Brain::~Brain() { dbg_msg("Brain", "Destructor called."); }

void Brain::addIdea(const std::string& idea)
{
  this->ideas[idx] = idea;
  this->idx        = (this->idx + 1) % 100;
}

void Brain::printIdeas() const
{
  for (int i = 0; i < 100; i++)
  {
    if (this->ideas[i] != "")
      std::cout << "idea no." << i << ": " << this->ideas[i] << std::endl;
  }
}
