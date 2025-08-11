/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 21:47:28 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/11 14:52:04 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

// the same as for Cure: making the destructor private so Ice can also never be
// initialised on the stack which could lead to segfault scenarios like this:
//
//    Character foo("foo");
//    Character bar("bar")
//    {
//      Cure c;
//      foo.equip(c);
//    }
//    foo.use(0, bar);
//
class Ice: virtual public AMateria
{
  private:
    Ice(const Ice& other);
    Ice& operator=(const Ice& other);
    ~Ice();

  public:
    Ice();

    AMateria *clone() const;
    void      use(ICharacter& target);
};

#endif
