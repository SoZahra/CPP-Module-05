/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:43:19 by fzayani           #+#    #+#             */
/*   Updated: 2025/03/10 16:51:53 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
class Bureaucrat;

class AForm {
	private :
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;

	public :
		AForm(const std::string& name,int gradeToSign, int gradeToExecute);
		virtual ~AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);

		const std::string& getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		//signer le AFormmulaire
		void beSigned(const Bureaucrat& bureaucrat);

		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception{
			public :
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public :
				virtual const char* what() const throw();
		};

		class FormNotSignedException : public std::exception{
			public :
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif