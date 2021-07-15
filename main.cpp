#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<string>
#include<fstream>

using namespace std;



class Passenger {
	string name;
	string password;
	int aadharNo;
	string phone;
	string address;
	int passportNo;
	string dob;
public:
	Passenger(string name,int aadharNo,string phone,string address,int passportNo,string dob)
	{
        this->name=name;
        this->aadharNo=aadharNo;
        this->phone=phone;
        this->address=address;
        this->passportNo=passportNo;
        this->dob=dob;
	}
	Passenger(){}

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
	     cout<<"Enter Name : "<<name;
	    cout<<"Aadhar Number : "<<aadharNo;
	    cout<<"Phone : "<<phone;
	    cout<<"Address : "<<address;
	    cout<<"Passport Number : "<<passportNo;
	    cout<<"Date Of Birth : "<<dob;
	}

	bool checkPass(string password)
	{
	    return this->password==password;
	}

	string getName()
	{
	    return name;
	}
};

class Flight {
	string flightName;
	int flightNo;
	string from;
	string to;
	double cost;
	int duration;
public:
	Flight(string name, int no, string from, string to, double cost, int duration)
	{
		this->flightName = name;
		this->flightNo = no;
		this->from=from;
		this->to=to;
		this->cost=cost;
		this->duration=duration;
	}
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

	void output()
	{
	    cout<<"Flight Name : "<<flightName;
	    cout<<"Flight Number : "<<flightNo;
	    cout<<"from : "<<from;
	    cout<<"to : "<<to;
	    cout<<"cost : "<<cost;
	    cout<<"duration : "<<duration;

	}


};


bool login(Passenger&p,fstream&file)
{
    bool loggedin=false;
    string name;
    string password;
    cout<<"Enter Name : ";cin>>name;
    cout<<"Enter Password : ";cin>>password;
    file.open("passenger.dat",ios::in|ios::binary);
    while(file.read((char*)&p,sizeof(p)))
    {
        if(p.getName()==name && p.checkPass(password))
            {loggedin=true;break;}
    }
    return loggedin;
}


void signup(fstream&file){
  file.open("passenger.dat",ios::app|ios::binary);
  Passenger p;
  p.input();
  file.write((char*)&p,sizeof(p));
  file.close();
}


int main()
{
    vector<Passenger> psngrs;
    Passenger p;
    int ch;
    fstream file;
    do{
        cout<<"1.Signup\n ";
        cout<<"2.Login \n ";
        cout<<"3.Exit \n ";
        cout<<"Enter Choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:signup(file);
            case 2:if(login(p,file)){
                p.output();
            };
            cout<<"enter";

        }
    }while(ch!=3);

}
