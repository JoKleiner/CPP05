/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:18:34 by joklein           #+#    #+#             */
/*   Updated: 2025/06/25 14:38:40 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include "AForm.hpp"
# include <fstream>

class AForm;

class Bureaucrat
{
  public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(class AForm &form) const;
	void executeForm(const AForm &form) const;
	
	class GradeTooHighException final : public std::exception {
		public:
		const char *what() const noexcept override {
			return ("Grade is too high!");
		}
	};

	class GradeTooLowException final : public std::exception {
		public:
		const char *what() const noexcept override {
			return ("Grade is too low!");
		}
	};

  private:
	const std::string m_name;
	int m_grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other);
