// hostel managment project 
//559
//045276
//3rd semester
//OOP

#include<iostream>
#include<string>
#include<iomanip>
#include<conio.h>
#include<fstream>
#include<cstdlib>
#include<string.h>
#include<cstdlib>

int a=0;

using namespace std;

// info as parent class for saving ,modifing and accesing info of every object created
class info
{
	protected:
		int id;
		char name[100],address[100],e_mail[50];
		long phone;
		char pass[15]="gcs";
		int payment;
		int absence;
	public:
		info()
		{
			id=a++;

		}
		
		int getpay()   //To get pay
		{
			return payment;
		}
		void setinfo()  //to set info of child class
		{
			char first_name[50],second_name[50];
			
			cout<<"Enter first name:";
			cin>>first_name;
            cout<<"enter second name:";
            cin>>second_name;
            strcat(first_name,second_name);
			cout<<"Enter mobile no:";
			cin>>phone;
			cout<<"Enter e-mail address:";
			cin>>e_mail;
			cout<<"Enter address;";
			cin>>address;
			cout<<"Enter password:";
			cin>>pass;
			
		}
		void getinfo ()  //to show info of child class
		{
			cout<<"ID:"<<id<<endl<<"Name:"<<name<<endl<<"Payment"<<payment;
			cout<<"Address:"<<address<<endl<<"Mobile no:"<<phone;
			
		}
    	void change_pass()  //to chnage password
	{
		 int x;
		 char p[15];
		 cout<<"Enter old password:";
		 cin>>p;
		 x=strcmp(pass,p);
		char a[15];
		char b[15];
		if(!strcmp(pass,p))
		{
			cout<<"Enter new password:";
			cin>>a;
			cout<<"Confirm your password:";
			cin>>b;
			if(!strcmp(a,b))
			{
			strcpy(pass,a);
			cout<<"password changed"<<endl;
		    }
		    else
		    {
		    	cout<<"password missmatch";
			}
		
		}
		else
		{
			cout<<"invalid password";
		}
	 }

	
};

 //class of students
class student:public info 
{
	private:
	
	protected:
	public:	
	int room;	
	void show()
	{
		cout<<"ID:"<<id<<endl<<"name:"<<name<<endl<<"pending payments:"<<payment;
		
	}
	
	int login()
	{
		int a;
		char p[50];
		cout<<"Enter your name:";
		cin>>name;
		pass:
		cout<<"Enter password";
		cin>>p;
		a=strcmp(p,pass);
		if(a==0)
		{
			return 1;
		}
		else
		{
			cout<<"invalid pass";
			goto pass;
		}	
		
	};
		
	
};

//class of staff
class staff:public info 
{
	private:
		
	protected:
		
	public:
	//for login to staff id
	int login()
	{
		int a;
		char p[50];
		cout<<"Enter your name:";
		cin>>name;
		pass:
		cout<<"Enter password";
		cin>>p;
		a=strcmp(p,pass);
		if(a==0)
		{
			return 1;
		}
		else
		{
			cout<<"invalid pass";
			goto pass;
		}
}
	
};

//class of clerk inherited with student and staff
class clerk:public student,public staff 
{
	
	private:
	int id=1;
	char name[100];
	char pass[15];	
	protected:
	
	public:
		void setroom(student s)
		{
			cout<<"Enter room no:";
			cin>>s.room;
		}
		
};

//class of supredent with info and clerk
class suprident:public info,public clerk 
{
	protected:
	int id=0;	
	public:	
	
};

int main()
{
	
	int temp1,temp2,id=400;
	//there we have data of 400 students so 400 objects of stuednts are declered
	student s[400];
	// 30 staff objects are dealered
	staff stf[30];
	// a superident and a clerk is declered
	suprident sup;
	clerk clk;
	cout<<"Welcome to hajvery Hostel " <<endl;
	a:
	// a set of options is given to setect your relivent feild	
	cout<<endl<<"1.students"<<endl<<"2.Clerk"<<endl<<"3.Supredient"<<endl<<"4.Staff"<<endl;
	cout<<"Enter the number according to your designation:"<<endl;
	cin>>temp1;
	
	// if user select student
	if(temp1==1)
	{cout<<endl<<"0.Go back"<<endl<<"1.new student"<<endl<<"2.Existing student"<<endl<<"3.Main menu"<<endl;
	 cout<<endl<<"choose"<<endl;
	 cin>>temp1;
	 if(temp1==0)
	 {
	 	goto a;
	 }
	 if(temp1==1)
	 {
	 	
	 	
	 	cout<<"Hostel hi aja. Address:Science college wahdat road"<<endl;
	 	
	 	
	 }
	 else if(temp1==2)
	 {
	 	int d;
		cout<<"enter your id:";
	 	cin>>d;
	 	if(s[d].login())
	 	{
	 		s[d].getinfo();
		 }
	 }else if(temp1==3)
	 {goto a;
	 }
	 
	}
	
	//if user select clerk
	else if(temp1==2)
	{
		cout<<"1.see details"<<endl<<"3.main menu"<<endl;
		cin>>temp1;
	
		}
	
	// if user select supredent
	else if(temp1==3)
	{
	}
	
	//if user select staff
	else if(temp1==4)
	{
	
		cout<<"1.see details"<<endl<<"3.main menu"<<endl;
		cin>>temp1;
		if(temp1==1)
		{
			int temp1;
		  	cout<<"enter your id:"<<endl;
		  	cin>>temp1;
		  	if(stf[temp1].login())
		  	{
		  		stf[temp1].getinfo();
			  }	
		}	
	}
	
	// for invalid selection
	else
	{
	   	cout<<"invalid selection";
		goto a;
	}
	
	b:
	cout<<"Press '0' to goto main menu or '1' to leave"<<endl;
	cin>>temp2;
	if(temp2==0)
	{
		goto a;
	}
	else if(temp2!=1)
	{
		cout<<"Press a valid key!!!!"<<endl;
		goto b;
	}
	
	
	
}
