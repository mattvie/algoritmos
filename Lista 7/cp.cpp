#include <iostream>
#include <vector>
using namespace std;

int vc[] = {2,3,5,7,11,13,17,19,23,29,31};
bool checkPrime(int a)
{
    for (int i = 0; i < 1; i++){
        if(vc[i] == a) return  true;
    }
    return false;
}

int main() {
	for(int i = 0; i< 20; i++) {
		if(checkPrime(i)) printf("%d\n", i);
		printf("ugly %d\n", i);
	}
	
}
