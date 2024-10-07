/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:18:48 by ysanchez          #+#    #+#             */
/*   Updated: 2024/10/07 21:53:14 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <limits>

int main (void)
{
	// CORRECT CONSTRUCTION
	std::cout << "*** VALID OBJECTS + INSERTION OPERATOR ***" << std::endl;
	try
	{
		Bureaucrat npc;
		std::cout << npc << std::endl;
		Bureaucrat high("Pepe", 10);
		Bureaucrat low("Pipo", 140);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// INCORRECT CONSTRUCTION
	std::cout << "\n*** INVALID OBJECTS ***" << std::endl;
	try
	{
		// Bureaucrat high("SuperPepe", 0);
		// Bureaucrat low("MiniPepe", 200);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Exception happened" << std::endl;
	}

	// INCREMENT / DECREMENT

	std::cout << "\n*** DECREMENT ***" << std::endl;
	Bureaucrat dummy("Pepe", 10);
	std::cout << dummy << std::endl;
	try
	{
		dummy.decrementGrade();
		std::cout << dummy << std::endl;
		dummy.setGrade(150);
		std::cout << dummy << std::endl;
		dummy.decrementGrade();
		std::cout << dummy << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n*** INCREMENT ***" << std::endl;

	dummy.setGrade(2);
	try
	{
		std::cout << dummy << std::endl;
		dummy.incrementGrade();
		std::cout << dummy << std::endl;
		dummy.incrementGrade();
		std::cout << dummy << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}