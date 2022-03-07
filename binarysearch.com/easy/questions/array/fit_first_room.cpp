// https://binarysearch.com/problems/First-Fit-Room

int solve(vector<int>& rooms, int target) {
    int MAX=INT_MAX;

    for(int i=0;i<rooms.size();i++) {
        if(rooms[i]>=target) {
            return rooms[i];
        }
    }
    return -1;
}