/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:42:14 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/06 21:11:39 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

// INSIGHT: we _have_ to declare the destructor in any base class virtual
// because otherwise we would get a core dump if an instance of a derived class
// is being freed. the compiler would not know which destructor to call first
// (try removing the virtual here!)
class WrongAnimal
{
  protected:
    std::string type;

  public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    virtual ~WrongAnimal();

    std::string getType() const;
    void        setType(const std::string& newType);
    void        makeSound() const;
};

#endif
