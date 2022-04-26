#include <iostream>
#define SSIZE 1002

using namespace std;

class Stack {
	private:
		int top;
		int arr[SSIZE];	
	
	public:
		Stack()	{
			top = -1;
			for (int i = 0; i < SSIZE; i++) {
				arr[i] = 0;
			}
		}
		
		bool isEmpty() {
			if (top == -1)
				return true;
			else
				return false;
		}
		
		bool isFull() {
			if (top == SSIZE-1)
				return true;
			else
				return false;
		}
		
		void push(int data) {
			if (isFull()) {
				cout << "Stack overflow." << endl;
			} else {
				top++;
				arr[top] = data;
			}
		}
		
		int pop() {
			if (isEmpty()) {
				cout << "Stack underflow." << endl;
				return 0;
			} else {
				int d = arr[top];
				arr[top] = 0;
				top--;
				return d;
			}
		}
		
		int count() {
			return (top + 1);
		}
		
		int peek(int pos) {
			if (isEmpty()) {
				cout << "Stack underflow." << endl;
				return 0;
			} else
				return arr[pos];
		}
		
		int getTop() {
			return peek(top);
		}
};

int main() {
	
	int q[1010], n, i, k, thepop;
	
	while(cin>>n && n!= 0) {
		for (i = 0; i<n; i++)
			cin>>q[i];
		
		k = i = 0;
		
		Stack st;
		
		while (i<n) {
			while(!st.isEmpty() && st.getTop() == k + 1) {
				k++;
				thepop=st.pop();
			}
			
			if (q[i] != k + 1)
				st.push(q[i]);
			else
				k++;
				
			i++;						
		}
		
		while(!st.isEmpty() && st.getTop() == k + 1) {
				k++;
				thepop=st.pop();
		}
		
		if(k==n) cout << "yes" << endl;
		else cout << "no" << endl;
		
	}
	
	return 0;
}

