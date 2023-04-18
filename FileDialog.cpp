#include <string>
#include <iostream>

#include "FileDialog.h"

using namespace std;

FileDialog::FileDialog() {}

string FileDialog::GetOpenFilePath()
{
    cout << "Executed open file dialog" << endl;
    string res = "test_open.txt";
    return res;
}

string FileDialog::GetSaveFilePath()
{
    cout << "Executed save file dialog" << endl;
    string res = "test_save.txt";
    return res;
}
