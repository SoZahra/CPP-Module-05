/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:52:46 by fzayani           #+#    #+#             */
/*   Updated: 2025/03/12 16:12:49 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>
#include "AForm.hpp"

class Bureaucrat {

	private :
		const std::string name;
		int 		grade;

	public :
		Bureaucrat(const std::string& name ,int grade);
		virtual ~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);

		const std::string& getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		void signForm(AForm& form);
		void executeForm(AForm const & form);

		//class d'execption
		class GradeTooHighException : public std::exception{
			public :
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public :
				virtual const char* what() const throw();
		};
};

//Operateur de surcharge
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif