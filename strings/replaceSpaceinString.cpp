#include<iostream>

using namespace std;

int main (){
    string str = "Hello Sameer is here!";

    for(int i = 0; i < str.size(); i++){
        if(str[i] == ' '){
            str[i] = '@';
        }
    }
    cout << str << endl;
    return 0;
}