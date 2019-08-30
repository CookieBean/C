#include <stdio.h>
int arr[100001], n;
void insertion();
void bubble();
void merge_sort(int data[], int p, int q);
void merge(int data[], int p, int q, int r);
void quick(int data[], int p, int q);
int main() {
  // insertion();
  // bubble();
  // merge_sort(arr, 0, 9);
  scanf("%d", &n);
  for(int i = 0; i<n; i++) scanf("%d", arr+i);
  quick(arr, 0, n-1);
  for(int i = n-1; i>=0; i--) printf("%d ", arr[i]);
}
void insertion() {
  for(int i = 1; i<10; i++)
    for(int j = i; j>=0; j--)
      if(arr[j]<arr[j-1]) {
        int tmp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = tmp;
      }
}
void bubble() {
  for(int i = 0; i<10; i++)
    for(int j = 0; j<9; j++)
      if(arr[j]>arr[j+1]) {
        int tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }
}
void merge_sort(int data[], int p, int q) {
  int r = (p+q)/2;
  if(p<q) {
    merge_sort(data, p, r);
    merge_sort(data, r+1, q);
    merge(data, p, r, q);
  }
}
void merge(int data[], int p, int q, int r) {
  int tmp[100001];
  int i = p, j = q+1, k = p;
  while(i<=q && j<=r) {
    if(data[i]<data[j]) tmp[k++] = data[i++];
    else tmp[k++] = data[j++];
  }
  while(i<=q) tmp[k++] = data[i++];
  while(j<=r) tmp[k++] = data[j++];
  for(i = p; i<=r; i++) data[i] = tmp[i];
}
void quick(int data[], int p, int q) {
  if(p >= q) return;
  int tmp[100001];
  int pivot = data[p], top = p, bot = q;
  for(int i = p+1; i<=q; i++) {
    if(data[i]<=pivot) tmp[top++] = data[i];
    else tmp[bot--] = data[i];
  }
  tmp[top] = pivot;
  for(int i = p; i<=q; i++) data[i] = tmp[i];
  quick(data, p, top-1);
  quick(data, top+1, q);
  return;
}
