/**
* @file Dugum.cpp
* @description Dugum sınıfı avl ağacımızın dügümü olacak şekilde tasarlanmıştır
* @course 1.ogretim B grubu
* @assignment 2.Odev
* @date 2 Aralık - 24 Aralık
* @author Abdülkadir USTA   abdulkadir.usta1@ogr.sakarya.edu.tr
*/

#include"Dugum.hpp"





Dugum::Dugum( BST* item, Dugum* next)
	{
		this->item = item;
		this->next = next;
	};