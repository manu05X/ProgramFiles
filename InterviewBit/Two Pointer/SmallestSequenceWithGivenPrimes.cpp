/*
Smallest sequence with given Primes
Given three prime number(p1, p2, p3) and an integer k. Find the first(smallest) k integers which have only p1, p2, p3 or a combination of them as their prime factors. Example: Input :
Prime numbers : [2,3,5]
k : 5 If primes are given as p1=2, p2=3 and p3=5 and k is given as 5, then the sequence of first 5 integers will be:
 Output:
{2,3,4,5,6} Explanation :
4 = p1 * p1 ( 2 * 2 ) 6 = p1 * p2 ( 2 * 3 ) Note: The sequence should be sorted in ascending order
*/
vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> result;
    
    if(D==0)        //if size is 0 return;
    return result;
    
    set<int>st;
    st.insert(A);  //insert element in set ,set will store it in ascending order
    st.insert(B);
    st.insert(C);

    while(!st.empty())
    {
        int cur_ele=*st.begin();
        st.erase(st.begin());
        result.push_back(cur_ele);
        
        if(result.size()==D)    //every time we push element we check for the given size when it became equal
            break;              //we will come out of loop and return result
            
        int p1=cur_ele*A;
        int p2=cur_ele*B;
        int p3=cur_ele*C;
        
        st.insert(p1);
        st.insert(p2);
        st.insert(p3);
    }
    
    return result;
}
