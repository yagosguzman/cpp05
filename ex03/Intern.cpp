/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:27:23 by ysanchez          #+#    #+#             */
/*   Updated: 2024/10/21 19:35:21 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "New intern created and ready to do boring tasks" << std::endl;
}

Intern::Intern(Intern& copy)
{
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
	return (*this);}