#include <iomanip>
#include <iostream>
#include "plaqueMenu.h"
#include "readAllOrders.h"
#include "manufactReport.h"
#include "findContacts.h"


using namespace std;

int main()
{
    bool allIsWell=true;
    string getChoice="BLANKITYBLANK";
    int choice=10;
    bool PLAYNICE=true;
    bool chosen=false;
    bool closingTime=false;
    int orderNumbers=0;
    int numCharacters=0;
    int numSmallBoards=0;

    cout<<"Welcome to the Norfolk City Schools Elementary School Teacher"<<endl;
    cout<<"Appreciation Plaque set Data Entry Program"<<endl;

    while(allIsWell==true){
        while(PLAYNICE==true && closingTime==false){
            cout<<"\nPlease Select an Option\n\n";
            cout<<"Enter 1 to Input Plaque Set Information\n";
            cout<<"Enter 2 to Create All Teacher Contact Lists\n";
            cout<<"Enter 3 to Print Manufacturing Report\n";
            cout<<"Enter 4 to Quit: ";
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
                if (choice==1){
                    plaqueMenu();
                    chosen=true;
                }
                if (choice==2){
                    getNumberOfOrders(orderNumbers);                                ////////////////////////////////////////////////////
                    teacherType* Hurray=new teacherType[orderNumbers];              //make an array of teacherTypes, one for each order.
                    readOrders(numCharacters,numSmallBoards,orderNumbers,Hurray);   //inFile is read twice, once to find number of orders,
                    findContacts(orderNumbers,Hurray);
                    printContacts(orderNumbers,Hurray);
                    chosen=true;                                                    //and again to store information.  This was done to
                    delete[]Hurray;                                                 //minimize the array size, so that only an array of the
                    orderNumbers=0;                                                 //exact needed size is created
                    numCharacters=0;
                    numSmallBoards=0;
                }
                if (choice==3){
                    getNumberOfOrders(orderNumbers);
                    teacherType* Hurray=new teacherType[orderNumbers];
                    readOrders(numCharacters,numSmallBoards,orderNumbers,Hurray);
                    manufacturingReport(numCharacters, numSmallBoards,orderNumbers,Hurray);
                    chosen=true;
                    delete[]Hurray;
                    numCharacters=0;
                    numSmallBoards=0;
                    orderNumbers=0;
                }
                if (choice==4){
                    closingTime=true;
                    chosen=true;
                    allIsWell=false;
                }
                else if (choice>4||choice<1){
                    PLAYNICE=false;
                }
            }
            if (chosen==true){
                chosen=false;
            }
            if (PLAYNICE==false){
                cout<<"\n\nENTER VALID CHOICE!!!\n";
                PLAYNICE=true;
            }
        }
    }
    return 0;
}
