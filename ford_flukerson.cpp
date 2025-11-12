#include <bits/stdc++.h>
using namespace std;

int n ;

bool bfs(vector<vector<int>>& rgraph , int s , int t , vector<int>&parent){

  vector<bool>visited(n,false);

  queue<int> q;
  q.push(s);
  visited[s] = true;
  parent[s] = -1;

  while(!q.empty()){
    int u = q.front();
    q.pop();

    for (int v = 0 ; v < n ; v++){
      if (!visited[v] && rgraph[u][v] > 0){
        q.push(v);
        visited[v] = true;
        parent[v] = u;

        if (v == t) return true;

      }

    }
  }

  return false;
}

int fordFlukerson(vector<vector<int>> graph , int s , int t){
  int maxFlow = 0;
  vector<int> parent(n);
  vector<vector<int>> rgraph = graph;

  while(bfs(rgraph , s , t , parent)){
    int flow = INT_MAX ;
    for (int v = t ; v != s ; v = parent[v]){
      int u = parent[v];
      flow = min(flow , rgraph[u][v]);
    }



    for (int v = t ; v != s ; v = parent[v]){

      int u = parent[v];

      rgraph[u][v] -= flow;
      rgraph[v][u] += flow;
    }

    maxFlow += flow;
  }

  return maxFlow;
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

    n = graph.size();
    cout << "Maximum flow: " << fordFlukerson(graph, 0, 5);
}

