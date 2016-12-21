#include <iostream>
#include <windows.h>
using namespace std;
typedef void (*FunctionFunc)();
typedef void (*generateMatrixFunc)(int, int**);
typedef void (*ShowFunc)(int, int**);
typedef void (*changeMatrixFunc)(int, int**);
int main()
{
    int x;

    cout<<"VVEDITE width of MATRIX"<<endl;
    cin>>x;
    int **arr = new int* [x];
    for (int coun = 0; coun < x; coun++)
        arr[coun] = new int [x];

FunctionFunc _FunctionFunc;
generateMatrixFunc _generateMatrixFunc;
changeMatrixFunc _changeMatrixFunc;
ShowFunc _ShowFunc;

HINSTANCE hInstLibrary = LoadLibrary("DLL_MATRIX.dll");
   if (hInstLibrary)
   {
      _FunctionFunc = (FunctionFunc)GetProcAddress(hInstLibrary,"Function");
      _generateMatrixFunc = (generateMatrixFunc)GetProcAddress(hInstLibrary,"generateMatrix");
      _changeMatrixFunc = (changeMatrixFunc)GetProcAddress(hInstLibrary,"changeMatrix");
      _ShowFunc = (ShowFunc)GetProcAddress(hInstLibrary,"Show");
if (_FunctionFunc)
      {
         _FunctionFunc();
      }
      if (_generateMatrixFunc)
      {
         _generateMatrixFunc(x,arr);
      }
      if (_ShowFunc)
      {
         _ShowFunc(x,arr);
      }
       if (_changeMatrixFunc)
      {
         _changeMatrixFunc(x,arr);
      }
      cout<<endl;
       if (_ShowFunc)
      {
         _ShowFunc(x,arr);
      }

    FreeLibrary(hInstLibrary);
   }
   else
   {
      std::cout << "DLL Failed To Load!" << std::endl;
   }
   std::cin.get();
   for (int coun = 0; coun < x; coun++)
        delete [] arr[coun];
   return 0;
}
