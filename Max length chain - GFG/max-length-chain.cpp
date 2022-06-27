// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/

void maxLen( struct val p[], int n , int &maxChain , int pre , int len , vector<int> &visited){

    for( int i = 0 ; i < n ; ++i ){
        
        if( visited[i] == 0 && pre < p[i].first ){
            visited[i] = 1;
            maxLen(p , n , maxChain , p[i].second , len+1 , visited);
            visited[i] = 0;
        }
        
    }
    
    maxChain = max(maxChain , len);
    
}

bool static cmp(struct val a , struct val b ){
    return a.second < b.second;
}

int maxChainLen(struct val p[],int n)
{
    
    int maxChain = 0;
    vector<int> visited(n , 0);
    
    maxLen( p , n , maxChain , -1 , 0 , visited);
    return maxChain;
    // sort(p , p+n , cmp);
    
    // int ans = 0;
    
    // for( int i = 0 ; i < n ; ++i ){
    //     int p = p[i].second;
    //     for( int j = i+1 ; j < n ; ++j ){
            
    //         if( )
    //     }
        
    // }
    
}