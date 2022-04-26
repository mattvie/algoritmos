#include <iostream>
#include <stdio.h>
	
using namespace std;
	
	class Node {
		public:
			string data;
			Node* next;
			Node* previous;
			
			Node() {
			data = "";
			next = NULL;
			previous = NULL;
			}
			
			Node(string d) {
			data = d;
			}
	};
	
	class DoublyLinkedList {
		
		public:
			Node * head;
			int size;
			
			DoublyLinkedList() {
				head = NULL;
				size=0;
			}
			DoublyLinkedList(Node * n) {
				head = n;
				size=1;
			}
			
			void appendNode(Node* n) {
				if (head == NULL) {
					
					head = n;
					size++;
				} else {
					
					Node* ptr = head;
				    while (ptr->next != NULL)
				      ptr = ptr->next;
				    ptr->next = n;
				    n->previous = ptr;
				    size++;
				}
			}
			
			void prependNode(Node * n) {
				if (head == NULL) {
				    head = n;
				    size++;
				  } else {
				    head->previous = n;
				    n->next = head;
				    head = n;
				    size++;
				}
			}
			
			// Insert 'n' after 'd'
			void insertNodeAfter(Node * d, Node * n) {
				Node* ptr = d;
				Node* nextNode = ptr->next;
				
			    if (nextNode == NULL) {
			    	
			        ptr->next = n;
			        n->previous = ptr;
			        size++;
			    }
			    else {
			    	
			        n->next = nextNode;
			        nextNode->previous = n;
			        n->previous = ptr;
			        ptr->next = n;
					size++;
				}
			}
			
			
			void print() {
			  Node * temp = head;
			
			  while (temp != NULL) {
			    cout << temp->data;
			    temp = temp->next;
			  } 
			  //cout << "\nSize: " << size << endl;
			  cout << endl;
			}
			
			void listDelete() {
				Node *temp;
				while(head!=NULL) {
					temp = head;
					head = head->next;
					delete temp;
				}
			}
			
	};
	
	int main() {
	
	DoublyLinkedList list;
	string holder="";
	bool end=true;
	
	int c;
	c = getchar();
	
	// remeber to change '-' to EOF
	while(c!=EOF) {
		
		if(c=='\n') {
			// First of all, add the last holder string to the list
			Node *n = new Node();
			n->data = holder;
			holder="";
			
			if(end)
				list.appendNode(n);
			else
				list.prependNode(n);
			// Needs to set end as true, as the new list needs to start appending
			end=true;
			
			// Will print the word and start a new word
			list.print();
			
			// Will delete the list		
			list.listDelete();
			
		} else if(c==']') {
			// End key pressed
			// Will add holder to the list. Need to check if home or end key was last pressed
			Node *n = new Node();
			n->data = holder;
			holder="";
			if(end) {
				// End key was pressed last
				// No need to change end bool, since last the end key was the last pressed
				list.appendNode(n);
			} else {
				// Home key was pressed last
				// Needs to change the end bool to true, since the end key was last pressed
				list.prependNode(n);
				end=true;
			}
			
		} else if(c=='[') {
			// Home key pressed
			// Will add holder to the list. Need to check if home or end key was last pressed
			Node *n = new Node();
			n->data = holder;
			holder="";
			if(end) {
				// End key was the last one pressed
				// Need to change end to false, since now the home key will be the last one pressed
				list.appendNode(n);
				end= false;
			} else {
				list.prependNode(n);
			}
			
		} else {
			// Just letters and underscores
			holder+=c;
			
		}
		
		
		c = getchar();
	}
	
	return 0;
}

