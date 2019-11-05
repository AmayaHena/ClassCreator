/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** Architechture
*/

#include "Architecture.hpp"

/* STD LIB */
#include <algorithm>
#include <cctype>
#include <regex>

std::string Architecture::alignCut(std::string &ref, std::string s)
{
	int i = 0;
	int j = 0;

	i = ref.size();
	j = 0;
	while (s[j++] == ' ');
	while (i + 1 != j - 1) {
		while (ref[i--] != '-')
			if (i <= 0)
				break;
		if (i <= 0)
			break;
		if (i + 1 == j - 1)
			break;
	}
	return ref.substr(0, i) + s;
}

std::vector<std::string> Architecture::completePartial(std::vector<std::string> &v)
{
    std::vector<std::string> vector;
	std::string ref;
	std::string buf;

	for (const std::string &s : v) {
		if (s[0] == '-')
			buf = s;
		if (!s.empty() && s[0] != '-')
			buf = Architecture::alignCut(ref, s);
		buf.erase(remove_if(buf.begin(), buf.end(), static_cast<int(*)(int)>(&std::isspace)),buf.end());
		if (!s.empty())
 			vector.push_back(buf);
		buf = std::regex_replace(buf, std::regex("-"), " - ");
		buf.erase(buf.begin());
		ref = buf;
	}
    return vector;
}


std::vector<std::string> Architecture::cutLine(std::string s)
{
    std::vector<std::string> vector;

	std::istringstream is(s);
	while (std::getline(is, s, '-'))
		vector.push_back(s);

	return vector;
}