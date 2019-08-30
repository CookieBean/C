#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
    long long int no;
    char name[11];
    struct node* next = NULL;
} node;
node* head = NULL;
void ins(long long int num, char* named);
void del(long long int num, char* named);
void print(int n);
//void print_all();

int main() {
    int n;
    long long int no;
    char c;
    char name[11];
    scanf("%d", &n);
    for(int i = 1; i<=n; i++) {
        //printf("%d번째\n", i);
        scanf(" %c %lld %s", &c, &no, name);
        //printf("input : %c %d %s\n", c, no, name);
        if(c == 'I' ) {
            ins(no, name);
        }
        if(c == 'D' ) {
            del(no, name);
        }
        //print_all();
    }
    for(int i = 1; i<=5; i++) {
        scanf("%d", &n);
        print(n);
    }
}

void ins(long long int num, char* named) {
    node* t, *trail = NULL;
    node* n = (node*)malloc(sizeof(node));
    strcpy(n->name, named);
    n->no = num;
    for(t = head; t!=NULL && n->no>t->no; trail = t, t = t->next) {
        //printf("head num : %d\n", t->no);
    }
    n->next = t;
    if(trail == NULL) {
        head = n;
    } else {
        trail->next = n;
    }
}

void del(long long int num, char* named) {
    node* t, *trail = NULL;
    for(t = head; t!=NULL && num!=t->no; trail = t, t = t->next);
    if(t == NULL) return;
    //printf("del : %d\n", t->no);
    if(t!=NULL && num == t->no) {
        if(trail==NULL) {
            head = t->next;
        } else {
            trail->next = t->next;
        }
        free(t);
    }
}

void print(int n) {
    int i;
    node* t = NULL;
    for(t = head, i = 1; i < n; t = t->next, i++);
    printf("%d %s\n", t->no, t->name);
}
/*
void print_all() {
    node* t = NULL;
    for(t = head; t!=NULL; t = t->next) printf("%d, %s\n", t->no, t->name);
    printf("--------------------------\n");
}
*/
