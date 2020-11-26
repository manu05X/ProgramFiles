/*
127. Word Ladder

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Note:

*	Return 0 if there is no such transformation sequence.
*	All words have the same length.
*	All words contain only lowercase alphabetic characters.
*	You may assume no duplicates in the word list.
*	You may assume beginWord and endWord are non-empty and are not the same.

Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

*/

/*
Approach 1: Breadth First Search
Intuition

Start from beginWord and search the endWord using BFS.

Algorithm

1> Do the pre-processing on the given wordList and find all the possible generic/intermediate states. Save these intermediate states in a dictionary with key as the intermediate word and value as the list of words which have the same intermediate word.

2> Push a tuple containing the beginWord and 1 in a queue. The 1 represents the level number of a node. We have to return the level of the endNode as that would represent the shortest sequence/distance from the beginWord.

3> To prevent cycles, use a visited dictionary.

4> While the queue has elements, get the front element of the queue. Let's call this word as current_word.

5> Find all the generic transformations of the current_word and find out if any of these transformations is also a transformation of other words in the word list. This is achieved by checking the all_combo_dict.

6> The list of words we get from all_combo_dict are all the words which have a common intermediate state with the current_word. These new set of words will be the adjacent nodes/words to current_word and hence added to the queue.

7> Hence, for each word in this list of intermediate words, append (word, level + 1) into the queue where level is the level for the current_word.

8> Eventually if you reach the desired word, its level would represent the shortest transformation sequence length.


class Solution {
  public int ladderLength(String beginWord, String endWord, List<String> wordList) {

    // Since all words are of same length.
    int L = beginWord.length();

    // Dictionary to hold combination of words that can be formed,
    // from any given word. By changing one letter at a time.
    Map<String, List<String>> allComboDict = new HashMap<>();

    wordList.forEach(
        word -> {
          for (int i = 0; i < L; i++) {
            // Key is the generic word
            // Value is a list of words which have the same intermediate generic word.
            String newWord = word.substring(0, i) + '*' + word.substring(i + 1, L);
            List<String> transformations = allComboDict.getOrDefault(newWord, new ArrayList<>());
            transformations.add(word);
            allComboDict.put(newWord, transformations);
          }
        });

    // Queue for BFS
    Queue<Pair<String, Integer>> Q = new LinkedList<>();
    Q.add(new Pair(beginWord, 1));

    // Visited to make sure we don't repeat processing same word.
    Map<String, Boolean> visited = new HashMap<>();
    visited.put(beginWord, true);

    while (!Q.isEmpty()) {
      Pair<String, Integer> node = Q.remove();
      String word = node.getKey();
      int level = node.getValue();
      for (int i = 0; i < L; i++) {

        // Intermediate words for current word
        String newWord = word.substring(0, i) + '*' + word.substring(i + 1, L);

        // Next states are all the words which share the same intermediate state.
        for (String adjacentWord : allComboDict.getOrDefault(newWord, new ArrayList<>())) {
          // If at any point if we find what we are looking for
          // i.e. the end word - we can return with the answer.
          if (adjacentWord.equals(endWord)) {
            return level + 1;
          }
          // Otherwise, add it to the BFS Queue. Also mark it visited
          if (!visited.containsKey(adjacentWord)) {
            visited.put(adjacentWord, true);
            Q.add(new Pair(adjacentWord, level + 1));
          }
        }
      }
    }

    return 0;
  }
}





*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> d(wordList.begin(), wordList.end());
        if(d.count(endWord) == 0) 
            return 0;
        queue<string> q;
        q.push(beginWord);
        int res = 0;
        while(!q.empty())
        {
            res++;
            int q_size = q.size();
            for(int i = 0; i < q_size; i++)
            {
                auto curr = q.front();
                if(curr == endWord) 
                    return res;
                q.pop();
                for(int j = 0; j < curr.size(); j++)
                {
                    auto tmp = curr[j];
                    for(char c = 'a'; c <= 'z'; c++)
                    {
                        curr[j] = c;
                        if(d.count(curr) != 0)
                        {
                            d.erase(curr);
                            q.push(curr);
                        }
                    }
                    curr[j] = tmp;
                }
            }
        }
        return 0;
    }
};


/*
Approach 2: Bidirectional Breadth First Search
Intuition

The graph formed from the nodes in the dictionary might be too big. 
The search space considered by the breadth first search algorithm depends upon the branching factor 
of the nodes at each level. If the branching factor remains the same for all the nodes, the search space 
increases exponentially along with the number of levels. Consider a simple example of a binary tree. 
With each passing level in a complete binary tree, the number of nodes increase in powers of 2.

We can considerably cut down the search space of the standard breadth first search algorithm if we launch 
two simultaneous BFS. One from the beginWord and one from the endWord. We progress one node at a time from 
both sides and at any point in time if we find a common node in both the searches, we stop the search. 
This is known as bidirectional BFS and it considerably cuts down on the search space and hence reduces the 
time and space complexity.

https://leetcode.com/problems/word-ladder/Figures/127/Word_Ladder_3.png

Algorithm

1>	The algorithm is very similar to the standard BFS based approach we saw earlier.

2>	The only difference is we now do BFS starting two nodes instead of one. This also changes the termination condition of our search.

3>	We now have two visited dictionaries to keep track of nodes visited from the search starting at the respective ends.

4>	If we ever find a node/word which is in the visited dictionary of the parallel search we terminate our search, 
		since we have found the meet point of this bidirectional search. It's more like meeting in the middle 
		instead of going all the way through.

	Termination condition for bidirectional search is finding a word which is already been seen by the parallel search.

5>	The shortest transformation sequence is the sum of levels of the meet point node from both the ends. Thus, for every visited node we save its level as value in the visited dictionary.



class Solution {

  private int L;
  private Map<String, List<String>> allComboDict;

  Solution() {
    this.L = 0;

    // Dictionary to hold combination of words that can be formed,
    // from any given word. By changing one letter at a time.
    this.allComboDict = new HashMap<>();
  }

  private int visitWordNode(
      Queue<Pair<String, Integer>> Q,
      Map<String, Integer> visited,
      Map<String, Integer> othersVisited) {

    Pair<String, Integer> node = Q.remove();
    String word = node.getKey();
    int level = node.getValue();

    for (int i = 0; i < this.L; i++) {

      // Intermediate words for current word
      String newWord = word.substring(0, i) + '*' + word.substring(i + 1, L);

      // Next states are all the words which share the same intermediate state.
      for (String adjacentWord : this.allComboDict.getOrDefault(newWord, new ArrayList<>())) {
        // If at any point if we find what we are looking for
        // i.e. the end word - we can return with the answer.
        if (othersVisited.containsKey(adjacentWord)) {
          return level + othersVisited.get(adjacentWord);
        }

        if (!visited.containsKey(adjacentWord)) {

          // Save the level as the value of the dictionary, to save number of hops.
          visited.put(adjacentWord, level + 1);
          Q.add(new Pair(adjacentWord, level + 1));
        }
      }
    }
    return -1;
  }

  public int ladderLength(String beginWord, String endWord, List<String> wordList) {

    if (!wordList.contains(endWord)) {
      return 0;
    }

    // Since all words are of same length.
    this.L = beginWord.length();

    wordList.forEach(
        word -> {
          for (int i = 0; i < L; i++) {
            // Key is the generic word
            // Value is a list of words which have the same intermediate generic word.
            String newWord = word.substring(0, i) + '*' + word.substring(i + 1, L);
            List<String> transformations =
                this.allComboDict.getOrDefault(newWord, new ArrayList<>());
            transformations.add(word);
            this.allComboDict.put(newWord, transformations);
          }
        });

    // Queues for birdirectional BFS
    // BFS starting from beginWord
    Queue<Pair<String, Integer>> Q_begin = new LinkedList<>();
    // BFS starting from endWord
    Queue<Pair<String, Integer>> Q_end = new LinkedList<>();
    Q_begin.add(new Pair(beginWord, 1));
    Q_end.add(new Pair(endWord, 1));

    // Visited to make sure we don't repeat processing same word.
    Map<String, Integer> visitedBegin = new HashMap<>();
    Map<String, Integer> visitedEnd = new HashMap<>();
    visitedBegin.put(beginWord, 1);
    visitedEnd.put(endWord, 1);

    while (!Q_begin.isEmpty() && !Q_end.isEmpty()) {

      // One hop from begin word
      int ans = visitWordNode(Q_begin, visitedBegin, visitedEnd);
      if (ans > -1) {
        return ans;
      }

      // One hop from end word
      ans = visitWordNode(Q_end, visitedEnd, visitedBegin);
      if (ans > -1) {
        return ans;
      }
    }

    return 0;
  }
}

*/

