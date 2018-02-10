#include <bits/stdc++.h>
using namespace std;

        if(n==1 && k==0) return 1;    
        else if( k==1 || n==k ) return 1;    
        else return Stirling(n-1, k)*k+Stirling(n-1, k-1); 



int main() {
	
} 
