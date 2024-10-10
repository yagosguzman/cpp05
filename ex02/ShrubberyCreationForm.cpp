/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:12:05 by ysanchez          #+#    #+#             */
/*   Updated: 2024/10/10 21:23:07 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target, int sign, int exec) : AForm("Shrubbery", 145, 137)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}
void	ShrubberyCreationForm::execute(Bureaucrat const& executor)
{
	if ()
	std::ofstream file;

		std::string name = target + "_shrubbery";

		file.open(name);
		if (file.is_open())
		{
			file << ",@@@@@@@,
		,,,.   ,@@@@@@/@@,  .oo8888o.
		,&%%&%&&%,@@@@@/@@@@@@,8888\88/8o
	,%&\%&&%&&%,@@@\@@@/@@@88\88888/88'
	%&&%&%&/%&&%@@\@@/ /@@@88888\88888'
	%&&%/ %&%%&&@@\ V /@@' `88\8 `/88'
	`&%\ ` /%&'    |.|        \ '|8'
		|o|        | |         | |
		|.|        | |         | |
		\\/ ._\//_/__/  ,\_//__\\/.  \_//__/_" << std::endl;
		
		file.close();
		}
		else
			std::cout << "Error creating the file" << std::endl;
}
