#include <iostream>
#include <iterator>
using namespace std;

// TODO: function template print()
template <typename T>
void print( const T *head, const T *tail )
{
    for( auto i = head; i != tail; ++i )
        cout << *i << " ";
}

// TODO: function template min_element()
template <typename T>
T* min_element( T *head, T *tail )
{
    T *min = head;
    for( auto i = head; i != tail; ++i )
    {
        if( *i < *min )
            min = i;
    }
    return min;
}

int main ()
{
    int i[3] = {3, 1, 2};
    double d[5] = {5.4, 3.2, 1.2, 4.5, 5.6};
    char c[4] = {'S', 'I', 'E', 'C'};

    print(i, i+std::size(i)); cout << endl;
    print(d, d+std::size(d)); cout << endl;
    print(c, c+std::size(c)); cout << endl;

//    print(i, 3); // error!

    cout << *min_element(i, i+std::size(i)) << endl;
    cout << *min_element(d, d+std::size(d)) << endl;
    cout << *min_element(c, c+std::size(c)) << endl;
}
