#include <bits/stdc++.h>

using namespace std;

#define inf 1<<30
#define mx 100005

typedef pair<int , int> ii;
typedef pair<int, ii> iii;

int arr[mx];

struct node{
	int l,r,lcnt,rcnt,maxcnt;
}tree[mx*3];

node init(int n, int b, int e){
	if(b==e){
		tree[n].l = arr[b];
		tree[n].r = arr[b];
		tree[n].lcnt = 1;
		tree[n].rcnt = 1;
		tree[n].maxcnt = 1;
		return tree[n];
	}
		
	int lt = n * 2;
	int rt = n * 2 + 1;
	int mid = (b+e) / 2;
	
	node left = init(lt, b, mid);
	node right = init(rt, mid+1, e);
	
	tree[n].l = left.l;
	tree[n].r = right.r;
	tree[n].lcnt = left.lcnt;
	tree[n].rcnt = right.rcnt;
	int m = max(left.maxcnt , right.maxcnt);
	
	if(left.r == right.l){
		tree[n].maxcnt = max(m, left.rcnt+right.lcnt);
		if(left.l == left.r)
			tree[n].lcnt = left.rcnt+right.lcnt;
		if(right.l == right.r)
			tree[n].rcnt = left.rcnt+right.lcnt;
	}
	else{
		tree[n].maxcnt = m;
		
	}
	
	return tree[n];
}

int query(int n, int i, int j, int b, int e){
	if(b < i && e < i){
		return 0;
	}
	if(b > j && e > j)
		return 0;
	else if(b>=i && e <= j)
		return tree[n].maxcnt;
	
	int lt = n * 2;
	int rt = n * 2 + 1;
	int mid = (b+e) / 2;
	
	int q1 = query(lt, i, j, b, mid);
	int q2 = query(rt, i, j, mid+1, e);
	
	if(q1 == 0){
		return q2;
	}
	else if(q2 == 0){
		return q1;
	}
	else{
		int m = max(q1,q2);
		if(tree[lt].r == tree[rt].l){
			int lc,rc;
			lc = min(mid-i+1, tree[lt].rcnt);
			rc = min(j-mid, tree[rt].lcnt);
			m = max(m, lc+rc);
		}
		
		return m;
	}
}

int main(){
	//freopen("input.txt","r",stdin);
	int n,q,a,b;
	while(scanf("%d%d",&n,&q),n){
		for(int i=1; i<=n; i++)
			scanf("%d",&arr[i]);
		init(1,1,n);
		for(int i=1; i<=q; i++){
			scanf("%d%d",&a,&b);
			printf("%d\n",query(1,a,b,1,n));
		}
	}
	return 0;
}
