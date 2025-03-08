/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:15:58 by fzayani           #+#    #+#             */
/*   Updated: 2025/03/08 16:21:48 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>


int main() {
	try {
		// Test constructeur normal
		Bureaucrat b1("John", 50);
		std::cout << b1 << std::endl;

		// Test incrémentation
		b1.incrementGrade();
		std::cout << "After increment: " << b1 << std::endl;

		// Test décrémentation
		b1.decrementGrade();
		std::cout << "After decrement: " << b1 << std::endl;

		// Test grade trop haut
		try {
			Bureaucrat b2("Alex", 0);  // Devrait lancer une exception
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}

		// Test grade trop bas
		try {
			Bureaucrat b3("Bob", 151);  // Devrait lancer une exception
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}

		// Test incrémentation limite
		Bureaucrat b4("Charlie", 1);
		std::cout << b4 << std::endl;
		try {
			b4.incrementGrade();  // Devrait lancer une exception
		} catch (std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}

		// Test décrémentation limite
		Bureaucrat b5("Dave", 150);
		std::cout << b5 << std::endl;
		try {
			b5.decrementGrade();  // Devrait lancer une exception
		} catch (std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	} catch (std::exception& e) {
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}
	return 0;
}