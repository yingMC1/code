#include <bits/stdc++.h>
using namespace std;
int main(){
 mt19937 rng(1);
 for(int n=1;n<=8;n++) for(int z=0;z<10000;z++){
  vector<string>s(n); for(auto &x:s){x={(rng()&1)?'R':'B',(rng()&1)?'R':'B'};}
  int brute=n;
  for(int mask=0;mask<(1<<n);mask++){int c=0;for(int i=0;i<n;i++){char r=(mask>>i&1)?s[i][0]:s[i][1];char l=(mask>>((i+1)%n)&1)?s[(i+1)%n][1]:s[(i+1)%n][0];c+=r!=l;} brute=min(brute,c);}
  int ans=n;
  for(int first=0;first<2;first++){int dp[2]={n+1,n+1};dp[first]=0;for(int i=1;i<n;i++){int f[2]={n+1,n+1};for(int p=0;p<2;p++)for(int q=0;q<2;q++){char r=p?s[i-1][0]:s[i-1][1],l=q?s[i][1]:s[i][0];f[q]=min(f[q],dp[p]+(r!=l));}dp[0]=f[0];dp[1]=f[1];}for(int last=0;last<2;last++){char r=last?s[n-1][0]:s[n-1][1],l=first?s[0][1]:s[0][0];ans=min(ans,dp[last]+(r!=l));}}
  if(ans!=brute){cerr<<"bad"<<n<<' '<<ans<<' '<<brute<<endl;return 1;}
 }
 cerr<<"all ok\n";
}
