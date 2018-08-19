#include <iostream>
#include "slinkedlist.h"
#include "slinkedlist.cpp"

using namespace std;

int main(){
    slinkedlist<string> mydic;
    string f,w,d,s,a,dl;
    bool check=true;
    while(check==true){
    cout<<":::CSE225 Dictionary:::"<<endl;
    cout<<"Please Enter 1 for find a word from Dictionary"<<endl;
    cout<<"Please Enter 2 for add new Word to Dictionary"<<endl;
    cout<<"Please Enter 3 for delete a word from Dictionary"<<endl;
    cout<<"Please Enter 4 for exit"<<endl;
    int ch;
    cin>>ch;
    switch(ch){

    case 1: cout<<"Enter Your Word"<<endl;
            cin>>f;
            if(mydic.RetrieveItem(f))
            {

            }
            else
                cout<<" Word Not Found"<<endl;
            break;

    case 2:
            cout<<"Please Enter Word"<<endl;
            cin>>w;
            cout<<"Please Enter definition"<<endl;
            cin>>d;
            cout<<"Please Enter synonym"<<endl;
            cin>>s;
            cout<<"Please Enter antonym"<<endl;
            cin>>a;
            mydic.insrt(w,d,s,a);
            break;

    case 3:
            cout<<"please Enter word to delete"<<endl;
            cin>>dl;
            mydic.DeleteItem(dl);
            break;

    case 4: check=false;
            break;

    }
    }
    return 0;
}
