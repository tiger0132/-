#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAX 30007

using namespace std;

int block;

struct Query
{
    int l,r,id,type;
    bool operator < ( const Query& a ) const
    {
        int b1 = l/block , b2 = a.l/block; 
        return b1 < b2 || ( b1 == b2 && r < a.r );
    } 
}q[MAX<<2];

int cnt[MAX];
int n,m,k,l,r,u,v;
int a[MAX];
int ans[MAX];

void set ( int id , int l , int r )
{
    q[id].l = l;
    q[id].r = r;
    q[id].id = id/4;
    q[id].type = id%4; 
} 

int main ( )
{
    while ( ~scanf ( "%d" , &n ) )
    {
        block = (int)(sqrt(n+0.5));
        scanf ( "%d" , &k );
        memset ( cnt , 0 , sizeof ( cnt ) );
        memset ( ans , 0 , sizeof ( ans ) );
        for ( int i = 1 ; i <= n ; i++ )
            scanf ( "%d" , &a[i] );
        scanf ( "%d" , &m );
        for ( int i = 0 ; i < m ; i++ )
        {
            scanf ( "%d%d%d%d" , &l , &r , &u , &v );
            set ( 4*i , l , v );
            set ( 4*i+1 , r+1 , u-1 );
            set ( 4*i+2 , l , u-1 );
            set ( 4*i+3 , r+1 , v );
        }
        sort ( q , q+4*m );
        int cur = 0 , l = 0 , r = -1;
        for ( int i = 0 ; i < 4*m ; i++ )
        {
            while ( l < q[i].l )
            {
                cnt[a[l]]--;
                if ( k > a[l] && k - a[l] <= n )
                    cur -= cnt[k-a[l]];
                l++;
            }
            while ( r > q[i].r )
            {
                cnt[a[r]]--;
                if ( k > a[r] && k - a[r] <= n )
                    cur -= cnt[k-a[r]];
                r--;
            }
            while ( l > q[i].l )
            {
                l--;
                if ( k > a[l] && k-a[l] <= n ) 
                    cur += cnt[k-a[l]];
                cnt[a[l]]++;
            }
            while ( r < q[i].r )
            {
                r++;
                if ( k > a[r] && k-a[r] <= n )
                    cur += cnt[k-a[r]];
                cnt[a[r]]++;
            }
            if ( q[i].type < 2 ) ans[q[i].id] += cur;
            else ans[q[i].id] -= cur;
        }
        for ( int i = 0 ; i < m ; i++ )
            printf ( "%d\n" , ans[i] );
    }
}