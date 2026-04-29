class LRUCache {
public:
    class doubly_ll {
    public:
        int key;
        doubly_ll* prev;
        doubly_ll* next;

        doubly_ll(int val) {
            key = val;
            prev = next = NULL;
        }
    };

    unordered_map<int, pair<int, doubly_ll*>> mp;
    doubly_ll* head;
    doubly_ll* tail;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = NULL;
        tail = NULL;
    }

    void insertAtHead(doubly_ll* temp){
        temp->prev = NULL;
        temp->next = head;

        if(head) head->prev = temp;
        head = temp;

        if(tail == NULL) tail = head;
    }

    void removeNode(doubly_ll* temp){
        if(temp->prev) temp->prev->next = temp->next;
        if(temp->next) temp->next->prev = temp->prev;

        if(temp == head) head = temp->next;
        if(temp == tail) tail = temp->prev;
    }

    int get(int key) {
        auto it = mp.find(key);

        if(it == mp.end()){
            return -1;
        }

        int value = it->second.first;
        doubly_ll* node = it->second.second;

        // move to head
        removeNode(node);
        insertAtHead(node);

        return value;
    }

    void del() {
        if(tail == NULL) return;

        int key = tail->key;
        doubly_ll* temp = tail;

        removeNode(temp);
        mp.erase(key);
        delete temp;
    }

    void put(int key, int value) {
        auto it = mp.find(key);

        if(it != mp.end()){
            // update existing
            doubly_ll* node = it->second.second;
            mp[key].first = value;

            removeNode(node);
            insertAtHead(node);
        } else {
            // new node
            if(mp.size() == capacity){
                del();
            }

            doubly_ll* node = new doubly_ll(key);
            insertAtHead(node);
            mp[key] = {value, node};
        }
    }
};