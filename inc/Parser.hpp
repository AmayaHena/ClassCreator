/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

/* STD Library */
#include <iostream>

/* STD Types Library */
#include <vector>

/* Types Library */
#include <sstream>
#include <iterator>

class Parser {

	public:

		Parser();
		~Parser() = default;

		/* Parsing public */
		bool helperCommand(void);
		void parsingProceed(const std::vector<std::string> &v);

		/* Getters */
		std::string getProjectName();
		bool getMain();
		std::vector<std::string> getSubFiles();
		bool getInheritance();
		bool getInterface();
		bool getMakefile();
		bool getCMake();
		bool getFolders();
		std::string getArchitecture();

	private:

		/* Parsing private */
		std::string userInput();

		/* Parsing Types */
		std::string parsingString(const std::string &type, const std::string &convention);
		std::vector<std::string> parsingStoVector(const std::string &type, const std::string &convention);
		bool parsingBoolean(std::string s);

		/* Parsing AV */
		void AVOptions(const std::vector<std::string> &v, const int i);
		bool parsingAV(const std::vector<std::string> &v);

		/* Variables - Ressources for user inputs */
		std::string _project_name;
		bool _main;
		std::vector<std::string> _sub_files;
		bool _interface;
		bool _inheritance;
		bool _makefile;
		bool _cmake;
		bool _folders;
		std::string _architecture;

};

#endif /* !PARSER_HPP_ */
