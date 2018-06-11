#include<iostream>
#include <ctime>
#include <sstream>
using namespace std; bool disable=false;
void showArray(int array[],int size){
    if(disable) return;
    for(int i=0;i<size;++i){
        cout<<array[i]<<',';
    }
    cout<<endl;
}
void insertSort(int array[], int size){
    int j,pickedVal;
    for(int i=size-1;i>=0;--i){
        j=size-1;
        pickedVal=array[i];
        while(j>i && pickedVal<=array[j]){
            --j;
        }
        for(int k=i;k<j;++k) {
            array[k] = array[k+1];
        }
        array[j]=pickedVal;
        showArray(array,size);
    }
}
void swap(int*arr,int p,int q){
    int temp=arr[p];
    arr[p]=arr[q];
    arr[q]=temp;
}
void bubbleSort(int array[], int size){
    for(int i=0;i<size-1;++i){
        for(int j=size-1;j>=1;--j){
            if(array[j]<array[j-1]){
                swap(array,j,j-1);
            }
        }
        showArray(array,size);
    }
}

void merge(int*arr,int left,int mid,int right){
    int l=left,r=mid+1,k=0;
    int *tempArr=new int[right-left+1];

    while(l<=mid && r<=right){
        if(arr[l]<=arr[r]){
            tempArr[k]=arr[l];
            ++l;
        }
        else{
            tempArr[k]=arr[r];
            ++r;
        }
        ++k;
    }

    while(l<=mid){
        tempArr[k]=arr[l];
        ++l;
        ++k;
    }

    while(r<=right){
        tempArr[k]=arr[r];
        ++r;
        ++k;
    }

    k=0;
    for(int i=left;i<=right;++i,++k){
        arr[i]=tempArr[k];
    }

        delete[] tempArr;

}
void mergeSortIter(int array[], int size){
    int width,left,mid,right;

    for (width=1;width<=size-1;width*=2)
    {

        for (left=0;left<size-1;left+=2*width)
        {
            right = left+2*width-1;
            if(right>size-1){
                right=size-1;
            }

            mid=left+width-1;

            if(mid<=right){
                merge(array,left,mid,right);
            }


        }
        showArray(array,size);
    }
}

int * loadArray(int size){
    int *arr=new int[size];
    for(int i=0;i<size;++i){
        cin>>arr[i];
    }
    return arr;
}

bool isCommand(const string command,const char *mnemonic){
    return command==mnemonic;
}
void generateRandom(int* &arrIS,int* &arrBS,int* &arrMS,int size){
    arrIS=new int[size];
    arrBS=new int[size];
    arrMS=new int[size];
    srand((unsigned)time(NULL));
    for(int i=0;i<size;++i){
        arrIS[i]=arrBS[i]=arrMS[i]=rand()%size;
    }
}
void measureTime(void (*sort)(int*,int),int size,int*arr,string which){
    clock_t begin,end;
    begin = clock();
    sort(arr,size);
    end = clock();
    cout<<endl<<which<<" for "<<size<<" "<<" time= "<<double(end-begin)/ CLOCKS_PER_SEC;
}
void compareTimes(int size){
    int *arrIS,*arrBS,*arrMS;
    generateRandom(arrIS,arrBS,arrMS,size);

    measureTime(&bubbleSort,size,arrBS,"BS");
    measureTime(&insertSort,size,arrIS,"IS");
    measureTime(&mergeSortIter,size,arrMS,"MS");

    delete[] arrBS;delete[] arrIS; delete[] arrMS;
}
int main(){

/*
    compareTimes(100);
    compareTimes(10'000);
    compareTimes(100'000);
*/

    string line;
    string command;
    int size=0;
    cout << "START" << endl;
    while(true){
        getline(cin,line);
        std::stringstream stream(line);
        stream >> command;
        if(line=="" || command[0]=='#')
        {
            // ignore empty line and comment
            continue;
        }

        // copy line on output with exclamation mark
        cout << "!" << line << endl;;

        // change to uppercase
        command[0]=toupper(command[0]);
        command[1]=toupper(command[1]);

        // read next argument, one int size
        stream >> size;

        // one-argument command
        if(isCommand(command,"HA")){
            cout << "END OF EXECUTION" << endl;
            break;
        }

        if(isCommand(command,"IS")) //*
        {
            int *arr=loadArray(size);
           // showArray(arr,size);
            insertSort(arr,size);
            continue;
        }

        if(isCommand(command,"BS")) //*
        {
            int *arr=loadArray(size);
            showArray(arr,size);
            bubbleSort(arr,size);
            continue;
        }

        if(isCommand(command,"MI"))
        {
            int *arr=loadArray(size);
            showArray(arr,size);
            mergeSortIter(arr,size);
            continue;
        }

        cout << "wrong argument in test: " << command << endl;
    }
    return 0;
}