#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[5] = { 1,5,10,25,50 }; ///??5???????? 
int dp[110][260];///??dp[i][v] ?i????????v????  
int main()
{
	int n;
	while (cin >> n)
	{
		memset(dp, 0, sizeof(dp)); //???dp??
		dp[0][0] = 1;///??
		for (int i = 0; i < 5; i++)
		{
			for (int k = 1; k <= 100; k++) //k???
			{
				for (int v = a[i]; v <= n; v++)
				{
					dp[k][v] += dp[k - 1][v - a[i]];//??????
				}                        
			}
		}
		int ans = 0;
		for (int i = 0; i <= 100; i++)
		{
			ans += dp[i][n];
		}
		cout << ans << endl;
	}
	return 0;
}
