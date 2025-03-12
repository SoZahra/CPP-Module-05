/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:38:28 by fzayani           #+#    #+#             */
/*   Updated: 2025/03/12 13:24:15 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <fstream>

class Shrubbery : public AForm {

	private :
		std::string target;

	public :
		Shrubbery(const std::string& target);
		virtual ~Shrubbery();
		Shrubbery(const Shrubbery& other);
		Shrubbery& operator=(const Shrubbery& other);

		virtual void execute(Bureaucrat const& executor) const;
};

#endif