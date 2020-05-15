# LRU Cache **
- 题目地址: [https://leetcode-cn.com/problems/lru-cache](https://leetcode-cn.com/problems/lru-cache)
- 执行时间: 216 ms
- 内存消耗: 39.3 MB
- 通过日期: 2020-05-13 20:29

## 题目内容
<p>运用你所掌握的数据结构，设计和实现一个  <a href="https://baike.baidu.com/item/LRU" target="_blank">LRU (最近最少使用) 缓存机制</a>。它应该支持以下操作： 获取数据 <code>get</code> 和 写入数据 <code>put</code> 。</p>

<p>获取数据 <code>get(key)</code> - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。<br>
写入数据 <code>put(key, value)</code> - 如果密钥已经存在，则变更其数据值；如果密钥不存在，则插入该组「密钥/数据值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。</p>



<p><strong>进阶:</strong></p>

<p>你是否可以在 <strong>O(1)</strong> 时间复杂度内完成这两种操作？</p>



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
        if(it != map.end()) { // 找到了，那么删除之前的，等下插入新的
            cache.erase(map[key]);
        } else { // 没找到
            // 没满
            
            // 满了
            if(cap == cache.size()) { // 删除最旧的
                auto last = cache.back();
                map.erase(last.first);
                cache.pop_back();
            }
        }
        // 插入新的
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