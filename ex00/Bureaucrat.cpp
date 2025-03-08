/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:16:03 by fzayani           #+#    #+#             */
/*   Updated: 2025/03/08 16:03:39 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name ,int grade) : name(name){
	if(grade < 1)
		throw(GradeTooHighException());
	else if(grade > 150)
		throw(GradeTooLowException());
	this->grade = grade;
}

Bureaucrat::~Bureaucrat(){
}


Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade){

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
	if(this != &other){
		this->grade = other.grade; //pas name parce qu'il est const
	}
	return *this;
}

const std::string& Bureaucrat::getName() const{
	return this->name;
}


int Bureaucrat::getGrade() const{
	return this->grade;
}

void Bureaucrat::incrementGrade(){
	if(this->grade <= 1)
		throw GradeTooHighException();
	this->grade--; //diminuer le nb = augmenter le grade
}

void Bureaucrat::decrementGrade(){
	if(this->grade >= 150)
		throw GradeTooLowException();
	this->grade++; //contraire
}

//exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade too hight ! The grade cannot be hight than 1.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade too hight ! The grade cannot be low than 150.";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat){
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}
