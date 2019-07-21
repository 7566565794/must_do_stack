int _stack :: getMin()
{
   //Your code here
   if(s.empty())
        return -1;
    return minEle;
}
/*returns poped element from stack*/
int _stack ::pop()
{
   //Your code here
   if(s.empty())
        return -1;
    if(s.top()>minEle){
        int t = s.top();
        s.pop();
        return t;
    }
    else if(s.top()<=minEle){
        int t = s.top();
        s.pop();
        int k = minEle;
        minEle = 2*minEle-t;
        return k;
    }
}
/*push element x into the stack*/
void _stack::push(int x)
{
   //Your code here
   if(s.empty()){
       s.push(x);
       minEle = x;
   }
   else if(x>=minEle){
       s.push(x);
   }
   else {
       s.push(2*x-minEle);
       minEle = x;
   }
   
}
