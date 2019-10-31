/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

/* STD LIB */
#include <iostream>

/* STD Types LIB */
#include <vector>
#include <string>

/* Class */
#include "Dir.hpp"
#include "File.hpp"
#include "Parser.hpp"
#include "Writer.hpp"
#include "State.hpp"

class Core {

	public:

		Core(const std::vector<std::string> &v);
		~Core() = default;

		/* Main Method - Run the program */
		bool run();

	private:

		/* Fill Path for Ressources _inc and _src */
		void fillPath(const std::string &s);

		/* Generation Folders and Files */
		bool generateCode();

		/* tools */
		void buildProject();

		/* Class */
		Parser _p;
		Dir _d;
		File _f;
		Writer _w;
		State _s;

		/* Variables - Ressource to build project */
		std::vector<std::string> _inc;
		std::vector<std::string> _src;

};

#endif /* !CORE_HPP_ */
