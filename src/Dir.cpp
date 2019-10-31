/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** dir
*/

/* STD LIB */
#include <iostream>

/* MKDIR LIB */
#include <sys/stat.h>
#include <sys/types.h>

#include "Dir.hpp"

bool Dir::createDir(const std::string &path, const std::string &name)
{
	std::string s = path + "/" + name;
	struct stat buffer;

	if (stat(s.c_str(), &buffer) == 0) {
		std::cout << "\033[0;33mDir already exits : \033[0m" << s << std::endl;
		return false;
	}
	if (mkdir(s.c_str(), 0777) == -1) {
		std::cout << "\033[0;31mFailed to create dir : \033[0m" << s << std::endl;
		return false;
	}
	std::cout << "\033[0;32mCreated dir : \033[0m" << s << std::endl;
	return true;
}
