/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <jhvalenc@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 13:49:25 by jhvalenc          #+#    #+#             */
/*   Updated: 2026/09/23 22:09:35 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

int main(void)
{
    std::cout << "Primera prueba" << '\n';
    try
    {
        // Intentamos crear un formulario que pide un grado 0 (imposible)
        Form f1("Formulario Imposible", 0, 50);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Excepción al crear formulario: " << e.what() << '\n';
    }

    std::cout << "\nSegunda prueba" << '\n';
    try
    {
        Bureaucrat boss("Jefe", 1);
        Form f2("Permiso de Vacaciones", 50, 50);

        // Imprimimos el estado inicial del formulario
        std::cout << f2 << '\n';

        // El jefe debería poder firmarlo sin problemas
        boss.signForm(f2);

        // Comprobamos que el estado ha cambiado a "Signed"
        std::cout << f2 << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error inesperado: " << e.what() << '\n';
    }

    std::cout << "\nTercera prueba" << '\n';
    try
    {
        Bureaucrat intern("Becario", 150);
        Form f3("Acceso al Servidor", 10, 10);

        std::cout << f3 << '\n';

        // El becario tiene grado 150, el formulario pide 10. Debe fallar.
        intern.signForm(f3);

        // Comprobamos que sigue "Not signed"
        std::cout << f3 << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error inesperado: " << e.what() << '\n';
    }

    return (0);
}
