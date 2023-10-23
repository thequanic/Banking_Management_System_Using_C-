#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <time.h>
#include <iomanip>
#include "admin.h"

using namespace std;
class acc_num
{
        int bankcode;
        int branchcode;
        long int account_code;
        int suffix;

        public:

        void init()
        {
            bankcode=24;
            branchcode=6785;
            account_code=1000000;
            suffix=810;


            fstream f;
            f.open("numbers.txt",ios::out|ios::binary);
            f.write((char*)this,sizeof(acc_num));
            

            f.close();

        }

        
        

       

};

class adm_num1
{
        int bankcode;
        int branchcode;
        long int admin_code;
        int suffix;

        public:

        void init()
        {
            bankcode=24;
            branchcode=6785;
            admin_code=1008000;
            suffix=820;


            fstream f;
            f.open("adminNumbers.txt",ios::out|ios::binary);
            f.write((char*)this,sizeof(adm_num));
            

            f.close();

        }

        
        

       

};




int main()
{
    acc_num a;
    adm_num1 b;

    a.init();
    b.init();

    admin adm;
    adm.createAccount();
}
    