#include<iostream>
#include<fstream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<queue>
#include<climits>
#include<cstring>
#include<unordered_set>
#include<stack>
#include<set>
using namespace std;
#include<conio.h>
#define _WIN32_WINNT 0x0500
#include<windows.h>
#include<time.h>

//Console Commands
COORD coord={45,13};
int row,col;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#define color(a) SetConsoleTextAttribute(hConsole,a);

/// To get the no. of rows and columns of the console screen
void GetScreenSize(int &row,int &col)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);
    col=csbi.srWindow.Right-csbi.srWindow.Left+1;
    row=csbi.srWindow.Bottom-csbi.srWindow.Top+1;
}

/// For Opening The console in Maximised mode
void Maximize(void)
{
    HWND consoleWindow=GetConsoleWindow();
    ShowWindow(consoleWindow,SW_MAXIMIZE);
}

/// For Restoring The console Size back to normal
void restore()
{
    HWND consoleWindow=GetConsoleWindow();
    ShowWindow(consoleWindow,SW_RESTORE);
}

void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//end of Console Commands


//Design section
void printFplanner(int c,int r)
{

gotoxy(c/2-81,r);color(7);  cout<<"::::::::::  :::         :::::::::::  ::::::::   :::    :::  :::::::::::      :::::::::   :::             :::      ::::    :::  ::::    :::  ::::::::::  :::::::::  "<<endl;Sleep(50);
gotoxy(c/2-81,r+1);color(7);cout<<":+:         :+:             :+:     :+:    :+:  :+:    :+:      :+:          :+:    :+:  :+:           :+: :+:    :+:+:   :+:  :+:+:   :+:  :+:         :+:    :+: "<<endl;Sleep(50);
gotoxy(c/2-81,r+2);color(7);cout<<"+:+         +:+             +:+     +:+         +:+    +:+      +:+          +:+    +:+  +:+          +:+   +:+   :+:+:+  +:+  :+:+:+  +:+  +:+         +:+    +:+ "<<endl;Sleep(50);
gotoxy(c/2-81,r+3);color(7);cout<<":#::+::#    +#+             +#+     :#:         +#++:++#++      +#+          +#++:++#+   +#+         +#++:++#++:  +#+ +:+ +#+  +#+ +:+ +#+  +#++:++#    +#++:++#:  "<<endl;Sleep(50);
gotoxy(c/2-81,r+4);color(7);cout<<"+#+         +#+             +#+     +#+   +#+#  +#+    +#+      +#+          +#+         +#+         +#+     +#+  +#+  +#+#+#  +#+  +#+#+#  +#+         +#+    +#+ "<<endl;Sleep(50);
gotoxy(c/2-81,r+5);color(7);cout<<"#+#         #+#             #+#     #+#    #+#  #+#    #+#      #+#          #+#         #+#         #+#     #+#  #+#   #+#+#  #+#   #+#+#  #+#         #+#    #+# "<<endl;Sleep(50);
gotoxy(c/2-81,r+6);color(7);cout<<"###         ##########  ###########  ########   ###    ###      ###          ###         ##########  ###     ###  ###    ####  ###    ####  ##########  ###    ### "<<endl;Sleep(50);

}

void printSearch()
{

gotoxy(col/2-27,1);color(10);cout<<"(  ____ \\(  ____ \\(  ___  )(  ____ )(  ____ \\|\\     /|"<<endl;Sleep(50);
gotoxy(col/2-27,2);color(10);cout<<"| (    \\/| (    \\/| (   ) || (    )|| (    \\/| )   ( |"<<endl;Sleep(50);
gotoxy(col/2-27,3);color(10);cout<<"| (_____ | (__    | (___) || (____)|| |      | (___) |"<<endl;Sleep(50);
gotoxy(col/2-27,4);color(10);cout<<"(_____  )|  __)   |  ___  ||     __)| |      |  ___  |"<<endl;Sleep(50);
gotoxy(col/2-27,5);color(10);cout<<"      ) || (      | (   ) || (\\ (   | |      | (   ) |"<<endl;Sleep(50);
gotoxy(col/2-27,6);color(10);cout<<"/\\____) || (____/\\| )   ( || ) \\ \\__| (____/\\| )   ( |"<<endl;Sleep(50);
gotoxy(col/2-27,7);color(10);cout<<"\\_______)(_______/|/     \\||/   \\__/(_______/|/     \\|"<<endl;Sleep(50);




}

