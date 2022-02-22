void login()
{
    int count;
    string userID,password,id,pass;
    system("CLS");
    cout<<"\t\tPlease enter your username and password: \n";
    cout<<"\t\tUsername: ";
    cin>>userID;
    //cout<<"\n";
    cout<<"\t\tPassword: ";
    cin>>password;
    //

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
        main();
    }
    else
    {
        cout<<"\t\t Wrong information. Please check your username and password again.\n";
        main();
    }

}
