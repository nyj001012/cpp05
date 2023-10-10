/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:13:01 by yena              #+#    #+#             */
/*   Updated: 2023/10/10 14:20:35 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yejin Na on 10/3/23.
//

#include "Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute < 1)
	  throw Form::GradeTooHighException();
  if (gradeToSign > 150 || gradeToExecute > 150)
	  throw Form::GradeTooLowException();
  this->_isSigned = false;
}

Form::Form(const Form &other): _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
  if (this != &other) {
	  this->_isSigned = other._isSigned;
  }
}

Form &Form::operator=(const Form &other) {
  if (this != &other) {
	  this->_isSigned = other._isSigned;
  }
  return *this;
}

Form::~Form() {

}

const std::string Form::getName() const {
  return this->_name;
}

bool Form::getIsSigned() const {
  return this->_isSigned;
}

int Form::getGradeToSign() const {
  return this->_gradeToSign;
}

int Form::getGradeToExecute() const {
  return this->_gradeToExecute;
}

/**
 * change the form status to signed if the bureaucrat's grade is higher or egal o the required one
 * @param bureaucrat
 */
void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > this->_gradeToSign)
	  throw Form::GradeTooLowException();
  this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
  os << "Form: " << form.getName()
     << "\tgrade to sign required: " << std::to_string(form.getGradeToSign())
     << "\tgrade to execute required: " << std::to_string(form.getGradeToExecute())
     << "\tis signed: " << std::to_string(form.getIsSigned());
  return os;
}
