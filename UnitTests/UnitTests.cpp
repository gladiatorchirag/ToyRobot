#include "pch.h"
#include "CppUnitTest.h"
#include <CppUnitTestAssert.h>
#include <iostream>
#include "../ToyRobot/Robot.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Toys;

namespace UnitTests
{
	TEST_CLASS(ToyRobotTest)
	{
	public:
		ToyRobotTest()
		{
			std::cout << "ToyRobotTest CTOR";
		}
		~ToyRobotTest()
		{
			std::cout << "ToyRobotTest DTOR";
		}
		TEST_METHOD(TestPlaceRobotNegativeCoords)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(-1, -1, "NORTH"), false);
		}
		TEST_METHOD(TestPlaceRobotNegativeXCoord)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(-1, 0, "NORTH"), false);
		}
		TEST_METHOD(TestPlaceRobotNegativeYCoord)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(1, -4, "NORTH"), false);
		}
		TEST_METHOD(TestPlaceRobotWrongDirection)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(0,0,"SOUTHE"), false);
		}
		TEST_METHOD(TestPlaceRobotNoDirection)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(0, 0, ""), false);
		}
		TEST_METHOD(TestPlaceRobotWrongXCoord)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(6, 4, "WEST"), false);
		}
		TEST_METHOD(TestPlaceRobotWrongYCoord)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(3, 5, "WEST"), false);
		}
		TEST_METHOD(TestPlaceRobotDirectionLowercase)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(3, 3, "south"), true);
			Assert::AreEqual(rob.GetDirection().c_str(), "SOUTH");
		}
		TEST_METHOD(TestPlaceRobotDirectionMixedcase)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(1, 2, "eAsT"), true);
			Assert::AreEqual(rob.GetDirection().c_str(), "EAST");
		}
		TEST_METHOD(TestPlaceRobotWrongCoords)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(100, 50000, "WEST"), false);
		}
		TEST_METHOD(TestPlaceRobotAllEast)
		{
			Robot rob;
			for (int xCoord = 0; xCoord < rob.GetTableLength(); xCoord++)
				for (int yCoord = 0; yCoord < rob.GetTableWidth(); yCoord++)
					Assert::AreEqual(rob.PlaceRobot(xCoord, yCoord, "EAST"), true);
		}
		TEST_METHOD(TestPlaceRobotAllWest)
		{
			Robot rob;
			for (int xCoord = 0; xCoord < rob.GetTableLength(); xCoord++)
				for (int yCoord = 0; yCoord < rob.GetTableWidth(); yCoord++)
					Assert::AreEqual(rob.PlaceRobot(xCoord, yCoord, "WEST"), true);
		}
		TEST_METHOD(TestPlaceRobotAllNorth)
		{
			Robot rob;
			for (int xCoord = 0; xCoord < rob.GetTableLength(); xCoord++)
				for (int yCoord = 0; yCoord < rob.GetTableWidth(); yCoord++)
					Assert::AreEqual(rob.PlaceRobot(xCoord, yCoord, "NORTH"), true);
		}
		TEST_METHOD(TestPlaceRobotAllSouth)
		{
			Robot rob;
			for (int xCoord = 0; xCoord < rob.GetTableLength(); xCoord++)
				for (int yCoord = 0; yCoord < rob.GetTableWidth(); yCoord++)
					Assert::AreEqual(rob.PlaceRobot(xCoord, yCoord, "SOUTH"), true);
		}
		TEST_METHOD(TestTurnLeftIgnore)
		{
			Robot rob;
			Assert::AreEqual(rob.TurnLeft(), false);
		}

		TEST_METHOD(TestTurnLeftPreFail)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(1, 0, "SOMEDIRECTION"), false);
			Assert::AreEqual(rob.TurnLeft(), false);
		}
		
		TEST_METHOD(TestTurnLeftWhenFacingEast)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(1, 0, "EAST"), true);
			Assert::AreEqual(rob.TurnLeft(), true);
			Assert::AreEqual(rob.GetDirection().c_str(), "NORTH");
		}

		TEST_METHOD(TestTurnLeftWhenFacingNorth)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(4, 0, "NORTH"), true);
			Assert::AreEqual(rob.TurnLeft(), true);
			Assert::AreEqual(rob.GetDirection().c_str(), "WEST");
		}
		
		TEST_METHOD(TestTurnLeftWhenFacingWest)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(1, 1, "WEST"), true);
			Assert::AreEqual(rob.TurnLeft(), true);
			Assert::AreEqual(rob.GetDirection().c_str(), "SOUTH");
		}

		TEST_METHOD(TestTurnLeftWhenFacingSouth)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(0, 0, "SOUTH"), true);
			Assert::AreEqual(rob.TurnLeft(), true);
			Assert::AreEqual(rob.GetDirection().c_str(), "EAST");
		}
		TEST_METHOD(TestRightPreFail)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(5, 0, "EAST"), false);
			Assert::AreEqual(rob.TurnRight(), false);
		}
		TEST_METHOD(TestRightWhenFacingEast)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(0, 0, "EAST"), true);
			Assert::AreEqual(rob.TurnRight(), true);
			Assert::AreEqual(rob.GetDirection().c_str(), "SOUTH");
		}
		TEST_METHOD(TestRightWhenFacingSouth)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(3, 1, "SOUTH"), true);
			Assert::AreEqual(rob.TurnRight(), true);
			Assert::AreEqual(rob.GetDirection().c_str(), "WEST");
		}
		TEST_METHOD(TestRightWhenFacingWest)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(1, 1, "WEST"), true);
			Assert::AreEqual(rob.TurnRight(), true);
			Assert::AreEqual(rob.GetDirection().c_str(), "NORTH");
		}
		TEST_METHOD(TestRightWhenFacingNorth)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(1, 1, "NORTH"), true);
			Assert::AreEqual(rob.TurnRight(), true);
			Assert::AreEqual(rob.GetDirection().c_str(), "EAST");
		}

		TEST_METHOD(TestMovePreFail)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(5, 0, "EAST"), false);
			Assert::AreEqual(rob.MoveForward(), false);
		}
		TEST_METHOD(TestMoveSouthFail)
		{
			// Dont fall off the southern edge
			Robot rob = Robot(10, 10);
			for (int i = 0; i < rob.GetTableLength(); i++)
			{
				Assert::AreEqual(rob.PlaceRobot(i, 0, "SOUTH"), true);
				Assert::AreEqual(rob.MoveForward(), false);
			}
		}
		TEST_METHOD(TestMoveEastFail)
		{
			// Dont fall off the eastern edge
			Robot rob = Robot(40, 40);
			for (int i = 0; i < rob.GetTableWidth(); i++)
			{
				Assert::AreEqual(rob.PlaceRobot(rob.GetTableLength() - 1, i, "EAST"), true);
				Assert::AreEqual(rob.MoveForward(), false);
			}
		}
		TEST_METHOD(TestMoveNorthFail)
		{
			// Dont fall off the northern edge
			Robot rob = Robot(50, 30);
			for (int i = 0; i < rob.GetTableLength(); i++)
			{
				Assert::AreEqual(rob.PlaceRobot(i, rob.GetTableWidth() - 1, "NORTH"), true);
				Assert::AreEqual(rob.MoveForward(), false);
			}
		}
		TEST_METHOD(TestMoveWestFail)
		{
			// Dont fall off the western edge
			Robot rob = Robot(20,30);
			for (int i = 0; i < rob.GetTableWidth(); i++)
			{
				Assert::AreEqual(rob.PlaceRobot(0, i, "WEST"), true);
				Assert::AreEqual(rob.MoveForward(), false);
			}
		}
		TEST_METHOD(TestMoveNorthPass)
		{
			Robot rob = Robot(20, 20);
			for (int xCoord = 0; xCoord < rob.GetTableLength(); xCoord++)
			{
				for (int yCoord = 0; yCoord < rob.GetTableWidth() - 1; yCoord++)
				{
					Assert::AreEqual(rob.PlaceRobot(xCoord, yCoord, "NORTH"), true);
					Assert::AreEqual(rob.MoveForward(), true);
					Assert::AreEqual(rob.GetPosition().value().second, yCoord + 1);
				}
			}
		}
		TEST_METHOD(TestMoveEastPass)
		{
			Robot rob = Robot(10, 10);
			for (int xCoord = 0; xCoord < rob.GetTableLength() - 1; xCoord++)
			{
				for (int yCoord = 0; yCoord < rob.GetTableWidth(); yCoord++)
				{
					Assert::AreEqual(rob.PlaceRobot(xCoord, yCoord, "EAST"), true);
					Assert::AreEqual(rob.MoveForward(), true);
					Assert::AreEqual(rob.GetPosition().value().first, xCoord + 1);
				}
			}
		}
		TEST_METHOD(TestMoveWestPass)
		{
			Robot rob = Robot(200, 300);
			for (int xCoord = 1; xCoord < rob.GetTableLength(); xCoord++)
			{
				for (int yCoord = 0; yCoord < rob.GetTableWidth(); yCoord++)
				{
					Assert::AreEqual(rob.PlaceRobot(xCoord, yCoord, "WEST"), true);
					Assert::AreEqual(rob.MoveForward(), true);
					Assert::AreEqual(rob.GetPosition().value().first, xCoord - 1);
				}
			}
		}
		TEST_METHOD(TestMoveSouthPass)
		{
			Robot rob = Robot(15, 15);
			for (int xCoord = 0; xCoord < rob.GetTableLength(); xCoord++)
			{
				for (int yCoord = 1; yCoord < rob.GetTableWidth(); yCoord++)
				{
					Assert::AreEqual(rob.PlaceRobot(xCoord, yCoord, "SOUTH"), true);
					Assert::AreEqual(rob.MoveForward(), true);
					Assert::AreEqual(rob.GetPosition().value().second, yCoord - 1);
				}
			}
		}
		TEST_METHOD(TestReportPlaceFail)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(100, 4, "NORTH"), false);
			Assert::AreEqual(rob.Report().c_str(), "");
		}
		TEST_METHOD(TestReportPlacePass)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(0, 3, "EAST"), true);
			Assert::AreEqual(rob.Report().c_str(), "0,3,EAST");
		}
		TEST_METHOD(TestReportMoveFail)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(0, 4, "NORTH"), true);
			Assert::AreEqual(rob.MoveForward(), false);
			Assert::AreEqual(rob.Report().c_str(), "0,4,NORTH");
			Assert::AreNotEqual(rob.Report().c_str(), "0,5,NORTH");
		}
		TEST_METHOD(TestReportMovePass)
		{
			Robot rob; 
			Assert::AreEqual(rob.PlaceRobot(1, 3, "SOUTH"), true);
			Assert::AreEqual(rob.MoveForward(), true);
			Assert::AreEqual(rob.Report().c_str(), "1,2,SOUTH");
		}
		TEST_METHOD(TestReportTurnLeftFail)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(0, 40, "EAST"), false);
			Assert::AreEqual(rob.TurnLeft(), false);
			Assert::AreEqual(rob.Report().c_str(), "");
		}
		TEST_METHOD(TestReportTurnLeftPass)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(1, 3, "SOUTH"), true);
			Assert::AreEqual(rob.TurnLeft(), true);
			Assert::AreEqual(rob.Report().c_str(), "1,3,EAST");
		}
		TEST_METHOD(TestReportTurnRightFail)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(10, 4, "NORTH"), false);
			Assert::AreEqual(rob.TurnRight(), false);
			Assert::AreEqual(rob.Report().c_str(), "");
		}
		TEST_METHOD(TestReportTurnRightPass)
		{
			Robot rob;
			Assert::AreEqual(rob.PlaceRobot(0, 0, "EAST"), true);
			Assert::AreEqual(rob.TurnRight(), true);
			Assert::AreEqual(rob.Report().c_str(), "0,0,SOUTH");
		}
		TEST_METHOD(TestScenario1)
		{
			Robot rob;
			rob.PlaceRobot(0, 0, "NORTH");
			rob.MoveForward();
			Assert::AreEqual(rob.Report().c_str(), "0,1,NORTH");
		}
		TEST_METHOD(TestScenario2)
		{
			Robot rob;
			rob.PlaceRobot(0, 0, "NORTH");
			rob.TurnLeft();
			Assert::AreEqual(rob.Report().c_str(), "0,0,WEST");
		}
		TEST_METHOD(TestScenario3)
		{
			Robot rob;
			rob.PlaceRobot(03, 01, "SOUTH");
			rob.TurnLeft();
			Assert::AreEqual(rob.Report().c_str(), "3,1,EAST");
		}
		TEST_METHOD(TestScenario4)
		{
			Robot rob;
			rob.PlaceRobot(1, 2, "EAST");
			rob.MoveForward();
			rob.MoveForward();
			rob.TurnLeft();
			rob.MoveForward();
			Assert::AreEqual(rob.Report().c_str(), "3,3,NORTH");
		}
		TEST_METHOD(TestScenario5)
		{
			Robot rob;
			rob.PlaceRobot(3, 2, "EAST");
			rob.MoveForward();
			rob.MoveForward();
			rob.MoveForward();
			rob.TurnLeft();
			rob.MoveForward();
			Assert::AreEqual(rob.Report().c_str(), "4,3,NORTH");
		}
		TEST_METHOD(TestScenario6)
		{
			Robot rob;
			rob.PlaceRobot(4, 2, "SOUTH");
			rob.MoveForward();
			rob.MoveForward();
			rob.MoveForward();
			rob.TurnLeft();
			rob.MoveForward();
			Assert::AreEqual(rob.Report().c_str(), "4,0,EAST");
		}
		TEST_METHOD(TestScenario7)
		{
			Robot rob;
			rob.PlaceRobot(3, 3, "NORTH");
			rob.MoveForward();
			rob.MoveForward();
			rob.TurnLeft();
			rob.MoveForward();
			rob.MoveForward();
			rob.MoveForward();
			rob.MoveForward();
			rob.MoveForward();
			rob.MoveForward();
			rob.TurnRight();
			Assert::AreEqual(rob.Report().c_str(), "0,4,NORTH");
			rob.TurnRight();
			Assert::AreEqual(rob.Report().c_str(), "0,4,EAST");
			rob.TurnRight();
			rob.MoveForward();
			Assert::AreEqual(rob.Report().c_str(), "0,3,SOUTH");
		}
		TEST_METHOD(TestScenario8)
		{
			Robot rob;
			rob.PlaceRobot(30, -3, "NORTH");
			rob.MoveForward();
			rob.MoveForward();
			rob.TurnLeft();
			rob.MoveForward();
			rob.MoveForward();
			rob.MoveForward();
			rob.MoveForward();
			rob.MoveForward();
			rob.MoveForward();
			rob.TurnRight();
			Assert::AreEqual(rob.Report().c_str(), "");
			rob.TurnRight();
			Assert::AreEqual(rob.Report().c_str(), "");
			rob.TurnRight();
			rob.MoveForward();
			Assert::AreEqual(rob.Report().c_str(), "");
		}
	};
}
