/*
*   robot.h
*  
*   made by 40847041S 朱自宇
*       A very easy header design for robots who lives in a
*   2-dimensional world that can do some easy commands.
*
*   The robot can:
*   1. moves around by 4 directions (since it lives in a 2D world.)
*   2. Look at 4 directions: [ 0:North, 1:East, 2:South, 3:West ]
*/

#ifndef ROBOT_H
#define ROBOT_H

#include <stdio.h>

class Robot
{
public:
    // basic settings about the robot
    void setposX( int x ) { posX__ = x; }
    void setposY( int y ) { posY__ = y; }
    void setLook( int f ) { look__ = f; }


    // get robot status
    int getposX() const { return posX__; }  // get the X-coordinate of the robot
    int getposY() const { return posY__; }  // get the Y-coordinate of the robot
    int getlook() const { return look__; }  // get the direction where the robot is facing [ 0:North, 1:East, 2:South, 3:West ]


    /* manipulating the robot */


    // human-like moving (consider facing direction)
    void GoForward( const int steps );
    void GoBackward( const int steps );
    void TurnRight() { look__ = (look__+1) % 4; }
    void TurnLeft() { look__ = (look__+3) % 4; }
    void TurnBack() { look__ = (look__+2) % 4; }

    // moving by coordinate, ignores facing direction
    void GoEast( int steps ) { posX__ += steps; }
    void GoWest( int steps ) { posX__ -= steps; }
    void GoNorth( int steps ) { posY__ += steps; }
    void GoSouth( int steps ) { posY__ -= steps; }

    // looking
    void LookAt( int direction ); // change looking direction of the robot [ 0:North, 1:East, 2:South, 3:West ] 

private:
    // coordinate
    int posX__ = 0;       // x position of the robot
    int posY__ = 0;       // y position of the robot

    // the robot looks at one direction
    int look__ = 0;   // [ 0:North, 1:East, 2:South, 3:West ]
    // switch direction
    void LookNorth() { look__ = 0; }  // look North (up)
    void LookEast() { look__ = 1; }   // look East (right)
    void LookSouth() { look__ = 2; }  // look South (down)
    void LookWest() { look__ = 3; }   // look West (left)

};

#endif