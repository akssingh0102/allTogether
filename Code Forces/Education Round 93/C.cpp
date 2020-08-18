#include<iostream>
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
int charToInt(char ch){

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int a[n];
        int *suf_sum=new int[n];
        for (int i = 0; i < n; i++)
        {
            a[i]=charToInt(s[i]);
            if(i==0)suf_sum[i]=a[i];
            else
            {
                suf_sum[i]=a[i-1]+a[i];
            }
            
        }
        int count=0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if(abs(i-j)==suf_sum[j]){
                    count++;
                }
            }
            
        }
        
            
    }

}