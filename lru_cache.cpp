deque<int>dq;
map<int,int>m;
int size;
LRUCache::LRUCache(int N)
{
     //Your code here
     dq.clear();
     m.clear();
     size = N;
}
/*Sets the key x with value y in the LRU cache */
void LRUCache::set(int x, int y) 
{
     //Your code here
     if(m.find(x)==m.end()){
         if(dq.size()==size){
             int temp = dq.back();
             dq.pop_back();
             m.erase(temp);
         }
     }
     else{
         deque<int>::iterator i = dq.begin();
         while(*i!=x)
            i++;
         dq.erase(i);
         m.erase(x);
     }
     dq.push_front(x);
     m[x] = y;
     
}
/*Returns the value of the key x if 
present else returns -1 */
int LRUCache::get(int x)
{
    //Your code here
    if(m.find(x)==m.end())
        return -1;
    deque<int>::iterator i=dq.begin();
    while(*i!=x)
        i++;
    dq.erase(i);
    dq.push_front(x);
    return m[x];
}
