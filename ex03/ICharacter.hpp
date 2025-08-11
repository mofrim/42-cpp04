/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 22:30:42 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/10 22:57:39 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>

// forward declaration needed here because including header would lead to
// circular inclusion
class AMateria;

class ICharacter
{
  public:
    ICharacter();
    ICharacter(const ICharacter& other);
    virtual ICharacter& operator=(const ICharacter& other);
    virtual ~ICharacter();

    virtual std::string const& getName() const                  = 0;
    virtual void               equip(AMateria *m)               = 0;
    virtual void               unequip(int idx)                 = 0;
    virtual void               use(int idx, ICharacter& target) = 0;
};

#endif
