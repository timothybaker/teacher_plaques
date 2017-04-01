#ifndef TEACHERTYPE_H
#define TEACHERTYPE_H

#include "mainPlaque.h"
#include "smallBoard.h"
#include "contactList.h"


class teacherType
{
    private:
        //teacherType variables
        Name teacherName;
        int yearsTaught;
        smallBoard board[50];
        mainPlaque plaque;
        contactList clist;


    public:
        //constructors and destructor

        teacherType();
        ~teacherType();
        teacherType(Name Name, int YearsTaught, mainPlaque Plaque);
        teacherType(const teacherType& old);

        //operator overloading
        teacherType& operator=(const teacherType& copied);
        bool operator==(const teacherType &other)const;
        bool operator!=(const teacherType& other)const;

        //setters and getters
        smallBoard getBoard(int index){return board[index];}
        mainPlaque getPlaque(){return plaque;}
        Name getTeacherName(){return teacherName;}
        contactList getContactList(){return clist;}
        int getYearsTaught(){return yearsTaught;}
        void setBoard(smallBoard Board[]){for(int i=0; i<50;i++){board[i]=Board[i];};}
        void setPlaque(mainPlaque Plaque){plaque=Plaque;}
        void setTeacherName(Name Name){teacherName=Name;}
        void setYearsTaught(int Years){yearsTaught=Years;}
        void setContactList(contactList Listed){clist=Listed;}


        //print functions
        void print(std::ostream& out);
        void printContacts(std::ostream& out);
        string fileNames(string fileNumber);

};



//insertion and extraction operators for teacherType

inline std::ostream& operator<<(std::ostream& out, teacherType& printer){
            printer.print(out);
            return out;
        }

inline std::istream& operator>> (std::istream& in, teacherType& reciever){
    Name Name;
    int Years=0;
    smallBoard board[50];
    mainPlaque plaque;

    in>>Name;
    in>>Years;
    for(int i=0;i<Years;i++){
        in>>board[i];
    }
    in>>plaque;
    in.ignore(100, '\n');

    reciever.setTeacherName(Name);
    reciever.setYearsTaught(Years);
    reciever.setBoard(board);
    reciever.setPlaque(plaque);

    return in;
}


#endif // TEACHERTYPE_H
