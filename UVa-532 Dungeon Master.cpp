#include <bits/stdc++.h>

using namespace std;

char adj[30][30][30];
int vis[30][30][30];

int _l[] = {1,0,-1,0,0,0};
int _r[] = {0,1,0,-1,0,0};
int _c[] = {0,0,0,0,1,-1};

void setG(int l, int r, int c){
	for(int i=0; i<l; i++)
			for(int j=0; j<r; j++)
				for(int k=0; k<c; k++)
					vis[l][r][c] = -1;
}	

void bfs(int l,int r,int c){
	queue <int> ql,qr,qc;
	int topl,topr,topc;
	ql.push(l);
	qr.push(r);
	qc.push(c);
	vis[l][r][c] = 0;
	while(!ql.empty() && !qr.empty() && !qc.empty()){
		topl = ql.front();
		topr = qr.front();
		topc = qc.front();
		ql.pop();
		qr.pop();
		qc.pop();
		for(int i=0; i<6; i++)
			if(topl+_l[i]>=0 && topl+_l[i]<30 && topr+_r[i]>=0 && topr+_r[i]<30 && topc+_c[i]>=0 && topc+_c[i]<30) 
				if(adj[topl+_l[i]][topr+_r[i]][topc+_c[i]] == '.'){
					ql.push(topl+_l[i]);
					qr.push(topr+_r[i]);
					qc.push(topc+_c[i]);
					adj[topl+_l[i]][topr+_r[i]][topc+_c[i]] = '#';
					vis[topl+_l[i]][topr+_r[i]][topc+_c[i]] = vis[topl][topr][topc] + 1;
				}
	}

}

int main(){
//	freopen("input.txt","r",stdin);
	int l,r,c,sl,sr,sc,el,er,ec;
	while(scanf("%d%d%d",&l,&r,&c),(l|r|c)){
		setG(l,r,c);
		for(int i=0; i<l; i++)
			for(int j=0; j<r; j++)
				for(int k=0; k<c; k++){
					scanf(" %c",&adj[i][j][k]);
					if(adj[i][j][k] == 'S'){
						sl = i;
						sr = j;
						sc = k;
					}
					 if(adj[i][j][k] == 'E'){
						el = i;
						er = j;
						ec = k;
						adj[i][j][k] = '.';
					}
				}
		bfs(sl,sr,sc);
		if(adj[el][er][ec] == '.')
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n",vis[el][er][ec]);
	}
	return 0;
}
