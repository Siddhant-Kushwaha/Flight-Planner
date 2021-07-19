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
void printBook()
{

color(6);cout<<",-----.   ,-----.  ,-----. ,--. ,--.    ,--.  ,--. ,-----. ,--.   ,--."<<endl;Sleep(50);
color(6);cout<<"|  |) /_ '  .-.  ''  .-.  '|  .'   /    |  ,'.|  |'  .-.  '|  |   |  |"<<endl;Sleep(50);
color(6);cout<<"|  .-.  \\|  | |  ||  | |  ||  .   '     |  |' '  ||  | |  ||  |.'.|  |"<<endl;Sleep(50);
color(6);cout<<"|  '--' /'  '-'  ''  '-'  '|  |\\   \\    |  | `   |'  '-'  '|   ,'.   |"<<endl;Sleep(50);
color(6);cout<<"`------'  `-----'  `-----' `--' '--'    `--'  `--' `-----' '--'   '--'"<<endl;Sleep(50);





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
//end of Design section
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

	void output()
	{
	    cout<<"Flight Name : "<<flightName<<'\n';
	    cout<<"Flight Number : "<<flightNo<<'\n';
	    cout<<"from : "<<from<<'\n';
	    cout<<"to : "<<to<<'\n';
	    cout<<"cost : "<<cost<<'\n';
	    cout<<"duration : "<<duration<<'\n';

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
    for(int i=s;i>=0;i--)cout<<arr[i]<<" ";
    for(int i=n-1;i>s;i--)cout<<arr[i]<<" ";
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
        gotoxy(c/2-12,r/2-3);cout<<"Enter Name : "<<name;
	    gotoxy(c/2-12,r/2-2);cout<<"Aadhar Number : "<<aadharNo;
	    gotoxy(c/2-12,r/2-1);cout<<"Phone : "<<phone;
	    gotoxy(c/2-12,r/2);cout<<"Address : "<<address;
	    gotoxy(c/2-12,r/2+1);cout<<"Passport Number : "<<passportNo;
	    gotoxy(c/2-12,r/2+2);cout<<"Date Of Birth : "<<dob;
	}

	bool checkPass(char password[20])
	{
	    return strcmp(this->password,password);
	}

	bool checkName(char name[20])
	{
	    return strcmp(this->name,name);
	}

	void showBooked(pair<int,vector<Flight>>path,string src,string dest,int discount)
	{
	    cout<<"Your Flight Details are : "<<endl;

	    for(auto&i:path.second)
            i.output();
        if(discount!=0)
            cout<<"Total Cost : "<<path.first-discount;
	}

	void book()
	{   string src,dest;
	    char x;
	    cout<<"Enter Source City : ";
	    cin>>src;
	    cout<<"Enter Destination City : ";
	    cin>>dest;
	    cout<<"What matters more to you Time or Money?(Press t for Time and m for Money) : \n";
        pair<int,vector<Flight>>minPath;
        int redeemed=0;
	    do
	    {   cin>>x;
	        if(x=='t')
            {
                minPath=shortestPathTime(src,dest);
            }
            else if(x=='m')
            {
                minPath=shortestPathCost(src,dest);
            }
            else
            {
                cout<<"It looks like enjoyment matters more to you.(Press either t or m)"<<'\n';
            }
	    }while(x=='t'||x=='m');

	    auto booked=[&](){
            cout<<"\nWooHoo! You are all set to go\n";
            cout<<"Congratulations! You have received a discount coupon of "<<minPath.first*0.05;
            discount+=minPath.first*0.05;
            for(auto &i:minPath.second){
                dInsert(history,n,s,i.getFlightNo());
            }
	    };

	    if(minPath.first!=-1)
        {
            for(auto &i:minPath.second)
                i.output();
            cout<<"Do You Want To Book These Flights (y/n) : ";
            char c;
            cin>>c;
            if(c=='y' || 'Y')
            {
                if(!discount)
                {
                    booked();
                }
                else
                {
                    cout<<"Do You Want To Redeem Your Discount Coupon (y/n) : ";
                    char ch;
                    cin>>ch;
                    if(ch=='y'){
                        redeemed=discount;
                        discount=0;
                        booked();
                    }
                    else booked();
                }

                showBooked(minPath,src,dest,redeemed);
            }
            else cout<<"Booking Canceled!";
	    }
	}
};



bool login(Passenger&p,fstream&file)
{
    file.seekg(0,ios::beg);
    bool loggedin=false;
    Passenger temp;
    char name[20];
    char password[20];
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
    _getch();
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

    if(file.write((char*)&p,sizeof(p)))
        gotoxy(col/2-12,row/2-5);cout<<"Successfully Signed Up!";
    p.output(col,row);
    _getch();
    system("cls");
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

pair<int,vector<Flight>> shortestPathCost(unordered_map<string,vector<Flight>>&graph,string src,string dest)
{
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

    return {dist[temp],st};
}

pair<int,vector<Flight>> shortestPathTime(unordered_map<string,vector<Flight>>&graph,string src,string dest)
{
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
    return {dist[temp],st};
}

int main()
{
     Maximize();
    GetScreenSize(row,col);

    vector<Passenger> psngrs;
    Passenger p;
    int ch;
    fstream file,file2;
    Flight ff;
    printFplanner(col,1);
    file2.open("Flights.dat",ios::in|ios::binary);
    while(file2.read((char*)&ff,sizeof(ff)))
    {
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
        gotoxy(col/2-3,row/2-2);cout<<"1.Signup ";
        gotoxy(col/2-3,row/2-1);cout<<"2.Login  ";
        gotoxy(col/2-3,row/2);cout<<"3.Exit  ";
        gotoxy(col/2-3,row/2+1);cout<<"Enter Choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:signup(file);break;
            case 2:if(login(p,file)){
                cout<<endl;
                p.output(col,row);
                cout<<"1.Show my Profile";
                cout<<"2.Search Flights";
                cout<<"3.Book Flight";
                cout<<"4.Travel History";
                break;
            }
            cout<<"enter";

        }
    }while(ch!=3);

}
