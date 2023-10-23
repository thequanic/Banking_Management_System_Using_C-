#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <time.h>
#include <iomanip>

using namespace std;


class acc_num
{
            int bankcode;
            int branchcode;
            long int account_code;
            int suffix;

        public:

            string get_acc(char*arr);
  
};

string acc_num:: get_acc(char* arr)
{
    fstream f;
    f.open("numbers.txt",ios::in|ios::binary|ios::out);

    f.read((char*)this,sizeof(acc_num));

    ++(this->account_code);
    ++(this->suffix); 
    string temp= to_string(bankcode)+"-"+to_string(branchcode)+"-"+to_string(account_code)+"-"+to_string(suffix);
    sprintf(arr,"%d-%d-%d-%d",bankcode,branchcode,account_code,suffix);
    f.seekg(0);
    f.seekp(0);

    f.write((char*)this,sizeof(acc_num));


    f.close();

    return temp;
}

       