#include <stdio.h>

int main()
{
    int count[50];
    int n=0;
    scanf("%d", &n );
    for( int i = 0; i < n; ++i )
    {
        int l = 0;
        scanf("%d", &l );
        int arr[50];
        for( int j =0; j <l; ++j )
        {
            scanf("%d", &arr[j] );
        }
        count[i] = 0;
        for( int j = 0; j < l; ++j )
        {
            for( int h = j+1; h < l; ++h )
            {
                if( arr[j] > arr[h] )
                {
                    int temp = arr[j];
                    arr[j] = arr[h];
                    arr[h] = temp;
                    count[i] += 1;
                }
            }
        }
    }

    for( int i = 0; i < n; ++i )
    {
        printf("Optimal train swapping takes %d swaps.\n", count[i] );
    }
}