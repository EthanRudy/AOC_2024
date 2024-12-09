#ifndef DAY_02_HPP
#define DAY_02_HPP

#include "../include/calendar.hpp"

inline static bool safe_report(const std::vector<int>& report) {
	bool safe = true, increasing;

	// Increasing
	if (report[0] > report[1]) { increasing = false; }
	// Decreasing
	else if (report[0] < report[1]) { increasing = true; }
	// Unsafe, neither increasing or decreasing
	else { return false; }

	for (int i = 0; i < report.size() - 1; ++i) {
		int diff = report[i + 1] - report[i];

		// Unsafe, to large a difference
		if (abs(diff) < 1 || abs(diff) > 3) { return false; }

		// Unsafe, mismatch inc/dec
		if ((increasing && diff <= 0) || (!increasing && diff >= 0)) { return false; }
	}

	return true;
}

void Calendar::Day02_Part1() {
	std::vector<std::vector<int>> reports;
	while (std::getline(input, line)) {
		std::stringstream ss(line);

		std::vector<int> report;
		while (ss >> token) {
			report.push_back(std::stoi(token));
		}
		reports.push_back(report);
	}

	timer.start();

	int num_safe = 0;
	for (const auto& report : reports) {
		if (safe_report(report)) { ++num_safe; }
	}

	timer.end();
	auto dura = timer.duration();
	std::cout << "Day 02 P1: " << num_safe << " found in " << dura.first << " " << dura.second << "(s)\n";
}

void Calendar::Day02_Part2() {
	std::vector<std::vector<int>> reports;
	while (std::getline(input, line)) {
		std::stringstream ss(line);

		std::vector<int> report;
		while (ss >> token) {
			report.push_back(std::stoi(token));
		}
		reports.push_back(report);
	}

	timer.start();

	int num_safe = 0;
	for (const auto report : reports) {
		if (safe_report(report)) { 
			++num_safe;
		}
		else {
			for (int i = 0; i < report.size(); ++i) {
				auto report_cpy = report;
				report_cpy.erase(report_cpy.begin() + i);

				if (safe_report(report_cpy)) {
					++num_safe;
					break;
				}
			}
		}
	}

	timer.end();
	auto dura = timer.duration();
	std::cout << "Day 02 P2: " << num_safe << " found in " << dura.first << " " << dura.second << "(s)\n";
}

#endif // !DAY_01_HPP