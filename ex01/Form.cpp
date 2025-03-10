/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:43:17 by fzayani           #+#    #+#             */
/*   Updated: 2025/03/10 13:24:09 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name,int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute){
		if(gradeToSign < 1 || gradeToExecute < 1)
			throw GradeTooHighException();
		else if(gradeToSign > 150 || gradeToExecute > 150)
			throw GradeTooLowException();
}

Form::~Form(){
}

Form::Form(const Form& other)
	: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign),
	gradeToExecute(other.gradeToExecute){

}

Form& Form::operator=(const Form& other){
	if(this != &other){
		this->isSigned = other.isSigned; //pas name parce qu'il est const
	}
	return *this;
}

const std::string& Form::getName() const{
	return this->name;
}

bool Form::getIsSigned() const{
	return this->isSigned;
}

int Form::getGradeToSign() const{
	return this->gradeToSign;
}

int Form::getGradeToExecute() const{
	return this->gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat){
	if(bureaucrat.getGrade() <= this->gradeToSign)
		this->isSigned = true;
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw(){
	return "Grade too hight for this form !";
}

const char* Form::GradeTooLowException::what() const throw(){
	return "Grade too low for this form !";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form: " << form.getName()
       << ", sign status: " << (form.getIsSigned() ? "signed" : "not signed")
       << ", grade to sign: " << form.getGradeToSign()
       << ", grade to execute: " << form.getGradeToExecute();
    return os;
}