void printBook(int c,int r,int a)
{
    gotoxy(c/2-34,r++);color(7);cout<<",-----.   ,-----.  ,-----. ,--. ,--.    ,--.  ,--. ,-----. ,--.   ,--."<<endl;Sleep(a);
    gotoxy(c/2-34,r++);color(7);cout<<"|  |) /_ '  .-.  ''  .-.  '|  .'   /    |  ,'.|  |'  .-.  '|  |   |  |"<<endl;Sleep(a);
    gotoxy(c/2-34,r++);color(7);cout<<"|  .-.  \\|  | |  ||  | |  ||  .   '     |  |' '  ||  | |  ||  |.'.|  |"<<endl;Sleep(a);
    gotoxy(c/2-34,r++);color(7);cout<<"|  '--' /'  '-'  ''  '-'  '|  |\\   \\    |  | `   |'  '-'  '|   ,'.   |"<<endl;Sleep(a);
    gotoxy(c/2-34,r++);color(7);cout<<"`------'  `-----'  `-----' `--' '--'    `--'  `--' `-----' '--'   '--'"<<endl;Sleep(a);
}
void printMagnify()
{

color(6);cout<<"                  %%@@@@@@#"<<endl;Sleep(50);
color(6);cout<<"              @&              &@"<<endl;Sleep(50);
color(6);cout<<"           @%                    &@"<<endl;Sleep(50);
color(6);cout<<"         #&                        @("<<endl;Sleep(50);
color(6);cout<<"       .@*                          (%"<<endl;Sleep(50);
color(6);cout<<"       .@                            @"<<endl;Sleep(50);
color(6);cout<<"       *@ .&                         &*"<<endl;Sleep(50);
color(6);cout<<"       *@  @                         @"<<endl;Sleep(50);
color(6);cout<<"        @* .@                       (%"<<endl;Sleep(50);
color(6);cout<<"         #&  @/                    @/"<<endl;Sleep(50);
color(6);cout<<"           @@  *@(               &@ @*"<<endl;Sleep(50);
color(6);cout<<"              @@     ,(.      @@#    @&@"<<endl;Sleep(50);
color(6);cout<<"                  .(@@@@@@(      *@@     @*"<<endl;Sleep(50);
color(6);cout<<"                                    @#     #@"<<endl;Sleep(50);
color(6);cout<<"                                      *@      @*"<<endl;Sleep(50);
color(6);cout<<"                                         @#     #@"<<endl;Sleep(50);
color(6);cout<<"                                           *@      @,"<<endl;Sleep(50);
color(6);cout<<"                                              @#  (@"<<endl;Sleep(50);
color(6);cout<<"                                                ,*"<<endl;Sleep(50);
}
void PrintProfile(int c,int r,int a)
{


gotoxy(c/2-42,r++);color(7);cout<<".88b  d88. db    db      d8888b. d8888b.  .d88b.  d88888b d888888b db      d88888b"<<endl;Sleep(a);
gotoxy(c/2-42,r++);color(7);cout<<"88'YbdP`88 `8b  d8'      88  `8D 88  `8D .8P  Y8. 88'       `88'   88      88'"<<endl;Sleep(a);
gotoxy(c/2-42,r++);color(7);cout<<"88  88  88  `8bd8'       88oodD' 88oobY' 88    88 88ooo      88    88      88ooooo"<<endl;Sleep(a);
gotoxy(c/2-42,r++);color(7);cout<<"88  88  88    88         88~~~   88`8b   88    88 88~~~      88    88      88~~~~~"<<endl;Sleep(a);
gotoxy(c/2-42,r++);color(7);cout<<"88  88  88    88         88      88 `88. `8b  d8' 88        .88.   88booo. 88."<<endl;Sleep(a);
gotoxy(c/2-42,r++);color(7);cout<<"YP  YP  YP    YP         88      88   YD  `Y88P'  YP      Y888888P Y88888P Y88888P"<<endl;Sleep(a);

}

