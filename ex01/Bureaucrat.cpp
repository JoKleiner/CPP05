/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:19:28 by joklein           #+#    #+#             */
/*   Updated: 2025/06/17 15:31:49 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : m_name("unnamed"), m_grade(150){
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : m_name(name){
	if (grade < 1)
	{
		std::cout << "Bureaucrat " << m_name << " not created: ";
		throw GradeTooHighException();
	}
	else if(grade > 150)
	{
		std::cout << "Bureaucrat " << m_name << " not created: ";
		throw GradeTooLowException();
	}
	else
	{
		m_grade = grade;
		std::cout << "Bureaucrat " << m_name << " created with grade " << grade << "." << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : m_name(other.m_name), m_grade(other.m_grade){
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
	if (this != &other)
		this->m_grade = other.m_grade;
	return (*this);
}

std::string Bureaucrat::getName() const{
	return (this->m_name);
}

int Bureaucrat::getGrade() const{
	return (this->m_grade);
}

void Bureaucrat::incrementGrade(){
	if (m_grade - 1 < 1)
		throw GradeTooHighException();
	else
		m_grade--;
}

void Bureaucrat::decrementGrade(){
	if (m_grade + 1 > 150)
		throw GradeTooLowException();
	else
		m_grade++;
}

void Bureaucrat::signForm(Form &form) const {
	if (form.isSigned())
		std::cout << m_name << " cannot sign " << form.getName() << " because it is already signed." << std::endl;
	else if (m_grade > form.getSignGrade())
	{
		std::cout << m_name << " cannot sign " << form.getName() << " because ";
		throw GradeTooLowException();
	}
	else
	{
		form.beSigned();
		std::cout << m_name << " signs " << form.getName() << "." << std::endl;
	}
}

void Bureaucrat::executeForm(const Form &form) const {
	if (!form.isSigned())
	{
		std::cout << m_name << " cannot execute " << form.getName() << " because it is not signed." << std::endl;
		return;
	}
	if (m_grade > form.getExecGrade())
	{
		std::cout << m_name << " cannot execute " << form.getName() << " because ";
		throw GradeTooLowException();
	}
	else
	{
		std::cout << m_name << " executes " << form.getName() << "." << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other){
	out << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
	return(out);
}
