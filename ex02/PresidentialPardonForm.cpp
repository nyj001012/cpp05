/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 07:52:18 by yena              #+#    #+#             */
/*   Updated: 2023/10/10 14:49:50 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by 나예진 on 2023/10/08.
//

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm(target + "_presidential_pardon", 25, 5) {
  this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other) {
  if (this != &other)
	  *this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  if (this != &other) {
	  this->_target = other._target;
  }
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {

}

/**
 * inform that target has been pardoned by Zaphod Beeblebrox
 * @param executor
 */
void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
  if (executor.getGrade() > this->getGradeToExecute())
    throw PresidentialPardonForm::GradeTooLowException();
  else if (!this->getIsSigned())
    throw PresidentialPardonForm::FormNotSignedException();
  else {
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
  }
}
