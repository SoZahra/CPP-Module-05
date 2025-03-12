/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:28:23 by fzayani           #+#    #+#             */
/*   Updated: 2025/03/12 12:11:41 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include "AForm.hpp"
#include <iostream>

class Presidential : public AForm {

	private :
		std::string target;

	public :
		Presidential(const std::string& target);
		virtual ~Presidential();
		Presidential(const Presidential& other);
		Presidential& operator=(const Presidential& other);

		virtual void execute(Bureaucrat const& executor) const;
};

#endif