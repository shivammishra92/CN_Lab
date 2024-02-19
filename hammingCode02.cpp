
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string decToBinary(int n) {

    int binaryNum[32];
    string bina, chan;
    int i = 0;
    if (n == 0) {
        return "0";
    } else {
        while (n > 0) {

            binaryNum[i] = n % 2;
            n = n / 2;
            i++;
        }

        for (int j = i - 1; j >= 0; j--) {
            bina = bina + to_string(binaryNum[j]);
        }
        return bina;
    }
}

int main() {
    string cw, chan, pos, cwt;
    int decimal = 0;
    char out[20];
    int rvali[30], pari[30], rout[30];
    int siz, i, rsiz, j = 0, k = 0, count = 1, p, le, poslen, flag = 0, sizt, l;
    cout << "Enter the code word ";
    cin >> cw;
    siz = cw.length();
    reverse(cw.begin(), cw.end());
    rvali[0] = 0;
    for (i = 0; i <= 100; i++) {
        if (pow(2, i) >= siz + i + 1) {
            rsiz = i;
            break;
        }
    }

    for (i = 0; j <= siz; i++) {
        if (((i + 1) == pow(2, k)) && (k <= rsiz)) {
            out[i] = 'r';
            k++;
        } else {
            out[i] = cw[j];

            j++;
        }
    }

    cout << "The number of data bits is " << siz;
    cout << "\nThe number of reduntant bits is " << rsiz;
    cout << "\nThe code word with reduntant bits is ";
    for (j = i; j >= 0; j--)
        cout << out[j];
    cout << "\nThe redundant bits are placed in position ";
    for (i = 0; i <= siz + rsiz; i++) {
        if (out[i] == 'r') {
            cout << i + 1 << " ";
            for (p = 0; p <= siz + rsiz; p++) {
                chan.clear();
                chan = decToBinary(p);
                chan = chan + "	";
                le = chan.length();
                if (i == 0) {
                    poslen = 0;
                } else {
                    pos = decToBinary(i);
                    poslen = pos.length();
                }
                if (chan[le - 12 - 1 - poslen] == '1')

                {

                    rvali[count] = p;
                    count++;
                }
            }

            rvali[count] = 0;
            count++;
            chan.clear();
        }
    }
    j = 0;
    for (i = 0; i < count; i++) {

        if (rvali[i] != 0) {
            if (out[(rvali[i] - 1)] == '1') {
                flag++;
            }
        }
        if (rvali[i] == 0 && i != 0) {
            pari[j] = flag;
            flag = 0;
            j++;
        }
    }

    j = 0;
    for (i = 0; i < 12; i++) {
        if (out[i] == 'r') {
            if (pari[j] % 2 == 0) {

                cout << "\nThe bit stored in r" << i + 1 << " is "
                     << "0";
                out[i] = '0';
            } else {
                out[i] = '1';
                cout << "\nThe bit stored in r" << i + 1 << " is "
                     << "1";
            }
            j++;
        }
    }
    for (i = 0; i < (siz + rsiz) / 2; i++) {
        swap(out[i], out[siz + rsiz - i - 1]);
    }
    cout << "\nThe data transferred is ";
    for (i = 0; i < 11; i++) {
        cout << out[i];
    }

    cout << "\nEnter the data after transmission to check error ";
    cin >> cwt;
    sizt = cwt.length();
    reverse(cwt.begin(), cwt.end());
    k = 0;
    l = 0;
    j = 0;

    for (p = 0; p < count; p++) {

        if (rvali[p] != 0) {

            if (cwt[(rvali[p] - 1)] == '1') {
                flag++;
            } else {
            }
        }
        if (rvali[p] == 0 && p != 0) {
            if (flag % 2 == 0) {

                rout[l] = 0;
            } else {

                rout[l] = 1;
            }

            flag = 0;
            l++;
        }
    }

    cout << "The redundant bits r4 r3 r2 r1 is ";
    for (i = 0; i < l; i++) {
        cout << " " << rout[i];
    }

    for (int i = l - 1; i >= 0; i--)
        decimal = decimal << 1 | rout[i];

    if (decimal == 0) {
        cout << "\nThere is no error in code";
    } else {
        cout << "\nThe error is in position " << decimal;

        for (int i = 0; i < sizt; i++) {
            if (i == decimal - 1) {
                if (cwt[i] == '0')
                    cwt[i] = '1';
                else
                    cwt[i] = '0';
            }
        }

        reverse(cwt.begin(), cwt.end());
        cout << "\nThe code after error correction is " << cwt;
    }

    cout << "\nBy Balachandra DS \n4NI18IS019";
    return 0;
}
