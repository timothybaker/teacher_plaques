#include <iomanip>
#include <iostream>
#include <fstream>
#include "teacherType.h"
#include "manufactReport.h"

using namespace std;


void manufacturingReport(int numCharacters, int numSmallBoards, int orderNumbers, teacherType Hurray[]){

    ofstream outFile;
    outFile.open("manufacturingReport.txt");
    float boardFeet=0;
    float boardHours=0;
    float orders=orderNumbers;
    float Characters=numCharacters;
    float SmallBoards=numSmallBoards;

    boardHours=((orders-1)*15)/60;
    boardFeet=((12*(orders-1))+((3/2)*SmallBoards))/12;


    cout<<setprecision(2)<<fixed;
    cout<<"\n\n\n\n-"<<setfill('-')<<setw(78)<<"-"<<endl;
    cout<<"Norfolk City Schools Teacher Appreciation Plaque Manufacturing Planning Report"<<endl;
    cout<<"-"<<setfill('-')<<setw(79)<<"-\n"<<endl;
    cout<<"Number of plaques:  "<<orderNumbers-1<<" plaques"<<endl;                                             //PLAQUES
    cout<<"Person-hours estimated for stenciling plaques:  "<<boardHours<<" person-hours"<<endl;                //PERSON HOURS FOR STENCILING
    cout<<"Number of small boards:  "<<numSmallBoards<<" small boards"<<endl;                                   //SMALL BOARDS
    cout<<setprecision(3)<<fixed;
    cout<<"Total Board Feet Required:  "<<boardFeet<<" board-feet"<<endl;                                       //BOARD FEET
    cout<<"Number of Characters:  "<<numCharacters<<" characters"<<endl;                                        //CHARACTERS
    cout<<setprecision(2)<<fixed;
    cout<<"Person hours estimated for application of characters:  "<<Characters/600<<" person-hours"<<endl;     //PERSON HOURS FOR CHARACTERS
    cout<<"-"<<setfill('-')<<setw(81)<<"-\n\n\n"<<endl;

    outFile<<setprecision(2)<<fixed;
    outFile<<"\n\n\n\n-"<<setfill('-')<<setw(78)<<"-"<<endl;
    outFile<<"Norfolk City Schools Teacher Appreciation Plaque Manufacturing Planning Report"<<endl;
    outFile<<"-"<<setfill('-')<<setw(79)<<"-\n"<<endl;
    outFile<<"Number of plaques:  "<<orderNumbers-1<<" plaques"<<endl;                                             //PLAQUES
    outFile<<"Person-hours estimated for stenciling plaques:  "<<boardHours<<" person-hours"<<endl;                //PERSON HOURS FOR STENCILING
    outFile<<"Number of small boards:  "<<numSmallBoards<<" small boards"<<endl;                                   //SMALL BOARDS
    outFile<<setprecision(3)<<fixed;
    outFile<<"Total Board Feet Required:  "<<boardFeet<<" board-feet"<<endl;                                       //BOARD FEET
    outFile<<"Number of Characters:  "<<numCharacters<<" characters"<<endl;                                        //CHARACTERS
    outFile<<setprecision(2)<<fixed;
    outFile<<"Person hours estimated for application of characters:  "<<Characters/600<<" person-hours"<<endl;     //PERSON HOURS FOR CHARACTERS
    outFile<<"-"<<setfill('-')<<setw(81)<<"-\n\n\n"<<endl;


    outFile.close();
}
