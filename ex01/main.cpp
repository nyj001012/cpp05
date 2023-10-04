/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@studen.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:38:38 by yena              #+#    #+#             */
/*   Updated: 2023/10/04 15:02:37 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  Bureaucrat bureaucrat = Bureaucrat("yena", 50);
  Form form = Form("form", 50);

  std::cout << "------------- INITIALISE TEST --------------" << std::endl;
  try {
    std::cout << "* initialise with grade -1" << std::endl;
    Form error = Form("error", -1);
  } catch (const std::exception &e) {
    std::cerr << F_RED
              << e.what()
              << FB_DEFAULT << std::endl;
  }

  std::cout << "------------ SIGN TEST (SUCCESS) -----------" << std::endl;
  std::cout << bureaucrat << std::endl;
  std::cout << form << std::endl;
  form.beSigned(bureaucrat);
  bureaucrat.signForm(form);
  std::cout << form << std::endl;

  std::cout << "------------- SIGN TEST (ERROR) ------------" << std::endl;
  Form topSecret = Form("topSecret", 1);
  std::cout << bureaucrat << std::endl;
  std::cout << topSecret << std::endl;
  try {
	topSecret.beSigned(bureaucrat);
	bureaucrat.signForm(topSecret);
  }
  catch (const std::exception &e) {
    std::cout << F_RED
			  << bureaucrat.getName()
			  << " cannot sign "
			  << topSecret.getName()
			  << " because "
              << e.what()
              << FB_DEFAULT << std::endl;
  }
  return (0);
}