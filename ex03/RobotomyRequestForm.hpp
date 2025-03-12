/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:22:36 by fzayani           #+#    #+#             */
/*   Updated: 2025/03/12 15:56:56 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>


class Robot : public AForm {

	private :
		std::string target;

	public :
		Robot(const std::string& target);
		virtual ~Robot();
		Robot(const Robot& other);
		Robot& operator=(const Robot& other);

		virtual void execute(Bureaucrat const& executor) const;
};

#endif