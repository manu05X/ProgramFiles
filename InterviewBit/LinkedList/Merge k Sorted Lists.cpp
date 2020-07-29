/*
https://leetcode.com/problems/merge-k-sorted-lists/ 
23. Merge k Sorted Lists


*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 //Gives TLE
class Solution {
    public:
    ListNode* SortedMerge(ListNode* a, ListNode* b) 
    { 
        ListNode* result = NULL; 

        /* Base cases */
        if (a == NULL) 
            return (b); 
        else if (b == NULL) 
            return (a); 

        /* Pick either a or b, and recur */
        if (a->val <= b->val) { 
            result = a; 
            result->next = SortedMerge(a->next, b); 
        } 
        else { 
            result = b; 
            result->next = SortedMerge(a, b->next); 
        } 

    return result; 
} 
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int n = lists.size();
        int last = n-1;
        // repeat until only one list is left 
        while (last != 0) 
        { 
            int i = 0, j = last; 

            // (i, j) forms a pair 
            while (i < j) 
            { 
                // merge List i with List j and store 
                // merged list in List i 
                lists[i] = SortedMerge(lists[i], lists[j]); 

                // consider next pair 
                i++, j--; 

                // If all pairs are merged, update last 
                if (i >= j) 
                    last = j; 
            } 
        } 

        return lists[0]; 
    }
};
//---------------------------------------------
//JAVA SOL
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> q = new PriorityQueue<ListNode>(Math.max(1,lists.length), new Comparator<ListNode>() {
            @Override
            public int compare(ListNode e1, ListNode e2) {
                return e1.val - e2.val;
            }
        });
        for (int i = 0; i < lists.length; i ++) {
            if (lists[i] != null) {
                q.add(lists[i]);
            }
        }
        ListNode fakeHead = new ListNode(-1);
        ListNode p = fakeHead;
        while (!q.isEmpty()) {
            ListNode n = q.poll();
            if (n.next != null) {
                q.add(n.next);
            }
            n.next = null;
            p.next = n;
            p = n;
        }
        return fakeHead.next;
    }
}
//----------------------------------------------------------





/*
Here a user defined class heap is made which consist of :-
capacity:- capacity of heap
curr:-current location of pointer
heap:array of ListnNode objects

The array notation of heap is used where left child is 2x+1 and right child is 2x+2 and parent is (x-1)/2.
The insert function is used to insert nodes to array of heap.The while loop takes care that a min heap is formed.
It checks if the newly inserted element if smaller then parent ,then it will swap thoso elements untill index reaches zero.
Extract min function is used to extract minimum and update the heap.Updation is done using heapify function.
The first node is taken and replaced by last node and then Heapify is called.
Heapify checks which element either left or right child is samller and swaps with that value.
*/

/*
//fast solution
class Heap
{
    int capacity;
    int curr;
    ListNode *heap;
    public:
    Heap(int x)
    {
        capacity=x;
        heap=new ListNode[x];
        curr=0;
    }
    int left(int x)
    {
        return 2*x+1;
    }
    int right(int x)
    {
        return 2*x+2;
    }
    int parent(int x)
    {
        return (x-1)/2;
    }
    void insert(ListNode x)
    {
        if(curr==capacity)
        {
            return;
        }
        heap[curr]=x;
        int ind=curr;
        curr++;
        while(heap[parent(ind)].val>heap[ind].val)
                   {
                       swap(heap[parent(ind)],heap[ind]);
                       ind=parent(ind);
                   }
    }
    int isEmpty()
    {
        return curr;
    }
    ListNode extractMin()
    {
        if(curr==0)
        {
            return NULL;
        }
        ListNode temp=heap[0];
        curr--;
        heap[0]=heap[curr];
        Heapify(0);
        return temp;
    }
    void Heapify(int x)
    {
        int l=left(x);
        int r=right(x);
        int sm=x;
        if(l<curr&&heap[l].val<heap[sm].val)
        {
            sm=l;
        }
        if(r<curr&&heap[r].val<heap[sm].val)
        {
            sm=r;
        }
        if(sm!=x)
        {
            swap(heap[sm],heap[x]);
                Heapify(sm);
        }   
    }
  void print()
  {
      for(int i=0;i<curr;i++)
      {
          cout<<heap[i].val<<" ";
      }
  }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size()==0)
        {
            return NULL;
        }
        int k=lists.size();
     Heap H(k);
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]!=NULL)
            {
                H.insert(lists[i][0]);        
            }
        }
        ListNode *temp=new ListNode(0);
        ListNode *ans=temp;
        
        while(H.isEmpty())
        {
            ListNode temp2=H.extractMin(); 
            ListNode *k2=new ListNode(temp2.val);
            temp->next=k2;
            temp=temp->next;
            if((temp2.next)!=NULL)
            {
            H.insert(*(temp2.next));     
            }
            }
        
        return ans->next;
    }
};
*/
