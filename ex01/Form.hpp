/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:09:38 by joklein           #+#    #+#             */
/*   Updated: 2025/06/17 15:06:55 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
  public:
	Form();
	Form(std::string name, int signGrade, int execGrade);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form() = default;

	std::string getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool isSigned() const;
	void beSigned();
	
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
	std::string m_name;
	int m_signGrade;
	int m_execGrade;
	bool m_signed;
};

std::ostream &operator<<(std::ostream &out, const Form &other);
