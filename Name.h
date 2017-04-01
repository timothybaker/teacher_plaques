#ifndef NAME_H
#define NAME_H

#include <string>
#include <iostream>

using namespace std;

///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~
//structure for a Name with title, first name and last name

class Name{

    private:
        //object variables
        string firstName;
        string lastName;
        string title;

    public:
        //constructors and destructor
        ~Name();
        Name();
        Name(string Title, string First, string Last);
        Name(const Name& old);

        //getters and setters
        void setFirstName(string First){firstName=First;}
        void setLastName(string Last) {lastName=Last;}
        void setTitle(string Title){title=Title;}
        string getFirstName(){return firstName;}
        string getLastName(){return lastName;}
        string getTitle(){return title;}

        //print function
        void print(std::ostream& out);

        //operator overloading
        Name operator=(const Name& copied);

};

//insertion and extraction operators for Name
inline std::ostream& operator<<(std::ostream& out, Name& printer){
            printer.print(out);
            return out;
        }

inline std::istream& operator>> (std::istream& in, Name& reciever){
    string First="";
    string Last="";
    string Title="";

    in>>Title;
    in>>First;
    in>>Last;

    in.ignore(100, '\n');

    reciever.setFirstName(First);
    reciever.setLastName(Last);
    reciever.setTitle(Title);

    return in;
}
#endif // NAME_H
