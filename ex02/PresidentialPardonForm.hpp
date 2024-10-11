/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:22:59 by ysanchez          #+#    #+#             */
/*   Updated: 2024/10/11 17:51:53 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm
{
private:
	const std::string _target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(PresidentialPardonForm& copy);
	~PresidentialPardonForm();

	PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
	
	void	beSigned(const Bureaucrat& signer);
	void	execute(const Bureaucrat& executor) const;
};

#endif