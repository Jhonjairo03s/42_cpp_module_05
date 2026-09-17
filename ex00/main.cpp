/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhvalenc <jhvalenc@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 13:49:25 by jhvalenc          #+#    #+#             */
/*   Updated: 2026/09/17 16:39:02 by jhvalenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    std::cout << " Primera prueba" << '\n';
    try
    {
        Bureaucrat hermes("Hermes", 75);
        std::cout << hermes;
        hermes.increment();
        std::cout << "Tras ascender: " << hermes;
    }
    catch (std::exception& e)
    {
        std::cerr << "Excepción: " << e.what() << '\n';
    }

    std::cout << "\n Segundo prueba" << '\n';
    try
    {
        Bureaucrat zeus("Zeus", 0);
        std::cout << zeus;
    }
    catch (std::exception& e)
    {
        std::cerr << "Excepción capturada: " << e.what() << '\n';
    }

    std::cout << "\n Tercera prueba" << '\n';
    try
    {
        Bureaucrat zoidberg("Zoidberg", 151);
        std::cout << zoidberg;
    }
    catch (std::exception& e)
    {
        std::cerr << "Excepción capturada: " << e.what() << '\n';
    }

    std::cout << "\n Cuarta prueba" << '\n';
    try
    {
        Bureaucrat boss("Jefe", 1);
        std::cout << boss;
        std::cout << "Intentando ascender..." << '\n';
        boss.increment();
        std::cout << boss;
    }
    catch (std::exception& e)
    {
        std::cerr << "Excepción capturada: " << e.what() << '\n';
    }

    std::cout << "\n Quinta prueba" << '\n';
    try
    {
        Bureaucrat sad("Milton", 150);
        std::cout << sad;
        std::cout << "Intentando degradar..." << '\n';
        sad.decrement();
        std::cout << sad;
    }
    catch (std::exception& e)
    {
        std::cerr << "Excepción capturada: " << e.what() << '\n';
    }

    std::cout << "\n Sexta prueba" << '\n';
    try
    {
        Bureaucrat cleo("Patra", 6);
        Bureaucrat patra = cleo;
        std::cout << patra;
        std::cout << "Decremento copia..." << '\n';
        patra.decrement();
        patra.decrement();
        std::cout << patra;
        std::cout << "Incremento original.." << '\n';
        cleo.increment();
        std::cout << cleo;
    }
    catch (std::exception& e)
    {
        std::cerr << "Excepción: " << e.what() << '\n';
    }

    return (0);
}
