/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:05:07 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/11 16:01:45 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Tests.hpp"

// due to the snippet from subject.pdf i drew the conclusion that ther mandatory
// path for dealing with Materias is through MateriaSource. A MateriaSource
// _takes ownership_ of the Materias it learns. Meaning: stuff like this
//
//    IMateriaSource *srcA = new MateriaSource();
//    IMateriaSource *srcB = new MateriaSource();
//    AMateria       *c    = new Cure();
//    srcA->learnMateria(c);
//    srcB->learnMateria(c);
//    delete c;
//    delete srcA;
//    delete srcB;
//
// is not allowed (but it is possible to write and therefore will lead to a
// segfault). So the rule is:
//
//    ** Any Materia that is passed to a MateriaSource should not be deleted in
//    the outer scope !!!**
//
// It can be passed to another MateriaSource, but without any effect. The
// Materia is _owned_ by ther first MateriaSource that learns it.
// I modified AMateria for this. i hope you do not mind.
//
// The same holds for Characters. They also take ownership *and* responsibility
// for what they get equipped with. Meaning: if some Materia was created and
// equipped to a Character _never_ delete it!
//
// Rule:
//
//    ** the only things that can be deleted in main are unused (unlearned,
//    unequipped) Materias, Characters and MateriaSources **
//
// that's it for now.
int main()
{
  //// snippet from subject.pdf ////

  IMateriaSource *src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  ICharacter *me = new Character("me");
  AMateria   *tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  ICharacter *bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);

  delete bob;
  delete me;
  delete src;

  //////// my own tests /////////

  Tests test;

  //// copy constructor example ////
  test.copyConstructorTest();

  //// clean mem mgmt ////
  test.cleanMemMgmtMateria0();
  test.cleanMemMgmtMateria1();
  test.cleanMemMgmtMateria2();

  //// character inv test ////
  test.characterInvMemTest();

  //// no stack for Materias! ////
  // test.noStack();

  return (0);
}
