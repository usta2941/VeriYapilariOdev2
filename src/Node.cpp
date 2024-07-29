/**
* @file Node.cpp
* @description Node sınıfı Node dugumunun metodları olacak şekilde tasarlanmıştır
* @course 1.ogretim B grubu
* @assignment 2.Odev
* @date 2 Aralık - 24 Aralık
* @author Abdülkadir USTA   abdulkadir.usta1@ogr.sakarya.edu.tr
*/



#include"Node.hpp"

using namespace std;



Node::Node(int dt,Node* lf,Node* rg)
    {
        this->left = lf;
        this->right = rg;
        this->data = dt; 
        this->height = 0;
    };