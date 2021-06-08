#include "Robot.h"
#include <algorithm>
#include <string>

namespace Toys
{
	bool Robot::PlaceRobot(int xCoord, int yCoord, std::string direction)
	{
		std::transform(direction.begin(), direction.end(), direction.begin(), ::toupper);
		bool bRet = false;
		if (!(direction.empty() 
			|| (std::find(Directions.begin(), Directions.end(), direction) == Directions.end())
			|| (xCoord < 0)
			|| (xCoord > (_tableLength - 1))
			|| (yCoord < 0)
			|| (yCoord > (_tableWidth - 1))))
		{
			_pos = std::make_pair(xCoord, yCoord);
			_direction = direction;
			bRet = true;
		}
		return bRet;
	}
	bool Robot::TurnLeft()
	{
		bool bRet = false;
		if (_pos)
		{
			auto newDirectionIter = LeftTurn.find(_direction);
			if (newDirectionIter != LeftTurn.end())
			{
				_direction = newDirectionIter->second;
				bRet = true;
			}
		}
		return bRet;
	}
	bool Robot::TurnRight()
	{
		bool bRet = false;
		if (_pos)
		{
			auto newDirectionIter = RightTurn.find(_direction);
			if (newDirectionIter != RightTurn.end())
			{
				_direction = newDirectionIter->second;
				bRet = true;
			}
		}
		return bRet;
	}
	bool Robot::MoveForward()
	{
		bool bRet = false;
		if (_pos)
		{
			std::pair<int, int>& coords = *_pos;
			if (_direction == DIR_EAST)
			{
				if (coords.first < (_tableLength - 1))
				{
					coords.first++;
					bRet = true;
				}
			}
			else if (_direction == DIR_WEST)
			{
				if (coords.first > 0)
				{
					coords.first--;
					bRet = true;
				}
			}
			else if (_direction == DIR_NORTH)
			{
				if (coords.second < (_tableWidth - 1))
				{
					coords.second++;
					bRet = true;
				}
			}
			else
			{
				if (coords.second > 0)
				{
					coords.second--;
					bRet = true;
				}
			}
		}
		return bRet;
	}

	std::string Robot::Report()
	{
		std::string retStr = "";
		if (_pos)
		{
			retStr = std::to_string((*_pos).first) + "," + std::to_string((*_pos).second) + "," + _direction;
			std::cout << retStr << std::endl;
		}
		return retStr;
	}
	Robot::Robot(uint32_t tableLength, uint32_t tableWidth)
	{
		_tableLength = tableLength;
		_tableWidth = tableWidth;
		_direction = "";
	}
}