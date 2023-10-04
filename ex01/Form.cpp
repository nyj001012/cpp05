/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:13:01 by yena              #+#    #+#             */
/*   Updated: 2023/10/04 14:47:16 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yejin Na on 10/3/23.
//

#include "Form.hpp"

Form::Form(std::string name, int grade): _name(name) {
  if (grade < 1)
	throw Form::GradeTooHighException();
  if (grade > 150)
	throw Form::GradeTooLowException();
  this->_isSigned = false;
  this->_grade = grade;
}

Form::Form(const Form &other): _name(other._name) {
  if (this != &other) {
	this->_isSigned = other._isSigned;
	this->_grade = other._grade;
  }
}

Form &Form::operator=(const Form &other) {
  if (this != &other) {
	this->_isSigned = other._isSigned;
	this->_grade = other._grade;
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

int Form::getGrade() const {
  return this->_grade;
}

/**
 * change the form status to signed if the bureaucrat's grade is higher or egal o the required one
 * @param bureaucrat
 */
void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > this->_grade)
	throw Form::GradeTooLowException();
  this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
  os << "Form: " << form.getName()
	 << "\tgrade required: " << std::to_string(form.getGrade())
	 << "\tis signed: " << std::to_string(form.getIsSigned());
  return os;
}
