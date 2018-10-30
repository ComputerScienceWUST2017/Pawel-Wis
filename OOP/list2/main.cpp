#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void initArrays(const int ppl, const int prod, float **&data) {
    data = new float *[ppl];

    for (int i = 0; i < ppl; ++i) {
        data[i] = new float[prod];
        for (int j = 0; j < prod; ++j) {
            data[i][j] = 0;
        }
    }

}

void saleProduct(const int numPpl, const int numProd, float **&data, string &input) {
    int salesmanNum, productNum;
    float value;
    if (sscanf(input.c_str(), "%d %d %f", &salesmanNum, &productNum, &value) != 3) { // checks if input is correct
        cout << "incorrect input" << endl;
        return;
    }

    if (salesmanNum <= 0 || salesmanNum > numPpl) {
        cout << "incorrect argument: number of salesman is wrong" << endl;
        return;
    }
    if (productNum <= 0 || productNum > numProd) {
        cout << "incorrect argument: number of product is wrong" << endl;
        return;
    }
    if (value < 0) {
        cout << "incorrect argument: price can not be negative" << endl;
        return;
    }
    data[salesmanNum - 1][productNum - 1] += value;
}

float sumRow(float **&data, int row, const int numProd) {
    float sum = 0;
    for (int i = 0; i < numProd; ++i) {
        sum += data[row][i];
    }
    return sum;
}

float sumCol(float **&data, int col, const int numPpl) {
    float sum = 0;
    for (int i = 0; i < numPpl; ++i) {
        sum += data[i][col];
    }
    return sum;
}

void printTable(const int numProd, const int numPpl, float **&data) {
    cout << setprecision(2) << fixed;   //
    cout << "                                 Product number\nSalesman";

    for (int i = 0; i < numProd; ++i) {
        cout << setw(13) << i + 1;
    }

    cout << setw(15) << "Total" << endl;

    for (int i = 0; i < numPpl; ++i) {
        cout << setw(8) << i + 1 << ": ";
        for (int j = 0; j < numProd; ++j) {
            cout << setw(11) << data[i][j] << "  ";
        }
        cout << setw(11) << sumRow(data, i, numProd) << endl;
    }
    cout << "   Total";
    for (int i = 0; i < numProd; ++i) {
        cout << setw(13) << sumCol(data, i, numPpl);
    }
    cout << endl;
}

int main() {
    const int numPpl = 5;
    const int numProd = 4;
    float **data;
    ifstream myfile;
    string inputLine;

    myfile.open("example.txt");
    if (!myfile.is_open()) {
        cout << "Couldn't open input file!" << endl;
        return 1;
    }

    initArrays(numPpl, numProd, data);

    while (getline(myfile, inputLine)) {
        saleProduct(numPpl, numProd, data, inputLine);
    }

    myfile.close();

    printTable(numProd, numPpl, data);

    return 0;
}