/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:40:42 by ysanchez          #+#    #+#             */
/*   Updated: 2024/10/16 20:05:05 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _reqSign(150), _reqExec(150)
{
	std::cout << "Default form created" << std::endl;	
}

AForm::AForm(std::string name, int sign, int exec) : _name(name), _signed(false), _reqSign(sign), _reqExec(exec)
{
	std::cout << "New form " << name << " created" << std::endl;
}

AForm::AForm(AForm& copy) : _name(copy._name), _signed(copy._signed), _reqSign(copy._reqSign), _reqExec(copy._reqExec)
{
	std::cout << "A new form has been copied from the original " << copy.getName() << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm " << this->getName() << " has been destroyed" << std::endl;
}

AForm& AForm::operator=(const AForm& src) // We can't reassign any const variables.
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

std::string	AForm::getName(void) const
{
	return (this->_name);
}

int			AForm::getExec(void) const
{
	return (this->_reqExec);
}

int			AForm::getSign(void) const
{
	return (this->_reqSign);
}

bool		AForm::isSigned(void) const
{
	return (this->_signed);
}

void		AForm::setSign(bool status)
{
	this->_signed = status;
}

void		AForm::beSigned(const Bureaucrat& who)
{
	if (this->isSigned())
	{
		std::cout << this->getName() << " form is already signed" << std::endl;
		return;
	}
	if (who.getGrade() <= this->_reqSign)
		this->setSign(true);
	else
		throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return ("The Bureaucrat's grade is too low to sign this form!");
}

const char* AForm::GradeTooHighException::what(void) const throw()
{
	return ("The Bureaucrat's grade is too high to sign this form!");
}

const char* AForm::FormNotSignedException::what(void) const throw()
{
	return ("This Form is NOT SIGNED so you can't EXECUTE it.");
}

std::ostream& operator<<(std::ostream &out, const AForm &src)
{
	if (src.isSigned())
		out << src.getName() << " is signed!\n - Required grade to sign: " << src.getSign()
			<< "\n - Required grade to execute: " << src.getExec() << std::endl;
	else
		out << src.getName() << " is NOT signed!\n - Required grade to sign: " << src.getSign()
			<< "\n - Required grade to execute: " << src.getExec() << std::endl;
	return (out);
}