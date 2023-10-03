/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@studen.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:38:38 by yena              #+#    #+#             */
/*   Updated: 2023/10/03 16:38:11 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
  Bureaucrat bureaucrat = Bureaucrat("yena", 1);

  std::cout << "------------- INITIALISE TEST --------------" << std::endl;
  try {
    std::cout << "* initialise with grade 159" << std::endl;
    Bureaucrat error = Bureaucrat("error", 159);
  } catch (const std::exception &e) {
    std::cerr << F_RED
              << e.what()
              << FB_DEFAULT << std::endl;
  }

  std::cout << "-------------- DECREASE GRADE --------------" << std::endl;
  std::cout << bureaucrat << std::endl;
  try {
    std::cout << "* decrease 149" << std::endl;
    bureaucrat.decreaseGrade(149);
    std::cout << bureaucrat << std::endl;
    std::cout << "* decrease 70" << std::endl;
    bureaucrat.decreaseGrade(70);
  }
  catch (const std::exception &e) {
    std::cout << F_RED
              << e.what()
              << FB_DEFAULT << std::endl;
  }

  std::cout << "-------------- INCREASE GRADE --------------" << std::endl;
  std::cout << bureaucrat << std::endl;
  try {
    std::cout << "* increase 100" << std::endl;
    bureaucrat.increaseGrade(100);
    std::cout << bureaucrat << std::endl;
    std::cout << "* increase 51" << std::endl;
    bureaucrat.increaseGrade(51);
  }
  catch (const std::exception &e) {
    std::cout << F_RED
              << e.what()
              << FB_DEFAULT << std::endl;
  }
  return (0);
}