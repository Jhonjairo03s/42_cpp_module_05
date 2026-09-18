/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <jhvalenc@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 17:07:39 by jhvalenc          #+#    #+#             */
/*   Updated: 2026/09/18 13:58:46 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name(""), _signed(false), _signGrade(150), _executeGrade(150)
{
    std::cout << "Default Constructor Called" << '\n';
}

Form::Form(const Form& other) : _name(other._name), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
    std::cout << "Constructor Copy Called" << '\n';
    this->_signed = other._signed;
}

Form& Form::operator=(const Form& other)
{
    std::cout << "Copy assignment operator called" << '\n';
    if (this != &other)
        this->_signed = other._signed;
    return (*this);
}

Form::~Form()
{
    std::cout << "Destructor called" << '\n';
}

Form::Form(const std::string name, int sign_grade, int execute_grade) : _name(name) , _signGrade(sign_grade) , _executeGrade(execute_grade)
{
    if (this->_signGrade < 1)
        throw GradeTooHighException("Grade too high");
    if (this->_signGrade > 150)
        throw GradeTooLowException("Grade too low");
    if (this->_executeGrade < 1)
        throw GradeTooHighException("Grade too high");
    if (this->_executeGrade > 150)
        throw GradeTooLowException("Grade too low");
}

Form::GradeTooHighException::GradeTooHighException(const std::string& msg) : _msgHigh(msg)
{
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
}

const char* Form::GradeTooHighException::what() const throw()
{
    return (_msgHigh.c_str());
}

Form::GradeTooLowException::GradeTooLowException(const std::string& msg) : _msgLow(msg)
{
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
}

const char* Form::GradeTooLowException::what() const throw()
{
    return (_msgLow.c_str());
}

void    Form::beSigned(Bureaucrat& bureaucrat)
{
    if(bureaucrat.getGrade() <= this->_signGrade)
        this->_signed = true;
    else
        throw GradeTooLowException("Grade too low");
}

const std::string&  Form::getName(void) const
{
    return (this->_name);
}

bool    Form::getSigned(void) const
{
    return (this->_signed);
}

int Form::getSignGrade(void) const
{
    return (this->_signGrade);
}

int Form::getExecuteGrade(void) const
{
    return (this->_executeGrade);
}

std::ostream&   operator<<(std::ostream& os, const Form& form)
{
    os << "Form: " << form.getName()
       << ", Status: " << (form.getSigned() ? "Signed" : "Not signed")
       << ", Sign Grade required: " << form.getSignGrade()
       << ", Execute Grade required: " << form.getExecuteGrade() << '.';
    return (os);
}
