/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:22:54 by joklein           #+#    #+#             */
/*   Updated: 2025/06/17 15:27:17 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
    Bureaucrat per1("Klaus", 8);
	Bureaucrat per2("Hans", 45);
	Form	*form1 = nullptr;
	Form	*form2 = nullptr;

    
	std::cout << "\ntry to create forms" << std::endl;
	try	{
		form1 = new Form("Form1", 10, 8);
	}
	catch (const std::exception &e)	{
		std::cout << e.what() << std::endl;
	}

	try	{
		form2 = new Form("Form2", 200, 20);
	}
	catch (const std::exception &e)	{
		std::cout << e.what() << std::endl;
	}

	try	{
		form2 = new Form("Form2", 20, 200);
	}
	catch (const std::exception &e)	{
		std::cout << e.what() << std::endl;
	}
    
	try	{
		form2 = new Form("Form2", 50, 40);
	}
	catch (const std::exception &e)	{
		std::cout << e.what() << std::endl;
	}
    
	std::cout << "\n" << per2 << std::endl;
	if (form1)
	{
        std::cout << *form1 << std::endl;
		try		{
            per2.signForm(*form1);
		}
		catch (const std::exception &e)		{
			std::cout << e.what() << std::endl;
		}
        
		try		{
			per2.executeForm(*form1);
		}
		catch (const std::exception &e)		{
			std::cout << e.what() << std::endl;
		}
	}
    
	if (form2)
	{
        std::cout << *form2 << std::endl;
		try		{
			per2.signForm(*form2);
		}
		catch (const std::exception &e)		{
			std::cout << e.what() << std::endl;
		}

		try		{
			per2.executeForm(*form2);
		}
		catch (const std::exception &e)		{
			std::cout << e.what() << std::endl;
		}
	}
    

	std::cout << "\n" << per1 << std::endl;
	if (form1)
	{
        std::cout << *form1 << std::endl;
		try		{
			per1.signForm(*form1);
		}
		catch (const std::exception &e)		{
			std::cout << e.what() << std::endl;
		}
		try		{
			per1.executeForm(*form1);
		}
		catch (const std::exception &e)		{
			std::cout << e.what() << std::endl;
		}
	}
	if (form2)
	{
        std::cout << *form2 << std::endl;
		try		{
			per1.signForm(*form2);
		}
		catch (const std::exception &e)		{
			std::cout << e.what() << std::endl;
		}
		try		{
			per1.executeForm(*form2);
		}
		catch (const std::exception &e)		{
			std::cout << e.what() << std::endl;
		}
	}

    if (form1)
	    delete form1;
    if (form2)
	    delete form2;
}
