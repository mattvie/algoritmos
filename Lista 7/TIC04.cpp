#include <iostream>

#define MAX_N 8

using namespace std;

int board[MAX_N+1][MAX_N+1];

bool PositionIsValid(int a, int k, int n) {
	int i, j;
	
	// Procurando na coluna K
	for (i=0; i<a; i++)
        if (board[i][k]=='Q') return false;
    
    // Procurando nas diagonais
    for (i=a, j=k; i>=0 && j<n; i--, j++)
        if (board[i][j]=='Q') return false;
        
    for (i=a, j=k; i>=0 && j>=0; i--, j--)
        if (board[i][j]=='Q') return false;
        
    return true;
}

void print_board(int n) {
	int i, j;
	
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++)
			printf("%c ", board[i][j]);
		printf("\n");
	}
	
	printf("\n");
}

void n_Queen(int a, int n) {
	
	if(a==n)		
		print_board(n);
		
	else {
		int i;
		
		for(i=0; i<n; i++) {
			if(PositionIsValid(a, i, n)) {
				board[a][i] = 'Q';
				n_Queen(a+1, n);
            	board[a][i] = '-';
			}			
		}
	}
}

void n_Queen_Handler(int a, int n) {
	if (n == 1)
		printf("Q\n");
    else if (n < 4)
    	printf("Not Possible\n");
    else
        n_Queen(0, n);
}

int main() {	
	int N, i, j;
	
	while(scanf("%d", &N)!=EOF) {
		
		for(i=0; i<N; i++)
			for(j=0; j<N; j++)
				board[i][j]='-';
		
		n_Queen_Handler(0, N);
	}
	
	return 0;
}
