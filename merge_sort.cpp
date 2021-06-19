#include <bits/stdc++.h>

#define ll          long long int
#define mod         1000000007
#define endl        "\n"
#define pb          push_back
#define max2(a,b)   ((a<b)?b:a)
#define max3(a,b,c) max2(max2(a,b),c)
#define min2(a,b)   ((a>b)?b:a)
#define min3(a,b,c) min2(min2(a,b),c)



using namespace std;

void merge(ll inp[],ll l,ll r, ll mid){
	ll s1=mid - l + 1;
	ll s2= r - mid;

	ll left[s1];
	ll right[s2];

	ll a=0,b=0,c=l;

	for (int i = 0; i < s1; ++i)
	{
		left[i]=inp[i+l];
	}

	for (int i = 0; i < s2; ++i)
	{
		right[i]=inp[mid+1+i];
	}

	while (a<s1 && b<s2)
	{
		if(left[a]<right[b]){
			inp[c]=left[a];
			c++;
			a++;
		}

		else{
			inp[c]=right[b];
			c++;
			b++;
		}


	} 


	while(a<s1){
		inp[c]=left[a];
			c++;
			a++;
	}

	while(b<s2){
		inp[c]=right[b];
			c++;
			b++;
	}

}


void mergesort(ll inp[],ll l, ll r){
	ll mid=(l+r)/2;
	if(l<r){
		mergesort(inp,l,mid);
		mergesort(inp,mid+1,r);
		merge(inp,l,r,mid);
	}

	
}




int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

   
    
	ll n;
	cin>>n;
    ll vect[n];
    for (int i = 0; i <= n-1; ++i)
    {
        cin>>vect[i];
    }

    mergesort(vect,0,n-1);
 
 	
    for (int i = 0; i <= n-1; ++i)
    {
        cout<<vect[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
