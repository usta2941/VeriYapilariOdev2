/**
* @file SayilarListesi.cpp
* @description SayilarListesi sınıfı avl ağacımızı yığınları ile beraber tutar, Gerekli işlemleri gerçekleştirir.
* @course 1.ogretim B grubu
* @assignment 2.Odev
* @date 2 Aralık - 24 Aralık
* @author Abdülkadir USTA   abdulkadir.usta1@ogr.sakarya.edu.tr
*/



#include"SayilarListesi.hpp"




Dugum* SayilarListesi::FindPrevByPosition( int position)  // tamam
		{
			if(position<0 || position>size) throw "index out of range";
			
			int index=1;
			
			for( Dugum* itr = head; itr != NULL; itr= itr->next,index++)
			{
				if(position == index) return itr;
			}
			return NULL;
		}

SayilarListesi::SayilarListesi()
		{
			head = NULL;
			size = 0;
		}


bool SayilarListesi::isEmpty()
		{
			return size == 0;
		}

int SayilarListesi::Count()
        { 
			return size;
		}

BST* SayilarListesi::getLinkedListInNode(int index)
    {
        	Dugum* current = head;
        	int currentIndex = 0;

        	// SayilarListesi'ni tarayarak hedef index değerine ulaş
        	while (current != nullptr) {
            	if (currentIndex == index) {
                	return current->item; 
            }
            current = current->next;
            currentIndex++;
        }

        return nullptr;
    }

void SayilarListesi::add(BST* item) 
		{
			insert(size,item); 
		}

void SayilarListesi::insert(int index,BST* item)
		{
			if(index == 0) 
				head = new Dugum(item,head);
			else
			{
				Dugum* prev = FindPrevByPosition(index);
				prev->next = new Dugum(item,prev->next);
			}
			size++;
		}

void SayilarListesi::remove(BST* item) 
		{
			int index = indexOf(item);
			removeAt(index);
		}

void SayilarListesi::removeAt(int index)  
		{
			if(size == 0) throw "empty list";
			Dugum* del;
			
			if(index == 0)
			{
				del = head;
				head = head->next;
			}
			else
			{
				Dugum* prev = FindPrevByPosition(index);
				del = prev->next;
				prev->next = FindPrevByPosition(index)->next->next;
			}
			
			delete del;
			size--;
		}

int SayilarListesi::indexOf(const BST* item)   
		{
			int index = 0;
			for(Dugum* itr= head; itr != NULL;itr= itr->next,index++)
				if(itr->item == item) return index;
			
			throw "index out of range";
		}

bool SayilarListesi::find(BST* item)
		{
			for(Dugum* itr = head; itr!= NULL;itr = itr->next)
			{
				if(itr->item == item)
					return true;
			}
			
			return false;
		}

void SayilarListesi::clear()   
		{
			while(!isEmpty())
				removeAt(0);
		}

void SayilarListesi::print() 
		{ 
			

			for(Dugum* itr = head; itr!= NULL;itr = itr->next)
			{
				
				itr->item->inorder();
				cout<<"\n"<<"-----------"<<endl;
			}
		}
void SayilarListesi::printLeaf()
        {
            for(Dugum* itr = head; itr!= NULL;itr = itr->next)
			{
				itr->item->bosalt();
				itr->item->printLeafNodes();
                
			}
        }

void SayilarListesi::printNodeValues()
        {
            for(Dugum* itr = head; itr!= NULL;itr = itr->next)
			{
				
				cout<<itr->item->sumOfNonLeafNodes();
				cout<<"\n"<<"-----------"<<endl;
			}
        }

void SayilarListesi::printAsci()
        {
            for(Dugum* itr = head; itr!= NULL;itr = itr->next)
			{
                int ascii = itr->item->sumOfNonLeafNodes()%(90-65 + 1) + 65;

                if (ascii >= 0 && ascii <= 127) {
                    char asciiChar = static_cast<char>(ascii);
                    std::cout<<asciiChar;
                }else
                {
                    std::cout << "Invalid ASCII value: " << ascii << std::endl;
                }
				
			}
        }

char SayilarListesi::SonHarf()
        {
            int ascii = head->item->sumOfNonLeafNodes()%(90-65 + 1) + 65;
            if (ascii >= 0 && ascii <= 127)
            {
                    char asciiChar = static_cast<char>(ascii);
                    return asciiChar;
            }
            else
            {
                std::cout << "Invalid ASCII value: " << ascii << std::endl;
            }
        }

int SayilarListesi::SonNo()
{
    return head->item->getSatirNo();
}

int SayilarListesi::minDeleteStack()
{
    int min = head->item->getValYigin();
    for(Dugum* itr = head; itr!= NULL;itr = itr->next)
	{
        if(min > itr->item->getValYigin())
        {
            min = itr->item->getValYigin();
        
        } 
	}

    for(Dugum* itr = head; itr!= NULL;itr = itr->next)
	{
        if(itr->item->getValYigin() == min) 
        {
            itr->item->deleteYigin();
            if(itr->item->isBosYigin())
            {   
                itr->item->Clear();
                remove(itr->item);
                return 1; // stack ve avl silindi

            }
            return 0;
        }
	}

    return 0;

}

int SayilarListesi::maxDeleteStack()
{
    int max = head->item->getValYigin();
    for(Dugum* itr = head; itr!= NULL;itr = itr->next)
	{
        if(max < itr->item->getValYigin()) max = itr->item->getValYigin();
	}

    for(Dugum* itr = head; itr!= NULL;itr = itr->next)
	{
        if(itr->item->getValYigin() == max) 
        {
            itr->item->deleteYigin();
            if(itr->item->isBosYigin())
            {
                itr->item->Clear();
                remove(itr->item);
                return 1; // stack ve avl silindi  (basa don)
            }
            return 0;
        }
	}

    return 0; // stack eleman cikti, avl silinmedi (devam et)

}


void SayilarListesi::dolan()
{
    for(Dugum* itr = head; itr!= NULL;itr = itr->next)
	{
        cout<<"---------------"<<endl;
        cout<<"avl no: "<<itr->item->getSatirNo()<<endl;
         int ascii = itr->item->sumOfNonLeafNodes()%(90-65 + 1) + 65;
            if (ascii >= 0 && ascii <= 127)
            {
                    char asciiChar = static_cast<char>(ascii);
                    cout<<"avl harf: "<<asciiChar<<endl;
            }
        
        itr->item->printLeafNodes();
        itr->item->printStack();

	}
}



SayilarListesi::~SayilarListesi()
		{
			clear();
		}
