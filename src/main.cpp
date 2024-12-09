#include "../calendar/day_01.h"
#include "../calendar/day_02.h"
#include "../calendar/day_03.h"
#include "../calendar/day_04.h"
#include "../calendar/day_05.h"


static const unsigned int DAY = 5;

int main() {

	Calendar calendar("./inputs/day_" + ((DAY < 10 ? "0" : "") + std::to_string(DAY)) + ".txt");


	switch (DAY) {
	case 1:
		calendar.Day01_Part1();
		calendar.reset();
		calendar.Day01_Part2();
		break;
	case 2:
		calendar.Day02_Part1();
		calendar.reset();
		calendar.Day02_Part2();
		break;
	case 3:
		calendar.Day03_Part1();
		calendar.reset();
		calendar.Day03_Part2();
		break;
	case 4:
		calendar.Day04_Part1();
		calendar.reset();
		calendar.Day04_Part2();
		break;
	case 5:
		calendar.Day05_Part1();
		calendar.reset();
		calendar.Day05_Part2();
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:
		break;
	case 11:
		break;
	case 12:
		break;
	case 13:
		break;
	case 14:
		break;
	case 15:
		break;
	case 16:
		break;
	case 17:
		break;
	case 18:
		break;
	case 19:
		break;
	case 20:
		break;
	case 21:
		break;
	case 22:
		break;
	case 23:
		break;
	case 24:
		break;
	case 25:
		break;
	}
	

}