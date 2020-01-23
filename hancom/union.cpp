#include <bits/stdc++.h>
using namespace std;
typedef struct NODE {
  struct NODE* next = NULL;
  struct NODE* prev = NULL;
  char pass = 0;
} NODE;
NODE bottom, ceil;
NODE* top = bottom;
void insert(char a) {
  NODE* nnode = (NODE*)malloc(sizeof(NODE));
  nnode -> next = top -> next;
  nnode -> prev = top;
  top -> next = nnode;
  nnode -> next -> prev = nnode;
  nnode -> pass = a;
}
void del() {
  top -> next -> prev = top -> prev;
  top -> prev -> next = top -> next;
  free(top);
}
void next() {
  if(top -> next != &ceil) top = top -> next;
}
void prev() {
  if(top != &bottom) top = top -> prev;
}
int main() {
  int n;
  scanf("%d", &n);
  char arr[1000005];
  for(int i=1;i<=n;i++) {
    scanf("%s", arr);
    for(int j=0;arr[j];j++) {
      if(arr[j] == '<') prev();
      else if(arr[j] == '>') next();
      else if(arr[j] == '-') del();
      else insert(arr[j]);
    }
  }
}
