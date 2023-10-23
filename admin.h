#include <iostream> //for input/output
#include <string>   //for string operations
#include <fstream>  //for writing and reading files
#include <cstring>
#include <time.h>
#include <iomanip>
#include "adminNumber.h"



using namespace std;


class admin
{

    char name[30];
    char phno[13];
    
   
    char passwd[30];
   
  
    char adminno[21];



    public:


        void createAccount();

        void signIn();

        void display_details();

        void view_all_admins();

        void update_phno();

        void update_passwd();

};

void admin::createAccount()
{
            


            cout<<">>> Enter your name:";
           
            cin.get(name,30);

            cout<<">>> Enter your phone number:";
            cin.ignore();
            cin.get(phno,13);

            
            cout<<">>> Enter a strong password:";
            cin.ignore();
            cin.get(passwd,30);

            cout<<">>> Re-enter password to confirm:";
            char p[30];
            cin.ignore();
            cin.get(p,30);
            
            
            
            while(1)
            {
                if(strcmp(passwd,p)==0)
                {
                                fstream f;
                                f.open("admins.txt",ios::app|ios::binary);


                                adm_num temp;
                                temp.get_adm(adminno);
                               
                                f.write((char*)this,sizeof(admin));
                                f.close();
                                display_details();
                                return;
                }
                else
                {
                    cout<<"\n*************************************************************************************\n";
                    cout<<"\tPasswords does not match.....Enter Again!\n";
                    cout<<">>> Enter a strong password:";
                    cin.ignore();
                    cin.get(passwd,30);

                    cout<<">>> Re-enter password to confirm:";
                    char p[30];
                    cin.ignore();
                    cin.get(p,30);
            
                    cout<<"\n*************************************************************************************\n";

                }
            }
}

void admin::display_details()
{
    cout<<"\n*************************************************************************************\n\n";
    cout<<"                                  ACCOUNT DETAILS                                    ";
    cout<<"\n\n*************************************************************************************\n\n";
    cout<<"\tAdmin name: "<<name<<endl;
    cout<<"\tAdmin number: "<<adminno<<endl;
    
    cout<<"\tHolder's phone number: "<<phno<<endl;
    //cout<<"\n*************************************************************************************\n";
  

}

void admin::signIn()
{
     while(1)
    {
        char admno_ [21];
        char passwd_[30];
        cout<<">>> Enter Admin number:";

        cin.ignore();
        cin>>admno_;
        
        cout<<">>> Enter password:";
        cin.ignore();
        cin.get(passwd_,30);

        fstream f;
        f.open("admins.txt",ios::in|ios::binary);

        while(f.read((char*)this,sizeof(admin)))
        {
           // cout<<"\n\n"<<admno_<<" "<<passwd_<<" "<<adminno<<" "<<passwd<<endl;

              
            if(strcmp(adminno,admno_)==0  && strcmp(passwd,passwd_)==0)
            {

             
                display_details();
                f.close();
                return;
            }
            
        }
        f.close();
                            cout<<"\n*************************************************************************************\n";
                            cout<<"\tAccount number and password does not matched!\n\n";
                            cout<<">>> Choose an option:\n";
                            cout<<"\t   1.Re-enter details\n";
                            cout<<"\t   2.Cancel request\n\n";
                            int choice,i=0;
                            cout<<">>> Enter your choice:";
                            cin>>choice;
                            switch(choice)
                            {
                                case 1:
                                {
                                    i=1;
                                    break;  
                                }

                                case 2:
                                {
                                    cout<<"\n\tRequest Cancelled\n";
                                    exit(0);
                                    break;
                                }

                                default:
                                {
                                    cout<<"\n\tInvalid Choice!\n";
                                    i=1;

                                }
                            }
                            cout<<"\n*************************************************************************************\n";
                            if(i==1){continue;}
                            else{return;}
    }


}

void admin::view_all_admins()
{
        cout<<"\n*************************************************************************************\n\n";
        cout<<"                                    ACCOUNT DETAILS                                       ";
        cout<<"\n\n*************************************************************************************\n\n";
        cout<<"-------------------------------------------------------------"<<endl;
        cout<<"| "<<setw(20)<<"NAME"<<" |"<<setw(21)<<"ADM. NUMBER"<<" | "<<setw(10)<<"PHN. NUMBER"<<" |"<<endl;
        cout<<"-------------------------------------------------------------"<<endl;

        fstream f;
        f.open("admins.txt",ios::in|ios::binary);

        while(f.read((char*)this,sizeof(admin)))
        {
            cout<<"| "<<setw(20)<<name<<" |"<<setw(21)<<adminno<<" | "<<setw(10)<<phno<<"  |"<<endl;

        }
        cout<<"-------------------------------------------------------------"<<endl;
      //  cout<<"\n*************************************************************************************\n";
        f.close();

}

void admin::update_phno()
{
    cout<<">>> Enter new phone number:";
    cin.ignore();
    char temp[13];

    cin.get(temp,13);


       

        char temp_admno[21];
        strcpy(temp_admno,adminno);
        char temp_passwd[30];
        strcpy(temp_passwd,passwd);
        
        


        fstream fs;
        fs.open("admins.txt",ios::in|ios::out|ios::binary);


        while (!fs.eof()) 
        {
                // storing the position of
                // current file pointeri.e. at
                // the end of previously read record
                int pos = fs.tellg();
        
                fs.read((char*)this, sizeof(admin));
                if (fs) 
                {
        
                    // comparing the roll no with that
                    // of the entered roll number
                    if (strcmp(adminno,temp_admno)==0 && strcmp(passwd,temp_passwd)==0) 
                    {
                        strcpy(phno, temp);
        
                        
                        fs.seekp(pos);
        
                        // writing the object to the file
                        fs.write((char*)this, sizeof(admin));
        
                    
                        break;
                    }
                }
        }

        fs.close();

        cout<<"                       PHONE NUMBER CHANGED";


}

void admin::update_passwd()
{
    cout<<">>> Enter new password:";
    cin.ignore();
    char temp[30];
    cin.ignore();
    cin.get(temp,30);



       

        char temp_admno[21];
        strcpy(temp_admno,adminno);
        char temp_passwd[30];
        strcpy(temp_passwd,passwd);
        


        fstream fs;
        fs.open("admins.txt",ios::in|ios::out|ios::binary);


        while (!fs.eof()) 
        {
                // storing the position of
                // current file pointeri.e. at
                // the end of previously read record
                int pos = fs.tellg();
        
                fs.read((char*)this, sizeof(admin));
                if (fs) 
                {
        
                    // comparing the roll no with that
                    // of the entered roll number
                    if (strcmp(adminno,temp_admno)==0 && strcmp(passwd,temp_passwd)==0) 
                    {
                        strcpy(passwd,temp);
        
                        
                        fs.seekp(pos);
        
                        // writing the object to the file
                        fs.write((char*)this, sizeof(admin));
        
                    
                        break;
                    }
                }
        }

        fs.close();

        cout<<"                       PASSWORD CHANGED";


}
