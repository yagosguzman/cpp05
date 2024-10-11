/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:20:15 by ysanchez          #+#    #+#             */
/*   Updated: 2024/10/11 17:52:09 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>

class RobotomyRequestForm
{
private:
	const std::string _target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(RobotomyRequestForm& copy);
	~RobotomyRequestForm();

	RobotomyRequestForm& operator=(const RobotomyRequestForm& src);

	void	beSigned(const Bureaucrat& signer);
	void	execute(const Bureaucrat& executor) const;
};

#endif