// https://binarysearch.com/problems/3-and-7

/**
 * TIP: Chicken McNugget Algo can be used :)
 * Find Chicken McNugget in (theory > math )
 * 
 */ 
bool solve(int n) {
    int ind=1, indThree=1;
    while(7*ind<=n || 3*indThree<=n) {
        if(7*ind<=n && (n - (7*ind))%3==0) {
            return true;
        }
        if(3*indThree<=n && (n - (3*ind))%7==0) {
            return true;
        }
        indThree++;
        ind++;
    }
    return false;   
}