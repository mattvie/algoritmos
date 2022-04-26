#include <iostream>
using namespace std;

typedef struct tNode {
    int v, h, idx, pl, pr;
    struct tNode *l, *r;
} tNode;

typedef struct {
    tNode *root;
} Tree;

int height(tNode *n) {
    return n? n->h: 0;
}

int max(int h1, int h2) {
    return h1 > h2? h1: h2;
}

void fixheight(tNode *n) {
    if(n) n->h = max(height(n->l), height(n->r)) + 1;
}

tNode *RR(tNode *n) {
    tNode *a = n->l;

    n->l = a->r;
    a->r = n;

    fixheight(n);
    fixheight(a);

    a->idx += n->pl;
    a->pl += n->pl;
    n->pl += a->pr;
    a->pr = 0;

    return a;
}

tNode *RL(tNode *n) {
    tNode *a = n->r;

    n->r = a->l;
    a->l = n;

    fixheight(n);
    fixheight(a);

    a->idx += n->pr;
    a->pr += n->pr;
    n->pr += a->pl;
    a->pl = 0;

    return a;
}

int GetBal(tNode *n) {
    return n ? height(n->l) - height(n->r): 0;
}

tNode *Bal(tNode *n) {
    fixheight(n);
    int bl = GetBal(n);

    if(bl < -1) {
        if(GetBal(n->r) > 1) n->r = RR(n->r);
        return RL(n);
    } else if(bl > 1) {
        if(GetBal(n->l) < -1) n->l = RL(n->l);
        return RR(n);
    }

    return n;
}

tNode *CreatetNode(int val, int idx) {
    tNode *tmp = (tNode*)malloc(sizeof(tNode));

    tmp->v = val;
    tmp->idx = idx;
    tmp->h = 1;
    tmp->pl = tmp->pr = 0;
    tmp->l = tmp->r = NULL;

    return tmp;
}

tNode *Add(tNode *n, int val, int idx) {
    if(!n) return CreatetNode(val, idx);
    else if(val < n->v) {
        n->idx += 1;
        n->pr += 1;

        if(n->l) n->l = Add(n->l, val, idx);
        else {
            n->l = Add(n->l, val, n->idx - 1);
            n->pl = 0;
        }
    } else {
        if(n->r) n->r = Add(n->r, val, idx);
        else {
            n->r = Add(n->r, val, n->idx + 1);
            n->pr = 0;
        }
    }

    return Bal(n);
}

void Find(tNode *n, int val) {
    tNode *i = n;

    while(i)
        if(val == curr->rootv) {
            printf("%d\n", curr->rootidx);
            return;
        } else if(val < curr->rootv) {
            if(curr->rootpl) {
                if(curr->rootl) {
                    curr->rootl->idx += curr->rootpl;
                    curr->rootl->pl += curr->rootpl;
                    curr->rootl->pr += curr->rootpl;
                }
                curr->rootpl = 0;
            }

            i = curr->rootl;
        } else {
            if(curr->rootpr) {
                if(curr->root) {
                    curr->root->idx += curr->rootpr;
                    curr->root->pl += curr->rootpr;
                    curr->root->pr += curr->rootpr;
                }
                curr->rootpr = 0;
            }

            i = curr->root;
        }

    printf("Data tidak ada\n");
}

int main() {
    Tree *tree = (Tree*) malloc(sizeof(Tree));
    tree->root = NULL;

    int Q, command, x;
    scanf("%d", &Q);

    while(Q--) {
        scanf("%d %d", &command, &x);
        if(cmd == 1)
			tree->root = Add(tree->root, x, 1);
        else
			Find(tree->root, x);
    }
}


