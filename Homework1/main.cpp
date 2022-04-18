#include <stdio.h>
#include <stdlib.h>
#include <maze.h>
#include <robot.h>

using ull = unsigned long long;

int main()
{
    // input
    int h = 0, w = 0;   // height, width
    ull step = 0;
    scanf("%d %d", &w, &h );
    scanf("%llu", &step );
    getc(stdin);        // get '\n' out


    // new map
    Maze NTNU;
    // set up map
    NTNU.setHeight( h );
    NTNU.setWidth( w );
    NTNU.setRoad( '.' );
    NTNU.setObstacle( '#' );
    NTNU.createMap();
    NTNU.setMap();
    

    // use the map, remember to free it (O)
    const char *m = NTNU.getMap();


    // new robot
    Robot Tcc;

    // since the robot's starting position is 'O', we have to make it to a road '.'
    char map[h][w];
    for( int i = 0; i < h; ++i )
    {
        for( int j = 0; j < w; ++j )
        {
            if( m[i*w+j] == 'O' )
            {
                map[i][j] = '.';
                Tcc.setposX( j );
                Tcc.setposY( i );
                Tcc.setLook( 0 );
            }
            else
                map[i][j] = m[i*w+j];
        }
    }




    // record the path
    int moveX[200];
    int moveY[200];
    int lookAt[200];
    for( int i = 0; i < 200; ++i )   // initialize
    {
        moveX[i] = 0;
        moveY[i] = 0;
        lookAt[i] = 0;
    }

    // maybe we don't start a circuit first...
    ull preliminary = 0;
    ull circuit = 0;
    int mode = 1;   // check 


    /*
    *   find circuit
    */
    while(mode)
    {
        // move for 1 step
        Tcc.GoForward(1);

        const int x = Tcc.getposX();
        const int y = Tcc.getposY();
    

        // check obstacle for 3 times( turn a round )
        for( int i = 0; i < 3; ++i )
        {
            if( Tcc.getlook() == 0 )
            {
                if( NTNU.isObstacle( x, y-1 ) )
                {
                    Tcc.TurnRight();
                }
            }
            else if( Tcc.getlook() == 1 )
            {
                if( NTNU.isObstacle( x+1, y ) )
                {
                    Tcc.TurnRight();
                }
            }
            else if( Tcc.getlook() == 2 )
            {
                if( NTNU.isObstacle( x , y+1 ) )
                {
                    Tcc.TurnRight();
                }
            }
            else if( Tcc.getlook() == 3 )
            {
                if( NTNU.isObstacle( x-1, y ) )
                {
                    Tcc.TurnRight();
                }
            }
            else
            {
                printf("Tcc looks at weird position :(\n");
            }
        }   // end "check obstacle"


        // circuit check
        for( ull i = 0; i < circuit; ++i )
        {
            if( ( x==moveX[i]) && (y==moveY[i]) && ( Tcc.getlook()==lookAt[i] ) )
            {
                circuit = circuit - i;
                preliminary = i;
                mode = 0;
            }
        }

    
        // check while
        if( mode == 0 ) // got the answer :)
        {
            break;
        }
        else    // keep going :(
        {
            // record this step
            const int look = Tcc.getlook();
            lookAt[circuit] = look;
            moveX[circuit] = x;
            moveY[circuit] = y;

            circuit += 1;
        }

    }   // end "find circuit"



    ull result;
    if( step == circuit )   // no circuit :(
    {
        result = step;  // so our output is the final step
    }
    else
    {
        // final position = CountInCircuitSteps + NonCircuitStep
        result = ((step-preliminary-1)%circuit) + preliminary;
    }
    printf("%d %d\n", moveX[result], moveY[result] );


    /**************************
    * Always remember to free *
    **************************/
    NTNU.freeMap();

    return 0;
}