/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:09:56 by joklein           #+#    #+#             */
/*   Updated: 2025/06/25 13:01:53 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45, "no_target"){
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45, target){
	std::cout << "RobotomyRequestForm " << this->getName() << " created with target: " << target << "." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other){
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm " << this->getName() << " destroyed." << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	
	std::cout << "BZZZZZZZZZZZRRRRRRRRRRRRTTTT" << std::endl;
	std::random_device rd;
	if(rd()%2){
		std::cout << this->getTarget() << " has been robotized." << std::endl;
	}
	else
		std::cout << "Robotizing " << this->getTarget() << " failed." << std::endl;
}
