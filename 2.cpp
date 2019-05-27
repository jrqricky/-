#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , a[2050] , f[70] , ct , q[2050] , tp;

int main()
{
	freopen("test.txt","r",stdin);
	scanf("%d",&n);
	for (int i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		if (f[a[i]]) continue;
		if (tp >= 32)
		{
			ct++;
			f[q[tp-31]] = 0;
		}
		f[a[i]] = 1;
		q[++tp] = a[i];
	}
	printf("%.2lf%\n",(double)ct*(double)100/(double)n);
	return 0;
}
