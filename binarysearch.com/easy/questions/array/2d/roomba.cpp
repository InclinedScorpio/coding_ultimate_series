// https://binarysearch.com/problems/Roomba

bool solve(vector<string>& moves, int x1, int y1) {
    int x=0, y=0;
    for(int i=0;i<moves.size();i++) {
        if(moves[i]=="NORTH") {
            y++;
        }else if(moves[i]=="EAST") {
            x++;
        }else if(moves[i]=="WEST") {
            x--;
        }else {
            y--;
        }
    }
    return x==x1 and y==y1;
}