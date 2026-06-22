class LRUCache {
public:
    
    class Node
    {
    public :
        int key ; 
        int val ;
        Node* next ;
        Node* prev ;

        Node(int _key , int _val)
        {
            key = _key ;
            val = _val ;
        }
    };

    Node* head = new Node(-1,-1) ;
    Node* tail = new Node(-1,-1) ;

    int cap ;  // capacity of cache 

    unordered_map<int , Node*> m ; // hashmap key-node mapping


    LRUCache(int capacity) {
        cap = capacity ;
        head -> next = tail ;
        tail -> prev = head ;
    }

    void addNode(Node* newNode)
    {
        Node* temp = head -> next ;
        newNode -> next = temp ;
        newNode -> prev = head ;
        temp -> prev = newNode ;
        head -> next = newNode ;
    }

    void deleteNode(Node* delNode)
    {
        Node* delPrev = delNode -> prev ;
        Node* delNext = delNode -> next ;
        delPrev -> next = delNext ;
        delNext -> prev = delPrev ;
    }
    
    int get(int key) {
        // if key exists 
        if (m.find(key) != m.end())
        {
            Node* resNode = m[key] ;
            int res = resNode->val ;
            m.erase(key) ;
            deleteNode(resNode) ;
            addNode(resNode) ;

            m[key] = head -> next ;
            return res ;
        }
        return -1 ;
    }
    
    void put(int key, int value) {
        // if key already exists
        if (m.find(key) != m.end())
        {
            Node* existingNode = m[key] ;
            m.erase(key) ;
            deleteNode(existingNode) ;
        }

        if (m.size() == cap)
        {
            m.erase(tail->prev->key) ;
            deleteNode(tail->prev) ;
        }

        addNode(new Node(key , value)) ;
        m[key] = head -> next ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */