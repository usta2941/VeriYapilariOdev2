/**
* @file Test.cpp
* @description kodu başlatır, dosyayı okur ağaclara yerleştirir, işlemleri yapar, en sonunda belleği serbest bırakır ve program sonlanır
* @course 1.ogretim B grubu
* @assignment 2.Odev
* @date 2 Aralık - 24 Aralık
* @author Abdülkadir USTA   abdulkadir.usta1@ogr.sakarya.edu.tr
*/
#include <iostream>// avl test
#include <fstream>// test
#include <sstream>// test

#include"Bst.hpp"
#include"SayilarListesi.hpp"




using namespace std;



int main()
{
    
    SayilarListesi *liste = new SayilarListesi();
    std::ifstream file("Veri.txt");

    //   Check 
    if (!file.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

  
   

    std::string line;
    int satirCounter = 1;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int number;
        
        BST* tree = new BST();

        while (iss >> number) {
            tree->Add(number);
            
            
            
        }
        liste->add(tree);
        tree->SatirNo(satirCounter);
        satirCounter++;
       
       
    }

    
    file.close();

   


    
    while(liste->Count() != 1)
    {
       system("CLS");
      


        liste->printAsci(); // avl yaprak hariç ascii değerini yazdırır
        liste->printLeaf(); // avl yaprakları stack e ekliyor
        
        while(1)
        {  
            if(liste->minDeleteStack() == 1) break; // yigit kucuk siliyor yıgıt bosaldıysa avl silinir dongu basa doner

            if(liste->maxDeleteStack() == 1) break; // yigit buyuk siliyor yıgıt bosaldıysa avl silinir dongu basa doner
        }

        
        
        
    }
    system("CLS");
    
    
    cout<<"===============================\n";
    cout<<"|                             |\n";
    cout<<"|     Son Karakter: "<<liste->SonHarf()<<"         |\n";
    cout<<"|     Avl No      : "<<liste->SonNo()<<"       |\n";
    cout<<"|                             |\n";
    cout<<"|                             |\n";
    cout<<"===============================\n";


    delete liste;




   
    return 0;
}