void printFlight(int a)
{
gotoxy(col/2-35,row/2-7);cout<<"                      %%%%%%%%%%%#"<<endl;Sleep(a);
gotoxy(col/2-35,row/2-6);cout<<"                       ,%%*      (%%%#."<<endl;Sleep(a);
gotoxy(col/2-35,row/2-5);cout<<"                         %%%         *%%%%."<<endl;Sleep(a);
gotoxy(col/2-35,row/2-4);cout<<"   //%%%%%%%.              ,%%*           *%%%%,"<<endl;Sleep(a);
gotoxy(col/2-35,row/2-3);cout<<"    %%*   (%%#            ..%%%////(#%%%%%%%%%%%%%%%%%%%%%%%%%%%%."<<endl;Sleep(a);
gotoxy(col/2-35,row/2-2);color(6);cout<<"     %%      %%%%%%%%%%%%%##(//*.                             *%%%"<<endl;Sleep(a);
gotoxy(col/2-35,row/2-1);color(7);cout<<"     //%%                                                       (%%%."<<endl;Sleep(a);
gotoxy(col/2-35,row/2);color(7);cout<<"      #%%                         %%%%(  %%%%  %%%%// *%%%%%%%%%%  (%%#"<<endl;Sleep(a);
gotoxy(col/2-35,row/2+1);color(8);cout<<"       %%,                                                          .%%"<<endl;Sleep(a);
gotoxy(col/2-35,row/2+2);color(8);cout<<"       .%%%%%%%%%%%%%%%%%####(*                                   .(%%%."<<endl;Sleep(a);
gotoxy(col/2-35,row/2+3);color(9);cout<<"                           (%%(              //%%%%%%%%%%%%%%%%%%%%#,"<<endl;Sleep(a);
gotoxy(col/2-35,row/2+4);color(10);cout<<"                         #%%,            ,%%%%."<<endl;Sleep(a);
gotoxy(col/2-35,row/2+5);color(11);cout<<"                       %%%.           %%%%,"<<endl;Sleep(a);
gotoxy(col/2-35,row/2+6);color(11);cout<<"                     %%%          (%%%("<<endl;Sleep(a);
gotoxy(col/2-35,row/2+7);color(12);cout<<"                  .%%%        ,%%%%"<<endl;Sleep(a);
gotoxy(col/2-35,row/2+8);color(12);cout<<"                //%%#       %%%%"<<endl;Sleep(a);
gotoxy(col/2-35,row/2+9);color(13);cout<<"                .**********,"<<endl;Sleep(a);

}

//end of Design section


    vector<string>city={"Mumbai","Delhi","New York","Chicago","Paris","London","Kolkata","Houston","Beijing","Tokyo","Sydney","Moscow","Toronto","Seoul","Singapore"
    ,"Dubai","Berlin","Auckland","CapeTown","Barcelona","Hong Kong","Bangkok","Rome","Amsterdam","Vienna","Shanghai","Prague",
    "San Fransico","Budapest","Abu Dhabi","Washington D.C","Doha","Karachi","Istanbul","Las Vegas"};

class Flight {
	char flightName[20];
	int flightNo;
	char from[20];
	char to[20];
	int cost;
	int duration;
public:

	Flight(){}
	void input()
	{
	    cout<<"Flight Name : ";cin>>flightName;
	    cout<<"Flight Number : ";cin>>flightNo;
	    cout<<"from : ";cin>>from;
	    cout<<"to : ";cin>>to;
	    cout<<"cost : ";cin>>cost;
	    cout<<"duration : ";cin>>duration;
	}

    void entry(string name, int no,string from, string to, int cost, int duration)
    {
        strcpy(this->flightName,name.c_str());
		this->flightNo=no;
		strcpy(this->from,from.c_str());
        strcpy(this->to,to.c_str());
		this->cost=cost;
        this->duration=duration;
    }

	void output(int c,int r)
	{
	    gotoxy(c,r);cout<<"Flight Name : "<<flightName;
	    gotoxy(c,r+1);cout<<"Flight Number : "<<flightNo;
	    gotoxy(c,r+2);cout<<"from : "<<from;
	    gotoxy(c,r+3);cout<<"to : "<<to;
	    gotoxy(c,r+4);cout<<"cost : "<<cost;
	    gotoxy(c,r+5);cout<<"duration : "<<duration;

	}

	string getName()
	{
	    return (string)flightName;
	}

	int getFlightNo()
	{
	    return flightNo;
	}

	string getFrom()
	{
	    return (string)from;
	}

	string getTo()
	{
	    return (string)to;
	}

	int getCost()
	{
	    return cost;
	}

	int getDuration()
	{
	    return duration;
	}
};
unordered_map<string,vector<Flight>> graph;
unordered_map<int,Flight>flight;
unordered_set<string> cities;
pair<int,vector<Flight>> shortestPathCost(string src,string dest);
pair<int,vector<Flight>> shortestPathTime(string src,string dest);

