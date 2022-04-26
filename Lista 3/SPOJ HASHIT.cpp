#include <iostream>
using namespace std;
#define SIZE 101
string table[SIZE];

int hash_function(string k) {
	int sum=0, i;
	
	for(i=0; i<k.length(); i++)
		sum+=k[i]*(1+i);
				
	return (19*sum) % SIZE;
}	

int hash_add(string k) {
	int h2, h = hash_function(k);
	
	// Check for duplicates
	int i;
	for(i=0; i<=19; i++) {
		h2 = (h + (23*i) + (i*i)) % 101;
		
		if(table[h2]==k)
			return 0;
	}
	
	// Checing for empties
	for(i=0; i<=19; i++) {
		h2 = (h + (23*i) + (i*i)) % 101;
		
		if(table[h2]=="") {
			table[h2] = k;
			return 1;
		}
	}
	
	// If nothing else...
	return 0;
}

int hash_del(string k) {
	int i;
	for(i=0; i<SIZE; i++){
		
		// If key is found, remove it
		if(table[i] == k) {
			table[i] = "";
			return 1;
		}
	}
	
	// If nothing else...
	return 0;
}

void hash_clear() {
	int i;
	for(i=0; i<SIZE; i++)
		table[i]="";
}

string rip_key(string k) {
	int i;
	string r="";
	
	for(i=4; i<k.length(); i++)
		r+=k[i];
		
	return r;
}

int main() {
	int N, i, M, count, j;
	string command;
	
	cin >> N;
	
	for(i=0; i<N; i++) {
		cin >> M;
		
		count = 0;
		
		// clear hash table here
		hash_clear();
		
		// chosing operations
		for(j=0; j<M; j++) {
			cin >> command;
			
			//if true ADD else DEL
			if(command[0]=='A')
				count+=hash_add(rip_key(command));
			else
				count-=hash_del(rip_key(command));
		}
		
		// Print number of entries
		cout << count << endl;
		
		// Print hash table
		for(j=0; j<SIZE; j++) {
			if(table[j]!="")
				cout << j << ":" << table[j] << endl;
		}
	}
	
		
	return 0;
}
