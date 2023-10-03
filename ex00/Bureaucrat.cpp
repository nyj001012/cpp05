/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@studen.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:46:56 by yena              #+#    #+#             */
/*   Updated: 2023/10/03 16:24:32 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yejin Na on 10/3/23.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name) {
  if (grade < 1)
    throw std::out_of_range(INCREASE_GRADE_ERROR);
  if (grade > 150)
    throw std::out_of_range(DECREASE_GRADE_ERROR);
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

Bureaucrat::~Bureaucrat(void) {

}

std::string Bureaucrat::getName(void) const {
  return (this->_name);
}

int Bureaucrat::getGrade(void) const {
  return (this->_grade);
}

void Bureaucrat::increaseGrade(int grade) {
  if (this->_grade - grade < 1)
    throw (char *)INCREASE_GRADE_ERROR;
  this->_grade -= grade;
}

void Bureaucrat::decreaseGrade(int grade) {
  if (this->_grade + grade > 150)
    throw (char *)DECREASE_GRADE_ERROR;
  this->_grade += grade;
}
