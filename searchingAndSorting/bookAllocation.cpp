// You have N books, each with Ai number of pages. M students need to be allocated contiguous books, with each student getting at least one book. Out of all the permutations, the goal is to find the permutation where the student with the most pages allocated to him gets the minimum number of pages, out of all possible permutations.

// Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).



bool isPossible(int A[], int N, int M, int sol){
    int pageSum = 0;
    int c = 1;
    for(int i = 0; i < N; i++){
        if(A[i] > sol){
            return false;
        }
        if(pageSum + A[i] > sol){
            c++;
            pageSum = 0;
            pageSum = A[i];

            if(c > M){
                return false;
            }
        }
        else{
            pageSum += A[i];
        }
    }
    return true;
}



int findPages(int A[], int N, int M){
    if(M > N){
        return -1;
    }

    int s = 0;
    int e = accumulate(A, A+N, 0);
    int mid = (s+e)/2;
    int ans = -1;

    while(s <= e){
        
        if(isPossible(A, N, M, mid)){
            ans = mid;
            end = mid-1;
        }
        else s = mid+1;

        mid = (s+e)/2;
    }
    return ans;
}