/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 09:40:13 by fmaurer           #+#    #+#             */
/*   Updated: 2025/08/11 11:40:52 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
#define TESTS_HPP

#include <string>

// my only purpose is to organize tests
class Tests
{
  private:
    Tests(const Tests& other);
    Tests& operator=(const Tests& other);
    void   _printTestStartBanner(const std::string& testname) const;
    void   _printTestEndBanner(const std::string& testname) const;

  public:
    Tests();
    ~Tests();

    // test funcs
    void copyConstructorTest() const;
    void noStack() const;
    void cleanMemMgmt() const;
};

#endif
