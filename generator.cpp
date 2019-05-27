#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int N = 64;
int p = 0; 
int e = 32; 
int m = 16; 
int t = 50 , r;
int g = 128;

int main()
{
	freopen("test.txt","w",stdout);
	printf("%d\n",g*m);
	while (g--)
	{
		r = rand()%100;
		if (r >= t) p = rand()%N;
		else p = (p+1)%N;
		for (int i = 1 ; i <= m ; i++)
			printf("%d\n",(p+rand()%(e+1))%N);
	}
	return 0;
}
