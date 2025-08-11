/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:41:39 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/11 16:36:09 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "utils.hpp"

#include <sstream>

int main()
{
  const int NumOfAAnimals = 6;
  AAnimal  *dogsncats[NumOfAAnimals];
  for (int i = 0; i < NumOfAAnimals; i++)
  {
    if (i < NumOfAAnimals / 2)
      dogsncats[i] = new Dog();
    else
      dogsncats[i] = new Cat();
  }

  for (int i = 0; i < NumOfAAnimals; i++)
  {
    std::ostringstream num;
    num << i;
    dogsncats[i]->newIdea("aha" + num.str());
    dogsncats[i]->newIdea("aha" + num.str() + ".5");
  }

  newline();

  for (int i = 0; i < NumOfAAnimals; i++)
  {
    dogsncats[i]->makeSound();
    dogsncats[i]->showIdeas();
  }

  newline();

  for (int i = 0; i < NumOfAAnimals; i++)
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
