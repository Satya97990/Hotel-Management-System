#include<conio.h>
#include <bits/stdc++.h>
using namespace std;
int cnt = 0;

class Customer
{
public:
      char name[100];
      char address[100];
      char phone[10];
      char email[100];
      char from_date[20];
      char to_date[20];
      float advance_payment;
      int booking_id;
      int room_no;
};
class Room
{
public:
      char room_type[15];
      int room_no;
      float room_price;
      int room_status;
      Customer cust;
      void display_room(Room);
      class Room addRoom(int);
      void searchRoom(int);
};
class Room rooms[100];
Room Room::addRoom(int room_num)
{
    class Room room;
    room.room_no=room_num;
    cout<<"\t\t\t Enter room type(AC/Non Ac:)"<<endl;
    cin>>room.room_type;
    cout<<"\t\t\t Enter room price:"<<endl;
    cin>>room.room_price;
    room.room_status=0;
    cout<<endl;
    cout<<"...................................."<<endl;
    cout<<"\t\t Room added succesfully"<<endl;
    cout<<"\t\t .............................."<<endl;
    cout<<"\t\t Enter any key to continue"<<endl;
    getch();
    return room;
}
// void Room::searchRoom(int)
// {
// }
void Room::searchRoom(int room_num)
{
      int i,found=0;
      for(int i=0;i<cnt;i++)
      {
            if(rooms[i].room_no==room_num)
            {
                  found=1;
                  break;
            }

      }
      if(found==1)
      {
            cout<<"\t\t Room Details"<<endl;
            cout<<"\t\t .........................."<<endl;
            if(rooms[i].room_status==1)
            {
                 cout<<"\t\tRoom is reserved"<<endl;
                 cout<<"\t\tRoom Number"<<rooms[i].room_no<<endl;
                 cout<<"\t\t\t Room type (AC/non ac)"<<rooms[i].room_type<<endl;
                 cout<<"\t\t\t room price "<<rooms[i].room_price<<endl;

            }
            else
            {
                  cout<<"\t\t Room is available"<<endl;
            }
           
      }
      else {
            cout<<"Room is not available"<<endl;
      }
}
void Room::display_room(Room room)
{
      cout << "\t\t\tRoom Number: " << room.room_no << endl;
      cout << "\t\t\tRoom type(AC/Non Ac): " << room.room_type << endl;
      cout << "\t\t\tRoom price: " << room.room_price << endl;
      cout << "\t\t\tRoom rent :" << room.room_price << endl;
}

class Hotel_Management
{
public:
      void check_in();
      void available_rooms();
      void searchCustomer(char *);
      void check_out(int);
      void guest_summary();
};

Hotel_Management hm;
Room rm;
void Hotel_Management::guest_summary()
{
    if(cnt==0)
    {
      cout<<"\t\t No guest is present"<<endl;
    }
    for(int i=0;i<cnt;i++)
    {
      if(rooms[i].room_status==1)
      {
            cout<<"\t\t\t Customer name :"<<rooms[i].cust.name<<endl;
            cout<<"\t\t\t Customer addres"<<rooms[i].cust.address<<endl;
            cout<<"\t\t\t Customer phone"<<rooms[i].cust.phone<<endl;
            cout<<"\t\t\t Customer E mail"<<rooms[i].cust.phone<<endl;
            cout<<"\t\t\t Room number:   "<<rooms[i].cust.room_no<<endl;
            cout<<"\t\t\t Staying since :"<<rooms[i].cust.from_date<<endl;
            cout<<"\t\t\t Staying till:"<<rooms[i].cust.to_date<<endl;
            cout<<"\t\t\t Advance payement :"<<rooms[i].cust.advance_payment<<endl;
            cout<<"\t\t\t Room type:(AC/Non Ac)" <<rooms[i].room_no<<endl;

            

      }
    }
    cout<<"Press any key to continue"<<endl;
    getch();
}


