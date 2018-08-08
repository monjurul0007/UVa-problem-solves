#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,p,t,pt[100],cnt;
    bool days[3651];
    scanf("%d",&t);
    while(t--){
		cnt = 0;
		for(int j=1; j<3651; j++)
			days[j] = false;
		scanf("%d%d",&n,&p);
		for(int i=0; i<p; i++)
			scanf("%d",&pt[i]);
		for(int i=0; i<p; i++)
			for(int j=pt[i]; j<=n; j+=pt[i])
				days[j] = true;
		for(int i=6; i<=n; i+=7){
			days[i] = false;
			days[i+1] = false;
		}
		
		for(int j=1; j<=n; j++)
			if(days[j])
				cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}
