#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<string.h>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<sstream>
#include "textEncryptionDES.h"
#include "menuFirst.h"
#include "compressionHuffman.h"
#include "decompressionHuffman.h"
#include "key_expand.h"
#include "encoding.h"
#include "decoding.h"
#include <typeinfo>
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
void compression();
void decompression();
void encryptionAES();
void encryptionDES();

int main()
{
    menuFirst();
    menuFlyFiler();
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

               menuFlyFiler();
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
                menuFlyFiler();
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
                menuFlyFiler();
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
                menuFlyFiler();
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
menuFlyFiler();
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
        wcout<<"File size - " <<FindFileData.nFileSizeLow<<" kb " <<endl;
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
void encryptionAES()
{
    //we will read from file input.txt
int extendedlength=0;
int choice;
string myText;
label:
   cout<<"Welcome to 128 bits AES encryption"<<endl;
   cout<<endl;
   cout<<"Enter you choice "<<endl;
   cout<<"1- Encoding"<<endl;
   cout<<"2- Decoding"<<endl;
   cin>>choice;

  switch(choice)
  {
  	case 1:
  		{
  	//encryption of text data
   ifstream File;
   string filepath = "encryption.aes";
    //clearing encryption.aes before editing
   File.open(filepath.c_str(), std::ifstream::out | std::ifstream::trunc );
   if (!File.is_open() || File.fail())
   {
   File.close();
   printf("\nError : failed to erase file content !");
   }
   File.close();
   //reading plain text from input.txt
  	fstream newfile;
	newfile.open("input.txt",ios::in); //open a file to perform read operation using file object
   if (newfile.is_open()){   //checking whether the file is open
      cout<<"Reading plain text from input.txt .........\n";
      Sleep(1000);
      string tp;
       cout<<"Reading KEY from key.txt ......\n";
      Sleep(1000);
       cout<<"Now encrypting ....\n";
          Sleep(1000);
        cout<<"writing encrypted data in encryption.aes ..\n";
          Sleep(1000);
          cout<<endl;
      while(getline(newfile, tp)){
	  //read data from file object and put it into string.
	  int messlength=tp.length();
	  int extendedlength;
	   if((messlength%16)!=0)
	   {
	  	extendedlength=messlength+(16-(messlength%16));
	   }
	   else
	   {
	   	extendedlength=messlength;
	    }
	    unsigned char* encryptedtext=new unsigned char[extendedlength];
	    for(int i=0;i<extendedlength;i++)
         {
  	       if(i<messlength)
  	       encryptedtext[i]=tp[i];
  	       else
  	       encryptedtext[i]=0;
         }
         //getting key from key.txt
        string k;
	    ifstream infile;
	    infile.open("key.txt");
	    if (infile.is_open())
	   {
		getline(infile, k); // The first line of file should be the key
		infile.close();
	   }

	   else cout << "Unable to open file";

	    istringstream tempkey(k);
	    unsigned char key[16];
	    unsigned int x;
	    for(int i=0;i<16;i++)
	    {
	    tempkey>>hex>>x;
		key[i] = x;
	    }
	    //extending key
	     unsigned char extendedkeys[176];
         Key_extenxion(key,extendedkeys);

        //encrypting our plain text
         for(int i=0;i<extendedlength;i+=16)
         {
          unsigned char* temp=new unsigned char[16];
		  for(int j=0;j<16;j++)
		  {
		  	temp[j]=encryptedtext[i+j];
		  }
		  encryption(temp , extendedkeys);
		  for(int j=0;j<16;j++)
		  {
		  	encryptedtext[i+j]=temp[j];
		  }
		 }
	//storing our encrypted data in encryption.aes
	ofstream fout;  // Create Object of Ofstream
    ifstream fin;
    fin.open("encryption.aes");
    fout.open ("encryption.aes",ios::app); // Append mode
    if(fin.is_open())
        fout<<encryptedtext<<"\n"; // Writing data to file
    fin.close();
    fout.close();
      }
      cout<<"128-bit AES encryption is done sucessfully\n";
      cout<<"Data has been appended to file encryption.aes";
      newfile.close(); //close the file object.
   }
  break;
}

	case 2:
		{
	  cout<<"Reading encrypted data from encryption.txt .........\n";
      Sleep(1000);
      string tp;
      cout<<"Reading KEY from key.txt ......\n";
      Sleep(1000);
      cout<<"Now Decrypting ....\n";
      Sleep(1000);
       cout<<"writing decrypted data in outputtext.txt ..\n";
          Sleep(1000);
          cout<<endl;
	cout<<"Following is our decrypted text:- \n";
	//clearing outputtext file
	ifstream File;
   string filepath = "outputtext.txt";
   File.open(filepath.c_str(), std::ifstream::out | std::ifstream::trunc );
   if (!File.is_open() || File.fail())
   {
   File.close();
   printf("\nError : failed to erase file content !");
   }
   File.close();

	ifstream MyReadFile;
	MyReadFile.open("encryption.aes", ios::in | ios::binary);
    if(MyReadFile.is_open())
    {
    while( getline (MyReadFile, myText) )
   {
   	cout.flush();
     char * x;
      x=&myText[0];
      int messlength=strlen(x);
	 char * msg = new char[myText.size()+1];

	strcpy(msg, myText.c_str());

	int n = strlen((const char*)msg);
	unsigned char * decryptedtext = new unsigned char[n];
	//decrypting our encrypted data
	for (int i = 0; i < n; i++) {
		decryptedtext[i] = (unsigned char)msg[i];
	}
	//reading key from key.txt file
		 string k;
	    ifstream infile;
	    infile.open("key.txt");
	    if (infile.is_open())
	   {
		getline(infile, k); // The first line of file should be the key
		infile.close();
	   }

	   else cout << "Unable to open file";
	    istringstream tempkey(k);
	    unsigned char key[16];
	    unsigned int x1;
	    for(int i=0;i<16;i++)
	    {
	    tempkey>>hex>>x1;
		key[i] = x1;
	    }
	    //extending key
        unsigned char extendedkeys[176];
        Key_extenxion(key,extendedkeys);
      //decrypting our data
      for (int i = 0; i < messlength; i += 16)
      {
        unsigned char * temp=new unsigned char[16];
        for(int j=0;j<16;j++)
        temp[j]=decryptedtext[i+j];
		decryption(temp , extendedkeys);
		for(int j=0;j<16;j++)
            decryptedtext[i+j]=temp[j];
      }
      //printing our plain text
			for(int i=0;i<messlength;i++)
			{
			cout<<decryptedtext[i];
			if(decryptedtext[i]==0 && decryptedtext[i-1]==0 )
			break;
	     	}
    //storing plain text in outputtext.txt file
			  cout<<endl;
			  ofstream fout;  // Create Object of Ofstream
              ifstream fin;
              fin.open("outputtext.txt");
              fout.open ("outputtext.txt",ios::app); // Append mode
              if(fin.is_open())
                fout<<decryptedtext<<"\n"; // Writing data to file

             fin.close();
             fout.close(); // Closing the file
         Sleep(500);
		}
}
	else
         {
	      cout<<"Can not open input file\n ";
       }
       cout<<"\n Data has been appended to file outputtext.txt";
MyReadFile.close();
}
  }
}
void compression()
{
     int frequency[256];
	int ASCII_values[256];
	int actual_frequency[256];
	char ch;
	char filename[50];
	char cfilename[50];
	string decode;
	cout<<"\n\t====================================";
	cout<<"\n\t\t  Text File Compressor\n";
	cout<<"\t====================================";
	cout<<"\n\nEnter Name of File to Compress : ";
	cin>>filename;

   	for(int i=0;i < 255;i++)     //To set initial values of arrays
  	{
     		ASCII_values[i] = 0;
    	 	actual_frequency[i] = 0;
    	 	frequency[i] = 0;
   	}
   	calculate_frequency(frequency,filename);  	//To calculate frequency of each character in file

   	SeperateCharacter(frequency,actual_frequency,ASCII_values);  //Make actual frequency array and ASCII values

	printFrequencyTable(actual_frequency,ASCII_values);  // Print frequency table
	cout<<"\nCharacter Table with Huffman codes \n";
	cout<<"\n\tCharacter\t\tHuffman Code\n";

   	HuffmanCodes(ASCII_values,actual_frequency,count1);  //Function to build Huffman tree

	Convert_StringBits_to_IntegerBits();          //Converts character from charactermap to int vector

	int len = strlen(filename);
	filename[len-1] = 'p';
	filename[len-2] = 'm';
	filename[len-3] = 'c';
	cout<<"\n";
	cout<<"\nHuffman encoding Tree : \n";
	printTree(cout,minHeap.top(),0);      //To display formed Tree  with '■' as parent nodes(including root)
	write_codes();
	ofstream fout;
  	fout.open(filename,ios::binary);

	cal_compressionRatio();                //To calculate compression ratio
	int temp1;
	BitwiseWrite s(fout);
	cout<<"\nProcessing.... Plz wait !!!";
	for(int d = 0;d < Huffcode.size();d++) {
	    temp1 = Huffcode[d];
	    s.writeBit(temp1);                //To write Bit by bit by bit in compressed file
	  }
	cout<<"\nCompression Successful !!!";
	/*int v;
	cout<<"\nEnter any key to exit : ";
	cin>>v;
    	return 0;*/
}
void decompression()
{
    int total_bits_written;
	int current_bits = 0;
	char data;
	char filename[32];
	cout<<"\n\t====================================";
	cout<<"\n\t\t Text File Decompressor\n";
	cout<<"\t====================================";
	cout << "\n\nEnter name of code file: ";
	cin >> filename;
	ifstream codestream(filename);
	if (!codestream.is_open())
	{
		cout <<"Error !!! Cannot open code file.\n";
		exit(1);
	}
	Huffman h;
	h.buildDecodingTree(codestream);
	cout << "Here is the Huffman decoding tree:\n";
	h.displayDecodingTree(cout);
	cout << endl;
	cout << "\nEnter Name of Compressed file : ";
	cin >> filename;
	ifstream in;
	ofstream fout;
	fout.open("Decompressed.txt");
	in.open(filename,ios::binary);
	BitwiseRead os(in);
	if (!in.is_open())
	{
		cout << "Error !!! Cannot open Compressed file.\n";
		exit(1);
	}
	cout<<"\nProcessing..... Plz Wait";
	char ch3;
	ch3=char(129);
	while(true)
	{

		data = h.decode(os);
		if( data == ch3)
		{
			break;
		}
		current_bits++;
		fout << data;
	}
	//cout<<"\nCount = "<<count;
	cout<<"\nDecompression Successful !!!\n";
	cout<<"\nTotal Number of Times Tree Traversed : "<<total_traversal;
	cout<<endl;
}
void encryptionDES()
{
    cout<<"Do you want to put a Hex Message by your own?(y/n):";
	string message,key;
	char ch,endc;
	bool encrypt;
	cin>>ch;
	if(tolower(ch)=='y'){
		 while(1){
			 cout<<"Enter the hex message(all upper case,type quit to quit):";
			 cin>>message;
			 bool check=input_verifier(message);
			 if(check==true||message=="quit")break;
			 else{
			 	cout<<"Wrong Input!"<<endl;
			 }
	 	 }
	 	 while(1){
			 cout<<"Enter the hex key(0123456789ABCDEF):";
			 cin>>key;
			 bool check=input_verifier(key);
			 if(check==true||key=="quit")break;
			 else{
			 	cout<<"Wrong Input!"<<endl;
			 }
 	 	 }

 	 	 if(message=="quit"&&key=="quit"){
   			cout<<"Now program will run on hard coded hex message:0123456789ABCDEF \nand key:133457799BBCDFF1"<<endl;
			Sleep(1000);
			string message="0123456789ABCDEF",key="133457799BBCDFF1";
			string encrypted_msg=des_process(message,key,true);
		    	cout<<"Finally!!Hex Encrypted Message:"<<encrypted_msg<<endl;

			char ch;
			cout<<"Want to see decryption?(y/n):";
			cin>>ch;
			if(tolower(ch)=='y'){
				cout<<"Decrytion Starts:"<<endl;
				string decrypted_msg=des_process(encrypted_msg,key,false);
				cout<<"Finally!!DES Decrypted Hex Message:"<<decrypted_msg;
			}
		  }
	 	  else{
			 cout<<"Encrypt/Decrypt(e/d)?:";
		 	 cin>>endc;
		 	 if(tolower(endc)=='e')encrypt=true;
		 	 else encrypt=false;

		 	if(message!="quit" && key!="quit"){
		 		if(encrypt){
		 	 		string encrypted_msg=des_process(message,key,encrypt);
		 	 		cout<<"\nFinally!!DES Encrypted Hex Message:"<<encrypted_msg<<endl;
		 	 		cout<<"Do you want to see its decryption(y/n):";
		 	 		char input;
		 	 		cin>>input;
		 	 		if(tolower(input)=='y'){
	 	 				string decrypted_msg=des_process(encrypted_msg,key,false);
		 	 			cout<<"Finally!!DES Decrypted Hex Message:"<<decrypted_msg;
		 	 	}
		  	}
	 	  	else{
	   			string decrypted_msg=des_process(message,key,encrypt);
	  	 		cout<<"\nFinally!!DES Decrypted Hex Message:"<<decrypted_msg<<endl;
	  	 	}
	 	  }
	   	  else if(message=="quit"){
	    	   	cout<<"Now program will run on hard coded hex message:0123456789ABCDEF"<<endl;
		   	Sleep(1000);
			string message="0123456789ABCDEF";
			string encrypted_msg=des_process(message,key,encrypt);
		    	cout<<"Finally!!Hex Encrypted Message:"<<encrypted_msg<<endl;

			char ch;
			cout<<"Want to see decryption?(y/n):";
			cin>>ch;
			if(tolower(ch)=='y'){
				cout<<"Decrytion Starts:"<<endl;
				string decrypted_msg=des_process(encrypted_msg,key,false);
				cout<<"Finally!!DES Decrypted Hex Message:"<<decrypted_msg;
			}
	   	  }
	    	  else if(key=="quit"){
	    		cout<<"Now program will run on hard coded hex key:133457799BBCDFF1"<<endl;
			Sleep(1000);
			string key="133457799BBCDFF1";
			string encrypted_msg=des_process(message,key,encrypt);
		        cout<<"Finally!!DES Encrypted Hex Message:"<<encrypted_msg<<endl;

			char ch;
			cout<<"Want to see decryption?(y/n):";
			cin>>ch;
			if(tolower(ch)=='y'){
				cout<<"Decrytion Starts:"<<endl;
				string decrypted_msg=des_process(encrypted_msg,key,false);
				cout<<"Finally!!DES Decrypted Hex Message:"<<decrypted_msg;
			}
		   }
	       }
	}
	else{
	 	string ascii_table[26]={
	   		"61",
			"62",
			"63",
			"64",
			"65",
			"66",
			"67",
			"68",
			"69",
			"6A",
			"6B",
			"6C",
			"6D",
			"6E",
			"6F",
			"70",
			"71",
			"72",
			"73",
			"74",
			"75",
			"76",
			"77",
			"78",
			"79",
			"7A"

		};
   		string characters="abcdefghijklmnopqrstuvwxyz";
		cout<<"Do you want to put plaintext?(y/n):";
		char inp;
		cin>>inp;
		if(tolower(inp)=='y'){
			string str="",message="";
			cout<<"Type the plain text 8 characters long(a to z):";
			cin>>str;

			for(int i=0;i<str.length();i++){
				int find=0;
				while(1){
					if(str[i]==characters[find])break;
					find++;
				}
				message=message+ascii_table[find];
			}

			while(1){
				 cout<<"Enter the hex key(0123456789ABCDEF):";
				 cin>>key;
				 bool check=input_verifier(key);
				 if(check==true)break;
				 else{
				 	cout<<"Wrong Input!"<<endl;
				 }
 	 	 	}
			string enc_msg=des_process(message,key,true);
	    		cout<<"Finally!!Hex Encrypted Message:"<<enc_msg<<endl;

			char ch;
			cout<<"Want to see decryption?(y/n):";
			cin>>ch;
			if(tolower(ch)=='y'){
				cout<<"Decrytion Starts:"<<endl;
				string de_msg=des_process(enc_msg,key,false);
				cout<<"Finally!!DES Decrypted Hex Message:"<<de_msg;

				int len=2;
				string substring="",plain_txt="";
				for(int i=0;i<16;i+=2){
					int find=0;
					substring=de_msg.substr(i,len);
					while(1){
						if(ascii_table[find]==substring)break;
						find++;
					}
					plain_txt=plain_txt+characters[find];
		        	}
				cout<<"\nDecrypted plain text is:"<<plain_txt<<endl;
			}

		}
		else{
			cout<<"Now program will run on hard coded hex message:0123456789ABCDEF \nand key:133457799BBCDFF1"<<endl;
			Sleep(1000);
			string message="0123456789ABCDEF",key="133457799BBCDFF1";
			string encrypted_msg=des_process(message,key,true);
			cout<<"Finally!!Hex Encrypted Message:"<<encrypted_msg<<endl;

			char ch;
			cout<<"Want to see decryption?(y/n):";
			cin>>ch;
			if(tolower(ch)=='y'){
				cout<<"Decrytion Starts:"<<endl;
				string decrypted_msg=des_process(encrypted_msg,key,false);
				cout<<"Finally!!DES Decrypted Hex Message:"<<decrypted_msg;
			}
		}
	}
}
