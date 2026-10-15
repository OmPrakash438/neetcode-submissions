class TimeMap {
    unordered_map<string, vector<pair<int, string>>> m;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto& value = m[key];
        int st = 0, end = value.size() - 1;
        string res = "";

        while(st <= end){
            int mid = st + (end - st)/2;
            if(value[mid].first <= timestamp){
                res = value[mid].second;
                st = mid + 1;
            }else{
                end = mid - 1;
            }
        }

        return res;
    }
};
