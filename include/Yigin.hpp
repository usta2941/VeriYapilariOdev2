/**
* @file Yigin.hpp
* @description Yigin sınıfının tanımlaması yapılmıştır
* @course 1.ogretim B grubu
* @assignment 2.Odev
* @date 2 Aralık - 24 Aralık
* @author Abdülkadir USTA   abdulkadir.usta1@ogr.sakarya.edu.tr
*/

#ifndef YIGIN_HPP
#define YIGIN_HPP

#include<iostream>
using namespace std;



class Yigin
{
public:
	Yigin();
	~Yigin();
	void ekle(int veri);
	void cikar();
    bool bosmu();
    bool dolumu();
	int getir();
    void Bosalt();
    
   
private:
	void genislet(int boyut);
	int kapasite;
    int tepe;
	int* veriler;
};








#endif