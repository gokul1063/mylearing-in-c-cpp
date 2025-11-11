#include <bits/stdc++.h>

using namespace std ;

struct Point{
  int x,y;
};

Point p0;

int orientation(Point p1 , Point p2 , Point p3){
  int val = (p2.y-p1.y)*(p3.x-p2.x) - (p2.x-p1.x)*(p3.y-p2.y);
  if (val == 0) return 0;

  return (val > 0) ? 1 : 2;
}

int distSqrt(Point p1, Point p2){
  return ((p1.x - p2.x) * (p1.x-p2.x)) + ((p1.y-p2.y) * (p1.y - p2.y));
}


bool compare (Point a , Point b){
  int o = orientation(p0,a,b);

  if (o == 0)  
      return (distSqrt(p0,a) < distSqrt(p0,b));

  return (o == 2);

}


vector<Point> convexHull(vector<Point> point){
  int n = point.size();

  if (n < 3)
      return {};
  int minY = point[0].y , minInd = 0;
  for(int i = 0 ;i < n ; i++){
    if (minY < point[i].y || minY == point[i].y && point[i].x < point[minInd].x){
      minY = point[i].y;
      minInd = i;
    }
  }

  swap(point[0] , point[minInd]);
  p0 = point[0];

  sort(point.begin()+1 , point.end(), compare);

  vector<Point> hull;

  hull.push_back(point[0]);
  hull.push_back(point[1]);
  hull.push_back(point[2]);


  for (int i = 3 ; i < n ; i++){
    while (hull.size() >= 2 && 
      orientation(hull[hull.size()-2] , hull[hull.size()-1] , point[i]) != 2) { 
          hull.pop_back();
    }
    hull.push_back(point[i]);
  }

  return hull;
}


int main() {

    // ✅ Hardcoded test case
    vector<Point> points = {
        {0, 3},
        {2, 2},
        {1, 1},
        {2, 1},
        {3, 0},
        {0, 0},
        {3, 3},
        {1, 2}
    };

    cout << "Input Points:\n";
    for (auto p : points)
        cout << "(" << p.x << ", " << p.y << ")\n";

    vector<Point> hull = convexHull(points);

    cout << "\nConvex Hull Points:\n";
    for (auto p : hull)
        cout << "(" << p.x << ", " << p.y << ")\n";

    return 0;
}



