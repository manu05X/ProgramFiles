/*
https://leetcode.com/problems/remove-k-digits/

402 Remove k digits

The way to solve this question is using a stack.
We initally push an element into tthe stack(non zero).
When we encounter the next element we check if it is smaller than the element present in the stack if so pop the element from
the stack and push this element.Why? because he current element has the cacpacity of producting a smaller number as compared to the latter.But we have to limit the pops upto k(cuz only k deletions allowed).
Let us use an example to understand it better:-
num = "1432219", k = 3
we first push 1 into the stack
           |         |
           |         |
           |         |   <-----Stack representation
           |   1     |
           |_________|

now we encounter 4 we check if 4 is lesser than 1 as it is not we push into the stack.

           |         |
           |         |
           |         |   <-----Stack representation
           |   4     |
           |___1_____|

then 3 comes as it is lesser than the top of the stack we pop 4 out and we push 3 in while simultaneously decrementing k . 

           |         |
           |         |
           |         |   <-----Stack representation  k=2
           |   3     |
           |___1_____|

2 beats 3 so 3 is popped out and 2 is pushed and k is decremented.

           |         |
           |         |
           |         |   <-----Stack representation  k=1
           |   2     |
           |___1_____|
2 doesnt beat 2 so it is pushed into the stack

           |         |
           |         |
           |   2     |   <-----Stack representation
           |   2     |
           |___1_____|
1 beats 2 so 2 is popped out and 1 is pushed in.

           |         |
           |         |
           |   1     |   <-----Stack representation   k=0
           |   2     |
           |___1_____|    
now we have the push whatever number is left as we have used up all our deletions

           |         |
           |   9     |
           |   1     |   <-----Stack representation
           |   2     |
           |___1_____|

           answer:-1219.

We will take another example to make sure our algorithm doesnt have leading 0s.

num = "10200", k = 1

           |         |
           |         |
           |         |   <-----Stack representation
           |   1     |
           |_________|
0 beats 1 but we should push 0 as this will cause leading zeros so we push the element if(ans.size()||c!='0') meaning
if ans.size()==0 and c=='0' it wouldnt push.

but we wedelete 1 as we have to fulfil the condition of the number of deleteions.

           |         |
           |         |
           |         |   <-----Stack representation   k=0
           |   2     |
           |_________|

           push  rest of the elements by making use of if(ans.size()||c!='0')push(element).



           |         |
           |   0     |
           |   0     |   <-----Stack representation   k=0
           |   2     |
           |_________|


           answer is 200
For optimization purposes we use a string as stack (s.push_back() and s.pop_back()).
*/
    string removeKdigits(string num, int k) 
	{
        string ans="";
        for(char &c:num)
        {
            while(ans.size() && ans.back()>c &&k)
            {
                ans.pop_back();
                k--;
            }
            if(ans.size()||c!='0')ans.push_back(c);
        }
        while(ans.size()&&k--)           //<-------this look is to make sure we fulfil the deletion condition
        {
            ans.pop_back();
        }
        return (ans=="")?"0":ans;
    }
	
	
/*
class Solution {
public:
    string removeKdigits(string num, int k) {
        // Idea is to use a stack, the number is inserted
        // when it is bigger than the stack top
        string s;
        for(int i = 0; i < num.size(); i++) 
        {
            while(!s.empty() && s.back() > num[i] && k) 
            {
                s.pop_back();
                --k;
            } 
            s += num[i];
        }
        // when digits are in non-decreasing order, remove k from last
        while(!s.empty() && k)
        {
            s.pop_back();
            --k;
        }
        // remove leading zeros
        int i = 0;
        while(i < s.size() && s[i] == '0')
            ++i;           
        
        // if the string is empty after removing zeros, then return 0, else the remaining string
        return i == s.size() ? "0" : s.substr(i);
    }
};
__________________________________________________________________________________________________________________

class Solution {
public:
    void buildLowest(string num, int k, string &res) {
        if (k == 0) {
            res.append(num);
            return;
        }

        int length = num.length();

        if (length <= k) {
            return;
        }

        int minIndex = 0;
        for (int i = 1; i <= k; i++) {
            if (num[i] < num[minIndex])
                minIndex = i;
        }

        res += num[minIndex];

        string subStr = num.substr(minIndex + 1, length - 1);

        buildLowest(subStr, k - minIndex, res);

    }

    string removeKdigits(string num, int k) {
        string result = "";

        buildLowest(num, k, result);

        if (result.length() == 0)
            result += '0';

        while(result[0] == '0' && result.length() > 1) {
            result = result.substr(1, result.length() - 1);
        }

        return result;
    }
};




*/