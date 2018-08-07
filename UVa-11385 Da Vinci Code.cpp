#include <bits/stdc++.h>

using namespace std;

map <long long int, int> fib_map;

void fib(){
	long long int a = 1, b = 2,c=a+b;
	int i=2;
	fib_map[a] = 0;
	fib_map[b] = 1;
	while(c<=(long long int)2147483648){
		fib_map[c] = i++;
		a = b;
		b = c;
		c = a+b;
	} 
}

int main(){
	int t,n,m,cnt;
	char st,arrS[200],arrC[200];
	fib();
	scanf("%d",&t);
	while(t--){
		cnt = 0;
		scanf("%d",&n);
		int arr[n];
		for(int i = 0; i<n; i++)
			scanf("%d\n",&arr[i]);
		while(1){
			scanf("%c",&st);
			if(st=='\n')
				break;
			if(st>='A' && st<='Z')
				arrC[cnt++] = st;
		}
		memset(arrS, ' ' , sizeof(arrS));
		int max = 0;
		for(int i = 0; i<n; i++){
			m = fib_map[arr[i]];
			if(max < m)
				max = m;
			arrS[m] = arrC[i];
		}
		arrS[max+1] = '\0';
		puts(arrS);
	}
	return 0;
}

