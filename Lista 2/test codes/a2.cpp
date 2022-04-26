#include <iostream>
using namespace std;

int arr[100001], value;
unsigned int N, Q, i;

int real_bin_search() {
	int left=-1, right=N, middle;
	
	while(left+1!=right) {
		middle=(left+right)/2;
		
		if(value < arr[middle])
			right = middle;
		if(value > arr[middle])
			left = middle;	
		if(value == arr[middle])
			return middle;
	}
	
	return -1;
}

int bin_search() {
	if(arr[0]==value)
		return 0;
	else
		return real_bin_search();
}

int main() {
	// First line contains N Q, number of elements in the array and number of queries to follow
	// 0 < N <= 10^5, 0 < Q <= 5*10^5
	cin >> N >> Q;
	
	for(i=0; i<N; i++)
		cin >> arr[i];
	
	for(i=0; i<Q; i++) {
		cin >> value;
		cout << bin_search() << endl;
	}
	
	return 0;
}
