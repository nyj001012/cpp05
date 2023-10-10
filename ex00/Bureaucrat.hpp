/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:46:56 by yena              #+#    #+#             */
/*   Updated: 2023/10/10 17:57:21 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yejin Na on 10/3/23.
//

#ifndef CPP05_EX00_BUREAUCRAT_HPP_
#define CPP05_EX00_BUREAUCRAT_HPP_

#include <iostream>

// font colour
#define F_BLACK "\033[0;30m"
#define F_RED "\033[0;31m"
#define F_GREEN "\033[0;32m"
#define F_YELLOW "\033[0;33m"
#define F_BLUE "\033[0;34m"
#define F_MAGENTA "\033[0;35m"
#define F_CYAN "\033[0;36m"
#define F_WHITE "\033[0;37m"
#define FB_DEFAULT "\033[0m"

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

  class GradeTooHighException: public std::exception {
   public:
    /**
     * @override std::exception
     * @return const char *errorMessage
     */
    virtual const char *what() const throw() {
      return "Error: too high grade";
    }
  };

  class GradeTooLowException: public std::exception {
   public:
    /**
     * @override std::exception
     * @return const char *errorMessage
     */
    virtual const char *what() const throw() {
      return "Error: too low grade";
    }
  };

  private:
    const std::string _name;
    int _grade;

};

 std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif //CPP05_EX00_BUREAUCRAT_HPP_
