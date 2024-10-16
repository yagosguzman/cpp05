/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:21:42 by ysanchez          #+#    #+#             */
/*   Updated: 2024/10/16 21:36:09 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), _target("default")
{
	std::cout << "Default constructor for Robotomy Request Form called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << "Robotomy Request Form created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& copy) : AForm(copy), _target(copy.getTarget())
{
	std::cout << "Copy constructor for Robotomy Request Form called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Request Form destroyed" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	if (this != &src)
	{
		this->setSign(src.isSigned());
		std::cout << "Copy assignment operator called for Robotomy Request Form" << std::endl;
	}
	else
		std::cout << "WARNING!\nSelf-assignation detected!" << std::endl;
	return (*this);
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void		RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (!this->isSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > 45)
		throw AForm::GradeTooLowException();
	std::cout << "*** BZZZZZZZZZZZZZZZ ***" << std::endl;
	std::cout << "*** ZZZZZZZZZZZMMMMM ***" << std::endl;
	std::cout << "*** BZZZZZZZZZZZZZZZ ***" << std::endl;
	std::cout << "Robotomy has finished. The result has been: " << std::endl;
	if (rand() % 2 == 0) // REVISAR ESTO (NO HACE DISTINTOS OUTPUTS SOLO FAIL)
		std::cout << "SUCCESS!" << std::endl;
	else
		std::cout << "FAIL..." << std::endl;
}
