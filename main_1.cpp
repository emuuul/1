#include <iostream>

using namespace std;

int main()
{
    int N;
    cout << "enter size:";
    bool check = true;
    while(check){
        cin >> N;
        if(N >= 2 && N <= 10000){
            check = false;
        }
        else{
            cout << "wrong number! Please try again\n";
        }
    }
    int *Buff = new int[N];
    
    cout << "enter numbers:\n";
    for(int i=0; i<N; i++){
        cout << i+1 << ")";
        cin >> Buff[i];
    }
    
    int count = 0;
    
    for(int i=0; i<N; i++){
        if(Buff[i] % 3 == 0){
            count++;
        }
    }

    int ANcount = N - count;

    int *newArr = new int[ANcount]; 
    int *newBuff = new int[count];
    
    for(int i=0, j=0, k=0; i<N; i++){
        if(Buff[i] % 3 == 0){
            newBuff[j] = Buff[i];
            j++;
        }
        else{
            newArr[k] = Buff[i];
            k++;
        }
    }
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - 1; j++) {
            if (newBuff[j] > newBuff[j + 1]) {
                int temp = newBuff[j];
                newBuff[j] = newBuff[j + 1];
                newBuff[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < ANcount; i++) {
        for (int j = 0; j < ANcount - 1; j++) {
            if (newArr[j] > newArr[j + 1]) {
                int temp = newArr[j];
                newArr[j] = newArr[j + 1];
                newArr[j + 1] = temp;
            }
        }
    }
    
    int  *result = new int[N];
    int count2 = 0;
    for(int i=0;i < count; i++){
        result[count2] = newBuff[i];
        count2++;
    }
    for(int i=0;i < ANcount; i++){
        result[count2] = newArr[i];
        count2++;
    }
    cout << "result:";
    for(int i = 0; i <N; i++){
        cout << result[i] << " ";
    }
    delete[] Buff;
    delete[] newArr;
    delete[] newBuff;
    delete[] result;
    return 0;
}
