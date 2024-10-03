#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(v) v.begin(),v.end()
const int inf = 1e9;
const int N = 1e6 +7;

#define alliswell Things will get better


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
bool sortbyCond(const pair<int, int> &a, const pair<int, int> &b) {

	if (a.first != b.first) {
		return a.first > b.first; 
	}
	return a.second < b.second; 
}

long long factorial(int n) {
    long long result = 1; 
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}
long long nPr(int n, int r) {
    return factorial(n) / factorial(n - r);
}

void solve() {
    int n;cin>>n;
    int a = 1;

    for (int i = 2; i*i<= n ; i++) {
    	if(n%i==0){
    		a=n/i;
    		break;
    	}
    }

    cout << a << " " << n-a << endl;
}
/*
logic: since lcm = (a*b)/gcd(a,b)
To minimize the LCM, we need to maximize the GCD. Therefore, our goal is to find two numbers 
a and b such that a+b=n and the GCD of a and b is as large as possible. 
To achieve this, we look for the smallest divisor of n, because dividing 
n by its smallest factor will yield the largest possible GCD between the two parts 
a and n−a.

Maximizing GCD: When a is the smallest divisor of n, the two numbers 
a and n−a have the highest possible GCD, as a divides n
*/
