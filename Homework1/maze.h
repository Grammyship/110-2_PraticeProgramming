/*
 *  maze.h
 *
 *
 *  made by 40847041S朱自宇
 *      A basic header file for 2D maps (or mazes).
 *
*/

#ifndef MAZE_H
#define MAZE_H

#include <stdio.h>
#include <stdlib.h>


class Maze
{
public:
    /*
    *   To use the Maze:
    *       Step1: Set up height and width for your new maze.
    *               setHeight( int );
    *               setWidth( int );
    *
    *       Step2(Optional): Set up the road and wall (obstacle) for your maze.
    *               setRoad( char );
    *               setObstacle( char );  
    *
    *       Step3: Create space for your new maze by height and width you have set.
    *               createMap();
    *
    *       Step4: Enter how your map is like line by line.
    *               setMap();
    *               ex. You should enter sth. like:
    *                   #####
    *                   #.#.#
    *                   #...#
    *                   #####
    *                   When '#' are the walls, and '.' for roads.
    *
    *       Step5: Always remember to free after use :)
    *               freeMap();
    */


    //  Attributes
    void setHeight( int height ) { height__ = height; }         
    void setWidth( int width ) { width__ = width; }
    void setRoad( char road ) { road__ = road; }                    // Optional
    void setObstacle( char obstacle ) { obstacle__ = obstacle; }    // Optional


    // Maze
    void createMap();   // by height and width
    void setMap();      // notice that you must have a map first (call createMap())

    /***************************************************
    * after using, please remember to free the map !!! *
    ***************************************************/
    void freeMap() { free(map__); }



    /*
     *  Get information:
     *      
     * 
    */
    int getHeight() const { return height__; }
    int getWidth() const { return width__; }
    int getSize() const { return height__*width__; }
    char getRoad() const { return road__; }
    char getObstacle() const { return obstacle__; }
    const char *getMap() const { return map__; }
    void printMap() const;


    // checking
    bool isObstacle( int x, int y ) const { return ( map__[y*width__ + x] == obstacle__ ); }


private:
    // attributes
    int height__= 0;        // height of the maze
    int width__ = 0;        // width of the maze
    char road__ = '\0';     // character that represent roads
    char obstacle__ = '\0'; // character that represent obstacles

    // maze storage
    char *map__ = nullptr;  // pointer to the maze space
};



#endif