#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct node
{
	int num, count;
}p[1005];

int set(int n)
{
	for(int i = 0;i < n;i++)
		p[i].count = 0, p[i].num = i+1;
}
int cmp(struct node x, struct node y)
{
	return x.count > y.count;
}
int main()
{
	int n, k, m, l[505], r[505], flag[1005];
	while(~scanf("%d%d", &n, &k))
	{
		set(n);
		memset(flag, 0, sizeof(flag));
		while(k--)
		{
			int m, temp;
			scanf("%d", &m);
			for(int i = 0;i < m;i++)
				scanf("%d", &l[i]);
			for(int i = 0;i < m;i++)
				scanf("%d", &r[i]);
			char com[5];
			scanf("%s", com);
			if(com[0] == '=')
			{
				for(int i = 0;i < m;i++)
					flag[l[i]-1] = flag[r[i]-1] = 1;
			}
			else if(com[0] == '<')
			{
				for(int i = 0;i < m;i++)
					p[l[i]-1].count--;
				for(int i = 0;i < m;i++)
					p[r[i]-1].count++;
			}
			else if(com[0] == '>')
			{
				for(int i = 0;i < m;i++)
					p[l[i]-1].count++;
				for(int i = 0;i < m;i++)
					p[r[i]-1].count--;
			}
		}
		int v = 0, ans;
		for(int i = 0;i < n;i++)
			if(!flag[i])
			{
				v++;
				ans = i+1;
			}
		if(v == 1)
		{
			printf("%d\n", ans);
			continue;
		}
		for(int i = 0;i < n;i++)
			if(p[i].count < 0)
				p[i].count = 0-p[i].count;
		sort(p, p+n, cmp);
		v = 0;
		for(int i = 0;i < n;i++)
			if(p[i].count == p[0].count)
				v++;
		if(v > 1)
			printf("0\n");
		else
			printf("%d\n", p[0].num);
	}
	return 0;
}