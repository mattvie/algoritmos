#include <iostream>

#define MAX_N 16

using namespace std;

bool isPrime[] = {0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0};
unsigned int primes[] = {2,3,5,7,11,13,17,19,23,29,31};
bool wasVisited[MAX_N+1];
int circularArray[MAX_N+1];

void backtrack(int x, int n) {
	//printf("a");
	int i, target;
	if(x==n) {
	//printf("b");
		target = circularArray[x]+circularArray[x+1];
		
		if(primes[target]) {
		//printf("c");
			for(i=1; i<n; i++)
				printf("%d ", circularArray[i]);
			printf("%d\n", circularArray[n]);
		}
		
		return;
	}
	
	for(i=2; i<=n; i++) {
		
		target = i + circularArray[x];
		if(!wasVisited[i] && primes[target]) {
			
			wasVisited[i] = 1;
			circularArray[x+1] = i;
			backtrack(x+1, n);
			wasVisited[i] = 0;
		}
	}
}

int main() {
	int N, i=1, j;
	wasVisited[1] = 1;
	while(scanf("%d", &N)!=EOF) {		
		
		if(i>1) {
			printf("\n");
			for(j=0; j<=N; j++)
				circularArray[j] = wasVisited[j] = 0;
		}
		
		circularArray[1] = circularArray[N] = 1;
		printf("Case %d:\n", i++);
		backtrack(1, N);
	}
	
	return 0;
}