void dInsert(int arr[],int &n,int &s,int data)
{
    if(n!=15) n++;
    arr[(s+1)%n]=data;
    s=(s+1)%n;

}

void dPrint(int arr[],int &s,int &n)
{
    system("cls");
    gotoxy(8,2);cout<<"Your Flight History : ";
    int j=4;
    for(int i=s;i>=0;i--){
        flight[arr[i]].output(8,j);j+=8;
    }
    for(int i=n-1;i>s;i--){
        flight[arr[i]].output(8,j);j+=8;
    }

}

class Passenger {

	char name[20];
	char password[20];
	char aadharNo[20];
	char phone[10];
	char address[40];
	char passportNo[20];
	char dob[10];
	int history[15];
	int n;
	int s; // deque start pointer
	int discount;
public:

	Passenger()
	{
	    n=0;
	    discount=0;
	    s=-1;
    }

	void input(int c,int r)
	{
	    gotoxy(c/2-12,r/2-4);cout<<"Enter Name : ";cin>>name;
	    gotoxy(c/2-12,r/2-3);cout<<"Password :";cin>>password;
	    gotoxy(c/2-12,r/2-2);cout<<"Aadhar Number : ";cin>>aadharNo;
	    gotoxy(c/2-12,r/2-1);cout<<"Phone : ";cin>>phone;
	    gotoxy(c/2-12,r/2);cout<<"Address : ";cin>>address;
	    gotoxy(c/2-12,r/2+1);cout<<"Passport Number : ";cin>>passportNo;
	    gotoxy(c/2-12,r/2+2);cout<<"Date Of Birth : ";cin>>dob;
	}

	void output(int c,int r)
	{
        gotoxy(c/2-12,r/2-3);cout<<"Name : "<<name;
	    gotoxy(c/2-12,r/2-2);cout<<"Aadhar Number : "<<aadharNo;
	    gotoxy(c/2-12,r/2-1);cout<<"Phone : "<<phone;
	    gotoxy(c/2-12,r/2);cout<<"Address : "<<address;
	    gotoxy(c/2-12,r/2+1);cout<<"Passport Number : "<<passportNo;
	    gotoxy(c/2-12,r/2+2);cout<<"Date Of Birth : "<<dob;
	}

	void travel_history(){
        dPrint(history,s,n);
	}

	bool checkPass(string password)
	{
	    return strcmp(this->password,password.c_str());
	}

	bool checkName(string name)
	{
	    return strcmp(this->name,name.c_str());
	}

	string getName()
	{
	    return (string)name;
	}

	string getPassword()
	{
	    return (string)password;
	}

	void showBooked(pair<int,vector<Flight>>path,string src,string dest,int discount,int cost,int duration)
	{
	    system("cls");
	    printBook(col,1,0);
	    gotoxy(col/2-13,7);cout<<"Your Flight Details are : ";
        gotoxy(col/2-13,9);cout<<"Total Cost : "<<cost-discount;
        gotoxy(col/2-13,10);cout<<"Total Duration : "<<duration;
	    int j=12;
	    for(auto&i:path.second)
            {i.output(col/2-13,j);j+=8;}
        _getch();
	}

