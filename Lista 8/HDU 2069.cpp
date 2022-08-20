#include <iostream>

using namespace std;

#define MAX_N 7500

int results[MAX_N], coins[5]={50, 25, 10, 5, 1};

void gen_results() {
	int i, j;
	results[0]=1;
	
	for(i=0; i<5; i++)
		for(j=coins[i]; j<MAX_N; j++)
			results[j] += results[j - coins[i]];
	
}

int main() {
	int n;
	
	gen_results();
	
	while(scanf("%d", &n)!=EOF)
		printf("%d\n", results[n]);
	
	return 0;
}
