/**
* @file Bst.hpp
* @description Bst sınıfının tanımlaması yapılmıştır
* @course 1.ogretim B grubu
* @assignment 2.Odev
* @date 2 Aralık - 24 Aralık
* @author Abdülkadir USTA   abdulkadir.usta1@ogr.sakarya.edu.tr
*/

#ifndef BST_HPP
#define BST_HPP 


#include<iostream>
#include <cmath> // avl

#include"Yigin.hpp"
#include"Node.hpp"
using namespace std;

class BST
{
    private:
    Node* root;
    Yigin* yigin;
    int satirNo;
    void printLeafNodesHelper(Node* node);

    
    
    int sumOfNonLeafNodesHelper(Node* node);
    


    Node* SwapWithLeftChild(Node* subNode);
    
    Node* SwapWithRightChild(Node* subNode);
    

    Node* SearchAndAdd(Node* &subNode,const int& item);
    

    bool Search(Node* &subNode,const int& item);
    

    bool DeleteNode(Node* &subNode);
    

    bool SearchAndDelete(Node* &subNode,const int& item);
    
    int Height(Node* subNode);
    

    void inorder(Node* subNode);
    


    void preorder(Node* subNode);
    


    void postorder(Node* subNode);
    

    void PrintLevel(Node* subNode,int level);
    
    
    public:
    
    BST();
    

    bool isEmpty();
    
    void Add(const int& item);
    

    void Delete(const int& item);
    


    bool search(const int& item);
    

    int Height();
    

    

    void Clear();
    


    void inorder();
    

    
    void preorder();
    

    
    void postorder();
    

    void levelorder();
    

    void bosalt();




    void printLeafNodes();
    


    int sumOfNonLeafNodes();
    

    void printStack();
    

    void SatirNo(int satirVal);
    

    int getSatirNo();
    

    int getValYigin();
    

    void deleteYigin();
    

    bool isBosYigin();
    

    ~BST();
    

    
};



















#endif