	void book(string src,string dest,bool ret)
	{
	    system("cls");

        printBook(col,1,1);

	    char x;
	    int duration=0,cost=0;

        pair<int,vector<Flight>>minPath;
        int redeemed=0;

	    do
	    {
	        printBook(col,1,0);
            gotoxy(col/2-20,row/2+2);cout<<"What matters more to you Time or Money?(t/m) : ";cin>>x;
	        if(x=='t') {
                    minPath=shortestPathTime(src,dest);
                    duration=minPath.first;
                    for(auto&i:minPath.second)cost+=i.getCost();
	        }
            else if(x=='m') {
                    minPath=shortestPathCost(src,dest);
                    cost=minPath.first;
                for(auto&i:minPath.second)duration+=i.getDuration();
            }

            else
            {
                gotoxy(col/2-9,row/2+4);
                cout<<"It looks like enjoyment matters more to you.(Press either t or m)";
                system("cls");
            }

        }while(x!='t' && x!='m');

	    auto booked=[&](){
	        system("cls");
	        printBook(col,1,0);
            gotoxy(col/2-27,row/2-1);cout<<"WooHoo! You are all set to go"<<'\n';
            gotoxy(col/2-27,row/2);cout<<"Congratulations! You have received a discount coupon of "<<cost*0.05;
            discount+=cost*0.05;
            for(auto &i:minPath.second)
                dInsert(history,n,s,i.getFlightNo());
                _getch();

	    };

	    auto bookreturn=[&]()
	    {

	        system("cls");
            char chc;
            if(ret==1){
                gotoxy(col/2-27,row/2-1);cout<<"Do You want To Book Return Flight? (y/n) : ";cin>>chc;
                do{
                    if(chc=='y' || chc=='Y')
                        book(dest,src,0);
                    else if(chc=='n' || chc=='N');
                }
                while(chc!='n' && chc!='N' && chc!='y' && chc!='Y');
            }
	    };

	    if(minPath.first!=-1)
        {
            system("cls");
            printBook(col,1,0);
            int j=12;
            gotoxy(col/2-6,10);cout<<"Best Route : ";
            for(auto &i:minPath.second)
                {i.output(col/2-9,j);j+=10;}
            gotoxy(col/2-24,8);cout<<"Do You Want To Book the Following Flights (y/n) : ";
            char c;
            cin>>c;
            if(c=='y' || c=='Y')
            {
                if(!discount)
                {
                    booked();
                }
                else
                {
                    system("cls");
                    printBook(col,1,0);
                    gotoxy(col/2-24,row/2-1);cout<<"Do You Want To Redeem Your Discount Coupon (y/n) : ";
                    char ch;
                    cin>>ch;
                    if(ch=='y'){
                        redeemed=min(cost,discount);
                        discount-=redeemed;
                        booked();
                    }
                    else booked();
                }
                showBooked(minPath,src,dest,redeemed,cost,duration);
                if(ret==1)bookreturn();
            }
            else {system("cls");gotoxy(col/2-8,row/2);cout<<"Booking Canceled!";}
	    }
	    else
        {   system("cls");
            printBook(col,1,0);
            gotoxy(col/2-17-src.length()/2-dest.length()/2,row/2-1);cout<<"There are No Flights Between "<<src<<" and "<<dest<<endl;
        }
	}

	void book_util()
	{
	    system("cls");
	    printBook(col,1,1);
        string src,dest;
        gotoxy(col/2-15,row/2-1);cout<<"Enter Source City : ";
	    cin>>src;

	    gotoxy(col/2-20,row/2);cout<<"Enter Destination City : ";
	    cin>>dest;
	    book(src,dest,1);
	}
};



bool login(Passenger&p,fstream&file)
{
    file.seekg(0,ios::beg);
    bool loggedin=false;
    Passenger temp;
    string name ,password;
    system("cls");
    gotoxy(col/2-9,row/2-1);cout<<"Enter Name : ";cin>>name;
    gotoxy(col/2-9,row/2);cout<<"Enter Password : ";cin>>password;
    while(file.read((char*)&temp,sizeof(temp)))
    {
        if(!temp.checkName(name) && !temp.checkPass(password))
        {
            p=temp;loggedin=true;
            break;
        }
    }
    return loggedin;
}


void signup(fstream&file)
{
    system("cls");
    Passenger p;
    p.input(col,row);
    system("cls");

    gotoxy(col/2-8,row/2);cout<<"Signing You Up";
    for(int i=0;i<5;i++)
    {
        Sleep(400);cout<<".";
    }
    system("cls");

    if(file.write((char*)&p,sizeof(p))) {gotoxy(col/2-12,row/2-5);cout<<"Successfully Signed Up!";}
    p.output(col,row);
    _getch();
    system("cls");
}

bool logout(fstream &f1,Passenger &p1)
{
    f1.seekg(0);
    Passenger temp;
    while(f1.read((char*)&temp,sizeof(temp)))
    {
         if(!p1.checkName(temp.getName()) && !p1.checkPass(temp.getPassword()))
            break;
    }
    int pos=f1.tellg();
    f1.seekp(pos-sizeof(p1),ios::beg);
    if(f1.write((char*)&p1,sizeof(p1)))
        {return 1;}
    return 0;
}


