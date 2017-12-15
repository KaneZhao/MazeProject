#include"MazeMap.h"
#include<iostream>
using namespace std;

MazeMap::MazeMap(char wall) :m_cWall(wall)
{
	m_cRoad = ' ';
	m_pMap = NULL;
}

MazeMap::~MazeMap()
{
	if (m_pMap)
	{
		for (int i = 0; i < m_iMapRow; ++i)
		{
			delete[] m_pMap[i];
			m_pMap[i] = NULL;
		}
		delete[] m_pMap;
		cout << "~MazeMap()" << endl;
	}
}

void MazeMap::setMap(int *map, int row, int col)
{
	m_iMapRow = row;
	m_iMapCol = col;
	m_pMap = new int*[m_iMapRow];
	for (int i = 0; i < m_iMapRow; ++i)
	{
		m_pMap[i] = new int[m_iMapCol];
	}
	int *p = map;
	for (int i = 0; i < m_iMapRow; ++i)
	{
		for (int j = 0; j < m_iMapCol; ++j)
		{
			m_pMap[i][j] = *p;
			p++;
		}
	}
}

void MazeMap::setWallChar(char wall)
{
	m_cWall = wall;
}

void MazeMap::printMap()
{
	for (int i = 0; i < m_iMapRow; ++i)
	{
		for (int j = 0; j < m_iMapCol; ++j)
		{
			if (m_pMap[i][j])
				cout << m_cWall;
			else
				cout << m_cRoad;
		}
		cout << endl;
	}
}

int** MazeMap::getMap()
{
	return m_pMap;
}

void MazeMap::setExitPosition(COORD coo)
{
	m_ExitPosition = coo;
}

COORD MazeMap::getExitPosition()
{
	return m_ExitPosition;
}