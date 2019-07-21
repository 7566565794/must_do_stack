using namespace std;

void maxOfK(int a[], int n, int k){
    int i=0;
    deque<int>q;
    for(i=0; i<k; i++){
        while(!q.empty() && a[q.back()]<=a[i])
            q.pop_back();
        q.push_back(i);
    }
    
    for(; i<n; i++){
        cout<<a[q.front()]<<" ";
        while(!q.empty() && q.front()<=i-k)
            q.pop_front();
        while(!q.empty() && a[q.back()]<=a[i])
            q.pop_back();
        q.push_back(i);
    }
    cout<<a[q.front()];
}

int main()
 {
	int t;
	cin>>t;
	
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int a[n];
	    for(int i=0; i<n; i++)
	        cin>>a[i];
	    maxOfK(a,n,k);
	    cout<<endl;
	}
	return 0;
}
