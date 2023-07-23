// Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
// Note: can you take care of the duplicates without using any additional Data Structure?


vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            set<int> ans;
            int i = 0; int j = 0; int k = 0;
            while(i < n1 && j < n2 && k < n3){
                if(A[i] == B[j] && A[i] == C[k]){
                    ans.insert(A[i]);
                    i++;
                    j++;
                    k++;
                }
                
                else{
                    int mini = min(A[i], min(B[j], C[k]));
                    
                    if(mini == A[i]) i++;
                    else if(mini == B[j]) j++;
                    else k++;
                    
                }
                
            }
            vector<int>v(ans.begin(), ans.end());
            return v;
        }