#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , a[2050] , p[70] , ct , si , f , g , q[2050][2] , tp , t[70];
set<int> st[2];

int main()
{
	freopen("test.txt","r",stdin);
	scanf("%d",&n);
	for (int i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		if (rand()%100 < 30) f = 1;
		else f = 0;
		if (t[a[i]])
		{
			q[t[a[i]]][1] = f;
			continue;
		}
		for (g = 0 ; g <= 1 ; g++)
			if (st[g].find(p[a[i]]) != st[g].end())
			{
				st[g].erase(st[g].find(p[a[i]]));
				si--;
				if (tp >= 24)
				{
					t[a[q[tp-23][0]]] = 0;
					st[q[tp-23][1]].insert(q[tp-23][0]);
					si++;
				}
				break;
			}
		if (g > 1)
		{
			if (tp >= 24)
			{
				if (si == 8)
				{
					ct++;
					if (st[0].size() > 0) st[0].erase(st[0].begin());
					else st[1].erase(st[1].begin());
					si--;
				}
				t[a[q[tp-23][0]]] = 0;
				st[q[tp-23][1]].insert(q[tp-23][0]);
				si++;
			}
		}
		p[a[i]] = i;
		q[++tp][0] = i;
		q[tp][1] = f;
		t[a[i]] = tp;
	}
	printf("%.2lf%\n",(double)ct*(double)100/(double)n);
	return 0;
}
