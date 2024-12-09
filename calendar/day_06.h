#ifndef DAY_06_HPP
#define DAY_06_HPP

#include "../include/calendar.h"

static inline std::vector<std::pair<int, int>> guard_path(int X, int Y, int(&map)[130][130]) {
	int direction = 0;
	std::vector<std::pair<int, int>> path;
	/*
	0 == up
	1 == right
	2 == down
	3 == left
	*/
	bool done = false;
	while (!done) {
		// Mark as visited
		map[Y][X] = 2;
		path.push_back({ X, Y });

		switch (direction) {
			// Up
		case 0:
			if (Y == 0) { done = true; }
			--Y;

			if (Y > 0 && map[Y - 1][X] == 1) {
				direction = 1;
			}
			break;

			// Right
		case 1:
			if (X == 129) { done = true; }
			++X;

			if (X < 129 && map[Y][X + 1] == 1) {
				direction = 2;
			}
			break;

			// Down
		case 2:
			if (Y == 129) { done = true; }
			++Y;

			if (Y < 129 && map[Y + 1][X] == 1) {
				direction = 3;
			}
			break;

			// Left
		case 3:
			if (X == 0) { done = true; }
			--X;

			if (X > 0 && map[Y][X - 1] == 1) {
				direction = 0;
			}
			break;
		}
	}

	return path;
}

inline void Calendar::Day06_Part1() {
	// Input
	const int DIM = 130;
	int map[DIM][DIM];
	int X, Y;
	int row = 0;
	while (std::getline(input, line)) {
		for (int col = 0; col < DIM; ++col) {
			map[row][col] = (line[col] == '.' ? 0 : (line[col] == '#' ? 1 : 2));
			if (map[row][col] == 2) {
				X = col, Y = row;
			}
		}

		++row;
	}

	timer.start();

	std::vector<std::pair<int, int>> path = guard_path(X, Y, map);
	std::set<std::pair<int, int>> unique_positions;
	for (const auto& coord : path) {
		unique_positions.insert(coord);
	}
	int num_unique = unique_positions.size();

	timer.end();
	auto dura = timer.duration();
	std::cout << "Day 06 P1: " << num_unique << " found in " << dura.first << " " << dura.second << "(s)\n";
}

inline void Calendar::Day06_Part2() {
	
	timer.start();

	// Finish

	timer.end();
	auto dura = timer.duration();
	std::cout << "Day 06 P2: " << "ANS" << " found in " << dura.first << " " << dura.second << "(s)\n";
}

#endif // !DAY_01_HPP