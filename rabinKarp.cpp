#include <bits/stdc++.h>
using namespace std;

#define d 255

void rabinKarp(string text , string patter , int q){
  int n = text.size();
  int m = patter.size();

  int p =0;
  int t = 0;
  int h = 1;

  for (int i = 0 ; i < m-1 ; i++){
    h = (h * d)%q;
  }
  
  for (int i = 0 ; i < m ; i++){
    p = (d*p + patter[i])%q;
    t = (d*t + text[i])%q;
  }

  for (int i = 0 ; i<= n-m ; i++){
    if (p == t){
      bool match = true;
      for (int j = 0 ; j < m ; j++){
        if (text[i+j] != patter[j]){
          match = false;
          break;
        }
      }
      if (match)
        cout << "patter found at : "<< i << endl;
    }

    if (i < n-m){
      t = (d*(t - text[i]*h) + text[i+m])%q;
      if (t < 0)
        t += q;
    }
  }


}

int main(){
  string text = "ABBAJAKLBBAABJLKJLKBBA";
  string pattern = "BBA";
  int q = 101;
  rabinKarp(text , pattern,q);
  return 0;
}
