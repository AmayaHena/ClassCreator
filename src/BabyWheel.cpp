/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** BabyWheel
*/

/* STD LIB */
#include <functional>
#include <fstream>

#include "File.hpp"

#include "BabyWheel.hpp"

void BabyWheel::printFile(std::string s)
{
	File f;
	std::vector<std::string> v = f.loadFile(s, true);

	for (const std::string &s : v)
		std::cout << s << std::endl;
}

bool BabyWheel::babyCheck()
{
	std::string s = "-EDITH";

	if (_v[0] != s)
		return false;
	if (_v.size() != 2)
		return false;
	if (_v[1] != "17A")
		return false;
	return true;
}

bool BabyWheel::babyImprove()
{
	File f;
	std::vector<std::string> v = f.loadFile("config/.baby", true);

	if (std::stoi(v[0]) > 25)
		return true;
	std::ofstream file("config/.baby");
	int i = std::stoi(v[0]) + 1;
	file << i << std::endl;
	return false;
}

bool BabyWheel::unlock(std::vector<std::string> v)
{
	_v = v;
//	if (!babyCheck())
//		return false;
//	else if (!babyImprove())
//		return false;
	std::cout << "\033[1;32mBaby wheel complete\033[0m" << std::endl;
	std::cout << "\033[1;32mYou'll have the full fonctionality of ClassCreator\033[0m" << std::endl;
	printFile("config/.header");
	return true;
}