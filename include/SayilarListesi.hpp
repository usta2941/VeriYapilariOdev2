/**
* @file SayilarListesi.hpp
* @description SayilarListesi sınıfının tanımlaması yapılmıştır
* @course 1.ogretim B grubu
* @assignment 2.Odev
* @date 2 Aralık - 24 Aralık
* @author Abdülkadir USTA   abdulkadir.usta1@ogr.sakarya.edu.tr
*/

#ifndef SAYILARLISTESI_HPP
#define SAYILARLISTESI_HPP


#include<iostream>
#include"Dugum.hpp"
#include"Bst.hpp"

using namespace std;







class SayilarListesi
{
	private:
		Dugum* head;
		int size;
		
		Dugum* FindPrevByPosition( int position);
		
			
	
	public:
		SayilarListesi();
		
		bool isEmpty();

		int Count();
		
        

		BST* getLinkedListInNode(int index);
        
		void add(BST* item);
		
		void insert(int index,BST* item= NULL);
		
		void remove(BST* item= NULL);
		
		void removeAt(int index);
	
		int indexOf(const BST* item= NULL); 
		
		bool find(BST* item= NULL);
		
		void clear();
		

		void print();

        void printLeaf();

        void printNodeValues();

        void printAsci();

        int minDeleteStack();

        int maxDeleteStack();

        char SonHarf();

        int SonNo();
        
        void dolan();
		
		~SayilarListesi();
		
};





#endif