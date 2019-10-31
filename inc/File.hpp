/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** File
*/

#ifndef FILE_HPP_
#define FILE_HPP_

/* STD Library */
#include <vector>
#include <iostream>
#include <fstream>
#include <unistd.h>

class File {

	public:

		File() = default;
		~File() = default;

		/* Load Config public */
		bool loadConfig(const bool main, const bool make, const bool cmake);

		/* Getters */
		std::vector<std::string> getMain();
		std::vector<std::string> getFileCpp();
		std::vector<std::string> getFileHpp();
		std::vector<std::string> getHeader();
		std::vector<std::string> getMakefile();
		std::vector<std::string> getCMake();

	private:

		/* Generic Tool to load file */
		std::vector<std::string> loadFile(const std::string &path, const bool request);

		/* Checks */
		bool checkDirExist(const std::string &s);
		bool checkFileExist(const std::string &s);

		/* Load Config private */
		std::vector<std::string> loadFileToV(const std::string &path);

		/* Variables - Ressources containers for files*/
		std::vector<std::string> _fileHpp;
		std::vector<std::string> _fileCpp;
		std::vector<std::string> _header;
		std::vector<std::string> _main;
		std::vector<std::string> _make;
		std::vector<std::string> _cmake;

};

#endif /* !FILE_HPP_ */
