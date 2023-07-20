// Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
// Note: Unlike 0/1 knapsack, you are allowed to break the item. 

 

static bool cmp(Item one, Item two) {
        double valuebyweight1 = (double)(one.value)/ (double)(one.weight);
        double valuebyweight2 =  (double)(two.value)/ (double)(two.weight);
        
        return valuebyweight1 > valuebyweight2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double ans = 0;
        sort(arr, arr+n, cmp);
        
        for(int i= 0;i<n;i++) {
            if(arr[i].weight <= W){
                ans += arr[i].value;
                W -= arr[i].weight;
            }
            else{
                double fraction =  (double)(W)/ (double)(arr[i].weight);
                ans += fraction * arr[i].value;
                W = 0;
            }
        }
        return ans;
    }