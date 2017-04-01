#include "teacherType.h"
#include <sstream>


teacherType::teacherType()
{
    Name Name;
    mainPlaque plaque;
    yearsTaught=0;
    contactList clist;
}

teacherType::teacherType(Name Name, int YearsTaught, mainPlaque Plaque){
    Name=Name;
    yearsTaught=YearsTaught;
    plaque=Plaque;
    contactList clist;
}

teacherType::~teacherType()
{

}

teacherType::teacherType(const teacherType& other)
{
        teacherName=other.teacherName;
        yearsTaught=other.yearsTaught;
        for(int i=0;i<yearsTaught;i++){
            board[i]=other.board[i];
        }
        plaque=other.plaque;
        clist=other.clist;
}

teacherType& teacherType::operator=(const teacherType& other)
{
    if (this == &other) return *this;

    else{
        teacherName=other.teacherName;
        yearsTaught=other.yearsTaught;
        for(int i=0;i<yearsTaught;i++){
            board[i]=other.board[i];
        }
        plaque=other.plaque;
        clist=other.clist;
    }
    return *this;
}

bool teacherType::operator==(const teacherType &other)const{
    if (this->teacherName==other.teacherName){
            if(this->yearsTaught==other.yearsTaught){
                return true;
            }
    }
    return false;
}

bool teacherType::operator!=(const teacherType& other)const{
    return !(*this==other);
}

void teacherType::print(std::ostream& out){
        out<<plaque<<endl;
        for(int i=0; i<yearsTaught;i++){
            out<<board[i]<<endl;
        }
        out<<"///\n";
}

void teacherType::printContacts(std::ostream& out){
        string first=teacherName.getFirstName();
        string last=teacherName.getLastName();

        out<<"\n\nContact List for "<<first<<" "<<last<<endl<<endl;
        clist.print(out);
}

string teacherType::fileNames(string fileNumber){
        string first=teacherName.getFirstName();
        string last=teacherName.getLastName();
        string FileName="";
        string fileTYPE=".txt";


        FileName=first+last+fileNumber+fileTYPE;

        return FileName;
}
