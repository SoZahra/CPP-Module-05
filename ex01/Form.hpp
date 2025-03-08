/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:43:23 by fzayani           #+#    #+#             */
/*   Updated: 2025/03/08 18:31:43 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
class Bureaucrat;
class Form {
	private :
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;

	public :
		Form(const std::string& name,int gradeToSign, int gradeToExecute);
		virtual ~Form();
		Form(const Form& other);
		Form& operator=(const Form& other);

		const std::string& getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		//signer le formmulaire
		void beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception{
		public :
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception{
		public :
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& bureaucrat);

#endif