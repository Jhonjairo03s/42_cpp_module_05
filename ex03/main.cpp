/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <jhvalenc@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 14:03:50 by jhvalenc          #+#    #+#             */
/*   Updated: 2026/10/06 14:11:10 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(void)
{
    // Para usar rand(), se necesita inicializar la "semilla"
    std::srand(std::time(NULL));

    std::cout << "--- CREANDO BURÓCRATAS ---" << '\n';
    Bureaucrat boss("El Jefe", 1);
    Bureaucrat mid("Oficinista", 50);
    Bureaucrat noob("Becario", 150);

    std::cout << "\n--- 1. PRUEBA: SHRUBBERY CREATION FORM ---" << '\n';
    ShrubberyCreationForm shrub("Jardin");

    // Intento de ejecución sin firma
    boss.executeForm(shrub);

    // Firma y ejecución normal (Requiere firmar 145, ejecutar 137)
    noob.signForm(shrub); // Falla, el becario es 150
    mid.signForm(shrub);  // Éxito, el oficinista es 50
    mid.executeForm(shrub); // Éxito, creará el archivo Jardin_shrubbery

    std::cout << "\n--- 2. PRUEBA: ROBOTOMY REQUEST FORM ---" << '\n';
    RobotomyRequestForm robot("Bender");

    // (Requiere firmar 72, ejecutar 45)
    mid.signForm(robot); // Éxito (50 <= 72)
    mid.executeForm(robot); // Falla (50 > 45)
    boss.executeForm(robot); // Éxito, hará ruidos y tendrá 50% de éxito

    std::cout << "\n--- 3. PRUEBA: PRESIDENTIAL PARDON FORM ---" << '\n';
    PresidentialPardonForm pardon("Zaphod");

    // (Requiere firmar 25, ejecutar 5)
    mid.signForm(pardon); // Falla (50 > 25)
    boss.signForm(pardon); // Éxito
    boss.executeForm(pardon); // Éxito, imprimirá el mensaje de perdón

    std::cout << "\n--- 4. LA PRUEBA DEL BECARIO (INTERN) ---" << '\n';
    Intern someRandomIntern;
    AForm* rrf;

    // Prueba de éxito
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf != NULL)
    {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf; // IMPORTANTE: El becario hizo un 'new', así que tú debes hacer el 'delete'
    }

    // Prueba de fallo
    AForm* failForm = someRandomIntern.makeForm("café con leche", "Jefe");
    if (failForm == NULL)
    {
        std::cout << "El formulario fallido fue gestionado correctamente devolviendo NULL." << '\n';
    }
    return (0);
}