void Hotel_Management::check_out(int roomnum)
{
      int i=0,days,rno,found=0;
      float total_bill=0;
      for(int i=0;i<cnt;i++)
      {
            if(rooms[i].room_no==roomnum)
            {
                  found=1;
                  break;

            }
      }
      if(found==1)
      {
            cout<<"\t\t\t Enter the number of days:";
            cin>>days;
            total_bill=days*rooms[i].room_price;
            cout<<"\t\t\t Checkout Details"<<endl;
            cout<<"\t\t .................................."<<endl;
            cout<<"\t\t\t Customer Name: "<<rooms[i].cust.name<<endl;
            cout<<"\t\t\t Customer address:"<<rooms[i].cust.address<<endl;
            cout<<"\t\t\t Customer phone :"<<rooms[i].cust.phone<<endl;
            cout<<"\t\t\t Room number: "<<rooms[i].room_no<<endl;
            cout<<"\t\t\t Room type(AC/Non AC): "<<rooms[i].room_type <<endl;
            cout<<"\t\t\t Total bill:"<<total_bill<<endl;
            cout<<"\t\t\t Advance payment "<<rooms[i].cust.advance_payment<<endl;
            cout<<"\t\t\t Remaining payment : "<<total_bill-rooms[i].cust.advance_payment<<endl;
            cout<<"............................................"<<endl;
            rooms[i].room_status=0;


      


      }
      else{
            cout<<"\t\t\t Room is not booked "<<endl;
            cout<<"\t\t\t Enter any key to continue"<<endl;
            getch();

      }

      
}
void Hotel_Management::searchCustomer(char *pname)
{
      int i = 0, found = 0;
      for (int i = 0; i < cnt; i++)
      {
            if (rooms[i].room_status == 1 && stricmp(rooms[i].cust.name, pname) == 0)
            {
                  cout << "\t\t\t Customer Name :" << rooms[i].cust.name << endl;
                  cout << "\t\t\t Room number : " << rooms[i].cust.room_no << endl;
                  cout << "\t\t To see more details press yes or no: ";
                  char option[10];
                  cin >> option;
                  if (stricmp(option, "yes") == 0)
                  {
                        rm.display_room(rooms[i]);
                  }
                  found = 1;
                  cout << "\t\t\t Press any key to continue" << endl;
                  getch();
            }
      }
}
void Hotel_Management::available_rooms()
{
      int i, found = 0;
      for (int i = 0; i < cnt; i++)
      {
            if (rooms[i].room_status == 0)
            {
                  rm.display_room(rooms[i]);
                  cout << "\t\t\t Room is available" << endl;
                  found = 1;
                  cout << "\t\t\tEnter any key to continue" << endl;
                  break;
            }
      }
      if (found == 0)
      {
            cout << "\t\t\t No room is available" << endl;
            cout << "\t\t\tEnter any key to continue" << endl;
            getch();
      }
}
void Hotel_Management::check_in()
{
      int i, found = 0, room_no;
      class Room room;
      cout << "\t\t Enter the room number: ";
      cin >> room_no;
      for (int i = 0; i < cnt; i++)
      {
            if (rooms[i].room_no == room_no)
            {
                  found = 1;
                  break;
            }
      }
      if (found == 1)
      {
            if (rooms[i].room_status == 1)
            {
                  cout << "\t\t\t Room is already Booked " << endl;
                  cout << "\t\t Press any key to continue..." << endl;
                  getch();
            }
            else
            {
                  cout << "\t\t Enter Booking id: " << endl;
                  cin >>rooms[i].cust.booking_id;
                  //cout << "\t\t..................................." << endl;
                  cout <<"\t\t\t Enter name: "<<endl;
                  cin>>rooms[i].cust.name;

                  cout <<"\t\t\t Ener address :"<<endl;
                  fflush(stdin);
                  cin>>rooms[i].cust.address;
                  cout<<"\t\t\t Ener phone :"<<endl;
                  fflush(stdin);
                  cin>>rooms[i].cust.phone;
                  cout <<"\t\t\t Ener email :"<<endl;
                  fflush(stdin);
                  cin>>rooms[i].cust.email;
                  cout <<"\t\t..................................." << endl;
                  cout <<"\t\t\t Enter from date: ";
                  cin>>rooms[i].cust.from_date;
                  cout <<"\t\t\t Enter to Date: "<<endl;
                  cin>>rooms[i].cust.to_date;
                  cout <<"\t\t\t Enter advance payment: "<<endl;
                  cin >> rooms[i].cust.advance_payment;
                  cout <<"\t\t..................................." << endl;
                  rooms[i].room_status = 1;
            }
      }
}

