/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:38:38 by yena              #+#    #+#             */
/*   Updated: 2023/10/10 19:48:33 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void) {
  Bureaucrat bureaucrat = Bureaucrat("yena", 20);
  Intern intern = Intern();

  std::cout << F_GREEN
            << "------------------- CREATE FORM TEST (SUCCESS) "
               "------------------"
            << FB_DEFAULT << std::endl;
  Form *shrubbery = intern.makeForm("shrubbery creation", "home");
  Form *robotomy = intern.makeForm("robotomy request", "bender");
  Form *presidential = intern.makeForm("presidential pardon", "Biden");
  std::cout << *shrubbery << std::endl;
  std::cout << *robotomy << std::endl;
  std::cout << *presidential << std::endl;
  std::cout << std::endl;

  std::cout << F_GREEN
            << "-------------------- CREATE FORM TEST (ERROR) "
               "-------------------"
            << FB_DEFAULT << std::endl;
  try {
    Form *error = intern.makeForm("error", "error");
    (void)error;
  } catch (const std::exception &e) {
    std::cerr << F_RED << e.what() << FB_DEFAULT << std::endl;
  }
  std::cout << std::endl;

  std::cout << F_GREEN
            << "-------------------- SIGN FORM TEST (SUCCESS) "
               "-------------------"
            << FB_DEFAULT << std::endl;
  std::cout << bureaucrat << std::endl;
  std::cout << *shrubbery << std::endl;
  std::cout << *robotomy << std::endl;
  std::cout << *presidential << std::endl;
  bureaucrat.signForm(*shrubbery);
  bureaucrat.signForm(*robotomy);
  bureaucrat.signForm(*presidential);
  std::cout << std::endl;

  std::cout << F_GREEN
            << "------------ EXECUTE FORM TEST (2: SUCCESS 1: ERROR) "
               "------------"
            << FB_DEFAULT << std::endl;
  std::cout << bureaucrat << std::endl;
  std::cout << *shrubbery << std::endl;
  std::cout << *robotomy << std::endl;
  std::cout << *presidential << std::endl;
  std::cout << std::endl;
  bureaucrat.executeForm(*shrubbery);
  bureaucrat.executeForm(*robotomy);
  bureaucrat.executeForm(*presidential);

  delete shrubbery;
  delete robotomy;
  delete presidential;
  return (0);
}