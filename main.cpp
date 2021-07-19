#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<string>
#include<fstream>
#include<cstring>
#include<set>
#include<stack>

using namespace std;

unordered_map<string,vector<Flight>> graph;

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
	int discount;
public:
//	Passenger(char name[20],char aadharNo[20],char phone[10],char address[40],char passportNo[20],char dob[10])
//	{
//        strcpy(this->name,name);
//        strcpy(this->aadharNo,aadharNo);
//        strcpy(this->phone,phone);
//        strcpy(this->address,address);
//        strcpy(this->passportNo,passportNo);
//        strcpy(this->dob,dob);
//	}

	Passenger()
	{
	    n=0;
    }

	void input()
	{
	    cout<<"Enter Name : ";cin>>name;
	    cout<<"Password :";cin>>password;
	    cout<<"Aadhar Number : ";cin>>aadharNo;
	    cout<<"Phone : ";cin>>phone;
	    cout<<"Address : ";cin>>address;
	    cout<<"Passport Number : ";cin>>passportNo;
	    cout<<"Date Of Birth : ";cin>>dob;
	}

	void output()
	{
        cout<<"\nName : "<<name;
	    cout<<"\nAadhar Number : "<<aadharNo;
	    cout<<"\nPhone : "<<phone;
	    cout<<"\nAddress : "<<address;
	    cout<<"\nPassport Number : "<<passportNo;
	    cout<<"\nDate Of Birth : "<<dob;
	}

	bool checkPass(char password[20])
	{
	    return strcmp(this->password,password);
	}

	bool checkName(char name[20])
	{
	    return strcmp(this->name,name);
	}
	void book()
	{   string src,dest;
	    char x;
	    cout<<"Enter Source City : ";
	    cin>>src;
	    cout<<"Enter Destination City : ";
	    cin>>dest;
	    cout<<"What matters more to you Time or Money?(Press t for Time and m for Money) : \n";

	    do()
	    { cin>>x;
	        if(x=='t')
        {
            ShortestPathTime(src,dest);
        }
        else if(x=='m')
        {
            ShortestPathCost(src,dest);
        }
        else
        {
            cout<<"It looks like enjoyment matters more to you.(Press either t or m)"<<'\n';
        }
	    }while(x=='t'||x=='m')
	}
};

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

bool login(Passenger&p,fstream&file)
{
    file.seekg(0,ios::beg);
    bool loggedin=false;
    Passenger temp;
    char name[20];
    char password[20];
    cout<<"\nEnter Name : ";cin>>name;
    cout<<"\nEnter Password : ";cin>>password;
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


void signup(fstream&file){
  Passenger p;
  p.input();
  p.output();
  if(file.write((char*)&p,sizeof(p)))
    cout<<"successfully signed up";
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

int shortestPath(unordered_map<string,vector<Flight>>&graph,string src,string dest)
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
    stack<Flight>st;
    string temp=dest;
    while(parent[dest].getFrom()!=src){
        st.push(parent[dest]);
        dest=parent[dest].getFrom();
    }
    st.push(parent[dest]);
    while(!st.empty()){
        st.top().output();cout<<endl;
        st.pop();
    }
    return dist[temp];
}


int main()
{
    vector<Passenger> psngrs;
    Passenger p;
    int ch;
    fstream file,file2;
    Flight ff;

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

//    cout<<shortestPath(graph,"Karachi","Chicago");

//    dfs_util(graph);
    file.open("passenger.dat",ios::app|ios::in|ios::binary);
    do{
        cout<<"1.Signup\n ";
        cout<<"2.Login \n ";
        cout<<"3.Exit \n ";
        cout<<"Enter Choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:signup(file);break;
            case 2:if(login(p,file)){
                cout<<endl;
                p.output();
                break;
            }
            cout<<"enter";

        }
    }while(ch!=3);

}
