/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:27:23 by ysanchez          #+#    #+#             */
/*   Updated: 2024/10/21 21:12:21 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "New intern created and ready to do boring tasks" << std::endl;
}

Intern::Intern(Intern& copy)
{
	*this = copy;
	std::cout << "New intern created from the copy of another" << std::endl;
}

Intern::~Intern()
{
	std::cout << "The intern has been destroyed" << std::endl;
}

Intern& Intern::operator=(const Intern& src)
{
	if (this != &src)
	{
		std::cout << "Copy assignment operator called for Intern" << std::endl;
	}
	else
		std::cout << "WARNING!\nSelf-assignation detected!" << std::endl;
	return (*this);
}

AForm* Intern::makeForm(std::string formType, std::string target)
{
		std::string arrform[3] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
	try
	{
		AForm* forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
		for (int i = 0; i < 3; i++)
		{
			if (arrform[i].compare(formType) == 0)
			{
				AForm* retval = forms[i];
				for (int j = 0; j < 3; j++)
					if (i != j)
						delete forms[j];
				std::cout << "The intern has created a new " << arrform[i] << " form" << std::endl; 
				return (retval);
			}
		}
		for (int i = 0; i < 3; i++)
			delete forms[i];
		throw; // EXCEPTION
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (NULL);
	}
}
