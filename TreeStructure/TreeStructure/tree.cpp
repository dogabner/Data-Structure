#include <iostream>
using namespace std;


struct havetry {
    struct month{
        int m;
    }
    string title;
    int *year;
} mine, yours;
int main()
{
    int b = 10;
    mine.year = &b;
    mine
    
    cout << mine.year;
    cout << *mine.year;
    return 0;
}
