#ifndef MAZEMAP_H
#define MAZEMAP_H

#include<windows.h>
#define WALL 1
#define ROAD 0

class MazeMap{
public:
	MazeMap(char wall);
	~MazeMap();
	void setWallChar(char wall);
	void setMap(int *map, int row, int col);
	void printMap();
	int** getMap();
	void setExitPosition(COORD coo);
	COORD getExitPosition();
private:
	char m_cWall;
	char m_cRoad;
	int **m_pMap;
	int m_iMapRow;
	int m_iMapCol;
	COORD m_ExitPosition;
};
#endif