void manage_room()
{
      int opt, room_num;
      string room_type, room_status;
      float room_price;
      int flg=0;

      cout << "\t\t Manage room" << endl;
      cout << "\t\t............................" << endl;
      cout << "\t\t 1.Add room" << endl;
      cout << "\t\t 2.Search room" << endl;
      cout << "\t\t 3.Back to main menu" << endl;
      cout << "\t\t 4.Back " << endl;
      cout << "\t\t............................." << endl;
      cout << "\t\t Enter your choice for above:";
      cin >> opt;

      switch (opt)
      {
      case 1:
            system("cls");
            cout<<"\t\t\t Enter the room number:"<<endl;
            cin>>room_num;
            
            for(int i=0;i<cnt;i++)
            {
                  if(rooms[i].room_no==room_num)
                  {
                        flg=1;
                  }
            }
            if(flg==1)
            {
                  cout<<"\t\t\t Room number is present. "<<endl;

                 // cout<<"\t\t\t Enter any key to continu"<<endl;
                  flg=0;
                 // getch();
            }
            else
            {
                  rooms[cnt]=rm.addRoom(room_num);
                  cnt++;
            }
           

            
            break;

      case 2:
            system("cls");
            cout<<"\t\t\t Enter the room number to be searched:"<<endl;
            cin>>room_num;
            rm.searchRoom(room_num);
            cout << "\t\t..........................." << endl;
            cout << "\t\t Press any key to continue..." << endl;
            getch();
            break;

      case 3:
            // system("cls");
            // cout << "\t\t\t Edit room" << endl;
            // cout << "\t\t.............................." << endl;
            // cout << "\t\t Enter room number:";
            // cin >> room_no;
            // cout << "\t\t Enter room type:";
            // cin >> room_type;
            // cout << "\t\t Enter room price:";
            // cin >> room_price;
            // cout << "\t\t Enter room status";
            // cin >> room_status;
            // cout << "\t\t.........................." << endl;
            // cout << "\t\t Press any key to continue..." << endl;
            // getch();
            break;
      default: cout<<"\t\t\t Please enter correct option"<<endl;
      
      }
}

int main()
{

      int opt,rno;
      char ch;
      char pname[20];
       char option;
      system("cls");
      do
      {
            system("cls");
            cout << "Welcome to the Hotel Management System" << endl;
            cout << "\t\t ....................................." << endl;
            cout << "\t\t 1. Manage Room" << endl;
            cout << "\t\t 2. Check-In-Room" << endl;
            cout << "\t\t 3. Available Room" << endl;
            cout << "\t\t 4. Check-Out Room" << endl;
            cout << "\t\t 5. Search Customer" << endl;
            cout << "\t\t 6. Guest summary" << endl;
            cout << "\t\t 7.Exit" << endl;
            cout << "\t\t ....................................." << endl;
            cout << "\t\tEnter your option" << endl;
            cin >>opt;
            switch(opt)
            {

            case 1:
            

                  manage_room();
                  break;
            case 2:
                  if (cnt == 0)
                  {
                        cout << "\t\t ....................................." << endl;
                        cout << "\t\t No room available" << endl;
                        cout << "\t\t........................................" << endl;
                       // cout << "\t\t Press any key to continue..." << endl;
                       // getch();
                        break;
                  }
                  else
                  {

                        hm.check_in();
                  }
                  break;
            case 3:
                  if (cnt == 0)
                  {
                        cout << "\t\t Rooms data is not available .\n Please add the rooms first";
                       // cout << "\t\t Press any key to continue";
                       // getch();
                  }
                  else
                  {

                        hm.available_rooms();
                       
                  }
                   break;
            case 4:
            if(cnt==0)
            {
                  cout<<"\t\t Rooms data is not available .\n Please add the room first";
                  //cout<<"\t\t Press any key to continue";
                  //getch();
            }
            else
            {
                  cout<<"\t\t\t Enter the room number: ";
                  cin>>rno;
                  hm.check_out(rno);
            }
            break;

            case 5:
                  if (cnt == 0)
                  {
                        cout << "\t\t Rooms data is not available . \n Please add the rooms first. ";
                        //cout << "\t\t Enter any key to continue";
                       // getch();
                  }
                  else
                  {
                        cout << "\t\t\tEnter the name of customer: ";
                        cin >> pname;
                        hm.searchCustomer(pname);
                        
                  }
                  break;
            case 6:
               hm.guest_summary();
               break;
            case 7: cout<<"\t\t\t Thank you for using the system "<<endl;
                     break;
            default: cout<<"\t\t\t Please enter correct option "<<endl;
            break;

            
            }
      cout<<"Do you wish to continue if yes press y else n"<<endl;
     
      cin>>option;
      

      }while (option=='y');
      return 0;
}