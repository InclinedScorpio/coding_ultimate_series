/**
 * 
 * QUESTION:
Reading Books:
Given number of pages inn different books and m students The books are arranged in any order (not necessarily ascending) of number of pages. Every student is assigned to read some consecutive segment of books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.

Find the maximum number of pages that a student will have to read.

Sample Input

books = [10, 20,30,15]
students = 2


Sample Output

45


Explanation:

There are 2 number of students. Books can be distributed

in following fashion :

  1) [10] and [20, 30, 15]

      Max number of pages is allocated to student

      2 with 65 pages



  2) [10, 20] and [30, 15]

      Max number of pages is allocated to student

      2 with 30 + 15 = 45 pages



  3) [10, 20, 30] and [15]

      Max number of pages is allocated to student

      1 with 60 pages

Of the 3 cases, Option 2 has the minimum pages = 45.

LOGIC: Think about it, we need to put a seperator in btw the array to divide it into subarray
- That subarray sub is the number of pages read by student
- We need to minimize the maximum value of pages read 
- Obviously the maximum number is the least value present and sum of all is max value possible
- So, solution must lie btw these 2 numbers! LOGIC!
- Let's start picking up random number and see if that's possible! How to check?

- Let's say if we are checking if 100 as max is possible
- Now we will check giving 100 to students and see if all students can take it...
- Now 2 things are possible:
1) To all given students we distributed 100 successfully! (That's our answer for now!)
2) 100 distributed to students > given! - Can't be taken as answer!

- How will 2) occur? let's say we have [50, 90, 90] - now we are trying 100 and students are 2
- So, first student got 50 (as 50+90 is not possible - max is 100), 2nd got 90 and 3rd got 90
- So required 3 students, so WE NEED TO INCREASE THE LIMIT 

- In case of 1) We must try to reduce number and then try, because we need minimum number.

- ** So we can use Binary search for this (Monotonic Binary Search!)

Q) How we came to this LOGIC??
A) We need to have max which is min, how can we do that? By having max everywhere - that's the only way to reduce it!
- Like if we have 2 numbers X, Y and we need to minimize X (X is greater), we can reduce X in such a way that (X~Y) !
- That's why above in above steps we are inserting the same number and trying to see if that would satisfy the students.

- If the number choosen is larger and all students are not getting accomodated, then obviously we need to reduce it
- If number is such that it's requiring more students then it's smaller and we need to increase it, so it can be accomodated by all students

- POINT TO NOTE IS : Although we do BS, at last, after we keep reducing, it will give exact answer as it will give answer as per pages array given
- We may have choosen 120, but after summing if it's coming to be 113 in books array, then algo will reduce 120 to 113  (Why? Because we are reducing the num in case it's satisfying criteria...)
**/ 

#include<bits/stdc++.h>
using namespace std;

bool isMaxPossible(vector<int> books, int totalStudents, int maxPages) {
    int currSum=0;
    int currStudents=1;
    for(int i=0;i<books.size();i++) {
        currSum+=books[i];
        if(currSum>maxPages) {
            currSum=books[i];
            currStudents++;
            if(currStudents>totalStudents) return false;
        }
    }
    return true;
}

int minPages(vector<int> books, int m){
    
    int left = *max_element(books.begin(), books.end());
    int right=0;
    for(int i: books) {
        right+=i;
    }

    int minAns=-1;
    while(left<=right) {
        int mid = (left+right)/2;
        if(isMaxPossible(books, m, mid)) {
            minAns=mid;
            right=mid-1;
        } else {
            left=mid+1;
        }
    }
    return minAns;
}