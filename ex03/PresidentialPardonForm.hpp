/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <jhvalenc@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 15:23:52 by jhvalenc          #+#    #+#             */
/*   Updated: 2026/10/03 15:27:51 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class   PresidentialPardonForm : public AForm
{
    private:
        const std::string   _target;
    public:
        // Forma Canónica Ortodoxa
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        // Función miembro
        ~PresidentialPardonForm();
        PresidentialPardonForm(const std::string target);
        // Función miembro
        void    execute(Bureaucrat const& executor) const;
};

#endif
