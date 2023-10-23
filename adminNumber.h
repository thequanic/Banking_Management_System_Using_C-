#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <time.h>
#include <iomanip>

using namespace std;


class adm_num
{
            int bankcode;
            int branchcode;
            long int admin_code;
            int suffix;

        public:

            string get_adm(char*arr);
  
};

string adm_num:: get_adm(char* arr)
{
    fstream f;
    f.open("adminNumbers.txt",ios::in|ios::binary|ios::out);

    f.read((char*)this,sizeof(adm_num));

    ++(this->admin_code);
    ++(this->suffix); 
    string temp= to_string(bankcode)+"-"+to_string(branchcode)+"-"+to_string(admin_code)+"-"+to_string(suffix);
    sprintf(arr,"%d-%d-%d-%d",bankcode,branchcode,admin_code,suffix);
    f.seekg(0);
    f.seekp(0);

    f.write((char*)this,sizeof(adm_num));


    f.close();

    return temp;
}

       