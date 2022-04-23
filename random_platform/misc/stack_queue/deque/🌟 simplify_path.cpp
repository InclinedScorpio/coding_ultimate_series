// https://leetcode.com/problems/simplify-path/


// Better way of doing is to use stringstream as we need data btw / /
class Solution {
public:
    string simplifyPath(string path) {     
        stringstream ss(path);
        string str;
        deque<string> dir;

        while(getline(ss, str, '/')) {
            if(str.length()==0) continue;
            if(str=="..") {
                if(dir.empty()) continue;
                dir.pop_back();
            } else if (str==".") {}
            else {
                dir.push_back(str);
            }
        }
        string res="";
        while(!dir.empty()) {
            res+="/";
            res+=dir.front();
            dir.pop_front();
        }
        return res=="" ? "/" : res;
    }
};

class Solution {
public:
    string simplifyPath(string path) {
        for(int i=0;i<path.length()-1;i++) {
            if(path[i]=='/' && path[i+1]=='/') {
                path.erase(i, 1);
                i--;
            }
        }
        // removed /// condition
        
        deque<string> dir;
        for(int i=1;i<path.length();i++) {
            string str="";
            while(i!=path.length() && path[i]!='/') {
                str+=path[i];
                i++;
            }
            if(str=="..") {
                if(dir.empty()) continue;
                dir.pop_back();
            } else if (str==".") {}
            else {
                dir.push_back(str);
            }
        }
        string res="";
        while(!dir.empty()) {
            res+="/";
            res+=dir.front();
            dir.pop_front();
        }
        return res=="" ? "/" : res;
    }
};

