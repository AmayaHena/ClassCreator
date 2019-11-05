/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** Architechture
*/

#ifndef ARCHITECHTURE_HPP_
#define ARCHITECHTURE_HPP_

/* STD LIB */
#include <iostream>

/* TYPE LIB */
#include <vector>

class Architecture {

	public:

		Architecture() = default;
		~Architecture() = default;

		/* Tools for complex arch */
		std::vector<std::string> completePartial(std::vector<std::string> &v);
		std::vector<std::string> cutLine(std::string &s);

	private:

		/* Tool for completeParital Method */
		std::string alignCut(std::string &ref, std::string s);

};

#endif /* !ARCHITECHTURE_HPP_ */
