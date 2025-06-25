/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:46:03 by joklein           #+#    #+#             */
/*   Updated: 2025/06/25 16:31:09 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern(){
    std::cout << "Rdm intern created." << std::endl;
}

Intern::Intern(Intern const &Intern){
    (void)Intern;
}

Intern &Intern::operator=(Intern const &Intern){
    (void)Intern;
    return(*this);
}

Intern::~Intern(){
    std::cout << "Rdm intern destroyed." << std::endl;
}

AForm* createShrubbery(const std::string &target) {
    return (new ShrubberyCreationForm(target));
}

AForm* createRobotomy(const std::string &target) {
    return (new RobotomyRequestForm(target));
}

AForm* createPresidential(const std::string &target) {
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string form_name, std::string target) const{
    
    static FormType exists_forms[] = {
        {"shrubbery creation", createShrubbery},
        {"robotomy request", createRobotomy},
        {"presidential pardon", createPresidential}
    };
    
    for (size_t i = 0; i < 3; ++i) {
        if (exists_forms[i].name == form_name) {
            std::cout << "Intern creates " << form_name << std::endl;
            return (exists_forms[i].createForm(target));
        }
    }
    
    std::cout << "Intern cannot create " << form_name << std::endl;
    return (nullptr);
}
