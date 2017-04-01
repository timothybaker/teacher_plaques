#include "mainPlaque.h"
#include <sstream>

using namespace std;


///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~
//structure Name function definitions

////////////////////////////////////////////////
//function to turn a Name object into one string
string Name::nameToString(Name Name){
    string stringName="";
    stringName=(Name.title)+" "+(Name.firstName)+" "+(Name.lastName);
    return stringName;
}

/////////////////////////////////////////////////
//function to count the words in a string
int Name::wordCounter(string counter){
    istringstream giveItUp;
    string useLESS="Iguess";
    int words=0;

    giveItUp.str(counter);

    while(giveItUp>>useLESS){
        words++;
    }
    return words;
}

/////////////////////////////////////////////////
//function to convert a string containing 2 or 3
//words into a Name object
Name Name::stringToName(string String, Name& strung){
    int words=0;


    words=strung.wordCounter(String);

    string one="";
    string two="";
    string three="";

    istringstream giveItUp;
    giveItUp.str(String);

    // cout<<endl<<endl<<words<<endl<<endl;                                                     // will print the number of words in each name

    if (words==2){
        giveItUp>>one;

        giveItUp>>two;
        strung=Name(one,two);
    }
    else if (words==3){
        giveItUp>>one;
        giveItUp>>two;
        giveItUp>>three;
        strung=Name(one,two,three);
    }
   else {
        strung=Name();
    }

return strung;
}

//destructor function

Name::~Name(){
}

//constructor functions

Name::Name(){
    firstName="";
    lastName="";
    title="";
}

Name::Name(string Title, string First, string Last){
    title=Title;
    firstName=First;
    lastName=Last;
}

Name::Name(string First, string Last){
        firstName=First;
        lastName=Last;
        title="";
}
/////////////////////////////////////////////////////
//assignment constructor
Name::Name(const Name& old){
    firstName=old.firstName;
    lastName=old.lastName;
    title=old.title;
}

/////////////////////////////////////////////////////
//operator overloading

Name Name::operator=(const Name& old){
    firstName=old.firstName;
    lastName=old.lastName;
    title=old.title;
    return *this;
}

bool Name::operator==(const Name &other)const{
    if (this->firstName==other.firstName){
            if(this->lastName==other.lastName){
                return true;
            }
    }
    return false;
}

bool Name::operator!=(const Name& other)const{
    return !(*this==other);
}



/////////////////////////////////////////////////////
//print function

void Name::print(std::ostream& out){
    out<<title<<" "<<firstName<<" "<<lastName;
}



///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~
//class mainPlaque function definitions


/////////////////////////////////////////////////////
//destructor function
mainPlaque::~mainPlaque(){
}

///~///~///~///~///~///~///~
//constructor functions
mainPlaque::mainPlaque(){
    Name teacherName;
    uniAbbrev="";
    gradYear="";
    saying=' ';
}

mainPlaque::mainPlaque(Name Name, string Uni, string Year, int Saying){
    teacherName=Name;
    uniAbbrev=Uni;
    gradYear=Year;
    saying=Saying;
}

mainPlaque::mainPlaque(const mainPlaque& old){
    teacherName=old.teacherName;
    uniAbbrev=old.uniAbbrev;
    gradYear=old.gradYear;
    saying=old.saying;
}

///~///~///~///~///~///~///~
//operator overloading
mainPlaque mainPlaque::operator=(const mainPlaque& old){
    teacherName=old.teacherName;
    uniAbbrev=old.uniAbbrev;
    gradYear=old.gradYear;
    saying=old.saying;
    return *this;
}
///~///~///~///~///~///~///~
//print function
void mainPlaque::print(std::ostream& out){
    out<<teacherName<<endl<<uniAbbrev<<endl<<gradYear<<endl<<saying;
}
