import java.io.*;
import java.util.*;
class Node{
    Node left,right;
    int data;
    Node(int data){
        this.data=data;
        left=right=null;
    }
}
class Solution{

	static void levelOrder(Node root)
    {
      //Write your code here
      Queue<Node> queue = new LinkedList<>(); //create empty queue for level order traversal
        queue.add(root); // enque root and initialize element in queue

        while (!queue.isEmpty()) 
        {
            Node curr = queue.remove(); //remove element from front of queue 
            System.out.print(" "+curr.data);

            if (curr.left != null) 
              queue.add(curr.left);
            if (curr.right != null) 
              queue.add(curr.right);
        }
      
    }

	public static Node insert(Node root,int data){
        if(root==null){
            return new Node(data);
        }
        else{
            Node cur;
            if(data<=root.data){
                cur=insert(root.left,data);
                root.left=cur;
            }
            else{
                cur=insert(root.right,data);
                root.right=cur;
            }
            return root;
        }
    }
    public static void main(String args[]){
            Scanner sc=new Scanner(System.in);
            int T=sc.nextInt();
            Node root=null;
            while(T-->0){
                int data=sc.nextInt();
                root=insert(root,data);
            }
            levelOrder(root);
        }	
}