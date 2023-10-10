/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 07:52:18 by yena              #+#    #+#             */
/*   Updated: 2023/10/10 14:48:02 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by 나예진 on 2023/10/08.
//

#ifndef CPP05_EX02_PRESIDENTIALPARDONFORM_HPP_
#define CPP05_EX02_PRESIDENTIALPARDONFORM_HPP_

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
 private:
  std::string _target;

 public:
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(const PresidentialPardonForm &other);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
  ~PresidentialPardonForm();
  void execute(Bureaucrat const &executor) const;

  class FormNotSignedException : public std::exception {
   public:
    virtual const char *what() const throw() {
      return "Error: PresidentialPardonForm: form is not signed";
	}
  };
};

#endif //CPP05_EX02_PRESIDENTIALPARDONFORM_HPP_
