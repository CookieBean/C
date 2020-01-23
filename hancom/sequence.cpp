///===== user.cpp =====

extern int orderCheck(int left, int right);

///====== main.cpp =====


#include <iostream>
#include <stdlib.h>
#include <ctime>
#define MAXSIZE 100000
using namespace std;

static int org[MAXSIZE], dat[MAXSIZE];
static int arrCount, QueryCount;

extern void array_restore(int arrCount, int dat[]);

int arr[500005], temp[500005];

void merge(int arr[], int s, int e, int brr[]) {
  if(s >= e) {
    return;
  }
  int mid = (s + e) / 2;

  merge(arr, s, mid, brr);
  merge(arr, mid + 1, e, brr);

  int i = s, j = mid + 1;
  for(int k=s;k<=e;k++) {
    if(j > e) {
      brr[k] = arr[i++];
    } else if(i > mid) {
      brr[k] = arr[j++];
    } else if(orderCheck(arr[i], arr[j])) {
      brr[k] = arr[i++];
    } else {
      brr[k] = arr[j++];
    }
  }
  for(int i = s;i<=e;i++) {
    arr[i] = brr[i];
  }
}

void array_restore(int arrCount, int dat[]){
    // implement here
    for(int i=0;i<arrCount;i++) arr[i] = i;
    merge(arr, 0, arrCount-1, temp);
    // for(int i=0;i<arrCount;i++) printf("%d ", arr[i]);
    for(int i=0;i<arrCount;i++) {
      dat[arr[i]] = i+1;
      // printf("dat[%d] = %d\n", arr[i], i+1);
    }
}

int orderCheck(int left, int right)
{
    QueryCount++;
    if (org[left] < org[right]) return 1;
    else return 0;
}

inline void Swap(int&a, int&b){
    int t = a; a = b; b = t;
}

static void init(int t)
{
    int i, j;
    QueryCount = 0;
    arrCount = rand() % 2000 + t * 2000;
    for (i = 0; i < arrCount; i++) {
        org[i] = i + 1;
        dat[i] = 0;
    }
    for (i = 0; i < arrCount; i++){
        j = (int)((long long)rand() * rand() % arrCount);
        Swap(org[i], org[j]);
    }
    // for(int i=0;i<arrCount;i++) printf("org[%d] : %d\n", i, org[i]);
    puts("");
}

static int arr_comp()
{
    if (QueryCount >= arrCount * 20) return MAXSIZE * 100;
    for (int i = 0; i < arrCount; i++) {
        if (org[i] != dat[i]) return MAXSIZE * 100;
    }
    return QueryCount;
}

int main(void)
{
    srand(time(NULL));
    for (int tc = 0; tc < 50; tc++)
    {
        init(tc);
        array_restore(arrCount, dat);
        cout << "#" << tc << " " << arrCount << " " << arr_comp() << endl;
    }

    return 0;
}
