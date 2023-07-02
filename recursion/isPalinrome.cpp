// Q. Given a number N.Find if the digit sum(or sum of digits) of N is a Palindrome number or not.
// Note:A Palindrome number is a number which stays the same when reversed.Example- 121,131,7 etc.

bool isPalindrome(int n)
{
    int rev = 0;
    int temp = n;
    while (temp)
    {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    return (rev == n);
}
int isDigitSumPalindrome(int N)
{
    // code here
    int sum = 0;
    while (N)
    {
        sum += N % 10;
        N /= 10;
    }

    return isPalindrome(sum);
}