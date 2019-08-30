//그래프
//#include <stdio.h>
//
//int arr[100][100];
//
//int main()
//{
//    int vertex, edge;
//    char a, b;
//    scanf("%d %d", &vertex, &edge);
//    for(int i = 1; i<=edge; i++) {
//        scanf(" %c %c", &a, &b);
//        //printf("%d", a-40);
//        arr[a-64][b-64] = 1;
//        arr[b-64][a-64] = 1;
//    }
//    for(int i = 1; i<=vertex; i++) {
//        for(int j = 1; j<=vertex; j++) {
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//} ctrl shift x -> codeblocks
// usually when you want to make whole code to annotator, you can yse ctrl /

//2진탐색
// #include <stdio.h>
// int arr[101];
// int f(int s, int e, int key) {
//     if(s >= e) return s;
//     if(key>arr[(s+e)/2]) return f((s+e)/2, e, key);
//     else if(key == arr[(s+e)/2]) return (s+e)/2;
//     else return f(s, (s+e)/2, key);
// }
//
// int main() {
//     for(int i = 1; i<=100; i++) {
//         arr[i] = i;
//     }
//     int n;
//     scanf("%d", &n);
//     printf("%d", f(1, 100, n));
//     return 0;
// }

#include <stdio.h>
char a, b;
int arr[27][27], top = -1, min = 10000000, sum = 0, vertex, edge, w, ver, len, min_len, p[27], *str;
typedef struct st1 {
  int weight;
  int ver;
  int str[27];
  int len;
} st1;
struct st1 v[100000];
int main() {
  scanf("%d %d", &vertex, &edge);
  for(int i = 1; i<=edge; i++) {
    scanf(" %c %c %d", &a, &b, &w);
    sum += arr[b-'A'][a-'A'] = arr[a-'A'][b-'A'] = w;
  }
  scanf(" %c %c", &a, &b);
  v[top].len = 1 + (v[++top].weight = 0);
  printf("%d\n", v[top].len);
  v[top].str[0] = v[top].ver= a-'A';
  while(top>-1) {
    w = v[top--].weight;
    ver = v[top+1].ver;
    str = v[top+1].str;
    len = v[top+1].len;
    if(min>w && w<=sum)
      for(int i = 0; i<vertex; i++) {
        if(arr[ver][i]!=0)
          if(i == b-'A' && min>w+arr[ver][i]) {
            min = w+arr[ver][i];
            for(int i = 0; i<(min_len = len+1) - 1; i++) {
              p[i] = str[i];
            }
            p[len] = b-'A';
          } else {
            v[++top].weight = w+arr[ver][i];
            v[top].str[len] = v[top].ver = i;
            for(int i = 0; i<(v[top].len = len+1) - 1; i++) {
              v[top].str[i] = str[i];
            }
          }
        }
  }
  printf("%d\n", min==10000000 ? -1 : min);
  for(int i = 0; i<min_len; i++) {
    printf("%c\n", p[i]+'A');
  }
}
