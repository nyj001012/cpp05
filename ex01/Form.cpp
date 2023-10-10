/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by yena              #+#    #+#             */
/*   Updated: 2023/10/10 18:57:58 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yejin Na on 15/3/23.
//

#include "Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
    : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
  try {
    if (gradeToSign < 1 || gradeToExecute < 1)
      throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
      throw Form::GradeTooLowException();
    this->_isSigned = false;
  } catch (std::exception &e) {
    std::cout << F_RED << e.what() << FB_DEFAULT << std::endl;
  }
}

Form::Form(const Form &other)
    : _name(other._name),
      _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute) {
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

Form::~Form() {}

const std::string Form::getName() const { return this->_name; }

bool Form::getIsSigned() const { return this->_isSigned; }

int Form::getGradeToSign() const { return this->_gradeToSign; }

int Form::getGradeToExecute() const { return this->_gradeToExecute; }

/**
 * change the form status to signed if the bureaucrat's grade is higher or egal
 * o the required one
 * @param bureaucrat
 */
void Form::beSigned(const Bureaucrat &bureaucrat) {
  try {
    if (bureaucrat.getGrade() > this->_gradeToSign)
      throw Form::GradeTooLowException();
    this->_isSigned = true;
  } catch (std::exception &e) {
    std::cout << F_RED << e.what() << FB_DEFAULT << std::endl;
  }
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
  os << "Form:\n"
     << "|" << std::setw(15) << "_name"
     << "|" << std::setw(15) << "_isSigned"
     << "|" << std::setw(15) << "_gradeToSign"
     << "|" << std::setw(15) << "_gradeToExecute"
     << "|\n|" << std::setw(15) << form.getName() << "|" << std::setw(15)
     << form.getIsSigned() << "|" << std::setw(15) << form.getGradeToSign()
     << "|" << std::setw(15) << form.getGradeToExecute() << "|\n";
  return os;
}
