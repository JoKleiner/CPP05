/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:18:34 by joklein           #+#    #+#             */
/*   Updated: 2025/06/03 17:16:06 by joklein          ###   ########.fr       */
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
	~Bureaucrat();

    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    
    class GradeTooHighException : public std::exception {
		const char* what() const noexcept override {
			return "Grade is too high!";
		}
	};

	class GradeTooLowException : public std::exception {
		const char* what() const noexcept override {
			return "Grade is too low!";
		}
	};
    
  private:
	const std::string m_name;
	int m_grade;

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other);

#endif
