#include<iostream>
#include<stdio.h>
#include <vector>
#include<string.h>
using namespace std;
int i, j;


string permutate(vector<int> array, string inp_string){
    string out_string = "";
    for(int i=0;i<array.size();i++)
        out_string += inp_string[array[i]-1];
    return out_string;
}

class SDES{
public:
    string KEY,K1,K2,IP_Output,INV_IP_Output;
    string Func_Output;
    string INPUT,OUTPUT;
    void initialise(string key)
    {
        KEY = key;
	    keys_gen();
    }


    void keys_gen();
    string left_shift(string input,int n);
    void DES_RoundOne();
    void DES_RoundTwo();
    void IP();
    void InvIP(string input);
    void Function_F(string left_input,string right_input,int key);
    string XOR(string a,string b);
    string SBOX0(string l);
	string SBOX1(string l);

};


void SDES :: keys_gen()
{

        cout<<"Enter the P10 permutation array: ";
        vector<int> P10(10,0);
        for(int i=0;i<10;i++)
            cin>>P10[i];
        string P10_output = permutate(P10,KEY);

        string P10_left = P10_output.substr(0,5), P10_right = P10_output.substr(5,5);
        string p_left = left_shift(P10_left,1), p_right = left_shift(P10_right,1);
        string p_total = p_left+p_right;
        cout<<"Enter the P8 permutation array: ";
        vector<int> P8(10,0);
        for(int i=0;i<8;i++)
            cin>>P8[i];
        K1 = permutate(P8,p_total);
        cout<<"K1: "<<K1<<endl;
	    string p_left1=left_shift(p_left,2), p_right1=left_shift(p_right,2);
       p_total = p_left1+p_right1;
        K2 = permutate(P8,p_total);
        cout<<"K2: "<<K2<<endl;
}

string SDES:: left_shift(string input,int n)
{
    string output = input;
        char firstbit;
	    while(n--){
            firstbit = output[0];
            output = output.substr(1,output.size()-1);
            output += firstbit;
        }
        return output;
}

void SDES:: DES_RoundOne()
{
        IP();
        string LIP = IP_Output.substr(0,4);
        string RIP = IP_Output.substr(4,8);
        cout<<"IP output: "<<IP_Output<<endl;
        Function_F(LIP,RIP,1);
        cout<<"Fn Output: "<<Func_Output<<endl;
}


void SDES:: DES_RoundTwo()
{
    string L1 = Func_Output.substr(0,4), R1 = Func_Output.substr(4,4);
    Function_F(R1,L1,2);
    cout<<"Fn Output second time: "<<Func_Output<<endl;
    InvIP(Func_Output);
    cout<<"\nENCRYPTED STRING IS: "<<INV_IP_Output<<endl;
}




void SDES:: IP()
{
    vector<int> IP_array(8,0);
        cout<<"Enter initial permutation array: ";
        for(int i=0;i<8;i++)
            cin>>IP_array[i];
        IP_Output = permutate(IP_array,INPUT);
}

void SDES:: InvIP(string input)
{
    vector<int> InvIPArray(8,0);
    cout<<"Enter Inverse initial permutation: ";
    for(int i=0;i<8;i++)
        cin>>InvIPArray[i];
    INV_IP_Output = permutate(InvIPArray,input);
}

void SDES:: Function_F(string left_input,string right_input,int key)

{
    cout<<"Enter E/P array: ";
    vector<int> E_P(8,0);
    for(int i=0;i<8;i++)
        cin>>E_P[i];
    string E_POutput = permutate(E_P,right_input);
    string XOR_Output;
    if(key == 1)
        XOR_Output = XOR(E_POutput,K1);
    else
        XOR_Output = XOR(E_POutput,K2);
    string left_xor = XOR_Output.substr(0,4),right_xor = XOR_Output.substr(4,8);
    string SBOX0_Output=SBOX0(left_xor);
    string SBOX1_Output=SBOX1(right_xor);
    string SBOX_Output = SBOX0_Output+SBOX1_Output;
    cout<<"Enter P4 Operation array: ";
    vector<int> P4(4,0);
    for(int i=0;i<4;i++)
        cin>>P4[i];
    string P4_Output = permutate(P4,SBOX_Output);
    string fk_Output = XOR(P4_Output,left_input);
    Func_Output = fk_Output + right_input;
}

string SDES:: XOR(string a,string b)
{
    string output = "";
    for(int i=0;i<a.size();i++){
        if(a[i] == b[i])
            output += "0";
        else
            output += "1";
    }
    return output;
}

string SDES :: SBOX0(string l)
{
        cout<<"\nSO Table: \n";
        vector<int> temp(4,0);
        vector<vector<int> > S0(4,temp);
        S0[0][0]=1;
        S0[0][1]=0;
        S0[0][2]=3;
        S0[0][3]=2;
        S0[1][0]=3;
        S0[1][1]=2;
        S0[1][2]=1;
        S0[1][3]=0;
        S0[2][0]=0;
        S0[2][1]=2;
        S0[2][2]=1;
        S0[2][3]=3;
        S0[3][0]=3;
        S0[3][1]=1;

        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
                cout<<S0[i][j]<<"\t";
            cout<<"\n";
        }



        string bits[]={"00","01","10","11"};
	    string lrow = l.substr(0,1)+l.substr(3,1),lcol = l.substr(1,1)+l.substr(2,1);
	    string SO;
        int i,lr,lc,b;
        for(i=0;i<4;i++){
            if(lrow == bits[i])
                lr=i;
            if(lcol == bits[i])
                lc=i;
        }
        b=S0[lr][lc];
        return bits[b];
}

string SDES ::  SBOX1(string l)
{
        cout<<"\nS1 Table: \n";
        vector<int> temp(4,0);
        vector<vector<int> > S1(4,temp);
        S1[0][0]=0;
        S1[0][1]=1;
        S1[0][2]=2;
        S1[0][3]=3;
        S1[1][0]=2;
        S1[1][1]=0;
        S1[1][2]=1;
        S1[1][3]=3;
        S1[2][0]=3;
        S1[2][1]=0;
        S1[2][2]=1;
        S1[2][3]=0;
        S1[3][0]=2;
        S1[3][1]=1;
        S1[3][2]=0;
        S1[3][3]=3;

        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
                cout<<S1[i][j]<<"\t";
            cout<<"\n";
        }

        string bits[]={"00","01","10","11"};
	    string lrow = l.substr(0,1)+l.substr(3,1),lcol = l.substr(1,1)+l.substr(2,1);
	    string SO;
        int i,lr,lc,b;
        for(i=0;i<4;i++){
            if(lrow == bits[i])
                lr=i;
            if(lcol == bits[i])
                lc=i;
        }
        b=S1[lr][lc];
        return bits[b];
}



int main()
{
    SDES sdes, s;
    int i;
    int n=10;
    string key;
    cout<<"ENCRYPTION OF DATA USING SIMPLE DES ALGORITHM";
    cout<<"\nEnter Key:";
    cin>>key;
    sdes.initialise(key);
    cout<<"\nEnter 8-bit plain text string to encrypt:\n";
    cin>>s.INPUT;
    cout<<"\nRound 1 of encryption: \n";
    s.DES_RoundOne();
    cout<<"\nRound 2 of encryption: \n ";
    s.DES_RoundTwo();

}
