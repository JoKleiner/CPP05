/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:22:54 by joklein           #+#    #+#             */
/*   Updated: 2025/06/17 12:30:54 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	*per1 = nullptr;
    Bureaucrat	*per2 = nullptr;
    Form        *form1 = nullptr;
    Form        *form2 = nullptr;
    
    std::cout << "try to create bureaucrats" << std::endl;
	try	{ 
        per1 = new Bureaucrat("Klaus", 8);}
	catch (const std::exception &e) {
        std::cout << e.what() << std::endl;}
    
    try {
        per2 = new Bureaucrat("Hans", 45);}
    catch(const std::exception& e) {
        std::cout << e.what() << std::endl;}
    

        
    std::cout << "\ntry to create forms" << std::endl;
    try {
        form1 = new Form("Form1", 10, 20);}
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;}
    
    try {
        form2 = new Form("Form2", 200, 20);}
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;}
    
    try {
        form2 = new Form("Form2", 20, 200);}
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;}
        
    try {
        form2 = new Form("Form2", 50, 100);}
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;}
    
    if(per2)
    {
        std::cout << "\n" << *per2 << std::endl;
        try {
            per2->signForm(*form1);
        }
        catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        try{
            per2->signForm(*form2);
        }
        catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

    if(per1)
    {
        std::cout << "\n" << *per1 << std::endl;
        try {
            per1->signForm(*form1);
        }
        catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        try{
            per1->signForm(*form2);
        }
        catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    
}
