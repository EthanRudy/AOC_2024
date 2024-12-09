#ifndef DAY_07_HPP
#define DAY_07_HPP

#include "../include/calendar.h"

std::string gen_binary_str(unsigned long long num, int bits) {
	unsigned long long base = pow(2, bits - 1);

	std::string str = "";

	while (base > 0) {
		if (num >= base) {
			str += "1"; 
			num -= base;
		}
		else {
			str += "0";
		}

		base /= 2;
	}

	return str;
}

inline void Calendar::Day07_Part1() {
	std::vector<std::pair<unsigned long long, std::vector<unsigned long long>>> equations;

	while (std::getline(input, line)) {
		std::stringstream ss(line);

		bool first = true;
		std::pair<unsigned long long, std::vector<unsigned long long>> equation;
		while (ss >> token) {
			if (first) {
				std::cout << token << "\n";
				equation.first = std::stoll(token.substr(0, token.size() - 1));
				first = false;
			}
			else {
				equation.second.push_back(std::stoll(token));
			}
		}

		equations.push_back(equation);
	}

	timer.start();

	// Solve
	// Okay we doing permutations for now

	unsigned long long total_cal = 0;
	for (auto& equation : equations) {

		std::cout << equation.first << ":\n";

		unsigned long long target = equation.first;

		bool found = false;
		int permu = 0;
		std::string bin_mask = "";
		int bits = equation.second.size() - 1;

		while (!found && permu < pow(2, bits)) {
			// Generate a permuation
			bin_mask = gen_binary_str(permu, bits);
			
			// Try it out
			unsigned long long num = equation.second[0];
			for (int i = 0; i < bits; ++i) {
				// Add
				if (bin_mask[i] == '0') {
					num += equation.second[i + 1];
				}
				// Mult
				else {
					num *= equation.second[i + 1];
				}
			}

			if (num == target) {
				total_cal += target;
				break;
			}

			++permu;
		}
	}

	timer.end();
	auto dura = timer.duration();
	std::cout << "Day 07 P1: " << total_cal << " found in " << dura.first << " " << dura.second << "(s)\n";
}

inline void Calendar::Day07_Part2() {
	// Input

	timer.start();

	// Solve

	timer.end();
	auto dura = timer.duration();
	std::cout << "Day 07 P2: " << "ANS" << " found in " << dura.first << " " << dura.second << "(s)\n";
}

#endif // !DAY_01_HPP