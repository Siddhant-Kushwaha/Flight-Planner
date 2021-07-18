#include<bits/stdc++.h>
using namespace std;
class Flight {
	char flightName[200];
	int flightNo;
	char from[200];
	char to[200];
	int cost;
	int duration;
public:

	Flight(){}
    Flight(string name, int no,string from, string to, int cost, int duration)
	{		strcpy(this->flightName,name.c_str());
		this->flightNo=no;
		strcpy(this->from,from.c_str());
	      strcpy(this->to,to.c_str());
		this->cost=cost;
	this->duration=duration;
}
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
};

int main()
{
    fstream file;
    file.open("Flights.dat",ios::app|ios::in|ios::binary);
    vector<string>city={"Mumbai","Delhi","New York","Chicago","Paris","London","Kolkata","Houston","Beijing","Tokyo","Sydney","Moscow","Toronto","Seoul","Singapore"
    ,"Dubai","Berlin","Auckland","CapeTown","Barcelona","Hong Kong","Bangkok","Rome","Amsterdam","Vienna","Shanghai","Prague",
    "San Fransico","Budapest","Abu Dhabi","Washington D.C","Doha","Karachi","Istanbul","Las Vegas"};
    vector<string>Airways={"IndiGo","Air India",
"SpiceJet",
"GoAir",
"AirAsia",
"Vistara",
"Alliance Air",
"TruJet",
"Etihad Airways",
"Emirates",
"Lufthansa",
"Aegean Airlines",
"Qatar Airways",
"Jet Airways",
"Kingfisher"
};

srand(time(0));
int x,y,a,fno=1000,mn;
int c;

Flight f;
for(int i=0;i<1000;i++)
{
    x=rand()%city.size();
    y=rand()%city.size();
    while(y==x)
    {
        y=rand()%city.size();

    }
    a=rand()%Airways.size();
    c=(rand()%211)+40;
    c*=100;
    mn=rand()%241+120;
    f.entry(Airways[a],fno,city[x],city[y],c,mn);
    fno++;
    file.write((char*)&f,sizeof(f));
}
file.seekg(0,ios::beg);
while(file.read((char*)&f,sizeof(f)))
{
    f.output();
    cout<<'\n';

}

}
