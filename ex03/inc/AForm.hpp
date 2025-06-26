/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:09:38 by joklein           #+#    #+#             */
/*   Updated: 2025/06/17 12:34:45 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
  private:
	AForm();

  public:
	AForm(std::string name, int signGrade, int execGrade, std::string target);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();

	std::string getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool isSigned() const;
	void beSigned();
	std::string getTarget() const;
	virtual void execute(const Bureaucrat &executor) const;
	
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
	const std::string	m_name;
	const int 		m_signGrade;
	const int 		m_execGrade;
	bool 		m_signed;
	const std::string	m_target;
};

std::ostream &operator<<(std::ostream &out, const AForm &other);
