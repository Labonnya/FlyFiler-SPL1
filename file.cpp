#include<iostream>
#include<fstream>
#include<string.h>
#include<cstdio>
#include<stdlib.h>
#include<Windows.h>
using namespace std;

//prototype
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

int main()
{
    int choice;
    cout<<"________________________________________________"<<endl;
    cout<<"\t\tWelcome to the menu";
    cout<<"\n";
    cout<<"1. Create new file"<<endl;
    cout<<"2. Write in file"<<endl;
    cout<<"3. Read from a file"<<endl;
    cout<<"4. Update a file"<<endl;
    cout<<"5. Rename a file"<<endl;
    cout<<"6. Copy contents of a file to another file"<<endl;
    cout<<"7. Delete a file"<<endl;
    cout<<"8. Rename a file"<<endl;
    cout<<"9. Search in a file"<<endl;
    cout<<"10. List all files in directory"<<endl;
    cout<<"11. Get size of all files in directory"<<endl;
    cout<<"12. Exit"<<endl;
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
    case 8:
        {
            renameFile();
        }
    case 9:
        {
            searchInFile();
        }
    case 10:
        {
            searchFileInDirectory();
        }
    case 11:
        {
            getFileSizeDirectory();
        }
    case 12:
        {
            exit(1);
        }
    /*case 7:
        {
            cout<<"\t\t\t Thank You!! \n\n";
              break;
        }*/

    default:
        system("CLS");
        cout<<"\t\t\t Please select from the given tab. \n";
        main();
    }
}


void createNewFile()
{
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

    cout<<"File is successfully created."<<endl;

    file.close();
    main();

}

void writeInFile()
{
        string filename,str;
        ofstream file;

        cout<<"Enter the name of the file where you want to write: "<<endl;
        cin>>filename;

        file.open(filename.c_str());
        if(!file)
    {
        cout<<"Error in opening source file. Try again.";
        main();
    }

        cout<<"Enter the text you want to write in your file: "<<endl;
        //cin>>str;
        cin.clear();
        cin.sync();
        getline(cin,str);

        file<<str<<endl;
        file.close();
        main();

}

void readFromFile()
{
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
        main();
}

void updateFile()
{
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
        main();
        file.close();
        }
        else if(n==0)
        {
            main();
        }
}

void copyFile()
{
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
        main();
    }
    cout<<"Enter the name of the file where you want to copy: "<<endl;
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
    cout<<"File copied successfully."<<endl;
    file1.close();
    file2.close();
    main();
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
        main();

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
        main();
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
        main();
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
                break;

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
                cout<<"Length of the longest word is " <<maximum-1<<endl;
                break;
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
                cout<<"The shortest word is " <<ch2<<"."<<endl;
                cout<<"Length of the shortest word is " <<minimum<<"."<<endl;
                break;
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
                       break;
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
                    cout<<"Digit is not present in file."<<endl;
                }
                else
                {
                    cout<<"Digits are found and occurred "<< count <<" times in file."<<endl;
                }

     }
           }
}

void searchFileInDirectory()
{
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
    main();

}

void getFileSizeDirectory()
{
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
        wcout<<"File size - " <<FindFileData.nFileSizeLow<<" kb"<<endl;
    }

    FindClose(hFindFile);
    main();

}



