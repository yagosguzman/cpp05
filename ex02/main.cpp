/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:18:48 by ysanchez          #+#    #+#             */
/*   Updated: 2024/10/14 22:01:40 by ysanchez         ###   ########.fr       */
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
	
	AForm* test = NULL;

	try
	{
		test = new ShrubberyCreationForm;
		std::cout << *test << std::endl;
		Bureaucrat president("Pepe", 137);
		president.signForm(*test);
		test->execute(president);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	delete test;

	AForm* test2 = NULL;

		try
	{
		test2 = new RobotomyRequestForm("Lobotomia");
		std::cout << *test2 << std::endl;
		Bureaucrat president("Pipo", 45);
		president.signForm(*test2);
		test2->execute(president);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	delete test2;
// 	// Trying to sign a form

// 	std::cout << "\n*** TRYING TO SIGN FORMS ***\n" << std::endl;

// 	Bureaucrat	potus("President", 1);
// 	Form		important("Very Important Form", 1, 1);
// 	try
// 	{
// 		important.beSigned(potus);
// 		std::cout << important << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}
	
	return (0);
}