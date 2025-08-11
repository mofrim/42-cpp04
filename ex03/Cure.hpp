/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 21:47:28 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/11 09:34:19 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

// making useless constructors private here. but more importantly: also making
// the destructor private! That leads to this class not being instantiable on
// the stack because the compiler needs to be able to call the destructor!!!
class Cure: virtual public AMateria
{
  private:
    Cure(const Cure& other);
    Cure& operator=(const Cure& other);

  public:
    Cure();
    ~Cure();
    AMateria *clone() const;
    void      use(ICharacter& target);
};

#endif
