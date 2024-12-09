#ifndef DAY_04_HPP
#define DAY_04_HPP

#include "../include/calendar.h"

static inline int count_card(const char (&grid)[140][140], int row, int col) {
	int count = 0;

	// Check left
	if (col >= 3) {
		if (grid[row][col - 1] == 'M' &&
			grid[row][col - 2] == 'A' &&
			grid[row][col - 3] == 'S') {
			++count;
		}
	}

	// Check right
	if (col < 137) {
		if (grid[row][col + 1] == 'M' &&
			grid[row][col + 2] == 'A' &&
			grid[row][col + 3] == 'S') {
			++count;
		}
	}

	// Check up
	if (row >= 3) {
		if (grid[row - 1][col] == 'M' &&
			grid[row - 2][col] == 'A' &&
			grid[row - 3][col] == 'S') {
			++count;
		}
	}

	// check down
	if (row < 137) {
		if (grid[row + 1][col] == 'M' &&
			grid[row + 2][col] == 'A' &&
			grid[row + 3][col] == 'S') {
			++count;
		}
	}


	return count;
}

static inline int count_diag(const char (&grid)[140][140], int row, int col) {
	int count = 0;

	// Check Left Up

	if (col >= 3 && row >= 3) {
		if (grid[row - 1][col - 1] == 'M' &&
			grid[row - 2][col - 2] == 'A' &&
			grid[row - 3][col - 3] == 'S') {
			++count;
		}
	}


	// Check Left Down

	if (col >= 3 && row < 137) {
		if (grid[row + 1][col - 1] == 'M' &&
			grid[row + 2][col - 2] == 'A' &&
			grid[row + 3][col - 3] == 'S') {
			++count;
		}
	}



	// Check Right Up
	if (col < 137 && row >= 3) {
		if (grid[row - 1][col + 1] == 'M' &&
			grid[row - 2][col + 2] == 'A' &&
			grid[row - 3][col + 3] == 'S') {
			++count;
		}
	}


	// Check Right Down
	if (col < 137 && row < 137) {
		if (grid[row + 1][col + 1] == 'M' &&
			grid[row + 2][col + 2] == 'A' &&
			grid[row + 3][col + 3] == 'S') {
			++count;
		}
	}


	return count;
}

inline void Calendar::Day04_Part1() {
	const int DIM = 140;
	char grid[DIM][DIM];
	
	int row = 0;
	while (std::getline(input, line)) {
		std::stringstream ss(line);

		for (int col = 0; col < DIM; ++col) {
			grid[row][col] = line[col];
		}

		++row;
	}

	timer.start();

	// Solve
	int count = 0;
	for (int row = 0; row < DIM; ++row) {
		for (int col = 0; col < DIM; ++col) {
			if (grid[row][col] == 'X') {
				count += count_card(grid, row, col);
				count += count_diag(grid, row, col);
			}
		}
	}

	timer.end();
	auto dura = timer.duration();
	std::cout << "Day 04 P1: " << count << " found in " << dura.first << " " << dura.second << "(s)\n";
}

inline void Calendar::Day04_Part2() {
	const int DIM = 140;
	char grid[DIM][DIM];

	int row = 0;
	while (std::getline(input, line)) {
		std::stringstream ss(line);

		for (int col = 0; col < DIM; ++col) {
			grid[row][col] = line[col];
		}

		++row;
	}

	timer.start();

	int numM, numS;
	int count = 0;
	for (int row = 1; row < 139; ++row) {
		for (int col = 1; col < 139; ++col) {
			if (grid[row][col] == 'A') {
				numM = (grid[row - 1][col - 1] == 'M') + (grid[row - 1][col + 1] == 'M') + (grid[row + 1][col + 1] == 'M') + (grid[row + 1][col - 1] == 'M');
				numS = (grid[row - 1][col - 1] == 'S') + (grid[row - 1][col + 1] == 'S') + (grid[row + 1][col + 1] == 'S') + (grid[row + 1][col - 1] == 'S');

				// Pesky messy diagonals
				if (numM == numS && numM == 2 && grid[row - 1][col - 1] != grid[row + 1][col + 1]) {
					++count;
				}
			}
		}
	}

	timer.end();
	auto dura = timer.duration();
	std::cout << "Day 04 P2: " << count << " found in " << dura.first << " " << dura.second << "(s)\n";
}

#endif // !DAY_01_HPP