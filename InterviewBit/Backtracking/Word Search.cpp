//https://leetcode.com/problems/word-search/
// 79. Word Search


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
    {
		if(board.empty())
			return false;
    
		for(int i=0; i<board.size(); i++)
		{
			for(int j=0; j<board[0].size(); j++)
			{
				if(dfs(board, 0, i, j, word))
					return true;
			}
		}
    
        return false;
    }

    bool dfs(vector<vector<char>>&board, int count, int i, int j, string& word)
    {
        if(word.size() == count) //Signifies that we have reached the end of search
            return true;

        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[count])
        return false;
        //We check if element is within bounds and then check if the character at that is the same as the corresponding character in string word


        char temp = board[i][j];
        board[i][j] = ' '; //To show that we have visited this node

        bool res = dfs(board, count+1, i+1, j, word) || 
				   dfs(board, count+1, i-1, j, word) || 
				   dfs(board, count+1, i, j+1, word) ||
				   dfs(board, count+1, i, j-1, word); //DFS in all 4 directions

        board[i][j] = temp; //Restore the element after checking

        return res;
    }
};


//OR Method 2 omre or less same

class Solution {
public:
    bool findWord(vector<vector<char>>& board, string word, int index,
        int i, int j, vector<vector<bool>>& visited) {

        if (index == word.length()) { //Full word found
            return true;
        }

        if (i < 0 || i >= board.size())
            return false;

        if (j < 0 || j >= board[0].size())
            return false;

        if (visited[i][j]) //This is not to use the same cell again
            return false; 

        if (board[i][j] == word[index]) {
            //cout<<i<<" "<<j<<endl;
            visited[i][j] = true;

            /* Search in all directions regardless of the next letter found in one direction */
            bool ret1 = findWord(board, word, index + 1, i - 1, j, visited);
            bool ret2 = findWord(board, word, index + 1, i + 1, j, visited);
            bool ret3 = findWord(board, word, index + 1, i, j - 1, visited);
            bool ret4 = findWord(board, word, index + 1, i, j + 1, visited);
            bool flag = (ret1 || ret2 || ret3 || ret4);
            
            if (!flag) { //If the word is not found then unmark the node, else it will hinder searching that node again after backtracking
                visited[i][j] = false;
            }
            
            return flag;
        }

        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int rows  = board.size(), columns = 0, i = 0, j = 0;
        bool flag = false;

        if (rows) {
            columns = board[0].size();
        }

        for (i = 0; i < rows; i++) {
            for (j = 0; j < columns; j++) {
                if (word[0] == board[i][j]) { //First letter of the word found, start searching for the word
                //Create new visited everytime for every new search, otherwise if there are duplicate letters, then search will be affected
                    vector<vector<bool>> visited(rows, vector<bool> (columns, false));

                    if (findWord(board, word, 0, i, j, visited)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};