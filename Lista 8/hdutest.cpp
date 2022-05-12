#include <iostream>

using namespace std;

int cents[5] = {50, 25, 10, 5, 1};

int coins(int n) {
	
	int i50, cont, max_coins[5]={0};
	
	for(i50=0; i50<5; i50++) {
		cont = n;
		
		while(cont >= cents[i50]) {
			max_coins[i50]++;
			cont-=cents[i50];
		}	
		//printf("%d\n", max_coins[i]);
	}
	
	cont=0;
	
	int i25, i10, i5, i1;
	
	for(i1=0; i1<=max_coins[4]; i1++) {
		if(i1==n) {
			cont++;
			continue;
		} else if(i1>n) break;
		
		for(i5=0; i5<=max_coins[3]; i5++) {
			if(i1+i5*5==n){
				cont++;
				continue;
			} else if(i1+i5*5>n) break;
			
			for(i10=0; i10<=max_coins[2]; i10++) {
				if(i1+i5*5+i10*10==n){
					cont++;
					continue;
				} else if(i1+i5*5+i10*10>n) break;
				
				for(i25=0; i25<=max_coins[1]; i25++) {
					if(i1+i5*5+i10*10+i25*25==n){
						cont++;
						continue;
					} else if(i1+i5*5+i10*10+i25*25>n) break;
					
					for(i50=0; i50<=max_coins[0]; i50++) {
						if(i1+i5*5+i10*10+i25*25+i50*50==n) cont++;
						else if(i1+i5*5+i10*10+i25*25+i50*50>n) break;
						
					}
				}				
			}
		}
	}
	
	return cont;
}

int main() {
	int n;
	
	while(scanf("%d", &n))
		printf("%d\n", coins(n));
	
	return 0;
}
