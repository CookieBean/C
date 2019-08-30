#include <stdio.h>
#include <stdlib.h>
#include <stack>

typedef struct node {
    int data;
    node* left,*right = NULL;
} node;
std::stack <node*> st;
node* root = NULL;
node* ins(int key, node* rt);
void del(int key, node* rt, node* parent);
node* f(node* rt);
void print_tree(node* rt, int lev);

void dfs(node* nd) {
    if(nd->left) dfs(nd->left);
    if(nd->right) dfs(nd->right);
    if(!nd->left && !nd->right) printf("%d 탐색 완료", nd->data);
}

int main() {
    root = ins(5, root);
    print_tree(root, 0);
    root = ins(3, root);
    print_tree(root, 0);
    root = ins(11, root);
    print_tree(root, 0);
    del(11, root, NULL);
    print_tree(root, 0);
    st.push(root);
}

node* ins(int key, node* rt) {
    if(rt == NULL) {
        rt = (node*)malloc(sizeof(node));
        rt->data = key;
        rt->left = rt->right = NULL;
    } else {
        if(rt->data > key) {
            rt->left = ins(key, rt->left);
        } else if(rt->data < key) {
            rt->right = ins(key, rt->right);
        }
    }
    return rt;
}

void del(int key, node* rt, node* parent) {
    if(rt == NULL) {
        return;
    } else {
        if(rt->data > key) {
            del(key, rt->left, rt);
        } else if(rt->data < key) {
            del(key, rt->right, rt);
        } else {
            if(rt->right == NULL && rt->left == NULL) {
                if(parent->left && parent->left == rt) {
                    parent->left = NULL;
                } else if(parent->right && rt->right == rt) {
                    parent->right = NULL;
                }
                free(rt);
            }
            if(rt->right != NULL && rt->left != NULL) {
                node* nd = f(rt->right);
                if(nd == NULL) {
                    rt->data = rt->right->data;
                    del(rt->data, rt->right, rt);
                }
                rt->data = nd->left->data;
                del(nd->data, nd->left, nd);
            } else {
                if(parent->right == rt) {
                    parent->right = rt->right ? rt->right : rt->left;
                } else if(parent->left == rt) {
                    parent->left = rt->right ? rt->right : rt->left;
                }
            }
        }

    }
}

void print_tree(node* rt, int lev) {
    if(rt == NULL) return;
    printf("\n");
    for(int i = 1; i<=lev; i++) {
        printf(" ");
    }
    printf("%d", rt->data);
    print_tree(rt->left, ++lev);
    print_tree(rt->right, lev);
}

node* f(node* rt) {
    if(rt->left == NULL) return NULL;
    if(rt->left->left == NULL) return rt;
    else return f(rt->left);
}
