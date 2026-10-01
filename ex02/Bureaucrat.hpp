/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <jhvalenc@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 12:23:07 by jhvalenc          #+#    #+#             */
/*   Updated: 2026/09/17 17:30:51 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  BUREAUCRAT_HPP
# define    BUREAUCRAT_HPP

# include <iostream>
# include <exception>

// Declaración Anticipada
class   Form;

class   Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
    public:
        // Forma Canónica Ortodoxa
        Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        // Constructor parametrizado
        Bureaucrat(const std::string name, int grade);
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
        // Funciones Miembro
        void    increment();
        void    decrement();
        void    signForm(Form& form);
        // Getters
        int getGrade(void) const;
        const std::string&    getName(void) const;
};

std::ostream&   operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
