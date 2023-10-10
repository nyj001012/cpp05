/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:46:56 by yena              #+#    #+#             */
/*   Updated: 2023/10/10 19:01:07 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yejin Na on 10/3/23.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
  try {
    if (grade < 1) throw Bureaucrat::GradeTooHighException();
    if (grade > 150) throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
  } catch (std::exception &e) {
    std::cout << F_RED << e.what() << FB_DEFAULT << std::endl;
  }
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
  if (this != &other) *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this != &other) {
    this->_grade = other._grade;
  }
  return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return this->_name; }

int Bureaucrat::getGrade() const { return this->_grade; }

void Bureaucrat::increaseGrade(int grade) {
  try {
    if (this->_grade - grade < 1) throw Bureaucrat::GradeTooHighException();
    this->_grade -= grade;
  } catch (std::exception &e) {
    std::cout << F_RED << e.what() << FB_DEFAULT << std::endl;
  }
}

void Bureaucrat::decreaseGrade(int grade) {
  try {
    if (this->_grade + grade > 150) throw Bureaucrat::GradeTooLowException();
    this->_grade += grade;
  } catch (std::exception &e) {
    std::cout << F_RED << e.what() << FB_DEFAULT << std::endl;
  }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade "
     << std::to_string(bureaucrat.getGrade()) << ".";
  return os;
}

void Bureaucrat::signForm(Form &form) {
  try {
    if (!form.getIsSigned()) form.beSigned(*this);
    std::cout << this->getName() << " signed " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << F_RED;
    std::cout << this->getName() << " cannot sign " << form.getName()
              << " because ";
    std::cout << e.what() << std::endl;
    std::cout << FB_DEFAULT;
  }
}
