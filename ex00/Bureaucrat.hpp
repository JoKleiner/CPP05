/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:18:34 by joklein           #+#    #+#             */
/*   Updated: 2025/07/15 16:54:42 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
  public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat() = default;

	std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException final : public std::exception {
		public:
			const char *what() const noexcept override;
	};

	class GradeTooLowException final : public std::exception {
		public:
			const char *what() const noexcept override;
	};

  private:
	const std::string m_name;
	int m_grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other);

#endif
