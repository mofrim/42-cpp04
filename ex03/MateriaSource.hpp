
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 08:19:34 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/10 08:22:40 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource: virtual public IMateriaSource
{
  private:
    AMateria *materias[4];
    int       idx;

    AMateria **gc;
    size_t     gc_idx;

    void       _addGarbage(AMateria *g);
    void       _collectGarbage();
    AMateria **_copyGC(AMateria **othergc, size_t other_gcidx);

  public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);
    virtual ~MateriaSource();

    void      learnMateria(AMateria *m);
    AMateria *createMateria(std::string const& type);
};

#endif
