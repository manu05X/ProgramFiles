/*
https://leetcode.com/problems/most-common-word/

819. Most Common Word

//After first while loop
Local Variables

p: "Bob hit a ball, the hit BALL flew far after it was hit."
b: {"hit"}
result: ""
count: 0
umap: {["it"] = 1, ["after"] = 1, ["flew"] = 1, ["the"] = 1, ["ball"] = 2, ["was"] = 1, ["a"] = 1, ["hit"] = 3, ["far"] = 1, ["bob"] = 1}
i: 55
 
 
 // After umap.erase(s) for loop
 Local Variables

p: "Bob hit a ball, the hit BALL flew far after it was hit."
b: {"hit"}
result: ""
count: 0
umap: {["it"] = 1, ["after"] = 1, ["flew"] = 1, ["the"] = 1, ["ball"] = 2, ["was"] = 1, ["a"] = 1, ["far"] = 1, ["bob"] = 1}
i: 55

// Result before ans
p: "Bob hit a ball, the hit BALL flew far after it was hit."
b: {"hit"}
result: "ball"
count: 2
umap: {["it"] = 1, ["after"] = 1, ["flew"] = 1, ["the"] = 1, ["ball"] = 2, ["was"] = 1, ["a"] = 1, ["far"] = 1, ["bob"] = 1}
i: 55
 
*/

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string result;
        int count = 0;
        unordered_map<string, int> umap;
        int i = 0;
        while(i < paragraph.size())
        {
            string result = "";
            while(i < paragraph.size() && isalpha(paragraph[i]))
            {
                result += tolower(paragraph[i]);
                i++;
            }
            if(result != "")
                umap[result]++;
            i++;
        }
        for(auto& s: banned){
            umap.erase(s);
        }
        for(auto& [key,value] : umap)
        {
            if(count < value)
            {
                result = key;
                count = value;
            }
        }
        return result;
    }
};