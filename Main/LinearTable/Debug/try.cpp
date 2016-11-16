#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    char t;
    cin.get(t);
    while(t!='\n')
    {
        cout << t - '0' << endl;
        cin.get(t);
    }
    getchar();
    return 0;
}