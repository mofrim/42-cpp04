/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:08:48 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/11 15:59:40 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

// my slightly modified version in order to maximize memmgmt cleanliness
class AMateria
{
  private:
    bool _isOwned;

  protected:
    std::string _type;

  public:
    AMateria();
    AMateria(const AMateria& other);
    AMateria& operator=(const AMateria& other);
    virtual ~AMateria();

    std::string const& getType() const;
    virtual AMateria  *clone() const = 0;
    virtual void       use(ICharacter& target);
    void               own();
    void               unOwn();
    bool               isOwned();
};

#endif
