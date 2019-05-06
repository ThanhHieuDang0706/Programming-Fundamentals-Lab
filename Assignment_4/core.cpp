//
// Created by Nguyen Duc Dung on 2019-04-20.
//

#include "core.h"

using namespace std;

struct recManager

void PrintOutput(const char* pRequest, void* pData, void* &pOutput, int N) {
    cout << pRequest << ":";
    int*    pInt = (int*)pOutput;
    for (int i = 0; i < N; ++i) {
        cout << ' ' << *pInt++;
    }
    cout << '\n';
}

void Initialization() {
    // TODO: Please implement the initialization step if it is required
    //       for your program. You can ignore this one if you don't have
    //       anything to initialize.
    char pFName[] = "diabetes.csv";
    ifstream csv(pFName);
    string tmp;
    while (getline(csv, tmp)) ++numLines;
    csv.close();

}

void Finalization() {
    // TODO: Please implement this finalization step if you have to clean up
    //       the application before exiting. Please ignore if you don't have
    //       anything to do before exiting.
    // NOTE: Any data that you allocated MUST BE CLEAN UP
}

void LoadData(const char* pFName, void* &pData) {
    // TODO: Load the records from the given file. The name of data file
    //       is given in pFName. The data that you load into is pointed to
    //       by the pointer pData. You should make decision on what data
    //       type will be used to store records.
    ifstream csv(pFName);
    pData = (Record*) pData;
    Record* data = new Record[numLines];
    pData = data;

    for (int i = 0; i < numLines; ++i) {
        csv >> (data[i]).pregnancies;
        csv.get(); 
        csv >> (data[i]).glucose;
        csv.get();
        csv >> (data[i]).bloodPressure;
        csv.get(); 
        csv >> (data[i]).skinThickness;
        csv.get();
        csv >> (data[i]).insulin;
        csv.get();
        csv >> (data[i]).BMI;
        csv.get();
        csv >> (data[i]).DPF;
        csv.get();
        csv >> (data[i]).age;
        csv.get();
        csv >> (data[i]).outcome;
        csv.get();
    }
    csv.close();
}

void ReleaseData(void* &pData) {
    // TODO: Release any data that you loaded. Please remember that there
    //       MUST BE NO MEMORY LEAK in this program.
}

void ProcessRequest(const char* pRequest, void* pData, void* &pOutput, int& N) {
    // TODO: Please implement this function to process requests from client.
    //       The reuqest is given in form of a string pointed by pRequest.
    //       The data that you stored if pointed by pData.
    //       The output MUST BE STORED in the memory pointed by pOutput.
    //       N is the number of integers in the output.
    if (strcmp("CR", pRequest) == 0) {
        N = 1;
        int *output = new int;
        pOutput = output;
        *output = numLines;
    } else if (strcmp("FR", pRequest)) {
        
    }

}

int main () {
    Initialization();
    void*   pData;
    LoadData("diabetes.csv", pData);
    printf("Done");
    struct Record * tmp = (Record*)pData;
    cout << tmp[0].pregnancies << endl;
    cout << tmp[2].pregnancies << endl;
    return 0;
}
