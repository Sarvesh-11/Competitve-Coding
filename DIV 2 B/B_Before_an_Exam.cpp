// Author :- Sarvesh Chaudhary
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
map<int,int> m;

//Functions


//Driver Function
int main(){
	io;
    ll n,k;cin>>n>>k;
    ll ma=0,mn=0;
    vector<pairi> v;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        v.push_back({a,b});
        ma+=a;mn+=b;
    }
    // cout<<ma<<" "<<mn<<endl;
    int j=0;
    if(k<ma and k>mn){
        cout<<"NO"<<endl;
    }
    else if(k==ma){
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++){
            cout<<v[i].first<<" ";
        }
    }
    else if(k==mn){
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++){
            cout<<v[i].second<<" ";
        }
    }
    else{
        cout<<"YES"<<endl;
        while(ma>=k){
            ma+=(v[j].second-v[j].first);v[j].first=v[j].second;j++;
        }
        if(ma==k){
            for(int i=0;i<n;i++){
                cout<<v[i].first<<" ";
            }
        }
        else{
            v[j-1].first-=(ma-k);
            for(int i=0;i<n;i++){
                cout<<v[i].first<<" ";
            }
        }
    }
	return 0;
}