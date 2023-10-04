/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:00:37 by yena              #+#    #+#             */
/*   Updated: 2023/10/04 16:29:54 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01__AForm_HPP_
#define EX01__AForm_HPP_

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

/**
 * @private const std::string _name
 * @private bool _isSigned
 * @private const int _grade (1 ~ 150)
 */
class AForm {
 private:
  const std::string _name;
  bool _isSigned;
  const int _gradeToSign;
  const int _gradeToExecute;

 public:
  AForm(std::string name, int gradeToSign, int gradeToExecute);
  AForm(const AForm &other);
  AForm &operator=(const AForm &other);
  virtual ~AForm();
  const std::string getName() const;
  bool getIsSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;
  void beSigned(const Bureaucrat &bureaucrat);
  virtual void execute(const Bureaucrat &executor) const = 0;

  class GradeTooHighException : public std::exception {
   public:
	virtual const char* what() const throw() {
	  return "Error: Form: grade is too high";
	}
  };

  class GradeTooLowException : public std::exception {
   public:
	virtual const char* what() const throw() {
	  return "Error: Form: grade is too low";
	}
  };
};

std::ostream &operator<<(std::ostream &os, const AForm &AForm);

#endif //EX01__AForm_HPP_
