/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:42:14 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/11 16:35:14 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Brain.hpp"

#include <string>

// in later c++ standards there is std::optional which would have been the
// appropriate thing to use here.
class AAnimal
{
  private:
    Brain *_brain;

  protected:
    std::string _type;

  public:
    AAnimal();
    AAnimal(const AAnimal& other);
    AAnimal& operator=(const AAnimal& other);
    virtual ~AAnimal();

    void         setType(const std::string& newType);
    std::string  getType() const;
    virtual void makeSound() const                = 0;
    virtual void newIdea(const std::string& idea) = 0;
    virtual void showIdeas()                      = 0;
};

#endif
