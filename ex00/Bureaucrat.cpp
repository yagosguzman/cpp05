/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:09:34 by ysanchez          #+#    #+#             */
/*   Updated: 2024/10/07 21:47:57 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <limits>

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "Default Bureaucrat called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
	std::cout << "New Bureaucrat called, his/her name is " << getName() 
		<< " and his/her rank is " << getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat& copy) : _name(copy._name) // _name when using copy constructor must be initialized here, otherwise we won't be able to do it later.
{
	this->_grade = (copy.getGrade());
	std::cout << "Copy constructor called, a Bureaucrat has been cloned" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "A Bureaucrat has been destroyed" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src) // _name is const so we can't assign him a new value once initialized.
{
	if (this != &src) // We check that it's not self-assignation
	{
		std::cout << "Copy assignment operator called" << std::endl;
		_grade = src._grade;
	}
	else
		std::cout << "WARNING!\nSelf-assignation detected!" << std::endl;
	return (*this);
}


std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int			Bureaucrat::getGrade(void)  const
{
	return (this->_grade);
}

void		Bureaucrat::setGrade(const int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
}


void		Bureaucrat::decrementGrade(void)
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void		Bureaucrat::incrementGrade(void)
{
	if (_grade -1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low!");
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high!");
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &src)
{
	out << src.getName() << ", Bureaucrat grade " << src.getGrade() << ".";
	return (out);
}