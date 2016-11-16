#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a;
    char result[a][4];
    for (int i = 0; i<a; ++i)
    {   
        cin >> b;
        if (b > 0){
            result[i][0] = 'y';
            result[i][1] = 'e';
            result[i][2] = 's';
            result[i][3] = '\0';}
        else{
            result[i][0] = 'n';
            result[i][1] = 'o';
            result[i][2] = '\0';}
    }

    for (int i = 0; i < a; ++i){
        for (int j=0; j < 4;++j)
            if (result[i][j] == '\0')
                break;
            else
                cout << result[i][j];
        cout<<endl;
    }

    return 0;
}