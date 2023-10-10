/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:42:55 by yena              #+#    #+#             */
/*   Updated: 2023/10/10 19:03:36 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01__FORM_HPP_
#define EX01__FORM_HPP_

#include <iomanip>
#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

/**
 * @private const std::string _name
 * @private bool _isSigned
 * @private const int _grade (1 ~ 150)
 */
class Form {
 public:
  Form(std::string name, int gradeToSign, int gradeToExecute);
  Form(const Form &other);
  Form &operator=(const Form &other);
  ~Form();
  const std::string getName() const;
  bool getIsSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;
  void beSigned(const Bureaucrat &bureaucrat);

  class GradeTooHighException : public std::exception {
   public:
    virtual const char *what() const throw() {
      return "Error: Form: grade is too high";
    }
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char *what() const throw() {
      return "Error: Form: grade is too low";
    }
  };

 private:
  const std::string _name;
  bool _isSigned;
  const int _gradeToSign;
  const int _gradeToExecute;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif  // EX01__FORM_HPP_
