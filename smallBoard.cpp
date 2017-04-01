#include "smallBoard.h"

///~///~///~///~///~///~///~
//destructor function
smallBoard::~smallBoard(){
}

///~///~///~///~///~///~///~
//constructor functions
smallBoard::smallBoard(){
    gradeTaught="";
    schoolName="";
    schoolYear="";
    emblem=' ';
}

smallBoard::smallBoard(string Grade, string School, char Emblem, string Year){
    gradeTaught=Grade;
    schoolName=School;
    schoolYear=Year;
    emblem=Emblem;
}

smallBoard::smallBoard(const smallBoard& old){
    gradeTaught=old.gradeTaught;
    schoolName=old.schoolName;
    schoolYear=old.schoolYear;
    emblem=old.emblem;
}




///~///~///~///~///~///~///~
//operator overloading
smallBoard smallBoard::operator=(const smallBoard& old){
    gradeTaught=old.gradeTaught;
    schoolName=old.schoolName;
    schoolYear=old.schoolYear;
    emblem=old.emblem;

    return *this;
}


///~///~///~///~///~///~///~
//print function
void smallBoard::print(std::ostream& out){
    out<<gradeTaught<<endl<<schoolName<<endl<<emblem<<endl<<schoolYear;
}
