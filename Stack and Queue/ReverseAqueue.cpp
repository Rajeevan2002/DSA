queue<int> rev(queue<int> q)
{
    // add code here.
   stack <int> s;
   while(q.empty()==false)
   {
       s.push(q.front());
       q.pop();
   }
   while(s.empty()==false)
   {
       q.push(s.top());
       s.pop();
   }
   return q;
}