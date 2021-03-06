#include "Name.h"

///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~
//structure Name function definitions


///~///~///~///~///~///~///~
//destructor function

Name::~Name(){
}

///~///~///~///~///~///~///~
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

Name::Name(const Name& old){
    firstName=old.firstName;
    lastName=old.lastName;
    title=old.title;
}

///~///~///~///~///~///~///~
//operator overloading

Name Name::operator=(const Name& copied){
    return Name(copied);
}

///~///~///~///~///~///~///~
//print function

void Name::print(std::ostream& out){
    out<<title<<". "<<firstName<<" "<<lastName;
}


