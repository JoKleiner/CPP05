/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joklein <joklein@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:22:54 by joklein           #+#    #+#             */
/*   Updated: 2025/06/03 17:20:01 by joklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat berti;
    Bureaucrat bert("ich", 20);
    Bureaucrat berto = bert;
    berti = bert;
    
    std::cout << berti << std::endl;
    
}