//void dfs(string name,unordered_map<string,vector<Flight>>&graph,unordered_map<string,bool> &visited)
//{
//    visited[name]=true;
//    for(auto&i:graph[name]){
//        if(!visited[i.getTo()])
//            dfs(i.getTo(),graph,visited);
//    }
//    return;
//}
//
//void dfs_util(unordered_map<string,vector<Flight>>&graph)
//{
//    unordered_map<string,bool>visited;
//    int k=0;
//    for(auto&i:graph)
//    {
//        if(!visited[i.first]){
//            dfs(i.first,graph,visited);
//            k++;
//        }
//    }
//    cout<<"Disconnected Components : "<<k<<endl;
//}

pair<int,vector<Flight>> shortestPathCost(string src,string dest)
{
    if(cities.find(src)==cities.end() || cities.find(dest)==cities.end()) return {-1,vector<Flight>()};
    unordered_map<string,int>dist;
    unordered_map<string,Flight>parent;
    dist[src]=0;
    set<pair<int,string>>s;
    s.insert({0,src});
    while(!s.empty())
    {
        pair<int,string>t=*(s.begin());
        s.erase(s.begin());
        string fromCity=t.second;
        for(auto&f:graph[t.second])
        {
            string toCity=f.getTo();
            if(dist[toCity]==0)dist[toCity]=INT_MAX;

            if(dist[toCity]>dist[fromCity]+f.getCost()){
                 if(s.find({dist[toCity],toCity})!=s.end()){
                     s.erase({dist[toCity],toCity});
                 }
                 dist[toCity]=dist[fromCity]+f.getCost();
                 s.insert({dist[toCity],toCity});
                 parent[toCity]=f;
            }
        }
    }
   vector<Flight>st;
    string temp=dest;
    while(parent[dest].getFrom()!=src){
        st.push_back(parent[dest]);
        dest=parent[dest].getFrom();
    }
    st.push_back(parent[dest]);
    reverse(st.begin(),st.end());

    return {dist[temp]?dist[temp]:-1,st};
}

pair<int,vector<Flight>> shortestPathTime(string src,string dest)
{
    if(cities.find(src)==cities.end() || cities.find(dest)==cities.end()) return {-1,vector<Flight>()};
    unordered_map<string,int>dist;
    unordered_map<string,Flight>parent;
    dist[src]=0;
    set<pair<int,string>>s;
    s.insert({0,src});
    while(!s.empty())
    {
        pair<int,string>t=*(s.begin());
        s.erase(s.begin());
        string fromCity=t.second;
        for(auto&f:graph[t.second])
        {
            string toCity=f.getTo();
            if(dist[toCity]==0)dist[toCity]=INT_MAX;

            if(dist[toCity]>dist[fromCity]+f.getDuration()){
                 if(s.find({dist[toCity],toCity})!=s.end()){
                     s.erase({dist[toCity],toCity});
                 }
                 dist[toCity]=dist[fromCity]+f.getDuration();
                 s.insert({dist[toCity],toCity});
                 parent[toCity]=f;
            }
        }

    }
    vector<Flight>st;
    string temp=dest;
    while(parent[dest].getFrom()!=src){
        st.push_back(parent[dest]);
        dest=parent[dest].getFrom();
    }
    st.push_back(parent[dest]);
    reverse(st.begin(),st.end());
    return {dist[temp]?dist[temp]:-1,st};
}

void search_flights()
{
    string src,dest;
    printSearch();
    for(int i=0;i<col;i++){
            gotoxy(i,8);cout<<"-";Sleep(5);
    }
    gotoxy(col/2-12,row/2-1);cout<<"Enter Source : ";
    cin>>src;
    gotoxy(col/2-12,row/2+1);cout<<"Enter Destination : ";
    cin>>dest;

    pair<int,vector<Flight>>path1=shortestPathCost(src,dest);
    pair<int,vector<Flight>>path2=shortestPathTime(src,dest);

    system("cls");
    for(int j=0;j<2;j++){
       string sear="Searching for Best Flights ...";
       for(int i=0;i<sear.length();i++) {
            gotoxy(col/2-10+i,row/2-1);cout<<sear[i];
            Sleep(40);
       }
        Sleep(100);
        for(int i=0;i<sear.length();i++)
        {
            gotoxy(col/2-10+i,row/2-1);cout<<" ";
            Sleep(40);
        }
    }
    printSearch();
    for(int i=0;i<col;i++){
            gotoxy(i,8);cout<<"-";Sleep(5);
    }
    color(7);

    int j=12;
    if(path1.first!=-1){
        gotoxy(col/4-9,10);cout<<"Cheapest Route :-\n";
        for(auto &i:path1.second){
            i.output(col/4-9,j);
            Sleep(10);
            j+=7;
        }
        j=12;
        gotoxy(3*col/4-9,10);cout<<"Fastest Route :-\n";
        for(auto &i:path2.second){
            i.output(3*col/4-9,j);Sleep(10);
            j+=7;
        }

        for(int i=9;i<row;i++){
            gotoxy(col/2,i);
            cout<<"|";Sleep(1);
        }
    }
    else{
            system("cls");
        gotoxy(col/2-17-src.length()/2-dest.length()/2,row/2-1);cout<<"There are No Flights Between "<<src<<" and "<<dest<<endl;
        return;
    }

}


