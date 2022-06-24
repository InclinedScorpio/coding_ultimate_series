// https://practice.geeksforgeeks.org/problems/implement-queue-using-array/1#

/**
 * LOGIC: 
 * 1) We need to move rear to next while inserting. Front shouldn't move while insertion
 * 2) After reaching end of array - we can do %100005 to ensure that we can insert to rear 
 * 3) Same %100005 needs to be done with front as well to ensure after reaching end, front again starts checking from starting!
 * 
 */ 

/* 

The structure of the class is
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};
 */

//Function to push an element x in a queue.
void MyQueue :: push(int x)
{
    if(rear!=0 && rear%100005+1==front%100005) return;
    arr[rear%100005]=x;
    rear++;
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{
    if(front==rear) return -1;
    int f = arr[front%100005];
    front++;
    return f;
}
