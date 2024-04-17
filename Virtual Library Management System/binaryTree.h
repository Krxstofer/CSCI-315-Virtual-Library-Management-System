//Name: Megan Palermo
//Description:  CSCI Group Project
//Date:  05/04/2024
//binaryTree.h: header file for the base class of the bSearchTreeType class

//D. S. Malik's binaryTreeType and nodeTypeT from the provided CSCI315_data_files.zip
//https://regent.instructure.com/courses/14753/modules/items/959303
//Chapter 19/binarySearchTreeAndVisitFunc/binaryTree.h
//search header changed by Megan Palermo
//nodeType renamed nodeTypeT by Megan Palermo to prevent confusion with queue's nodes

//Header File Binary Search Tree
#ifndef H_binaryTree
#define H_binaryTree

#include <iostream> 

using namespace std;

    //Definition of the Node
template <class elemType>
struct nodeTypeT
{
    elemType info; 
    nodeTypeT<elemType> *lLink;
    nodeTypeT<elemType> *rLink;
};
	
    //Definition of the class
template <class elemType>
class binaryTreeType
{
public:
    const binaryTreeType<elemType>& operator=
                 (const binaryTreeType<elemType>&); 
      //Overload the assignment operator.

    bool isEmpty() const;
      //Function to determine whether the binary tree is empty.
      //Postcondition: Returns true if the binary tree is empty;
      //               otherwise, returns false.

    void inorderTraversal() const;
      //Function to do an inorder traversal of the binary tree.
      //Postcondition: Nodes are printed in inorder sequence.

    void preorderTraversal() const;
      //Function to do a preorder traversal of the binary tree.
      //Postcondition: Nodes are printed in preorder sequence.

    void postorderTraversal() const;
      //Function to do a postorder traversal of the binary tree.
      //Postcondition: Nodes are printed in postorder sequence.

    void inorderTraversal(void (*visit) (elemType&)) const;
      //Function to do an inorder traversal of the binary tree.
      //The parameter visit, which is a function, specifies
      //the action to be taken at each node.
      //Postcondition: The action specified by the function 
      //               visit is applied to each node of the 
      //               binary tree.

    int treeHeight() const;
      //Function to determine the height of a binary tree.
      //Postcondition: Returns the height of the binary tree.

    int treeNodeCount() const;
      //Function to determine the number of nodes in a 
      //binary tree.
      //Postcondition: Returns the number of nodes in the 
      //               binary tree.

    int treeLeavesCount() const;
      //Function to determine the number of leaves in a 
      //binary tree.
      //Postcondition: Returns the number of leaves in the 
      //               binary tree.

    void destroyTree();
      //Function to destroy the binary tree.
      //Postcondition: Memory space occupied by each node 
      //               is deallocated.
      //               root = nullptr;

   virtual elemType* search(const elemType& searchItem) const = 0;//changed
      //Function to determine if searchItem is in the binary 
      //tree.
      //Postcondition: Returns a pointer to the item if searchItem is //changed
      //               found in the binary tree; otherwise, returns 
      //               false.


    virtual void insert(const elemType& insertItem) = 0;
      //Function to insert insertItem in the binary tree.
      //Postcondition: If there is no node in the binary tree
      //               that has the same info as insertItem, a
      //               node with the info insertItem is created
      //               and inserted in the binary search tree.

    virtual void deleteNode(const elemType& deleteItem) = 0;
      //Function to delete deleteItem from the binary tree 
      //Postcondition: If a node with the same info as 
      //               deleteItem is found, it is deleted from
      //               the binary tree.
      //               If the binary tree is empty or 
      //               deleteItem is not in the binary tree, 
      //               an appropriate message is printed.

    binaryTreeType(const binaryTreeType<elemType>& otherTree); 
      //Copy constructor

    binaryTreeType();   
      //Default constructor

    ~binaryTreeType();   
      //Destructor

protected:
    nodeTypeT<elemType>  *root;

private:
    void copyTree(nodeTypeT<elemType>* &copiedTreeRoot,
                  nodeTypeT<elemType>* otherTreeRoot);
      //Makes a copy of the binary tree to which 
      //otherTreeRoot points. 
      //Postcondition: The pointer copiedTreeRoot points to
      //               the root of the copied binary tree.

    void destroy(nodeTypeT<elemType>* &p);
      //Function to destroy the binary tree to which p points. 
      //Postcondition: Memory space occupied by each node, in 
      //               the binary tree to which p points, is 
      //               deallocated.
      //               p = nullptr;

    void inorder(nodeTypeT<elemType> *p) const;
      //Function to do an inorder traversal of the binary
      //tree to which p points.  
      //Postcondition: Nodes of the binary tree, to which p
      //               points, are printed in inorder sequence.

    void preorder(nodeTypeT<elemType> *p) const;
      //Function to do a preorder traversal of the binary
      //tree to which p points.  
      //Postcondition: Nodes of the binary tree, to which p
      //               points, are printed in preorder 
      //               sequence.

    void postorder(nodeTypeT<elemType> *p) const;
      //Function to do a postorder traversal of the binary
      //tree to which p points.  
      //Postcondition: Nodes of the binary tree, to which p
      //               points, are printed in postorder 
      //               sequence.

