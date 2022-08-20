#include <iostream>

using namespace std;

#define MAX_N 7500

int results[MAX_N]={0}, coins[5]={1,5,10,25,50}, biggest_N=1;

void gen_results(int n) {	
	if(n > biggest_N) {
		int i, j;
		biggest_N = n;
		for(i=0; i<5; i++)
			for(j=biggest_N; j<n; j++)
				results[j] += results[j - coins[i]];
		biggest_N=n;	
			
	}	
}

int main() {
	int n;
	results[0]=1;
	while(scanf("%d", &n)!=EOF) {
		gen_results(n);
		printf("%d\n", results[n]);
	}
	
	return 0;
}
