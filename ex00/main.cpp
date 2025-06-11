/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:22:54 by joklein           #+#    #+#             */
/*   Updated: 2025/06/11 14:02:51 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	*per1 = nullptr;
    Bureaucrat	*per2 = nullptr;
    Bureaucrat	*per3 = nullptr;
    
    std::cout << "try to create bureaucrats" << std::endl;
	try	{ 
        per1 = new Bureaucrat("Klaus", 2);}
	catch (const std::exception &e) {
        std::cout << e.what() << std::endl;}
    
    try {
        per2 = new Bureaucrat("Hans", 149);}
    catch(const std::exception& e) {
        std::cout << e.what() << std::endl;}
    
    try {
        per3 = new Bureaucrat("Max", 0);}
    catch(const std::exception& e) {
        std::cout << e.what() << std::endl;}

    
	if (per1)
	{
		std::cout << "\nPersonal 1: " << *per1 << std::endl;
        std::cout << "try to increment grade" << std::endl;
        try {
            per1->incrementGrade();
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << "Personal 1: " << *per1 << std::endl;
        std::cout << "try to increment grade" << std::endl;
        try {
            per1->incrementGrade();
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << "Personal 1: " << *per1 << std::endl;
        delete per1;
	}

    
    if (per2)
	{
		std::cout << "\nPersonal 2: " << *per2 << std::endl;
        std::cout << "try to decrement grade" << std::endl;
        try {
            per2->decrementGrade();
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << "Personal 2: " << *per2 << std::endl;
        std::cout << "try to decrement grade" << std::endl;
        try {
            per2->decrementGrade();
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << "Personal 2: " << *per2 << std::endl;
        delete per2;
	}

    
    if (per3)
	{
		std::cout << "\nPersonal 3 exist?" << std::endl;
        delete per3;
	}
}
