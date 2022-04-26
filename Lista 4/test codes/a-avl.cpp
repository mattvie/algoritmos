#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

//#define DATASIZE 10000

//Node vNode[DATASIZE];
//int vData[DATASIZE];

class Node {
	public:
		int data;
		Node* left;
		Node* right;
			
		Node() {
            data = 0;
            left = right = NULL;
		}
			
		Node(int d) {
		    data = d;
            left = right = NULL;
		}
};

// ON BST, THE N->RIGHT->DATA >= N->DATA
//         AND N->LEFT->DATA < n->DATA

class BST {
	public:
    	BST() {
            root = NULL;
            node_count = 0;
            c=0;
            flag = false;
        }

        BST(Node* n) {
            root = n;
            node_count = 1;
            c=0;
            flag = false;
        }
        
        void insert(int d) {
        	root = bst_insert(root, d);
        	node_count++;
		}
		
		void inorder_index(int x) {
			c=0;
			flag = false;
			bst_index(root, x);
		}
	
    private:
        Node* root;
        // Counts number of elements
        int node_count;
		int c;
		bool flag;
		
        Node* bst_insert(Node* rt, int d) {
            if(rt == NULL) {
                rt = new Node();
                rt->data = d;
                rt->left = rt->right = NULL;
            } else if(d < rt->data)
                rt->left = bst_insert(rt->left, d);
            else
                rt->right = bst_insert(rt->right, d);
            return rt;
        }		
		
		void bst_index(Node* rt, int x) {
			if(rt) {
				bst_indexhelp(rt->left, x);
				//cout << rt->data << " ";
				if(rt->data == x) {
					cout << c+1;
					flag = true;
					return;
				} else
					c++;
				bst_indexhelp(rt->right, x);
			}
			
			if(flag==false)cout << "Data tidak ada";
		}
		
		void bst_indexhelp(Node* rt, int x) {
			if(rt) {
				bst_indexhelp(rt->left, x);
				//cout << rt->data << " ";
				if(rt->data == x) {
					cout << c+1;
					flag = true;
					return;
				} else
					c++;
				bst_indexhelp(rt->right, x);
			}
		}
};

int main() {
	int command, x, i, Q; //how many queries
	BST tree;
	
	cin >> Q;
	
	for(i=0; i<Q; i++) {
		cin >> command >> x;
		
		if(command==1) {
		//insert x to the list	
			tree.insert(x);
		} else {
		// find x index on the list on ascending order
			tree.inorder_index(x);
		}
	}
	
	return 0;
}
