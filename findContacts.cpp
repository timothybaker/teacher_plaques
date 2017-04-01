#include "findContacts.h"
#include "contactList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>


int genRandomNumber(int nmax);

/////////////////////////////////////////////////////////
//function to find contacts based on rules 1-10

void findContacts(int orderNumbers, teacherType Hurray[]){

    bool allContacts=false;
    bool allFilledUp=false;
    bool gotCone=false;
    bool gotCtwo=false;
    bool gotCthree=false;
    bool gotCfour=false;
    bool gotCfive=false;
    teacherType searcher;
    mainPlaque seekAnd;
    smallBoard destroy[50];
    contactList filling;
    Name theONE;
    Name BLANK;
    string andONLY;
    int rule1=0;
    int rule2=0;
    int rule3=0;
    int rule4=0;
    int rule5=0;
    int rule6=0;
    int rule7=0;
    int rule8=0;
    int rule9=0;
    int rule10=0;

    srand(time(0));	    //Seed srand for the random number generator for rule 10

    while(allContacts==false){ //loops through until all teachers who have placed an order have a contact list generated

        for(int j=0;j<orderNumbers-1;j++){
            teacherType searcher=Hurray[j];
            seekAnd=searcher.getPlaque();
            for (int k=0;k<50;k++){
                destroy[k]=searcher.getBoard(k);
            }
    gotCone=false;
    gotCtwo=false;
    gotCthree=false;
    gotCfour=false;
    gotCfive=false;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//contact one

            /////////////////////////////
            //rule 1
            while(allFilledUp==false){
                for (int i=0;i<orderNumbers-1;i++){
                    if ((seekAnd.getUniAbbrev()==Hurray[i].getPlaque().getUniAbbrev())&& searcher!=Hurray[i]&&
                    (destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())){
                        int seekerGrad=atoi(seekAnd.getGradYear().c_str());
                        int soughtGrad=atoi(Hurray[i].getPlaque().getGradYear().c_str());
                        if(seekerGrad<=soughtGrad+3 && seekerGrad>=soughtGrad-3){
                            if(destroy[searcher.getYearsTaught()].getGradeTaught()==Hurray[i].getBoard(Hurray[i].getYearsTaught()).getGradeTaught()){
                                string converter="";
                                converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                                theONE.stringToName(converter,theONE);
                                andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                                filling.setCone(theONE);
                                filling.setSone(andONLY);
                                allFilledUp=true;
                                gotCone=true;
                                rule1++;
                                theONE=BLANK;
                                andONLY="";
                                break;
                            }
                        }
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;


            ////////////////////////////////////////
            //rule 2
           while(allFilledUp==false&&gotCone==false){
                for(int i=0;i<orderNumbers-1;i++){
                    if ((seekAnd.getGradYear()==Hurray[i].getPlaque().getGradYear())&& seekAnd.getUniAbbrev()==Hurray[i].getPlaque().getUniAbbrev() && searcher!=Hurray[i] &&
                    (destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())){
                        string converter="";
                        converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                        theONE.stringToName(converter,theONE);
                        andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                        filling.setCone(theONE);
                        filling.setSone(andONLY);
                        allFilledUp=true;
                        gotCone=true;
                        rule2++;
                        theONE=BLANK;
                        andONLY="";
                        break;
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;



           ///////////////////////////////////////
           //rule 3
            while(allFilledUp==false&&gotCone==false){
                for (int i=0;i<orderNumbers-1;i++){
                    if ((seekAnd.getUniAbbrev()==Hurray[i].getPlaque().getUniAbbrev())&& searcher!=Hurray[i]&&
                    (destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())){
                        int seekerGrad=atoi(seekAnd.getGradYear().c_str());
                        int soughtGrad=atoi(Hurray[i].getPlaque().getGradYear().c_str());
                        if(seekerGrad<=soughtGrad+3 && seekerGrad>=soughtGrad-3){
                            string converter="";
                            converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                            theONE.stringToName(converter,theONE);
                            andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                            filling.setCone(theONE);
                            filling.setSone(andONLY);
                            allFilledUp=true;
                            gotCone=true;
                            rule3++;
                            theONE=BLANK;
                            andONLY="";
                            break;
                        }
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;


           ///////////////////////////////////////
           //rule 4
            while(allFilledUp==false&&gotCone==false){
                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&&searcher!=Hurray[i]){
                            if(destroy[searcher.getYearsTaught()-1].getGradeTaught()==Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getGradeTaught() &&
                            (searcher.getYearsTaught()<3 && Hurray[i].getYearsTaught()<3)){
                                string converter="";
                                converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                                theONE.stringToName(converter,theONE);
                                andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                                filling.setCone(theONE);
                                filling.setSone(andONLY);
                                allFilledUp=true;
                                gotCone=true;
                                rule4++;
                                theONE=BLANK;
                                andONLY="";
                                break;
                            }
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;


           ///////////////////////////////////////
           //rule 5
            while(allFilledUp==false&&gotCone==false){
                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&&searcher!=Hurray[i] ){
                            if(destroy[searcher.getYearsTaught()-1].getGradeTaught()==Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getGradeTaught() &&
                            (searcher.getYearsTaught()>19 && Hurray[i].getYearsTaught()>19)){
                                string converter="";
                                converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                                theONE.stringToName(converter,theONE);
                                andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                                filling.setCone(theONE);
                                filling.setSone(andONLY);
                                allFilledUp=true;
                                gotCone=true;
                                rule5++;
                                theONE=BLANK;
                                andONLY="";
                                break;
                            }
                    }
                     if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;



           ///////////////////////////////////////
           //rule6
            while(allFilledUp==false&&gotCone==false){
                int k=0;
                int first=0;
                int second=0;
                int third=0;
                int fourth=0;
                int fifth=0;
                int sixth=0;
                int seventh=0;
                int eighth=0;
                int ninth=0;
                int tenth=0;
                int eleventh=0;
                int twelveth=0;

                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&&searcher!=Hurray[i] ){
                        for(int m=0;m<searcher.getYearsTaught();m++){
                            k=first=second=third=fourth=fifth=sixth=seventh=eighth=ninth=tenth=eleventh=twelveth=0;
                            for (int p=0;p<searcher.getYearsTaught();p++){
                                if (searcher.getBoard(m).getGradeTaught()==Hurray[i].getBoard(p).getGradeTaught()){
                                    if (searcher.getBoard(m).getGradeTaught()=="K"){
                                        k++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="1"){
                                        first++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="2"){
                                        second++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="3"){
                                        third++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="4"){
                                        fourth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="5"){
                                        fifth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="6"){
                                        sixth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="7"){
                                        seventh++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="8"){
                                        eighth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="9"){
                                        ninth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="10"){
                                        tenth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="11"){
                                        eleventh++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="12"){
                                        twelveth++;
                                    }
                                }
                            }
                        }
                        if(k>3 || first>3 || second >3 || third>3 || fourth>3 || fifth>3 || sixth>3 || seventh>3 || eighth>3 || ninth>3 || tenth>3 || eleventh>3 || twelveth>3){
                            string converter="";
                            converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                            theONE.stringToName(converter,theONE);
                            andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                            filling.setCone(theONE);
                            filling.setSone(andONLY);
                            allFilledUp=true;
                            gotCone=true;
                            rule6++;
                            theONE=BLANK;
                            andONLY="";
                            break;
                        }
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;



           ///////////////////////////////////////
           //rule 7
            while(allFilledUp==false&&gotCone==false){
                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&& searcher!=Hurray[i] &&
                    (seekAnd.getUniAbbrev()==Hurray[i].getPlaque().getUniAbbrev())){
                        string converter="";
                        converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                        theONE.stringToName(converter,theONE);
                        andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                        filling.setCone(theONE);
                        filling.setSone(andONLY);
                        allFilledUp=true;
                        gotCone=true;
                        rule7++;
                        theONE=BLANK;
                        andONLY="";
                        break;
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;



           ///////////////////////////////////////
           //rule 8
            while(allFilledUp==false&&gotCone==false){
                int k=0;
                int first=0;
                int second=0;
                int third=0;
                int fourth=0;
                int fifth=0;
                int sixth=0;
                int seventh=0;
                int eighth=0;
                int ninth=0;
                int tenth=0;
                int eleventh=0;
                int twelveth=0;

                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&&searcher!=Hurray[i] ){
                        for(int m=0;m<searcher.getYearsTaught();m++){
                            k=first=second=third=fourth=fifth=sixth=seventh=eighth=ninth=tenth=eleventh=twelveth=0;
                            for (int p=0;p<searcher.getYearsTaught();p++){
                                if (searcher.getBoard(m).getGradeTaught()==Hurray[i].getBoard(p).getGradeTaught()){
                                    if (searcher.getBoard(m).getGradeTaught()=="K"){
                                        k++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="1"){
                                        first++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="2"){
                                        second++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="3"){
                                        third++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="4"){
                                        fourth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="5"){
                                        fifth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="6"){
                                        sixth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="7"){
                                        seventh++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="8"){
                                        eighth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="9"){
                                        ninth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="10"){
                                        tenth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="11"){
                                        eleventh++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="12"){
                                        twelveth++;
                                    }
                                }
                            }
                        }
                        if(k>1 || first>1 || second >1 || third>1 || fourth>1 || fifth>1 || sixth>1 || seventh>1 || eighth>1 || ninth>1 || tenth>1 || eleventh>1 || twelveth>1){
                            string converter="";
                            converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                            theONE.stringToName(converter,theONE);
                            andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                            filling.setCone(theONE);
                            filling.setSone(andONLY);
                            allFilledUp=true;
                            gotCone=true;
                            rule8++;
                            theONE=BLANK;
                            andONLY="";
                            break;
                        }
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;


           ///////////////////////////////////////
           //rule 9
            while(allFilledUp==false&&gotCone==false){
                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&&searcher!=Hurray[i] &&
                    (searcher.getTeacherName().getFirstName()==Hurray[i].getTeacherName().getFirstName())){
                        string converter="";
                        converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                        theONE.stringToName(converter,theONE);
                        andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                        filling.setCone(theONE);
                        filling.setSone(andONLY);
                        allFilledUp=true;
                        gotCone=true;
                        rule9++;
                        theONE=BLANK;
                        andONLY="";
                        break;
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;


           ///////////////////////////////////////
           //rule 10
            while(allFilledUp==false&&gotCone==false){
                int i=0;
                i=genRandomNumber(orderNumbers-1);
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&&searcher!=Hurray[i] ){
                        string converter="";
                        converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                        theONE.stringToName(converter,theONE);
                        andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                        filling.setCone(theONE);
                        filling.setSone(andONLY);
                        allFilledUp=true;
                        gotCone=true;
                        rule10++;
                        theONE=BLANK;
                        andONLY="";
                        break;
                    }
            }
            allFilledUp=false;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//contact two


            /////////////////////////////
            //rule 1
            while(allFilledUp==false){
                for (int i=0;i<orderNumbers-1;i++){
                    if ((seekAnd.getUniAbbrev()==Hurray[i].getPlaque().getUniAbbrev())&& searcher!=Hurray[i]&&
                    (destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&& (filling.getCone()!=Hurray[i].getTeacherName())){
                        int seekerGrad=atoi(seekAnd.getGradYear().c_str());
                        int soughtGrad=atoi(Hurray[i].getPlaque().getGradYear().c_str());
                        if(seekerGrad<=soughtGrad+3 && seekerGrad>=soughtGrad-3){
                            if(destroy[searcher.getYearsTaught()].getGradeTaught()==Hurray[i].getBoard(Hurray[i].getYearsTaught()).getGradeTaught()){
                                string converter="";
                                converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                                theONE.stringToName(converter,theONE);
                                andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                                filling.setCtwo(theONE);
                                filling.setStwo(andONLY);
                                allFilledUp=true;
                                gotCtwo=true;
                                rule1++;
                                theONE=BLANK;
                                andONLY="";
                                break;
                            }
                        }
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;


            ////////////////////////////////////////
            //rule 2
           while(allFilledUp==false&&gotCtwo==false){
                for(int i=0;i<orderNumbers-1;i++){
                    if ((seekAnd.getGradYear()==Hurray[i].getPlaque().getGradYear())&& seekAnd.getUniAbbrev()==Hurray[i].getPlaque().getUniAbbrev() && searcher!=Hurray[i] &&
                    (destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&& (filling.getCone()!=Hurray[i].getTeacherName())){
                        string converter="";
                        converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                        theONE.stringToName(converter,theONE);
                        andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                        filling.setCtwo(theONE);
                        filling.setStwo(andONLY);
                        allFilledUp=true;
                        gotCtwo=true;
                        rule2++;
                        theONE=BLANK;
                        andONLY="";
                        break;
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;



           ///////////////////////////////////////
           //rule 3
            while(allFilledUp==false&&gotCtwo==false){
                for (int i=0;i<orderNumbers-1;i++){
                    if ((seekAnd.getUniAbbrev()==Hurray[i].getPlaque().getUniAbbrev())&& searcher!=Hurray[i]&&
                    (destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&& (filling.getCone()!=Hurray[i].getTeacherName())){
                        int seekerGrad=atoi(seekAnd.getGradYear().c_str());
                        int soughtGrad=atoi(Hurray[i].getPlaque().getGradYear().c_str());
                        if(seekerGrad<=soughtGrad+3 && seekerGrad>=soughtGrad-3){
                            string converter="";
                            converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                            theONE.stringToName(converter,theONE);
                            andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                            filling.setCtwo(theONE);
                            filling.setStwo(andONLY);
                            allFilledUp=true;
                            gotCtwo=true;
                            rule3++;
                            theONE=BLANK;
                            andONLY="";
                            break;
                        }
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;


           ///////////////////////////////////////
           //rule 4
            while(allFilledUp==false&&gotCtwo==false){
                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&& searcher!=Hurray[i]
                    && (filling.getCone()!=Hurray[i].getTeacherName())){
                            if(destroy[searcher.getYearsTaught()-1].getGradeTaught()==Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getGradeTaught() &&
                            (searcher.getYearsTaught()<3 && Hurray[i].getYearsTaught()<3)){
                                string converter="";
                                converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                                theONE.stringToName(converter,theONE);
                                andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                                filling.setCtwo(theONE);
                                filling.setStwo(andONLY);
                                allFilledUp=true;
                                gotCtwo=true;
                                rule4++;
                                theONE=BLANK;
                                andONLY="";
                                break;
                            }
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;


           ///////////////////////////////////////
           //rule 5
            while(allFilledUp==false&&gotCtwo==false){
                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&&searcher!=Hurray[i] && (filling.getCone()!=Hurray[i].getTeacherName())){
                            if(destroy[searcher.getYearsTaught()-1].getGradeTaught()==Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getGradeTaught() &&
                            (searcher.getYearsTaught()>19 && Hurray[i].getYearsTaught()>19)){
                                string converter="";
                                converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                                theONE.stringToName(converter,theONE);
                                andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                                filling.setCtwo(theONE);
                                filling.setStwo(andONLY);
                                allFilledUp=true;
                                gotCtwo=true;
                                rule5++;
                                theONE=BLANK;
                                andONLY="";
                                break;
                            }
                    }
                     if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;



           ///////////////////////////////////////
           //rule6
            while(allFilledUp==false&&gotCtwo==false){
                int k=0;
                int first=0;
                int second=0;
                int third=0;
                int fourth=0;
                int fifth=0;
                int sixth=0;
                int seventh=0;
                int eighth=0;
                int ninth=0;
                int tenth=0;
                int eleventh=0;
                int twelveth=0;

                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&&searcher!=Hurray[i]
                    && (filling.getCone()!=Hurray[i].getTeacherName()) ){
                        for(int m=0;m<searcher.getYearsTaught();m++){
                        k=first=second=third=fourth=fifth=sixth=seventh=eighth=ninth=tenth=eleventh=twelveth=0;
                            for (int p=0;p<searcher.getYearsTaught();p++){
                                if (searcher.getBoard(m).getGradeTaught()==Hurray[i].getBoard(p).getGradeTaught()){
                                    if (searcher.getBoard(m).getGradeTaught()=="K"){
                                        k++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="1"){
                                        first++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="2"){
                                        second++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="3"){
                                        third++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="4"){
                                        fourth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="5"){
                                        fifth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="6"){
                                        sixth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="7"){
                                        seventh++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="8"){
                                        eighth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="9"){
                                        ninth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="10"){
                                        tenth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="11"){
                                        eleventh++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="12"){
                                        twelveth++;
                                    }
                                }
                            }
                        }
                        if(k>3 || first>3 || second >3 || third>3 || fourth>3 || fifth>3 || sixth>3 || seventh>3 || eighth>3 || ninth>3 || tenth>3 || eleventh>3 || twelveth>3){
                            string converter="";
                            converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                            theONE.stringToName(converter,theONE);
                            andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                            filling.setCtwo(theONE);
                            filling.setStwo(andONLY);
                            allFilledUp=true;
                            gotCtwo=true;
                            rule6++;
                            theONE=BLANK;
                            andONLY="";
                            break;
                        }
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;



           ///////////////////////////////////////
           //rule 7
            while(allFilledUp==false&&gotCtwo==false){
                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&& searcher!=Hurray[i] &&
                    (seekAnd.getUniAbbrev()==Hurray[i].getPlaque().getUniAbbrev())&& (filling.getCone()!=Hurray[i].getTeacherName())){
                        string converter="";
                        converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                        theONE.stringToName(converter,theONE);
                        andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                        filling.setCtwo(theONE);
                        filling.setStwo(andONLY);
                        allFilledUp=true;
                        gotCtwo=true;
                        rule7++;
                        theONE=BLANK;
                        andONLY="";
                        break;
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;



           ///////////////////////////////////////
           //rule 8
            while(allFilledUp==false&&gotCtwo==false){
                int k=0;
                int first=0;
                int second=0;
                int third=0;
                int fourth=0;
                int fifth=0;
                int sixth=0;
                int seventh=0;
                int eighth=0;
                int ninth=0;
                int tenth=0;
                int eleventh=0;
                int twelveth=0;

                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&&searcher!=Hurray[i]
                        && (filling.getCone()!=Hurray[i].getTeacherName())){
                        for(int m=0;m<searcher.getYearsTaught();m++){
                            k=first=second=third=fourth=fifth=sixth=seventh=eighth=ninth=tenth=eleventh=twelveth=0;
                            for (int p=0;p<searcher.getYearsTaught();p++){
                                if (searcher.getBoard(m).getGradeTaught()==Hurray[i].getBoard(p).getGradeTaught()){
                                    if (searcher.getBoard(m).getGradeTaught()=="K"){
                                        k++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="1"){
                                        first++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="2"){
                                        second++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="3"){
                                        third++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="4"){
                                        fourth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="5"){
                                        fifth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="6"){
                                        sixth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="7"){
                                        seventh++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="8"){
                                        eighth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="9"){
                                        ninth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="10"){
                                        tenth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="11"){
                                        eleventh++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="12"){
                                        twelveth++;
                                    }
                                }
                            }
                        }
                        if(k>1 || first>1 || second >1 || third>1 || fourth>1 || fifth>1 || sixth>1 || seventh>1 || eighth>1 || ninth>1 || tenth>1 || eleventh>1 || twelveth>1){
                            string converter="";
                            converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                            theONE.stringToName(converter,theONE);
                            andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                            filling.setCtwo(theONE);
                            filling.setStwo(andONLY);
                            allFilledUp=true;
                            gotCtwo=true;
                            rule8++;
                            theONE=BLANK;
                            andONLY="";
                            break;
                        }
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;


           ///////////////////////////////////////
           //rule 9
            while(allFilledUp==false&&gotCtwo==false){
                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&&searcher!=Hurray[i] &&
                    (searcher.getTeacherName().getFirstName()==Hurray[i].getTeacherName().getFirstName())&& (filling.getCone()!=Hurray[i].getTeacherName())){
                        string converter="";
                        converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                        theONE.stringToName(converter,theONE);
                        andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                        filling.setCtwo(theONE);
                        filling.setStwo(andONLY);
                        allFilledUp=true;
                        gotCtwo=true;
                        rule9++;
                        theONE=BLANK;
                        andONLY="";
                        break;
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;


           ///////////////////////////////////////
           //rule 10
            while(allFilledUp==false&&gotCtwo==false){
                int i=0;
                i=genRandomNumber(orderNumbers-1);
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&&searcher!=Hurray[i]
                    && (filling.getCone()!=Hurray[i].getTeacherName())){
                        string converter="";
                        converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                        theONE.stringToName(converter,theONE);
                        andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                        filling.setCtwo(theONE);
                        filling.setStwo(andONLY);
                        allFilledUp=true;
                        gotCtwo=true;
                        rule10++;
                        theONE=BLANK;
                        andONLY="";
                        break;
                    }
            }
            allFilledUp=false;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//contact three

            /////////////////////////////
            //rule 1
            while(allFilledUp==false){
                for (int i=0;i<orderNumbers-1;i++){
                    if ((seekAnd.getUniAbbrev()==Hurray[i].getPlaque().getUniAbbrev())&& searcher!=Hurray[i]&& (filling.getCtwo()!=Hurray[i].getTeacherName())&&
                    (destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&& (filling.getCone()!=Hurray[i].getTeacherName())){
                        int seekerGrad=atoi(seekAnd.getGradYear().c_str());
                        int soughtGrad=atoi(Hurray[i].getPlaque().getGradYear().c_str());
                        if(seekerGrad<=soughtGrad+3 && seekerGrad>=soughtGrad-3){
                            if(destroy[searcher.getYearsTaught()].getGradeTaught()==Hurray[i].getBoard(Hurray[i].getYearsTaught()).getGradeTaught()){
                                string converter="";
                                converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                                theONE.stringToName(converter,theONE);
                                andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                                filling.setCthree(theONE);
                                filling.setSthree(andONLY);
                                allFilledUp=true;
                                gotCthree=true;
                                rule1++;
                                theONE=BLANK;
                                andONLY="";
                                break;
                            }
                        }
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;


            ////////////////////////////////////////
            //rule 2
           while(allFilledUp==false&&gotCthree==false){
                for(int i=0;i<orderNumbers-1;i++){
                    if ((seekAnd.getGradYear()==Hurray[i].getPlaque().getGradYear())&& seekAnd.getUniAbbrev()==Hurray[i].getPlaque().getUniAbbrev() && searcher!=Hurray[i] &&
                    (destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&& (filling.getCone()!=Hurray[i].getTeacherName())
                    && (filling.getCtwo()!=Hurray[i].getTeacherName())){
                        string converter="";
                        converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                        theONE.stringToName(converter,theONE);
                        andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                        filling.setCthree(theONE);
                        filling.setSthree(andONLY);
                        allFilledUp=true;
                        gotCthree=true;
                        rule2++;
                        theONE=BLANK;
                        andONLY="";
                        break;
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;



           ///////////////////////////////////////
           //rule 3
            while(allFilledUp==false&&gotCthree==false){
                for (int i=0;i<orderNumbers-1;i++){
                    if ((seekAnd.getUniAbbrev()==Hurray[i].getPlaque().getUniAbbrev())&& searcher!=Hurray[i]&& (filling.getCtwo()!=Hurray[i].getTeacherName())&&
                    (destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&& (filling.getCone()!=Hurray[i].getTeacherName())){
                        int seekerGrad=atoi(seekAnd.getGradYear().c_str());
                        int soughtGrad=atoi(Hurray[i].getPlaque().getGradYear().c_str());
                        if(seekerGrad<=soughtGrad+3 && seekerGrad>=soughtGrad-3){
                            string converter="";
                            converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                            theONE.stringToName(converter,theONE);
                            andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                            filling.setCthree(theONE);
                            filling.setSthree(andONLY);
                            allFilledUp=true;
                            gotCthree=true;
                            rule3++;
                            theONE=BLANK;
                            andONLY="";
                            break;
                        }
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;


           ///////////////////////////////////////
           //rule 4
            while(allFilledUp==false&&gotCthree==false){
                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&& searcher!=Hurray[i]
                    && (filling.getCone()!=Hurray[i].getTeacherName())&& (filling.getCtwo()!=Hurray[i].getTeacherName())){
                            if(destroy[searcher.getYearsTaught()-1].getGradeTaught()==Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getGradeTaught() &&
                            (searcher.getYearsTaught()<3 && Hurray[i].getYearsTaught()<3)){
                                string converter="";
                                converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                                theONE.stringToName(converter,theONE);
                                andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                                filling.setCthree(theONE);
                                filling.setSthree(andONLY);
                                allFilledUp=true;
                                gotCthree=true;
                                rule4++;
                                theONE=BLANK;
                                andONLY="";
                                break;
                            }
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;


           ///////////////////////////////////////
           //rule 5
            while(allFilledUp==false&&gotCthree==false){
                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&&searcher!=Hurray[i]
                    && (filling.getCone()!=Hurray[i].getTeacherName())&& (filling.getCtwo()!=Hurray[i].getTeacherName())){
                            if(destroy[searcher.getYearsTaught()-1].getGradeTaught()==Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getGradeTaught() &&
                            (searcher.getYearsTaught()>19 && Hurray[i].getYearsTaught()>19)){
                                string converter="";
                                converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                                theONE.stringToName(converter,theONE);
                                andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                                filling.setCthree(theONE);
                                filling.setSthree(andONLY);
                                allFilledUp=true;
                                gotCthree=true;
                                rule5++;
                                theONE=BLANK;
                                andONLY="";
                                break;
                            }
                    }
                     if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;



           ///////////////////////////////////////
           //rule6
            while(allFilledUp==false&&gotCthree==false){
                int k=0;
                int first=0;
                int second=0;
                int third=0;
                int fourth=0;
                int fifth=0;
                int sixth=0;
                int seventh=0;
                int eighth=0;
                int ninth=0;
                int tenth=0;
                int eleventh=0;
                int twelveth=0;

                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&&searcher!=Hurray[i]
                    && (filling.getCone()!=Hurray[i].getTeacherName()) && (filling.getCtwo()!=Hurray[i].getTeacherName())){
                        for(int m=0;m<searcher.getYearsTaught();m++){
                        k=first=second=third=fourth=fifth=sixth=seventh=eighth=ninth=tenth=eleventh=twelveth=0;
                            for (int p=0;p<searcher.getYearsTaught();p++){
                                if (searcher.getBoard(m).getGradeTaught()==Hurray[i].getBoard(p).getGradeTaught()){
                                    if (searcher.getBoard(m).getGradeTaught()=="K"){
                                        k++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="1"){
                                        first++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="2"){
                                        second++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="3"){
                                        third++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="4"){
                                        fourth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="5"){
                                        fifth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="6"){
                                        sixth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="7"){
                                        seventh++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="8"){
                                        eighth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="9"){
                                        ninth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="10"){
                                        tenth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="11"){
                                        eleventh++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="12"){
                                        twelveth++;
                                    }
                                }
                            }
                        }
                        if(k>3 || first>3 || second >3 || third>3 || fourth>3 || fifth>3 || sixth>3 || seventh>3 || eighth>3 || ninth>3 || tenth>3 || eleventh>3 || twelveth>3){
                            string converter="";
                            converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                            theONE.stringToName(converter,theONE);
                            andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                            filling.setCthree(theONE);
                            filling.setSthree(andONLY);
                            allFilledUp=true;
                            gotCthree=true;
                            rule6++;
                            theONE=BLANK;
                            andONLY="";
                            break;
                        }
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;



           ///////////////////////////////////////
           //rule 7
            while(allFilledUp==false&&gotCthree==false){
                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&& searcher!=Hurray[i] &&
                    (seekAnd.getUniAbbrev()==Hurray[i].getPlaque().getUniAbbrev())&& (filling.getCone()!=Hurray[i].getTeacherName())&& (filling.getCtwo()!=Hurray[i].getTeacherName())){
                        string converter="";
                        converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                        theONE.stringToName(converter,theONE);
                        andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                        filling.setCthree(theONE);
                        filling.setSthree(andONLY);
                        allFilledUp=true;
                        gotCthree=true;
                        rule7++;
                        theONE=BLANK;
                        andONLY="";
                        break;
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;



           ///////////////////////////////////////
           //rule 8
            while(allFilledUp==false&&gotCthree==false){
                int k=0;
                int first=0;
                int second=0;
                int third=0;
                int fourth=0;
                int fifth=0;
                int sixth=0;
                int seventh=0;
                int eighth=0;
                int ninth=0;
                int tenth=0;
                int eleventh=0;
                int twelveth=0;

                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&&searcher!=Hurray[i]
                        && (filling.getCone()!=Hurray[i].getTeacherName())&& (filling.getCtwo()!=Hurray[i].getTeacherName())){
                        for(int m=0;m<searcher.getYearsTaught();m++){
                            k=first=second=third=fourth=fifth=sixth=seventh=eighth=ninth=tenth=eleventh=twelveth=0;
                            for (int p=0;p<searcher.getYearsTaught();p++){
                                if (searcher.getBoard(m).getGradeTaught()==Hurray[i].getBoard(p).getGradeTaught()){
                                    if (searcher.getBoard(m).getGradeTaught()=="K"){
                                        k++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="1"){
                                        first++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="2"){
                                        second++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="3"){
                                        third++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="4"){
                                        fourth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="5"){
                                        fifth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="6"){
                                        sixth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="7"){
                                        seventh++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="8"){
                                        eighth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="9"){
                                        ninth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="10"){
                                        tenth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="11"){
                                        eleventh++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="12"){
                                        twelveth++;
                                    }
                                }
                            }
                        }
                        if(k>1 || first>1 || second >1 || third>1 || fourth>1 || fifth>1 || sixth>1 || seventh>1 || eighth>1 || ninth>1 || tenth>1 || eleventh>1 || twelveth>1){
                            string converter="";
                            converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                            theONE.stringToName(converter,theONE);
                            andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                            filling.setCthree(theONE);
                            filling.setSthree(andONLY);
                            allFilledUp=true;
                            gotCthree=true;
                            rule8++;
                            theONE=BLANK;
                            andONLY="";
                            break;
                        }
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;


           ///////////////////////////////////////
           //rule 9
            while(allFilledUp==false&&gotCthree==false){
                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&&searcher!=Hurray[i] &&
                    (searcher.getTeacherName().getFirstName()==Hurray[i].getTeacherName().getFirstName())&& (filling.getCone()!=Hurray[i].getTeacherName())
                    && (filling.getCtwo()!=Hurray[i].getTeacherName())){
                        string converter="";
                        converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                        theONE.stringToName(converter,theONE);
                        andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                        filling.setCthree(theONE);
                        filling.setSthree(andONLY);
                        allFilledUp=true;
                        gotCthree=true;
                        rule9++;
                        theONE=BLANK;
                        andONLY="";
                        break;
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;


           ///////////////////////////////////////
           //rule 10
            while(allFilledUp==false&&gotCthree==false){
                int i=0;
                i=genRandomNumber(orderNumbers-1);
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&&searcher!=Hurray[i]
                    && (filling.getCone()!=Hurray[i].getTeacherName())&& (filling.getCtwo()!=Hurray[i].getTeacherName())){
                        string converter="";
                        converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                        theONE.stringToName(converter,theONE);
                        andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                        filling.setCthree(theONE);
                        filling.setSthree(andONLY);
                        allFilledUp=true;
                        gotCthree=true;
                        rule10++;
                        theONE=BLANK;
                        andONLY="";
                        break;
                    }
            }
            allFilledUp=false;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//contact four


            /////////////////////////////
            //rule 1
            while(allFilledUp==false){
                for (int i=0;i<orderNumbers-1;i++){
                    if ((seekAnd.getUniAbbrev()==Hurray[i].getPlaque().getUniAbbrev())&& searcher!=Hurray[i]&& (filling.getCtwo()!=Hurray[i].getTeacherName())&&
                    (destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&& (filling.getCone()!=Hurray[i].getTeacherName())
                    && (filling.getCthree()!=Hurray[i].getTeacherName())){
                        int seekerGrad=atoi(seekAnd.getGradYear().c_str());
                        int soughtGrad=atoi(Hurray[i].getPlaque().getGradYear().c_str());
                        if(seekerGrad<=soughtGrad+3 && seekerGrad>=soughtGrad-3){
                            if(destroy[searcher.getYearsTaught()].getGradeTaught()==Hurray[i].getBoard(Hurray[i].getYearsTaught()).getGradeTaught()){
                                string converter="";
                                converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                                theONE.stringToName(converter,theONE);
                                andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                                filling.setCfour(theONE);
                                filling.setSfour(andONLY);
                                allFilledUp=true;
                                gotCfour=true;
                                rule1++;
                                theONE=BLANK;
                                andONLY="";
                                break;
                            }
                        }
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;


            ////////////////////////////////////////
            //rule 2
           while(allFilledUp==false&&gotCfour==false){
                for(int i=0;i<orderNumbers-1;i++){
                    if ((seekAnd.getGradYear()==Hurray[i].getPlaque().getGradYear())&& seekAnd.getUniAbbrev()==Hurray[i].getPlaque().getUniAbbrev() && searcher!=Hurray[i] &&
                    (destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&& (filling.getCone()!=Hurray[i].getTeacherName())
                    && (filling.getCtwo()!=Hurray[i].getTeacherName())&& (filling.getCthree()!=Hurray[i].getTeacherName())){
                        string converter="";
                        converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                        theONE.stringToName(converter,theONE);
                        andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                        filling.setCfour(theONE);
                        filling.setSfour(andONLY);
                        allFilledUp=true;
                        gotCfour=true;
                        rule2++;
                        theONE=BLANK;
                        andONLY="";
                        break;
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;



           ///////////////////////////////////////
           //rule 3
            while(allFilledUp==false&&gotCfour==false){
                for (int i=0;i<orderNumbers-1;i++){
                    if ((seekAnd.getUniAbbrev()==Hurray[i].getPlaque().getUniAbbrev())&& searcher!=Hurray[i]&& (filling.getCtwo()!=Hurray[i].getTeacherName())&&
                    (destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&& (filling.getCone()!=Hurray[i].getTeacherName())
                    && (filling.getCthree()!=Hurray[i].getTeacherName())){
                        int seekerGrad=atoi(seekAnd.getGradYear().c_str());
                        int soughtGrad=atoi(Hurray[i].getPlaque().getGradYear().c_str());
                        if(seekerGrad<=soughtGrad+3 && seekerGrad>=soughtGrad-3){
                            string converter="";
                            converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                            theONE.stringToName(converter,theONE);
                            andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                            filling.setCfour(theONE);
                            filling.setSfour(andONLY);
                            allFilledUp=true;
                            gotCfour=true;
                            rule3++;
                            theONE=BLANK;
                            andONLY="";
                            break;
                        }
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;


           ///////////////////////////////////////
           //rule 4
            while(allFilledUp==false&&gotCfour==false){
                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&& searcher!=Hurray[i]
                    && (filling.getCone()!=Hurray[i].getTeacherName())&& (filling.getCtwo()!=Hurray[i].getTeacherName())&& (filling.getCthree()!=Hurray[i].getTeacherName())){
                            if(destroy[searcher.getYearsTaught()-1].getGradeTaught()==Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getGradeTaught() &&
                            (searcher.getYearsTaught()<3 && Hurray[i].getYearsTaught()<3)){
                                string converter="";
                                converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                                theONE.stringToName(converter,theONE);
                                andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                                filling.setCfour(theONE);
                                filling.setSfour(andONLY);
                                allFilledUp=true;
                                gotCfour=true;
                                rule4++;
                                theONE=BLANK;
                                andONLY="";
                                break;
                            }
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;


           ///////////////////////////////////////
           //rule 5
            while(allFilledUp==false&&gotCfour==false){
                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&&searcher!=Hurray[i]
                    && (filling.getCone()!=Hurray[i].getTeacherName())&& (filling.getCtwo()!=Hurray[i].getTeacherName())&& (filling.getCthree()!=Hurray[i].getTeacherName())){
                            if(destroy[searcher.getYearsTaught()-1].getGradeTaught()==Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getGradeTaught() &&
                            (searcher.getYearsTaught()>19 && Hurray[i].getYearsTaught()>19)){
                                string converter="";
                                converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                                theONE.stringToName(converter,theONE);
                                andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                                filling.setCfour(theONE);
                                filling.setSfour(andONLY);
                                allFilledUp=true;
                                gotCfour=true;
                                rule5++;
                                theONE=BLANK;
                                andONLY="";
                                break;
                            }
                    }
                     if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;



           ///////////////////////////////////////
           //rule6
            while(allFilledUp==false&&gotCfour==false){
                int k=0;
                int first=0;
                int second=0;
                int third=0;
                int fourth=0;
                int fifth=0;
                int sixth=0;
                int seventh=0;
                int eighth=0;
                int ninth=0;
                int tenth=0;
                int eleventh=0;
                int twelveth=0;

                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&&searcher!=Hurray[i]
                    && (filling.getCone()!=Hurray[i].getTeacherName()) && (filling.getCtwo()!=Hurray[i].getTeacherName())&& (filling.getCthree()!=Hurray[i].getTeacherName())){
                        for(int m=0;m<searcher.getYearsTaught();m++){
                        k=first=second=third=fourth=fifth=sixth=seventh=eighth=ninth=tenth=eleventh=twelveth=0;
                            for (int p=0;p<searcher.getYearsTaught();p++){
                                if (searcher.getBoard(m).getGradeTaught()==Hurray[i].getBoard(p).getGradeTaught()){
                                    if (searcher.getBoard(m).getGradeTaught()=="K"){
                                        k++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="1"){
                                        first++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="2"){
                                        second++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="3"){
                                        third++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="4"){
                                        fourth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="5"){
                                        fifth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="6"){
                                        sixth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="7"){
                                        seventh++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="8"){
                                        eighth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="9"){
                                        ninth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="10"){
                                        tenth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="11"){
                                        eleventh++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="12"){
                                        twelveth++;
                                    }
                                }
                            }
                        }
                        if(k>3 || first>3 || second >3 || third>3 || fourth>3 || fifth>3 || sixth>3 || seventh>3 || eighth>3 || ninth>3 || tenth>3 || eleventh>3 || twelveth>3){
                            string converter="";
                            converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                            theONE.stringToName(converter,theONE);
                            andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                            filling.setCfour(theONE);
                            filling.setSfour(andONLY);
                            allFilledUp=true;
                            gotCfour=true;
                            rule6++;
                            theONE=BLANK;
                            andONLY="";
                            break;
                        }
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;



           ///////////////////////////////////////
           //rule 7
            while(allFilledUp==false&&gotCfour==false){
                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&& searcher!=Hurray[i] &&
                    (seekAnd.getUniAbbrev()==Hurray[i].getPlaque().getUniAbbrev())&& (filling.getCone()!=Hurray[i].getTeacherName())&& (filling.getCtwo()!=Hurray[i].getTeacherName())
                    && (filling.getCthree()!=Hurray[i].getTeacherName())){
                        string converter="";
                        converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                        theONE.stringToName(converter,theONE);
                        andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                        filling.setCfour(theONE);
                        filling.setSfour(andONLY);
                        allFilledUp=true;
                        gotCfour=true;
                        rule7++;
                        theONE=BLANK;
                        andONLY="";
                        break;
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;



           ///////////////////////////////////////
           //rule 8
            while(allFilledUp==false&&gotCfour==false){
                int k=0;
                int first=0;
                int second=0;
                int third=0;
                int fourth=0;
                int fifth=0;
                int sixth=0;
                int seventh=0;
                int eighth=0;
                int ninth=0;
                int tenth=0;
                int eleventh=0;
                int twelveth=0;

                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&&searcher!=Hurray[i]
                        && (filling.getCone()!=Hurray[i].getTeacherName())&& (filling.getCtwo()!=Hurray[i].getTeacherName())&& (filling.getCthree()!=Hurray[i].getTeacherName())){
                        for(int m=0;m<searcher.getYearsTaught();m++){
                            k=first=second=third=fourth=fifth=sixth=seventh=eighth=ninth=tenth=eleventh=twelveth=0;
                            for (int p=0;p<searcher.getYearsTaught();p++){
                                if (searcher.getBoard(m).getGradeTaught()==Hurray[i].getBoard(p).getGradeTaught()){
                                    if (searcher.getBoard(m).getGradeTaught()=="K"){
                                        k++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="1"){
                                        first++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="2"){
                                        second++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="3"){
                                        third++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="4"){
                                        fourth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="5"){
                                        fifth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="6"){
                                        sixth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="7"){
                                        seventh++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="8"){
                                        eighth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="9"){
                                        ninth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="10"){
                                        tenth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="11"){
                                        eleventh++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="12"){
                                        twelveth++;
                                    }
                                }
                            }
                        }
                        if(k>1 || first>1 || second >1 || third>1 || fourth>1 || fifth>1 || sixth>1 || seventh>1 || eighth>1 || ninth>1 || tenth>1 || eleventh>1 || twelveth>1){
                            string converter="";
                            converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                            theONE.stringToName(converter,theONE);
                            andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                            filling.setCfour(theONE);
                            filling.setSfour(andONLY);
                            allFilledUp=true;
                            gotCfour=true;
                            rule8++;
                            theONE=BLANK;
                            andONLY="";
                            break;
                        }
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;


           ///////////////////////////////////////
           //rule 9
            while(allFilledUp==false&&gotCfour==false){
                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&&searcher!=Hurray[i] &&
                    (searcher.getTeacherName().getFirstName()==Hurray[i].getTeacherName().getFirstName())&& (filling.getCone()!=Hurray[i].getTeacherName())
                    && (filling.getCtwo()!=Hurray[i].getTeacherName())&& (filling.getCthree()!=Hurray[i].getTeacherName())){
                        string converter="";
                        converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                        theONE.stringToName(converter,theONE);
                        andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                        filling.setCfour(theONE);
                        filling.setSfour(andONLY);
                        allFilledUp=true;
                        gotCfour=true;
                        rule9++;
                        theONE=BLANK;
                        andONLY="";
                        break;
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;


           ///////////////////////////////////////
           //rule 10
            while(allFilledUp==false&&gotCfour==false){
                int i=0;
                i=genRandomNumber(orderNumbers-1);
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&&searcher!=Hurray[i]
                    && (filling.getCone()!=Hurray[i].getTeacherName())&& (filling.getCtwo()!=Hurray[i].getTeacherName())&& (filling.getCthree()!=Hurray[i].getTeacherName())){
                        string converter="";
                        converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                        theONE.stringToName(converter,theONE);
                        andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                        filling.setCfour(theONE);
                        filling.setSfour(andONLY);
                        allFilledUp=true;
                        gotCfour=true;
                        rule10++;
                        theONE=BLANK;
                        andONLY="";
                        break;
                    }
            }
            allFilledUp=false;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//contact five


            /////////////////////////////
            //rule 1
            while(allFilledUp==false){
                for (int i=0;i<orderNumbers-1;i++){
                    if ((seekAnd.getUniAbbrev()==Hurray[i].getPlaque().getUniAbbrev())&& searcher!=Hurray[i]&& (filling.getCtwo()!=Hurray[i].getTeacherName())&&
                    (destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&& (filling.getCone()!=Hurray[i].getTeacherName())
                    && (filling.getCthree()!=Hurray[i].getTeacherName())&& (filling.getCfour()!=Hurray[i].getTeacherName())){
                        int seekerGrad=atoi(seekAnd.getGradYear().c_str());
                        int soughtGrad=atoi(Hurray[i].getPlaque().getGradYear().c_str());
                        if(seekerGrad<=soughtGrad+3 && seekerGrad>=soughtGrad-3){
                            if(destroy[searcher.getYearsTaught()].getGradeTaught()==Hurray[i].getBoard(Hurray[i].getYearsTaught()).getGradeTaught()){
                                string converter="";
                                converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                                theONE.stringToName(converter,theONE);
                                andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                                filling.setCfive(theONE);
                                filling.setSfive(andONLY);
                                allFilledUp=true;
                                gotCfive=true;
                                rule1++;
                                theONE=BLANK;
                                andONLY="";
                                break;
                            }
                        }
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;


            ////////////////////////////////////////
            //rule 2
           while(allFilledUp==false&&gotCfive==false){
                for(int i=0;i<orderNumbers-1;i++){
                    if ((seekAnd.getGradYear()==Hurray[i].getPlaque().getGradYear())&& seekAnd.getUniAbbrev()==Hurray[i].getPlaque().getUniAbbrev() && searcher!=Hurray[i] &&
                    (destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&& (filling.getCone()!=Hurray[i].getTeacherName())
                    && (filling.getCtwo()!=Hurray[i].getTeacherName())&& (filling.getCthree()!=Hurray[i].getTeacherName())&& (filling.getCfour()!=Hurray[i].getTeacherName())){
                        string converter="";
                        converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                        theONE.stringToName(converter,theONE);
                        andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                        filling.setCfive(theONE);
                        filling.setSfive(andONLY);
                        allFilledUp=true;
                        gotCfive=true;
                        rule2++;
                        theONE=BLANK;
                        andONLY="";
                        break;
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;



           ///////////////////////////////////////
           //rule 3
            while(allFilledUp==false&&gotCfive==false){
                for (int i=0;i<orderNumbers-1;i++){
                    if ((seekAnd.getUniAbbrev()==Hurray[i].getPlaque().getUniAbbrev())&& searcher!=Hurray[i]&& (filling.getCtwo()!=Hurray[i].getTeacherName())&&
                    (destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&& (filling.getCone()!=Hurray[i].getTeacherName())
                    && (filling.getCthree()!=Hurray[i].getTeacherName())&& (filling.getCfour()!=Hurray[i].getTeacherName())){
                        int seekerGrad=atoi(seekAnd.getGradYear().c_str());
                        int soughtGrad=atoi(Hurray[i].getPlaque().getGradYear().c_str());
                        if(seekerGrad<=soughtGrad+3 && seekerGrad>=soughtGrad-3){
                            string converter="";
                            converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                            theONE.stringToName(converter,theONE);
                            andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                            filling.setCfive(theONE);
                            filling.setSfive(andONLY);
                            allFilledUp=true;
                            gotCfive=true;
                            rule3++;
                            theONE=BLANK;
                            andONLY="";
                            break;
                        }
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;


           ///////////////////////////////////////
           //rule 4
            while(allFilledUp==false&&gotCfive==false){
                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&& searcher!=Hurray[i]
                    && (filling.getCone()!=Hurray[i].getTeacherName())&& (filling.getCtwo()!=Hurray[i].getTeacherName())&& (filling.getCthree()!=Hurray[i].getTeacherName())
                    && (filling.getCfour()!=Hurray[i].getTeacherName())){
                            if(destroy[searcher.getYearsTaught()-1].getGradeTaught()==Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getGradeTaught() &&
                            (searcher.getYearsTaught()<3 && Hurray[i].getYearsTaught()<3)){
                                string converter="";
                                converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                                theONE.stringToName(converter,theONE);
                                andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                                filling.setCfive(theONE);
                                filling.setSfive(andONLY);
                                allFilledUp=true;
                                gotCfive=true;
                                rule4++;
                                theONE=BLANK;
                                andONLY="";
                                break;
                            }
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;


           ///////////////////////////////////////
           //rule 5
            while(allFilledUp==false&&gotCfive==false){
                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&&searcher!=Hurray[i]
                    && (filling.getCone()!=Hurray[i].getTeacherName())&& (filling.getCtwo()!=Hurray[i].getTeacherName())&& (filling.getCthree()!=Hurray[i].getTeacherName())
                    && (filling.getCfour()!=Hurray[i].getTeacherName())){
                            if(destroy[searcher.getYearsTaught()-1].getGradeTaught()==Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getGradeTaught() &&
                            (searcher.getYearsTaught()>19 && Hurray[i].getYearsTaught()>19)){
                                string converter="";
                                converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                                theONE.stringToName(converter,theONE);
                                andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                                filling.setCfive(theONE);
                                filling.setSfive(andONLY);
                                allFilledUp=true;
                                gotCfive=true;
                                rule5++;
                                theONE=BLANK;
                                andONLY="";
                                break;
                            }

                    }
                     if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;



           ///////////////////////////////////////
           //rule6
            while(allFilledUp==false&&gotCfive==false){
                int k=0;
                int first=0;
                int second=0;
                int third=0;
                int fourth=0;
                int fifth=0;
                int sixth=0;
                int seventh=0;
                int eighth=0;
                int ninth=0;
                int tenth=0;
                int eleventh=0;
                int twelveth=0;

                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&&searcher!=Hurray[i]
                    && (filling.getCone()!=Hurray[i].getTeacherName()) && (filling.getCtwo()!=Hurray[i].getTeacherName())&& (filling.getCthree()!=Hurray[i].getTeacherName())
                    && (filling.getCfour()!=Hurray[i].getTeacherName())){
                        for(int m=0;m<searcher.getYearsTaught();m++){
                            k=first=second=third=fourth=fifth=sixth=seventh=eighth=ninth=tenth=eleventh=twelveth=0;
                            for (int p=0;p<searcher.getYearsTaught();p++){
                                if (searcher.getBoard(m).getGradeTaught()==Hurray[i].getBoard(p).getGradeTaught()){
                                    if (searcher.getBoard(m).getGradeTaught()=="K"){
                                        k++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="1"){
                                        first++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="2"){
                                        second++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="3"){
                                        third++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="4"){
                                        fourth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="5"){
                                        fifth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="6"){
                                        sixth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="7"){
                                        seventh++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="8"){
                                        eighth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="9"){
                                        ninth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="10"){
                                        tenth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="11"){
                                        eleventh++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="12"){
                                        twelveth++;
                                    }
                                }
                            }
                        }
                        if(k>3 || first>3 || second >3 || third>3 || fourth>3 || fifth>3 || sixth>3 || seventh>3 || eighth>3 || ninth>3 || tenth>3 || eleventh>3 || twelveth>3){
                            string converter="";
                            converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                            theONE.stringToName(converter,theONE);
                            andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                            filling.setCfive(theONE);
                            filling.setSfive(andONLY);
                            allFilledUp=true;
                            gotCfive=true;
                            rule6++;
                            theONE=BLANK;
                            andONLY="";
                            break;
                        }
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;



           ///////////////////////////////////////
           //rule 7
            while(allFilledUp==false&&gotCfive==false){
                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&& searcher!=Hurray[i] &&
                    (seekAnd.getUniAbbrev()==Hurray[i].getPlaque().getUniAbbrev())&& (filling.getCone()!=Hurray[i].getTeacherName())&& (filling.getCtwo()!=Hurray[i].getTeacherName())
                    && (filling.getCthree()!=Hurray[i].getTeacherName())&& (filling.getCfour()!=Hurray[i].getTeacherName())){
                        string converter="";
                        converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                        theONE.stringToName(converter,theONE);
                        andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                        filling.setCfive(theONE);
                        filling.setSfive(andONLY);
                        allFilledUp=true;
                        gotCfive=true;
                        rule7++;
                        theONE=BLANK;
                        andONLY="";
                        break;
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;



           ///////////////////////////////////////
           //rule 8
            while(allFilledUp==false&&gotCfive==false){
                int k=0;
                int first=0;
                int second=0;
                int third=0;
                int fourth=0;
                int fifth=0;
                int sixth=0;
                int seventh=0;
                int eighth=0;
                int ninth=0;
                int tenth=0;
                int eleventh=0;
                int twelveth=0;

                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&&searcher!=Hurray[i]
                    && (filling.getCone()!=Hurray[i].getTeacherName())&& (filling.getCtwo()!=Hurray[i].getTeacherName())&& (filling.getCthree()!=Hurray[i].getTeacherName())
                    && (filling.getCfour()!=Hurray[i].getTeacherName())){
                        for(int m=0;m<searcher.getYearsTaught();m++){
                            k=first=second=third=fourth=fifth=sixth=seventh=eighth=ninth=tenth=eleventh=twelveth=0;
                            for (int p=0;p<searcher.getYearsTaught();p++){
                                if (searcher.getBoard(m).getGradeTaught()==Hurray[i].getBoard(p).getGradeTaught()){
                                    if (searcher.getBoard(m).getGradeTaught()=="K"){
                                        k++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="1"){
                                        first++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="2"){
                                        second++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="3"){
                                        third++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="4"){
                                        fourth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="5"){
                                        fifth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="6"){
                                        sixth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="7"){
                                        seventh++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="8"){
                                        eighth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="9"){
                                        ninth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="10"){
                                        tenth++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="11"){
                                        eleventh++;
                                    }
                                    if (searcher.getBoard(m).getGradeTaught()=="12"){
                                        twelveth++;
                                    }
                                }
                            }
                        }
                        if(k>1 || first>1 || second >1 || third>1 || fourth>1 || fifth>1 || sixth>1 || seventh>1 || eighth>1 || ninth>1 || tenth>1 || eleventh>1 || twelveth>1){
                            string converter="";
                            converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                            theONE.stringToName(converter,theONE);
                            andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                            filling.setCfive(theONE);
                            filling.setSfive(andONLY);
                            allFilledUp=true;
                            gotCfive=true;
                            rule8++;
                            theONE=BLANK;
                            andONLY="";
                            break;
                        }
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;


           ///////////////////////////////////////
           //rule 9
            while(allFilledUp==false&&gotCfive==false){
                for(int i=0;i<orderNumbers-1;i++){
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&&searcher!=Hurray[i] &&
                    (searcher.getTeacherName().getFirstName()==Hurray[i].getTeacherName().getFirstName())&& (filling.getCone()!=Hurray[i].getTeacherName())
                    && (filling.getCtwo()!=Hurray[i].getTeacherName())&& (filling.getCthree()!=Hurray[i].getTeacherName())&& (filling.getCfour()!=Hurray[i].getTeacherName())){
                        string converter="";
                        converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                        theONE.stringToName(converter,theONE);
                        andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                        filling.setCfive(theONE);
                        filling.setSfive(andONLY);
                        allFilledUp=true;
                        gotCfive=true;
                        rule9++;
                        theONE=BLANK;
                        andONLY="";
                        break;
                    }
                    if(i==orderNumbers-2){
                        allFilledUp=true;
                        break;
                    }
                }
            }
            allFilledUp=false;


           ///////////////////////////////////////
           //rule 10
            while(allFilledUp==false&&gotCfive==false){
                int i=0;
                i=genRandomNumber(orderNumbers-1);
                    if ((destroy[searcher.getYearsTaught()-1].getSchoolName()!=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName())&&searcher!=Hurray[i]
                    && (filling.getCone()!=Hurray[i].getTeacherName())&& (filling.getCtwo()!=Hurray[i].getTeacherName())&& (filling.getCthree()!=Hurray[i].getTeacherName())
                    && (filling.getCfour()!=Hurray[i].getTeacherName())){
                        string converter="";
                        converter=(Hurray[i].getTeacherName().getFirstName())+" "+(Hurray[i].getTeacherName().getLastName());
                        theONE.stringToName(converter,theONE);
                        andONLY=Hurray[i].getBoard(Hurray[i].getYearsTaught()-1).getSchoolName();
                        filling.setCfive(theONE);
                        filling.setSfive(andONLY);
                        allFilledUp=true;
                        gotCfive=true;
                        rule10++;
                        theONE=BLANK;
                        andONLY="";
                        break;
                    }
            }
            allFilledUp=false;



        Hurray[j].setContactList(filling); //set all contacts for the teacher indexed
    }
        allContacts=true;
    }
    allContacts=true;





    cout<<"\n\n"<<orderNumbers-1<<" lists were built."<<endl;
    cout<<"Rule 1 used "<<rule1<<" times to generate contacts."<<endl;
    cout<<"Rule 2 used "<<rule2<<" times to generate contacts."<<endl;
    cout<<"Rule 3 used "<<rule3<<" times to generate contacts."<<endl;
    cout<<"Rule 4 used "<<rule4<<" times to generate contacts."<<endl;
    cout<<"Rule 5 used "<<rule5<<" times to generate contacts."<<endl;
    cout<<"Rule 6 used "<<rule6<<" times to generate contacts."<<endl;
    cout<<"Rule 7 used "<<rule7<<" times to generate contacts."<<endl;
    cout<<"Rule 8 used "<<rule8<<" times to generate contacts."<<endl;
    cout<<"Rule 9 used "<<rule9<<" times to generate contacts."<<endl;
    cout<<"Rule 10 used "<<rule10<<" times to generate contacts."<<endl;
}


/////////////////////////////////////////////////////////
//function to print all contact lists

void printContacts(int orderNumbers, teacherType Hurray[]){

    ofstream outFile;
    string fileNAME="";
    string fileNumber="";
    string convertID;
    string numbers;
    ostringstream streamer;

    int ID=0;

    for(int i=0;i<orderNumbers-1;i++){
        ID++;
        streamer.str("");
        streamer<<ID;
        convertID=streamer.str();
        numbers=convertID;
        fileNumber=numbers;
        fileNAME=Hurray[i].fileNames(fileNumber);  //passes int ID, converted to a string, to fileNames function which creates a file name based on "first+last+uniqueID+.txt"
        outFile.open(fileNAME.c_str());
        Hurray[i].printContacts(outFile);
        outFile.close();
    }
}


///////////////////////////////////////////////////////////
//random number generator for rule 10

int genRandomNumber(int nmax){
    	return rand() % nmax;
}
