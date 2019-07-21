using namespace std;

struct pts{
    int x,y;
};
bool isDelim(pts temp){
    return (temp.x==-1 && temp.y==-1);
}

bool isValid(int i, int j, int r, int c){
    return (i>=0 && i<r && j>=0 && j<c);
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int r,c;
	    cin>>r>>c;
	    int a[r][c];
	    queue<pts>q;
	    pts temp;
	    for(int i=0; i<r; i++){
	        for(int j=0; j<c; j++){
	            cin>>a[i][j];
	            if(a[i][j]==2){
	                temp.x = i;
	                temp.y = j;
	                q.push(temp);
	            }
	        }
	    }
	    temp.x = -1;
	    temp.y = -1;
	    q.push(temp);
	    int ans = 0;
	    while(!q.empty()){
	        bool flag = false;
	        
	        while(!isDelim(q.front())){
	           temp = q.front();
	           if(isValid(temp.x+1,temp.y,r,c) && a[temp.x+1][temp.y]==1){
	               if(!flag){
	                    flag = true;
	                    ans++;
	               }
	               temp.x++;
	               a[temp.x][temp.y] = 2;
	               q.push(temp);
	               temp.x--;
	           }
	           if(isValid(temp.x-1,temp.y,r,c) && a[temp.x-1][temp.y]==1){
	               if(!flag){
	                    flag = true;
	                    ans++;
	               }
	               temp.x--;
	               a[temp.x][temp.y] = 2;
	               q.push(temp);
	               temp.x++;
	           }
	           if(isValid(temp.x,temp.y+1,r,c) && a[temp.x][temp.y+1]==1){
	               if(!flag){
	                    flag = true;
	                    ans++;
	               }
	               temp.y++;
	               a[temp.x][temp.y] = 2;
	               q.push(temp);
	               temp.y--;
	           }
	           if(isValid(temp.x,temp.y-1,r,c) && a[temp.x][temp.y-1]==1){
	               if(!flag){
	                    flag = true;
	                    ans++;
	               }
	               temp.y--;
	               a[temp.x][temp.y] = 2;
	               q.push(temp);
	               temp.y++;
	           }
	            q.pop();   
	        }
	        q.pop();
    	    if(!q.empty()){
    	        temp.x = -1;
    	        temp.y = -1;
    	        q.push(temp);
	        }
	    }
	    
	    bool f = false;
	    for(int i=0; i<r; i++){
	        for(int j=0; j<c; j++){
	            if(a[i][j]==1){
	                f = true;
	            }
	        }
	    }
	    if(!f)
	     cout<<ans<<endl;
	    else
	        cout<<"-1"<<endl;
	}
	return 0;
}
