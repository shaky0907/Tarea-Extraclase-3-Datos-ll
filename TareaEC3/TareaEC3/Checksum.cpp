#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    cout <<"Server"<<endl;
    char a[20],b[20];
    char sum[20],complement[20], sum2[20];
    int i;

    cout<<"Por favor escriba el primer segmento de la informacion\n";
    cin>>a;
    cout<<"Por favor escriba el segundo segmento de la informacion\n";
    cin>>b;

    if(strlen(a)==strlen(b))
    {
        char carry='0';
        int length=strlen(a);

        for(i=length-1;i>=0;i--)
        {
            if(a[i]=='0' && b[i]=='0' && carry=='0')
            {
                sum[i]='0';
                carry='0';
            }
            else if(a[i]=='0' && b[i]=='0' && carry=='1')
            {
                sum[i]='1';
                carry='0';

            }
            else if(a[i]=='0' && b[i]=='1' && carry=='0')
            {
                sum[i]='1';
                carry='0';

            }
            else if(a[i]=='0' && b[i]=='1' && carry=='1')
            {
                sum[i]='0';
                carry='1';

            }
            else if(a[i]=='1' && b[i]=='0' && carry=='0')
            {
                sum[i]='1';
                carry='0';

            }
            else if(a[i]=='1' && b[i]=='0' && carry=='1')
            {
                sum[i]='0';
                carry='1';

            }
            else if(a[i]=='1' && b[i]=='1' && carry=='0')
            {
                sum[i]='0';
                carry='1';

            }
            else if(a[i]=='1' && b[i]=='1' && carry=='1')
            {
                sum[i]='1';
                carry='1';

            }
            else
                break;
        }
        cout<<"\nSuma="<<carry<<sum;

        for(i=0;i<length;i++)
        {
            if(sum[i]=='0')
                complement[i]='1';
            else
                complement[i]='0';
        }

        if(carry=='1')
            carry='0';
        else
            carry='1';

        cout<<"\nChecksum="<<carry<<complement;
    }
    else
        cout<<"\nLos segmentos están mal escritos";

    cout <<"\nCliente"<<endl;
    char c[20],d[20];
    char sum_recibido[20],complement_recibido[20];
    int j;

    cout<<"Por favor escriba el primer segmento de la informacion recibida\n";
    cin>>c;
    cout<<"Por favor escriba el segundo segmento de la informacion recibida\n";
    cin>>d;

    if(strlen(c)==strlen(a))
    {
        char carry='0';
        int length=strlen(c);

        for(j=length-1;j>=0;j--)
        {
            if(c[j]=='0' && d[j]=='0' && carry=='0')
            {
                sum[j]='0';
                carry='0';
            }
            else if(c[j]=='0' && d[j]=='0' && carry=='1')
            {
                sum[j]='1';
                carry='0';

            }
            else if(c[j]=='0' && d[j]=='1' && carry=='0')
            {
                sum[j]='1';
                carry='0';

            }
            else if(c[j]=='0' && d[j]=='1' && carry=='1')
            {
                sum[j]='0';
                carry='1';

            }
            else if(c[j]=='1' && d[j]=='0' && carry=='0')
            {
                sum[j]='1';
                carry='0';

            }
            else if(c[j]=='1' && d[j]=='0' && carry=='1')
            {
                sum[j]='0';
                carry='1';

            }
            else if(c[j]=='1' && d[j]=='1' && carry=='0')
            {
                sum[j]='0';
                carry='1';

            }
            else if(c[j]=='1' && d[j]=='1' && carry=='1')
            {
                sum[j]='1';
                carry='1';

            }
            else
                break;
        }

        cout<<"\nSuma_recibida="<<carry<<sum;
        carry='0';
        length;

        for(j=length-1;j>=0;j--)
        {
            if(complement[j]=='0' && sum[j]=='0' && carry=='0')
            {
                sum2[j]='0';
                carry='0';
            }
            else if(complement[j]=='0' && sum[j]=='0' && carry=='1')
            {
                sum2[j]='1';
                carry='0';

            }
            else if(complement[j]=='0' && sum[j]=='1' && carry=='0')
            {
                sum2[j]='1';
                carry='0';

            }
            else if(complement[j]=='0' && sum[j]=='1' && carry=='1')
            {
                sum2[j]='0';
                carry='1';

            }
            else if(complement[j]=='1' && sum[j]=='0' && carry=='0')
            {
                sum2[j]='1';
                carry='0';

            }
            else if(complement[j]=='1' && sum[j]=='0' && carry=='1')
            {
                sum2[j]='0';
                carry='1';

            }
            else if(complement[j]=='1' && sum[j]=='1' && carry=='0')
            {
                sum2[j]='0';
                carry='1';

            }
            else if(complement[j]=='1' && sum[j]=='1' && carry=='1')
            {
                sum2[j]='1';
                carry='1';

            }
            else
                break;
        }

        carry = '1';

        cout<<"\nSuma_recibida con complementaria="<<carry<<sum2;

        for(j=0;j<length;j++)
        {
            if(sum2[j]=='0')
                complement_recibido[j]='1';
            else
                complement_recibido[j]='0';
        }

        if(carry=='1')
            carry='0';
        else
            carry='1';

        cout<<"\nChecksum_final="<<carry<<complement_recibido;
        bool valid_solution = true;
        for (int k=0; k < (strlen(complement_recibido)); k++){
            if (complement_recibido[k] == '1'){
                valid_solution = false;
            }
        }
        if (valid_solution == true){
            cout << "\nno hay errores en la informacion recibida" << endl;
        }
        else{
            cout << "\nhay al menos un error en la informacion recibida" << endl;
        }
    }
    else
        cout<<"\nLos segmentos recibidos están mal escritos";




    return 0;
}
