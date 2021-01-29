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
bool dc(ll n,ll d){
    for(ll i=n;i>0;i/=10){
        if(i%10==d){
            return true;
        }
    }
    return false;
}

//Driver Function
int main(){
	io;
	w(t){
        ll n,d;cin>>n>>d;
        ll arr[n];
        sidha(i,0,n){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            if(dc(arr[i],d)){
                cout<<"YES"<<endl;
                continue;
            }

            int x=arr[i]%d;
            int c=arr[i]/d;
            bool a=false;
            while(c>0){
                x+=d;
                if(dc(x,d)){
                    a=true;break;
                }
                c--;
            }
            if(a){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
	return 0;
}