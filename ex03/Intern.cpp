/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:27:23 by ysanchez          #+#    #+#             */
/*   Updated: 2024/10/24 19:25:34 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

typedef AForm* (*arrforms)(std::string);

Intern::Intern()
{
	std::cout << "New intern created. He's ready to do boring tasks" << std::endl;
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

static AForm* makeShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm* makeRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm* makePresPardon(std::string target)
{
	return (new PresidentialPardonForm(target));
} 

AForm* Intern::makeForm(std::string formType, std::string target)
{
	for (size_t i = 0; i < formType.length(); i++)
		formType.at(i) = tolower(formType.at(i));
	arrforms ft_forms[3]= {makeShrubbery, makeRobotomy, makePresPardon};
	std::string arrform[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)
	{
		if (arrform[i].compare(formType) == 0)
		{
			AForm* retval = ft_forms[i](target);
			std::cout << "The intern has created a new " << arrform[i] << " form" << std::endl; 
			return (retval);
		}
	}
	std::cout << "The intern couldn't create the form " << formType << std::endl;
	return (NULL);
}
