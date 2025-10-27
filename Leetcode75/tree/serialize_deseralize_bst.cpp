// https://leetcode.com/problems/serialize-and-deserialize-bst/description


/**
 * Think of recursion and how the nodes can be placed as node_item | node_item-left | - ....etc....
 * 
 */
class Codec {
public:
    string str="";
    int currInd=0;

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) {
            str+="|-";
            return str;
        }
        this->str += "|" + to_string(root->val);
        serialize(root->left);
        serialize(root->right);
        return this->str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string& data) {
        if(data[currInd]=='|') {
            currInd++;
            if(data[currInd]=='-' || data.length()<=currInd){
                currInd++;
                return NULL;
            }
        }
        string numVal="";
        while(data.length()>currInd && data[currInd]!='|') {
            numVal+=data[currInd];
            ++currInd;
        }
        int nodeVal = stoi(numVal);
        TreeNode* currNode = new TreeNode(nodeVal);
        currNode->left = deserialize(data);
        currNode->right = deserialize(data);
        return currNode;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

