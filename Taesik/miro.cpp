#include <bits/stdc++.h>
using namespace std;
char arr[102][102];
bool visited[102][102];
pair<int, int> s, g;
queue<pair<pair<int, int>, int>> Q;
int vx[4] = {0, 1, 0, -1};
int vy[4] = {1, 0, -1, 0};
int main() {
  int h, w;
  scanf("%d %d", &h, &w);
  for(int i=1;i<=h;i++) for(int j=1;j<=w;j++) {
    scanf(" %c" , &arr[i][j]);
    if(arr[i][j] == 'S') {
      s.first = i;
      s.second = j;
    } else if(arr[i][j] == 'G') {
      g.first = i;
      g.second = j;
      arr[i][j] = '.';
    }
  }
  pair<pair<int, int>, int> k(s, 0);
  Q.push(k);
  while(!Q.empty()) {
    pair<pair<int, int>, int> a;
    a = Q.front();
    Q.pop();
    if(a.first == g) {
      printf("%d", a.second);
      return 0;
    }
    for(int i=0;i<4;i++) if(arr[a.first.first+vx[i]][a.first.second+vy[i]] == '.' && !visited[a.first.first+vx[i]][a.first.second+vy[i]]) {
      visited[a.first.first+vx[i]][a.first.second+vy[i]] = true;
      pair<pair<int, int>, int> tmp;
      tmp.first.first = a.first.first + vx[i];
      tmp.first.second = a.first.second + vy[i];
      tmp.second = a.second + 1;
      Q.push(tmp);
    }
  }
}
