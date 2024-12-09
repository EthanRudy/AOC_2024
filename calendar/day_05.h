#ifndef DAY_05_HPP
#define DAY_05_HPP

#include "../include/calendar.h"

struct day_05_rule {
	int X;
	std::vector<int> Ys;
};

static int Xi, Yi;

bool rule_passed(const std::vector<day_05_rule>& rules, const std::vector<int>& update) {
	bool passed = true;

	for (int i = 0; i < update.size() - 1; ++i) {

		int X = update[i + 1], Y = update[i];

		for (auto& rule : rules) {
			if (rule.X == X) {
				if (std::find(rule.Ys.begin(), rule.Ys.end(), Y) != rule.Ys.end()) {
					Xi = i + 1, Yi = i;

					return false;
				}
			}
		}
	}

	return true;
}

inline void Calendar::Day05_Part1() {
	std::vector<day_05_rule> rules;
	std::vector<std::vector<int>> updates;
	bool rule_section = true;
	while (std::getline(input, line)) {

		if (line == "") {
			rule_section = false;
			continue;
		}

		if (rule_section) {
			int X = std::stoi(line.substr(0, 2));
			int Y = std::stoi(line.substr(3));

			bool newX = true;
			for (auto& rule : rules) {
				if (rule.X == X) {
					rule.Ys.push_back(Y);
					newX = false;
					break;
				}
			}

			if (newX) {
				rules.push_back({ X, {Y} });
			}
		}
		else {
			std::stringstream ss(line);

			std::vector<int> new_update;

			while (std::getline(ss, token, ',')) {
				new_update.push_back(std::stoi(token));
			}

			updates.push_back(new_update);
		}
	}

	timer.start();

	int sum = 0;

	for (auto& update : updates) {
		if (rule_passed(rules, update)) {
			sum += update[update.size() / 2];
		}
	}

	timer.end();
	auto dura = timer.duration();
	std::cout << "Day 05 P1: " << sum << " found in " << dura.first << " " << dura.second << "(s)\n";
}

inline void Calendar::Day05_Part2() {
	std::vector<day_05_rule> rules;
	std::vector<std::vector<int>> updates;
	bool rule_section = true;
	while (std::getline(input, line)) {

		if (line == "") {
			rule_section = false;
			continue;
		}

		if (rule_section) {
			int X = std::stoi(line.substr(0, 2));
			int Y = std::stoi(line.substr(3));

			bool newX = true;
			for (auto& rule : rules) {
				if (rule.X == X) {
					rule.Ys.push_back(Y);
					newX = false;
					break;
				}
			}

			if (newX) {
				rules.push_back({ X, {Y} });
			}
		}
		else {
			std::stringstream ss(line);

			std::vector<int> new_update;

			while (std::getline(ss, token, ',')) {
				new_update.push_back(std::stoi(token));
			}

			updates.push_back(new_update);
		}
	}

	timer.start();

	// Somehow really fucking fast?
	// My first attempt wasn't any different but its suddenly faster
	// Idk what I did but yipee?
	int sum = 0;
	for (auto& update : updates) {

		if (!rule_passed(rules, update)) {

			while (!rule_passed(rules, update)) {
				int temp = update[Xi];
				update[Xi] = update[Yi];
				update[Yi] = temp;
			}

			sum += update[update.size() / 2];
		}
	}

	timer.end();
	auto dura = timer.duration();
	std::cout << "Day 05 P2: " << sum << " found in " << dura.first << " " << dura.second << "(s)\n";
}

#endif // !DAY_01_HPP