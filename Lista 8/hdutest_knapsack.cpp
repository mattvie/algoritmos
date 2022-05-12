#include <iostream>

using namespace std;

#define MAX_N 2010

int w[5]={1,5,10,25,50}, v[5]={1,1,1,1,1}, F[10][10];

void knapsack(int N, int W) {
	int i, j;
	
	for(i=0; i<=N; i++) {
		for(j=0; j<=W; j++) {
		//cout << "w[i] = " << w[i] << ". v[i] = " << v[i] << endl;
		if(i==0 || j==0)
			F[i][j]=0;
		else if(w[i]<=j)
			F[i][j] = max( F[i-1][j], v[i]+F[i-1][j - w[i]]);
		else
			F[i][j] = F[i-1][j];
		}		
	}
	
	printf("%d\n", F[N][W]);
}

int main() {
	int S, N, i;
	
	knapsack(11, 5);
	
	return 0;
}
