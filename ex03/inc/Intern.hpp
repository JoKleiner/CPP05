/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:37:14 by joklein           #+#    #+#             */
/*   Updated: 2025/06/25 15:50:36 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

struct FormType {
    std::string name;
    AForm* (*createForm)(const std::string &target);
};

class Intern
{
    public:
        Intern();
        Intern(Intern const &Intern);
        Intern &operator=(Intern const &Intern);
        ~Intern();

        AForm *makeForm(std::string form_name, std::string target) const;
        
};
