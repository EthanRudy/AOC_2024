#ifndef UTILS_H
#define UTILS_H

#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "timer.h"

class Calendar {
public:

	Calendar() {}

	Calendar(const std::string& file_path) {
		input.open(file_path);
	}

	~Calendar() {
		input.close();
	}

	void reset() {
		input.clear();
		input.seekg(0, std::ios::beg);
	}

	void Day01_Part1();
	void Day01_Part2();

	void Day02_Part1();
	void Day02_Part2();

	void Day03_Part1();
	void Day03_Part2();

	void Day04_Part1();
	void Day04_Part2();

	void Day05_Part1();
	void Day05_Part2();

	void Day06_Part1();
	void Day06_Part2();

	void Day07_Part1();
	void Day07_Part2();

protected:
private:

	std::fstream input;
	std::string line, token;

	Timer timer;
};

#endif // !UTILS_H