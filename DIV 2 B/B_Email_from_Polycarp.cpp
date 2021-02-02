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
bool solve(string a,string b){
    int j=0;
    for(int i=0;i<b.size()&&j<a.size();i++){
        if(a[j]==b[i]){
            j++;
        }
    }
    if(j==a.size()){
        return true;
    }
    return false;
}

//Driver Function
int main(){
	io;
	w(t){
        string s,t;cin>>s>>t;
        bool ok=true;
        int j=0;
        if(t.length()<s.length()){
            // cout << "NO" << endl;
            ok=false;
        }
        else{
            for(int i=0;i<t.length();i++){
                if(t[i] == s[j]) j++;
                else{
                    if(i == 0 || t[i] != t[i-1]){
                        // cout << "NO" << endl;
                        ok=false;
                        break;
                    }
                }
            }
            
        }
        if(j<s.length()) ok=false;
        if(ok)
            cout<<"YES"<<endl;
        else 
            cout<<"NO"<<endl;
    }
	return 0;
}