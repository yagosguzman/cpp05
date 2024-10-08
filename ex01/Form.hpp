/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:12:54 by ysanchez          #+#    #+#             */
/*   Updated: 2024/10/08 20:22:14 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_reqSign;
	const int			_reqExec;

public:
	Form();
	Form(std::string name, int sign, int exec);
	Form(Form& copy);
	~Form();

	Form& operator=(const Form& src);

	std::string	getName(void) const;
	int			getExec(void) const;
	int			getSign(void) const;
	bool		isSigned(void) const;
	void		setSign(bool);
	void		beSigned(const Bureaucrat& who);

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

std::ostream& operator<<(std::ostream &out, const Form &src);


#endif