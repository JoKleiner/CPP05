/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:09:38 by joklein           #+#    #+#             */
/*   Updated: 2025/06/25 12:53:53 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <random>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm  : public AForm
{
  private:
	RobotomyRequestForm();
	
  public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	~RobotomyRequestForm();

	void execute(const Bureaucrat &executor) const override;
	
};
