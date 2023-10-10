/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 07:21:34 by yena              #+#    #+#             */
/*   Updated: 2023/10/10 14:46:35 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by 나예진 on 2023/10/08.
//

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm(target + "_robotomy", 72, 45) {
  this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other) {
  if (this != &other)
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  if (this != &other) {
	this->_target = other._target;
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {

}

/**
 * make some drilling noises and tell us that the robotomization was a success or a failure
 * @param executor
 */
void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
  if (executor.getGrade() > this->getGradeToExecute())
	throw RobotomyRequestForm::GradeTooLowException();
  else if (!this->getIsSigned())
	throw RobotomyRequestForm::FormNotSignedException();
  else {
	std::cout << "* drilling noises *" << std::endl;
	std::srand(time(NULL));
	if (std::rand() % 2)
	  std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
	  std::cout << this->_target << ": robotomization failed" << std::endl;
  }
}