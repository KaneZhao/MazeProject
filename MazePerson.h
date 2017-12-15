#ifndef MAZEPERSON_H
#define MAZEPERSON_H

#include<windows.h>
#include"MazeMap.h"

class MazePerson{
public:
	MazePerson();
	bool walkUp();
	bool walkDown();
	bool walkLeft();
	bool walkRight();
	void setPosition(int x, int y);
	void setHero(char hero);
	void setDirection(char direction);
	void moveForward(char direction);
	void setMap(MazeMap *map);
	void start();
	int getSteps();
private:
	char m_cHero;
	char m_cHeroLookAt;
	COORD m_heroCurrentPositon;
	MazeMap *m_pMap;
	int m_iSteps;
};
#endif