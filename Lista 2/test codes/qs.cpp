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
	arr[0] = 2;
	arr[1] = 3;
	arr[2] = 1;
	arr[3] = 7;
	arr[4] = 12;
	arr[5] = 5;
	
	quickSort(arr, 0, 5);
	
	for(i=0;i<6; i++)
		cout << arr[i] << " ";
	
	
	return 0;	
}

