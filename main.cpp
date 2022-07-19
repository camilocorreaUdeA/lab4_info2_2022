#include<iostream>

using namespace std;

int main(){
    // memory leak - dangling pointer
    int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}}; // *ptr = arr[0]
    // **ptr = matrix[0][0]
    //cout<<"Matrix[0][0]: "<<*(*(matrix+1)+1)<<endl;

    /* new - new[]
    delete - delete[] */

    int** matrix2 = nullptr;
    matrix2 = new int*[3];
    for(int i=0; i<3; i++){
        matrix2[i] = new int[3];
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            *(*(matrix2+i)+j) = *(*(matrix+i)+j);
        }
    }

    cout<<matrix2[0][0]<<endl;
    cout<<matrix2[1][1]<<endl;
    cout<<matrix2[2][2]<<endl;

    for(int i=0; i<3; i++){
        delete[] matrix2[i];
    }

    delete[] matrix2;





    return 0;
}