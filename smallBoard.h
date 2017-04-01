#ifndef SMALLBOARD_H_INCLUDED
#define SMALLBOARD_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

class smallBoard {

    private:
        //object variables
        string gradeTaught;
        string schoolName;
        string schoolYear;
        char emblem;

    public:
        //constructors and destructor
        ~smallBoard();
        smallBoard();
        smallBoard(string Grade, string School, char Emblem, string Year);
        smallBoard(const smallBoard& old);

        //setters and getters
        void setGradeTaught(string Grade){gradeTaught=Grade;}
        void setSchoolName(string School){schoolName=School;}
        void setSchoolYear (string Year){schoolYear=Year;}
        void setEmblem (char Emblem){emblem=Emblem;}
        string getGradeTaught(){return gradeTaught;}
        string getSchoolName(){return schoolName;}
        string getSchoolYear(){return schoolYear;}
        char getEmblem(){return emblem;}

        //print function
        void print(std::ostream& out);

        //operator overloading
        smallBoard operator=(const smallBoard& old);

};

//insertion and extraction operators
inline std::ostream& operator<<(std::ostream& out, smallBoard& printer){
            printer.print(out);
            return out;
        }

inline std::istream& operator>> (std::istream& in, smallBoard& reciever){
    string Grade="";
    string School="";
    string tempYear="";
    string Year="";
    string tempEmblem="";
    char Emblem=' ';

    in>>Grade;
    in>>School;
    in>>tempYear;
    in>>tempEmblem;
    in.ignore(100, '\n');

    Emblem=tempEmblem[0];
    Year=(tempYear[0]+tempYear[1]+tempYear[2]+tempYear[3]);

    reciever.setGradeTaught(Grade);
    reciever.setSchoolName(School);
    reciever.setSchoolYear(Year);
    reciever.setEmblem(Emblem);

    return in;
}


#endif // SMALLBOARD_H_INCLUDED
