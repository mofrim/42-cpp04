/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 08:20:59 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/10 17:59:18 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "utils.hpp"

IMateriaSource::IMateriaSource()
{
  dbg_msg("IMateriaSource", "Default Constructor called.");
}

IMateriaSource::IMateriaSource(const IMateriaSource& other)
{
  (void)other;
  dbg_msg("IMateriaSource", "Copy Constructor called.");
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource& other)
{
  (void)other;
  dbg_msg("IMateriaSource", "Copy-Assignment Constructor called.");
  return (*this);
}

IMateriaSource::~IMateriaSource()
{
  dbg_msg("IMateriaSource", "Destructor called.");
}
