/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:00:09 by fzayani           #+#    #+#             */
/*   Updated: 2025/03/12 16:14:26 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

Presidential::Presidential(const std::string& target):
	AForm("Presidential Pardon", 25, 5),target(target){
}


Presidential::~Presidential(){
}

Presidential::Presidential(const Presidential& other) :
	AForm(other), target(other.target){
}

Presidential& Presidential::operator=(const Presidential& other){
	if(this != &other){
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

void Presidential::execute(Bureaucrat const& executor) const{
	if(!this->getIsSigned())
		throw FormNotSignedException();
	if(executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}