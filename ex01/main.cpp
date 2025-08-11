/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:41:39 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/07 15:02:49 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// FIXME: downgrade this exercise to not using abstract class

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "utils.hpp"

#include <sstream>

int main()
{
  const int NumOfAnimals = 6;
  Animal   *dogsncats[NumOfAnimals];
  for (int i = 0; i < NumOfAnimals; i++)
  {
    if (i < NumOfAnimals / 2)
      dogsncats[i] = new Dog();
    else
      dogsncats[i] = new Cat();
  }

  for (int i = 0; i < NumOfAnimals; i++)
  {
    std::ostringstream num;
    num << i;
    dogsncats[i]->newIdea("aha" + num.str());
    dogsncats[i]->newIdea("aha" + num.str() + ".5");
  }

  newline();

  for (int i = 0; i < NumOfAnimals; i++)
  {
    dogsncats[i]->makeSound();
    dogsncats[i]->showIdeas();
  }

  newline();

  for (int i = 0; i < NumOfAnimals; i++)
    delete dogsncats[i];

  newline();

  {
    Dog bob;
    bob.makeSound();
  }

  newline();

  {
    Cat cat;
    cat.makeSound();

    newline();

    for (int i = 0; i < 101; i++)
    {
      std::ostringstream num;
      num << i;
      cat.newIdea("catidea no." + num.str());
    }
    cat.showIdeas();

    newline();
  }

  return (0);
}
