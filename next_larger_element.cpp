using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    long long int a[n];
	    for(int i=0; i<n; i++)
	        cin>>a[i];
	    stack<long long int>s;
	    long long int m[n];
	    s.push(0);
	    for(int i=1; i<n; i++){
	        while(!s.empty() && a[s.top()]<a[i]){
	            m[s.top()] = a[i];
	            s.pop();
	        }
	        s.push(i);
	    }
	    while(!s.empty()){
	        m[s.top()] = -1;
	        s.pop();
	    }
	    for(int i=0; i<n; i++){
	        cout<<m[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
