#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count = 0;
    scanf("%d", &count );
    
    int *dynArr, *dynArr2;
    dynArr = (int *)malloc( count * sizeof(int) );
    if( dynArr == NULL )
    {
        fprintf(stderr, "Error: dynArr\n");
        return 1;
    }
    dynArr2 = (int *)malloc( count * sizeof(int) );
    if( dynArr2 == NULL )
    {
        fprintf(stderr, "Error: dynArr\n");
        return 1;
    }

    for( int i = 0; i < count; i++ )
    {
        dynArr[i] = 0;
        dynArr2[i] = 0;
    }


    for( int i = 0; i < count; i++ )
    {
        scanf("%d", &dynArr[i] );
    }


    for( int i = 0; i < count; i++ )
    {
        int k = dynArr[i];
        int digit = 0;
        while( k != 0 )
        {
            k = k/10.0;
            ++digit;
        }

        for( int j = (dynArr[i]-9*digit); j < dynArr[i]; j++ )
        {
            int temp = j;
            k = j;
            while( k != 0 )
            {
                temp += k % 10;
                k /= 10;
            }
            if( temp == dynArr[i] )
            {
                dynArr2[i] = j;
                break;
            }
        }
    }

    for( int i = 0; i < count; i++ )
        printf("%d\n", dynArr2[i]);

    free(dynArr);
    free(dynArr2);

    return 0;
}