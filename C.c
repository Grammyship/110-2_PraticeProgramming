#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n = 11;
    char buffer[10];
    int upper = 10, lower = 1;
    int status = 0;
    while(1)
    {
        scanf("%d\n", &n );
        if(n == 0)
            return 0;
        else if( n != 0 )
        {
            if( fgets(buffer, sizeof(buffer) , stdin ) != NULL )
            {
                if( buffer[strlen(buffer)-1] == '\n')
                    buffer[strlen(buffer)-1] == '\0';

                if( buffer[4] == 'h' )
                    status = 1;
                else if( buffer[4] == 'l' )
                    status = 2;
                else if(buffer[4] == 't' )
                    status = 3;
            }

            if( status == 1 )
                upper = n;
            else if( status == 2 )
                lower = n;
            else if( status == 3 )
            {
                if( n >= upper || n <= lower )
                    printf("Stan is dishonest\n");
                else
                    printf("Stan may be honest\n");

                upper = 10;
                lower = 1;
            }
        }
    
    }
    return 1;
}