#include <iostream>
#include <cstring>
using namespace std;

char exor(char a,char b)                                      // perform exor operation
{
    if(a==b)
        return '0';
    else
        return '1';
}

void crc(char data[], char key[], bool next = false)
{
    int datalen = strlen(data);
    int keylen = strlen(key);

    for(int i=0;i<keylen-1;i++)                //appending n-1 zeroes to data
        data[datalen+i]='0';
    data[datalen+keylen-1]='\0';

    int codelen = datalen+keylen-1;                //lenght of appended data word

    char temp[20],rem[20];

    for(int i=0;i<keylen;i++)
        rem[i]=data[i];                    //considering n bits of data for each step of binary division/EXOR

    for(int j=keylen;j<=codelen;j++)
    {
        for(int i=0;i<keylen;i++)
            temp[i]=rem[i];                // remainder of previous step is divident of current step

        if(rem[0]=='0')                //if 1's bit of remainder is 0 then shift the rem by 1 bit
        {
            for(int i=0;i<keylen-1;i++)
                rem[i]=temp[i+1];
        }
        else                    //else exor the divident with generator key
        {
            for(int i=0;i<keylen-1;i++)
                rem[i]=exor(temp[i+1],key[i+1]);

        }
        if(j!=codelen)
            rem[keylen-1]=data[j];        //appending next bit of data to remainder obtain by division
        else
            rem[keylen-1]='\0';
    }

    for(int i=0;i<keylen-1;i++)
        data[datalen+i]=rem[i];                //replace n-1 zeros with n-1 bit CRC
    data[codelen]='\0';


    if(next){
        cout<<"CRC="<<rem<<"\nDataword="<<data;
        cout<<"\nREVISAR"<<endl;
        char rec[20];
        cout<<"Escriba la informacion recibida:";
        cin>>rec;

        crc(rec,key);
    }
    else{
        cout<<"Residuo="<<rem<<endl;

        bool paso = true;
        for(int i = 0; i < strlen(rem);i++){
            if(rem[i]!='0'){
                paso = false;
                break;
            }
        }

        if(paso){
            cout<<"El mensaje se mando correctamente"<<endl;
        }
        else{
            cout<< "El mensaje contiene un error"<<endl;
        }
    }

}

int main() {
    char key[20], data[20];

    cout << "Escriba la informacion:";
    cin >> data;
    cout << "Escriba el key:";
    cin >> key;

    crc(data, key,true);
    return 0;
}