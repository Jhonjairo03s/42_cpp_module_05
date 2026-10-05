/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <jhvalenc@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 16:09:16 by jhvalenc          #+#    #+#             */
/*   Updated: 2026/10/05 18:10:18 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    :   AForm("PresidentialPardonForm", 25, 5), _target("")
{
    std::cout << "PresidentialPardonForm: Default Constructor Called" << '\n';
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    :   AForm(other), _target(other._target)
{
    std::cout << "PresidentialPardonForm: Constructor Copy Called" << '\n';
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    std::cout << "PresidentialPardonForm: Copy assignment operator called" << '\n';
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm: Destructor called" << '\n';
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
    :   AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

void    PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if (this->getSigned() == false)
        throw AForm::NotSignedException("Form is not signed!");
    if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowException("Grade is too low to execute");
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << '\n';
}
