/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:09:56 by joklein           #+#    #+#             */
/*   Updated: 2025/06/26 15:00:47 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

AForm::AForm() : m_name("unnamed"), m_signGrade(150), m_execGrade(150), m_signed(false), m_target("no_target"){
}

AForm::AForm(std::string name, int signGrade, int execGrade, std::string target) : m_name(name), m_signGrade(signGrade), m_execGrade(execGrade), m_signed(false), m_target(target){
	if (signGrade < 1 || execGrade < 1)
	{
		std::cout << "AForm " << m_name << " not created: ";
		throw GradeTooHighException();
	}
	else if (signGrade > 150 || execGrade > 150)
	{
		std::cout << "AForm " << m_name << " not created: ";
		throw GradeTooLowException();
	}
	else
	{
		std::cout << "AForm " << m_name << " created with sign grade " << signGrade << " and exec grade " << execGrade << "." << std::endl;
	}
}

AForm::AForm(const AForm &other) : m_name(other.m_name),
	m_signGrade(other.m_signGrade), m_execGrade(other.m_execGrade),
	m_signed(other.m_signed){
}

AForm &AForm::operator=(const AForm &other){
	if (this != &other)
	{
		this->m_signed = other.m_signed;
	}
	return (*this);
}

AForm::~AForm(){
	std::cout << "AForm " << m_name << " destroyed." << std::endl;
}

std::string AForm::getName() const{
	return (this->m_name);
}

int AForm::getSignGrade() const{
	return (this->m_signGrade);
}

int AForm::getExecGrade() const{
	return (this->m_execGrade);
}

bool AForm::isSigned() const{
	return (this->m_signed);
}

void AForm::beSigned(){
	this->m_signed = true;
}

std::string AForm::getTarget() const{
	return (this->m_target);
}

std::ostream &operator<<(std::ostream &out, const AForm &other){
	out << other.getName() << ", sign grade " << other.getSignGrade() << ", exec grade "
    << other.getExecGrade() << ", is signed " << other.isSigned() << ".";
	return (out);
}

void AForm::execute(const Bureaucrat &executor) const{
	std::cout << executor.getName() << std::endl;
}
