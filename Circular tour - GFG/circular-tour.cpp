// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int tp = 0 , d = 0;
       for( int i = 0 ; i < n; ++i ){
           tp += p[i].petrol;
           d += p[i].distance;
       }
       
       if( d > tp ){
           return -1;
       }
       
       int sum = 0;
       vector<int> isP(n , -1);
       int start = 0;
       for( int i = 0 ; i < n ; ++i ){
           sum += p[i].petrol;
           if( sum < p[i].distance ){
               sum = 0;
               start = (i+1)%n;
           }
           else{
               sum -= p[i].distance;
           }
       }
       
       return start;
       
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends