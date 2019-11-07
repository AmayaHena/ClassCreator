/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** parser
*/

#include "Parser.hpp"

Parser::Parser() : _main(false), _interface(false), _inheritance(false), _makefile(false), _cmake(false), _folders(false) {}

std::string Parser::getProjectName(void)
{
	return _project_name;
}

bool Parser::getMain(void)
{
	return _main;
}

std::vector<std::string> Parser::getSubFiles(void)
{
	return _sub_files;
}

bool Parser::getInheritance(void)
{
	return _inheritance;
}

bool Parser::getInterface(void)
{
	return _interface;
}

bool Parser::getMakefile(void)
{
	return _makefile;
}

bool Parser::getFolders(void)
{
	return _folders;
}

bool Parser::getCMake(void)
{
	return _cmake;
}

std::string Parser::getArchitecture()
{
	return _architecture;
}

bool Parser::helperCommand()
{
    std::cout << "usage: classCreator [Project Name] [-miMCdfA] ..." << std::endl
              << std::endl << "\tOptions:" << std::endl
              << "\t-m\tmake a main function" << std::endl
              << "\t-i\tmake inheritance from the main class of the project" << std::endl
              << "\t-I\tmake interface for every class" << std::endl
              << "\t-M\tmake a makefile" << std::endl
              << "\t-C\tmake CMakeLists.txt for CMake" << std::endl
              << "\t-d\tmake directory for classes" << std::endl
              << "\t-f\tmake some subfiles for your project, muste be follow by subfiles name" << std::endl
              << "\t-A\ttake a file as parameter following this option and generate an architecture" << std::endl << std::endl;
    return false;
}

void Parser::AVOptions(const std::vector<std::string> &v, const int i)
{
	for (int j = 1; v[i][j]; j++) {
		switch (v[i][j]) {
		case 'm' :
			_main = true;
			break;
		case 'i' :
			_inheritance = true;
			break;
		case 'I' :
			_interface = true;
			break;
		case 'M' :
			_makefile = true;
			break;
		case 'C' :
			_cmake = true;
			break;
		case 'd' :
			_folders = true;
			break;
		case 'A' :
			_architecture = v[i + 1];
			break;
		}
	}
}

bool Parser::parsingAV(const std::vector<std::string> &v)
{
	if (v.empty())
		return false;
	if (v[0] == "-h")
		return Parser::helperCommand();
	_project_name = v[0];
	for (unsigned int i = 1; i < v.size(); i++) {
		if (v[i][0] == '-')
			Parser::AVOptions(v, i);
		else
			_sub_files.push_back(v[i]);
	}
	return true;
}

bool Parser::parsingProceed(const std::vector<std::string> &v)
{
	if (v.empty())
		return false;
	Parser::parsingAV(v);
	return true;
}
