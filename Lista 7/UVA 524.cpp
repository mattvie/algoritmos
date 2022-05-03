#include <iostream>

#define MAX_N 16

using namespace std;

bool isPrime[] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0};
bool visits[MAX_N+1];
int path[MAX_N+1] = {0};
int n=0;

int path_array[][7] = {
	{0,0,0,0,0,0,-1}, //0
	{2,4,6,10,12,16,-1}, //1
	{1,3,5,9,11,15,-1}, //2
	{2,4,8,10,14,16,-1}, //3
	{1,3,7,9,13,15,-1}, //4
	{2,6,8,12,14,-1,0}, //5
	{1,5,7,11,13,-1,0}, //6
	{4,6,10,12,16,-1,0}, //7
	{3,5,9,11,15,-1,0}, //8
	{2,4,8,10,14,-1,0}, //9
	{1,3,7,9,13,-1,0}, //10
	{2,6,8,12,-1,0,0}, //11
	{1,5,7,11,-1,0,0}, //12
	{4,6,10,16,-1,0,0}, //13
	{3,5,9,15,-1,0,0}, //14
	{2,4,8,14,16,-1,0}, //15
	{1,3,7,13,15,-1,0}}; //16

void path_finding(int x, int steps) {
	cout << "";
	int i = 0, target;
	if(steps<n) {
		while(path_array[x][i]!=-1 && path_array[x][i]<=n) {
			target = path_array[x][i];
			
			if(!visits[target] && isPrime[target+x]) {
				visits[target] = true;
				path[steps+1] = target;
				
				path_finding(target, steps+1);
				
				visits[target] = false;
				//path[steps+1] = 0;
			}
						
			
			i++;
		}		
	} else if(isPrime[x+1]) {
		printf("1");
		for(i=2; i<=n; i++)
			printf(" %d", path[i]);
		printf("\n");	
	}
}

int main() {
	int i=1, j;
	visits[1] = true;
	
	while(scanf("%d", &n)!=EOF) {		
		
		if(i>1) {
			printf("\n");
			for(j=0; j<=n; j++)
				visits[i] = false;
		}

		printf("Case %d:\n", i++);
		path_finding(1, 1);
	}
	
	return 0;
}
