/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@studen.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:38:38 by yena              #+#    #+#             */
/*   Updated: 2023/10/08 07:48:42 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void) {
  Bureaucrat bureaucrat = Bureaucrat("yena", 50);
  ShrubberyCreationForm shrubbery = ShrubberyCreationForm("grow_trees");

  std::cout << "------------ SHRUBBERY SIGN TEST (SUCCESS) -----------" << std::endl;
  std::cout << bureaucrat << std::endl;
  std::cout << shrubbery << std::endl;
  bureaucrat.signForm(shrubbery);
  std::cout << shrubbery << std::endl;
  std:: cout << std::endl;

  std::cout << "------------- SHRUBBERY SIGN TEST (ERROR) ------------" << std::endl;
  ShrubberyCreationForm errorShrubbery = ShrubberyCreationForm("error");
  Bureaucrat pettyBureaucrat = Bureaucrat("petty", 150);
  std::cout << pettyBureaucrat << std::endl;
  std::cout << errorShrubbery << std::endl;
  pettyBureaucrat.signForm(errorShrubbery);
  std::cout << std::endl;

  std::cout << "---------- SHRUBBERY EXECUTE TEST (SUCCESS) ----------" << std::endl;
  std::cout << bureaucrat << std::endl;
  std::cout << shrubbery << std::endl;
  bureaucrat.executeForm(shrubbery);
  std::cout << std::endl;

  std::cout << "------ SHRUBBERY EXECUTE TEST (ERROR: NO SIGN) -------" << std::endl;
  std::cout << bureaucrat << std::endl;
  std::cout << errorShrubbery << std::endl;
  bureaucrat.executeForm(errorShrubbery);
  std::cout << std::endl;

  std::cout << "------ SHRUBBERY EXECUTE TEST (ERROR: TOO LOW) -------" << std::endl;
  std::cout << pettyBureaucrat << std::endl;
  std::cout << shrubbery << std::endl;
  pettyBureaucrat.executeForm(shrubbery);
  std::cout << std::endl;

  std::cout << "------------- ROBOTOMY SIGN TEST (SUCCESS) -------------" << std::endl;
  RobotomyRequestForm robotomy = RobotomyRequestForm("Tychus J. Findlay");
  bureaucrat.signForm(robotomy);
  std::cout << std::endl;

  std::cout << "---------- ROBOTOMY EXECUTE TEST (SUCCESS) -----------" << std::endl;
  std::cout << bureaucrat << std::endl;
  std::cout << robotomy << std::endl;
  bureaucrat.executeForm(robotomy);
  std::cout << std::endl;

  return (0);
}