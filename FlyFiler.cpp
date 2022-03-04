#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<cstdio>
#include<Windows.h>
using namespace std;

//function prototypes
void registration();
bool login();
void forgot();
void email();
size_t length(const char *s);
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

bool isChar(char c)
{
    return ((c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z'));
}

bool isDigit(const char c)
{
    return (c >= '0' && c <= '9');
}

int main()
{
    menuFirst();
    menuFlyFiler();
}

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
    cout<<"\t13. Exit"<<endl;

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
            exit(1);
        }
    case 14:
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
void createNewFile()
{
    system("CLS");
    string name;
    ofstream file;

    cout<<"Enter your file name: "<<endl;
    cin>>name;

     while(1){
      if(name.find('.'))
      {
          break;
      }
      else{
        cout<<"Not in correct format. Enter again."<<endl;
        cout<<"Enter file name in .txt format: "<<endl;
        cin>>name;
      }
    }

    do
        {
            file.open(name.c_str());
    }while(file.fail());
    system("CLS");
    cout<<"File is successfully created."<<endl;

    file.close();

           menuFlyFiler();

}

void writeInFile()
{
        system("CLS");
        string filename,str;
        ofstream file;

        cout<<"Enter the name of the file where you want to write: "<<endl;
        cin>>filename;

        file.open(filename.c_str());
        if(!file)
    {
        cout<<"Error in opening source file. Try again.";

           menuFlyFiler();
    }

        cout<<"Enter the text you want to write in your file: "<<endl;
        //cin>>str;
        cin.clear();
        cin.sync();
        getline(cin,str);

        file<<str<<endl;
        system("CLS");
        cout<<"File is written successfully."<<endl;
        file.close();

           menuFlyFiler();

}

void readFromFile()
{
    system("CLS");
    string filename,str;
        ifstream file;

        cout<<"Enter the name of the file you want read: "<<endl;
        cin>>filename;

        cout<<"\n";
        cout<<"Content of the file: "<<endl;

        file.open(filename.c_str());

        if(!file)
    {
        cout<<"Error in opening source file. Try again.";
        main();
    }
        while(getline(file,str)){
            cout<<str<<endl;
        }
        //system("CLS");
           menuFlyFiler();
}

void updateFile()
{
    system("CLS");
    string filename,str;
    int n;
        ofstream file;
        ifstream file1;

        cout<<"Enter the name of the file which you want to update: "<<endl;
        cin>>filename;

        file.open(filename.c_str(),ios::out|ios::app);
        if(!file)
    {
        cout<<"Error in opening source file. Try again.";
        main();
    }

        cout<<"Enter the text you want to write in your file: "<<endl;

        cin.clear();
        cin.sync();
        getline(cin,str);

        file<<str<<endl;

        cout<<"Do you want to check if your file is updated? If yes press 1 else press 0."<<endl;
        cin>>n;
        if(n==1)
        {
            cout<<"Content of the file: "<<endl;

        file1.open(filename.c_str());
        while(getline(file1,str)){
            cout<<str<<endl;
        }

           menuFlyFiler();
        file.close();
        }
        else if(n==0)
        {

           menuFlyFiler();
        }
}

void copyFile()
{
    system("CLS");
    ifstream file1;
    ofstream file2;

    char ch;
    string fname1,fname2;

    cout<<"Enter the name of the file from which you want to copy: "<<endl;
    cin>>fname1;

    file1.open(fname1.c_str());
    if(!file1)
    {
        cout<<"Error in opening source file. Try again.";

           menuFlyFiler();
    }
    cout<<"Enter the name of the file where you want to copy: "<<endl;
    cin>>fname2;

    file2.open(fname2.c_str());
    if(!file2)
    {
        cout<<"Error in opening destination file. Try again.";

           menuFlyFiler();
    }

    while(!file1.eof())
        {
           ch=(char)file1.get();
           if(int(ch)!=-1 )
           {
               file2<<ch;
           }
        }
        system("CLS");
    cout<<"File copied successfully."<<endl;
    file1.close();
    file2.close();

           menuFlyFiler();
}

void deleteFile()
{
    string filename;
        ifstream file;

        cout<<"Enter the name of the file you want to delete: "<<endl;
        cin>>filename;
        if(!file)
    {
        cout<<"Error in opening source file. Try again.";
        main();
    }
        remove(filename.c_str());
        cout<<"File is removed."<<endl;
        menuFlyFiler();
}
void renameFile()
{
    ifstream file1;
      ofstream file2;

    char ch;
    string fname1,fname2;

    cout<<"Enter the name of the file you want to rename: "<<endl;
    cin>>fname1;

    file1.open(fname1.c_str());
    if(!file1)
    {
        cout<<"Error in opening source file. Try again.";
        main();
    }
    cout<<"Enter the name you want to set for your file: "<<endl;
    cin>>fname2;

    file2.open(fname2.c_str());
    if(!file2)
    {
        cout<<"Error in opening destination file. Try again.";
        main();
    }
     while(!file1.eof())
        {
           ch=(char)file1.get();
           if(int(ch)!=-1 )
           {
               file2<<ch;
           }
        }
         file1.close();
        remove(fname1.c_str());
        cout<<"File is renamed."<<endl;
        menuFlyFiler();
        file2.close();
}

void searchInFile()
{

string filename;
        int choice;
        ifstream file;

        cout<<"Enter the name of the file where you want to search: ";
        cin>>filename;

        file.open(filename.c_str());
        if(!file)
    {
        cout<<"Error in opening destination file. Try again.";

           menuFlyFiler();
    }

        cout<<"\t\tSearch option menu: "<<endl;
        cout<<"1. Search a word in file and number of occurrence"<<endl;
        cout<<"2. Search a character in file and number of occurrence"<<endl;
        cout<<"3. Find the longest word in file"<<endl;
        cout<<"4. Find the shortest word in file"<<endl;
        cout<<"5. Find number of line in file"<<endl;
        cout<<"6. Find digit in file"<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            {
                int count=0;
                char ch[20],c[20];

                cout<<"Enter the word you want to search: ";
                cin>>c;

                while(file)
                {
                    file>>ch;
                    if(strcmp(ch,c)==0)
                    {
                        count++;
                    }
                }
                if(count==0)
                {
                    cout<<"Word is not present in file."<<endl;
                }
                else
                {
                    cout<<"Word "<<c<< " is found and occurred "<< count <<" times in file."<<endl;
                }

                //searchInFile();

            }
        case 2:
            {
                   int count=0;
                   char c,ch;
                   cout<<"Enter the character you want to search: "<<endl;
                   cin>>c;
                   while(!file.eof())
                   {
                       file>>ch;
                    if(ch==c)
                    {
                        count++;
                    }
                   }
                   if(count==0)
                {
                    cout<<"Character "<<c<<" is not present in file."<<endl;
                }
                else
                {
                    cout<<"Character is "<<c<< " found and occurred "<< count <<" times in file."<<endl;
                }
                searchInFile();
                break;

            }
        case 3:
            {
                char ch1[100],ch2[100];
                int maximum=0;
                while(!file.eof())
                {
                    file>>ch1;
                    if(maximum<strlen(ch1))
                    {
                        maximum=strlen(ch1);
                        strcpy(ch2,ch1);
                    }
                }
                cout<<"The longest word is " <<ch2<<endl;
                cout<<"Length of the longest word is " <<maximum<<endl;
                searchInFile();
                break;
                 //searchInFile();
            }
        case 4:
            {
                char ch1[100],ch2[100];
                int minimum=1000;
                while(!file.eof())
                {
                    file>>ch1;
                    if(minimum>strlen(ch1))
                    {
                        minimum=strlen(ch1);
                        strcpy(ch2,ch1);
                    }
                }
               // system("CLS");
                cout<<"The shortest word is " <<ch2<<"."<<endl;
                cout<<"Length of the shortest word is " <<minimum<<"."<<endl;
                searchInFile();
                break;
                // searchInFile();
            }
        case 5:
            {
                int count=0;
                   char ch;
                   while(!file.eof())
                   {
                       file.get(ch);
                       if(ch=='.')
                        {
                           count++;
                        }
                   }

                       cout<<"Number of lines in file is "<<count<<"."<<endl;
searchInFile();
                break;
                        //searchInFile();
            }

        case 6:
            {
                int count=0;
                char ch;
                   while(!file.eof())
                   {
                       file.get(ch);
                       if(isdigit(ch))
                        {
                           count++;
                        }
                   }
                        if(count==0)
                {
                    system("CLS");
                    cout<<"Digit is not present in file."<<endl;
                }
                else
                {
                   // system("CLS");
                    cout<<"Digits are found and occurred "<< count <<" times in file."<<endl;
                }
menuFlyFiler();
               break;

                //searchInFile();
           }
           }

}

