/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:38:38 by yena              #+#    #+#             */
/*   Updated: 2023/10/10 14:36:28 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  Bureaucrat bureaucrat = Bureaucrat("yena", 50);
  Form form = Form("form", 50, 50);

  std::cout << "------------- INITIALISE TEST --------------" << std::endl;
  try {
    std::cout << "* initialise with grade -1" << std::endl;
    Form error = Form("error", -1, 10);
  } catch (const std::exception &e) {
    std::cerr << F_RED
              << e.what()
              << FB_DEFAULT << std::endl;
  }
  std::cout << std::endl;

  std::cout << "------------ SIGN TEST (SUCCESS) -----------" << std::endl;
  std::cout << bureaucrat << std::endl;
  std::cout << form << std::endl;
  bureaucrat.signForm(form);
  std::cout << form << std::endl;
  std::cout << std::endl;

  std::cout << "------------- SIGN TEST (ERROR) ------------" << std::endl;
  Form topSecret = Form("topSecret", 1, 15);
  std::cout << bureaucrat << std::endl;
  std::cout << topSecret << std::endl;
  bureaucrat.signForm(topSecret);
  return (0);
}