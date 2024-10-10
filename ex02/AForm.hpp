/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:12:54 by ysanchez          #+#    #+#             */
/*   Updated: 2024/10/10 19:56:28 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
protected:
	const std::string	_name;
	bool				_signed;
	const int			_reqSign;
	const int			_reqExec;

public:
	AForm();
	AForm(std::string name, int sign, int exec);
	AForm(AForm& copy);
	~AForm();

	AForm& operator=(const AForm& src);

	std::string		getName(void) const;
	int				getExec(void) const;
	int				getSign(void) const;
	bool			isSigned(void) const;
	void			setSign(bool);
	void			beSigned(const Bureaucrat& who);
	virtual void	execute(Bureaucrat const& executor) = 0;

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

std::ostream& operator<<(std::ostream &out, const AForm &src);


#endif