#ifndef MAINPLAQUE_H_INCLUDED
#define MAINPLAQUE_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~
//structure for a Name with title, first name and last name

struct Name{

    private:
        //object variables
        string firstName;
        string lastName;
        string title;

    public:
        //constructors and destructor
        ~Name();
        Name();
        Name(string First, string Last);
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
        bool operator==(const Name &other)const;
        bool operator!=(const Name& other)const;


        //Name to string
        string nameToString(Name Name);

        //String to Name
        Name stringToName(string String, Name& Name);
        int wordCounter(string counter);
};


//insertion and extraction operators for Name
inline std::ostream& operator<<(std::ostream& out, Name& printer){
        out<<printer.getTitle()<<" "<<printer.getFirstName()<<" "<<printer.getLastName();
        return out;
}

inline std::istream& operator>> (std::istream& in, Name& reciever){
    string First="";
    string Last="";
    string Title="";

    in>>Title;
    in>>First;
    in>>Last;

    reciever.setFirstName(First);
    reciever.setLastName(Last);
    reciever.setTitle(Title);

    return in;
}

///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~
//class for mainPlaque

class mainPlaque {

    private:
        //object variables
        Name teacherName;
        string uniAbbrev;
        string gradYear;
        int saying;

    public:
        //constructors and destructor
        ~mainPlaque();
        mainPlaque();
        mainPlaque(Name Name, string Uni, string Year, int saying);
        mainPlaque(const mainPlaque& old);

        //setters and getters
        void setTeacherName(Name Name){teacherName=Name;}
        void setUniAbbrev(string Abbrev){uniAbbrev=Abbrev;}
        void setGradYear (string Year){gradYear=Year;}
        void setSaying (int Saying){saying=Saying;}
        Name getTeacherName(){return teacherName;}
        string getUniAbbrev(){return uniAbbrev;}
        string getGradYear(){return gradYear;}
        int getSaying(){return saying;}

        //print function
        void print(std::ostream& out);

        //operator overloading
        mainPlaque operator=(const mainPlaque& copied);



};

//insertion and extraction operators for mainPlaque
inline std::ostream& operator<<(std::ostream& out, mainPlaque& printer){
            printer.print(out);
            return out;
        }

inline std::istream& operator>> (std::istream& in, mainPlaque& reciever){
    Name Name;
    string Uni="";
    string tempYear="";
    string Year="";
    int Saying=0;

    in>>Name;
    in>>Uni;
    in>>tempYear;
    in>>Saying;
    in.ignore(100, '\n');

    Year=tempYear[0]+tempYear[1]+tempYear[2]+tempYear[3];

    reciever.setTeacherName(Name);
    reciever.setUniAbbrev(Uni);
    reciever.setGradYear(Year);
    reciever.setSaying(Saying);

    return in;
}



#endif // MAINPLAQUE_H_INCLUDED
