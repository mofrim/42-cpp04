
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:37:16 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/03 19:06:32 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

#include <iostream>
#include <string>

void dbg_msg(const std::string& name, const std::string& msg)
{
  if (DEBUG)
    std::cout << "[" << name << "] " << msg << std::endl;
}

std::string get_prefix(const std::string& type, const std::string& name)
{
  return ("  " + type + "(" + name + ") ");
}

void newline() { std::cout << std::endl; }
