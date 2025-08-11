/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:42:14 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/07 11:41:28 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Brain.hpp"

#include <string>

// in later c++ standards there is std::optional which would have been the
// appropriate thing to use here.
class Animal
{
  private:
    Brain *brain;

  protected:
    std::string type;

  public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

    void         setType(const std::string& newType);
    std::string  getType() const;
    virtual void makeSound() const                = 0;
    virtual void newIdea(const std::string& idea) = 0;
    virtual void showIdeas()                      = 0;
};

#endif
