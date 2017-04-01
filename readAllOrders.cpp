#include "readAllOrders.h"
#include "teacherType.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


void getNumberOfOrders(int& numberOfOrders){

        ifstream inFile;
        /////////////////////////////////////////////////////
        //find the number of orders
        inFile.open("allOrders.txt");
        char findBars[100];
        string foundBars="";
        while(!inFile.eof()){
            inFile.getline(findBars,100);
            foundBars=findBars;
            if (foundBars=="///"){
                numberOfOrders++;
            }
        }
        inFile.close();
}


void readOrders(int& numCharacters, int& numSmallBoards, int& numberOfOrders, teacherType Hurray[]){

        ///////////////////////////////////////////////////
        //function variables
        ofstream outFile;
        ifstream inFile;
        Name heyTeach("I","AM","TEACH");
        teacherType BUELLER; //test mule, THANKS BUELLER
        mainPlaque Picard;
        smallBoard tryME;
        smallBoard* StevieRay=new smallBoard[50];
        int orderNumbers=numberOfOrders;
        int orderCounter=1;



        ////////////////////////////////////////////////////
        //store the information from allOrders into Hurray

            char lineGrabber[100];
            string barFinder="";
            bool thatsAllFolks=false;
            bool getMeOutOfHere=false;
            int hurrayIndex=0;
            int rayIndex=0;

            inFile.open("allOrders.txt");
            outFile.open("testingBueller.txt");

            inFile.getline(lineGrabber,100);
            barFinder=lineGrabber;
            if(barFinder!="///"){thatsAllFolks=true;}

            while(thatsAllFolks==false){
                        //fill plaque
                        orderCounter++;
                        rayIndex=0;
                        inFile.getline(lineGrabber, 50);
                        barFinder=lineGrabber;
                            numCharacters+=barFinder.length();
                            heyTeach.stringToName(barFinder,heyTeach);
                            Picard.setTeacherName(heyTeach);
                            Hurray[hurrayIndex].setTeacherName(heyTeach);
                        inFile.getline(lineGrabber,100);
                        barFinder=lineGrabber;
                            numCharacters+=barFinder.length();
                            Picard.setUniAbbrev(barFinder);
                        inFile.getline(lineGrabber,100);
                        barFinder=lineGrabber;
                            numCharacters+=barFinder.length();
                            Picard.setGradYear(barFinder);
                        inFile.getline(lineGrabber,100);
                        barFinder=lineGrabber;
                            numCharacters+=barFinder.length();
                            Picard.setSaying(barFinder[0]-48);

                        //fill smallBoard
                        numSmallBoards++;
                        inFile.getline(lineGrabber,100);
                        barFinder=lineGrabber;
                            numCharacters+=barFinder.length();
                            tryME.setGradeTaught(barFinder);
                        inFile.getline(lineGrabber,100);
                        barFinder=lineGrabber;
                            numCharacters+=barFinder.length();
                            tryME.setSchoolName(barFinder);
                        inFile.getline(lineGrabber,100);
                        barFinder=lineGrabber;
                            numCharacters+=barFinder.length();
                            tryME.setEmblem(barFinder[0]);
                        inFile.getline(lineGrabber,100);
                        barFinder=lineGrabber;
                            numCharacters+=barFinder.length();
                            tryME.setSchoolYear(barFinder);

                        StevieRay[rayIndex]=tryME;

                    while (getMeOutOfHere==false){
                        rayIndex++;
                        //fill smallBoard for as many times as one exist for this teacher
                        inFile.getline(lineGrabber,100);
                        barFinder=lineGrabber;
                            if(barFinder=="///"){getMeOutOfHere=true;break;}
                            numCharacters+=barFinder.length();
                            tryME.setGradeTaught(barFinder);
                        inFile.getline(lineGrabber,100);
                        barFinder=lineGrabber;
                            numCharacters+=barFinder.length();
                            tryME.setSchoolName(barFinder);
                        inFile.getline(lineGrabber,100);
                        barFinder=lineGrabber;
                            numCharacters+=barFinder.length();
                            tryME.setEmblem(barFinder[0]);
                        inFile.getline(lineGrabber,100);
                        barFinder=lineGrabber;
                            numCharacters+=barFinder.length();
                            tryME.setSchoolYear(barFinder);
                        StevieRay[rayIndex]=tryME;
                        numSmallBoards++;
                    }
                        getMeOutOfHere=false;
                    ////////////////////////////////////////////////////
                    //set Hurray
                    Hurray[hurrayIndex].setYearsTaught(rayIndex);
                    Hurray[hurrayIndex].setPlaque(Picard);
                    Hurray[hurrayIndex].setBoard(StevieRay);
                    //Hurray[hurrayIndex].print(outFile);                           // print all of the orders back to testingBueuller for verfication
                    hurrayIndex++;
                    if(orderCounter==orderNumbers){thatsAllFolks=true;}
            }
        inFile.close();
        outFile.close();
        //cout<<orderNumbers<<"<\n-NUMBER OF ORDERS<-"<<endl;                     // print order numbers as the readOrders file is read

        ////////////////////////////////////////////////////
        //let my people go
        delete []StevieRay;
}



