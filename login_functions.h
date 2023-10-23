#include <iostream>

#include "bankAccount.h"
#include "admin.h"

using namespace std;





int admin_login()
{
        string s="OPERATION PERFORMED SUCCESSFULLY";
        cout<<"\n\n*************************************************************************************\n\n";
        cout<<"\n                            *************************************";
        cout<<"\n                            |             GET STARTED           |";
        cout<<"\n                            *************************************";
        cout<<"\n                            |        1.SIGN IN                  |\n";
         
        cout<<"                            |        2.EXIT                     |\n";       
        cout<<"                            *************************************\n";


        cout<<"\n\n*************************************************************************************\n\n";
        //asking for user choice
        cout<<"\n>>> Enter your choice::";
        int choice;
        cin>>choice;
        cout<<"\n\n*************************************************************************************\n\n";
        
        admin *a=new admin;
        
        switch(choice)
        {
            case 1:
            {
                a->signIn();
                break;
            }


            default:
            {       
                        s="        PROGRAM ENDED         ";
                        cout<<"\n\n*************************************************************************************\n\n";
                        cout<<"                         "<<s<<"                            ";
                        cout<<"\n\n*************************************************************************************\n\n";
                        exit(0);

            }
        }
        cout<<"\n\n*************************************************************************************\n\n";
        cout<<"                         "<<s<<"                            ";
        cout<<"\n\n*************************************************************************************\n\n";


        while(1)
        {
                cout<<"\n\n*************************************************************************************\n\n";
                cout<<"\n                        *****************************************";
                cout<<"\n                        |                WELCOME                |";
                cout<<"\n                        *****************************************";
                cout<<"\n                        |        1.VIEW ALL  ACCOUNT            |\n";
                cout<<"                        |        2.VIEW DELETED ACCOUNTS        |\n";   
                cout<<"                        |        3.UN-DELETE ACCOUNT            |\n";  
                cout<<"                        |        4.VIEW ALL ADMINS              |\n";
                cout<<"                        |        5.CREATE NEW ADMIN             |\n"; 
                cout<<"                        |        6.VIEW MY DETAILS              |\n";
                cout<<"                        |        7.CHANGE PASSWORD              |\n";
                cout<<"                        |        8.CHANGE PHONE NUMBER          |\n";
                cout<<"                        |        9.EXIT                         |\n";    
                cout<<"                        *****************************************\n";


                cout<<"\n\n*************************************************************************************\n\n";
                //asking for user choice
                cout<<"\n>>> Enter your choice::";
                int choice;
                cin>>choice;
                cout<<"\n\n*************************************************************************************\n\n";
                
                
                s="OPERATION PERFORMED SUCCESSFULLY";


                bankAccount*b=new bankAccount;


                switch(choice)
                {
                    case 1:
                    {
                        b->view_all_accounts();
                        break;
                    }

                    case 2:
                    {
                        b->view_deleted_accounts();
                        break;
                    }

                    case 3:
                    {
                        b->undelete_acc();
                        break;
                    }

                    case 4:
                    {
                        a->view_all_admins();
                        break;
                    }

                     case 5:
                    {
                        a->createAccount();
                        break;
                    }

                    case 6:
                    {
                        a->display_details();
                        break;
      
 
                    }

                    case 7:
                    {
                        a->update_passwd();
                        break;
      
 
                    }

                    case 8:
                    {
                        a->update_phno();
                        break;
      
 
                    }


                    case 9:
                    {
                                s="        PROGRAM ENDED         ";
                                cout<<"\n\n*************************************************************************************\n\n";
                                cout<<"                         "<<s<<"                            ";
                                cout<<"\n\n*************************************************************************************\n\n";
                                exit(0);

                    }
                    default:
                    {
                        s="        INVALID CHOICE         ";
                    }
                }
                cout<<"\n\n*************************************************************************************\n\n";
                cout<<"                         "<<s<<"                            ";
                //cout<<"\n\n*************************************************************************************\n\n";

        }
    return 0;

}


