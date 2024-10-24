/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:20:15 by ysanchez          #+#    #+#             */
/*   Updated: 2024/10/16 21:57:11 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	const std::string _target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(RobotomyRequestForm& copy);
	~RobotomyRequestForm();

	RobotomyRequestForm& operator=(const RobotomyRequestForm& src);

	std::string getTarget(void) const;
	void		execute(const Bureaucrat& executor) const;
};

#endif