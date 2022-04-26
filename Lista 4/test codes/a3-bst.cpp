#include <iostream>
using namespace std;

#define DATASIZE 100011
 
typedef struct tNode {
	tNode* left;
	tNode* right;
	int val;
} tNode;

tNode Node[DATASIZE];
int bst_size=0;
int data[DATASIZE];

void bst_insert(tNode* &root, int data) {
	if (!root) {
		root = &Node[bst_size];
		bst_size++;
		root->val=data;
		root->left=NULL;
		root->right=NULL;
	} else if (data < root->val)
		bst_insert(root->left, data);
	else
		bst_insert(root->right, data);
}
//n = root, val = target, i = curr
void bst_find_index(tNode* &root, int target) {
	tNode *curr = root;

    while(curr)
        if(target == curr->val) {
            printf("%d\n", curr->idx);
            return;
        } else if(val < i->v) {
            if(i->pl) {
                if(i->l) {
                    i->l->idx += i->pl;
                    i->l->pl += i->pl;
                    i->l->pr += i->pl;
                }
                i->pl = 0;
            }

            i = i->l;
        } else {
            if(i->pr) {
                if(i->r) {
                    i->r->idx += i->pr;
                    i->r->pl += i->pr;
                    i->r->pr += i->pr;
                }
                i->pr = 0;
            }

            i = i->r;
        }

    printf("Data tidak ada\n");
	
}


int main() {
	int command, i, size=0, Q; //how many queries
	//cin >> Q;
	scanf("%d", &Q);
	tNode* root=NULL;
	while (Q--) {
		//cin >> command >> data[size];
		scanf("%d %d", &command, &data[size]);
		if(command==1) {
		//insert x to the list	
			bst_insert(root, data[size]);
		} else {
		// find x index on the list on ascending order
			bst_find_index(root, data[size]);
		}
		size++;
	}
	
    return 0;
}
