/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:15:15 by fzayani           #+#    #+#             */
/*   Updated: 2025/03/12 17:21:54 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() {
}

Intern::~Intern() {
}

Intern::Intern(const Intern& other) {
	 (void)other;// L'Intern n'a pas d'attributs à copier
}

Intern& Intern::operator=(const Intern& other) {
	(void)other; // L'Intern n'a pas d'attributs à copier
	return *this;
}

const char* Intern::UnknownFormException::what() const throw() {
	return "Unknown form type!";
}

// Fonctions de création des différents formulaires
static AForm* createPresidential(const std::string& target) {
	return new Presidential(target);
}

static AForm* createRobotomy(const std::string& target) {
	return new Robot(target);
}

static AForm* createShrubbery(const std::string& target) {
	return new Shrubbery(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
	// Structure pour associer les noms de formulaires aux fonctions de création
	struct FormCreator {
		std::string name;
		AForm* (*create)(const std::string&);
		std::string displayName;
	};

	// Tableau des formulaires disponibles
	const FormCreator forms[] = {
		{"presidential pardon", createPresidential, "Presidential Pardon Form"},
		{"robotomy request", createRobotomy, "Robotomy Request Form"},
		{"shrubbery creation", createShrubbery, "Shrubbery Creation Form"}
	};

	const int numForms = sizeof(forms) / sizeof(forms[0]);

	// Rechercher le formulaire par son nom
	for (int i = 0; i < numForms; i++) {
		if (formName == forms[i].name) {
			AForm* form = forms[i].create(target);
			std::cout << "Intern creates " << forms[i].displayName << std::endl;
			return form;
		}
	}

	// Si le formulaire n'est pas trouvé
	std::cout << "Intern cannot create form: " << formName << " (unknown form type)" << std::endl;
	throw UnknownFormException();
}