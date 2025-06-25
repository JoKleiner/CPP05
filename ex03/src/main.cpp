/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:22:54 by joklein           #+#    #+#             */
/*   Updated: 2025/06/25 16:29:32 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Intern.hpp"

int	main()
{
    std::cout << "\ncreate bureaucrat and rdmintern:" << std::endl;
	Bureaucrat bureauc1("Klaus", 3);
    Intern someRandomIntern;
    
    AForm* rrf1;
    AForm* rrf2;
    AForm* rrf3;
    AForm* rrf4;
    
    std::cout << "\n";
    rrf1 = someRandomIntern.makeForm("shrubbery creation", "Bender");
    std::cout << "\n";
    rrf2 = someRandomIntern.makeForm("robotomy request", "dog");
    std::cout << "\n";
    rrf3 = someRandomIntern.makeForm("presidential pardon", "C. Manson");
    std::cout << "\n";
    rrf4 = someRandomIntern.makeForm("fart form", "can");

    std::cout << "\nsign and execute shrubby:" << std::endl;
    bureauc1.signForm(*rrf1);
    bureauc1.executeForm(*rrf1);
    if(rrf1)
        delete rrf1;
    
    std::cout << "\nsign and execute robot:" << std::endl;
    bureauc1.signForm(*rrf2);
    bureauc1.executeForm(*rrf2);
    if(rrf2)
        delete rrf2;

    std::cout << "\nsign and execute pardon:" << std::endl;
    bureauc1.signForm(*rrf3);
    bureauc1.executeForm(*rrf3);
    if(rrf3)
        delete rrf3;
    
    std::cout << std::endl;
    if(rrf4)
        delete rrf4;
}