void searchFileInDirectory()
{
    system("CLS");
   WIN32_FIND_DATAA FindFileData;
    HANDLE hFindFile;
    LPCWSTR file = L"*.cpp";

    hFindFile = FindFirstFile((LPCSTR)file,&FindFileData);

    if(INVALID_HANDLE_VALUE == hFindFile)
    {
        cout<<"Error in finding file."<<endl;
        cout<<"Error "<< GetLastError() << endl;
    }
    else
    {
        cout<<"File found."<<endl;
        wcout<<"File name - " <<FindFileData.cFileName<<endl;
       // wcout<<"File size - " <<FindFileData.nFileSizeLow<<endl;
    }
    while(FindNextFile(hFindFile,&FindFileData))
    {
        wcout<< "File name - " <<FindFileData.cFileName<<endl;
    }

    FindClose(hFindFile);

           menuFlyFiler();

}

void getFileSizeDirectory()
{
    system("CLS");
     WIN32_FIND_DATAA FindFileData;
    HANDLE hFindFile;
    LPCWSTR file = L"*.cpp";

    hFindFile = FindFirstFile((LPCSTR)file,&FindFileData);

    if(INVALID_HANDLE_VALUE == hFindFile)
    {
        cout<<"Error in finding file."<<endl;
        cout<<"Error "<< GetLastError() << endl;
    }
    else
    {
        cout<<"File found."<<endl;
        wcout<<"File name - " <<FindFileData.cFileName<<endl;
        wcout<<"File size - " <<FindFileData.nFileSizeLow<<endl;
    }
   while(FindNextFile(hFindFile,&FindFileData))
    {
        wcout<< "File name - " <<FindFileData.cFileName<<endl;
        wcout<<"File size - " <<FindFileData.nFileSizeLow<<endl;
    }

    FindClose(hFindFile);

           menuFlyFiler();
}

