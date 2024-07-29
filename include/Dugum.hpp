/**
* @file Dugum.hpp
* @description Dugum sınıfının tanımlaması yapılmıştır
* @course 1.ogretim B grubu
* @assignment 2.Odev
* @date 2 Aralık - 24 Aralık
* @author Abdülkadir USTA   abdulkadir.usta1@ogr.sakarya.edu.tr
*/


#ifndef DUGUM_HPP
#define DUGUM_HPP


#include<iostream>
#include"Bst.hpp"
using namespace std;






class Dugum
{
    public:
	    BST* item;
	    Dugum* next;
	
	    Dugum( BST* item = NULL, Dugum* next = NULL);
	
};














#endif