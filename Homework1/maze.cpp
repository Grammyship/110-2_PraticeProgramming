#include <maze.h>


/*
*   Warning:
*       Always remember to call the freeMap at the end!
*/
void Maze::createMap()
{
    map__ = (char *) calloc( height__ * width__, sizeof(char) );
}

void Maze::setMap()
{
    int count = 0;
    for( int i = 0; i < height__; ++i )
    {
        for( int j = 0; j < width__+1; ++j )
        {
            char c = fgetc(stdin);
            if( c == '\n' );
            else
                map__[i*width__+j] = c;
        }
    }
}

void Maze::printMap() const
{
    for( int i = 0; i < height__; ++i )
    {
        for( int j = 0; j < width__; ++j )
        {
            printf("%c", map__[i*width__+j]);
        }
        puts("");
    }
}