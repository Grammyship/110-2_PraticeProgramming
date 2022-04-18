#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    // for customers
    char customer_item[101][101];
    int customer_award[101];

    char map[100];

    int num_all_customers;
    scanf("%d", &num_all_customers);
    for (int i = 0; i < num_all_customers; i++)
    {
        scanf("%s%d", customer_item[i], &customer_award[i]); fgetc(stdin);
    }
    for (int i = 0; i < 7; i++)
    {
        for( int j = 0; j < 12; j++ )
        {
            char c = fgetc(stdin);
            if( c == '\n')
                ;
            else
            {
                map[i*11+j] = c;
            }
        }
    }

    // game loop
    while (1) {
        // turns
        int turns_remaining;
        scanf("%d", &turns_remaining);

        // player
        int player_x;
        int player_y;
        char player_item[101];
        scanf("%d%d%s", &player_x, &player_y, player_item);

        // partner
        int partner_x;
        int partner_y;
        char partner_item[101];
        scanf("%d%d%s", &partner_x, &partner_y, partner_item);

        // the number of tables in the kitchen that currently hold an item
        int num_tables_with_items;
        scanf("%d", &num_tables_with_items);

        int tableX[101];
        int tableY[101];
        char *tableI[101];

        for (int i = 0; i < num_tables_with_items; i++) {
            int table_x;
            int table_y;
            char item[101];
            scanf("%d%d%s", &table_x, &table_y, item);
            tableX[i] = table_x;
            tableY[i] = table_y;
            tableI[i] = item;
        }
    /*
        // ignore until wood 1 league
        char oven_contents[101];
        int oven_timer;
        scanf("%s%d", oven_contents, &oven_timer);
    */
        // the number of customers currently waiting for food
        int num_customers;
        scanf("%d", &num_customers);
        for (int i = 0; i < num_customers; i++) {
            char customer_item[101];
            int customer_award;
            scanf("%s%d", customer_item, &customer_award);
        }

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");


        // MOVE x y
        // USE x y
        // WAIT
        printf("WAIT\n");
    }

    return 0;
}