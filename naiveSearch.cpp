#include <bits/stdc++.h>

using namespace std;

void naiveSearch(string text , string pattern){
  int m = text.size();
  int n = pattern.size();

  for (int i = 0 ; i <= m-n ; i++){
    int j;
    for(j = 0 ; j < n ; j++){
      if (text[i+j] != pattern[j])
        break;
    }

    if (j == n)
      cout << "string match index at : " << i << endl;
  }
}

int main(){
  string text = "ABBAJAKLBBAABJLKJLKBBA";
  string pattern = "BBA";
  naiveSearch(text , pattern);
  return 0;
}
