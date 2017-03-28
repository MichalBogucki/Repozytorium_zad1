#include "List.h"
#include "List.cpp"

int main()
{
    int cNumber, choice;
    initialise ();
//-----------menu-------------
    while (1)
    {
    cout << "\n";
    list1.display();
    cout << "\n-----------menu-------------\n";
    cout << "\t 0. Lewy p  oczatek"<< endl;
    cout << "\t 10. Wybierz element po ID"<< endl;
    cout << "\t 11. Wybierz element po choiceosci"<< endl;
    cout << "\t 2. Stworz element"<< endl;
    cout << "\t 3. Usun obecny element"<< endl;
    cout << "\t 9. EXIT"<< endl;
    cout << "------------------------------\n";
    cout << "\Obecny wskaznik =="; list1.showCurrent(it);
    cout <<"Wybierz opcje: ";
    cin>>cNumber;
    cin.clear();
    cin.ignore(100, '\n');

    switch(cNumber)
        {
        case 0:
        it = list1.head;
        break;
        case 10:
            cout<<" Podaj ID: "<<endl;
            cin>>choice;
            it = list1.getID(choice);
        break;
        case 11:
            cout<<" Podaj choiceosc: "<<endl;
            cin>>choice;
            it = list1.getVal(choice);
        break;
        case 2:
            cout<<" Podaj choiceosc: "<<endl;
            cin>>choice;
            list1.insertList(it,choice);
            it = it.next(it);
        break;
        case 3:
            list1.deleteList(it);
        break;
        case 9:
            cout<<endl<<"_koniec_"<<endl;
            exit(0);
        break;

        default:
        cout<<endl<<"...Niewlasciwy...cNumber..."<<endl;
        break;
        }
    }
return 0;
}

