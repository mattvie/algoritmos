#include <iostream>
using namespace std;

int arr[100001], value;
unsigned int N, Q, i;

int fst_bin_search(int left, int right) {
	if (left>right)
		return -1;
	
	int middle=(left+right)/2;
	if(arr[middle]==value) {
		
		if(!middle || arr[middle-1]!=value)
			return middle;
		return fst_bin_search(left, middle-1);
	}
	
	if(arr[middle]>value)
		return fst_bin_search(left, middle-1);
	return fst_bin_search(middle+1, right);
}

int main() {
	// First line contains N Q, number of elements in the array and number of queries to follow
	// 0 < N <= 10^5, 0 < Q <= 5*10^5
	//cin >> N >> Q;
	scanf ("%d %d", &N, &Q);
	for(i=0; i<N; i++)
		//cin >> arr[i];
		scanf ("%d", &arr[i]);
	
	for(i=0; i<Q; i++) {
		//cin >> value;
		//cout << fst_bin_search(0, N-1) << endl;
		scanf ("%d", &value);
		printf ("%d\n", fst_bin_search(0, N-1));
	}
	
	return 0;
}
