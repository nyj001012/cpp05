/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@studen.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:42:55 by yena              #+#    #+#             */
/*   Updated: 2023/10/03 16:48:18 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01__FORM_HPP_
#define EX01__FORM_HPP_

#include <iostream>

/**
 * @private const std::string _name
 * @private bool _isSigned;
 * @private const int _grade
 */
class Form {
 private:
  const std::string _name;
  bool _isSigned;
  const int _grade;
};

#endif //EX01__FORM_HPP_
