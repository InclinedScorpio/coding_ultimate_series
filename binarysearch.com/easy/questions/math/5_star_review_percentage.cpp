// https://binarysearch.com/problems/5-Star-Review-Percentage

int solve(vector<vector<int>>& reviews, int threshold) {
    float fiveStar=0;
    float totalRating=0;
    for(int i=0;i<reviews.size();i++) {
        fiveStar+=reviews[i][0];
        totalRating+=reviews[i][1];
    }
    //formula
    int res = ceil( ( (fiveStar*100) - (threshold*totalRating) ) / (threshold-100) );
    return res>=0 ? res : 0;
}
