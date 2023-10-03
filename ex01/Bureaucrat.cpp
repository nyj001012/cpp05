/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@studen.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:46:56 by yena              #+#    #+#             */
/*   Updated: 2023/10/03 16:55:55 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yejin Na on 10/3/23.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name) {
  if (grade < 1)
    throw GradeTooHighException();
  if (grade > 150)
    throw GradeTooLowException();
  this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
  if (this != &other)
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this != &other) {
    this->_grade = other._grade;
  }
  return (*this);
}

Bureaucrat::~Bureaucrat() {

}

std::string Bureaucrat::getName() const {
  return (this->_name);
}

int Bureaucrat::getGrade() const {
  return (this->_grade);
}

void Bureaucrat::increaseGrade(int grade) {
  if (this->_grade - grade < 1)
    throw GradeTooHighException();
  this->_grade -= grade;
}

void Bureaucrat::decreaseGrade(int grade) {
  if (this->_grade + grade > 150)
    throw GradeTooLowException();
  this->_grade += grade;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.getName()
     << ", bureaucrat grade "
     << std::to_string(bureaucrat.getGrade())
     << ".";
  return os;
}