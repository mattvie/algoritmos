#include <iostream>
using namespace std;

string rip_key(string k) {
	int i;
	string r="";
	
	for(i=4; i<k.length(); i++)
		r+=k[i];
		
	return r;
}

int main() {
	
	cout << rip_key("mateus viegas");
	
	return 0;
}
