/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:01:58 by yena              #+#    #+#             */
/*   Updated: 2023/10/04 15:12:42 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:13:01 by yena              #+#    #+#             */
/*   Updated: 2023/10/04 15:01:57 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yejin Na on 10/3/23.
//

#include "AForm.hpp"

AForm::AForm(std::string name, int grade): _name(name), _grade(grade) {
  if (grade < 1)
	throw AForm::GradeTooHighException();
  if (grade > 150)
	throw AForm::GradeTooLowException();
  this->_isSigned = false;
}

AForm::AForm(const AForm &other): _name(other._name), _grade(other._grade) {
  if (this != &other) {
	this->_isSigned = other._isSigned;
  }
}

AForm &AForm::operator=(const AForm &other) {
  if (this != &other) {
	this->_isSigned = other._isSigned;
  }
  return *this;
}

AForm::~AForm() {

}

const std::string AForm::getName() const {
  return this->_name;
}

bool AForm::getIsSigned() const {
  return this->_isSigned;
}

int AForm::getGrade() const {
  return this->_grade;
}

/**
 * change the AForm status to signed if the bureaucrat's grade is higher or egal o the required one
 * @param bureaucrat
 */
void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > this->_grade)
	throw AForm::GradeTooLowException();
  this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm) {
  os << "AForm: " << AForm.getName()
	 << "\tgrade required: " << std::to_string(AForm.getGrade())
	 << "\tis signed: " << std::to_string(AForm.getIsSigned());
  return os;
}
