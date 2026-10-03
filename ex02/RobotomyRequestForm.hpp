/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <jhvalenc@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 13:49:33 by jhvalenc          #+#    #+#             */
/*   Updated: 2026/10/03 14:33:02 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>

class   RobotomyRequestForm : public AForm
{
    private:
        const std::string   _target;
    public:
        // Forma Canónica Ortodoxa
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm&    operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();
        // Constructor parametrizado
        RobotomyRequestForm(const std::string target);
        // Función miembro
        void    execute(Bureaucrat const& executor) const;
};

#endif
