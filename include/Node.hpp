/**
* @file Node.hpp
* @description Node sınıfının tanımlaması yapılmıştır
* @course 1.ogretim B grubu
* @assignment 2.Odev
* @date 2 Aralık - 24 Aralık
* @author Abdülkadir USTA   abdulkadir.usta1@ogr.sakarya.edu.tr
*/
#ifndef NODE_HPP
#define NODE_HPP


#include<iostream>

using namespace std;


class Node
{
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int dt,Node* lf = NULL,Node* rg = NULL);
    
};


#endif