/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <jhvalenc@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 12:36:48 by jhvalenc          #+#    #+#             */
/*   Updated: 2026/10/03 14:17:31 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    :   AForm("ShrubberyCreationForm", 145, 137), _target("")
{
    std::cout << "ShrubberyCreationForm: Default Constructor Called" << '\n';
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
    :   AForm(other), _target(other._target)
{
    std::cout << "ShrubberyCreationForm: Constructor Copy Called" << '\n';
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    std::cout << "ShrubberyCreationForm: Copy assignment operator called" << '\n';
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm: Destructor called" << '\n';
}

// Los atributos _singGrade y _executeGrade de la clase base AForm,
// al ser const se debe delegar su inicialización al constructor parametrizado
// de la clase padre
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) 
    :   AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}
/*
ShrubberyCreationForm::NotSignedException::NotSignedException(const std::string& msg)
    : _msgNotSign(msg)
{
}

ShrubberyCreationForm::NotSignedException::~NotSignedException() throw()
{
}

const char* ShrubberyCreationForm::NotSignedException::what() const throw()
{
    return (_msgNotSign.c_str());
}
*/
void    ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    std::string     filename;
    std::ofstream   file;

    if (this->getSigned() == false)
        throw AForm::NotSignedException("Form is not signed!");
    if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowException("Grade is too low to execute");
    filename = this->_target + "_shrubbery";
    file.open(filename.c_str(), std::ios::out);
    if (!file)
        std::cerr << "Error: Could not open file " << filename << '\n';
    file << "       _-_" << '\n';
    file << "    /~~   ~~\\" << '\n';
    file << " /~~         ~~\\" << '\n';
    file << "{               }" << '\n';
    file << " \\  _-     -_ /" << '\n';
    file << "   ~  \\\\ //  ~" << '\n';
    file << "_- -   | | _- _" << '\n';
    file << "  _ -  | |   -_" << '\n';
    file << "      // \\\\" << '\n';
    file.close();
}
