/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:09:56 by joklein           #+#    #+#             */
/*   Updated: 2025/06/26 14:56:34 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137, "no_target"){
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137, target){
	std::cout << "ShrubberyCreationForm " << this->getName() << " created with target: " << target << "." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other){
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm " << this->getName() << " destroyed." << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	
	std::string filename = this->getTarget() + "_shrubbery";
	std::ofstream file_write(filename);
	if (!file_write.is_open())
		throw std::runtime_error("Failed to open file for writing.");
	
	file_write << 
		"\n            ,@@@@@@@,\n"
		"    ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
		" ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
		",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
		"%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
		"%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
		"`&%\\ ` /%&'    |.|        \\ '|8'\n"
		"    |o|        | |         | |\n"
		"    |.|        | |         | |\n"
		"  \\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";	
	file_write.close();

	std::ifstream file_read(filename);
    std::string line;
    while (std::getline(file_read, line)) {
        std::cout << line << std::endl;
    }
}
