#ifndef CONTACTLIST_H_INCLUDED
#define CONTACTLIST_H_INCLUDED

#include "mainPlaque.h"

class contactList{

    private:
        //class variables
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

    public:
        //constructors and destructor
        contactList();
        ~contactList();
        contactList(Name one, Name two, Name three, Name four, Name five,string Sone, string Stwo, string Sthree, string Sfour, string Sfive);
        contactList(const contactList& old);

        //setters and getters
        void setCone(Name CONTACT){contactONE=CONTACT;}
        void setCtwo(Name CONTACT){contactTWO=CONTACT;}
        void setCthree(Name CONTACT){contactTHREE=CONTACT;}
        void setCfour(Name CONTACT){contactFOUR=CONTACT;}
        void setCfive(Name CONTACT){contactFIVE=CONTACT;}
        void setSone(string SCHOOL){schoolONE=SCHOOL;}
        void setStwo(string SCHOOL){schoolTWO=SCHOOL;}
        void setSthree(string SCHOOL){schoolTHREE=SCHOOL;}
        void setSfour(string SCHOOL){schoolFOUR=SCHOOL;}
        void setSfive(string SCHOOL){schoolFIVE=SCHOOL;}
        Name getCone(){return contactONE;}
        Name getCtwo(){return contactTWO;}
        Name getCthree(){return contactTHREE;}
        Name getCfour(){return contactFOUR;}
        Name getCfive(){return contactFIVE;}
        string getSone(){return schoolONE;}
        string getStwo(){return schoolTWO;}
        string getSthree(){return schoolTHREE;}
        string getSfour(){return schoolFOUR;}
        string getSfive(){return schoolFIVE;}

        //operator overloading
        contactList& operator=(const contactList& copied);

        //print function
        void print(std::ostream& out);

};

//insertion and extraction operators for teacherType

inline std::ostream& operator<<(std::ostream& out, contactList& printer){
            printer.print(out);
            return out;
        }

inline std::istream& operator>> (std::istream& in, contactList& reciever){
    Name one;
    Name two;
    Name three;
    Name four;
    Name five;

    string Sone;
    string Stwo;
    string Sthree;
    string Sfour;
    string Sfive;

    in>>one;
    in>>Sone;
    in>>two;
    in>>Stwo;
    in>>three;
    in>>Sthree;
    in>>four;
    in>>Sfour;
    in>>five;
    in>>Sfive;
    in.ignore(100, '\n');

    reciever.setCone(one);
    reciever.setSone(Sone);
    reciever.setCtwo(two);
    reciever.setStwo(Stwo);
    reciever.setCthree(three);
    reciever.setSthree(Sthree);
    reciever.setCfour(four);
    reciever.setSfour(Sfour);
    reciever.setCfive(five);
    reciever.setSfive(Sfive);

    return in;
}




#endif // CONTACTLIST_H_INCLUDED
