#include <stdio.h>

int a;

void filter(int i, int j) {
    int k = 0, t = a;
    while(t!=1) {
        if( (i%t)>(t/3) &&
            (i%t)<=(t*2/3) &&
            (j%t)>(t/3) &&
            (j%t)<=(t*2/3)) { k = 1; }
        t/=3;
    }
    if(k == 1) printf(" ");
    else printf("o");
}

int main()
{
    int i, j;
    scanf("%d", &a);
    for(i = 1; i<=a; i++) {
        for(j = 1; j<=a; j++) {
            filter(i, j);
        }
        printf("\n");
    }
}
