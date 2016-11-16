#include <iostream>
#define max(a,b) ((a)>(b)?a:b)
using namespace std;

int main(){
    int maximum = 1;
    cout << maximum;
    maximum = max(5,34);
    cout << maximum;
    return 0;
}