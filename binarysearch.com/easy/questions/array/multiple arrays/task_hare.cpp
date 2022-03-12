// https://binarysearch.com/problems/Task-Hare

int solve(vector<int>& tasks, vector<int>& people) {
    sort(tasks.rbegin(), tasks.rend());
    sort(people.rbegin(), people.rend());

    int currPerson=0;
    int taskFinished=0;
    for(int i=0;i<tasks.size() && currPerson<people.size();i++) {
        if(tasks[i]<=people[currPerson]) {
            taskFinished++;
            currPerson++;
        }
    }
    return taskFinished;
}
