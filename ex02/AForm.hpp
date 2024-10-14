/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:12:54 by ysanchez          #+#    #+#             */
/*   Updated: 2024/10/14 21:18:11 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_reqSign;
	const int			_reqExec;

public:
	AForm();
	AForm(std::string name, int sign, int exec);
	AForm(AForm& copy);
	virtual ~AForm();

	AForm& operator=(const AForm& src);

	std::string		getName(void) const;
	int				getExec(void) const;
	int				getSign(void) const;
	bool			isSigned(void) const;
	void			setSign(bool);
	virtual void	beSigned(const Bureaucrat& who);
	virtual void	execute(const Bureaucrat& executor) const = 0;

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

	class FormNotSignedException : public std::exception
	{
	public: 
		virtual const char* what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream &out, const AForm &src);


#endif