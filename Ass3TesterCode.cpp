#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
int randInt(int max){
    return rand()%(max+1);
}
void writeCommendToFile(int num,ofstream &file){
    static int actualCH=0;
    switch(num){
        case 0:
        {
            file<<"IH "<<randInt(9)<<endl;
            return;
        }
        case 1:case 2:case 3:
        {
            file<<"IH "<<randInt(9)<<endl;
            return;
        }
        case 4:
        {
            file<<"DH"<<endl;
            return;
        }
        case 5: case 6: case 7:
        {
            file<<"IT "<<randInt(9)<<endl;
            return;
        }
        case 8:
        {
            file<<"DT"<<endl;
            return;
        }
        case 9:
        {
            file<<"FV "<<randInt(9)<<endl;
            return;
        }
        case 10:
        {
            file<<"RV "<<randInt(9)<<endl;
            return;
        }
        case 11:case 12:
        {
            file<<"AD "<<!actualCH<<endl;
            return;
        }
        case 17:
        {
            file<<"SH"<<endl;
            return;
        }
        case 13:
        {
            file<<"ST"<<endl;
            return;
        }
        case 14:
        {
            file<<"CL"<<endl;
            return;
        }
        case 15:case 16:
        {
            actualCH=!actualCH;
            file<<"CH "<<actualCH<<endl;;
            return;
        }
    }
}
int main() {
    srand((unsigned)time(0));
    ofstream file;
    file.open("tester.txt");
    if(!file.is_open()){
        cout<<"error opening file\n";
        return 1;
    }

    file<< "GO 2\n" << "CH 0\n"<< "IN\n" << "CH 1\n"<< "IN\n"<< "CH 0\n";
    for(int i=0;i<1'000'000;++i){
        writeCommendToFile(randInt(17),file);
    }
    file<<"HA\n"<<endl;
    file.close();
    return 0;
}
