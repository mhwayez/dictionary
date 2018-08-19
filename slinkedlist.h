#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

template <class ItemType>
class NodeType{
    public:
        ItemType word;
        ItemType definition;
        ItemType synonym;
        ItemType antonym;
        NodeType *next;

};

template<class ItemType>
class slinkedlist{
    private:
        NodeType<ItemType> *head, *currentPos;
        int length;
    public:
        slinkedlist();
        ~slinkedlist();
        void makeEmpty();
        void insrt(ItemType word,ItemType definition,ItemType synonym,ItemType antonym);
        bool RetrieveItem(ItemType &);
        void DeleteItem(ItemType);
};

#endif

