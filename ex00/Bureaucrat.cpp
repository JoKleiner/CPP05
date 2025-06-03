/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:19:28 by joklein           #+#    #+#             */
/*   Updated: 2025/06/03 17:19:50 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : m_name("unnamed"), m_grade(150){
	std::cout << "constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : m_name(name), m_grade(grade){
	std::cout << "setconstructor" << std::endl;
	if (grade < 1)
		throw GradeTooLowException();
	else if(grade > 150)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : m_name(other.m_name),
	m_grade(other.m_grade){
	std::cout << "copy-constructor" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
	std::cout << "copy-assignment" << std::endl;
	if (this != &other)
		this->m_grade = other.m_grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(){
	std::cout << "destructor" << std::endl;
}

std::string Bureaucrat::getName() const{
	return (this->m_name);
}

int Bureaucrat::getGrade() const{
	return (this->m_grade);
}

void Bureaucrat::incrementGrade(){
	if (m_grade - 1 < 1)
		throw GradeTooLowException();
	else
		m_grade--;
}

void Bureaucrat::decrementGrade(){
	if (m_grade + 1 > 150)
		throw GradeTooHighException();
	else
		m_grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other){
	out << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
	return(out);
}
