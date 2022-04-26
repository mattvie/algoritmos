#include <iostream>
using namespace std;

#define DATASIZE 10000
 
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

void bst_print(tNode* root) {
	if (root) {
		bst_print(root->left);
		bst_print(root->right);
		cout << root->val << endl;
	}
}

int main() {
	
	int size=0;
	tNode* root=NULL;
	while (cin >> data[size]) {
		bst_insert(root, data[size]);
		size++;
	}
				
	bst_print(root);
	
    return 0;
}
