#ifndef DAY_01_HPP
#define DAY_01_HPP

#include "../include/calendar.hpp"

inline void Calendar::Day01_Part1() {
	// Auto sorted insertion
	std::multiset<int> left, right;

	while (std::getline(input, line)) {
		std::stringstream ss(line);

		ss >> token;
		left.insert(std::stoi(token));

		ss >> token;
		right.insert(std::stoi(token));
	}

	timer.start();

	int dist = 0;
	for (auto iter1 = left.begin(); iter1 != left.end(); ++iter1) {
		int index = std::distance(left.begin(), iter1);
		auto iter2 = std::next(right.begin(), index);
		dist += abs(*iter1 - *iter2);
	}

	timer.end();
	auto dura = timer.duration();
	std::cout << "Day 01 P1: " << dist << " found in " << dura.first << " " <<  dura.second << "(s)\n";
}

inline void Calendar::Day01_Part2() {
	std::vector<int> left;
	std::map<int, int> right;

	while (std::getline(input, line)) {
		std::stringstream ss(line);

		ss >> token;
		left.push_back(std::stoi(token));

		ss >> token;
		++right[std::stoi(token)];
	}

	timer.start();

	int sim_score = 0;
	for (int i : left) {
		sim_score += right[i] * i;
	}

	timer.end();
	auto dura = timer.duration();
	std::cout << "Day 01 P2: " << sim_score << " found in " << dura.first << " " << dura.second << "(s)\n";

}

#endif // !DAY_01_HPP