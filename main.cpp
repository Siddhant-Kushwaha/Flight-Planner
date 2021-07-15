#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<string>
#include<fstream>

using namespace std;



class Passenger {
    public:
	char *name;
	char *password;
	int aadharNo;
	char *phone;
	char *address;
	int passportNo;
	char *dob;

	Passenger(char name[20],int aadharNo,char phone[10],char address[40],int passportNo,char dob[10])
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
	     cout<<"\nName : "<<name;
	    cout<<"\nAadhar Number : "<<aadharNo;
	    cout<<"\nPhone : "<<phone;
	    cout<<"\nAddress : "<<address;
	    cout<<"\nPassport Number : "<<passportNo;
	    cout<<"\nDate Of Birth : "<<dob;
	}

	bool checkPass(char password[20])
	{
	    cout<<"pass : "<<password;
	    return this->password==password;
	}

	char* getName()
	{
	    return name;
	}
};

class Flight {
	char *flightName;
	int flightNo;
	char *from;
	char *to;
	double cost;
	int duration;
public:
	Flight(char name[25], int no,char from[20], char to[20], double cost, int duration)
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
    file.seekg(0,ios::beg);
    bool loggedin=false;
    Passenger temp;
    char name[20];
    char password[20];
    cout<<"\nEnter Name : ";cin>>name;
    cout<<"\nEnter Password : ";cin>>password;
    while(file.read((char*)&temp,sizeof(temp)))
    {
        if(temp.getName()==name && temp.checkPass(password))
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


int main()
{
    vector<Passenger> psngrs;
    Passenger p;
    int ch;
    fstream file;
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
