#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <time.h>
#include <iomanip>

using namespace std;


class passbook
{
    private:
    
            
            float amt;
            char type[30];
            char time[30];
            float finalamt;
        

    public:
            passbook(float amt,float finalamt,char type[],char time[]);
            passbook();
            void print();

};

passbook::passbook(float amt,float finalamt,char type[],char time[])
{
    this->amt=amt;
    this-> finalamt=finalamt;
    strcpy(this-> type, type);
    strcpy(this->time,time);
               
}

passbook::passbook()
{

}


void passbook::print()
{
    cout<<"| "<<setw(11)<<this->amt<<" INR  |  "<<setw(16)<<this->type<<"  | "<<setw(9)<<this->finalamt<<" INR  | ";
    for(int i=0;i<24;i++)
    {
        cout<<time[i];
    }
    cout<<"    |"<<endl;
}
