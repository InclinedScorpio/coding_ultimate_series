// https://binarysearch.com/problems/Validate-Delivery-Orders

bool solve(vector<string>& orders) {
    map<int, bool> store;
    for(int i=0;i<orders.size();i++) {
        char type = orders[i][0];
        int deliveryNumber = stoi(orders[i].substr(1, orders[i].length()-1));
        if(type=='P') {
            if(store.find(deliveryNumber)!= store.end()) 
                return false;
            store[deliveryNumber]=true;
        } else {
            if(store.find(deliveryNumber)!= store.end()) {
                if(store[deliveryNumber]) {
                    store[deliveryNumber] = false;
                } else return false;
            } else return false;
        }
    }

    for(auto storeValue: store) {
        if(storeValue.second) return false;
    }

    return true;
}
