using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    char a[n];
	    int f[26] = {0};
	    for(int i=0; i<n; i++)
	        cin>>a[i];
	    queue<char>q;
	    for(int i=0; i<n; i++){
	        q.push(a[i]);
	        f[a[i]-'a']++;
	        while(!q.empty()){
	            if(f[q.front()-'a']>1)
	                q.pop();
	            else{
	                cout<<q.front()<<" ";
	                break;
	            }
	        }
	        if(q.empty())
	            cout<<"-1"<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
