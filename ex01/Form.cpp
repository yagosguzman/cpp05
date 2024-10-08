/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:40:42 by ysanchez          #+#    #+#             */
/*   Updated: 2024/10/08 20:24:14 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _reqSign(150), _reqExec(150)
{
	std::cout << "Default form created" << std::endl;	
}

Form::Form(std::string name, int sign, int exec) : _name(name), _signed(false), _reqSign(sign), _reqExec(exec)
{
	std::cout << "New form " << name << " created" << std::endl;
}

Form::Form(Form& copy) : _name(copy._name), _signed(copy._signed), _reqSign(copy._reqSign), _reqExec(copy._reqExec)
{
	std::cout << "A new form has been copied from the original " << copy.getName() << std::endl;
}

Form::~Form()
{
	std::cout << "Form " << this->getName() << " has been destroyed" << std::endl;
}

Form& Form::operator=(const Form& src) // We can't reassign any const variables.
{
	if (this != &src)
	{
		_signed = src._signed;
		std::cout << "Copy assignment operator called for form" << std::endl;
	}
	else
		std::cout << "WARNING!\nSelf-assignation detected!" << std::endl;
	return (*this);
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

int			Form::getExec(void) const
{
	return (this->_reqExec);
}

int			Form::getSign(void) const
{
	return (this->_reqSign);
}

bool		Form::isSigned(void) const
{
	return (this->_signed);
}

void		Form::setSign(bool status)
{
	this->_signed = status;
}

void		Form::beSigned(const Bureaucrat& who)
{
	if (this->isSigned())
	{
		std::cout << this->getName() << " form is already signed" << std::endl;
		return;
	}
	if (who.getGrade() <= this->_reqSign)
		this->setSign(true);
	else
		throw Form::GradeTooLowException();
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return ("The Bureaucrat's grade is too low to sign this form!");
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return ("The Bureaucrat's grade is too high to sign this form!");
}

std::ostream& operator<<(std::ostream &out, const Form &src)
{
	if (src.isSigned())
		out << src.getName() << " form is signed!\n - Required grade to sign: " << src.getSign()
			<< "\n - Required grade to execute: " << src.getExec() << std::endl;
	else
		out << src.getName() << " form is NOT signed!\n - Required grade to sign: " << src.getSign()
			<< "\n - Required grade to execute: " << src.getExec() << std::endl;
	return (out);
}