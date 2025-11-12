#include <bits/stdc++.h>

using namespace std;

int knapsack(int w , vector<int> &wt , vector<int> &val , int n){
  if( n == 0 || w == 0)
    return 0;

  if (wt[n-1] <= w)
    return max(val[n-1] + knapsack(w-wt[n-1] , wt , val , n-1) , knapsack(w,wt,val,n-1));
  else 
    return knapsack(w,wt,val,n-1);

}


int knapsack2(int w , vector<int> &wt , vector<int> &val , int n){
  vector<vector<int>> dp(n+1 , vector<int>(w+1 , 0));

  for (int i = 1 ; i <= n ; i++){
    for (int j = 1 ; j <= w ; j++){
      if (wt[i-1] <= j)
        dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]] , dp[i-1][j]);
      else 
        dp[i][j] = dp[i-1][j];
    }
  }
  return dp[n][w];
}
int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    int n = val.size();

    cout << "Maximum value (Recursive): " << knapsack(W, wt, val, n);
    cout << "Maximum value (Recursive): " << knapsack2(W, wt, val, n);
}
