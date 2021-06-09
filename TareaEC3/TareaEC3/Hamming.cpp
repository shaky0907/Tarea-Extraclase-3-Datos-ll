#include<iostream>

using namespace std;

int main() {
    int data[10];
    int dataatrec[10], c, c1, c2, c3, i;

    cout << "Escriba 4 bits uno por uno:\n";
    cin >> data[0];
    cin >> data[1];
    cin >> data[2];
    cin >> data[4];

    //Calculation of even parity
    data[6] = data[0] ^ data[2] ^ data[4];
    data[5] = data[0] ^ data[1] ^ data[4];
    data[3] = data[0] ^ data[1] ^ data[2];

    cout << "\nLa informacion codificada es:\n";
    for (i = 0; i < 7; i++)
        cout << data[i];

    cout << "\n\nEscriba la informacion recibida bit por bit:\n";
    for (i = 0; i < 7; i++)
        cin >> dataatrec[i];

    c1 = dataatrec[6] ^ dataatrec[4] ^ dataatrec[2] ^ dataatrec[0];
    c2 = dataatrec[5] ^ dataatrec[4] ^ dataatrec[1] ^ dataatrec[0];
    c3 = dataatrec[3] ^ dataatrec[2] ^ dataatrec[1] ^ dataatrec[0];
    c = c3 * 4 + c2 * 2 + c1;

    if (c == 0) {
        cout << "\nNo hubo error durante la transmision\n";
    }
    else {
        cout << "\nError en la posicion: " << c;
        cout << "\nInfo enviada : ";
        for (i = 0; i < 7; i++)
            cout << data[i];

        cout << "\nInfo recibida : ";
        for (i = 0; i < 7; i++)
            cout << dataatrec[i];

        cout << "\nEl mensaje correcto es:\n";

        //if errorneous bit is 0 we complement it else vice versa
        if (dataatrec[7 - c] == 0)
            dataatrec[7 - c] = 1;
        else
            dataatrec[7 - c] = 0;
        for (i = 0; i < 7; i++) {
            cout << dataatrec[i];
        }
    }
    return 0;
}