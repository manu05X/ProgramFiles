/*
//https://leetcode.com/problems/interval-list-intersections/
986. Interval List Intersections

*/

//sol->

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<vector<int>> res;
        int Aptr=0,Bptr=0;
        int sizeA = A.size();
        int sizeB = B.size();
        vector<int> temp(2);    //To push elements to res vector
        //Iterate over all intervals and store answer
        while(Aptr<sizeA && Bptr<sizeB)
        {
            if(B[Bptr][0]<=A[Aptr][1] && A[Aptr][0]<=B[Bptr][1])
            {
                temp[0] = max(A[Aptr][0],B[Bptr][0]);
                temp[1] = min(A[Aptr][1],B[Bptr][1]);
                res.push_back(temp);
            }
            //Now increment either Aptr or Bptr conditionally
            if(A[Aptr][1]>B[Bptr][1])
                Bptr+=1;
            else
                Aptr+=1;
        }
        return res;
    }
};

/*

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> v; //To push elements to v vector
        int i=0,j=0;
        //Iterate over all intervals and store answer
        while(i<A.size() && j<B.size())
		{
            int l=max(A[i][0], B[j][0]);
            int u=min(A[i][1], B[j][1]);
            if(l<=u) 
				v.push_back({l,u});
            
			if(A[i][1] < B[j][1])   //Now increment either Aptr or Bptr conditionally
				i++;
            else 
				j++;
        }
        return v;
    }
};


*/