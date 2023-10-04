/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@studen.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:42:55 by yena              #+#    #+#             */
/*   Updated: 2023/10/04 14:28:11 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01__FORM_HPP_
#define EX01__FORM_HPP_

#include <iostream>
#include "Bureaucrat.hpp"

/**
 * @private const std::string _name
 * @private bool _isSigned
 * @private const int _grade (1 ~ 150)
 */
class Form {
 private:
  const std::string _name;
  bool _isSigned;
  const int _grade;

 public:
  Form(std::string name, int grade);
  Form(const Form &other);
  Form &operator=(const Form &other);
  ~Form();
  const std::string getName() const;
  bool getIsSigned() const;
  int getGrade() const;
  void beSigned(const Bureaucrat &bureaucrat);
};

class GradeTooHighException : public std::exception {
 public:
  virtual const char* what() const throw() {
	return "Error: grade of Form is too high";
  }
};

class GradeTooLowException : public std::exception {
 public:
  virtual const char* what() const throw() {
	return "Error: grade of Form is too low"
  }
};

#endif //EX01__FORM_HPP_
