/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <jhvalenc@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:57:35 by jhvalenc          #+#    #+#             */
/*   Updated: 2026/09/17 17:50:42 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include "Bureaucrat.hpp"

class   Form
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _signGrade;
        const int           _executeGrade;
    public:
        // Forma Canónica Ortodoxa
        Form();
        Form(const Form& other);
        Form&   operator=(const Form& other);
        ~Form();
        // Constructor parametrizado
        Form(const std::string name, int sign_grade, int execute_grade);
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
        // Getters
        const std::string&    getName(void) const;
        bool    getSigned(void) const;
        int     getSignGrade(void) const;
        int     getExecuteGrade(void) const;
};

std::ostream&   operator<<(std::ostream& os, const Form& form);

#endif
