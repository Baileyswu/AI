/*--------------------------------------------
 * File Name: POJ 3696
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-10-02 22:16:59
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 44725
#define LL long long
#define MOD 150000
LL gcd(LL a, LL b)
{
	return b == 0?a:gcd(b, a%b);
}
LL hs[MOD],head[MOD],next[MOD],id[MOD],top;
void insert(LL x, LL y)
{
	//printf("%12lld %lld\n", x, y);
    LL k = x%MOD;
    hs[top] = x, id[top] = y, next[top] = head[k], head[k] = top++;
}
LL find(LL x)
{
    LL k = x%MOD;
    for(LL i = head[k]; i != -1; i = next[i])
        if(hs[i] == x)
            return id[i];
    return -1;
}
LL mult(LL a, LL b, LL c)
{
    a %= c; b %= c;
    LL ret = 0, tmp = a;
    while(b)
    {
        if(b & 1LL)
        {
            ret += tmp;
            if(ret > c) ret -= c;
        }
        tmp <<= 1;
        if(tmp > c) tmp -= c;
        b >>= 1;
    }
    return ret%c;
}
LL BSGS(LL a,LL b,LL c)
{
	//printf("a b c %lld %lld %lld\n", a, b, c);
    memset(head, -1, sizeof(head));
    top = 1;
    /*if(b == 1)
        return 0;*/
    LL m = sqrt(c*1.0), j;
    long long x = 1, p = 1;
    //printf("insert %lld\n", m);
    for(LL i = 0; i < m; ++i, p = p*a%c)
    {
        insert(p*b%c, i);//存的是(a^j*b, j)
    }
    //printf("insert ok \n");
    for(long long i = m; ;i += m)
    {
        if( (j = find(x = mult(x,p,c))) != -1 )
            return i-j;  //a^(ms-j)=b(mod c)
    	//printf("%lld %lld %lld\n", i, j, x);
        if(i > c)
            break;
    }
    return 0;
}

int main()
{
	LL o = 0;
	LL n;
	while(scanf("%lld", &n), n)
	{
		printf("Case %d: ", ++o);
		LL m = n/gcd(n, 8)*9;
		if(gcd(m,10) != 1)
		{
			printf("0\n");
			continue;
		}
		printf("%lld\n", BSGS(10,1,m));
	}
	return 0;
}