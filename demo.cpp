#include"MazeMap.h"
#include"stdlib.h"
#include<windows.h>
#include<iostream>
#include<string>
#include"MazePerson.h"
using namespace std;

int main()
{
	int map[11][11] = {
		{ WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL },
		{ WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD },
		{ WALL, ROAD, WALL, WALL, WALL, ROAD, WALL, WALL, WALL, ROAD, WALL },
		{ WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, WALL },
		{ WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, WALL, WALL },
		{ WALL, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, WALL },
		{ WALL, ROAD, WALL, WALL, WALL, WALL, WALL, WALL, WALL, ROAD, WALL },
		{ WALL, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, WALL },
		{ WALL, WALL, WALL, ROAD, WALL, WALL, WALL, ROAD, WALL, ROAD, WALL },
		{ ROAD, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, WALL },
		{ WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL }
	};
	MazeMap *mm = new MazeMap('H');
	COORD exitPosition;
	exitPosition.X = 0;
	exitPosition.Y = 9;
	mm->setMap(&map[0][0], 11, 11);
	mm->setExitPosition(exitPosition);
	mm->printMap();

	string emptySpace(5, '\n');
	cout << emptySpace;

	MazePerson *mper = new MazePerson();
	mper->setHero('o');
	mper->setPosition(10, 1);
	mper->setDirection('D');
	mper->setMap(mm);
	mper->start();

	cout << "共走了" << mper->getSteps() << "步" << endl;

	delete mper;
	mper = NULL;

	system("pause");
}