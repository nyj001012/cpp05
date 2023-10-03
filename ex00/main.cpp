/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@studen.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:38:38 by yena              #+#    #+#             */
/*   Updated: 2023/10/03 14:44:10 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
  Bureaucrat bureaucrat;
  int adder;

  std::cout << "-------------- DECREASE GRADE --------------" << std::endl;
  std::cout << "bureaucrat's grade: " << bureaucrat.getGrade() << std::endl;
  try {
    std::cout << "* decrease 149" << std::endl;
    adder = 149;
    bureaucrat.decreaseGrade(adder);
    std::cout << "bureaucrat's grade: " << bureaucrat.getGrade() << std::endl;
    std::cout << "* decrease 70" << std::endl;
    adder = 70;
    bureaucrat.decreaseGrade(adder);
  }
  catch (char *error_message) {
    std::cout << F_RED
              << error_message << " (adder: " << adder << ")"
              << FB_DEFAULT << std::endl;
  }

  std::cout << "-------------- INCREASE GRADE --------------" << std::endl;
  std::cout << "bureaucrat's grade: " << bureaucrat.getGrade() << std::endl;
  try {
    std::cout << "* increase 100" << std::endl;
    adder = 100;
    bureaucrat.increaseGrade(adder);
    std::cout << "bureaucrat's grade: " << bureaucrat.getGrade() << std::endl;
    std::cout << "* increase 51" << std::endl;
    adder = 51;
    bureaucrat.increaseGrade(adder);
  }
  catch (char *error_message) {
    std::cout << F_RED
              << error_message << " (adder: " << adder << ")"
              << FB_DEFAULT << std::endl;
  }
  return (0);
}