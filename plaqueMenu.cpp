#include <iomanip>
#include <iostream>
#include <fstream>
#include "teacherType.h"
#include "plaqueMenu.h"

using namespace std;

void displayStencil(teacherType teacher, mainPlaque plaque, smallBoard board[], Name teacherName, int boardCounter);
void selectionToSaying(mainPlaque plaque,string& super, string& sayan);

///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~
//plaque menu and functions

void plaqueMenu(){

    Name teacherName;
    teacherType teacher;
    mainPlaque plaque;
    smallBoard* board=new smallBoard[50];
    ofstream outFile;
    int boardCounter=0;
    bool allIsWell=true;
    string getChoice="BLANKITYBLANK";
    int choice=10;
    bool PLAYNICE=true;
    bool chosen=false;

    outFile.open("allOrders.txt",ios::out | ios::app);

    while(allIsWell==true){

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //small board collection
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////


        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //saying collection
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        while(PLAYNICE==true&&chosen==false){
            cout<<"\n\nChoose one of the following five sayings for your plaque:\n\n";
            cout<<"[1] A teacher takes a hand, opens a mind and touches a heart\n";
            cout<<"[2] Those who know, DO.  Those that understand, TEACH.\n";
            cout<<"[3] Be somebody who makes EVERYBODY feel like SOMEBODY\n";
            cout<<"[4] Good teachers TEACH, great teachers INSPIRE\n";
            cout<<"[5] Teaching elementary school is an adventure, not a job.\n";
            cout<<"\nEnter Your Choice (1-5): ";
            cin>>getChoice;

            if (getChoice.length()>1){
            PLAYNICE=false;
            }
            getChoice=CutterUpper(getChoice, 1);
            cin.ignore(100, '\n');
            cout<<endl;

            while (PLAYNICE==true&&chosen==false){
                if (getChoice[0]<48||getChoice[0]>57){
                    PLAYNICE=false;
                    break;
                }
                else if (getChoice[0]>47||getChoice[0]){
                    choice=getChoice[0]-48;
                }
                if (choice==1||choice==2||choice==3||choice==4||choice==5){
                    plaque.setSaying(choice);
                    chosen=true;
                }
                else if (choice>5||choice<1){
                    PLAYNICE=false;
                }
            }
            if (PLAYNICE==false){
                cout<<"\n\nENTER VALID CHOICE!!!\n";
                PLAYNICE=true;
            }
        }
        if (chosen==true){
            chosen=false;
        }
        //////////////////////////////////////////////////////////////////////////////////////////////////////////
        //Name collection
        //////////////////////////////////////////////////////////////////////////////////////////////////////////
        while(PLAYNICE==true&&chosen==false){
            //Name collection
            cout<<"\n\nEnter your title, first name, and last name (25 or fewer characters)\n";
            cout<<"Example: Mr. Timmy Hendrix\n\n";
                string getName="";
                Name gotName;
                cin>>gotName;
                cin.ignore(100,'\n');
                getName=gotName.nameToString(gotName);
                if (getName.length()<26){
                    teacherName=gotName;
                    chosen=true;
                }
                else {
                    PLAYNICE=false;
                }
            if (PLAYNICE==false){
                PLAYNICE=true;
                cout<<"\nPlease Enter 25 or fewer Characters\n";
            }
        }
       if (chosen==true){
           chosen=false;
       }

        //////////////////////////////////////////////////////////////////////////////////////////////////////////
        //Graduation Date collection
        //////////////////////////////////////////////////////////////////////////////////////////////////////////
        while(PLAYNICE==true&&chosen==false){
            //College Graduation date collection
            cout<<"\n\n\nEnter the 4-digit year that you graduated from college:\n\n";
                string getYear="";
                cin>>getYear;
                cin.ignore(100,'\n');
            if (getYear.length()!=4){
                    PLAYNICE=false;
            }
            for (unsigned int i=0;i<getYear.length();i++){
                if (getYear[i]>57||getYear[i]<48){
                    if(PLAYNICE==true){
                        PLAYNICE=false;
                    }
                }
            }
            while(PLAYNICE==true&&chosen==false){
                    plaque.setGradYear(getYear);
                    chosen=true;
            }
            if (PLAYNICE==false){
                PLAYNICE=true;
                cout<<"\nPlease Enter 4-digits (0-9)\n";
            }
       }
       if (chosen==true){
           chosen=false;
       }
        //////////////////////////////////////////////////////////////////////////////////////////////////////////
        //University or college collection
        //////////////////////////////////////////////////////////////////////////////////////////////////////////
        while(PLAYNICE==true&&chosen==false){
            //Name collection
            cout<<"\n\n\nEnter the abbreviated name for the school where you earned"<<endl;
            cout<<"your degree (10 or fewer characters)\n";
            cout<<"Example: ODU\n\n";
                char gotSchool[100];
                cin.get(gotSchool,100);
                cin.ignore(100,'\n');
                string getSchool=gotSchool;
                if (getSchool.length()<10){
                    plaque.setUniAbbrev(getSchool);
                    chosen=true;
                }
                else {
                    PLAYNICE=false;
                }
            if (PLAYNICE==false){
                PLAYNICE=true;
                cout<<"\nPlease Enter 10 or fewer Characters\n";
            }
       }
       if (chosen==true){
           chosen=false;
       }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //small board collection
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool wouldYouHaveAnother=true;
        while (wouldYouHaveAnother==true){
            string getChoice="";

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //grade taught collection
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////
        while(PLAYNICE==true&&chosen==false){
            cout<<"\n\n\nEnter the grade taught for this small board (K-12)\n\n";
                string getGrade="";
                cin>>getGrade;
                cin.ignore(100,'\n');
                if (getGrade.length()>2){PLAYNICE=false;}
                if (PLAYNICE==true){if(getGrade!="K"){PLAYNICE=false;}}
                if (PLAYNICE==false){if(getGrade=="k"){PLAYNICE=true;}}
                if (PLAYNICE==false){if(getGrade[0]>48 && getGrade[0]<57){PLAYNICE=true;}}
                if (PLAYNICE==true&&getGrade.length()>1){if(getGrade[1]>50||getGrade[1]<48){PLAYNICE=false;}}
                if (PLAYNICE==true){if(getGrade.length()>1){if(getGrade[0]!=49){PLAYNICE=false;}}}
                if (PLAYNICE==true){
                    if(getGrade[0]=='k'){getGrade[0]='K';}
                    board[boardCounter].setGradeTaught(getGrade);
                    chosen=true;
                }
                if (PLAYNICE==false){
                    PLAYNICE=true;
                    cout<<"\nPlease Enter K or 1-12\n";
                }
        }
        if (chosen==true){
            chosen=false;
        }

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //school Name collection
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////
        while(PLAYNICE==true&&chosen==false){
            cout<<"\n\nEnter the name of the school where you taught for this small"<<endl;
            cout<<"board (28 or fewer characters)\n";
            cout<<"Example: Florence Bowser Elementary\n\n";
                char gotSchool[28];
                string getSchool="";
                cin.get(gotSchool,28);
                cin.ignore(100,'\n');
                getSchool=gotSchool;
                if (getSchool.length()<28){
                    board[boardCounter].setSchoolName(getSchool);
                    chosen=true;
                }
                else {
                    PLAYNICE=false;
                }
            if (PLAYNICE==false){
                PLAYNICE=true;
                cout<<"\nPlease Enter 28 or fewer Characters\n";
            }
        }
        if (chosen==true){
            chosen=false;
        }

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //emblem collection
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////
        while(PLAYNICE==true&&chosen==false){

            cout<<"\n\n\nEnter the character for the emblem you would like on this small board.\n\n";
            cout<<"[A] Apple\n";
            cout<<"[R] Ruler\n";
            cout<<"[C] Chalkboard\n";
            cout<<"[G] Graduation Cap\n";
            cout<<"[H] Handprint\n";
            cout<<"[N] None\n";
            cout<<"\nEnter your choice: ";
                string getEmblem="";
                cin>>getEmblem;
                cin.ignore(100,'\n');
                if (getEmblem.length()>1 || getEmblem.length()<1){
                        PLAYNICE=false;
                }
                getEmblem=CutterUpper(getEmblem,1);
                if (getEmblem[0]!='A'){
                    if(getEmblem[0]!='R'){
                        if(getEmblem[0]!='C'){
                            if(getEmblem[0]!='G'){
                                if(getEmblem[0]!='H'){
                                    if(getEmblem[0]!='N'){
                                        if (PLAYNICE==true){
                                            PLAYNICE=false;
                                        }}}}}}
                }
                if (PLAYNICE==true){
                    board[boardCounter].setEmblem(getEmblem[0]);
                    chosen=true;
                }
            if (PLAYNICE==false){
                PLAYNICE=true;
                cout<<"\n\nPlease Enter A, R, C, G, H, or N\n";
            }
       }
       if (chosen==true){
           chosen=false;
       }

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //school year collection
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////
        while(PLAYNICE==true&&chosen==false){
            cout<<"\n\n\nEnter the 4-digit year for the starting year for this small board.\n";
            cout<<"Example: For the 2015-2016 school year, enter 2015.\n\n";
                string getYear="";
                cin>>getYear;
                cin.ignore(100,'\n');
            if (getYear.length()!=4){
                    PLAYNICE=false;
            }
            for (unsigned int i=0;i<getYear.length();i++){
                if (getYear[i]>57||getYear[i]<48){
                    if(PLAYNICE==true){
                        PLAYNICE=false;
                    }
                }
            }
            if(PLAYNICE==true){
                    board[boardCounter].setSchoolYear(getYear);
                    chosen=true;
            }
            if (PLAYNICE==false){
                PLAYNICE=true;
                cout<<"\n\nPlease Enter 4-digits (0-9)\n";
            }
        }
        if (chosen==true){
            chosen=false;
        }

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //would you have another??
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////
            while(PLAYNICE==true&&chosen==false){
                cout<<"\n\n\nAdd another small board (Y or N)\n";
                cout<<"Press Y to add another small board or N to complete the order and save it: ";
                cin>>getChoice;
                cin.ignore(100,'\n');
                if (getChoice.length()>1){PLAYNICE=false;}
                getChoice[0]=toupper(getChoice[0]);
                if (getChoice[0]!='Y'){if(getChoice[0]!='N'){PLAYNICE=false;}}
                if (PLAYNICE==true){
                        if (getChoice[0]=='Y'){
                            chosen=true;
                        }
                        if (getChoice[0]=='N'){
                            chosen=true;
                            wouldYouHaveAnother=false;
                            allIsWell=false;
                        }
                }
                else if(PLAYNICE==false){
                    cout<<"\n\nPlease Enter Y or N\n";
                    PLAYNICE=true;
                }
            }
            if (chosen==true){
           chosen=false;
            }
        boardCounter++;
        }//End of wouldYouHaveAnother loop

    }//End of Plaque Menu Main Control While loop

    teacher.setTeacherName(teacherName);
    plaque.setTeacherName(teacherName);
    teacher.setYearsTaught(boardCounter);
    teacher.setPlaque(plaque);
    teacher.setBoard(board);
    teacher.print(outFile);

    displayStencil(teacher, plaque, board, teacherName, boardCounter);
    cout<<"\n\n\nORDER COMPLETE -- Your order has been saved to the allOrders.txt file.\n\n"<<endl;

    delete []board;
    outFile.close();
}// End of Plaque Menu


