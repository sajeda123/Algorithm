/* Dynamic Programming C/C++ implementation of LCS problem */
#include<iostream>
#include<cstdio>
using namespace std;

//int max(int a, int b);

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int max(int a, int b)
{
    return (a > b)? a : b;
}
int call_LCS( string X, string Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;

   /* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;

       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;

       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }

   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n];
}

/* Utility function to get max of 2 integers */


/* Driver program to test above function */
int main()
{
   string str1,str2;
   cin>>str1;
   cin>>str2;
  int m =str1.length();
  int n = str2.length();
  //cout<<m<<" "<<n<<endl;

 // printf("Length of LCS is %d\n", lcs( str1, str2, m, n ) );
  cout<<"Length of LCS is="<<call_LCS( str1, str2, m, n )<<endl;

  return 0;
}
