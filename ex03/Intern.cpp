/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 08:09:18 by yena              #+#    #+#             */
/*   Updated: 2023/10/10 15:04:08 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by 나예진 on 2023/10/08.
//

#include "Intern.hpp"

Intern::Intern() {

}

Intern::Intern(const Intern &other) {
  if (this != &other)
	*this = other;
}

Intern &Intern::operator=(const Intern &other) {
  (void)other;
  return *this;
}

Intern::~Intern() {

}

/**
 * make form of type: [shrubbery creation, robotomy request, presidential pardon].
 * after use, you should delete the form.
 * @param formName
 * @param target
 * @return Form*
 */
Form *Intern::makeForm(std::string formName, std::string target) {
  Form *form;

  if (formName == "shrubbery creation")
	  form = new ShrubberyCreationForm(target);
  else if (formName == "robotomy request")
  	form = new RobotomyRequestForm(target);
  else if (formName == "presidential pardon")
	  form = new PresidentialPardonForm(target);
  else
	  throw Intern::InvalidFormNameException();
  std::cout << "Intern creates " << formName << std::endl;
  return form;
}
