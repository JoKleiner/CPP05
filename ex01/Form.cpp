/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:09:56 by joklein           #+#    #+#             */
/*   Updated: 2025/06/26 14:52:22 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : m_name("unnamed"), m_signGrade(150), m_execGrade(150), m_signed(false){
}

Form::Form(std::string name, int signGrade, int execGrade) : m_name(name), m_signGrade(signGrade), m_execGrade(execGrade), m_signed(false){
	if (signGrade < 1 || execGrade < 1)
	{
		std::cout << "Form " << m_name << " not created: ";
		throw GradeTooHighException();
	}
	else if (signGrade > 150 || execGrade > 150)
	{
		std::cout << "Form " << m_name << " not created: ";
		throw GradeTooLowException();
	}
	else
	{
		std::cout << "Form " << m_name << " created with sign grade " << signGrade << " and exec grade " << execGrade << "." << std::endl;
	}
}

Form::Form(const Form &other) : m_name(other.m_name),
	m_signGrade(other.m_signGrade), m_execGrade(other.m_execGrade),
	m_signed(other.m_signed){
}

Form &Form::operator=(const Form &other){
	if (this != &other)
		this->m_signed = other.m_signed;
	return (*this);
}

std::string Form::getName() const{
	return (this->m_name);
}

int Form::getSignGrade() const{
	return (this->m_signGrade);
}

int Form::getExecGrade() const{
	return (this->m_execGrade);
}

bool Form::isSigned() const{
	return (this->m_signed);
}

void Form::beSigned(){
	this->m_signed = true;
}

std::ostream &operator<<(std::ostream &out, const Form &other){
	out << other.getName() << ", sign grade " << other.getSignGrade() << ", exec grade "
    << other.getExecGrade() << ", is signed " << other.isSigned() << ".";
	return (out);
}
