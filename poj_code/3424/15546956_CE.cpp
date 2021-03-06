#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
#define N 110
#define M 1000000
set <string> ans;
set <string>::iterator iter;
int n;
struct node
{
	int x, y;
	node(){}
	node(int x, int y) : x(x), y(y) {}
	node operator + (const node &b){
		return node(x+b.x, y+b.y);
	}
	void pr(){
		printf("%d %d\n", x, y);
	}
}p[N], o, f;
char key[3][4] = {
	"123", "456", "789"
};
bool out(node a){
	return a.x >= 300 || a.y >= 300 || a.x < 0 || a.y < 0;
}
bool solve(){
	if(out(f)) return false;
	for(int i = 0;i < 300;i++)
		for(int j = 0;j < 300;j++){
			int flag = 0;
			string tp = "";
			// printf("i j %d %d\n", i, j);
			for(int k = 0;k < n;k++){
				node q = p[k]+node(i,j);
				if(out(q)){
					flag = 1; break;
				}
				tp += key[q.y/100][q.x/100];
				// printf("%d %d %c\n", q.y/100, q.x/100, key[q.y/100][q.x/100]);
				// tp += key[q.x/100][q.y/100];
			}
			if(!flag){
				// sort(tp.begin(), tp.end());
				ans.insert(tp);
			}
		}
	return true;
}
int main()
{
	while(~scanf("%d", &n)){
		ans.clear();
		o = node(M, M); f = node(-1, -1);
		for(int i = 0;i < n;i++){
			scanf("%d%d", &p[i].x, &p[i].y);
			p[i].y = 2000-p[i].y;
			o.x = min(o.x, p[i].x);
			o.y = min(o.y, p[i].y);
			f.x = max(f.x, p[i].x);
			f.y = max(f.y, p[i].y);
		}
		// o.pr(), f.pr();
		for(int i = 0;i < n;i++){
			p[i].x -= o.x;
			p[i].y -= o.y;
			// p[i].pr();
		}
		f.x -= o.x; f.y -= o.y;
		if(!solve()) printf("NONE\n");
		else {
			for(iter = ans.begin();iter != ans.end();iter++)
				printf("%s\n", iter->c_str());
		}
	}
	return 0;
}