void clearFile()
{
    system("CLS");

    string filename,str;
        ofstream file;

        cout<<"Enter the name of the file which you want to clear: "<<endl;
        cin>>filename;

        file.open(filename.c_str(),std::ofstream::out | std::ofstream::trunc);
        if(!file)
    {
        cout<<"Error in opening source file. Try again.";

           menuFlyFiler();
    }
    file.close();
    system("CLS");
    cout<<"File is cleared."<<endl;

           menuFlyFiler();
}

void mergeFile()
{
system("CLS");
      ifstream file1,file2;
      ofstream file3;

    string str1,str2;
    string fname1,fname2,fname3;

    cout<<"Enter the name of the first file: "<<endl;
    cin>>fname1;

    file1.open(fname1.c_str());
    if(!file1)
    {
        cout<<"Error in opening source file. Try again.";

           menuFlyFiler();
    }

    cout<<"Enter the name of the second file: "<<endl;
    cin>>fname2;

    file2.open(fname2.c_str());
    if(!file2)
    {
        cout<<"Error in opening destination file. Try again.";

           menuFlyFiler();
    }

    cout<<"Enter the new file name where you want to merge: "<<endl;
    cin>>fname3;

    file3.open(fname3.c_str());

    while(getline(file1, str1)){
         file3<<str1;
         file3<<endl;
      }

   while(getline(file2, str2)){
         file3<<str2;
         file3<<endl;
      }

        file1.close();
        file2.close();
        file3.close();
        system("CLS");
        cout<<"File is merged successfully."<<endl;

           menuFlyFiler();
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



