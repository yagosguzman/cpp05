/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:09:34 by ysanchez          #+#    #+#             */
/*   Updated: 2024/10/05 14:02:40 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

Bureaucrat::Bureaucrat(Bureaucrat& copy)
{
	this->_name = (copy.getName());
	this->_grade = (copy.getGrade());
	std::cout << "Copy constructor called, a Bureaucrat has been cloned" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "A Bureaucrat has been destroyed" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_name = src._name;
	_grade = src._grade;
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

Bureaucrat::GradeTooLowException()
{

}

Bureaucrat::GradeTooHighException()
{
	
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &src)
{
	out << src.getName() << ", Bureaucrat grade " << src.getGrade() << "." << std::endl;
	return (out);
}