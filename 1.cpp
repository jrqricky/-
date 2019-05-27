#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , a[2050] , p[70] , ne[2050] , ct;
set<int> st;

int main()
{
	freopen("test.txt","r",stdin);
	scanf("%d",&n);
	for (int i = 1 ; i <= n ; i++)
		scanf("%d",&a[i]);
	for (int i = 0 ; i < 64 ; i++)
		p[i] = n+i+1;
	for (int i = n ; i >= 1 ; i--)
	{
		ne[i] = p[a[i]];
		p[a[i]] = i;
	}
	for (int i = 1 ; i <= n ; i++)
	{
		if (st.find(i) != st.end()) 
		{
			st.erase(st.find(i));
			st.insert(ne[i]);
			continue;
		}
		if (st.size() == 32)
		{
			ct++;
			st.erase(prev(st.end()));
		}
		st.insert(ne[i]);
	}
	printf("%.2lf%\n",(double)ct*(double)100/(double)n);
	return 0;
}
