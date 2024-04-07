// ConsoleApplication8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;  

class Divace abstract   
{
public:
    virtual void Print() = 0;   
    
};

class VideoCard : public Divace 
{
    string name;    
public:
    VideoCard(string n) 
    {
        name = n;   
    }
    void Print() 
    {
        cout << "Vido card: " << name << endl;  
    }
};

class CPU : public Divace
{   
    string name;
public:
    CPU(string n)   
    {
        name = n;
    }   
    void Print()
    {
        cout << "CPU: " << name << endl;
    }
};

class HDD : public Divace   
{
    string name;
public:
    HDD(string n)
    {
        name = n;   
    }
    void Print()
    {
        cout << "HDD: " << name << endl;    
    }
};

class IPrint abstract       
{
    Divace* divace; 
public:
    Divace* GetDivice() 
    {
        return divace;  
    }
    void SetDivace(Divace* divace)
    {
        this->divace = divace;  
    }
    virtual void ShowDevice()   
    {
        divace->Print();         
    }
    virtual void PrintDivace() = 0; 
};

class HomePc : public IPrint    
{   
public: 
    void PrintDivace() 
    {
        cout << "I use home pc" << endl;    
    }
};

class GameePc : public IPrint   
{
public:
    void PrintDivace()  
    {
        cout << "I use game pc" << endl;   
    }
};

void client(Divace* divace, IPrint* Iprint) 
{
    Iprint->SetDivace(divace);  
    Iprint->ShowDevice();   
    Iprint->PrintDivace();  
}

int main()
{
    Divace* div = new VideoCard("Nvidia RTX 3080"); 
    IPrint* pnt = new GameePc();  
    client(div, pnt);
    delete div; 
    delete pnt;     
    cout << endl; 

    div = new CPU("Intel Core i9-11900K");  
    pnt = new HomePc();     
    client(div, pnt);   
    delete div; 
    cout << endl;   

    div = new HDD("Samsung 1TB SSD");   
    client(div, pnt);      
    delete div;     

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