    void inorder(nodeTypeT<elemType> *p, 
                 void (*visit) (elemType&)) const;
      //Function to do an inorder traversal of the binary tree
      //starting at the node specified by the parameter p. 
      //The parameter visit, which is a function, specifies the
      //action to be taken at each node.
      //Postcondition: The action specified by the function visit
      //               is applied to each node of the binary tree
      //               to which p points.

    int height(nodeTypeT<elemType> *p) const;
      //Function to determine the height of the binary tree
      //to which p points. 
      //Postcondition: Height of the binary tree to which 
      //               p points is returned.

    int max(int x, int y) const;
      //Function to determine the larger of x and y.
      //Postcondition: Returns the larger of x and y.

    int nodeCount(nodeTypeT<elemType> *p) const;
      //Function to determine the number of nodes in 
      //the binary tree to which p points. 
      //Postcondition: The number of nodes in the binary 
      //               tree to which p points is returned.

    int leavesCount(nodeTypeT<elemType> *p) const;
      //Function to determine the number of leaves in  
      //the binary tree to which p points 
      //Postcondition: The number of leaves in the binary 
      //               tree to which p points is returned.
};

	//Definition of member functions

template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
    root = nullptr;
}

template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
    return (root == nullptr);
}

template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
{
    inorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::preorderTraversal() const
{
    preorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::postorderTraversal() const
{
    postorder(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeHeight() const
{
    return height(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeNodeCount() const
{
    return nodeCount(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const
{
    return leavesCount(root);
}

template <class elemType>
void  binaryTreeType<elemType>::copyTree
                       (nodeTypeT<elemType>* &copiedTreeRoot,
                        nodeTypeT<elemType>* otherTreeRoot)
{
    if (otherTreeRoot == nullptr)
        copiedTreeRoot = nullptr;
    else
    {
        copiedTreeRoot = new nodeTypeT<elemType>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
        copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
    }
} //end copyTree

template <class elemType>
void binaryTreeType<elemType>::inorder
                              (nodeTypeT<elemType> *p) const
{
    if (p != nullptr)
    {
        inorder(p->lLink);
        cout << p->info << " ";
        inorder(p->rLink);
    }
}

template <class elemType>
void binaryTreeType<elemType>::preorder
                              (nodeTypeT<elemType> *p) const
{
    if (p != nullptr)
    {
        cout << p->info << " ";
        preorder(p->lLink);
        preorder(p->rLink);
    }
}

template <class elemType>
void binaryTreeType<elemType>::postorder
                              (nodeTypeT<elemType> *p) const
{
    if (p != nullptr)
    {
        postorder(p->lLink);
        postorder(p->rLink);
        cout << p->info << " ";
    }		
}

   //Overload the assignment operator
template <class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::
        operator=(const binaryTreeType<elemType>& otherTree)
{ 
    if (this != &otherTree) //avoid self-copy
    {
        if (root != nullptr)   //if the binary tree is not empty,
                            //destroy the binary tree
            destroy(root);

        if (otherTree.root == nullptr) //otherTree is empty
            root = nullptr;
        else
            copyTree(root, otherTree.root);
    }//end else

    return *this; 
}

template <class elemType>
void  binaryTreeType<elemType>::destroy(nodeTypeT<elemType>* &p)
{
    if (p != nullptr)
    {
        destroy(p->lLink);
        destroy(p->rLink);
        delete p;
        p = nullptr;
    }
}

template <class elemType>
void  binaryTreeType<elemType>::destroyTree()
{
    destroy(root);
}

	//copy constructor
template <class elemType>
binaryTreeType<elemType>::binaryTreeType
                (const binaryTreeType<elemType>& otherTree)
{
    if (otherTree.root == nullptr) //otherTree is empty
        root = nullptr;
    else
        copyTree(root, otherTree.root);
}

    //Destructor
template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
    destroy(root);
}

template<class elemType>
int binaryTreeType<elemType>::height
                             (nodeTypeT<elemType> *p) const
{
    if (p == nullptr)
        return 0;
    else
        return 1 + max(height(p->lLink), height(p->rLink));
}

template <class elemType>
int binaryTreeType<elemType>::max(int x, int y) const
{
    if (x >= y)
        return x;
    else
        return y;
}

template <class elemType>
int binaryTreeType<elemType>::nodeCount(nodeTypeT<elemType> *p) const
{
    cout << "Write the definition of the function nodeCount."
         << endl;

    return 0;
}

template <class elemType>
int binaryTreeType<elemType>::leavesCount(nodeTypeT<elemType> *p) const
{
    cout << "Write the definition of the function leavesCount."
         << endl;

    return 0;
}

template <class elemType>
void binaryTreeType<elemType>::inorderTraversal
                        (void (*visit) (elemType& item)) const
{ 
    inorder(root, *visit);
}

template <class elemType> 
void binaryTreeType<elemType>::inorder(nodeTypeT<elemType>* p,
                         void (*visit) (elemType& item)) const
{
    if (p != nullptr)
    {
        inorder(p->lLink, *visit);
        (*visit)(p->info);
        inorder(p->rLink, *visit);
    }
}

#endif