void welcome()
{
    system("cls");
    string wel="Welcome Folks!";
    for(int i=0;i<wel.length();i++){
        gotoxy(col/2-7+i,2);cout<<wel[i];Sleep(100);
    }
    printFlight(80);

    Sleep(400);
    for(int i=0;i<2;i++)
    {
        string load=". . . . . . . .";
        for(int j=0;j<load.length();j++)
        {
            gotoxy(col/2-6+j,row-4);cout<<load[j];Sleep(80);
        }
        for(int j=0;j<load.length();j++)
        {
            gotoxy(col/2-6+j,row-4);cout<<" ";Sleep(80);
        }


    }

}


int main()
{
    Maximize();
    GetScreenSize(row,col);

    welcome();
    for(auto&cty:city)cities.insert(cty);
    vector<Passenger> psngrs;
    Passenger p;
    int ch;
    fstream file,file2;
    Flight ff;
    file2.open("Flights.dat",ios::in|ios::binary);
    while(file2.read((char*)&ff,sizeof(ff)))
    {
        flight[ff.getFlightNo()]=ff;
        graph[ff.getFrom()].push_back(ff);
    }

//    for(auto&i:graph)
//    {
//        cout<<i.first<<" : "<<endl;
//        for(auto&j:i.second) j.output();
//        cout<<endl<<endl;
//    }

//    cout<<shortestPath(graph,"Sydney","Chicago");

//    dfs_util(graph);
    file.open("passenger.dat",ios::app|ios::in|ios::binary);
    do{
        system("cls");
        printFplanner(col,1);
        gotoxy(col/2-3,row/2-2);cout<<"1.Signup ";
        gotoxy(col/2-3,row/2-1);cout<<"2.Login  ";
        gotoxy(col/2-3,row/2);cout<<"3.Exit  ";
        gotoxy(col/2-3,row/2+1);cout<<"Enter Choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:signup(file);break;
            case 2:if(login(p,file)){
                int c=5;
                do{
                    system("cls");
                    printFplanner(col,1);
                    gotoxy(col/2-10,row/2-2);cout<<"1.Show my Profile";
                    gotoxy(col/2-10,row/2-1);cout<<"2.Search Flights";
                    gotoxy(col/2-10,row/2);cout<<"3.Book Flight";
                    gotoxy(col/2-10,row/2+1);cout<<"4.Travel History";
                    gotoxy(col/2-10,row/2+2);cout<<"5.Logout";

                    gotoxy(col/2-10,row/2+4);cout<<"Enter Your Choice : ";

                    cin>>c;
                    switch(c){
                        case 1:
                            system("cls");
                            PrintProfile(col,1,1);
                            p.output(col,row);
                            _getch();
                            break;
                        case 2:
                            system("cls");
                            search_flights();
                            _getch();
                            break;
                        case 3:
                            p.book_util();
                            _getch();
                            break;
                        case 4:
                            p.travel_history();
                            _getch();
                            break;
                        case 5:file.close();file.open("passenger.dat",ios::out|ios::in|ios::binary);
                                if(logout(file,p))
                                {system("cls");gotoxy(col/2-11,row/2-1);cout<<"Logged out successfully\n";_getch();}file.close();
                                file.open("passenger.dat",ios::app|ios::in|ios::binary);
                        case 6:
                            break;
                        default:gotoxy(col/2-8,row/2-2);cout<<"Invalid Choice";

                    }
                }
                while(c!=5);
            }
            else{
                    system("cls");
            gotoxy(col/2-6,row/2-1);
                cout<<"Login Failed ";
                _getch();
                file.clear();
            }
            break;
//            cout<<"enter";

        }
    }while(ch!=3);

    return 0;
}
