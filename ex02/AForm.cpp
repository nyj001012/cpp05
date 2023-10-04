/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:01:58 by yena              #+#    #+#             */
/*   Updated: 2023/10/04 16:09:08 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yejin Na on 10/3/23.
//

#include "AForm.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute < 1)
	throw AForm::GradeTooHighException();
  if (gradeToSign > 150 || gradeToExecute > 150)
	throw AForm::GradeTooLowException();
  this->_isSigned = false;
}

AForm::AForm(const AForm &other): _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
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

int AForm::getGradeToSign() const {
  return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {
  return this->_gradeToExecute;
}

/**
 * change the AForm status to signed if the bureaucrat's grade is higher or egal o the required one
 * @param bureaucrat
 */
void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > this->_gradeToSign)
	throw AForm::GradeTooLowException();
  this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm) {
  os << "Form: " << AForm.getName()
	 << "\tgrade to sign required: " << std::to_string(AForm.getGradeToSign())
	 << "\tgrade to execute required: " << std::to_string(AForm.getGradeToExecute())
	 << "\tis signed: " << std::to_string(AForm.getIsSigned());
  return os;
}