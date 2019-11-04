/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** Architechture
*/

#include "Architecture.hpp"

#include <algorithm>
#include <cctype>
#include <regex>

std::vector<std::string> Architecture::completePartial(std::vector<std::string> &v)
{
    std::vector<std::string> vector;
	std::string ref;
	std::string buf;
	int i = 0;
	int j = 0;

	for (const std::string &s : v) {
		if (s[0] == '-') {
			ref = s;
			buf = s;
		}
		if (!s.empty() && s[0] != '-') {
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
			buf = ref.substr(0, i) + s;
		}
		buf.erase(remove_if(buf.begin(), buf.end(), static_cast<int(*)(int)>(&std::isspace)),buf.end());
		std::replace(buf.begin(), buf.end(), '-', '/');
		if (!s.empty())
 			vector.push_back(buf);
		buf = std::regex_replace(buf, std::regex("/"), " - ");
		buf.erase(buf.begin());
		ref = buf;
	}
    return vector;
}


std::vector<std::string> Architecture::cutLine(std::string &s)
{
	/// 2 - Send the current line to a cutter
	/// Wich return a vector of string with a string by dir
	///
	/// Example :
	/// /Item/Potion/Heal
	/// /Item/Potion/Heal
	/// Into :
	/// (Considering, std::vector<std::string> v)
	/// v[0] = *Project Name*
	/// v[1] = "inc"
	/// v[2] = "Item"
	/// v[3] = "Potion"
	/// v[4] = "Heal"
	///
	/// v[0] = *Project Name*
	/// v[1] = "src"
	/// v[2] = "Item"
	/// v[3] = "Potion"
	/// v[4] = "Heal"

    std::vector<std::string> vector;
    (void)vector;
    (void)s;
    return vector;
}