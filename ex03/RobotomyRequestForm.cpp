/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 07:21:34 by yena              #+#    #+#             */
/*   Updated: 2023/10/10 19:21:03 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by 나예진 on 2023/10/08.
//

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : Form(target + "_robotomy", 72, 45) {
  std::srand(time(NULL));
  this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : Form(other) {
  if (this != &other) *this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    const RobotomyRequestForm &other) {
  if (this != &other) {
    this->_target = other._target;
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

/**
 * make some drilling noises and tell us that the robotomization was a success
 * or a failure
 * @param executor
 */
void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
  if (executor.getGrade() > this->getGradeToExecute())
    throw RobotomyRequestForm::GradeTooLowException();
  else if (!this->getIsSigned())
    throw RobotomyRequestForm::FormNotSignedException();
  else {
    std::cout << "* drilling noises *" << std::endl;
    if (std::rand() % 2)
      std::cout << this->_target << " has been robotomized successfully"
                << std::endl;
    else
      std::cout << this->_target << ": robotomization failed" << std::endl;
  }
}