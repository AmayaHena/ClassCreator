/*
** EPITECH PROJECT, 2019
** ClassCreator
** File description:
** BabyWheel
*/

#ifndef BABYWHEEL_HPP_
#define BABYWHEEL_HPP_

/* STD LIB */
#include <iostream>
#include <vector>

class BabyWheel {

	public:

		BabyWheel() = default;
		~BabyWheel() = default;

		/* Unlock BabyWheel */
		bool unlock(std::vector<std::string> v);

	private:

		/* Tools */
		void printFile(std::string s);

		/* Verification of BabyWheel State */
		bool babyCheck();
		bool babyImprove();

		std::vector<std::string> _v;
		std::string s;

};

#endif /* !BABYWHEEL_HPP_ */
