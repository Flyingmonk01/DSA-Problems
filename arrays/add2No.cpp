// Given two array A[0….N-1] and B[0….M-1] of size N and M respectively, representing two numbers such that every element of arrays represent a digit. For example, A[] = { 1, 2, 3} and B[] = { 2, 1, 4 } represent 123 and 214 respectively. The task is to find the sum of both the numbers.


string calc_Sum(int *a,int n,int *b,int m){
    // Complete the function
        
        int i = n-1;
        int j = m-1;
        string ans;
        int carry = 0;
        
        while(i >= 0 && j >= 0){
            int first = a[i];
            int second = b[j];
            
            int sum = first+second+carry;
            int digit = sum%10;
            carry = sum/10;
            ans.push_back(digit+'0');
            i--;
            j--;
        }
        
        while(i >= 0){
            int num = a[i];
            int sum = carry+num;
            int digit = sum%10;
            carry = sum/10;
            ans.push_back(digit+'0');
            i--;
        }
        
        while(j >= 0){
            int num = b[j];
            int sum = carry+num;
            int digit = sum%10;
            carry = sum/10;
            ans.push_back(digit+'0');
            j--;
        }
        if(carry){
            ans.push_back(carry+'0');
        }
        
        reverse(ans.begin(), ans.end());
        
        int count = 0;
        for(auto x : ans){
            if(x != '0') break;
            else count++;
        }
        if(count){
            return ans.substr(count);
        }
        
        return ans;
    }