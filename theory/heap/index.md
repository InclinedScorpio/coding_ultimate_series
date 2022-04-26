# Heap Introduction
- A complete Binary Tree which satisfies heap property

### Binary Tree
- Tree which can have max 2 child nodes

### Complete Binary Tree
- Tree which should definitely have 2 child nodes
- Apart from the last level which can may not have 2 child nodes
- But the nodes must be filled from left to right! (IMP)

### Heap Property
1. Max heap property
- every child node must be smaller than the root node.
- root will be greater

2. Min heap property
- every child node must be greater than the root node
- root will be smaller

---
> Examples
        (Example Max Heap)
                 50
            45        47
        30     32  34    40

        (Example Min Heap)
                 10
            15        20
        20     22  22    30

---

### Height of Complete Binary Tree
- Height of complete Binary Tree is (logN)
- Hence, height of Heap is (logN)

### Heap is represented as an Array! How?

                 50
            40        45
        30     20  35    10
  
  
    [ 50, 40, 45, 30, 20, 35, 10]
      1   2   3   4   5   6   7

- This array can be used to find Root, or 2 children of that node
- Parent: floor(i/2)
- Children: Left: (2*i), right: (2*i + 1)

> That's why complete binary tree is required to implement it into array like above

----

> So a heap is basically represented in form of array & operations are also done in the array itself!

#### Heapify (To create Heap recursively)
- Heapify is used to turn a BST to Heap using recusive checking heap properties.
- Complexity: O(N)  - as it doesn't do logN for each no, here it only takes N/2-1 and for that do never runs for log N

**PROOF OF HEAPIFY TAKES O(N):**
<!--Do it here -->

----

#### PRIORITY QUEUE
- Priority queue can be used from STL
- It implements both Min-Queue/Max-Queue
- By default it implements "Max Queue"

**MAX HEAP!**
```
#include<queue>

priority_queue<int> maxHeap (arr.begin(), arr.end());

OR

priority_queue<int> maxHeap; // use push to insert!
```

**MIN HEAP!**
```
#include<queue>

priority_queue<int, vector<int>, greater<int>> maxHeap (arr.begin(), arr.end());

OR

class Comparator {
    public:
        bool operator()(int a, int b) {
            return b<a;
        }
};

priority_queue<int, vector<int>, Comparator> maxHeap; // use push to insert!
```

### Operations in Priority Queue
- push
- pop
- size
- top: to get top item!



