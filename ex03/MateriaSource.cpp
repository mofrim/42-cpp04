
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 08:20:59 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/10 08:23:17 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "utils.hpp"

MateriaSource::MateriaSource(): IMateriaSource(), idx(0), gc_idx(0)
{
  dbg_msg("MateriaSource", "Default Constructor called.");
  this->gc = NULL;
  for (size_t i = 0; i < 4; i++)
    this->materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other):
  IMateriaSource(other), idx(other.idx)
{
  dbg_msg("MateriaSource", "Copy Constructor called.");
  for (size_t i = 0; i < 4; i++)
    this->materias[i] = other.materias[i]->clone();
  this->gc     = this->_copyGC(other.gc, other.gc_idx);
  this->gc_idx = other.gc_idx;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
  dbg_msg("MateriaSource", "Copy-Assignment Constructor called.");
  for (size_t i = 0; i < 4; i++)
  {
    if (this->materias[i])
      delete this->materias[i];
    this->materias[i] = other.materias[i];
  }
  this->idx = other.idx;

  // delete and copy gc from other
  this->_collectGarbage();
  this->gc     = this->_copyGC(other.gc, other.gc_idx);
  this->gc_idx = other.gc_idx;
  return (*this);
}

MateriaSource::~MateriaSource()
{
  dbg_msg("MateriaSource", "Destructor called.");
  for (size_t i = 0; i < 4; i++)
    if (this->materias[i])
    {
      delete this->materias[i];
      this->materias[i] = NULL;
    }
  this->_collectGarbage();
}

// this is little bit the _crux_ of the exercise. either we store the new
// Materias in memory by allocating them on the heap by using somehting like
// this:
//
//    AMateria *new_m           = m->clone();
//    this->materias[this->idx] = new_m;
//
// but then we would loose any Materia that we learned by someway like this
//
//    src->learnMateria(new Cure());
//
// One way to fix this could be by cloning and deleting the Materia we learned.
// But that might have unwanted consequences if the Materia still would be in
// use in the outer scope. The following snippet would segfault with the delete
// variant.
//
//    IMateriaSource *srcA = new MateriaSource();
//    IMateriaSource *srcB = new MateriaSource();
//    AMateria       *c    = new Cure();
//    srcA->learnMateria(c);
//    srcB->learnMateria(c); // BOOOM! Segfault!
//
// but it also fails with the non-deleting variant but if *c is deleted
// first :/ so, what shall we do here?
//
//    IMateriaSource *srcA = new MateriaSource();
//    IMateriaSource *srcB = new MateriaSource();
//    AMateria       *c    = new Cure();
//    srcA->learnMateria(c);
//    srcB->learnMateria(c);
//    delete c;
//    delete srcA; // BOOOM! AGAIN! Segault
//    delete srcB;
//
// SOLUTION: introduce ownership.
void MateriaSource::learnMateria(AMateria *m)
{

  if (m->isOwned())
    return;
  if (this->idx == 4)
  {
    this->_addGarbage(m);
    m->own();
    return;
  }
  this->materias[this->idx] = m;
  m->own();
  this->idx++;
}

AMateria *MateriaSource::createMateria(std::string const& type)
{
  for (size_t i = 0; i < 4; i++)
  {
    if (this->materias[i] && this->materias[i]->getType() == type)
    {
      AMateria *cloned = this->materias[i]->clone();
      cloned->unOwn();
      return (cloned);
    }
  }
  return (NULL);
}

// delete all garbage
void MateriaSource::_collectGarbage()
{
  if (this->gc)
  {
    for (size_t i = 0; i < this->gc_idx; i++)
      delete this->gc[i];
    delete[] this->gc;
    this->gc = NULL;
  }
}

// copy the other gc by cloneing every gc entry. through this the other gc will
// not be touched if this goes out of scope before the other. this function is
// also used in the gc update process.
AMateria **MateriaSource::_copyGC(AMateria **other_gc, size_t other_gcidx)
{
  if (other_gc == NULL)
    return (NULL);
  AMateria **gc_copy = new AMateria *[other_gcidx];
  for (size_t i = 0; i < other_gcidx; i++)
    gc_copy[i] = other_gc[i]->clone();
  return (gc_copy);
}

// add a new AMateria pointer to the end of GC array. would have been nicer with
// vector.
void MateriaSource::_addGarbage(AMateria *g)
{
  AMateria **new_gc = new AMateria *[gc_idx + 1];
  size_t     i;

  for (i = 0; i < this->gc_idx; i++)
    new_gc[i] = this->gc[i];
  new_gc[i] = g;

  if (this->gc)
    delete[] this->gc;
  this->gc = new_gc;
  this->gc_idx++;
}
