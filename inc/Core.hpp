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

		Core() = default;
		~Core() = default;

		/* Main Method - Run the program */
		bool run(const std::vector<std::string> &v);

	private:

		/* Fill Path for Ressources _inc and _src */
		void fillPath(const std::string &s);

		/* Generation Folders and Files */
		bool architectCode();
		void minimalCode();
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

		/* Variables - Ressource for subfiles */
		std::vector<std::string> _arch;

};

#endif /* !CORE_HPP_ */
