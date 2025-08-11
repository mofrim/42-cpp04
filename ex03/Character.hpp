/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:15:10 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/11 15:10:49 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

#include <string>

class Character: public ICharacter
{
  private:
    std::string name;
    int         inv_idx;
    AMateria   *inv[4];

    AMateria **gc;
    size_t     gc_idx;

    void       _addGarbage(AMateria *g);
    void       _collectGarbage();
    AMateria **_copyGC(AMateria **othergc, size_t other_gcidx);

  public:
    Character();
    Character(const Character& other);
    Character& operator=(const Character& other);
    ~Character();

    // extra constructor
    Character(const std::string& cname);

    std::string const& getName() const;
    void               equip(AMateria *m);
    void               unequip(int idx);
    void               use(int idx, ICharacter& target);
};

#endif
