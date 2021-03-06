#include<iostream>
using namespace std;
struct rec
{
	long num;
    rec *left;
    rec *right;
    bool rthread;
}*tree;
class searchTree
{
 private:
         int count;
         long sum;
 public: 
        rec *delnum(long,rec *);
	    rec *insert(rec *,long);
	    void deletenode(long,rec *);
	    void search(rec *,long);
	    void preorder(rec *);
	    void inorder(rec *);
	    void postorder(rec *);
        void showCount();
        void showSum();
        int depth(rec *);
	    searchTree()
	    {
		tree=NULL;
		count=0;
		sum=0;
	    }
};
int main()
{
    int choice;
    long digit;
    int element;
    searchTree ST;
    do
    {
        cout<<endl<<"Enter 1: Insert a node in the BST";
		cout<<endl<<"Enter 2: Search a node in BST";
		cout<<endl<<"Enter 3: Display(preorder)the BST";
		cout<<endl<<"Enter 4: Display(inorder)the BST";
		cout<<endl<<"Enter 5: Display(postorder) the BST";
		cout<<endl<<"Enter 6: Delete the element";
        cout<<endl<<"Enter 7: Count the number of nodes";
		cout<<endl<<"Enter 8: Calculate the depth of the tree";
		cout<<endl<<"Enter 9: Calculate the number of leaf nodes";
		cout<<endl<<"Enter 10: Calculate the sum of all the nodes";
		cout<<endl<<"Enter 11: Exit";
		cout<<endl<<"Enter your choice ";  
 
        cin>>choice;
        cout<<endl;
		switch(choice)
	    {
		   case 1: cout<<"Enter value: To quit enter 0"<<endl;
			       cin>>digit;
			       while(digit!=0)
				   {
				                  tree=ST.insert(tree,digit);
				                  cin>>digit;
                   };
                   break;
		   case 2: cout<<"Enter the number to be searched";
			       cin>>digit;
			       ST.search(tree,digit);
			       break;
		   case 3: cout<<endl<<"preorder traversing TREE"<<endl;
			       ST.preorder(tree);
                   break;
		   case 4: cout<<endl<<"inorder traversing TREE"<<endl;
			       ST.inorder(tree);
                   break;
		   case 5: cout<<endl<<"postorder traversing TREE"<<endl;
			       ST.postorder(tree);
                   break;
		   case 6: cout<<"Enter element which do you want delete from  the BST"<<endl;
			       cin>>digit;
			       ST.deletenode(digit,tree);
			       break;
           case 7: ST.showCount();
                   break;
           case 8: cout<<"The depth of the tree is"<<ST.depth(tree);
                   break;
           case 9:
           case 10: ST.showSum();
		   case 11: cout<<"END"<<endl;
			       break;
		};
  }while(choice!=11);
  system("pause");
  return 0;
}
rec * searchTree::insert(rec *tree,long digit)
{
	if(tree==NULL)
	  {
		tree=new rec;
		tree->left=tree->right=NULL;
		tree->num=digit;
		count++;
		sum+=digit;
	  }
     else
	  if(digit<tree->num)
		tree->left=insert(tree->left,digit);
     else
	  if(digit>tree->num)
		tree->right=insert(tree->right,digit);
     else if(digit==tree->num)
	    {
	       cout<<"Duplicate node:Node not added";
        }
	    return(tree);
}
void searchTree::deletenode(long digit,rec *node)
{
    rec *r,*q,*p=node,*temp;
    bool l=false;
    if(tree==NULL)
    {
                  cout<<endl<<"Tree is empty.";
    }
    if(digit<node->num)
    {
                       p=node;
                       l=true;
                       deletenode(digit,node->left);
    }                   
    if(digit>node->num)
    {
                       p=node;
                       l=false;
                       deletenode(digit,node->right);
    }                   
    q=node;
    if((q->right==NULL)&&(q->left==NULL))
    {
                                         if(l==true)
                                         p->left=NULL;
                                         else
                                         p->right=NULL;
                                         delete q;
    }                         
    else 
    {
         if(q->right==NULL)
         {
                           r=q->left;
                           if(l==true)
                           p->left=r;
                           else
                           p->right=r;
                           delete q;
         }                  
         else if(q->left==NULL)
         {
              r=q->right;
              if(l==true)
              p->left=r;
              else
              p->right=r;
              delete q;
         }
         else
         {
             r=q->right;
             if(r->left=NULL)
             {
                        if(l==true)
                        p->left=r;
                        else
                        p->right=r;
             }
             else
             {
                 while(r->left!=NULL)
                 {
                          temp=r;
                          r=r->left;
                 }
                 q->num=r->num;
                 temp->left==NULL;
                 delete r;
                 return;                 
             }
         }
    }                                   
}
void searchTree::search(rec *tree,long digit)
{
	if(tree==NULL)
	   cout<<"The number does not exits"<<endl;
   else
	if(digit==tree->num)
	cout<<endl<<"Number is "<<digit;
   else
	if(digit<tree->num)
	   search(tree->left,digit);
   else
	  search(tree->right,digit);
}

void searchTree::preorder(struct rec *tree)
{
	if(tree!=NULL)
	  {
		cout<<endl<<tree->num;
		preorder(tree->left);
		preorder(tree->right);
	  }
}

void searchTree::inorder(struct rec *tree)
{
	if(tree!=NULL)
	    {
		inorder(tree->left);
		cout<<endl<<tree->num;
		inorder(tree->right);
	    }
}
void searchTree::postorder(struct rec *tree)
{
	if(tree!=NULL)
	  {
		postorder(tree->left);
		postorder(tree->right);
		cout<<endl<<tree->num;
	  }

}
void searchTree::showCount()
{
     cout<<"The no. of nodes are "<<count<<endl;
}
void searchTree::showSum()
{
     cout<<"The sum of all the nodes are "<<sum<<endl;
}
int searchTree:: depth(rec *p)
{
    static int h1=0,h2=0;
    if(p!=NULL)
    {
               
    {
               h1=depth(p->left)+1;
               h2=depth(p->right)+1;
    }
    if(h1>h2)
    return h1;
    else 
    return h2;
    }
    else
    return 0;
}


    
    
     
