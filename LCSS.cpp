#include<iostream>
using namespace std;
int LCS_print(string x,string y,int m,int n){
    int L[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                L[i][j]=0;
            }
            else if(x[i-1]==y[j-1]){
                L[i][j]=L[i-1][j-1]+1;
            }
            else{
                    L[i][j]=max(L[i][j-1],L[i-1][j]);

            }
        }
    }
    return L[m][n];

}


int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int m=s1.length();
    int n=s2.length();
    cout<<LCS_print(s1,s2,m,n)<<endl;

}
