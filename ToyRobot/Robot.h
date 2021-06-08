#pragma once

#include <iostream>
#include <optional>
#include <vector>
#include <map>

namespace Toys
{
	const int MAX_X = 5;
	const int MAX_Y = 5;
	const std::string DIR_EAST = "EAST";
	const std::string DIR_WEST = "WEST";
	const std::string DIR_NORTH = "NORTH";
	const std::string DIR_SOUTH = "SOUTH";
	const std::vector<std::string> Directions = 
	{
		DIR_EAST,
		DIR_WEST,
		DIR_NORTH,
		DIR_SOUTH
	};
	const std::map<std::string, std::string> LeftTurn = 
	{
		{DIR_EAST, DIR_NORTH},
		{DIR_NORTH, DIR_WEST},
		{DIR_WEST, DIR_SOUTH},
		{DIR_SOUTH, DIR_EAST}
	};
	const std::map<std::string, std::string> RightTurn =
	{
		{DIR_EAST,  DIR_SOUTH},
		{DIR_NORTH, DIR_EAST},
		{DIR_WEST,  DIR_NORTH},
		{DIR_SOUTH, DIR_WEST}
	};
	class Robot
	{
		std::optional<std::pair<int, int>> _pos;
		std::string _direction;
		uint32_t _tableLength;
		uint32_t _tableWidth;
	public:
		Robot(uint32_t tableLength = MAX_X, uint32_t tableWidth = MAX_Y);
		~Robot() {}
		bool PlaceRobot(int xCoord, int yCoord, std::string direction);
		bool TurnLeft();
		bool TurnRight();
		bool MoveForward();
		std::string Report();
		std::optional<std::pair<int, int>> GetPosition() const { return _pos; }
		uint32_t GetTableLength() const { return _tableLength; }
		uint32_t GetTableWidth() const { return _tableWidth; }
		std::string GetDirection() const { return _direction; }
	};
}