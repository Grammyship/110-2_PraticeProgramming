#include <iostream>
#include <string.h>
#include <iterator>
using namespace std;

struct CStudent
{
   int id = 0,
       score = 0;
   char name[30] = {};
};


ostream & operator << (ostream &os, const CStudent &stu)
{
    os << stu.id << ' ' << stu.name << ' ' << stu.score;
    return os;
}

void sort(CStudent data[], int n, int(*func)(const CStudent &, const CStudent & ))
{
    for( int i = 0; i < n-1; ++i )
    {
        for( int j = i+1; j < n; ++j )
        {
            if( func(data[i], data[j]) )
            {
                swap(data[i], data[j]);
            }
        }
    }
}


int CompareId(const CStudent &lhs, const CStudent &rhs)
{
    if( lhs.id > rhs.id ) return 1;
    else return 0;
}
int CompareName(const CStudent &lhs, const CStudent &rhs)
{
    int l_size = std::size(lhs.name);
    int r_size = std::size(rhs.name);
    int count = min(l_size, r_size);

    for( int i = 0; i < count; ++i )
    {
        if( lhs.name[i] > rhs.name[i] )
            return 1;
        else if( lhs.name[i] > rhs.name[i] )
        {}
        else
            return 0;
    }
    if( l_size > r_size )
        return 1;
    return 0;
}

int CompareScore(const CStudent &lhs, const CStudent &rhs)
{
    if( lhs.score > rhs.score ) return 1;
    else return 0;
}



int main()
{
    CStudent data[] = {{1, 90, "David"}, {5, 100, "Allen"}, {3, 92, "Alice"}, {2, 85, "Bob"}, {4, 91, "Cyndi"}};

    sort(data, size(data), CompareId);
    for (const auto &e: data) {cout << e << endl;} cout << endl;
    sort(data, size(data), CompareName);
    for (const auto &e: data) {cout << e << endl;} cout << endl;
    sort(data, size(data), CompareScore);
    for (const auto &e: data) {cout << e << endl;} cout << endl;
}






