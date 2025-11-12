#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int lcs(string x, string y){
  int n = x.size();
  int m = y.size();

  vector<vector<int>> dp(n+1,vector<int>(m+1 , 0));

  for (int i = 1 ; i <= n ; i++){
    for (int j = 1 ; j <= m ; j++){
      if (x[i-1] == y[j-1])
        dp[i][j] = 1 + dp[i-1][j-1];
      else 
        dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
    }
  }

  for (int i = 0 ; i < n ; i++){
    for (int j = 0 ; j < m ;j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

  string lcs = "";
  int i = n , j = m;

  while (i > 0 && j > 0){
    if (x[i-1] == y[j-1]){
      lcs += x[i-1];
      i--;
      j--;
    }
    else {
        if (dp[i-1][j] > dp[i][j-1])
          i--;
        else 
          j--;
    }
  }

  reverse(lcs.begin() , lcs.end());
  cout << lcs << endl;
  return dp[n][m];
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    cout << "Length of LCS: " << lcs(X, Y);
}
