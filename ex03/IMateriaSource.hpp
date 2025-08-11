/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 08:19:34 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/10 21:04:22 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource
{
  public:
    IMateriaSource();
    IMateriaSource(const IMateriaSource& other);
    IMateriaSource& operator=(const IMateriaSource& other);
    virtual ~IMateriaSource();

    virtual void      learnMateria(AMateria *)               = 0;
    virtual AMateria *createMateria(std::string const& type) = 0;
};

#endif
