#ifndef SLINKEDLIST_CPP
#define SLINKEDLIST_CPP
#include "slinkedlist.h"
#include <iostream>

using namespace std;

template <class ItemType>
slinkedlist<ItemType>::slinkedlist(){
    head = NULL;
    currentPos = NULL;
    length = 0;
}

template <class ItemType>
slinkedlist<ItemType>::~slinkedlist(){
    makeEmpty();
}
template <class ItemType>
void slinkedlist<ItemType>::makeEmpty(){
    NodeType<ItemType> *t;

    while(head!=NULL){
        t = head;
        head = head->next;
        delete t;
    }

    length = 0;
}


template <class ItemType>
void slinkedlist<ItemType>::insrt(ItemType word,ItemType definition,ItemType synonym,ItemType antonym){
    NodeType<ItemType> *location = head;

    if(head==NULL){
        NodeType<ItemType> *t = new NodeType<ItemType>;
        t->word = word;
        t->definition = definition;
        t->synonym = synonym;
        t->antonym = antonym;
        t->next = NULL;
            head = t;
            currentPos = t;
    }
    else{
        if(word > currentPos->word){
            NodeType<ItemType> *t = new NodeType<ItemType>;
        t->word = word;
        t->definition = definition;
        t->synonym = synonym;
        t->antonym = antonym;
        t->next = NULL;
            currentPos->next = t;
            currentPos = t;
        }
        else if(word < head->word){
            NodeType<ItemType> *t = new NodeType<ItemType>;
        t->word = word;
        t->definition = definition;
        t->synonym = synonym;
        t->antonym = antonym;
            t->next = head;
            head = t;
        }
        else {
            while(!(location->next->word > word)){
                location = location->next;
            }

            NodeType<ItemType> *t = new NodeType<ItemType>;
        t->word = word;
        t->definition = definition;
        t->synonym = synonym;
        t->antonym = antonym;
            t->next = location->next;
            location->next = t;
        }
    }

    length++;
}

template <class ItemType>
void slinkedlist<ItemType>::DeleteItem(ItemType item){
    NodeType<ItemType> *t = head;
    NodeType<ItemType> *temp;

    if(head==NULL){
        cout << "No items in the list" << endl;
    }

    if(head->word == item){
        temp = t;
        head = head->next;
    }
    else{
        while(!(item==((t->next)->word))){
            t = t->next;
        }

        temp = t->next;
        t->next = (t->next)->next;
    }

    delete temp;
    cout<<"Word Deleted"<<endl;
    length--;
}

template <class ItemType>
bool slinkedlist<ItemType>::RetrieveItem(ItemType &item){
    NodeType<ItemType> *t = head;

    while(t!=NULL){
        if(t->word == item){
        cout<<"Word = " <<t->word<<endl;
        cout<<"Definition = " <<t->definition<<endl;
        cout<<"Synonym = " <<t->synonym<<endl;
        cout<<"Antonym = " <<t->antonym<<endl;
        cout<<endl;
            return true;
        }
        t = t->next;
    }
    return false;
}
#endif
