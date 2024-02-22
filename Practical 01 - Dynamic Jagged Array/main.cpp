#include <fstream>
#include <iostream>
#include <sstream>

int*** myArr = NULL;
int** numCols = NULL;
int numRows = 0;

void clearArray() {
    if (myArr==NULL) return;
    if (numCols==NULL) return;
    for (int i = 0; i < numRows; i++){
        //Dealocate all integers
        if (numCols[i] != NULL)
            for (int k = 0; k < *numCols[i]; k++){
                if (myArr[i][k]!=NULL) delete myArr[i][k]; 
            }           
                
        //Dealocate the row
        if (myArr[i]!=NULL) delete[] myArr[i];
    }
    //Dealocate myArr
    if (myArr!=NULL) delete[] myArr;
    myArr = NULL;
    std::cout<<"Deleted array with "<< numRows <<" rows"<<std::endl;

    if (numCols==NULL) return;
    for (int i = 0; i < numRows; i++)
        //Dealocate all integers
        if (numCols[i]!=NULL) delete numCols[i];
    //Dealocate numCols
    if (numCols!=NULL) delete[] numCols; 
    numCols = NULL;
    numRows = 0;
    
}

int getRowNum(std::string fileName){
    int result = 0;
    std:: fstream myFile(fileName.c_str ());
    std:: string col;
    while(std::getline(myFile ,col)){
        result++;
    }
    myFile.close();
    return result;
}

int getColNum(std::string colum){
    int result = 0;
    while (colum.length()!=0){
            if(colum.find(',') == std:: string ::npos){
                result++;
                colum.erase (0,colum.length());
            }
            else {
                result++;
                colum.erase (0,colum.find(',')+1);
            }
    }
    return result;
}

int** MakeColArr(std::string column) {
    std::string numStr;
    int num;
    int colCounter = getColNum(column);
    if (colCounter == 0) return NULL;

    int** result = new int*[colCounter];

    for (int c = 0; c < (colCounter - 1); c++) {
        numStr = column.substr(0, column.find(','));
        column.erase(0, column.find(',') + 1);
        std::istringstream iss(numStr);
        iss >> num;
        result[c] = new int(num);
    }

    numStr = column.substr(0, column.length());
    column.erase(0, column.length());
    std::istringstream iss(numStr);
    iss >> num;
    result[colCounter - 1] = new int(num);

    return result;
}



void populateFromFile(std::string fileName) {
    if (myArr != NULL) clearArray();
    
    numRows = getRowNum(fileName);

    if (numRows == 0){
        myArr=NULL;
        numCols=NULL;
        return;
    }
    myArr = new int**[numRows];
    numCols = new int*[numRows];

    std:: fstream myFile(fileName.c_str ());
    std:: string col;
    for (int r = 0; r < numRows; r++)
    {
        std::getline(myFile ,col);
        numCols[r] = new int(getColNum(col));
        myArr[r] = MakeColArr(col);     
    }

    std::cout<<"Created array from textfile with "<<numRows<<" rows"<<std::endl;

    myFile.close();
}

void populateFromTerminal() {
    if (myArr != NULL) clearArray();
    
    std::cin>>numRows;
    if (numRows == 0){
        myArr=NULL;
        numCols=NULL;
        return;
    }
    myArr = new int**[numRows];
    numCols = new int*[numRows];

    std:: string col;
    for (int r = 0; r < numRows; r++)
    {
       std::cin>>col;
        numCols[r] = new int(getColNum(col));
        myArr[r] = MakeColArr(col);     
    }

    std::cout<<"Created array from terminal with "<<numRows<<" rows"<<std::endl;
}

void printArr() {
    if (myArr==NULL){
        std::cout<<"Array is empty"<<std::endl;
        return;
    }
    
    for (int r = 0; r < numRows;r++){
        if (*numCols[r]>0){
            for (int c = 0; c < (*numCols[r]-1);c++)
                std::cout<<*myArr[r][c]<<",";
            std::cout<<*myArr[r][*numCols[r]-1]<<std::endl;
        }
        else std::cout<<std::endl;
    }
}

void printArrStructure() {
    if (numCols==NULL){
        std::cout<<"Array is empty"<<std::endl;
        return;
    }
    std::cout<<numRows<<":[";
    for (int r = 0; r < (numRows - 1); r++)
        std::cout<<*numCols[r]<<",";
    std::cout<<*numCols[numRows - 1]<<"]"<<std::endl;
}

int main() {
    std::cout << "Reading :\n";
    populateFromTerminal ();
    std::cout << "Printing\n";
    printArr ();
    printArrStructure ();
    clearArray ();
    return 0;
}