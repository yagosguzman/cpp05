/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:04:14 by ysanchez          #+#    #+#             */
/*   Updated: 2024/10/10 20:02:33 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>
#include <exception>

class Bureaucrat
{
private:
	const	std::string		_name;
			int	_grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat& copy);
	~Bureaucrat();

	Bureaucrat& operator=(const Bureaucrat& src);

	std::string	getName(void) const;
	int			getGrade(void) const;
	void		setGrade(const int grade);
	void		incrementGrade(void);
	void		decrementGrade(void);
	void		signForm(Form doc);
	void		executeForm(AForm const& form);

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what(void) const throw();
	};
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &src);

#endif