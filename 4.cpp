#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , a[2050] , ct , f , q[40][2] , g , t[70] , p;

void ins(int i , int j)
{
	t[q[j][1]-1] = 0;
	t[a[i]] = j+1;
	q[j][0] = 2+f;
	q[j][1] = a[i]+1;
	g = (j+1)%32;
	p = 1;
}

int main()
{
	freopen("test.txt","r",stdin);
	scanf("%d",&n);
	for (int i = 1 ; i <= n ; i++)
	{ 
		scanf("%d",&a[i]);
		if (rand()%100 < 30) f = 1;
		else f = 0;
		if (!q[g][1])
		{
			t[a[i]] = g+1;
			q[g][0] = 2+f;
			q[g][1] = a[i]+1;
			g = (g+1)%32;
			continue;
		}
		if (t[a[i]])
		{
			q[t[a[i]]-1][0] = 2+f;
			continue;
		}
		ct++;
		p = 0;
		for (int j = g , h = 0 ; h < 32 ; j = (j+1)%32 , h++)
		{
			if (!q[j][0])
			{
				ins(i,j);
				break;
			}
		}
		if (p) continue;
		for (int j = g , h = 0 ; h < 32 ; j = (j+1)%32 , h++)
		{
			if (q[j][0] == 1)
			{
				ins(i,j);
				break;
			}
			if (q[j][0] >= 2) q[j][0] -= 2;
		}
		if (p) continue;
		for (int j = g , h = 0 ; h < 32 ; j = (j+1)%32 , h++)
		{
			if (!q[j][0])
			{
				ins(i,j);
				break;
			}
		}
		if (p) continue;
		for (int j = g , h = 0 ; h < 32 ; j = (j+1)%32 , h++)
		{
			if (q[j][0] == 1)
			{
				ins(i,j);
				break;
			}
		}
	}
	printf("%.2lf%\n",(double)ct*(double)100/(double)n);
	return 0;
}
