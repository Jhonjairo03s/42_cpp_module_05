/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <jhvalenc@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 13:05:26 by jhvalenc          #+#    #+#             */
/*   Updated: 2026/10/06 14:26:36 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern: Default Constructor Called" << '\n';
}

Intern::Intern(const Intern& other)
{
    (void)other;
    std::cout << "Intern: Constructor Copy Called" << '\n';
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    std::cout << "Intern: Copy assignment operator called" << '\n';
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern: Destructor called" << '\n';
}

AForm*  Intern::makeShrubbery(std::string target) const
{
    return (new ShrubberyCreationForm(target));
}

AForm*  Intern::makeRobotomy(std::string target) const
{
    return (new RobotomyRequestForm(target));
}

AForm*  Intern::makePresidential(std::string target) const
{
    return (new PresidentialPardonForm(target));
}

AForm*  Intern::makeForm(std::string formName, std::string target) const
{
    int index;

    std::string formNames[3] = {
        "shrubbery creation", "robotomy request", "presidential pardon"
    };

    AForm*  (Intern::*formMakes[3])(std::string) const = {
        &Intern::makeShrubbery,
        &Intern::makeRobotomy,
        &Intern::makePresidential
    };

    index = 0;
    while (index < 3)
    {
        if (formName == formNames[index])
        {
            std::cout << "Intern creates " << formName << '\n';
            return ((this->*formMakes[index])(target));
        }
        index++;
    }
    std::cerr << "Intern failed to create form: '" << formName << "' does not exist." << '\n';
    return (NULL);
}
