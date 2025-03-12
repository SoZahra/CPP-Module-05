/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:38:26 by fzayani           #+#    #+#             */
/*   Updated: 2025/03/12 16:14:54 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

Shrubbery::Shrubbery (const std::string& target):
	AForm(" Shrubbery Form", 145, 137), target(target){
}

Shrubbery::~Shrubbery(){
}

Shrubbery::Shrubbery(const Shrubbery& other):
	AForm(other), target(other.target){
}

Shrubbery& Shrubbery::operator=(const Shrubbery& other){
	if(this != &other){
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

void Shrubbery::execute(Bureaucrat const& executor) const{
	if(!this->getIsSigned())
		throw FormNotSignedException();
	if(executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();

	std::string filename = this->target +"_shrubbery";
	std::ofstream outfile(filename.c_str());

	if(!outfile.is_open()){
		std::cerr << "Error: Could not create file " << filename << std::endl;
		return;
	}

	outfile << "    /\\    " << std::endl;
    outfile << "   /  \\   " << std::endl;
    outfile << "  /    \\  " << std::endl;
    outfile << " /      \\ " << std::endl;
    outfile << "/________\\" << std::endl;
    outfile << "    ||    " << std::endl;
    outfile << "    ||    " << std::endl;
    outfile << std::endl;
    outfile << "       /\\       " << std::endl;
    outfile << "      /  \\      " << std::endl;
    outfile << "     /    \\     " << std::endl;
    outfile << "    /      \\    " << std::endl;
    outfile << "   /        \\   " << std::endl;
    outfile << "  /          \\  " << std::endl;
    outfile << " /            \\ " << std::endl;
    outfile << "/              \\" << std::endl;
    outfile << "^^^^^^^^^^^^^^^^" << std::endl;
    outfile << "      ||||      " << std::endl;
    outfile << "      ||||      " << std::endl;

    outfile.close();

	std::cout << "Create file " << filename << " with ASCII trees" << std::endl;
}