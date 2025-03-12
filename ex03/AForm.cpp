/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:43:13 by fzayani           #+#    #+#             */
/*   Updated: 2025/03/12 12:06:22 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) :
	name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute){
		if(gradeToSign < 1 || gradeToExecute < 1)
			throw GradeTooHighException();
		else if(gradeToSign > 150 || gradeToExecute > 150)
			throw GradeTooLowException();
}

AForm::~AForm(){
}

AForm::AForm(const AForm& other):
	name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign),
	gradeToExecute(other.gradeToExecute){
}

AForm& AForm::operator=(const AForm& other){
	if(this != &other){
		this->isSigned = other.isSigned;
	}
	return *this;
}

const std::string& AForm::getName() const{
	return this->name;
}

bool AForm::getIsSigned() const{
	return this->isSigned;
}

int AForm::getGradeToSign() const{
	return this->gradeToSign;
}

int AForm::getGradeToExecute() const{
	return this->gradeToExecute;
}

//signer le AFormmulaire
void AForm::beSigned(const Bureaucrat& bureaucrat){
	if(bureaucrat.getGrade() <= this->gradeToSign)
		this->isSigned = true;
	else
		throw GradeTooLowException();
}


const char* AForm::GradeTooHighException::what() const throw(){
	return "Grade too hight for this form !";
}

const char* AForm::GradeTooLowException::what() const throw(){
	return "Grade too low for this form !";
}

const char* AForm::FormNotSignedException::what() const throw(){
	return "Form is not signed !";
}

std::ostream& operator<<(std::ostream& os, const AForm& form){
	os << "Form: " << form.getName()
		<< ", sign status: " << (form.getIsSigned() ? "signed" : "not signed")
		<< ", grade to sign " << form.getGradeToSign()
		<< ", grade to execute: " << form.getGradeToExecute();
	return os;
}
