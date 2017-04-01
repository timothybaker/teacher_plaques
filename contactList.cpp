#include "contactList.h"


contactList::contactList()
{
        Name contactONE;
        Name contactTWO;
        Name contactTHREE;
        Name contactFOUR;
        Name contactFIVE;

        string schoolONE;
        string schoolTWO;
        string schoolTHREE;
        string schoolFOUR;
        string schoolFIVE;
}

contactList::contactList(Name one, Name two, Name three, Name four, Name five, string Sone, string Stwo, string Sthree, string Sfour, string Sfive)
{
        contactONE=one;
        contactTWO=two;
        contactTHREE=three;
        contactFOUR=four;
        contactFIVE=five;

        schoolONE=Sone;
        schoolTWO=Stwo;
        schoolTHREE=Sthree;
        schoolFOUR=Sfour;
        schoolFIVE=Sfive;
}


contactList::~contactList()
{

}


contactList::contactList(const contactList& other)
{
        contactONE=other.contactONE;
        contactTWO=other.contactTWO;
        contactTHREE=other.contactTHREE;
        contactFOUR=other.contactFOUR;
        contactFIVE=other.contactFIVE;

        schoolONE=other.schoolONE;
        schoolTWO=other.schoolTWO;
        schoolTHREE=other.schoolTHREE;
        schoolFOUR=other.schoolFOUR;
        schoolFIVE=other.schoolFIVE;
}



contactList& contactList::operator=(const contactList& other)
{
    if (this == &other) return *this;

    else{
        contactONE=other.contactONE;
        contactTWO=other.contactTWO;
        contactTHREE=other.contactTHREE;
        contactFOUR=other.contactFOUR;
        contactFIVE=other.contactFIVE;

        schoolONE=other.schoolONE;
        schoolTWO=other.schoolTWO;
        schoolTHREE=other.schoolTHREE;
        schoolFOUR=other.schoolFOUR;
        schoolFIVE=other.schoolFIVE;
    }
    return *this;
}



void contactList::print(std::ostream& out){
        out<<contactONE<<" "<<"-- "<<schoolONE<<endl;
        out<<contactTWO<<" "<<"-- "<<schoolTWO<<endl;
        out<<contactTHREE<<" "<<"-- "<<schoolTHREE<<endl;
        out<<contactFOUR<<" "<<"-- "<<schoolFOUR<<endl;
        out<<contactFIVE<<" "<<"-- "<<schoolFIVE<<endl;
}
