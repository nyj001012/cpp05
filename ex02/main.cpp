/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:38:38 by yena              #+#    #+#             */
/*   Updated: 2023/10/10 19:15:12 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  Bureaucrat bureaucrat = Bureaucrat("yena", 50);
  ShrubberyCreationForm shrubbery = ShrubberyCreationForm("yena");

  std::cout << F_GREEN
            << "----------------- SHRUBBERY SIGN TEST (SUCCESS) "
               "-----------------"
            << FB_DEFAULT << std::endl;
  std::cout << bureaucrat << std::endl;
  std::cout << shrubbery << std::endl;
  bureaucrat.signForm(shrubbery);
  std::cout << shrubbery << std::endl;
  std::cout << std::endl;

  std::cout << F_GREEN
            << "------------------ SHRUBBERY SIGN TEST (ERROR) "
               "------------------"
            << FB_DEFAULT << std::endl;
  ShrubberyCreationForm errorShrubbery = ShrubberyCreationForm("error");
  Bureaucrat pettyBureaucrat = Bureaucrat("petty", 150);
  std::cout << pettyBureaucrat << std::endl;
  std::cout << errorShrubbery << std::endl;
  pettyBureaucrat.signForm(errorShrubbery);
  std::cout << std::endl;

  std::cout << F_GREEN
            << "---------------- SHRUBBERY EXECUTE TEST (SUCCESS) "
               "---------------"
            << FB_DEFAULT << std::endl;
  std::cout << bureaucrat << std::endl;
  std::cout << shrubbery << std::endl;
  bureaucrat.executeForm(shrubbery);
  std::cout << std::endl;

  std::cout << F_GREEN
            << "----------------- SHRUBBERY EXECUTE TEST (ERROR) "
               "----------------"
            << FB_DEFAULT << std::endl;
  std::cout << bureaucrat << std::endl;
  std::cout << errorShrubbery << std::endl;
  bureaucrat.executeForm(errorShrubbery);
  std::cout << std::endl;

  std::cout << F_GREEN
            << "---------------- SHRUBBERY EXECUTE TEST (TOO LOW) "
               "---------------"
            << FB_DEFAULT << std::endl;
  std::cout << pettyBureaucrat << std::endl;
  std::cout << shrubbery << std::endl;
  pettyBureaucrat.executeForm(shrubbery);
  std::cout << std::endl;

  std::cout << F_GREEN
            << "------------------ ROBOTOMY SIGN TEST (SUCCESS) "
               "-----------------"
            << FB_DEFAULT << std::endl;
  RobotomyRequestForm robotomy = RobotomyRequestForm("Tychus");
  std::cout << bureaucrat << std::endl;
  std::cout << robotomy << std::endl;
  bureaucrat.signForm(robotomy);
  std::cout << std::endl;

  std::cout << F_GREEN
            << "---------------- ROBOTOMY EXECUTE TEST (SUCCESS) "
               "---------------"
            << FB_DEFAULT << std::endl;
  Bureaucrat mengsk = Bureaucrat("Mengsk", 1);
  std::cout << mengsk << std::endl;
  std::cout << robotomy << std::endl;
  mengsk.executeForm(robotomy);
  std::cout << std::endl;

  std::cout << F_GREEN
            << "------------ PRESIDENTIAL PARDON SIGN TEST (SUCCESS) "
               "------------"
            << FB_DEFAULT << std::endl;
  PresidentialPardonForm pardon = PresidentialPardonForm("agenda");
  Bureaucrat president = Bureaucrat("Mr. president", 1);
  std::cout << president << std::endl;
  std::cout << pardon << std::endl;
  president.signForm(pardon);
  std::cout << std::endl;

  std::cout << F_GREEN
            << "----------- PRESIDENTIAL PARDON EXECUTE TEST (SUCCESS) "
               "----------"
            << FB_DEFAULT << std::endl;
  Bureaucrat primeMinister = Bureaucrat("Mr. primeMinister", 2);
  std::cout << primeMinister << std::endl;
  std::cout << pardon << std::endl;
  primeMinister.executeForm(pardon);

  return (0);
}