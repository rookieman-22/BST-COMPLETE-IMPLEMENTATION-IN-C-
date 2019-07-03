#include<iostream>
#include<queue>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node* root;
node *getnewnode(int x)
{
    node* temp=new node();
    temp->data=x;
    temp->right=NULL;
    temp->left=NULL;
}
node *insert(int x,node *root)
{
    if(root==NULL)
    {
        root=getnewnode(x);
        return root;
    }
    else{
        if(x<=root->data)
        {
            root->left=insert(x,root->left);
            return root;
        }
        if(x>root->data)
        {
            root->right=insert(x,root->right);
            return root;
        }
    }
}
bool search(node *root,int x)
{
    if(root==NULL)
    {
      return false;
    }
    else
    {
        if(root->data==x)
            return true;
        else if(x<=root->data)
            return search(root->left,x);
        else
            return search(root->right,x);
    }
}
int findmin(node *root)
{
    if(root->left==NULL)
        return root->data;
    else
        return findmin(root->left);
}
int findmax(node *root)
{
    if(root->right==NULL)
        return root->data;
    else
        return findmax(root->right);
}
int findheight(node *root)
{
    int left,right;
    if(root==NULL)
        return -1;
    else{
        left=findheight(root->left);
        right=findheight(root->right);
        return (max(left,right)+1);
    }
}
void levelordertraversal(node *root)
{
   queue<node *>q;
   q.push(root);
   while(!q.empty())
   {
       node *current=q.front();
       cout<<current->data<<"\t";
       if(current->left!=NULL)
        q.push(current->left);
       if(current->right!=NULL)
        q.push(current->right);
       q.pop();
   }
}
void preordertraversal(node *root)
{
    if(root==NULL)
        return;
    else
     {
        cout<<root->data<<"\t";
        preordertraversal(root->left);
        preordertraversal(root->right);
     }
}
void postordertraversal(node* root)
{
    if(root==NULL)
        return ;
    else
    {
        postordertraversal(root->left);
        postordertraversal(root->right);
        cout<<root->data<<"\t";
    }
}
void inordertraversal(node *root)
{
    if(root==NULL)
        return;
    else{
        inordertraversal(root->left);
        cout<<root->data<<"\t";
        inordertraversal(root->right);
    }
}
int main()
{
    int x;
    root=NULL;
    root=insert(5,root);
    root=insert(8,root);
    root=insert(10,root);
    root=insert(24,root);
    root=insert(12,root);
    cout<<"Enter element you want to search: ";
    cin>>x;
    bool y;
    y=search(root,x);
    if(y==1)
        cout<<"Element is present in tree\n\n";
    else
        cout<<"Element is not present in tree\n\n";
    int z=findmax(root);
    cout<<"Maximum element in tree is: "<<z<<"\n\n";;
    z=findmin(root);
    cout<<"Minimum element in root is: "<<z<<"\n\n";
    z=findheight(root);
    cout<<"Height of the binary tree is: "<<z<<"\n\n";
    cout<<"Level order traversal of elements is : ";
    levelordertraversal(root);
    cout<<"\n\n";
    cout<<"Pre order traversal of elements is: ";
    preordertraversal(root);
    cout<<"\n\n";
    cout<<"Post order traversal of elements is: ";
    postordertraversal(root);
    cout<<"\n\n";
    cout<<"Inorder traversal of elements is: ";
    inordertraversal(root);
    cout<<"\n\n";

}
