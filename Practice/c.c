#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct CStudent
{
    int id,
        score;
    char name[30];
} CStudent;

void scan(CStudent *s)
{
    scanf("%d %s %d", &s->id, s->name, &s->score);
}
void print(const CStudent *s)
{
    printf("%d %s %d\n", s->id, s->name, s->score);
}

int CompId(const void *l, const void *r)
{
    const CStudent *lhs = ( const CStudent *)l;
    const CStudent *rhs = ( const CStudent *)r;
    if( lhs->id > rhs->id ) return 1;
    else return 0;
}

int CompName(const void *l, const void *r)
{
    const CStudent *lhs = ( const CStudent *)l;
    const CStudent *rhs = ( const CStudent *)r;
    int mode = strcmp(lhs->name,rhs->name);
    if( mode > 0 )
        return 1;
    else return 0;
}



int main(void)
{
    CStudent students[] = {{1, 90, "David"}, {5, 100, "Allen"}, {3, 92, "Alice"}, {2, 85, "Bob"}, {4, 91, "Cyndi"}};
    const int n = sizeof(students)/sizeof(students[0]);

    qsort(students, n, sizeof(CStudent), CompId);
    for (int i=0; i<n; i+=1)
    {
        print(&students[i]);
    }
    puts("");

    qsort(students, n, sizeof(CStudent), CompName);
    for (int i=0; i<n; i+=1)
    {
        print(&students[i]);
    }
    return 0;
}

