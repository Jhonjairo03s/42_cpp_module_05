/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <jhvalenc@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 20:00:06 by jhvalenc          #+#    #+#             */
/*   Updated: 2026/09/17 16:16:25 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{
    std::cout << "Default Constructor Called" << '\n';
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
    std::cout << "Constructor Copy Called" << '\n';
    this->_grade = other._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "Copy assignment operator called" << '\n';
    if (this != &other)
        this->_grade = other._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << '\n';
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
    if (this->_grade < 1)
        throw GradeTooHighException("Grade too high");
    if (this->_grade > 150)
        throw GradeTooLowException("Grade too low");
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& msg) : _msgHigh(msg)
{
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return (_msgHigh.c_str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& msg) : _msgLow(msg)
{
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return (_msgLow.c_str());
}

void    Bureaucrat::increment(void)
{
    this->_grade = this->_grade - 1;
    if (this->_grade < 1)
        throw GradeTooHighException("Grade too high");
}

void    Bureaucrat::decrement(void)
{
    this->_grade = this->_grade + 1;
    if (this->_grade > 150)
        throw GradeTooLowException("Grade too low");
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

const std::string&  Bureaucrat::getName(void) const
{
    return(this->_name);
}

std::ostream&   operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << '.' << '\n';
    return (os);
}
