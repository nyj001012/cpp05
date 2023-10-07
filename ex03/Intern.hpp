/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 08:09:18 by yena              #+#    #+#             */
/*   Updated: 2023/10/08 08:30:50 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by 나예진 on 2023/10/08.
//

#ifndef CPP05_EX03_INTERN_HPP_
#define CPP05_EX03_INTERN_HPP_

#include <iostream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
 private:

 public:
  Intern();
  Intern(const Intern &other);
  Intern &operator=(const Intern &other);
  ~Intern();
  Form *makeForm(std::string formName, std::string target);
  class InvalidFormNameException : public std::exception {
   public:
	virtual const char *what() const throw() {
	  return "Error: Intern: I don't know what form you want to make";
	}
  };
};

#endif //CPP05_EX03_INTERN_HPP_
