/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 07:52:18 by yena              #+#    #+#             */
/*   Updated: 2023/10/10 19:20:02 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by 나예진 on 2023/10/08.
//

#ifndef CPP05_EX02_PRESIDENTIALPARDONFORM_HPP_
#define CPP05_EX02_PRESIDENTIALPARDONFORM_HPP_

#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

class PresidentialPardonForm : public Form {
 public:
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(const PresidentialPardonForm &other);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
  ~PresidentialPardonForm();
  void execute(Bureaucrat const &executor) const;

 private:
  std::string _target;

  class FormNotSignedException : public std::exception {
   public:
    virtual const char *what() const throw() {
      return "Error: PresidentialPardonForm: form is not signed";
    }
  };
};

#endif  // CPP05_EX02_PRESIDENTIALPARDONFORM_HPP_
