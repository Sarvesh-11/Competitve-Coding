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
    vector<pairi> v;
    ll mn=0,mx=0;
    sidha(i,0,n){
        int a,b;cin>>a>>b;
        v.pb({a,b});
        mn+=a;mx+=b;
    }
    //cout<<mn<<" "<<mx<<endl;
    if(k<mn or k>mx){
        cout<<"NO"<<endl;
    }
    else{
        k-=mn;
        //cout<<k<<" ";
        for(int i=0;i<n;i++){
            if(k>=(v[i].second-v[i].first)){
                k-=(v[i].second-v[i].first);
                v[i].first=v[i].second;
            }
            else{
                v[i].first+=k;k=0;
                break;
            }
            //cout<<k<<" ";
        }
        //cout<<mn<<" "<<mx<<endl;
         cout<<"YES"<<endl;
        //cout<<k<<endl;
        for(int i=0;i<n;i++){
            cout<<v[i].first<<" ";
        }
    }
	return 0;
}