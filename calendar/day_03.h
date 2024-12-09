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

	int sum = 0;
	while (instructions.find("mul(") != std::string::npos) {
		// Find next "mul("
		int index = instructions.find("mul(");
		int offset = 4;
		bool skip = false;
		
		// First number
		std::string num1 = "";
		while (instructions[index + offset] > 47 && instructions[index + offset] < 58) {
			num1 += instructions[index + offset];
			++offset;
		}
		if (num1.size() < 1 || num1.size() > 3) { skip = true; }

		// Comma
		if (skip || instructions[index + offset] != ',') {
			instructions = instructions.substr(index + offset);
			continue;
		}
		else {
			++offset;
		}

		// Second Number
		std::string num2 = "";
		while (instructions[index + offset] > 47 && instructions[index + offset] < 58) {
			num2 += instructions[index + offset];
			++offset;
		}
		if (num2.size() < 1 || num2.size() > 3) { skip = true; }

		// Last Parenthese
		if (skip || instructions[index + offset] != ')') {
			instructions = instructions.substr(index + offset);
			continue;
		}
		else {
			++offset;
		}

		instructions = instructions.substr(index + offset);
		sum += (std::stoi(num1) * std::stoi(num2));
	}

	timer.end();
	auto dura = timer.duration();
	std::cout << "Day 03 P1: " << sum << " found in " << dura.first << " " << dura.second << "(s)\n";
}

inline void Calendar::Day03_Part2() {
	// Input
	std::string instructions = "";
	while (std::getline(input, line)) {
		instructions += line;
	}

	timer.start();

	int sum_enabled = 0;
	bool enabled = true;
	while (instructions.find("mul(") != std::string::npos) {
		// Find next "mul("
		int index = instructions.find("mul(");
		int offset = 4;
		bool skip = false;

		int doIndex = instructions.find("do()");
		int dontIndex = instructions.find("don't()");

		if (doIndex == -1) { doIndex = 999999999; }
		if (dontIndex == -1) { dontIndex = 999999999; }

		if (doIndex < dontIndex && doIndex < index) {
			enabled = true;
			instructions = instructions.substr(doIndex + 1);
			continue;
		}
		else if (dontIndex < doIndex && dontIndex < index) {
			enabled = false;
			instructions = instructions.substr(dontIndex + 1);
			continue;
		}

		// First number
		std::string num1 = "";
		while (instructions[index + offset] > 47 && instructions[index + offset] < 58) {
			num1 += instructions[index + offset];
			++offset;
		}
		if (num1.size() < 1 || num1.size() > 3) { skip = true; }

		// Comma
		if (skip || instructions[index + offset] != ',') {
			instructions = instructions.substr(index + offset);
			continue;
		}
		else {
			++offset;
		}

		// Second Number
		std::string num2 = "";
		while (instructions[index + offset] > 47 && instructions[index + offset] < 58) {
			num2 += instructions[index + offset];
			++offset;
		}
		if (num2.size() < 1 || num2.size() > 3) { skip = true; }

		// Last Parenthese
		if (skip || instructions[index + offset] != ')') {
			instructions = instructions.substr(index + offset);
			continue;
		}
		else {
			++offset;
		}

		instructions = instructions.substr(index + offset);
		sum_enabled += (std::stoi(num1) * std::stoi(num2)) * enabled;
	}

	timer.end();
	auto dura = timer.duration();
	std::cout << "Day 03 P2: " << sum_enabled << " found in " << dura.first << " " << dura.second << "(s)\n";
}

#endif // !DAY_01_HPP