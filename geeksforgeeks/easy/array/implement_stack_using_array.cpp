// https://practice.geeksforgeeks.org/problems/implement-stack-using-array/1#

void MyStack :: push(int x)
{
    arr[top+1]=x;
    top++;
}

//Function to remove an item from top of the stack.
int MyStack :: pop()
{
    if(top==-1) return -1;
    int toReturn = arr[top];
    top--;
    return toReturn;
}