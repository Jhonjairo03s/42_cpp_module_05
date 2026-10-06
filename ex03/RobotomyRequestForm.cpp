/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <jhvalenc@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 14:10:28 by jhvalenc          #+#    #+#             */
/*   Updated: 2026/10/03 14:36:58 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    :   AForm("RobotomyRequestForm", 72, 45), _target("")
{
    std::cout << "RobotomyRequestForm: Default Constructor Called" << '\n';
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    :   AForm(other), _target(other._target)
{
    std::cout << "RobotomyRequestForm: Constructor Copy Called" << '\n';
}

RobotomyRequestForm&    RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    std::cout << "RobotomyRequestForm: Copy assignment operator called" << '\n';
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm: Destructor called" << '\n';
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
    :   AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

void    RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    int n;

    if (this->getSigned() == false)
        throw AForm::NotSignedException("Form is not signed!");
    if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowException("Grade is too low to execute");
    std::cout << "* Drilling noises: ZZZZZZZZZZZ! Brrrrrrr! *" << '\n';
    n = std::rand() % 2;
    if (n == 0)
        std::cout << this->_target << " has been robotomized successfully!" << '\n';
    else
        std::cout << "The robotomy of " << this->_target << " has failed." << '\n';
}
