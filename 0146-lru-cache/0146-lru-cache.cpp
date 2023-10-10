class LRUCache {
public:
    unordered_map<int,int> mp;
    list<int> lst;
    unordered_map<int,list<int>::iterator> address;
    int cap;
    int siz;
    LRUCache(int capacity) {
        cap = capacity;
        siz = 0;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        list<int>::iterator itr = address[key];
        lst.erase(itr);
        address.erase(key);
        lst.push_front(key);
        address[key] = lst.begin();
        return mp[key];
    }
    
    void put(int key, int value) {
       if(mp.find(key)!=mp.end()){
           siz--;
           lst.erase(address[key]);
           address.erase(key);
           mp.erase(key);
       } 
       if(siz==cap){
           int k = lst.back();
           lst.pop_back();
           address.erase(k);
            mp.erase(k);
            siz--;
       }
       siz++;
       lst.push_front(key);
       address[key] = lst.begin();
       mp[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */