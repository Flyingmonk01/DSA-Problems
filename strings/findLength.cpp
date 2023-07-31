#include<iostream>

using namespace std;

int main (){
    
    string str = "sameer";

    int len = 0;
    for(int i = 0; i < str.length(); i++){
        len++;
    }
    cout << len << endl;
    return 0;
}