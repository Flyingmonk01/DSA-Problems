

#include <iostream>

using namespace std;

int main()
{
    int arr[4][4] = {
                    {1,   9,  4, 10},
                    { 3,   6, 90, 11},
                     { 2, 30, 85, 72},
                    { 6, 31, 99, 15}};

    for(int j = 0; j < 4; j++){
        if(j&1){
            for(int i = 4-1; i >= 0; i--)
                cout << arr[i][j] << " ";
        }
        else{
            for(int i = 0; i < 4; i++){
                cout << arr[i][j] << " ";
            }
        }
    }

    return 0;
}