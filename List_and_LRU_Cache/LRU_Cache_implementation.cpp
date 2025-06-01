#include <iostream>
#include "ArrayBasedMyList.h"
// #include "LinkedListBasedMyList.h"
using namespace std;

template <class K, class V>
class LRUCache
{
private:
    int lruSize;
    int lruCapacity;
    MyList<K> keyList;
    MyList<V> valueList;

public:
    LRUCache(int capacity)
    {
        lruCapacity = capacity;
        lruSize = 0;
    }
    V get(K key)
    {
        int index = keyList.find(key);
        if (index != -1)
        {
            keyList.setToPos(index);
            K tempKey = keyList.getValue();
            keyList.erase();
            valueList.setToPos(index);
            V tempValue = valueList.getValue();
            valueList.erase();
            keyList.pushBack(tempKey);
            valueList.pushBack(tempValue);
            return tempValue;
        }
        return -1;
    }
    void put(K key, V value)
    {
        int index = keyList.find(key);
        if (index != -1)
        {
            keyList.setToPos(index);
            valueList.setToPos(index);
            keyList.erase();
            valueList.erase();
            keyList.pushBack(key);
            valueList.pushBack(value);
        }
        else
        {
            keyList.pushBack(key);
            valueList.pushBack(value);
            lruSize++;
            if (lruSize > lruCapacity)
            {
                keyList.setToBegin();
                valueList.setToBegin();
                keyList.erase();
                valueList.erase();
                lruSize--;
            }
        }
    }
};
int main()
{
    FILE *fin, *fout;
    fin = freopen("lru_input.txt", "r", stdin);
    fout = freopen("lru_output.txt", "w", stdout);
    int capacity;
    cin >> capacity;
    LRUCache<int, int> cache(capacity);
    int query;
    cin >> query;
    for (int i = 0; i < query; i++)
    {
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            int key;
            cin >> key;
            cout << cache.get(key) << endl;
        }
        else if (choice == 2)
        {
            int key, value;
            cin >> key >> value;
            cache.put(key, value);
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}