/**
* @file Bst.cpp
* @description Bst sınıfı avl ağacımızın metodları olacak şekilde tasarlanmıştır
* @course 1.ogretim B grubu
* @assignment 2.Odev
* @date 2 Aralık - 24 Aralık
* @author Abdülkadir USTA   abdulkadir.usta1@ogr.sakarya.edu.tr
*/

#include"Bst.hpp"


using namespace std;


void BST::printLeafNodesHelper(Node* node)
    {
        if (node == NULL) {
            return;}
        
        
        if (node->left == NULL && node->right == NULL) {
            yigin->ekle(node->data);
    }
    
    printLeafNodesHelper(node->left);
    printLeafNodesHelper(node->right);
    }

    
    
int BST::sumOfNonLeafNodesHelper(Node* node)
    {
    if (node == NULL || (node->left == NULL && node->right == NULL)) {
        return 0;
    }

    return node->data + sumOfNonLeafNodesHelper(node->left) + sumOfNonLeafNodesHelper(node->right);
    }


Node* BST::SwapWithLeftChild(Node* subNode)
    {
        Node* tmp = subNode->left;
        subNode->left = tmp->right;
        tmp->right = subNode;

        subNode->height = Height(subNode);
        tmp->height = 1 + max(Height(tmp->left),subNode->height);

        return tmp;

    }


Node* BST::SwapWithRightChild(Node* subNode)
    {
        Node* tmp = subNode->right;
        subNode->right = tmp->left;
        tmp->left = subNode;

        subNode->height = Height(subNode);
        tmp->height = 1 +max(Height(tmp->right),subNode->height);

        return tmp;
    }

Node* BST::SearchAndAdd(Node* &subNode,const int& item)
    {   
        
        if(subNode == NULL)
        {
            subNode= new Node(item);
            Yigin *rootYigin = new Yigin();
            yigin = rootYigin;
        } 
         
        else if(item <= subNode->data)
        {
            subNode->left = SearchAndAdd(subNode->left,item);

            if(Height(subNode->left) == Height(subNode->right) + 2)
            {
                if(item < subNode->left->data)
                {
                    subNode = SwapWithLeftChild(subNode);
                }
                else
                {
                    subNode->left = SwapWithRightChild(subNode->left);
                    subNode = SwapWithLeftChild(subNode);
                }
            }
        }         
        else
        {
            subNode->right = SearchAndAdd(subNode->right,item);

            if(Height(subNode->right) == Height(subNode->left) + 2)
            {
                if(item > subNode->right->data)
                {
                    subNode = SwapWithRightChild(subNode);
                }
                else
                {
                    subNode->right = SwapWithLeftChild(subNode->right);
                    subNode = SwapWithRightChild(subNode);
                }
            }

        }
        
        subNode->height = Height(subNode);

        return subNode;
    }

bool BST::Search(Node* &subNode,const int& item)
    {
        if(subNode == NULL) return false;
        if(subNode->data == item) return true;
        if(item < subNode->data)
            return Search(subNode->left,item);// dikkat
        else
            return Search(subNode->right,item); // dikkat
        
    }

bool BST::DeleteNode(Node* &subNode)
    {
        Node* delNode = subNode;

        if(subNode->right == NULL) subNode = subNode->left;
        else if(subNode->left == NULL) subNode = subNode->right;
        else
        {
            delNode = subNode->left;
            Node* parent = subNode;
            while(delNode->right != NULL)
            {
                parent = delNode;
                delNode = delNode->right;
            }

            subNode->data = delNode->data;
            if(parent == subNode) subNode->left = delNode->left;
            else parent->right = delNode->left;

        }

        delete delNode;
        return true;
    }

bool BST::SearchAndDelete(Node* &subNode,const int& item)
    {
        if(subNode == NULL) return false;
        if(subNode->data == item) return DeleteNode(subNode);
        else if(item < subNode->data)
            return SearchAndDelete(subNode->left,item);
        else    
            return SearchAndDelete(subNode->right,item);

    }

int BST::Height(Node* subNode)
    {
        if(subNode == NULL) return -1;
        return 1+max(Height(subNode->left), Height(subNode->right));
    }

void BST::inorder(Node* subNode)
    {
        if(subNode != NULL)
        {
            inorder(subNode->left);
            cout<<subNode->data<<" ";
            inorder(subNode->right);

        }
    }


void BST::preorder(Node* subNode)
    {
        if(subNode != NULL)
        {
            cout<<subNode->data<<" ";
            preorder(subNode->left);
            preorder(subNode->right);
        }
    }


void BST::postorder(Node* subNode)
    {
        if(subNode != NULL)
        {
            postorder(subNode->left);   
            postorder(subNode->right);
            cout<<subNode->data<<" ";

        }
    }

void BST::PrintLevel(Node* subNode,int level)
    {
        if(subNode == NULL) return;
        if(level == 0) cout<<subNode->data<<" ";
        else
        {
            PrintLevel(subNode->left,level-1);
            PrintLevel(subNode->right,level-1);
        }
    }
    

    
BST::BST()
    {
        root = NULL;
        yigin = NULL;
    }

bool BST::isEmpty()
    {
        return root==NULL;
    }

void BST::Add(const int& item)
    {
       if(root != NULL) 
       {
            if(search(item)) return; // sonra eklendi
       }
       root= SearchAndAdd(root,item);
    }

void BST::Delete(const int& item)
    {
       if(SearchAndDelete(root,item) == false) throw "item not found";
    }


bool BST::search(const int& item)
    {
        return Search(root,item);
    }

int BST::Height()
    {
     return Height(root);
    }

    

void BST::Clear()
    {   
        
        while(!isEmpty()) DeleteNode(root);
        delete yigin;
    }


void BST::inorder()
    {
        inorder(root);
    }

    
void BST::preorder()
    {
        preorder(root);
    }

    
void BST::postorder()
    {
        postorder(root);
    }

void BST::levelorder()
    {
        int h = Height();

        for(int level= 0; level <= h;level++)
        {
            PrintLevel(root,level);
        }

    }

void BST::bosalt()
{
    yigin->Bosalt();
    /*
    while(!yigin->bosmu())
    {
        yigin->cikar();
    }*/
}



void BST::printLeafNodes() 
    {
    printLeafNodesHelper(root);
    }


int BST::sumOfNonLeafNodes() {
    return sumOfNonLeafNodesHelper(root);
    }

void BST::printStack()
    {
        
            while(!yigin->bosmu())
            {
                cout<<yigin->getir()<<" ";
                yigin->cikar();
            }
                   
    }

void BST::SatirNo(int satirVal)
    {
        satirNo = satirVal;
    }

int BST::getSatirNo()
    {
        return satirNo;
    }

int BST::getValYigin()
    {
        return yigin->getir();
    }

void BST::deleteYigin()
    {
        yigin->cikar();
    }

bool BST::isBosYigin()
    {
        return yigin->bosmu();
    }

BST::~BST()
    {
        Clear();
    }





    
    

