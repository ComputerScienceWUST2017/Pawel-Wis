#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

int *getKey(unsigned long size) {
    char *block = new char[size + 1];
    int *output = new int[size];
    block[0] = '\0';
    ifstream urandom("/dev/urandom", ios::in | ios::binary);
    urandom.read(block, size);
    for (unsigned long i = 0; i < size; ++i) {
        output[i] = abs(block[i]) % 26;
    }
    urandom.close();
    delete[] block;
    return output;
}

void printKey(const int *otp, unsigned long len) {
    for (unsigned long i = 0; i < len; ++i) {
        cout << otp[i] << ',';
    }
    cout << endl;
}

string encrypt(string &sentence, const int *otp) {
    string output;
    for (unsigned long i = 0; i < sentence.length(); ++i) {
        if (isalpha(sentence[i])) {
            output += (char) ((tolower(sentence[i]) + otp[i] - 97) % 26 + 97);
        } else {
            output += sentence[i];
        }
    }
    return output;
}

string decrypt(string &sentence, const int *otp) {
    unsigned long len = sentence.length();
    string output;
    for (unsigned long  i = 0; i < len; ++i) {
        if (isalpha(sentence[i])) {
            int decrChar = sentence[i] - otp[i] - 97;
            if (decrChar < 0) {
                decrChar += 26;
            }
            decrChar += 97;
            output += (char) decrChar;
        } else {
            output += sentence[i];
        }
    }
    return output;
}

int main() {
    string input = "Listen to me carefully, tomorrow you have a plane to Mexico at fifteen to eight. The ticket will be sent to you by e-mail. When you leave the airport, check a locker under the red telephone booth, open it with the secret password: spanishinqusition. You will find a new ID card, three thousand pesos and keys to the apartment against the street. From today you are Juan Pablo Fernandez Maria FC Barcelona John Sergio Vasily Shevchenko and you are a Russian immigrant from Romania. You work as a hairdresser two kilometers from the airport. Good luck, forget about your previous life and break all contacts, even with the customer service from the BBC";
    const int *key = getKey(input.length());
    string encrypted = encrypt(input, key);
    cout << input << endl << endl;
    cout << encrypted << endl << endl;
    printKey(key, input.length());
    cout << endl << decrypt(encrypted, key) << endl;
    return 0;
}