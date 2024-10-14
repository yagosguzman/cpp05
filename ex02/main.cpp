/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:18:48 by ysanchez          #+#    #+#             */
/*   Updated: 2024/10/14 19:51:04 by ysanchez         ###   ########.fr       */
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
	
	try
	{
		const AForm* test = new ShrubberyCreationForm;
		std::cout << *test << std::endl;
		Bureaucrat president("Pepe", 137);
		test->execute(president);// NO FUNCIONA LA IMPLEMENTACION DEL NOMBRE DEL ARCHIVO
		if (test->isSigned())
			std::cout << "This is signed" << std::endl;
		else
			std::cout << "This is NOT signed" << std::endl;
		delete test;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

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