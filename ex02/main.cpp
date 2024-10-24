/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:18:48 by ysanchez          #+#    #+#             */
/*   Updated: 2024/10/24 19:47:37 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <limits>

int main (void)
{
	// Creation of forms
	std::cout << "*** CREATING FORMS ***\n" << std::endl;
	std::cout << "\n* SHRUBBERY CREATION FORM *\n" << std::endl;
	
	ShrubberyCreationForm* test = NULL;
	ShrubberyCreationForm* test2 = NULL;


	try
	{
		test = new ShrubberyCreationForm;
		test2 = new ShrubberyCreationForm(*test);
		std::cout << "\nTEST 1:" << *test << std::endl;
		std::cout << "TEST 2:" << *test2 << std::endl;
		Bureaucrat pepeBureaucrat("Pepe", 137);
		pepeBureaucrat.signForm(*test); //  If we take out this line it can't be executed
		test->execute(pepeBureaucrat);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	delete test;
	delete test2;

	std::cout << "\n* ROBOTOMY REQUEST FORM *\n" << std::endl;

	AForm* test3 = NULL;

		try
	{
		test3 = new RobotomyRequestForm("Mickey Mouse");
		std::cout << *test3 << std::endl;
		Bureaucrat randomBureaucrat("Pipo", 45);
		randomBureaucrat.signForm(*test3); //  If we take out this line it can't be executed
		test3->execute(randomBureaucrat);
		// std::cout << "This won't be printed" << std::endl; // To test taking the sign
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	delete test3;
	
	std::cout << "\n* PRESIDENTIAL PARDON FORM *\n" << std::endl;

	AForm* test4 = NULL;

		try
	{
		test4 = new PresidentialPardonForm("Tarzan");
		std::cout << *test4 << std::endl;
		Bureaucrat randomBureaucrat("John Cena", 5);
		randomBureaucrat.signForm(*test4); //  If we take out this line it can't be executed
		test4->execute(randomBureaucrat);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	delete test4;
	
	return (0);
}