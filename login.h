#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED
#include<iostream>
#include "menuFirst.h"
using namespace std;

bool login()
{
    bool log = false;
    int count;
    string userID,password,id,pass;
    system("CLS");
    cout<<"\t\tPlease enter your username and password: \n";
    cout<<"\t\tUsername: ";
    cin>>userID;
    //cout<<"\n";
    cout<<"\t\tPassword: ";
    cin>>password;

    ifstream input("record.txt");

    while(input>>id>>pass)
    {
        if(id==userID && pass==password)
        {
            count=1;
            system("CLS");
        }
    }

    input.close();

    if(count==1)
    {
        cout<<"\nYour LOGIN is successful!\n";
        log = true;
    }
    else
    {
        cout<<"\t\t Wrong information. Please check your username and password again.\n";
        log = false;
        main();
    }
    if(log==true)
    {
        menuFlyFiler();
    }

}
void registration()
{
    string name,email_id,password,user_name;
    string phone_no;
    cout<<"Fill up the following informations to sign up with us today.";
    cout<<"\n";
    cout<<"\t\tEnter your full name: ";
    cin>>name;
    cout<<"\t\tEnter your username: ";
    cin>>user_name;
    cout<<"\t\tEnter your email id: ";
    cin>>email_id;

    if (!isChar(email_id[0]))
        {
           cout<<"\t\tInvalid email id. Please try again.\n";
           cout<<"\t\tEnter your email id: ";
            cin>>email_id;
        }
    int a=-1, d=-1;
    for (int i=0; i<email_id.length(); i++) {

        if (email_id[i] == '@') {
            a=i;
        }
        else if (email_id[i] == '.') {
            d=i;
        }
    }
    if (a==-1 || d==-1)
    {
        cout<<"\t\tInvalid email id. Please try again.\n";
        cout<<"\t\tEnter your email id: ";
            cin>>email_id;
    }
    if (a>d)
        {
            cout<<"\t\tInvalid email id. Please try again.\n";
            cout<<"\t\tEnter your email id: ";
            cin>>email_id;
        }
    cout<<"\t\tEnter your phone number: ";
    cin>>phone_no;
    int len = length(phone_no.c_str());
    if(phone_no[0]!=0 && phone_no[1]!=1 && len<11)
    {
        cout<<"\t\tInvalid phone number. Try again.";
        cout<<"\t\tEnter phone number: ";
        cin>>phone_no;
    }
    cout<<"\t\t Set up your password: ";
    cin>>password;
    int pass_len= length(password.c_str());
    if(pass_len<8)
    {
        cout<<"\t\tPassword must be of 8 characters. Try again.\n";
        cout<<"\t\tEnter password again: ";
        cin>>password;
    }

    ofstream f1("record.txt", ios::app);
    f1<<user_name<<" "<<password<<endl;

    ofstream f3("info.txt", ios::app);
    f3<<phone_no<<" "<<name<<" "<<email_id;

    system("CLS");
    cout<<"\t\tYour registration is successful. Thank you!!\n";
    menuFirst();

}
size_t length(const char *s)
{
    size_t size = 0;

    while (*s) {
        size += 1;
        s +=1;
    }

    return size;
}

void forgot()
{
   int option;
   system("CLS");
   cout<<"Don't worry if you forgot your password.";
   cout<<"\nPress 1 to search by your username.";
   cout<<"\nPress 2 to go back to main menu.";

   cout<<"\nEnter your choice: ";
   cin>>option;

   switch(option)
   {
   case 1:
       {
    int count=0;
    string suserid,sid,spass;
    cout<<"Enter the username you remember: ";
    cin>>suserid;

    ifstream f2("record.txt");
    while(f2>>sid>>spass)
    {
        if(sid==suserid)
        {
            count=1;
        }
    }
    f2.close();
    if(count==1)
    {
        cout<<"Your account is found!!";
        cout<<"Your password is: "<<spass;
        cout<<endl;
        //system("CLS");
        menuFirst();
    }
    else
    {
        cout<<"Sorry your account was not found.";
        //system("CLS");
        cout<<endl;
        menuFirst();
    }
    break;
   }
   case 2:
    {
        menuFirst();
    }
   default:
    {
        cout<<"Wrong choice. Please try again."<<endl;
        forgot();
    }
}
}



#endif // LOGIN_H_INCLUDED
