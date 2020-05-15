# LRU Cache LCCI **
- 题目地址: [https://leetcode-cn.com/problems/lru-cache-lcci](https://leetcode-cn.com/problems/lru-cache-lcci)
- 执行时间: 256 ms
- 内存消耗: 39.3 MB
- 通过日期: 2020-05-13 20:53

## 题目内容
<p>设计和构建一个“最近最少使用”缓存，该缓存会删除最近最少使用的项目。缓存应该从键映射到值(允许你插入和检索特定键对应的值)，并在初始化时指定最大容量。当缓存被填满时，它应该删除最近最少使用的项目。</p>

<p>它应该支持以下操作： 获取数据 <code>get</code> 和 写入数据 <code>put</code> 。</p>

<p>获取数据 <code>get(key)</code> - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。<br>
写入数据 <code>put(key, value)</code> - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。</p>

<p><strong>示例:</strong></p>

<pre>LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得密钥 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得密钥 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class LRUCache {
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        auto it = map.find(key);
        if(it != map.end()) {
            auto kv = *map[key];
            cache.erase(map[key]);
            cache.push_front(kv);
            map[key] = cache.begin();
            return kv.second;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto it = map.find(key);
        if(it != map.end()) {
            cache.erase(map[key]);
        } else {
            if(cap == cache.size()) {
                auto lst = cache.back();
                map.erase(lst.first);
                cache.pop_back();
            }
        }
        cache.push_front(make_pair(key, value));
        map[key] = cache.begin();
    }

private:
    int cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

```