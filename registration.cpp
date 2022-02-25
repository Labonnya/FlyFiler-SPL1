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
//
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
    main();

}
