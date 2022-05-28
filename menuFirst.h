#ifndef MENUFIRST_H_INCLUDED
#define MENUFIRST_H_INCLUDED

#include<iostream>


using namespace std;
void createNewFile();
void writeInFile();
void readFromFile();
void updateFile();
void renameFile();
void copyFile();
void deleteFile();
void searchInFile();
void searchFileInDirectory();
void getFileSizeDirectory();
void clearFile();
void mergeFile();
void menuFirst();
void menuFlyFiler();
void compression();
void decompression();
void encryptionAES();
void encryptionDES();

void menuFlyFiler()
{
    int choice;
    cout<<"\n\n\n\n";
    cout<<"\t\t\t________________________________________________\n\n\n"<<endl;
    cout<<"\t\t\t             WELCOME TO FLYFILER\n\n";
    cout<<"\n";
    cout<<"\t\t\t___________________Menu___________________\n\n";
    cout<<"\t1. Create new file"<<endl;
    cout<<"\t2. Write in file"<<endl;
    cout<<"\t3. Read from a file"<<endl;
    cout<<"\t4. Update a file"<<endl;
    cout<<"\t5. Rename a file"<<endl;
    cout<<"\t6. Copy contents of a file to another file"<<endl;
    cout<<"\t7. Delete a file"<<endl;
    cout<<"\t8. Merge contents of two file"<<endl;
    cout<<"\t9. List all files in directory"<<endl;
    cout<<"\t10. Get size of all files in directory"<<endl;
    cout<<"\t11. Clear file"<<endl;
    cout<<"\t12. Search in file"<<endl;
    cout<<"\t13. Compress a file"<<endl;
    cout<<"\t14. Decompress a file"<<endl;
    cout<<"\t15. Encrypt or decrypt a file"<<endl;
    cout<<"\t16. Encrypt or decrypt 64 bit text"<<endl;
    cout<<"\t17. Exit"<<endl;

    cout<<"Enter your choice: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        {
          createNewFile();
            break;
        }
    case 2:
        {
            writeInFile();
              break;
        }
    case 3:
        {
            readFromFile();
              break;
        }

    case 4:
        {
            updateFile();
            break;
        }

    case 5:
        {
            renameFile();
            break;
        }
    case 6:
        {
            copyFile();
        }
    case 7:
        {
            deleteFile();
        }
   /* case 8:
        {
            renameFile();
        }*/
    case 8:
        {
            mergeFile();
        }
    case 9:
        {
            searchFileInDirectory();
        }
    case 10:
        {
            getFileSizeDirectory();
        }
    case 11:
        {
            clearFile();
        }
    case 12:
        {
            searchInFile();
        }
    case 13:
        {
            compression();
        }
    case 14:
        {
           decompression();
        }
   case 15:
        {
          encryptionAES();
        }
   case 16:
    {
        encryptionDES();
    }
    case 17:
        {
            cout<<"\t\t\t Thank You!! \n\n";
              break;
        }

    default:
        system("CLS");
        cout<<"\t\t\t Please select from the given tab. \n";
        menuFlyFiler();
    }
}

void registration();
bool login();
void forgot();
void email();
bool isChar(char c)
{
    return ((c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z'));
}

bool isDigit(const char c)
{
    return (c >= '0' && c <= '9');
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

void menuFirst()
{
    int choice;
    cout<<"\t\t\t_____________________________________________________\n\n\n";
    cout<<"\t\t\t            WELCOME TO FLYFILER\n\n\n";
    cout<<"\t\t\t___________________Menu___________________\n\n";
    cout<<"\t Press 1 to LOGIN           \n";
    cout<<"\t Press 2 to REGISTRATION          \n";
    cout<<"\t Press 3 if you forgot your PASSWORD \n";
    cout<<"\t Press 4 to EXIT \n";
   // cout<<"\t Press 5 to go to FlyFiler Menu \n";

    cin>>choice;
    cout<<endl;

    switch(choice)
    {
    case 1:
        {
          login();
           break;
        }

    case 2:
        {
           registration();
            break;
        }

    case 3:
        {
             forgot();
               break;
        }

    case 4:
        {
            cout<<"\t\t\t Thank You!! \n\n";
               break;
        }

    /*case 5:
        {
           menuFlyFiler();
        }*/

    default:
        system("CLS");
        cout<<"\t\t\t Please select from the given tab. \n";
        menuFirst();
}
}
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
        menuFirst();
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
#endif // MENUFIRST_H_INCLUDED
