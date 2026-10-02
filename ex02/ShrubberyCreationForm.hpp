/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <jhvalenc@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 14:08:58 by jhvalenc          #+#    #+#             */
/*   Updated: 2026/10/02 19:28:00 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <fstream>

class   ShrubberyCreationForm : public AForm
{
    private:
        const std::string   _target;
    public:
        // Forma Canónica Ortodoxa
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm&  operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();
        // Constructor parametrizado
        ShrubberyCreationForm(const std::string target);
        // Herencia exception
        class   NotSignedException : public std::exception
        {
            private:
                std::string _msgNotSign;
            public:
                NotSignedException(const std::string& msg);
                virtual ~NotSignedException() throw();
                virtual const char* what() const throw();
        }
        // Función miembro
        void execute(Bureaucrat const& executor) const;
};

#endif
