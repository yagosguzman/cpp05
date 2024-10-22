/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:27:23 by ysanchez          #+#    #+#             */
/*   Updated: 2024/10/22 19:45:35 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

typedef AForm* (*arrforms)(std::string);

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

static std::string lowercase(std::string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) >= 'A' && str.at(i) <= 'Z')
			str.at(i) += 32;
	}
	return (str);
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
	formType = lowercase(formType);
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
	std::cout << "The intern couldn't create the form you asked for" << std::endl;
	return (NULL);
}
