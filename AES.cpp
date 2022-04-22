#include <iostream>
#include<bitset>
#include<iomanip>

using namespace std;

typedef bitset<8> byte;
typedef bitset<32> word;

int Nround = 10;
int Nkey = 4;

byte S_Box[16][16] = {
    {0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76},
    {0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0},
    {0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15},
    {0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75},
    {0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84},
    {0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF},
    {0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8},
    {0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2},
    {0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73},
    {0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB},
    {0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79},
    {0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08},
    {0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A},
    {0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E},
    {0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF},
    {0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16}
};

word Rcon[10] = {0x01000000, 0x02000000, 0x04000000, 0x08000000, 0x10000000,
                 0x20000000, 0x40000000, 0x80000000, 0x1b000000, 0x36000000};

word Word(byte& k1, byte& k2, byte& k3, byte& k4)
{
    word oneWord(0x00000000);
    word temp;
    temp = k1.to_ulong();
    temp<<=24; //first 8 bit
    oneWord|=temp;  // OR kore add
    temp = k2.to_ulong();
    temp<<=16;
    oneWord|=temp;
    temp = k3.to_ulong();
    temp<<=8;
    oneWord|=temp;
    temp = k4.to_ulong();
    oneWord|=temp;
    return oneWord;
}

word Rotword(word& key)
{
    word leftBits(0x00000000);
    leftBits=key>>24;
    key = (key<<8)|leftBits;
    return key;
}

word Subword(word& key)
{
    word temp;
    for(int i=0;i<32;i+=8)
    {
        int row = key[i+7]*8 + key[i+6]*4 + key[i+5]*2 + key[i+4];
        int col = key[i+3]*8 + key[i+2]*4 + key[i+1]*2 + key[i];
        byte val = S_Box[row][col];
        for(int j=0;j<8;j++)
        {
            temp[i+j]=val[j];
        }
    }
    return temp;
}

void KeyExpansion(byte key[16], word exKey[44])
{
    word temp;
    int i=0;
    while(i<Nkey)
    {
        exKey[i] = Word(key[4*i], key[(4*i)+1], key[(4*i)+2], key[(4*i)+3]);
        i++;
    }
    i = Nkey;

    while(i<4*(Nround+1))
    {
        temp = exKey[i-1];
        if(i%Nkey==0)
        {
            word S = Rotword(temp);
            S = Subword(S);
            exKey[i]= exKey[i-Nkey]^S^Rcon[i/Nkey-1];
        }
        else
        {
            exKey[i] = temp^exKey[i-Nkey];
        }
        i++;
    }

}

