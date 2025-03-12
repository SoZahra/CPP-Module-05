/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:59:38 by fzayani           #+#    #+#             */
/*   Updated: 2025/03/12 17:20:01 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
	try {
		// Création d'un Intern
		Intern someRandomIntern;

		// Création des bureaucrates
		Bureaucrat boss("Boss", 1);

		// Test de création de différents formulaires
		AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Zaphod");
		AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Garden");

		// Test des formulaires créés
		std::cout << "\nTest des formulaires créés par l'Intern:" << std::endl;
		std::cout << *rrf << std::endl;
		std::cout << *ppf << std::endl;
		std::cout << *scf << std::endl;

		// Signature et exécution
		boss.signForm(*rrf);
		boss.executeForm(*rrf);

		boss.signForm(*ppf);
		boss.executeForm(*ppf);

		boss.signForm(*scf);
		boss.executeForm(*scf);

		// Test avec un nom de formulaire invalide
		try {
			AForm* unknown = someRandomIntern.makeForm("unknown form", "Target");
			delete unknown; // Ne sera jamais exécuté
		} catch (std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}

		// Nettoyage (important pour éviter les fuites de mémoire)
		delete rrf;
		delete ppf;
		delete scf;

	} catch (std::exception& e) {
		std::cout << "Exception inattendue: " << e.what() << std::endl;
	}

	return 0;
}