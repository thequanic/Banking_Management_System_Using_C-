#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <time.h>
#include <iomanip>
#include "accountnumber.h"
#include "passbook.h"


using namespace std;
char saving[7]="saving", current[8]="current";

class bankAccount
{
    char name[30];
    char phno[13];
    
    char acctype[10];
    char passwd[30];
    float bal;
    char account_file[30];
    char acc[21];



    public:


        void createAccount();

        void signIn();

        void display_details();  

        void withdraw(); 

        void deposit();
        
        void update_phno();

        void update_passwd();

        void print_passbook();  

        void delete_acc(); 

        void view_all_accounts();

        void view_deleted_accounts();

        void undelete_acc();

        void bank_details();    

      

};

void bankAccount::createAccount()
{
            


            cout<<">>> Enter your name:";
            cin.ignore();
            cin.get(name,30);

            cout<<">>> Enter your phone number:";
            cin.ignore();
            cin.get(phno,13);

            cout<<">>> Enter account type: (saving/current) :";
            cin.ignore();
            cin.get(acctype,10);

            cout<<">>> Enter initial balance:";
            
            cin>>bal;

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
                    
                    if(strcmp(acctype,saving)==0 || strcmp(acctype,current)==0)
                    {
                        if((strcmp(acctype,saving)==0 && bal>=500)||(strcmp(acctype,current)==0 && bal>=1500))
                        {       

                                fstream f;
                                f.open("accounts.txt",ios::app|ios::binary);


                                acc_num temp;
                                temp.get_acc(acc);
                                char a[21];
                                strcpy(a,acc);
                                strcpy(account_file,strcat(a,".txt"));
                                f.write((char*)this,sizeof(bankAccount));
                                f.close();
                                display_details();
                                return;
                        }
                        else if(strcmp(acctype,saving)==0 && bal<500)
                        {
                            cout<<"\n*************************************************************************************\n";
                            cout<<"\t Atleast required 500 INR for Saving account\n\n";
                            cout<<">>> Choose an option:\n";
                            cout<<"\t   1.Re-enter balance\n";
                            cout<<"\t   2.Cancel request\n\n";
                            int choice,i=0;
                            cout<<">>> Enter your choice:";
                            cin>>choice;
                            switch(choice)
                            {
                                case 1:
                                {
                                    cout<<">>> Re-enter initial balance:";
                                    cin>>bal; 
                                    i=1;
                                    break;  
                                }

                                case 2:
                                {
                                    cout<<"\tRequest Cancelled\n";
                                    exit(0);
                                    break;
                                }

                                default:
                                {
                                    cout<<"\tInvalid Choice!\n";
                                    i=1;

                                }
                            }
                            cout<<"\n*************************************************************************************\n";
                            if(i==1){continue;}
                            else{break;}
                        }

                        else if(strcmp(acctype,current)==0 && bal<1500)
                        {
                            cout<<"\n*************************************************************************************\n";
                            cout<<"\tAtleast required 1500 INR for Current account\n\n";
                            cout<<">>> Choose an option:\n";
                            cout<<"\t   1.Re-enter balance\n";
                            cout<<"\t   2.Cancel request\n\n";
                            int choice,i=0;
                            cout<<">>> Enter your choice:";
                            cin>>choice;
                            switch(choice)
                            {
                                case 1:
                                {
                                    cout<<">>> Re-enter initial balance:";
                                    cin>>bal; 
                                    i=1;
                                    break;  
                                }

                                case 2:
                                {
                                    cout<<"\tRequest Cancelled\n";
                                    exit(0);
                                    break;
                                }

                                default:
                                {
                                    cout<<"\tInvalid Choice!\n";
                                    i=1;

                                }
                            }
                            cout<<"\n*************************************************************************************\n";
                            if(i==1){continue;}
                            else{break;}
                        }
                    }
                    else
                    {
                        cout<<"\n*************************************************************************************\n";
                        cout<<"\tEntered wrong account type!.....Enter Again!!\n";
                        cout<<">>> Enter account type: (saving/current) :";
                        cin.ignore();
                        cin.get(acctype,10);
                        cout<<"\n*************************************************************************************\n";
                        continue;
                    }
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

void bankAccount::display_details()
{
    cout<<"\n*************************************************************************************\n\n";
    cout<<"                                  ACCOUNT DETAILS                                    ";
    cout<<"\n\n*************************************************************************************\n\n";
    cout<<"\tAccount holder name:     "<<name<<endl;
    cout<<"\tAccount number:          "<<acc<<endl;
    cout<<"\tAccount type:            "<<acctype<<endl;
    cout<<"\tHolder's phone number:   "<<phno<<endl;
    cout<<"\tAccount current balance: "<<bal<<endl;
    

}

void bankAccount::signIn()
{
    while(1)
    {
        char accno_ [21];
        char passwd_[30];
        cout<<">>> Enter account number:";

        cin.ignore();
        cin>>accno_;
        
        cout<<">>> Enter password:";
        cin.ignore();
        cin.get(passwd_,30);

        fstream f;
        f.open("accounts.txt",ios::in|ios::binary);

        while(!f.eof())
        {
            f.read((char*)this,sizeof(bankAccount));   

           
            if(strcmp(acc,accno_)==0  && strcmp(passwd,passwd_)==0)
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

void bankAccount::withdraw()
{
    cout<<">>> Enter amount to be withdrawal:";
    float b;
    cin>>b;

    

    if(bal-b<=500 && strcmp(acctype,saving)==0)
    {
                cout<<"\n\tTransaction will cause balance to drop below \n\tor equal to 500 in saving account....\n";
                cout<<"\n\n\t***************not enough balance****************\n";
                cout<<"\n\t*************Transaction cancelled***************\n\n";
    }
    else if(bal-b<=1500 && strcmp(acctype,current)==0)
    {
                cout<<"\n\tTransaction will cause balance to drop below \n\tor equal to 1500 in current account....\n";
                cout<<"\n\n\t***************not enough balance****************\n";
                cout<<"\n\t*************Transaction cancelled***************\n\n";
    }
    else
    {
        bal-=b;

        char temp_accno[21];
        strcpy(temp_accno,acc);
        char temp_passwd[30];
        strcpy(temp_passwd,passwd);
        float temp_bal=bal;


        fstream fs;
        fs.open("accounts.txt",ios::in|ios::out|ios::binary);


        while (!fs.eof()) 
        {
                // storing the position of
                // current file pointeri.e. at
                // the end of previously read record
                int pos = fs.tellg();
        
                fs.read((char*)this, sizeof(bankAccount));
                if (fs) 
                {
        
                    // comparing the roll no with that
                    // of the entered roll number
                    if (strcmp(acc,temp_accno)==0 && strcmp(passwd,temp_passwd)==0 ) {
                        bal= temp_bal;
        
                        // setting the new (modified )
                        // data of the object or new record
                
        
                        // placing the put(writing) pointer
                        // at the starting of the  record
                        fs.seekp(pos);
        
                        // writing the object to the file
                        fs.write((char*)this, sizeof(bankAccount));
        
                    
                        break;
                    }
                }
        }

        fs.close();


        time_t t=time(NULL);
        char arr[]="withdrawl   ";

        passbook *p=new passbook(b,bal,arr,ctime(&t));
        cout<<"\n*************************************************************************************\n\n";
        cout<<"                                     RECEIPT                                         ";
        cout<<"\n\n*************************************************************************************\n\n";
        cout<<"----------------------------------------------------------------------------------------"<<endl;
        cout<<"| added/withdrawl  |  Transaction Type  |  Final Balance |           TIME              |"<<endl;
        cout<<"----------------------------------------------------------------------------------------"<<endl;
        p->print();
        cout<<"----------------------------------------------------------------------------------------"<<endl;
       // cout<<"\n*************************************************************************************\n";


        fstream f;
        f.open(account_file,ios::app|ios::binary);
        f.write((char*)p,sizeof(passbook));
        f.flush();
        f.close();

    }
}

void bankAccount::deposit()
{
    cout<<">>> Enter amount to be deposit:";
    float b;
    cin>>b;


        bal+=b;

        char temp_accno[21];
        strcpy(temp_accno,acc);
        char temp_passwd[30];
        strcpy(temp_passwd,passwd);
        float temp_bal=bal;


        fstream fs;
        fs.open("accounts.txt",ios::in|ios::out|ios::binary);


        while (!fs.eof()) 
        {
                // storing the position of
                // current file pointeri.e. at
                // the end of previously read record
                int pos = fs.tellg();
        
                fs.read((char*)this, sizeof(bankAccount));
                if (fs) 
                {
        
                    
                    if (strcmp(acc,temp_accno)==0 && strcmp(passwd,temp_passwd)==0) 
                    {
                        bal= temp_bal;
        
                        // setting the new (modified )
                        // data of the object or new record
                
        
                        // placing the put(writing) pointer
                        // at the starting of the  record
                        fs.seekp(pos);
        
                        // writing the object to the file
                        fs.write((char*)this, sizeof(bankAccount));
        
                    
                        break;
                    }
                }
        }

        fs.close();


        time_t t=time(NULL);
        char arr[]="deposit   ";

        passbook *p=new passbook(b,bal,arr,ctime(&t));

        cout<<"\n*************************************************************************************\n\n";
        cout<<"                                     RECEIPT                                         ";
        cout<<"\n\n*************************************************************************************\n\n";
        cout<<"----------------------------------------------------------------------------------------"<<endl;
        cout<<"| added/withdrawl  |  Transaction Type  |  Final Balance |           TIME              |"<<endl;
        cout<<"----------------------------------------------------------------------------------------"<<endl;
        p->print();
        cout<<"----------------------------------------------------------------------------------------"<<endl;
       // cout<<"\n*************************************************************************************\n";

        fstream f;
        f.open(account_file,ios::app|ios::binary);
        f.write((char*)p,sizeof(passbook));
        f.flush();
        f.close();

    

}



void bankAccount::update_phno()
{
    cin.ignore();
    cout<<">>> Enter new phone number:";
    char temp[13];
 
    cin.get(temp,13);


       

        char temp_accno[21];
        strcpy(temp_accno,acc);
        char temp_passwd[30];
        strcpy(temp_passwd,passwd);
        


        fstream fs;
        fs.open("accounts.txt",ios::in|ios::out|ios::binary);


        while (!fs.eof()) 
        {
                // storing the position of
                // current file pointeri.e. at
                // the end of previously read record
                int pos = fs.tellg();
        
                fs.read((char*)this, sizeof(bankAccount));
                if (fs) 
                {
        
                   
                    if (strcmp(acc,temp_accno)==0 && strcmp(passwd,temp_passwd)==0) 
                    {
                        strcpy(phno,temp);
        
                        
                        fs.seekp(pos);
        
                        // writing the object to the file
                        fs.write((char*)this, sizeof(bankAccount));
        
                    
                        break;
                    }
                }
        }

        fs.close();

        cout<<"\n                       PHONE NUMBER CHANGED";



}



void bankAccount::update_passwd()
{
    cin.ignore();
    cout<<">>> Enter new passwd:";
    char temp[30];
     
    cin.get(temp,30);


       

        char temp_accno[21];
        strcpy(temp_accno,acc);
        char temp_passwd[30];
        strcpy(temp_passwd,passwd);
        


        fstream fs;
        fs.open("accounts.txt",ios::in|ios::out|ios::binary);


        while (!fs.eof()) 
        {
                // storing the position of
                // current file pointeri.e. at
                // the end of previously read record
                int pos = fs.tellg();
        
                fs.read((char*)this, sizeof(bankAccount));
                if (fs) 
                {
        
                    
                    if (strcmp(acc,temp_accno)==0 && strcmp(passwd,temp_passwd)==0) 
                    {
                        strcpy(passwd,temp);
        
                        
                        fs.seekp(pos);
        
                        // writing the object to the file
                        fs.write((char*)this, sizeof(bankAccount));
        
                    
                        break;
                    }
                }
        }

        fs.close();

        cout<<"\n                       PASSWORD CHANGED";


}

void bankAccount::print_passbook()
{
        passbook *p=new passbook();

        fstream f;
        f.open(account_file,ios::in|ios::binary);
        int c=0;

        while(f.read((char*)p,sizeof(passbook)))
        {
            
         
            
            c++;
            if(c==1)
            {
                cout<<"*************************************************************************************\n\n";
                cout<<"                                     PASSBOOK                                         ";
                cout<<"\n\n*************************************************************************************\n\n";
                cout<<"----------------------------------------------------------------------------------------"<<endl;
                cout<<"| added/withdrawl  |  Transaction Type  |  Final Balance |           TIME              |"<<endl;
                cout<<"----------------------------------------------------------------------------------------"<<endl;
                //cout<<"\n*************************************************************************************\n";

            }
            p->print();
                
        }

        if(c==0)
        {
            cout<<"\tNo Transaction History\n";
        }
        else{
            cout<<"----------------------------------------------------------------------------------------"<<endl;
        
        }


        f.close();
}


void bankAccount::delete_acc()
{
    
    char temp_accno[21];
    strcpy(temp_accno,acc);
    char temp_passwd[30];
    strcpy(temp_passwd,passwd);
    int flag=0;

    ifstream ifs;
    ifs.open("accounts.txt", ios::in | ios::binary);
  
    ofstream ofs,ofs2;
    ofs.open("temp.txt", ios::app | ios::binary);
    ofs2.open("deleted_accounts.txt",ios::app | ios::binary);
  
    while (!ifs.eof()) {
  
        ifs.read((char*)this, sizeof(bankAccount));
  
        // if(ifs)checks the buffer record in the file
        if (ifs) {
  
            if (strcmp(acc,temp_accno)==0 && strcmp(passwd,temp_passwd)==0) 
            {
                flag = 1;
                ofs2.write((char*)this, sizeof(bankAccount));
                
            }
            else {
              
                ofs.write((char*)this, sizeof(bankAccount));
            }
        }
    }
  
    ofs.close();
    ofs2.close();
    ifs.close();
  
    // delete the old file
    remove("accounts.txt");
    
  
    // rename new file to the older file
    rename("temp.txt", "accounts.txt");
  
    if (flag == 1)
        cout << "\nRecord successfully deleted \n";
    else
        cout << "\nRecord not found \n";
}

void bankAccount::view_all_accounts()
{
        fstream f;
        f.open("accounts.txt",ios::in|ios::binary);
        
       
        
        cout<<"\n*************************************************************************************\n\n";
        cout<<"                                    ACCOUNT DETAILS                                       ";
        cout<<"\n\n*************************************************************************************\n\n";
        cout<<"-----------------------------------------------------------------------------------"<<endl;
        cout<<"| "<<setw(20)<<"NAME"<<" |"<<setw(21)<<"ACC. NUMBER"<<" | "<<setw(10)<<"PHN. NUMBER"<<" |"<<setw(8)<<"TYPE"<<" |"<<setw(10)<<"BALANCE"<<" |"<<endl;
        cout<<"-----------------------------------------------------------------------------------"<<endl;
        

       

        while(f.read((char*)this,sizeof(bankAccount)))
        {
            cout<<"| "<<setw(20)<<name<<" |"<<setw(21)<<acc<<" | "<<setw(10)<<phno<<"  |"<<setw(8)<<acctype<<" |"<<setw(10)<<bal<<" |"<<endl;

        }
        cout<<"-----------------------------------------------------------------------------------"<<endl;
        //cout<<"\n*************************************************************************************\n";
        f.close();

}

void bankAccount::view_deleted_accounts()
{

        fstream f;
        f.open("deleted_accounts.txt",ios::in|ios::binary);



        cout<<"\n*************************************************************************************\n\n";
        cout<<"                                  DELETED ACCOUNT DETAILS                                 ";
        cout<<"\n\n*************************************************************************************\n\n";
        cout<<"-----------------------------------------------------------------------------------"<<endl;
        cout<<"| "<<setw(20)<<"NAME"<<" |"<<setw(21)<<"ACC. NUMBER"<<" | "<<setw(10)<<"PHN. NUMBER"<<" |"<<setw(8)<<"TYPE"<<" |"<<setw(10)<<"BALANCE"<<" |"<<endl;
        cout<<"-----------------------------------------------------------------------------------"<<endl;
        

        

        while(f.read((char*)this,sizeof(bankAccount)))
        {
            cout<<"| "<<setw(20)<<name<<" |"<<setw(21)<<acc<<" | "<<setw(10)<<phno<<"  |"<<setw(8)<<acctype<<" |"<<setw(10)<<bal<<" |"<<endl;

        }
        cout<<"-----------------------------------------------------------------------------------"<<endl;
        //cout<<"\n*************************************************************************************\n";
        f.close();
}

void bankAccount::undelete_acc()
{
    cout<<">>> Enter Account Number:";
    char acc_[21];
    cin>>acc_;

    fstream f;
    f.open("deleted_accounts.txt",ios::in|ios::binary);
    int flag=0;

    while(f.read((char*)this,sizeof(bankAccount)))
    {
            if(strcmp(acc_,acc)==0)
            {
                fstream f2;
                flag=1;
                f2.open("accounts.txt",ios::app|ios::binary);
                f2.write((char*)this,sizeof(bankAccount));
                f2.close();

                cout<<"\tACCOUNT RECOVERED\n";
                display_details();
                
            }
            else{
                fstream f2;
                
                f2.open("temp.txt",ios::app|ios::binary);
                f2.write((char*)this,sizeof(bankAccount));
                f2.close();

            
            }


    }

    f.close(); 

     // delete the old file
    remove("deleted_accounts.txt");
    
  
    // rename new file to the older file
    rename("temp.txt", "deleted_accounts.txt");

    if(flag==0){cout<<"\tNO ACCOUNT FOUND! RECOVERY FAILED\n";};
  

}

void bankAccount::bank_details()
{
    long long int count=0,sum=0;
    fstream f;
    f.open("accounts.txt",ios::in|ios::binary);

    while(f.read((char*)this,sizeof(bankAccount)))
    {
            count++;
            sum+=bal;


    }

    f.close();

    cout<<"\tBANK CODE:24\n";
    cout<<"\tBRANCH CODE:6785\n";
    cout<<"\tTOTAL NUMBER OF ACCOUNTS:"<<count<<endl;
    cout<<"\tTOTAL AMOUNT IN BANK:"<<sum<<endl;



}
  

