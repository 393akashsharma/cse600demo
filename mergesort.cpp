#include<bits/stdc++.h>
using namespace std;
struct Node
{
  int val;
  Node* left;
  Node* right;

  Node(int element)
  {
      val= element;
      left = NULL;
      right =NULL;
  }

};

class BST
{
  Node* root;
  public:
      BST()
      {
          root =NULL;
      }

      Node* insertBST(Node* cur , int key)
      {
          if(cur == NULL)
          {
              return new Node(key);
          }
          if(key < cur->val)
          {
              cur->left = insertBST(cur->left, key);
          }
          else if(key > cur->val)
          {
               cur->right = insertBST(cur->right, key);
          }

          return cur;
      }
      void insert(int element)
      {
         root = insertBST(root, element);
      }
    void bstsearch( Node* curr ,int small ,int large)
    {
            if(curr == NULL)
                return;

            if(curr->val > large)
            {
               bstsearch(curr->left , small,large);
            }
            if(  curr->val < small)
                bstsearch(curr->right , small,large);

             if(curr->val >= small && curr->val <=large )
             {
                  bstsearch(curr->left , small,large);
                  cout<<curr->val<<" ";
                  bstsearch(curr->right , small,large);
             }
    }
    void Rangebst(int min, int max)
    {
        Node* curr = root;

        if(curr == NULL)
            return ;
        else
        {
          return bstsearch(curr , min , max);

        }

    }





};


int main()
{
    BST bst;
    int node,element,val1,val2;
    cout<<"Enter the number of node";
    cin>>node;
    for(int i=0;i<node;i++)
    {
        cin>>element;
        bst.insert(element);
    }

    cout<<"Enter the value of the range "<<endl;
    cin>>val1>>val2;
    bst.Rangebst(val1, val2);


}
