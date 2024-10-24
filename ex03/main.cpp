/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:18:48 by ysanchez          #+#    #+#             */
/*   Updated: 2024/10/24 18:17:41 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <limits>

int main (void)
{
	std::cout << "**** CREATING A NEW INTERN + EXISTING FORMS ****\n" << std::endl;
	Intern randomIntern;

	AForm* form1;
	AForm* form2;
	AForm* form3;

	form1 = randomIntern.makeForm("ShrubBery CrEaTiOn", "Paquillo");
	form2 = randomIntern.makeForm("PRESIDENTIAL PARDON", "Jose Luis");
	form3 =  randomIntern.makeForm("robotomy REQUEST", "Gustavo");
	std::cout << std::endl;
	if (form1)
		std::cout << *form1 << std::endl;
	if (form2)
		std::cout << *form2 << std::endl;
	if (form3)
		std::cout << *form3 << std::endl;

	delete form1;
	delete form2;
	delete form3;
	
	std::cout << "\n**** TRYING TO CREATE A NON-EXISTENT FORM ****\n" << std::endl;
	AForm* nonexistent = randomIntern.makeForm("Non existent form", "Paquillo");
	
	if (nonexistent)
		std::cout << *nonexistent << std::endl;

	delete nonexistent;
	
	return (0);
}