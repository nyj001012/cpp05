/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:38:38 by yena              #+#    #+#             */
/*   Updated: 2023/10/10 18:55:01 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  Bureaucrat bureaucrat = Bureaucrat("yena", 50);
  Form form = Form("form", 50, 50);

  std::cout << F_GREEN
            << "------------------------ INITIALISE TEST "
               "------------------------"
            << FB_DEFAULT << std::endl;
  std::cout << "* initialise with grade -1" << std::endl;
  Form error = Form("error", -1, 10);
  std::cout << std::endl;

  std::cout << F_GREEN
            << "---------------------- SIGN TEST (SUCCESS) "
               "----------------------"
            << FB_DEFAULT << std::endl;
  std::cout << bureaucrat << std::endl;
  std::cout << form << std::endl;
  bureaucrat.signForm(form);
  std::cout << form << std::endl;
  std::cout << std::endl;

  std::cout << F_GREEN
            << "----------------------- SIGN TEST (ERROR) "
               "-----------------------"
            << FB_DEFAULT << std::endl;
  Form topSecret = Form("topSecret", 1, 15);
  std::cout << bureaucrat << std::endl;
  std::cout << topSecret << std::endl;
  bureaucrat.signForm(topSecret);
  return (0);
}