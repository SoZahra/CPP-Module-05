/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:15:58 by fzayani           #+#    #+#             */
/*   Updated: 2025/03/08 18:29:40 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		// Test des bureaucrates
		Bureaucrat highGrade("John", 5);
		Bureaucrat lowGrade("Bob", 100);

		std::cout << highGrade << std::endl;
		std::cout << lowGrade << std::endl;

		// Test des formulaires
		Form easyForm("Simple Form", 90, 100);
		Form hardForm("Complex Form", 20, 10);

		std::cout << easyForm << std::endl;
		std::cout << hardForm << std::endl;

		// Test de signature des formulaires
		highGrade.signForm(easyForm);
		highGrade.signForm(hardForm);

		lowGrade.signForm(easyForm);
		lowGrade.signForm(hardForm);

		// Vérification après signature
		std::cout << "After signing attempts:" << std::endl;
		std::cout << easyForm << std::endl;
		std::cout << hardForm << std::endl;

		// Test des exceptions
		try {
			Form invalidForm("Invalid", 0, 100); // Grade trop élevé
		} catch (std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}

		try {
			Form invalidForm("Invalid", 100, 151); // Grade trop bas
		} catch (std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}

	} catch (std::exception& e) {
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	return 0;
}