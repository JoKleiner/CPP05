/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:22:54 by joklein           #+#    #+#             */
/*   Updated: 2025/06/25 14:40:06 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"

int	main()
{
    std::cout << "\ncreate bureaucrat:" << std::endl;
	Bureaucrat bureauc1("Hans", 45);
    Bureaucrat bureauc2("Mom t.Ripper", 1);
    
    std::cout << "\ncreate forms:" << std::endl;
    ShrubberyCreationForm shrubby("home");
    PresidentialPardonForm pardon("J.t.Ripper");
    RobotomyRequestForm roboty("toilet");
    
    std::cout << "\n________________________________________\n\nsign and execute shrubby:\n" << std::endl;
    try {
        bureauc1.signForm(shrubby);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        bureauc1.executeForm(shrubby);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n________________________________________\n\nsign and execute pardon:\n" << std::endl;
    try {
        bureauc2.signForm(pardon);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        bureauc2.executeForm(pardon);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n________________________________________\n\nsign and execute roboty 5 times:\n" << std::endl;
    try {
        bureauc1.signForm(roboty);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    for (int i = 1; i <= 5; i++)
    {
        std::cout << i << ": ";
        try {
            bureauc1.executeForm(roboty);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

}
