# ToyRobot
ToyRobot is a console application. It is a simulation of a toy robot moving on a square table top of dimensions 5 units x 5 units. The robot is free to roam around the table but does not fall. 
The application can read commands of the following form:
* PLACE X,Y,F
* MOVE
* LEFT
* RIGHT
* REPORT

## Building the code
Please use Visual Studio 2019 to build and run the application.

## Unit tests
Unit tests are written using Microsoft Unit testing framework.

## Commands reference 
* PLACE command puts the robot in position X,Y and facing NORTH,EAST,SOUTH or WEST. the origin (0,0) is considered as the south west corner.
  * Usage: PLACE 0,3,NORTH
  * Arguments to PLACE command must strictly be X,Y,F
  * Any other command must be preceeded by a successful PLACE command, otherwise it is ignored.
* MOVE command moves the robot one unit forward in the direction that it is facing.
  * Any argument to MOVE command is ignored.
* LEFT command turns the robot 90 degrees left without changing its position.
  * Any argument to LEFT command is ignored.
* RIGHT command turns the robot 90 degrees right without changing its position.
  * Any argument to RIGHT command is ignored.
* REPORT command will output the X,Y and F of the robot on the commandline.
* HELP command is added to display help text at run time.

