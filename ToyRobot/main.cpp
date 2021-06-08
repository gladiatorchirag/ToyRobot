#include <iostream>
#include <string>
#include <regex>
#include "Robot.h"

using namespace Toys;

void DisplayHelp();

int main()
{
    char prompt = ' ';
    std::cout << "Hello!" << std::endl;
    DisplayHelp();
    /*std::cout << "Press any key to start!" << std::endl;
    std::cin >> prompt;*/
    std::cout << "-----------------------------------------" << std::endl;
    std::regex rgxJustMatchPlaceCmd("^(PLACE)(\\s.*)*$", std::regex_constants::icase);
    std::regex rgxPlaceCmd("^(PLACE)\\s+([0-9])\\s*,\\s*([0-9])\\s*,\\s*(SOUTH|EAST|NORTH|WEST)\\s*$", std::regex_constants::icase);
    //std::regex rgxMoveCmd("^MOVE\\s*$", std::regex_constants::icase);// strictly just the MOVE command
    std::regex rgxMoveCmd("^(MOVE)(\\s.*)*$", std::regex_constants::icase);
    //std::regex rgxLeftCmd("^LEFT\\s*$", std::regex_constants::icase);// strictly just the LEFT command
    std::regex rgxLeftCmd("^(LEFT)(\\s.*)*$", std::regex_constants::icase);
    //std::regex rgxRightCmd("^RIGHT\\s*$", std::regex_constants::icase);// strictly just the RIGHT command
    std::regex rgxRightCmd("^(RIGHT)(\\s.*)*$", std::regex_constants::icase);
    //std::regex rgxReportCmd("^REPORT\\s*$", std::regex_constants::icase); // strictly just the REPORT command
    std::regex rgxReportCmd("^(REPORT)(\\s.*)*$", std::regex_constants::icase);
    std::regex rgxHelpCmd("^\\s*(h|help)\\s*$", std::regex_constants::icase);
    const uint32_t tableLength = 5, tableWidth = 5;
    Robot rob = Robot(tableLength, tableWidth);
    std::cout << "Enter command or just Hit Enter to Quit!" << std::endl; 
    while (true)
    {    
        std::string inputStr;
        std::cin.clear();
        std::getline(std::cin, inputStr);
        std::smatch sm;
        if (std::regex_search(inputStr, sm, rgxJustMatchPlaceCmd))
        {
            if (std::regex_search(inputStr, sm, rgxPlaceCmd))
            {
                // Place command
                int xCoord = std::stoi(sm[2]);
                int yCoord = std::stoi(sm[3]);
                std::string direction = sm[4];
                rob.PlaceRobot(xCoord, yCoord, direction);
            }
            else
                std::cout << "Malformed or incomplete PLACE command. Usage: PLACE 2,1,NORTH" << std::endl;
        }
        else if (std::regex_search(inputStr, sm, rgxMoveCmd))
            rob.MoveForward();
        else if (std::regex_search(inputStr, sm, rgxLeftCmd))
            rob.TurnLeft();
        else if (std::regex_search(inputStr, sm, rgxRightCmd))
            rob.TurnRight();
        else if (std::regex_search(inputStr, sm, rgxReportCmd))
            rob.Report();
        else if (std::regex_search(inputStr, sm, rgxHelpCmd))
            DisplayHelp();
        else if (inputStr == "")
            break;
        else
            std::cout << "Illegal or incomplete command. Please try again" << std::endl;
    }
}

void DisplayHelp()
{
    std::cout << "Valid Commands:" << std::endl
                << "PLACE X,Y,F            <Puts the Robot in position X,Y on the table while facing Direction F>" << std::endl
                << "                       Value of X and Y must be between 0 and 4" << std::endl
                << "                       Direction can be EAST, WEST, NORTH or SOUTH" << std::endl
                << "                       Example: PLACE 0,0,NORTH" << std::endl
                << "MOVE                   <Moves one step forward in the current direction>" << std::endl
                << "LEFT                   <Turn Left>" << std::endl
                << "RIGHT                  <Turn Right>" << std::endl
                << "h|help                 <Display this help text>" << std::endl;
}