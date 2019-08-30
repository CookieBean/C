#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int order;
    int coefficient;
    node* next = NULL;
} node;
node* head = NULL;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i<=n; i++) {
        int o, c;
        scanf("%d %d", &o, &c);
        insert_node(o, c);
    }
    return 0;
}

void insert_node(int o, int c) {
    node* t, *trail = NULL;
    node* n = (node*)malloc(sizeof(node));
    n->order = o;
    n->coefficient = c;
    for(t = head; t!=NULL&&n->order>=t->order; trail = t, t = t->next);
    if(n->order == t->order) {
        free(n);
        t->coefficient += c;
        return;
    }
    n->next = t;
    if(trail == NULL) head->next = n;
    else trail->next = n;
}

void print_node() {
    node* t;
    for(t = head, t!=NULL; t = t->next) {
        printf("%d차 : %d\n", t->order, t->coefficient);
    }
}
