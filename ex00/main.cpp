/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:38:38 by yena              #+#    #+#             */
/*   Updated: 2023/10/10 18:30:55 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
  Bureaucrat bureaucrat = Bureaucrat("yena", 1);

  std::cout << "------------- INITIALISE TEST --------------" << std::endl;
  std::cout << "* initialise with grade 159" << std::endl;
  Bureaucrat error = Bureaucrat("error", 159);
  std::cout << std::endl;

  std::cout << "-------------- DECREASE GRADE --------------" << std::endl;
  std::cout << bureaucrat << std::endl;
  std::cout << "* decrease 149" << std::endl;
  bureaucrat.decreaseGrade(149);
  std::cout << bureaucrat << std::endl;
  std::cout << "* decrease 70" << std::endl;
  bureaucrat.decreaseGrade(70);
  std:: cout << std::endl;

  std::cout << "-------------- INCREASE GRADE --------------" << std::endl;
  std::cout << bureaucrat << std::endl;
  std::cout << "* increase 100" << std::endl;
  bureaucrat.increaseGrade(100);
  std::cout << bureaucrat << std::endl;
  std::cout << "* increase 51" << std::endl;
  bureaucrat.increaseGrade(51);
  return (0);
}