int user_login()
{
        string s="OPERATION PERFORMED SUCCESSFULLY";
        cout<<"\n\n*************************************************************************************\n\n";
        cout<<"\n                            *************************************";
        cout<<"\n                            |             GET STARTED           |";
        cout<<"\n                            *************************************";
        cout<<"\n                            |        1.SIGN IN                  |\n";
        cout<<"                            |        2.CREATE ACCOUNT           |\n";   
        cout<<"                            |        3.EXIT                     |\n";       
        cout<<"                            *************************************\n";


        cout<<"\n\n*************************************************************************************\n\n";
        //asking for user choice
        cout<<"\n>>> Enter your choice::";
        int choice;
        cin>>choice;
        cout<<"\n\n*************************************************************************************\n\n";
        
        bankAccount *b=new bankAccount;
        
        switch(choice)
        {
            case 1:
            {
                b->signIn();
                break;
            }

            case 2:
            {
                b->createAccount();
           
                break;
            }

            default:
            {       
                        s="        PROGRAM ENDED         ";
                        cout<<"\n\n*************************************************************************************\n\n";
                        cout<<"                         "<<s<<"                            ";
                        cout<<"\n\n*************************************************************************************\n\n";
                        exit(0);

            }
        }
        cout<<"\n\n*************************************************************************************\n\n";
        cout<<"                         "<<s<<"                            ";
        cout<<"\n\n*************************************************************************************\n\n";


        while(1)
        {
                cout<<"\n\n*************************************************************************************\n\n";
                cout<<"\n                        *****************************************";
                cout<<"\n                        |                WELCOME                |";
                cout<<"\n                        *****************************************";
                cout<<"\n                        |        1.VIEW ACCOUNT DETAILS         |\n";
                cout<<"                        |        2.DEPOSIT AMOUNT               |\n";   
                cout<<"                        |        3.WITHDRAW AMOUNT              |\n";  
                cout<<"                        |        4.VIEW PASSBOOK                |\n";
                cout<<"                        |        5.CHANGE PHONE NUMBER          |\n";
                cout<<"                        |        6.CHANGE PASSWORD              |\n"; 
                cout<<"                        |        7.DELETE ACCOUNT               |\n";
                cout<<"                        |        8.EXIT                         |\n";    
                cout<<"                        *****************************************\n";


                cout<<"\n\n*************************************************************************************\n\n";
                //asking for user choice
                cout<<"\n>>> Enter your choice::";
                int choice;
                cin>>choice;
                cout<<"\n\n*************************************************************************************\n\n";
                
    
                s="OPERATION PERFORMED SUCCESSFULLY";


                switch(choice)
                {
                    case 1:
                    {
                        b->display_details();
                        break;
                    }

                    case 2:
                    {
                        b->deposit();
                        break;
                    }

                    case 3:
                    {
                        b->withdraw();
                        break;
                    }

                    case 4:
                    {
                        b->print_passbook();
                        break;
                    }

                     case 5:
                    {
                        b->update_phno();
                        break;
                    }

                    case 6:
                    {
                        b->update_passwd();
                        break;
                    }

                    case 7:
                    {
                        b->delete_acc();
                        delete b;
                        s="        PROGRAM ENDED         ";
                        cout<<"\n\n*************************************************************************************\n\n";
                        cout<<"                         "<<s<<"                            ";
                        cout<<"\n\n*************************************************************************************\n\n";
                        exit(0);
                  
 
                    }

                    case 8:
                    {
                                s="        PROGRAM ENDED         ";
                                cout<<"\n\n*************************************************************************************\n\n";
                                cout<<"                         "<<s<<"                            ";
                                cout<<"\n\n*************************************************************************************\n\n";
                                exit(0);

                    }
                    default:
                    {
                        s="        INVALID CHOICE         ";
                    }
                }
                cout<<"\n\n*************************************************************************************\n\n";
                cout<<"                         "<<s<<"                            ";
               // cout<<"\n\n*************************************************************************************\n\n";

        }
    return 0;

}