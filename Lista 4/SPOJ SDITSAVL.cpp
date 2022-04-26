#include <iostream>
using namespace std;

typedef struct Node {
	int key;
	struct Node *left;
	struct Node *right;
	int height;
	int left_child ;
	int right_child;
	int count;	
} Node;

// Height of a node!
int h(Node* n) {
	if(!n)
		return 0;
	else
		return n->height;
	return 0;
}

int height_help(Node* a) {
	return 1 + max(h(a->left), h(a->right));
}

Node* RR(Node* y) {
	Node* x = y->left;
	Node* z = x->right;
	
	x->right = y;
	y->left = z;
	
	y->height = height_help(y);
	x->height = height_help(x);
	
	y->left_child = x->right_child;
	x->right_child = 1 + y->left_child + y->right_child;
	
	return x;
}

Node* LR(Node* y) {
	Node* x = y->right;
	Node* z = x->left;
	
	x->left = y;
	y->right = z;
	
	y->height = height_help(y);
	x->height = height_help(x);
	
	y->right_child = x->left_child;
	x->left_child = 1 + y->left_child + y->right_child;
	
	return x;
}

int getBalance(Node* n) {
	if(!n)
		return 0;
	return h(n->left) - h(n->right);
}

Node* insert(Node* n, int k) {
	if(!n) {
		Node* aux = new Node();
		
	    aux->key = k;
	    aux->left = aux->right = NULL;
	    aux->height = aux->count = 1;
	    aux->left_child = aux->right_child = 0;
	    return aux;		
	}
	
	if(n->key == k) {
		n->count++;
		return n;
	}
	
	if(n->key > k)
		n->left = insert(n->left, k);
	else if(n->key < k)
		n->right = insert(n->right, k);
	else
		return n;
		
	n->height = height_help(n);
	
	if(n->right)
		n->right_child = 1 + n->right->right_child + n->right->left_child;
	
	if(n->left)
		n->left_child = 1 + n->left->right_child + n->left->left_child;

	int bal = getBalance(n);
	if(bal > 1 && k < n->left->key)
		return RR(n);
	if(bal < -1 && k > n->right->key)
		return LR(n);
	if(bal > 1 && k > n->left->key) {
		n->left = LR(n->left);
		return RR(n);
	}
	if(bal < -1 && k < n->right->key) {
		n->right = RR(n->right);
		return LR(n);
	}

	//else everything...
	return n;
}

Node* getMin(Node* n) {
	Node* aux = n;
	
	while(aux->left)
		aux = aux->left;
	return aux;
}

bool exists(Node* rt, int k) {
	if(!rt)
		return false;
	if(rt->key == k)
		return true;
	if(rt->key < k)
		return exists(rt->right, k);
	else
		return exists(rt->left, k);		

}

int find_index(Node* rt, int k) {
	if(rt->key == k)
		return 1 + rt->left_child;
	else if(rt->key < k)
		return 1 + rt->left_child + find_index(rt->right, k);
	else
		return find_index(rt->left, k);
}

int main() {
	int command, i, Q, value;
	Node* root = NULL;
	// Q = number of queries
	// value = parameter of insert/index find
	//cin >> Q;
	scanf("%d", &Q);
	for(i=0; i<Q; i++) {
		//cin >> command >> value;
		scanf("%d %d", &command, &value);
		
		if(command==1) {
		//insert x to the list	
			root = insert(root, value);
		} else {
		// find x index on the list on ascending order
			if(exists(root, value))
				printf("%d\n", find_index(root, value));
			else
				printf("Data tidak ada\n");		
		}
	}
	return 0;
}
