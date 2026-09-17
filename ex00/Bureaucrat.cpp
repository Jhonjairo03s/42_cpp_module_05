/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <jhvalenc@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 20:00:06 by jhvalenc          #+#    #+#             */
/*   Updated: 2026/09/16 20:19:02 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(0)
{
    std::cout << "Default Constructor Called" << '\n';
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
    std::cout << "Constructor Copy Called" << '\n';
    this->_grade = other._grade;
}
