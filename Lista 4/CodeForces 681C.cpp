#include <iostream>
using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
  
// A class for Min Heap
class MinHeap {
    int arr[100005]; // array of elements in the heap
    int heap_size; // number of elements in the heap
public:
    MinHeap() {
	    heap_size = 0;
	}
  
	bool empty() {
		if(heap_size)
			return false;
		return true;
	}
  
    int parent(int i) {
		return (i-1)/2;
	}
  
    int left(int i) {
		return (2*i + 1);
	}
  
    int right(int i) {
		return (2*i + 2);
	}
  
    // Returns the minimum key (key at root) from the heap
    int getMin() {
		return arr[0];
	}
	
	// Inserts a new key 'k'
	void insertKey(int k) {
	  
	    int i = heap_size++;
	    arr[i] = k;
	  
	    // fix heap (if needed)
	    while (i && arr[parent(i)]>arr[i]) {
	       swap(&arr[i], &arr[parent(i)]);
	       i = parent(i);
	    }
	}
	  
	// RemoveMin asked on question
	int removeMin() {
	    if (!heap_size)
	        return INT_MAX;
	    if (heap_size==1) {
	        heap_size--;
	        return arr[0];
	    }
	  
	    // Store the minimum value, and remove it from heap
	    int root = arr[0];
	    arr[0] = arr[--heap_size];
	    MinHeapify(0);
	    return root;
	}

	
	void MinHeapify(int i) {
		
	    int l = left(i);
	    int r = right(i);
	    int smallest = i;
	    
	    if (l<heap_size && arr[l]<arr[i])
	        smallest = l;
	    if (r<heap_size && arr[r]<arr[smallest])
	        smallest = r;
	    if (smallest!=i) {
	        swap(&arr[i], &arr[smallest]);
	        MinHeapify(smallest);
	    }
	}
};

char cmd_array[100005];
int data_array[100005];

int add(char c, int i, int count) {
	cmd_array[count] = c;
	data_array[count++] = i;
	return count++;
}

void resolve(int i) {
	if(cmd_array[i]=='r')
		cout << "removeMin" << endl;
	else if(cmd_array[i]=='i')
		cout << "insert " << data_array[i] << endl;
	else
		cout << "getMin " << data_array[i] << endl;
}

int main() {
	MinHeap h;
	int i, data;
	int count = 0;
	int n; // minimum possible number of records in the modified sequence of operations
	string cmd;
	
	cin >> n;
	
	for(i=0; i<n; i++) {
		cin>>cmd;
		
		if(cmd[0]=='i') {
			cin >> data;
			h.insertKey(data);
			count = add(cmd[0], data, count);
		} else if(cmd[0]=='g') {
			cin >> data;
			
			int a;
			while(!h.empty() && h.getMin()<data) {
				h.removeMin();
				count = add('r', 0, count);
			}
			
			if(h.empty() || h.getMin()>data) {
				h.insertKey(data);
				count = add('i', data, count);	
			}
			count = add(cmd[0], data, count);
		} else {
			// removeMin
			if(h.empty())
				count = add('i', -1, count);
			else
				h.removeMin();
			count = add(cmd[0], 0, count);
		}
	}
	
	cout << count << endl;
	
	for(i=0; i<count; i++) {
		resolve(i);
	}
	
	return 0;
}
