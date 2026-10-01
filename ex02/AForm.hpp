/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <jhvalenc@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:57:35 by jhvalenc          #+#    #+#             */
/*   Updated: 2026/10/01 13:29:11 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

# include "Bureaucrat.hpp"

class   AForm
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _signGrade;
        const int           _executeGrade;
    public:
        // Forma Canónica Ortodoxa
        AForm();
        AForm(const AForm& other);
        AForm&   operator=(const AForm& other);
        ~AForm();
        // Constructor parametrizado
        AForm(const std::string name, int sign_grade, int execute_grade);
        //Herencia exception
        class   GradeTooHighException : public std::exception
        {
            private:
                std::string _msgHigh;
            public:
                GradeTooHighException(const std::string& msg);
                virtual ~GradeTooHighException() throw();
                virtual const char* what() const throw();
        };
        class   GradeTooLowException : public std::exception
        {
            private:
                std::string _msgLow;
            public:
                GradeTooLowException(const std::string& msg);
                virtual ~GradeTooLowException() throw();
                virtual const char* what() const throw();
        };
        // Función Miembro
        void    beSigned(Bureaucrat& bureaucrat);
        virtual void    execute(Bureaucrat const & executor) const = 0;
        // Getters
        const std::string&    getName(void) const;
        bool    getSigned(void) const;
        int     getSignGrade(void) const;
        int     getExecuteGrade(void) const;
};

std::ostream&   operator<<(std::ostream& os, const AForm& form);

#endif
