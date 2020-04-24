#include<bits/stdc++.h>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

class LRUCache {
    int _capacity;
    list<int> _keys ;
    unordered_map<int, pair<int, list<int>::const_iterator>> cache ;

    public:
    LRUCache(int capacity) : _capacity(capacity) { }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
           _keys.erase(cache[key].second);
           _keys.push_front(key);
           cache[key].second = _keys.begin();
           return cache[key].first ;
        }
        return -1 ;
    }

    void put(int key, int value ) {
        if (cache.find(key) != cache.end() ) {
            _keys.erase(cache[key].second) ;
            _keys.push_front(key) ;
            cache[key] = {value, _keys.begin()} ;
        }else {
            if(_keys.size() == _capacity) {
                cache.erase(_keys.back()) ;
                _keys.pop_back() ;
            }
            _keys.push_front(key) ;
            cache[key] = { value, _keys.begin() } ;
        }
    }
} ;



int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    LRUCache obj(2) ;

    obj.put(2, 6);
    obj.put(1, 5);

    obj.get(2);
    obj.put(5, 8) ;
    cout << obj.get(1) ;

    return 0;
}
