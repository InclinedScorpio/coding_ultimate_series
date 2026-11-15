// https://leetcode.com/problems/time-based-key-value-store/description/

class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mapper;
public:

    int checkHighest(vector<pair<int, string>>& res, int timestamp) {
        int left=0, right=res.size()-1;

        int mid;
        int saveLeastOne=-1;
        while(left<=right) {
            mid = left + (right-left)/2;

            if(res[mid].first==timestamp) {
                return mid;
            } else if(res[mid].first<timestamp) {
                left=mid+1;
                saveLeastOne=mid;
            } else {
                right=mid-1;
            }
        }
        return saveLeastOne;
    }

    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mapper[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>>& res = mapper[key];
        if(res.size()==0) return "";
        int s =  checkHighest(res, timestamp);
        if(s==-1) return "";
        return res[s].second;
    }
};

// foo  timestamp -> 

//



/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */