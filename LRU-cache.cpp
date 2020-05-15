map<int, int> ma, ma_t;
set<pair<int, int>> se;
int cap, tim;
LRUCache::LRUCache(int capacity) {
    ma_t.clear();
    ma.clear();
    se.clear();
    cap = capacity;
    tim = 0;
}

int LRUCache::get(int key) {
    if(ma_t.find(key)!=ma_t.end()){
        pair<int, int> pa = make_pair(ma_t[key], key);
        if(se.find(pa)!=se.end()){
            se.erase(pa);
            tim++;
            ma_t[key] = tim;
            se.insert(make_pair(ma_t[key], key));
            return ma[key];
            
        }
        else return -1;
    }else return -1;
}

void LRUCache::set(int key, int value) {
    if(ma.find(key)!=ma.end()){
        ma[key] = value;
        pair<int,int> pa = make_pair(ma_t[key], key);
        if(se.find(pa)!=se.end()){
            se.erase(pa);
            tim++;
            ma_t[key] = tim;
            se.insert(make_pair(ma_t[key], key));
        }else{
            if(se.size()==cap){
                pair<int, int> te = *se.begin();
                se.erase(te);
            }
            tim++;
            ma_t[key] = tim;
            se.insert(make_pair(ma_t[key], key));
        }
    }else{
        ma[key] = value;
        tim++;
        ma_t[key] = tim;
        pair<int, int> pa = make_pair(ma_t[key], key);
        if(se.size()==cap){
            pair<int, int> te = *se.begin();
            se.erase(te);
        }
        se.insert(pa);
    }
}

