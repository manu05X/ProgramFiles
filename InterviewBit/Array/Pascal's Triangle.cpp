/*
https://leetcode.com/problems/pascals-triangle/
118. Pascal's Triangle
*/

//sol->

vector<vector<int>> generate(int numRows) {
	vector <vector <int>> pascalTriangle;
	for (int i = 0; i < numRows; i++) {
		vector <int> row;
		for (int j = 0; j < i + 1; j++) { 
			if (j == 0 || j == i)  //edges
				row.push_back(1);
			else {
				if (i != 1) { 
					row.push_back(pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j]);
				}
			}
		}
		pascalTriangle.push_back(row);
	}
	return pascalTriangle;
}

//2nd method
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(numRows==0) return {};
        while(numRows!=1)
        {
            vector<int> temp;
            temp.push_back(1);
            for(int i = 0; i<ans.size()-1;i++)
            {
                temp.push_back(ans[ans.size()-1][i]+ans[ans.size()-1][i+1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
            numRows--;
        }
        return ans;
    }
};

//3rd Method

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
         vector<vector<int>> res(numRows);
        
        for(int i=0;i<numRows; i++){
            
            res[i].resize(i+1);
            
            res[i][0]=res[i][i]=1;  //putting 1 manually in 1st and last column
            
            for(int j=1;j<i;j++){
                
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
            
        }
        return res;
    }
};