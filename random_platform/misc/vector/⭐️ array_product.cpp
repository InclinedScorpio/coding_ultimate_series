/**
 * QUESTION: Array Product
 * 
 * <Array Products>
 * 
 * Implement a function that takes in a vector of integers, and returns a vector of the same length, where each element in the output array is equal to the product of every other number in the input array. Solve this problem without using division.
 * In other words, the value at output[i] is equal to the product of every number in the input array other than input[i]. You can assume that answer can be stored inside int datatype and no-overflow will occur due to products.
 * 
 * Sample Input 
 * Both inputs and outputs are vectors.
 * {1,2,3,4,5}
 * 
 * Sample Output
 * {120, 60, 40, 30, 24}
 * 
 */ 


/**
 * LOGIC: Keep product from left and right.
 * - Now traverse and product left[i-1] * right[i+1] ! 
 * 
 * COMPLEXITY: O(N)
 * 
 */ 
vector<int> productArray(vector<int> arr){
    
    //Create an output Array
    int n = arr.size();
    vector<int> output(n,1);
    
    //update the output array and return
    //complete the code
    
    vector<int> fromLeft;
    vector<int> fromRight;
    
    int leftProd=1, rightProd = 1;
    int fromReverseIndex=arr.size()-1;
    for(int i=0;i<n;i++) {
        leftProd = arr[i]*leftProd;
        fromLeft.push_back(leftProd);
        rightProd = arr[fromReverseIndex]* rightProd;
        fromRight.insert(fromRight.begin(), rightProd);
        fromReverseIndex--;
    }
    
    output[0]=fromRight[1];
    for(int i=1;i<n-1;i++) {
        output[i]= fromLeft[i-1]*fromRight[i+1];
    }
    output[n-1]=fromLeft[n-2];
    return output;
}
