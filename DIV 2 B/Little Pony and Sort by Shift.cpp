// Problem: B. Little Pony and Sort by Shift
// Contest: Codeforces - Codeforces Round #259 (Div. 2)
// URL: https://codeforces.com/problemset/problem/454/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
 * Author: runtime_terr0r
*/

#include<bits/stdc++.h>
using namespace std;
#define w(x) int x; cin>>x; while(x--)
#define ll long long int
#define sidha(i,a,b) for(int i=a;i<b;i++)
#define set_built(x) __builtin_popcountll(x)
#define zero_built(x) __bultin_ctzll(x)
#define pairi pair<int,int>
#define vi vector<int>
#define mod 1000000007
#define MAX INT_MAX
#define MIN INT_MIN
#define pb push_back
#define po pop_back
#define all(c) c.begin(),c.end()
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//Global Variable
//map<int,int> m;

//Functions


//Driver Function
int main(){
	io;
	int n;cin>>n;
	int arr[n];
	sidha(i,0,n){
		cin>>arr[i];
	}
	int k=0,t;
	for(int i=1;i<n;i++){
		if(arr[i]<arr[i-1]){
			k++;t=i;
		}
	}
	if(n==1){
		cout<<0<<endl;
	}
	else if(k>1){
		cout<<-1<<endl;
	}
	else if(k==0){
		cout<<0<<endl;
	}
	else if(arr[n-1]>arr[0]){
		cout<<-1<<endl;
	}
	else{
		cout<<n-t<<endl;
	}
	return 0;
}
