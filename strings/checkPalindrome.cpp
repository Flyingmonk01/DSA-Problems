#include<iostream>

using namespace std;

int main (){
    string str = "racexcar";
    bool flag = true;
    int s = 0, e = str.size()-1;
    while(s <= e){
        if(str[s] != str[e]){
            flag = false;
            break;
        }
        s++, e--;
    }
    if(flag){
        cout << "Palindrome" << endl;
    }
    else{
        cout << "Not palindrome" << endl;
    }
    return 0;
}   