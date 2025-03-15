#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pbs insert
#define pi pair<ll,ll>
#define py cout<<"YES\n";
#define pys cout<<"Yes\n";
#define pn cout<<"NO\n";
#define pns cout<<"No\n";
#define co(x1) cout<<x1<<"\n";
#define ct(x1) cout<<x1<<" ";
#define elc cout<<"\n";
#define el "\n";
#define fl(x1,x2,x3) for(int x1=x2;x1<x3;x1++)
#define flr(x1,x2,x3) for(int x1=x2;x1>=x3;x1--)
#define flx(x1) for(auto x:x1) ct(x) elc
#define forni for(int i=0;i<n;i++)
#define all(x1) x1.begin(),x1.end()
#define allr(x1) x1.rbegin(),x1.rend()
#define sz(x) x.size()
#define vec(x) vector<x>

const int N=1e5+9;
ll a[N],t[4*N],amount=0;

void build(int n,int b,int e){
    if(b==e){
        t[n]=a[b];
        return;
    }
    int m=(b+e)/2,l=n*2,r=(n*2)+1;
    build(l,b,m);
    build(r,m+1,e);
    t[n]=t[l]+t[r];
}
 
void remove(int n,int b,int e,int i,int v){
    if(i<b || i>e) return;
    if(b==e){
        amount=t[n];
        t[n]=v;
        return;
    }
    int m=(b+e)/2,l=(n*2),r=(n*2)+1;
    remove(l,b,m,i,v);
    remove(r,m+1,e,i,v);
    t[n]=t[l]+t[r];
}

void update(int n,int b,int e,int i,int v){
    if(i<b || i>e) return;
    if(b==e){
        t[n]+=v;
        return;
    }
    int m=(b+e)/2,l=(n*2),r=(n*2)+1;
    update(l,b,m,i,v);
    update(r,m+1,e,i,v);
    t[n]=t[l]+t[r];
}
 
ll query(int n,int b,int e,int i, int j){
    if(e<i || b>j) return 0;
    if(b>=i && e<=j) return t[n];
    int m=(b+e)/2,l=(n*2),r=(n*2)+1;
    return query(l,b,m,i,j)+query(r,m+1,e,i,j);
}

void asikM(){
    ll n,q;
    cin >> n>>q;
    fl(i,1,n+1) cin>>a[i]; 
    build(1,1,n);
    while(q--){
        ll x;
        cin>>x;
        if(x==1){
            ll in;
            cin>>in;
            remove(1,1,n,in+1,0);
            co(amount)
        }
        else if(x==2){
            ll in,val;
            cin>>in>>val;
            update(1,1,n,in+1,val);
        }
        else{
            ll i,j;
            cin>>i>>j;
            ll c=query(1,1,n,i+1,j+1);
            co(c)
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    cin >> t;
    fl(i,0,t){
        co("Case "<<i+1<<":")
        asikM();      
    }
    return 0;
}