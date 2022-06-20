class LRUCache {
public:
    class node
    {
        public:
        int key;
        int val;
        node* prev;
        node* next;
        node(int _key,int _val)
        {
            key=_key;
            val=_val;
        }
    };
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    
    unordered_map<int,node*> mp;
    int cap;
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addNode(node* n)
    {
        node* temp=head->next;
        n->next=head->next;
        n->prev=head;
        head->next=n;
        temp->prev=n;
    }
    
    void deleteNode(node *n)
    {
        node* prevtemp=n->prev;
        node* prevnext=n->next;
        prevtemp->next=prevnext;
        prevnext->prev=prevtemp;
    }
    
    int get(int key) 
    {
        if(mp.find(key)!=mp.end())
        {
            node* temp=mp[key];
            int res=temp->val;
            deleteNode(temp);
            mp.erase(key);
            addNode(temp);
            mp[key]=head->next;
            return res;
        }
        return -1;
        
    }
    
    void put(int key, int value) 
    {
        if(mp.find(key)!=mp.end())
        {
            node* temp=mp[key];
            mp.erase(key);
            deleteNode(temp);
        }
        if(mp.size()==cap)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        addNode(new node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */