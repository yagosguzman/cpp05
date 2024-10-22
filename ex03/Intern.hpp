/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:10:46 by ysanchez          #+#    #+#             */
/*   Updated: 2024/10/22 18:25:43 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <map>
#include "AForm.hpp"

class Intern
{
private:
	

public:
	Intern();
	Intern(Intern& copy);
	~Intern();

	Intern& operator=(const Intern& src);

	AForm* makeForm(std::string formType, std::string target);
};

#endif