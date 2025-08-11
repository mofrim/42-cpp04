/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:05:07 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/11 11:39:32 by fmaurer          ###   ########.fr       */
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
#include "utils.hpp"

#include <iostream>

int main()
{
  Tests test;
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

  //// copy constructor example ////
  // test.copyConstructorTest();

  //// crash example no1 ////

  test.cleanMemMgmt();

  //// no stack for Materias! ////
  // test.noStack();

  //// extra ////

  // newline();
  //
  // IMateriaSource *src1 = new MateriaSource();
  //
  // newline();
  //
  // AMateria *at = new Cure();
  //
  // newline();
  //
  // src1->learnMateria(at);
  //
  // newline();
  //
  // delete at;
  //
  // newline();
  //
  // delete src1;

  // IMateriaSource *srcX = new MateriaSource();
  // srcX->learnMateria(new Ice());
  // srcX->learnMateria(new Cure());
  // ICharacter *meX  = new Character("meX");
  // ICharacter *bobX = new Character("bobX");
  // AMateria   *tmpX;
  // tmpX = srcX->createMateria("ice");
  // meX->equip(tmpX);
  // tmpX = srcX->createMateria("cure");
  // meX->equip(tmpX);
  // meX->equip(tmpX);
  // meX->equip(tmpX);
  // meX->use(0, *bobX);
  // meX->use(1, *bobX);
  // meX->use(2, *bobX);
  // meX->use(3, *bobX);
  //
  // *meX = *bobX;
  //
  // delete bobX;
  // delete meX;
  // delete srcX;

  return (0);
}
