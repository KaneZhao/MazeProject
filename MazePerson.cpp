#include"MazePerson.h"
#include<windows.h>

MazePerson::MazePerson()
{
	m_iSteps = 0;
}

void MazePerson::moveForward(char direction)
{
	unsigned long numWritten;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	FillConsoleOutputCharacter(handle, ' ', 1, m_heroCurrentPositon, &numWritten);
	switch (direction)
	{
	case 'U':
		m_heroCurrentPositon.Y -= 1;
		break;
	case 'R':
		m_heroCurrentPositon.X += 1;
		break;
	case 'D':
		m_heroCurrentPositon.Y += 1;
		break;
	case 'L':
		m_heroCurrentPositon.X -= 1;
		break;
	default:
		break;
	}
	FillConsoleOutputCharacter(handle, m_cHero, 1, m_heroCurrentPositon, &numWritten);
	m_cHeroLookAt = direction;
}

bool MazePerson::walkUp()
{
	if (m_pMap->getMap()[m_heroCurrentPositon.Y - 1][m_heroCurrentPositon.X])
		return false;
	else
	{
		moveForward('U');
		return true;
	}
}
bool MazePerson::walkDown()
{
	if (m_pMap->getMap()[m_heroCurrentPositon.Y + 1][m_heroCurrentPositon.X])
		return false;
	else
	{
		moveForward('D');
		return true;
	}
}
bool MazePerson::walkLeft()
{
	if (m_pMap->getMap()[m_heroCurrentPositon.Y][m_heroCurrentPositon.X - 1])
		return false;
	else
	{
		moveForward('L');
		return true;
	}
}
bool MazePerson::walkRight()
{
	if (m_pMap->getMap()[m_heroCurrentPositon.Y][m_heroCurrentPositon.X + 1])
		return false;
	else
	{
		moveForward('R');
		return true;
	}
}
void MazePerson::setDirection(char direction)
{
	m_cHeroLookAt = direction;
}
void MazePerson::setPosition(int x, int y)
{
	unsigned long numWritten;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	m_heroCurrentPositon.X = x;
	m_heroCurrentPositon.Y = y;
	FillConsoleOutputCharacter(handle, m_cHero, 1, m_heroCurrentPositon, &numWritten);
}

void MazePerson::setHero(char hero)
{
	m_cHero = hero;
}
void MazePerson::setMap(MazeMap *map)
{
	m_pMap = map;
}
int MazePerson::getSteps()
{
	return m_iSteps;
}
void MazePerson::start()
{
	while (true)
	{
		switch (m_cHeroLookAt)
		{
		case 'U':
			walkRight() || walkUp() || walkLeft() || walkDown();
			break;
		case 'D':
			walkLeft() || walkDown() || walkRight() || walkUp();
			break;
		case 'R':
			walkDown() || walkRight() || walkUp() || walkLeft();
			break;
		case 'L':
			walkUp() || walkLeft() || walkDown() || walkRight();
			break;
		default:
			break;
		}
		m_iSteps++;
		if (m_heroCurrentPositon.X == m_pMap->getExitPosition().X&&m_heroCurrentPositon.Y == m_pMap->getExitPosition().Y)
		{
			break;
		}
		Sleep(500);
	}
}