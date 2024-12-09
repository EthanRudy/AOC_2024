#ifndef DAY_03_HPP
#define DAY_03_HPP

#include "../include/calendar.h"

inline void Calendar::Day03_Part1() {
	// Input
	std::string instructions = "";
	while (std::getline(input, line)) {
		instructions += line;
	}

	timer.start();



	timer.end();
	auto dura = timer.duration();
	std::cout << "Day 03 P1: " << "ANS" << " found in " << dura.first << " " << dura.second << "(s)\n";
}

inline void Calendar::Day03_Part2() {
	// Input

	timer.start();

	// Solve

	timer.end();
	auto dura = timer.duration();
	std::cout << "Day 03 P2: " << "ANS" << " found in " << dura.first << " " << dura.second << "(s)\n";
}

#endif // !DAY_01_HPP