#include <iostream>
using namespace std;

int arr[200002];
int size_track = 0, value;

void quicksort(int vet[], int comeco, int fim) {
    int pivot, aux;
	int i, j;

	pivot = vet[(comeco+fim)/2];
	i = comeco;
	j = fim;

	while(i <= j){
		while(vet[i] < pivot)
			i++;

		while(vet[j] > pivot)
			j--;

		if(i <= j){
			aux = vet[i];
			vet[i] = vet[j];
			vet[j] = aux;
			i++;j--;
        }
	}

	if(j > comeco)
		quicksort(vet, comeco, j);

	if(i < fim)
		quicksort(vet, j+1, fim);

}

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

void insert() {
	arr[size_track++] = value;
}

void where_is() {
	quicksort(arr, 0, size_track+1);
	int ans = fst_bin_search(0, size_track)+1;
	if(ans>0)
		cout << ans << endl;
	else
		cout << "Data tidak ada" << endl;
}

int main() {
	int command, i, Q;
	// Q = number of queries
	// value = parameter of insert/index find
	cin >> Q;
	for(i=0; i<Q; i++) {
		cin >> command >> value;
		
		if(command==1) {
		//insert x to the list	
		insert();
		} else {
		// find x index on the list on ascending order
		where_is();
		}
	}
	
	return 0;
}
