/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 07:21:34 by yena              #+#    #+#             */
/*   Updated: 2023/10/10 14:47:45 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by 나예진 on 2023/10/08.
//

#ifndef CPP05_EX02_ROBOTOMYREQUESTFORM_HPP_
#define CPP05_EX02_ROBOTOMYREQUESTFORM_HPP_

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
 private:
  std::string _target;

 public:
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(const RobotomyRequestForm &other);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
  ~RobotomyRequestForm();
  void execute(Bureaucrat const &executor) const;

  class FormNotSignedException : public std::exception {
   public:
    virtual const char *what() const throw() {
      return "Error: RobotomyRequestForm: form is not signed";
	}
  };
};

#endif //CPP05_EX02_ROBOTOMYREQUESTFORM_HPP_
