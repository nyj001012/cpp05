/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 08:09:18 by yena              #+#    #+#             */
/*   Updated: 2023/10/10 19:49:18 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by 나예진 on 2023/10/08.
//

#include "Intern.hpp"

static const std::string formTypes[3] = {
    "shrubbery creation", "robotomy request", "presidential pardon"};

Intern::Intern() {}

Intern::Intern(const Intern &other) {
  if (this != &other) *this = other;
}

Intern &Intern::operator=(const Intern &other) {
  (void)other;
  return *this;
}

Intern::~Intern() {}

/**
 * make form of type: [shrubbery creation, robotomy request, presidential
 * pardon]. after use, you should delete the form.
 * @param formName
 * @param target
 * @return Form*
 */
Form *Intern::makeForm(std::string formName, std::string target) {
  int typeNumber = 0;
  Form *form;

  for (typeNumber = 0; typeNumber < 3; typeNumber++) {
    if (formName == formTypes[typeNumber]) break;
  }
  switch (typeNumber) {
    case 0:
      form = new ShrubberyCreationForm(target);
      break;
    case 1:
      form = new RobotomyRequestForm(target);
      break;
    case 2:
      form = new PresidentialPardonForm(target);
      break;
    default:
      throw Intern::InvalidFormNameException();
      break;
  }
  std::cout << "Intern creates " << formName << std::endl;
  return form;
}