///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~///~
//various functions

string CutterUpper(string tobeCutUp, int cutLength)
{
    string CutterAdder=" ";
    string Cutter="";
    char Upper='!';

    for (int i=0; i<cutLength;i++){
        Cutter=Cutter+CutterAdder;
    }

    for(int i=0; i<cutLength; i++){
        Upper=tobeCutUp[i];
        Cutter[i]=toupper(Upper);
    }
    return Cutter;
}

/////////////////////////////////////////////////////////////
//function to display ASCII stencil of plaque
void displayStencil(teacherType teacher, mainPlaque plaque, smallBoard board[], Name teacherName, int boardCounter){

    string problemSolver=teacherName.nameToString(teacherName);
    string super="";
    string sayan="";
    int superLength=0;
    int sayanLength=0;
    int superOffset=0;
    int sayanOffset=0;

    selectionToSaying(plaque,super,sayan);
    superLength=super.length();
    superOffset=superLength;
    sayanLength=sayan.length();
    sayanOffset=sayanLength;
    if (superOffset%2!=0){superOffset--;}
    if (sayanOffset%2!=0){sayanOffset--;}

    cout<<"\n="<<setfill('=')<<setw(53)<<"="<<endl;
    cout<<"|"<<setfill(' ')<<setw(53)<<"|"<<endl;
    cout<<"|"<<setfill(' ')<<setw(53)<<"|"<<endl;
    cout<<"|"<<setfill(' ')<<setw(53)<<"|"<<endl;
    cout<<"|"<<setfill(' ')<<setw(53)<<"|"<<endl;
    cout<<"|"<<setfill(' ')<<setw(53)<<"|"<<endl;
    cout<<"|"<<setfill(' ')<<setw(53)<<"|"<<endl;
    cout<<"|"<<setfill(' ')<<setw(11)<<" "<<right<<"(Stenciled SchoolHouse Scene)"<<setw(13)<<"|"<<endl;
    cout<<"|"<<setfill(' ')<<setw(53)<<"|"<<endl;
    cout<<"|"<<setfill(' ')<<setw(53)<<"|"<<endl;
    cout<<"|"<<setfill(' ')<<left<<setw(26)<<problemSolver<<setw(20)<<right<<plaque.getUniAbbrev()<<setw(2)<<", "<<setw(4)<<plaque.getGradYear()<<"|"<<endl;
    cout<<"|"<<setfill(' ')<<setw(53)<<"|"<<endl;
    cout<<"|"<<setfill(' ')<<setw((52-superLength)/2)<<" "<<super<<" "<<setw((52-superOffset)/2)<<"|"<<endl;
    cout<<"|"<<setfill(' ')<<setw(53)<<"|"<<endl;
    cout<<"|"<<setfill(' ')<<setw((52-sayanLength)/2)<<" "<<sayan<<" "<<setw((52-sayanOffset)/2)<<"|"<<endl;
    cout<<"|"<<setfill(' ')<<setw(53)<<"|"<<endl;
    cout<<"="<<setfill('=')<<setw(53)<<"="<<endl;

    for(int i=0;i<boardCounter;i++){
        int inTheMiddleSir=0;
        int onTheRightKindly=0;
        inTheMiddleSir=board[i].getSchoolName().length();
        onTheRightKindly=inTheMiddleSir;
        if (inTheMiddleSir%2!=0){inTheMiddleSir=inTheMiddleSir-1;}
        if (board[i].getGradeTaught()=="10" || board[i].getGradeTaught()=="11" || board[i].getGradeTaught()=="12"){inTheMiddleSir++;}
        cout<<setfill(' ')<<setw(7)<<"O"<<setw(41)<<"0"<<endl;
        cout<<setfill(' ')<<setw(7)<<"$"<<setw(41)<<"$"<<endl;
        cout<<"="<<setfill('=')<<setw(53)<<"="<<endl;
        cout<<"|"<<setfill(' ')<<setw(53)<<"|"<<endl;
        cout<<"|"<<setfill(' ')<<setw(2)<<" "<<board[i].getGradeTaught()<<setw((46-inTheMiddleSir)/2)<<" "<<board[i].getSchoolName();
        cout<<setw((46-onTheRightKindly)/2)<<" "<<board[i].getEmblem()<<right<<setw(3)<<"|"<<endl;
        cout<<"|"<<setfill(' ')<<setw(24)<<" "<<board[i].getSchoolYear()<<setw(25)<<"|"<<endl;
        cout<<"="<<setfill('=')<<setw(53)<<"="<<endl;
    }
}

/////////////////////////////////////////////////////////////
//function to convert saying selection into two strings
//to send to stencil picture

void selectionToSaying(mainPlaque plaque, string& super, string& sayan){
    if(plaque.getSaying()==1){
        super="A teacher takes a hand,";
        sayan="opens a mind, and touches a heart";
    }
    if(plaque.getSaying()==2){
        super="Those who know, DO.";
        sayan="Those that understand, TEACH.";
    }
    if(plaque.getSaying()==3){
        super="Be somebody who makes";
        sayan="EVERYBODY feel like SOMEBODY";
    }
    if(plaque.getSaying()==4){
        super="Good teachers TEACH,";
        sayan="great teachers INSPIRE";
    }
    if(plaque.getSaying()==5){
        super="Teaching elementary school";
        sayan="is an adventure, not a job";
    }
}
