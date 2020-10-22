/*
https://leetcode.com/problems/flatten-2d-vector/
251. Flatten 2D Vector

Design and implement an iterator to flatten a 2d vector. It should support the following operations: next and hasNext.

 

Example:

Vector2D iterator = new Vector2D([[1,2],[3],[4]]);

iterator.next(); // return 1
iterator.next(); // return 2
iterator.next(); // return 3
iterator.hasNext(); // return true
iterator.hasNext(); // return true
iterator.next(); // return 4
iterator.hasNext(); // return false
 

Notes:

Please remember to RESET your class variables declared in Vector2D, as static/class variables are persisted across multiple test cases. Please see here for more details.
You may assume that next() call will always be valid, that is, there will be at least a next element in the 2d vector when next() is called.

*/

//sol->

class Vector2D {
public:
    Vector2D(vector<vector<int>> v) {
        for (vector<int> row : v) {
            for (int elem : row) {
                q.push(elem);
            }
        }
    }
    
    int next() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    bool hasNext() {
        return !q.empty();
    }
private:
    queue<int> q;
};

//M2.
//Your data is a copy of vec2d. If you copy all the data anyway, you might as well just copy it into a single simple vector<int>. Makes things easier.

class Vector2D {
    vector<int> data;
    int i = 0;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        for (auto& v : vec2d)
            data.insert(end(data), begin(v), end(v));
    }

    int next() {
        return data[i++];
    }

    bool hasNext() {
        return i < data.size();
    }
};