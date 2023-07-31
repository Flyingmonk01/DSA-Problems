#include <iostream>

using namespace std;

bool isPalindrome(string &str, int s, int e)
{
    while (s <= e)
    {
        if (str[s] != str[e])
        {
            return false;
        }
        s++;
        e--;
    }
    return true;
}

int main()
{
    string str = "racexcaer";

    int s = 0;
    int e = str.length() - 1;
    bool flag = true;
    while (s <= e)
    {
        if (str[s] != str[e])
        {
            flag = isPalindrome(str, s + 1, e) || isPalindrome(str, s, e - 1);
        }
        s++, e--;
    }
    if (flag)
    {
        cout << true;
    }
    else
        cout << false;
    return 0;
}