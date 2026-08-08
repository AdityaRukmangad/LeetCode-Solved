class LRUCache {
public:
    struct Node{                //node structure
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int k , int v){        //contructor
            key = k;
            val =v;
            prev = nullptr;
            next = nullptr;
        }
    };


    int cap;
    unordered_map<int,Node*>mp;

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    void addnode(Node* node){
        node->next= head->next;
        node->prev=head;
        head->next->prev = node;
        head->next =node;
    }
    void remove(Node* node){
        Node* prevnode = node->prev;
        Node* nextnode = node->next;
        prevnode->next=nextnode;
        nextnode->prev=prevnode;
    }

    LRUCache(int capacity) {
        cap = capacity ;
        head ->next =tail;
        tail->prev =head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
        return -1;
        Node* node = mp[key];
        remove(node);
        addnode(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){     //case 1 key already exist
            Node* node=mp[key];
            remove(node);
            node->val = value;
            addnode(node);
            return;
        }
        Node* node= new Node(key,value);        //doesnt exists 
        mp[key]=node;
        addnode(node);

        if(mp.size()> cap){                 // If capacity is ceeded
            Node* lru = tail->prev;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */