/*
Road Inspection
Problem Description

Martial is a civil engineer. The king of Berland has handed Martial the job of constructing roads in his newly acquired country, Kerland. Kerland has total K unconnected villages numbered [1, 2, ..., K] which are to be connected. Unfortunately, Martial is not very skilled and starts by picking up two random villages and constructing road between them. So, the king has also hired another guy Paul to keep a check on the construction. From time to time, Paul goes for inspection and picks up two random villages to check if they are yet connected.

You have to help Paul to check if the two villages are connected.

Note:

Roads are bidirectional.
There can be case where Martial or Paul picks village i and village j such that: i = j or i and j already have a road between them.


Problem Constraints
1 <= K <= 1000000
1 <= Number of constructions + Number of inspections <= 100000



Input Format
Integer A : Number of villages K as mentioned in the problem.

vector< vector < int > > B: Each entry of B contains three numbers: (type, village_1, village_2).
If type is 0: Martial has picked the villages for construction of roads.
If type is 1: Paul is inspecting the villages to check for connectivity.
Entries are in chronological order.



Output Format
A vector of answers to inspections. Whenever the villages are inspected, push 1 if they are connected and 0 otherwise.



Example Input
Input 1:

A = 4
B = [[0, 1, 2], [0,2,3], [1,1,3], [0,3,4], [0,4,3], [1,1,4]]


Example Output
Output 1:

[1, 1]


Example Explanation
Explanation 1:

At 1st inspection, their exist a path between 1 and 3 i.e. 1 -> 2 -> 3.
At 2nd inspection, their also exist a path between 1 and 4 i.e. 1 -> 2 -> 3 -> 4.
so, the ans is [1, 1].

*/



