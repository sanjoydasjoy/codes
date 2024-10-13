#include <bits/stdc++.h>
using namespace std;

void Dutch_National_Flag_Algorithm(vector<int>v){

    int n = v.size();
    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid<=high){
        if(v[mid]==0){
            swap(v[mid],v[low]);
            low++;
            mid++;
        }
        else {
            swap(v[mid],v[high]);
            high--;
        }

    }



    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
}

int main()
{

    int n;cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];


    Dutch_National_Flag_Algorithm(arr);

    
}




