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
int bin_search(vector<int>v,int num,int len){
	int first=0,end=len-1;
	int mid=(first+end)/2;
	while(first<=end){
		if(v[mid]==num)return mid+1;
		else if(v[mid]>num)end=mid-1;
		else first=mid+1;
		mid=(first+end)/2;
	}
	return 0;
}
void sieve(int n){
	vector<bool>isPrime(n+1,true);
	int ans=0;
	for(int i=2;i<=sqrt(n);i++){
		if(isPrime[i]){
			for(int j=i*i;j<=n;j=j+i)
				isPrime[j]=false;
		}
	} 
	for(int i=2;i<=n;i++)
		if(isPrime[i])
			prime.push_back(i);
	}
	bool comp(pair<int,int>x,pair<int,int>y){
		return x.second<y.second;
	}
	int dp1(int i,int j){
		if(i==s1.size() or j==t1.size())return 0;

		if(dp[i][j]!=-1)return dp[i][j]; 
		int res=0;
		if(s1[i]==t1[j]){
			res = 1+dp1(i+1,j+1);
			mark[i][j]=1;
		}
		else{
			int tmp1=dp1(i+1,j);
			int tmp2=dp1(i,j+1);
			if(tmp1>tmp2){
				mark[i][j]=2;
			}
			else mark[i][j]=3;

			res= max(tmp1,tmp2);
		}
		return dp[i][j]=res;

	}
	void print_way(int i,int j){
		if(i==s1.size() or j==t1.size())return;

		if(mark[i][j]==1){
			cout<<s1[i];
			print_way(i+1,j+1);
		}
		else if(mark[i][j]==2){
			print_way(i+1,j);
		}
		else print_way(i,j+1);

	}
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
		int n;cin>>n;
		string s;cin>>s;
		int mx=-1;
		set<int>left;
		map<char,int>right;

		for (char c : s) right[c]++;

		for (int i = 0; i < n-1; ++i)
		{
			left.insert(s[i]);
			if(right[s[i]]==1)right.erase(s[i]);
			else right[s[i]]--; 
			//cout<<left.size()<<" "<<right.size()<<endl;
			mx=max(mx,(int)(left.size()+right.size()));
		}
		cout<<mx<<endl;


	}


/*
6
2
aa
7
abcabcd
5
aaaaa
10
paiumoment
4
aazz
8
szhkbpph

*/
