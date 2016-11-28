

#include<iostream>
#include<fstream>
#include<stdio.h>
#include <algorithm>
#include <string>
#include <string.h>


using namespace std;

int main()
{   cout<<"name of file"<<endl;
    char fname[10],msg[50];
    string str;
    cin>>fname;
    ofstream ofs(fname,ios::in);
    if (ofs)
        {cout<<"file already exist"<<endl;}
    ofs.close();
    fstream fs;
    fs.open(fname,ios::out);
    if (!fs.is_open())
        {
        cout<<"CAnnot open file"<<endl;
        return 0;
        }
    fs<<"new string to work with\n";
    fs.close();
    fs.open(fname,ios::in);
    if(fs)
        {
        fs.read(msg,sizeof(msg));
        puts(msg);
        }
    else
        cout<<"nothing in"<<fname<<endl;
    cout<<"Errors with "<<fname<<": ";
    cerr<<fs;
    str=msg;
    transform(str.begin(), str.end(),str.begin(), ::toupper);
    const char * c = str.c_str();
    cout<<c;
    fstream nfs("newfile.txt",ios::in);
    nfs.open("newfile.txt",ios::out);
    nfs.write(c,strlen(c));
    nfs.close();
    return 0;
 }

