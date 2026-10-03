/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <jhvalenc@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 19:41:51 by jhvalenc          #+#    #+#             */
/*   Updated: 2026/10/03 14:45:37 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp" 

int main(void)
{
    // Para usar rand(), se necesita inicializar la "semilla"
    std::srand(std::time(NULL));

    std::cout << "=== 1. PRUEBAS DE CREACION Y RANGOS ==- " << std::endl;
    {
        try {
            // ShrubberyCreationForm requiere: Sign 145, Exec 137
            Bureaucrat lowRank("Novato", 150);
            Bureaucrat midRank("Intermedio", 140);
            Bureaucrat highRank("Jefe", 1);
            
            ShrubberyCreationForm form("jardin");

            std::cout << form << std::endl;

            // Intento 1: Burócrata con rango muy bajo para firmar (150 > 145)
            std::cout << "\n[Prueba] " << lowRank.getName() << " intenta firmar el formulario:" << std::endl;
            lowRank.signForm(form);

            // Intento 2: Burócrata con rango suficiente para firmar (140 <= 145)
            std::cout << "\n[Prueba] " << midRank.getName() << " intenta firmar el formulario:" << std::endl;
            midRank.signForm(form);

            std::cout << form << std::endl;

            // Intento 3: Ejecutar sin rango suficiente de ejecución (140 > 137)
            std::cout << "\n[Prueba] " << midRank.getName() << " intenta ejecutar el formulario (sin rango de ejecucion):" << std::endl;
            midRank.executeForm(form);

            // Intento 4: Ejecutar con rango suficiente (1 <= 137)
            std::cout << "\n[Prueba] " << highRank.getName() << " intenta ejecutar el formulario:" << std::endl;
            highRank.executeForm(form);

        } catch (std::exception &e) {
            std::cout << "Excepcion capturada: " << e.what() << std::endl;
        }
    }

    std::cout << "\n=== 2. PRUEBA DE EJECUTAR SIN FIRMAR ===" << std::endl;
    {
        try {
            Bureaucrat boss("Director", 1);
            ShrubberyCreationForm unsignedForm("casa");

            std::cout << unsignedForm << std::endl;

            // Intentar ejecutar un formulario que no ha sido firmado
            boss.executeForm(unsignedForm);

        } catch (std::exception &e) {
            std::cout << "Excepcion capturada correctamente: " << e.what() << std::endl;
        }
    }

    std::cout << '\n';

    std::cout << "=== 1. PRUEBAS DE CREACION Y RANGOS (ROBOTOMY) ===" << std::endl;
    {
        try {
            // RobotomyRequestForm requiere: Sign 72, Exec 45
            Bureaucrat lowRank("Novato", 80);
            Bureaucrat midRank("Intermedio", 70);
            Bureaucrat highRank("Jefe", 1);

            RobotomyRequestForm form("Bender");

            std::cout << form << std::endl;

            // Intento 1: Burócrata con rango muy bajo para firmar (80 > 72)
            std::cout << "\n[Prueba] " << lowRank.getName() << " intenta firmar el formulario:" << std::endl;
            lowRank.signForm(form);

            // Intento 2: Burócrata con rango suficiente para firmar (70 <= 72)
            std::cout << "\n[Prueba] " << midRank.getName() << " intenta firmar el formulario:" << std::endl;
            midRank.signForm(form);

            std::cout << form << std::endl;

            // Intento 3: Ejecutar sin rango suficiente de ejecución (70 > 45)
            std::cout << "\n[Prueba] " << midRank.getName() << " intenta ejecutar el formulario (sin rango de ejecucion):" << std::endl;
            midRank.executeForm(form);

            // Intento 4: Ejecutar con rango suficiente (1 <= 45) -> Debería hacer los ruidos y el 50/50
            std::cout << "\n[Prueba] " << highRank.getName() << " intenta ejecutar el formulario:" << std::endl;
            highRank.executeForm(form);

        } catch (std::exception &e) {
            std::cout << "Excepcion capturada: " << e.what() << std::endl;
        }
    }

    std::cout << "\n=== 2. PRUEBA DE EJECUTAR SIN FIRMAR ===" << std::endl;
    {
        try {
            Bureaucrat boss("Director", 1);
            RobotomyRequestForm unsignedForm("C3PO");

            std::cout << unsignedForm << std::endl;

            // Intentar ejecutar un formulario que no ha sido firmado
            boss.executeForm(unsignedForm);

        } catch (std::exception &e) {
            std::cout << "Excepcion capturada correctamente: " << e.what() << std::endl;
        }
    }

    std::cout << "\n=== 3. PRUEBA DE PROBABILIDAD (50% EXITO / 50% FALLO) ===" << std::endl;
    {
        try {
            Bureaucrat boss("Director", 1);
            RobotomyRequestForm luckyForm("R2D2");

            boss.signForm(luckyForm);

            std::cout << "\n[Prueba] Ejecutando varias veces para comprobar el 50% de exito/fallo:" << std::endl;
            for (int i = 0; i < 4; ++i) {
                std::cout << "--- Intento " << i + 1 << " ---" << std::endl;
                boss.executeForm(luckyForm);
            }

        } catch (std::exception &e) {
            std::cout << "Excepcion capturada: " << e.what() << std::endl;
        }
    }

    return (0);
}
