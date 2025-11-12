#include <bits/stdc++.h>

using namespace std;
#define INF 1e4

void floydWarshall(vector<vector<int>> graph){

  int n = graph.size();
  vector<vector<int>> dist(n , vector<int>(n,0));

  for (int i = 0 ; i < n ; i++){
    for (int j = 0 ; j < n ; j++){
      if (i != j && graph[i][j] == 0)
        dist[i][j] = INF;
      else 
        dist[i][j] = graph[i][j];
    }
  }


  for (int k = 0 ; k < n ; k++){
    for (int i = 0 ; i < n ; i++){
      for (int j = 0 ; j < n ; j++){
        if (dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }

  for (int i = 0 ; i < n ; i++){
    for (int j = 0 ; j < n ; j++){
      if (dist[i][j] == INF)
        cout << "INF" << " ";
      else 
        cout << dist[i][j] << " ";
    }
    cout << endl;
  }

}

int main() {
    vector<vector<int>> graph = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };


    floydWarshall(graph);
}
