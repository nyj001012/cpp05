/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:46:56 by yena              #+#    #+#             */
/*   Updated: 2023/10/10 18:36:10 by yena             ###   ########.fr       */
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
