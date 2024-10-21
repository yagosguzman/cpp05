/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:24:03 by ysanchez          #+#    #+#             */
/*   Updated: 2024/10/16 21:57:52 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5), _target("default")
{
	std::cout << "Default constructor for Presidential Pardon Form called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
	std::cout << "Presidential Pardon Form created, target is : " << this->getTarget() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& copy) : AForm(copy), _target(getTarget())
{
	std::cout << "Copy constructor for Presidential Pardon Form called" << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon Form destroyed" << std::endl;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src) // We can't reassign any const variables.
{
	if (this != &src)
	{
		this->setSign(src.isSigned());
		std::cout << "Copy assignment operator called for Presidential Pardon Form" << std::endl;
	}
	else
		std::cout << "WARNING!\nSelf-assignation detected!" << std::endl;
	return (*this);
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void		PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!this->isSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > 5)
		throw AForm::GradeTooLowException();
	std::cout << this->getTarget() << " has been pardoned by the president Zaphod Beeblebrox" << std::endl;
}