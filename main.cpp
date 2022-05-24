#include <iostream>
#include <string.h>

using namespace std;


struct node
{
    int num = 1;
    int fill = 0;
    char name[3][10];
    node *next;
    node *prev;
};
class transpo
{
    node *header[3];
    node *cn;

public:
    transpo()
    {
        for (int i = 0; i < 3; i++)
            header[i] = NULL;
    }
    void create()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                node *nn = new node;
                nn->next = NULL;
                nn->prev = NULL;
                if (header[i] == NULL)
                {
                    header[i] = nn;
                    nn->num = 1;
                }
                else
                {
                    node *cn = header[i];
                    while (cn->next != NULL)
                    {
                        cn = cn->next;
                    }
                    if (j == 3 || j == 5 || j == 7 || j == 8)
                    {
                        cn->num = 3;
                    }
                    if (j == 2 || j == 4 || j == 6)
                    {
                        cn->num = 2;
                    }
                    cn->next = nn;
                    nn->prev = cn;
                }
            }
        }
    }
    void display()
    {
        int j = 0, k = 0, l = 0;
        for (int i = 0; i < 48; i++)
        {
            cout << "--";
        }
        cout << "\n "
        ;
        for (int i = 1; i < 4; i++)
        {
            cout << "| Column number : "<< i << " \t\t";
        }
        cout << "|\n" ;
        for (int i = 0; i < 48; i++)
        {
            cout << "--";
        }
        cn = header[j];
        node *sn = header[j + 1];
        node *tn = header[j + 2];
        cout << "\n ";
        while (cn != NULL)
        {
            if (cn->fill != cn->num && cn->num != 0)
            {
                j++;
                cout << "| Seat no : "<< j;
                cout << "->Vacant cots->"<< cn->num;
            }
            else
            {
                j++;
                cout << "| Seat no : "<< j;
                cout << "->Present ";
            }
            if (sn->fill != sn->num && sn->num != 0)
            {
                k++;
                cout << "\t |Seat no : "<< j;
                cout << "->Vacant cots->"<< sn->num;
            }
            else
            {
                k++;
                cout << " \t | Seat  no : "<< j;
                cout << "->Present ";
            }
            if (tn->fill != tn->num && tn->num != 0)
            {
                l++;
                cout << "\t | Seat  no : "<< j;
                cout << "->Vacant cots->"<< tn->num << "| ";
            }
            else
            {
                l++;
                cout << "\t | Seat no : "<< j;
                cout << "->Present "<< " | ";
            }
            cout << " \n ";
            for (int i = 0; i < 48; i++)
            {
                cout << "--" ;
            }
            cout << "\n ";
            cn = cn->next;
            sn = sn->next;
            tn = tn->next;
        }
    }
    void book(int people)
    {
        int col, sts;
        cout << "\nEnter the column number : ";
        cin >> col;
        try
        {
            if (col < 0 ||col > 4)

            {
                throw(col);
            }
            cn = header[col - 1];

            cout << "\nEnter the seat number : ";
            cin >> sts;
            try
            {

                if (sts < 0 || sts > 10)
                {
                    throw(sts);
                }
                else
                {
                    int i = 1;
                    while (i < sts)
                    {
                        cn = cn->next;
                        i++;
                    }
                    if (cn->num >= people)
                    {
                        cout << "\nSeat is vacant you can apply for seat " ;

                        int count = 0;
                        while (cn->fill - 1 <= cn->num)
                        {

                            cout << "\nEnter name "<< cn -> fill + 1 << " : ";

                            cin >> cn->name[cn->fill];
                            count++;
                            cn->fill++;
                            if (count >= people)
                            {
                                break;
                            }
                        }
                        cn->num = cn->num - people;
                    }

                    else
                    {
                        cout << "\nSeat is already taken, sorry !!!";
                    }
                }
            }
            catch (int r)
            {
                cout << "\nInvalid  column number : "<< r;
            }
        }
        catch (int r)
        {
            cout << " \ninvalid Seat  number : " << r;
        }

        catch (int r)

        {
            cout << "\nSeat doesn't exist : "<< r;
        }
    }

void createBus(){

int size;





}


string showBus(string x){

    string bus = x;


    if(bus.empty()){


        return "Bus is Empty\n";
    }


}


};



int main()
{

    transpo obj;
    int key;
    bool ch = 1;
    obj.create();



    for(int x = 0; x < 50; x++){

        cout<<"=";

    }

    cout << "\n=\t\tMenu\t\t\t\t =\n";

    for(int x = 0; x < 50; x++){

        cout<<"=";

}
    do{

    cout << "\n1. Add Bus Name \n2.Bus Reservation\n3.Show Buses Available\n4.Exit\nEnter Your choice-->";

    cin >> key;

    if(key == 1){

    }else if(key == 2){

         do{

        cout << "\n1.Reserve a seat for 1 person\n2.Reserve a seat for 2 persons\n3.Reserve a seat for 3 persons\n4.Display the current status of reserve a seat\n5.Exit\n";
        cout << " Enter your choice : "   ;
        cin >> key;
        switch (key)
        {
        case 1:

            obj.book(1);
            break;

        case 2:

            obj.book(2);
            break;

        case 3:

            obj.book(3);
            break;

        case 4:

            obj.display();
            break;
        case 5:
            ch = 0;
            break;
        default:
            cout << "Invalid Choice!\n";
            break;
        }


        }while(ch);

    }else if(key == 3){

    }else if(key == 4){
    ch = 0;
    }

}while(ch);


    return 0;
}
