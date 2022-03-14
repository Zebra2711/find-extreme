#include<conio.h>
#include<stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <limits>
std::fstream& GotoLine(std::fstream& file, unsigned int num){
    file.seekg(std::ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}
using namespace std;
int main9()
{
    //READ FILE
    ifstream FileIn;
    FileIn.open("D:\\NewText.txt", ios_base::in);
    if (FileIn.fail()==true)
    {
        cout<<"Khong ton tai file\n";
        system("pause");
        return 0;
    }
    //system("cls");
    string s;
    while(getline(FileIn,s))
    {
        cout<<s<<endl;
    }
    FileIn.close();
    //WRITE FILE
    char data_input[100];
    fgets(data_input,100,stdin);
    ofstream FileOut;
    FileOut.open("D:\\NewText2.txt",ios_base::out);
    long pos = FileOut.tellp();
    //FileOut<<endl;
    //FileOut.seekp();
    FileOut<<data_input;
    fflush(stdin);
    FileOut.close();
    system("pause");
    return 0;
}


