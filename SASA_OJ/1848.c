#include <stdio.h>
int arr[11][11], n, visited[11], stack[100];
int all_visit() {
  for(int i = 1; i<=n; i++) if(!visited[i-1]) return 0;
  return 1;
}
int main() {
  int f = 0, top = -1;
  scanf("%d", &n);
  for(int i = 0; i<n; i++)
    for(int j = 0; j<n; j++)
      scanf("%d", &arr[i][j]);
  stack[++top] = 0;
  while(top > -1 && !all_visit()) {
    f = stack[top--];
    if(visited[f] == 1) continue;
    printf("%c ", f+65);
    visited[f] = 1;
    for(int i = n; i>=0; i--) if(arr[f][i]==1&&visited[i] == 0) stack[++top] = i;
  }
}
