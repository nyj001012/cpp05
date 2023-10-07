/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:15:14 by yena              #+#    #+#             */
/*   Updated: 2023/10/04 16:19:35 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by 나예진 on 2023/10/04.
//

#ifndef CPP05_EX02_SHRUBBERYCREATIONFORM_HPP_
#define CPP05_EX02_SHRUBBERYCREATIONFORM_HPP_

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
 private:
  std::string _target;

 public:
  ShrubberyCreationForm(std::string target);
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
  ~ShrubberyCreationForm();
  void execute(const Bureaucrat &executor) const;

  class FileOpenException : public std::exception {
   public:
	virtual const char *what() const throw() {
	  return "Error: ShrubberyCreationForm: file open error";
	}
  };

  class FormNotSignedException : public std::exception {
   public:
	virtual const char *what() const throw() {
	  return "Error: ShrubberyCreationForm: form is not signed";
	}
  };
};

#endif //CPP05_EX02_SHRUBBERYCREATIONFORM_HPP_
