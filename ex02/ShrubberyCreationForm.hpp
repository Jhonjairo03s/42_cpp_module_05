/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <jhvalenc@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 14:08:58 by jhvalenc          #+#    #+#             */
/*   Updated: 2026/10/02 14:08:19 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <iostream>

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
        // Función miembro
        void execute(Bureaucrat const & executor) const;
};

#endif
