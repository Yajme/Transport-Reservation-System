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

struct busInfo{

    int busNumber;
    string busName;
    string busDriver;



};
class transpo
{
    node *header[3];
    node *cn;
    int size;
    busInfo* queue;

public:
    transpo()
    {
        for (int i = 0; i < 3; i++){
            header[i] = NULL;
        }

        size = 0;
        queue = new busInfo[100];
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
                    header[i] = nn; //head
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

void remove()
{
char srch[3][10];



}
void createBus(busInfo regBus){

    queue[size] = regBus;
    size++;
    cout << "Bus created\n";
}


void showBus(){


    if(size == 0){

        cout << "No Bus Found\n";

    }
    for(int x = 0; x < size; x++){

        cout <<"["<<x+1<<"]" << queue[x].busName << endl;
    }


}
void selectBus(string x){

    if(size == 0){

        cout << "No Bus Found\n";

    }

    for(int i = 0; i < size;i++)
    {

        if(x == queue[i].busName)
        {

        }
    }
}




};



int main()
{

    transpo obj;
    busInfo bus;
    int key;
    string busName;
    bool ch0 = 1, ch1 = 1;

    obj.create();




    do{

        for(int x = 0; x < 50; x++){

        cout<<"=";

        }

    cout << "\n=\t\tMenu\t\t\t\t =\n";

        for(int x = 0; x < 50; x++){

        cout<<"=";

        }

    cout << "\n1. Add Bus Name \n2.Bus Reservation\n3.Cancel Bus Reservation\n4.Show Buses Available\n5.Exit\n\n\tEnter Your choice--> ";

    cin >> key;

    if(key == 1){

            cout << "Enter Bus name:";
            cin >> bus.busName;
            cout << "Enter Bus Driver:";
            cin >> bus.busDriver;
            cout << "Enter Bus Number:";
            cin >> bus.busNumber;

            obj.createBus(bus); //registers bus data passed to method create bus



    }else if(key == 2){

        string selectBus;
        bool busReserve = 1; //bool busReserve is true





        do{

        obj.showBus(); //displays registered bus


        cout << "Select Bus:"; //promt message
        cin >> selectBus; //input string name of bus

        obj.selectBus(selectBus); //string bus is to be passed to object select bus
        busReserve = 0;//breaks the loop


        }while(busReserve); //bool busReserve keeps the loop




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
            ch1 = 0;
            break;
        default:
            cout << "Invalid Choice!\n";
            break;
        }




        }while(ch1);//keeps the loop alive, breaks if set to false

    }else if(key == 3){


/*






*/



    }else if(key == 4){

        obj.showBus(); //displays registered bus

    }else if(key == 5){
    ch0 = 0;
    }





}while(ch0);



    return 0;
}
