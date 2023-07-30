
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<long long int>& trees, long long int& woodRequired, long long int& sol){

  long long int woodLen = 0;
  for(long long int i = 0; i < trees.size(); i++){
    if(trees[i] >= sol){
      woodLen += trees[i] - sol;
    }
  }
  return woodLen >= woodRequired;
}

int minHeightRequired(vector<long long int>& trees, long long int& woodRequired){

  long long int start = 0;
  long long int end = *max_element(trees.begin(), trees.end());

  long long int ans = -1;
  long long int mid = start + (end - start)/2;

  while(start <= end){
    if(isPossible(trees, woodRequired, mid)){
      ans = mid;
      start = mid+1;
    }
    else{
      end = mid-1;
    }
    mid = start + (end - start)/2;
  }
  return ans;
}

int main() {
  long long int nTrees;
  cin >> nTrees;

  long long int woodRequired;
  cin >> woodRequired;

  vector<long long int> trees;
  for(long long int i = 0; i < nTrees; i++){
    long long int value;
    cin >> value;
    trees.push_back(value);
  }

  cout << minHeightRequired(trees, woodRequired) << endl;
  return 0;
}