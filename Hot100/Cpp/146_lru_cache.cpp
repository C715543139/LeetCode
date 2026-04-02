#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    int cap;
    unordered_map<int, list<pair<int, int> >::iterator> cacheMap;
    list<pair<int, int> > cacheTable;

    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        if (cacheMap.find(key) != cacheMap.end()) {
            auto it = cacheMap[key];
            int value = it->second;
            cacheTable.erase(it);
            cacheTable.emplace_front(key, value);
            cacheMap[key] = cacheTable.begin();
            return value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            cacheTable.erase(cacheMap[key]);
        }
        if (cacheTable.size() == cap) {
            int popKey = cacheTable.back().first;
            cacheTable.pop_back();
            cacheMap.erase(popKey);
        }
        cacheTable.emplace_front(key, value);
        cacheMap[key] = cacheTable.begin();
    }
};


int main() {
    LRUCache lRUCache = LRUCache(2);
    lRUCache.put(1, 0); // 缓存是 {1=1}
    lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    cout << lRUCache.get(1) << endl; // 返回 1
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << lRUCache.get(2) << endl; // 返回 -1 (未找到)
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << lRUCache.get(1) << endl; // 返回 -1 (未找到)
    cout << lRUCache.get(3) << endl; // 返回 3
    cout << lRUCache.get(4) << endl; // 返回 4
    return 0;
}
