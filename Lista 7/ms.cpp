#include <iostream>

#define MAX_N 16

using namespace std;

bool isPrime[] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0};
unsigned int primes[] = {2,3,5,7,11,13,17,19,23,29,31};
bool wasVisited[MAX_N+1] = {0};
int circularArray[MAX_N+1] = {0};

int try_next(int left, int x, int n) {
	int i;
	for(i=2; i<=n; i++) {
		if(i!=left && !wasVisited[i]) {
			
			if(isPrime[left+i])
				return i;
			
		}
	}
	
	return -1;
}

void try_all(int left, int n) {
	int i, count=2, keeper;
	circularArray[2] = left;
	wasVisited[left] = 1;
	
	for(i=2; i<=n && count<n; i++) {
		keeper = try_next(left, i, n);
		
		if(keeper==-1) return;
		else {
			wasVisited[keeper] = 1;
			circularArray[++count] = keeper;
			left = keeper;
		}
	}
	
	for(i=0; i<=n; i++)
		printf("%d ", circularArray[i]);
}

void handler(int x, int n) {
	int i;
	
	for(i=2; i<=n; i++)
		wasVisited[i] = circularArray[i] = 0;
		
	for(i=2; i<=n; i++) {
		
		if(isPrime[i+1]) {
			try_all(i, n);
		}
		
		
	}
}

int main() {
	int N, i=1, j;
	wasVisited[1] = circularArray[1] = 1;
	while(scanf("%d", &N)!=EOF) {		
		
		if(i>1) {
			printf("\n");
			//for(j=0; j<=N; j++)
			//	circularArray[j] = wasVisited[j] = 0;
		}
		
		printf("Case %d:\n", i++);
		handler(1, N);
	}
	
	return 0;
}
