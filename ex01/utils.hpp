/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:38:44 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/04 21:47:13 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

#ifndef DEBUG
#define DEBUG 1
#endif

void        dbg_msg(const std::string& name, const std::string& msg);
std::string get_prefix(const std::string& type, const std::string& name);
void        newline();

#endif
