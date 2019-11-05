/*
** EPITECH PROJECT, 2019
** ClassCreatorWIP
** File description:
** State
*/

#ifndef STATE_HPP_
#define STATE_HPP_

/* STD LIB */
#include <iostream>
#include <vector>

/* Class */
#include "Parser.hpp"
#include "Writer.hpp"
#include "Dir.hpp"

class State {

	public:

		State() = default;
		~State() = default;

		/* Tools - state the writer and launch writer */
		/* CPP HPP Interface */
		void createHpp(Parser &p, Writer &w, const std::vector<std::string> &file, const std::string &s);
		void createCpp(Parser &p, Writer &w, const std::vector<std::string> &file, const std::string &s);
		void createInterface(Parser &p, Writer &w, const std::vector<std::string> &file, const std::string &s);

		/* CPP HPP Interface for complex arch */
		void createHppArch(Parser &p, Writer &w, const std::vector<std::string> &file, const std::vector<std::string> &tmp, std::string &path, unsigned int i, std::string &past_path);
		void createCppArch(Parser &p, Writer &w, const std::vector<std::string> &file, const std::vector<std::string> &tmp, std::string &path, unsigned int i);
		void createInterfaceArch(Parser &p, Writer &w, const std::vector<std::string> &file, const std::vector<std::string> &tmp, std::string &path, unsigned int i, std::string &past_path);

		/* CPP HPP Interface at Root */
		void createHppRoot(Parser &p, Writer &w, const std::vector<std::string> &file, const std::string &s);
		void createCppRoot(Parser &p, Writer &w, const std::vector<std::string> &file, const std::string &s);
		void createInterfaceRoot(Parser &p, Writer &w, const std::vector<std::string> &file, const std::string &s);

		/* main Makefile CMake at Root */
		void generateMain(Parser &p, Writer &w, const std::vector<std::string> &file, const std::vector<std::string> &inc);
		void generateMakefile(Parser &p, Writer &w, const std::vector<std::string> &file, const std::vector<std::string> &src);
		void generateCMake(Parser &p, Writer &w, const std::vector<std::string> &file, const std::vector<std::string> &inc, const std::vector<std::string> &src);

	private:

		Dir _d;

};

#endif /* !STATE_HPP_ */