void addRoundKey(byte state[16], word roundKey[4])
{
    int i,j;
    for(int i=0,j=0;i<16,j<4;i+=4,j++)
    {
        word k1= roundKey[j]>>24;
        word k2 = (roundKey[j]<<8)>>24;
        word k3 = (roundKey[j]<<16)>>24;
        word k4 = (roundKey[j]<<24)>>24;
        cout<<"Round keys "<<hex<<k1.to_ulong()<<" "<<hex<<k2.to_ulong()<<" "<<hex<<k3.to_ulong()<<" "<<hex<<k4.to_ulong()<<endl;

        state[i] = state[i]^byte(k1.to_ulong());
        state[i+1] = state[i+1]^byte(k2.to_ulong());
        state[i+2] = state[i+2]^byte(k3.to_ulong());
        state[i+3] = state[i+3]^byte(k4.to_ulong());

    }

    cout <<endl<< "Add Round Key"<<endl;
    for(int i=0; i<4; i++)
    {
        for(int j=0;j<16;j+=4)
        {
        cout << setfill('0') << setw(2) << right << hex << state[j+i].to_ulong() << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void SubBytes(byte state[16])
{
    for(int i=0;i<16;i++)
    {
        int row = (state[i]>>4).to_ulong();
        int col = ((state[i]<<4)>>4).to_ulong();
        byte val = S_Box[row][col];
        state[i]=val;
    }
    cout <<endl<< "Sub Bytes"<<endl;
    for(int i=0; i<4; i++)
    {
        for(int j=0;j<16;j+=4)
        {
        cout << setfill('0') << setw(2) << right << hex << state[j+i].to_ulong() << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void ShiftRows(byte state[16])
{
    byte temp;
    temp = state[1];
    //2nd row
    for(int i=0;i<9;i+=4)
    {
        state[i+1] = state[i+5];
    }
    state[13]=temp;

    //3rd row
    for(int i=0;i<5;i+=4)
    {
        temp = state[i+2];
        state[i+2] = state[i+10];
        state[i+10]= temp;
    }

    //4th row
    temp = state[15];
    for(int i=15;i>6;i-=4)
    {
        state[i] = state[i-4];
    }
    state[3] = temp;

    cout <<endl<< "Shift Rows"<<endl;
    for(int i=0; i<4; i++)
    {
        for(int j=0;j<16;j+=4)
        {
        cout << setfill('0') << setw(2) << right << hex << state[j+i].to_ulong() << " ";
        }
        cout << endl;
    }
    cout << endl;
}

byte GFMul(byte a, byte b)
{
    byte p = 0;
    byte hi_bit_set;
    for (int counter = 0; counter < 8; counter++) {
        if ((b & byte(1)) != 0) {
            p ^= a;
        }
        hi_bit_set = (byte) (a & byte(0x80));
        a <<= 1;
        if (hi_bit_set != 0) {
            a ^= 0x1b;
        }
        b >>= 1;
    }
    return p;
}

void MixColumns(byte state[16])
{
    byte arr[4];
    for(int i=0;i<16;i+=4)
    {
        for(int j=0;j<4;j++)
        {
            arr[j] = state[i+j];
        }
        state[i] = GFMul(0x02, arr[0]) ^ GFMul(0x03, arr[1]) ^ arr[2] ^ arr[3];
        state[i+1] = arr[0] ^ GFMul(0x02, arr[1]) ^ GFMul(0x03, arr[2]) ^ arr[3];
        state[i+2] = arr[0] ^ arr[1] ^ GFMul(0x02, arr[2]) ^ GFMul(0x03, arr[3]);
        state[i+3] = GFMul(0x03, arr[0]) ^ arr[1] ^ arr[2] ^ GFMul(0x02, arr[3]);
    }
    cout <<endl<< "Mix Columns"<<endl;
    for(int i=0; i<4; i++)
    {
        for(int j=0;j<16;j+=4)
        {
        cout << setfill('0') << setw(2) << right << hex << state[j+i].to_ulong() << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void encrypt(byte state[16], word Key[44])
{
    word roundKey[4];
    for(int i=0;i<4;i++)
    {
        roundKey[i]= Key[i];
    }
    addRoundKey(state,roundKey);
    for(int r=1;r<Nround;r++)
    {
        cout<<endl<<"   Round "<<r<<endl;
        SubBytes(state);
        ShiftRows(state);
        MixColumns(state);
        for(int i=0;i<4;i++)
        {
            roundKey[i] = Key[4*r+i];
        }
        addRoundKey(state,roundKey);
    }
    cout<<endl<<"   Round 10"<<endl;
    SubBytes(state);
    ShiftRows(state);
    for(int i=0;i<4;i++)
        {
            roundKey[i] = Key[4*Nround+i];
        }
    addRoundKey(state,roundKey);
}

int main()
{
    byte plain[16] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0xfe,0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10};
    byte key[16] = {0x0f, 0x15, 0x71, 0xc9, 0x47, 0xd9, 0xe8, 0x59, 0x0c, 0xb7, 0xad, 0xd6, 0xaf, 0x7f, 0x67, 0x98};
    word exKey[44];
    KeyExpansion(key,exKey);
    encrypt(plain,exKey);
    cout <<endl<< "Encrypted Cipher Text:"<<endl;
    for(int i=0; i<4; i++)
    {
        for(int j=0;j<16;j+=4)
        {
        cout << setfill('0') << setw(2) << right << hex << plain[j+i].to_ulong() << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
