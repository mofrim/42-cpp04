/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 09:39:21 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/11 15:43:11 by fmaurer          ###   ########.fr       */
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

Tests::Tests() {}

Tests::Tests(const Tests& other) { (void)other; }

Tests& Tests::operator=(const Tests& other)
{
  (void)other;
  return (*this);
}

Tests::~Tests() {}

void Tests::_printTestStartBanner(const std::string& testname) const
{
  newline();
  std::cout << "<<< Running test: " << testname << " >>>" << std::endl;
  newline();
}

void Tests::_printTestEndBanner(const std::string& testname) const
{
  newline();
  std::cout << "<<< Finished test: " << testname << " >>>" << std::endl;
  newline();
}

void Tests::copyConstructorTest() const
{
  this->_printTestStartBanner("copyConstructorTest");
  {
    ICharacter *bob1 = new Character("bob1");
    Character   kalle(*static_cast<Character *>(bob1));
    std::cout << "  hi! my name is " << kalle.getName() << std::endl;
    Cure *c1 = new Cure();
    kalle.equip(c1);
    kalle.use(0, kalle);
    kalle.use(1, kalle);
    delete bob1;
  }
  this->_printTestEndBanner("copyConstructorTest");
}

void Tests::noStack() const
{
  // this->_printTestStartBanner("noStack");
  // {
  //   Character foo("foo");
  //   Character bar("bar");
  //   {
  //     Cure c;
  //     foo.equip(&c);
  //   }
  //   std::cout << "  now going for it:" << std::endl;
  //   foo.use(0, bar);
  // }
  // this->_printTestEndBanner("noStack");
}

void Tests::cleanMemMgmtMateria0() const
{
  this->_printTestStartBanner("cleanMemMgmtMateria0");
  {
    IMateriaSource *srcA = new MateriaSource();
    IMateriaSource *srcB = new MateriaSource();
    AMateria       *c    = new Cure();
    srcA->learnMateria(c);
    srcB->learnMateria(c);
    delete srcA;
    delete srcB;
  }
  this->_printTestEndBanner("cleanMemMgmtMateria0");
}

void Tests::cleanMemMgmtMateria1() const
{
  this->_printTestStartBanner("cleanMemMgmtMateria1");
  {
    IMateriaSource *srcA = new MateriaSource();
    srcA->learnMateria(new Cure());
    srcA->learnMateria(new Ice());
    srcA->learnMateria(new Cure());
    srcA->learnMateria(new Ice());
    srcA->learnMateria(new Cure());
    srcA->learnMateria(new Cure());
    srcA->learnMateria(new Cure());
    delete srcA;
  }
  this->_printTestEndBanner("cleanMemMgmtMateria1");
}

void Tests::cleanMemMgmtMateria2() const
{
  this->_printTestStartBanner("cleanMemMgmtMateria2");
  {
    IMateriaSource *srcA = new MateriaSource();
    IMateriaSource *srcB = new MateriaSource();
    Character       bob("bob");
    Cure           *c = new Cure();
    srcA->learnMateria(c);
    srcB->learnMateria(c);
    newline();
    AMateria *matA = srcA->createMateria("cure");
    newline();
    matA->use(bob);
    newline();
    AMateria *matB = srcB->createMateria("cure");
    newline();
    if (matB)
      matB->use(bob);
    if (matA)
      delete matA;
    if (matB)
      delete matB;
    delete srcA;
    delete srcB;
  }
  this->_printTestEndBanner("cleanMemMgmtMateria2");
}

void Tests::characterInvMemTest() const
{
  this->_printTestStartBanner("characterInvMemTest");
  {
    Character     bob("bob");
    Character     elon("elon");
    MateriaSource src;
    src.learnMateria(new Cure());
    src.learnMateria(new Ice());
    bob.equip(src.createMateria("ice"));
    bob.equip(src.createMateria("cure"));
    bob.equip(src.createMateria("ice"));
    bob.equip(src.createMateria("cure"));
    bob.equip(src.createMateria("ice"));
    bob.equip(src.createMateria("ice"));

    bob.use(0, elon);
    bob.use(1, elon);
    bob.use(2, elon);
    bob.use(3, elon);
    bob.use(4, elon);
  }
  this->_printTestEndBanner("characterInvMemTest");
}
