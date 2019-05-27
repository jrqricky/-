#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , a[2050] , f[70] , ct;
set<int> st;

int main()
{
	freopen("test.txt","r",stdin);
	scanf("%d",&n);
	for (int i = 1 ; i <= n ; i++)
	{ 
		scanf("%d",&a[i]);
		if (f[a[i]]) st.erase(st.find(f[a[i]]));
		if (st.size() == 32)
		{
			ct++;
			f[a[*st.begin()]] = 0;
			st.erase(st.begin());
		}
		f[a[i]] = i;
		st.insert(i);
	}
	printf("%.2lf%\n",(double)ct*(double)100/(double)n);
	return 0;
}
