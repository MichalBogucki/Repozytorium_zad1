#include "list.h"
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
    cout << "\t 0. Lewy poczatek "<< endl;
    cout << "\t 10. Wybierz element po ID"<< endl;
    cout << "\t 11. Wybierz element po Wartosci"<< endl;
    cout << "\t 2. Stworz element"<< endl;
    cout << "\t 3. Skopiuj element element"<< endl;
    cout << "\t 33. Wklej element"<< endl;
    cout << "\t 4. Usun obecny element"<< endl;
    cout << "\t 9. EXIT"<< endl;
    cout << "------------------------------\n";
    cout << "\Obecny wskaznik ==>"; list1.showCurrent(it);
    cout << "\Skopionawa wartosc ==>"<<list1.vCopy<<endl;
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
            cout<<" Podaj wartosc: "<<endl;
            cin>>choice;
            it = list1.getVal(choice);
        break;
        case 2:
            cout<<" Podaj wartosc: "<<endl;
            cin>>choice;
            list1.insertList(it,choice);
            it = it.next(it);
        break;
        case 3:
            list1.copy(it);
        break;

        case 33:
            list1.paste(it);
        break;

        case 4:
            list1.deleteList(it);
        break;
        case 9:
            cout<<endl<<"_koniec_"<<endl;
            exit(0);
        break;

        default:
        cout<<endl<<"...Niewlasciwy...Wybor..."<<endl;
        break;
        }
    }
return 0;
}

