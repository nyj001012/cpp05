/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:46:56 by yena              #+#    #+#             */
/*   Updated: 2023/10/10 19:57:42 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yejin Na on 10/3/23.
//

#ifndef CPP05_EX00_BUREAUCRAT_HPP_
#define CPP05_EX00_BUREAUCRAT_HPP_

#include <iostream>

#include "Form.hpp"
#include "font.hpp"

class Form;

/**
 * @property _name: constant name
 * @property _grade: ranges from 1 (highest possible grade) to
 *                   150 (lowest possible grade)
 */
class Bureaucrat {
 public:
  Bureaucrat(std::string name, int grade);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);
  ~Bureaucrat();

  std::string getName() const;
  int getGrade() const;
  void increaseGrade(int grade);
  void decreaseGrade(int grade);
  void signForm(Form &form);

  class GradeTooHighException : public std::exception {
   public:
    /**
     * @override std::exception
     * @return const char *errorMessage
     */
    virtual const char *what() const throw() { return "Error: too high grade"; }
  };

  class GradeTooLowException : public std::exception {
   public:
    /**
     * @override std::exception
     * @return const char *errorMessage
     */
    virtual const char *what() const throw() { return "Error: too low grade"; }
  };

 private:
  const std::string _name;
  int _grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif  // CPP05_EX00_BUREAUCRAT_HPP_
