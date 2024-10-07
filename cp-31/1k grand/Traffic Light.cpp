//optimal

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(v) v.begin(),v.end()
#define ho cout<<"YES"<<endl
#define na cout<<"NO"<<endl
#define show(x) for(auto i:x)cout<<i<<" ";cout<<endl;
const int inf = 1e9;
const int N = 1e6 +7;

#define alliswell Things will get better


int dp[3005][3005];
int mark[3005][3005];
vector<int>prime;
string s1,t1;

void solve();

	int32_t main()
	{
		ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
		int t=1;
		cin>>t;
		while(t--){
			solve();
		}

		return 0;
	}
	void solve()
	{
		int n;
		char c;
		cin>>n>>c;
		string s;cin>>s;
		int mx=0,x=0;
		s+=s;
		for(int i=0;i<s.size();i++){
			if(s[i]==c){
				x=0;
				while(s[i]!='g' && i<s.size()){
					x++;
					i++;
				}
				if(x>mx)mx=x;
			}
		}
		if(c=='g')cout<<0<<endl;
		else cout<<mx<<endl;
	}


/*
6
5 r
rggry
1 g
g
3 r
rrg
5 y
yrrgy
7 r
rgrgyrg
9 y
rrrgyyygy


*/


#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(v) v.begin(),v.end()
#define ho cout<<"YES"<<endl
#define na cout<<"NO"<<endl
#define show(x) for(auto i:x)cout<<i<<" ";cout<<endl;
const int inf = 1e9;
const int N = 1e6 +7;

#define alliswell Things will get better


int dp[3005][3005];
int mark[3005][3005];
vector<int>prime;
string s1,t1;

void solve();

	int32_t main()
	{
		ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
		int t=1;
		cin>>t;
		while(t--){
			solve();
		}

		return 0;
	}
	void solve()
	{
		int n;
		char c;
		cin>>n>>c;
		string s;cin>>s;
		int mx=-1,x=0,p;
		for(int j=0;j<n;j++){
			if(s[j]=='g'){
				p=j+1;
				break;}
		}
		for(int i=0;i<n;i++){
			if(s[i]==c and i!=n-1){
				x=0;
				for(int j=i+1;j<n;j++){
					if(s[j]=='g'){
						x=j-i;
						//cout<<"first"<< " "<<x<<endl;
						mx=max(mx,x);
						break;
					}
				}
				if(!x){
					x=n-i+p-1;
					mx=max(mx,x);
					//cout<<"sec"<< " "<<x<<endl;
				}
			}
			if(s[i]==c and i==n-1)mx=max(mx,p);
		}
		if(c=='g')cout<<0<<endl;
		else cout<<mx<<endl;



	}


/*
6
5 r
rggry
1 g
g
3 r
rrg
5 y
yrrgy
7 r
rgrgyrg
9 y
rrrgyyygy


*/
