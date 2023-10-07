/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:15:14 by yena              #+#    #+#             */
/*   Updated: 2023/10/04 16:19:02 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by 나예진 on 2023/10/04.
//

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm(target + "_shrubbery", 145, 137) {
  this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other) {
  if (this != &other)
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  if (this != &other) {
	this->_target = other._target;
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

/**
 * create a file with the name of the target and write a tree in it
 * @param bureaucrat
 */
void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const {
  if (bureaucrat.getGrade() > this->getGradeToExecute())
	throw ShrubberyCreationForm::GradeTooLowException();
  else if (!this->getIsSigned())
	throw ShrubberyCreationForm::FormNotSignedException();
  else {
	std::ofstream file;
	file.open(this->getName());
	if (!file.is_open())
	  throw ShrubberyCreationForm::FileOpenException();
    file << "                   ___" << std::endl;
    file << "            _,-'\"\"   \"\"\"\"`--." << std::endl;
    file << "         ,-'          __,,-- \\" << std::endl;
    file << "       ,'    __,--\"\"\"\"dF      )" << std::endl;
    file << "      /   .-\"Hb_,--\"\"dF      /" << std::endl;
    file << "    ,'       _Hb ___dF\"-._,-'" << std::endl;
    file << "  ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
    file << " (     ,-'                  `." << std::endl;
    file << "  `._,'     _   _             ;" << std::endl;
    file << "   ,'     ,' `-'Hb-.___..._,-'" << std::endl;
    file << "   \\    ,'\"Hb.-'HH`-.dHF\"" << std::endl;
    file << "    `--'   \"Hb  HH  dF\"" << std::endl;
    file << "            \"Hb HH dF" << std::endl;
    file << "             \"HbHHdF" << std::endl;
    file << "              |HHHF" << std::endl;
    file << "              |HHH|" << std::endl;
    file << "              |HHH|" << std::endl;
    file << "              |HHH|" << std::endl;
    file << "              |HHH|" << std::endl;
    file << "              dHHHb" << std::endl;
    file << "            .dFd|bHb.               o" << std::endl;
    file << "  o       .dHFdH|HbTHb.          o /" << std::endl;
	file << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << std::endl;
	file << "##########################################" << std::endl;
	file.close();
 }
}
