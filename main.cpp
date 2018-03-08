#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
int randInt(int max){
    return rand()%(max+1);
}
void writeCommendToFile(int num,ofstream &plik){
    static int actualCH=0;
    switch(num){
        case 0:
        {
            plik<<"IH "<<randInt(9)<<endl;
            return;
        }
        case 1:case 2:case 3:
        {
            plik<<"IH "<<randInt(9)<<endl;
            return;
        }
        case 4:
        {
            plik<<"DH"<<endl;
            return;
        }
        case 5: case 6: case 7:
        {
            plik<<"IT "<<randInt(9)<<endl;
            return;
        }
        case 8:
        {
            plik<<"DT"<<endl;
            return;
        }
        case 9:
        {
            plik<<"FV "<<randInt(9)<<endl;
            return;
        }
        case 10:
        {
            plik<<"RV "<<randInt(9)<<endl;
            return;
        }
        case 11:case 12:
        {
            plik<<"AD "<<!actualCH<<endl;
            return;
        }
        case 17:
        {
            plik<<"SH"<<endl;
            return;
        }
        case 13:
        {
            plik<<"ST"<<endl;
            return;
        }
        case 14:
        {
            plik<<"CL"<<endl;
            return;
        }
        case 15:case 16:
        {
            actualCH=!actualCH;
            plik<<"CH "<<actualCH<<endl;;
            return;
        }
    }
}
int main() {
    srand((unsigned)time(0));
    ofstream plik;
    plik.open("tester.txt");
    if(!plik.is_open()){
        cout<<"error opening file\n";
        return 1;
    }

    plik<< "GO 2\n" << "CH 0\n"<< "IN\n" << "CH 1\n"<< "IN\n"<< "CH 0\n";
    for(int i=0;i<1'000'000;++i){
        writeCommendToFile(randInt(17),plik);
    }
    plik<<"HA\n"<<endl;
    plik.close();
    return 0;
}