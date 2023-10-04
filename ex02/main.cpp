/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@studen.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:38:38 by yena              #+#    #+#             */
/*   Updated: 2023/10/04 16:36:48 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  Bureaucrat bureaucrat = Bureaucrat("yena", 50);
  ShrubberyCreationForm shrubbery = ShrubberyCreationForm("grow_trees");

  std::cout << "------------ SHRUBBERY SIGN TEST (success) -----------" << std::endl;
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

  std::cout << "----- SHRUBBERY EXECUTE TEST (success) -----" << std::endl;
  std::cout << bureaucrat << std::endl;
  std::cout << shrubbery << std::endl;
  bureaucrat.executeForm(shrubbery);
  std::cout << std::endl;

  std::cout << "-- SHRUBBERY EXECUTE TEST (ERROR: NO SIGN) --" << std::endl;
  std::cout << bureaucrat << std::endl;
  std::cout << errorShrubbery << std::endl;
  bureaucrat.executeForm(errorShrubbery);
  std::cout << std::endl;

  std::cout << "-- SHRUBBERY EXECUTE TEST (ERROR: TOO LOW) --" << std::endl;
  std::cout << pettyBureaucrat << std::endl;
  std::cout << shrubbery << std::endl;
  pettyBureaucrat.executeForm(shrubbery);
  std::cout << std::endl;
  return (0);
}