/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 22:30:42 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/10 18:02:10 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "utils.hpp"

ICharacter::ICharacter()
{
  dbg_msg("ICharacter", "Default Constructor called.");
}
ICharacter::ICharacter(const ICharacter& other)
{
  (void)other;
  dbg_msg("ICharacter", "Copy Constructor called.");
}
ICharacter& ICharacter::operator=(const ICharacter& other)
{
  (void)other;
  dbg_msg("ICharacter", "Copy-Assignment Constructor called.");
  return (*this);
}

ICharacter::~ICharacter() { dbg_msg("ICharacter", "Destructor called."); }
