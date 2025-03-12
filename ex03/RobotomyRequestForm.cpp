/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:22:12 by fzayani           #+#    #+#             */
/*   Updated: 2025/03/12 16:14:40 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

Robot::Robot(const std::string& target):
	AForm(" Robotomy Request", 75, 45),target(target){
}

Robot::~Robot(){
}

Robot::Robot(const Robot& other):
	AForm(other), target(other.target){
}

Robot& Robot::operator=(const Robot& other){
	if(this != &other){
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

void Robot::execute(Bureaucrat const& executor) const{
	if(!this->getIsSigned())
		throw FormNotSignedException();
	if(executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	std::cout << "Driiiillll Driiiillll ! " << std::endl;

	//chance aleatoire
	srand(time(NULL));
	if(rand() % 2){ //50% de chance
		std::cout << this->target << " has been robotomized successfully !" << std::endl;
	} else {
		std::cout << "Robotisation of " << this->target << " has failed." << std::endl;
	}
}