/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:18:48 by ysanchez          #+#    #+#             */
/*   Updated: 2024/10/10 20:02:12 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <limits>

int main (void)
{
	// Creation of forms
	std::cout << "*** CREATING FORMS ***\n" << std::endl;
	
	try
	{
		Form test;
		Form complete("very important doc", 10, 5);
		Form copy(complete);

		complete.setSign(true); // If we sign complete and then we make test equal to complete test will be signed too
		test = complete;

		std::cout << test << std::endl;
		std::cout << complete << std::endl;
		std::cout << copy << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	// Trying to sign a form

	std::cout << "\n*** TRYING TO SIGN FORMS ***\n" << std::endl;

	Bureaucrat	potus("President", 1);
	Form		important("Very Important Form", 1, 1);
	try
	{
		important.beSigned(potus);
		std::cout << important << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}