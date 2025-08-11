/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 22:11:42 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/06 20:55:25 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "utils.hpp"

#include <iostream>

WrongCat::WrongCat(): WrongAnimal()
{
  dbg_msg("WrongCat", "Default Constructor called");
  this->type  = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other)
{
  dbg_msg("WrongCat", "Copy Constructor called");
  this->type  = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
  dbg_msg("WrongCat", "Copy-Assignment Constructor called");
  this->type  = other.type;
  return (*this);
}

WrongCat::~WrongCat() { dbg_msg("WrongCat", "Destructor called."); }

void WrongCat::makeSound() const
{
  std::cout << "(" << this->type << ") " << "miau! krrchch!" << std::endl;
}
