/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:12:05 by ysanchez          #+#    #+#             */
/*   Updated: 2024/10/16 21:55:14 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), _target("default")
{
	std::cout << "Shrubbery Creation Form created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
	std::cout << "Shrubbery Creation Form with target created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& copy) : AForm(copy), _target(copy.getTarget())
{
	std::cout << "Copy constructor for Shrubbery Creation Form called" << std::endl;
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Creation Form destroyed" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) // We can't reassign any const variables.
{
	if (this != &src)
	{
		this->setSign(src.isSigned());
		std::cout << "Copy assignment operator called for Shrubbery Creation Form" << std::endl;
	}
	else
		std::cout << "WARNING!\nSelf-assignation detected!" << std::endl;
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void		ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!this->isSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > 137)
		throw AForm::GradeTooLowException();
	std::ofstream file;

		std::string fullName = this->getTarget() + "_shrubbery";
		const char* name = fullName.c_str();

		file.open(name);
		if (file.is_open())
		{
			file << "              ,@@@@@@@,\n";
			file << "      ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
			file << "  ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
			file << " ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
			file << " %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
			file << " %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
			file << "  `&%\\ ` /%&'    |.|        \\ '|8'\n";
			file << "      |o|        | |         | |\n";
			file << "      |.|        | |         | |\n";
			file << "   \\\\/ ._\\//_/__/ . \\_// __\\/ . \\_//__/_" << std::endl;
		
			file.close();
		}
		else
			std::cout << "Error creating the file" << std::endl;
}
