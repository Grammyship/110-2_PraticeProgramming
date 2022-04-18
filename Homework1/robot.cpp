#include <robot.h>


// move forward
void Robot::GoForward( const int steps )
{
    // North
    if( look__ == 0 )
    {
        posY__ -= steps;
    }
    // East
    else if( look__ == 1 )
    {
        posX__ += steps;
    }
    // South
    else if( look__ == 2 )
    {
        posY__ += steps;
    }
    // West
    else if( look__ == 3 )
    {
        posX__ -= steps;
    }
    else
    {
        printf("GoForward(): Looks at weird direction :(\n");
    }
}



// move backward
void Robot::GoBackward( const int steps )
{
    // North
    if( look__ == 0 )
    {
        posY__ += steps;
    }
    // East
    else if( look__ == 1 )
    {
        posX__ -= steps;
    }
    // South
    else if( look__ == 2 )
    {
        posY__ -= steps;
    }
    // West
    else if( look__ == 3 )
    {
        posX__ += steps;
    }
    else
    {
        printf("GoForward(): Looks at weird direction :(\n");
    }
}


// looking direction
void Robot::LookAt( const int direction )
{
    if ( direction == 0 )
        LookNorth();
    else if ( direction == 1 )
        LookEast();
    else if ( direction == 2 )
        LookSouth();
    else if ( direction == 3 )
        LookWest();
    else
        printf("Look(): invalid input :(\n");
}