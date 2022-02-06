#include <bits/stdc++.h>
using namespace std;


class TimeMap {
    unordered_map<string, vector<pair<int, string>>> m;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto &pairs = m[key];
        pair<int, string> p = {timestamp, string({127})};
        auto i = upper_bound(pairs.begin(), pairs.end(), p);
        if (i !=  pairs.begin()){
            return (i - 1)->second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */