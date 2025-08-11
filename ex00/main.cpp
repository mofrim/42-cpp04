/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:41:39 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/06 21:12:12 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "utils.hpp"

#include <iostream>

// alrighty! polymorphism and the keyword `virtual` explained...
//
// `virtual` was invented specifically for realizing _Polymorphisms in C++. Say
// you have a base class like our `Animal` class, and different derived classes
// like `Dog`, `Cat`, `Turtle`. Without having a way to tell the compiler if a
// function should be called using the base classes member or a derived classes
// member stuff like this would not work:
//
//    std::vector<Animal*> zoo;
//    zoo.push_back(new Dog());
//    zoo.push_back(new Cat());
//    zoo.push_back(new Turtle());
//
//    for (size_t i = 0; i < zoo.size(); ++i) {
//        zoo[i]->makeSound(); // we want the derived classes sound here!
//    }
//
// if the compiler would not know about the the member functions makeSound() it
// would not help to "hide" them by simply defining them in every derived class
// like this:
//
//    class Dog: public Animal {
//      ...
//      void makeSound() const;
//    }
//
// in this case the loop would only print the sound of the base class 3 times.
// by declaring like this:
//
//    class Dog: public Animal {
//      ...
//      virtual void makeSound() const;
//    }
//
// we get the polymorphic behavior we want.
//
// in general there are 2 types of polymorphism:
//
//    1) compile-time (or early-binding, static polymorphisms)
//    2) run-time (or late-binding, dynaimc polys)
//
// compile-time polymorphism we already know from function or operator
// overloading.
// the thing we want here is run-time polymorphism. this is achieved by using
// the `virtual` keyword.
// btw, polymorphism == many forms == context dependent function selection (~)

int main()
{
  const Animal *meta = new Animal();
  const Animal *j    = new Dog();
  const Animal *i    = new Cat();
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound(); // will output the cat sound!
  meta->makeSound();
  j->makeSound();

  newline();

  const WrongAnimal *wmeta = new WrongAnimal();
  const WrongAnimal *k     = new WrongCat();
  std::cout << k->getType() << " " << std::endl;
  wmeta->makeSound();
  k->makeSound();
  
  newline();

  delete meta;
  delete j;
  delete i;
  delete wmeta;
  delete k;

  return (0);
}
