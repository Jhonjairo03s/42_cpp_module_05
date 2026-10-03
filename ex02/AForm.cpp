/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <jhvalenc@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 13:33:49 by jhvalenc          #+#    #+#             */
/*   Updated: 2026/10/03 14:08:32 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name(""), _signed(false), _signGrade(150), _executeGrade(150)
{
    std::cout << "Default Constructor Called" << '\n';
}

AForm::AForm(const AForm& other) : _name(other._name), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
    std::cout << "Constructor Copy Called" << '\n';
    this->_signed = other._signed;
}

AForm& AForm::operator=(const AForm& other)
{
    std::cout << "Copy assignment operator called" << '\n';
    if (this != &other)
        this->_signed = other._signed;
    return (*this);
}

AForm::~AForm()
{
    std::cout << "Destructor called" << '\n';
}

AForm::AForm(const std::string name, int sign_grade, int execute_grade) 
    : _name(name) , _signed(false), _signGrade(sign_grade) , _executeGrade(execute_grade)
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

AForm::GradeTooHighException::GradeTooHighException(const std::string& msg) : _msgHigh(msg)
{
}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return (_msgHigh.c_str());
}

AForm::GradeTooLowException::GradeTooLowException(const std::string& msg) : _msgLow(msg)
{
}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return (_msgLow.c_str());
}

AForm::NotSignedException::NotSignedException(const std::string& msg)
    : _msgNotSign(msg)
{
}

AForm::NotSignedException::~NotSignedException() throw()
{
}

const char* AForm::NotSignedException::what() const throw()
{
    return (_msgNotSign.c_str());
}

void    AForm::beSigned(Bureaucrat& bureaucrat)
{
    if(bureaucrat.getGrade() <= this->_signGrade)
        this->_signed = true;
    else
        throw GradeTooLowException("Grade too low");
}

const std::string&  AForm::getName(void) const
{
    return (this->_name);
}

bool    AForm::getSigned(void) const
{
    return (this->_signed);
}

int AForm::getSignGrade(void) const
{
    return (this->_signGrade);
}

int AForm::getExecuteGrade(void) const
{
    return (this->_executeGrade);
}

std::ostream&   operator<<(std::ostream& os, const AForm& form)
{
    os << "Form: " << form.getName()
       << ", Status: " << (form.getSigned() ? "Signed" : "Not signed")
       << ", Sign Grade required: " << form.getSignGrade()
       << ", Execute Grade required: " << form.getExecuteGrade() << '.';
    return (os);
}
