/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:59:38 by fzayani           #+#    #+#             */
/*   Updated: 2025/03/12 16:59:17 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

//test avec robotisation qui fail

// int main() {
// 	try {
// 		// Test des bureaucrates
// 		Bureaucrat ceo("CEO", 1);
// 		Bureaucrat manager("Manager", 40);
// 		Bureaucrat intern("Intern", 140);

// 		std::cout << ceo << std::endl;
// 		std::cout << manager << std::endl;
// 		std::cout << intern << std::endl;

// 		// Test des formulaires
// 		Presidential pardon("John Doe");
// 		Robot robotomy("Jane Doe");
// 		Shrubbery shrubbery("Garden");

// 		std::cout << pardon << std::endl;
// 		std::cout << robotomy << std::endl;
// 		std::cout << shrubbery << std::endl;

// 		// Test de signature et d'exécution
// 		// Le CEO peut tout signer et exécuter
// 		ceo.signForm(pardon);
// 		ceo.executeForm(pardon);

// 		// Le manager peut signer et exécuter la robotomy
// 		manager.signForm(robotomy);
// 		manager.executeForm(robotomy);

// 		// Le manager peut signer mais pas exécuter le pardon
// 		try {
// 			manager.signForm(pardon);
// 			manager.executeForm(pardon);
// 		} catch (std::exception& e) {
// 			std::cout << "Exception caught: " << e.what() << std::endl;
// 		}

// 		// Le stagiaire peut seulement signer et exécuter le shrubbery
// 		intern.signForm(shrubbery);
// 		intern.executeForm(shrubbery);

// 		// Test d'un formulaire non signé
// 		Shrubbery unsignedShrubbery("Backyard");
// 		try {
// 			manager.executeForm(unsignedShrubbery);
// 		} catch (std::exception& e) {
// 			std::cout << "Exception caught: " << e.what() << std::endl;
// 		}

// 	} catch (std::exception& e) {
// 		std::cout << "Exception caught: " << e.what() << std::endl;
// 	}
// 	return 0;
// }


//test avec robotisation qui ne fail pas

int main() {
	try {
		// Test des bureaucrates
		Bureaucrat ceo("CEO", 1);  // Grade 1 - le plus élevé

		std::cout << ceo << std::endl;

		// Créer un formulaire ShrubberyCreationForm
		Shrubbery shrubbery("Garden");

		std::cout << "Formulaire créé: " << shrubbery << std::endl;

		// Le CEO peut signer et exécuter le formulaire
		std::cout << "\nTest de signature et d'exécution du formulaire Shrubbery:" << std::endl;
		ceo.signForm(shrubbery);
		ceo.executeForm(shrubbery);

		// Afficher le contenu du fichier créé
		std::cout << "\nContenu du fichier Garden_shrubbery:" << std::endl;
		std::ifstream file("Garden_shrubbery");
		if (file.is_open()) {
			std::string line;
			while (getline(file, line)) {
				std::cout << line << std::endl;
			}
			file.close();
		} else {
			std::cout << "Impossible d'ouvrir le fichier." << std::endl;
		}

	} catch (std::exception& e) {
		std::cout << "Exception inattendue: " << e.what() << std::endl;
	}

	return 0;
}