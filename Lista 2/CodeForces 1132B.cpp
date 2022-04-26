#include <iostream>
using namespace std;

unsigned int n, i, m, arr[300001], qrr;
long long int ans=0;

void quickSort(unsigned int vet[], int comeco, int fim) {
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
		quickSort(vet, comeco, j);

	if(i < fim)
		quickSort(vet, j+1, fim);
}

int main() {
	// n = number of chocolate bars
	cin >> n;
	
	for(i=0; i<n; i++) {
		cin >> arr[i];
		ans+=arr[i];
	}
	
	// sort(a);
	quickSort(arr, 0, n-1);
		
	// m = number of coupons owned
	cin >> m;
	
	for(i=0; i<m; i++) {
		cin >> qrr;
		cout << ans - arr[n-qrr] << endl;
	}
	
	return 0;
}
