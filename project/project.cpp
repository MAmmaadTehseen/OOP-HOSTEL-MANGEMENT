// hostel managment project 
//559
//045276
//3rd semester
//OOP

#include<iostream>
#include<string>
#include<conio.h>
#include<windows.h>
#include<fstream>



int a=0,b=0;

using namespace std;

// info as parent class for saving ,modifing and accesing info of every object created by child classes
class info
{
	protected:
		int id;
		string firstname,sname,e_mail ,department,phone ;
		string pass;
		long payment;
	
	public:
		info()
		{
		payment=0;
		firstname="ammad";
		sname="khan";
			
		pass="gcs";
		phone="03046249904 "; 
		department="it" ;
		e_mail="ammadtehseen@gmail.com ";
		}
		
		//getter of pay To get pay
		int getpay()   
		{
			return payment;
		}
		 //to set info of child class
		
	//to set info 
		void setinfoc()  
		{
			
			cout<<"Enter firstname:";
			cin.ignore();
			getline(cin,firstname);
			cout<<"Enter second name:";
			getline(cin,sname);			
			cout<<"Enter mobile no:";
			getline(cin,phone);
			cout<<"Enter E-mail:";
			getline(cin,e_mail);
			cout<<"Enter password:";
			getline(cin,pass);
			cout<<"Enter job/department:";
			getline(cin,department);
			
			
		}
	//to chnage password
    	void change_pass()  
	{
		 string p ;
		 password:
		 cout<<"Enter old password:";
		 cin>>p;
	
		string a ;
		string b ;
		if(!p.compare(pass))
		{
			ab:
			
			cout<<"Enter new password:";
			cin.ignore();
			getline(cin,a );
			cout<<"Confirm your password:";
			getline(cin,b );
			if(!a.compare(b))
			{
			pass=a;
			cout<<"***Password changed***"<<endl;
		    }
		    else
		    {
		    	cout<<"***password missmatch***";
		    	goto ab;
			}
		
		}
		else
		{
			cout<<"!!!!!!!!!!!invalid password!!!!!!!!";
			goto password;
		}
     }
     //login function 
     int login()
	{
		string p ;
		int a;
		
		pass:
		cout<<"Enter password: ";
		cin.ignore();
		getline(cin,p);
		
		
		if(p==pass)
		{
			return 1;
		}
		else
		{
			char temp1;
			cout<<"invalid pass"<<endl;
			cout<<"press 'y' to enter password again"<<endl;
			cin>>temp1;
			if(temp1=='y')
			{
			goto pass;}
			return 0;
		}
	}
	//function to add payment
     	void add_payment()
		{
			long p;
			cout<<"Enter payment to add:"<<endl;
			cin>>p;
			payment=payment+p;
		}
		//function to subtract payment
	void sub_payment()
		{
			long p;
			cout<<"Enter payment to subtract:"<<endl;
			cin>>p;
			payment=payment-p;
		}
	 

	
};
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 //class of students
class student:public info 
{
	public:
		//setter 
		void set(string s1,long c,string s2,string s3,string s4,string s5,string s6,string s7)
		{
			
			firstname=s1;
			sname=s6;
			payment=c;
			department=s2;
			phone=s3;
			e_mail=s4;
			pass=s5;
			room=s7;
			
			
		
		}
		//setter of payment
		void setpay(long pay)
		{
			payment=pay;
		}
		//constructor
	student()
		{
			//unique id is provided to every student
			id=a++;
			room="00";
		
		}
		//destructor 
		~student()
		{
			//data is written into file
	    ofstream file1("student.txt",ios::app);
			
			file1.seekp(ios::end);
			file1<<id<<endl;
			file1<<firstname<<endl;
			file1<<sname<<endl;
			file1<<payment<<endl;
			file1<<department<<endl;
			file1<<phone<<endl;
			file1<<e_mail<<endl;
			file1<<pass<<endl;
			file1<<room<<endl;
			file1<<"------------------------------------------------------------------------------------------------"<<endl;
			file1.close();
			id=b++;
			
		
		}
		//to show info of students
		void getinfo ()  
		{

			cout<<"ID:"<<id<<endl<<"Name:"<<firstname<<" "<<sname<<endl<<"Payment:"<<payment<<endl;
			cout<<"E-mail:"<<e_mail<<endl<<"Mobile no:"<<phone<<endl<<"Department:"<<department<<endl<<"room:"<<room<<endl;
			
		}
	protected:
	public:	
	string room;	

	
	
		
	};
	
		
	

int x=0,y=0;
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//class of staff
class staff:public info 
{
	private:
		
	protected:
		
	public:
		//setter
		void set(string s1,long c,string s2,string s3,string s4,string s5,string s6)
		{
			
			firstname=s1;
			sname=s6;
			payment=c;
			department=s2;
			phone=s3;
			e_mail=s4;
			pass=s5;
			
			
		
		}
		//to show info 
		void getinfo()  
		{
			cout<<"ID:"<<id<<endl<<"Name:"<<firstname<<" "<<sname<<endl<<"Payment:"<<payment<<endl;
			cout<<"E-mail:"<<e_mail<<endl<<"Mobile no:"<<phone<<endl<<"job:"<<department<<endl;
			
		}
	//construtor
		staff()
		{
			id=x++;
		}
		//destructor
		~staff()
		{
			//writing data into file
			
			ofstream file1("staff.txt",ios::app);
			file1<<id<<endl;
			file1<<firstname<<endl;
			file1<<sname<<endl;
			file1<<payment<<endl;
			file1<<department<<endl;
			file1<<phone<<endl;
			file1<<e_mail<<endl;
			file1<<pass<<endl;
			file1<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
			file1.close();
			id=y++;
			
		}
	
};
// class of mess
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class mess
{
	long totalbill;
	long totalstu,bps;
	public:
		//bill function is defined to make a average bill for every student in order to assign every student a bill amount in one commmand
	 long bill()
		{
		
		cout<<"Enter total bill:";
		cin>>totalbill;
		cout<<"Enter total students:";
		cin>>totalstu;
		bps=totalbill/totalstu;
		return bps;
		}
};

//class of clerk inherited with student and staff
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class clerk:public student,public staff,public mess
{
	
	private:
		
		string pass;
	
	protected:
	
	public:
		clerk()
		{
			pass="ammad1";
			ifstream file("clerk.txt");
			file>>pass;
		}
		~clerk()
		{
			ofstream file("clerk.txt");
			file<<pass<<endl;
		}
			//to chnage password
    	void change_pass()  
	{
		 string p ;
		 password:
		 cout<<"Enter old password:";
		 cin>>p;
	
		string a ;
		string b ;
		if(!p.compare(pass))
		{
			ab:
			
			cout<<"Enter new password:";
			cin.ignore();
			getline(cin,a );
			cout<<"Confirm your password:";
			getline(cin,b );
			if(!a.compare(b))
			{
			pass=a;
			cout<<"***Password changed***"<<endl;
		    }
		    else
		    {
		    	cout<<"***password missmatch***";
		    	goto ab;
			}
		
		}
		else
		{
			cout<<"!!!!!!!!!!!invalid password!!!!!!!!";
			goto password;
		}
     }

		//setroom function is used to sewt room no to student
		void setroom(student s)
		{
			cout<<"Enter room no:";
			cin>>s.room;
		}
		//login function for staff
	int login()
	{
		
		string p ;
		int a;
		
		pass:
		cout<<"Enter password: ";
		cin.ignore();
		getline(cin,p);
		
		
		if(p==pass)
		{
			return 1;
		}
		else
		{
			char temp1;
			cout<<"!!!!invalid pass!!!!"<<endl;
			cout<<"press 'y' to enter password again or any other alphabet to goto main menu."<<endl;
			cin>>temp1;
			if(temp1=='y')
			{
			goto pass;}
			return 0;
		}
	}	
		
		
};
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//class of supredent with info and clerk
class suprident:public clerk 

{
	protected:
		
		
		string pass ;	
	public:
			suprident()
		{
			pass="ammad1";
			ifstream file("superident.txt");
			file>>pass;
		}
		~suprident()
		{
			ofstream file("superident.txt");
			file<<pass<<endl;
		}
			//to chnage password
    	void change_pass()  
	{
		 string p ;
		 password:
		 cout<<"Enter old password:";
		 cin>>p;
	
		string a ;
		string b ;
		if(!p.compare(pass))
		{
			ab:
			
			cout<<"Enter new password:";
			cin.ignore();
			getline(cin,a );
			cout<<"Confirm your password:";
			getline(cin,b );
			if(!a.compare(b))
			{
			pass=a;
			cout<<"***Password changed***"<<endl;
		    }
		    else
		    {
		    	cout<<"***password missmatch***";
		    	goto ab;
			}
		
		}
		else
		{
			cout<<"!!!!!!!!!!!invalid password!!!!!!!!";
			goto password;
		}
     }

	//login function for superident	
	int login()
	{
		string p ;
		int a;
		
		pass:
		cout<<"Enter password: ";
		cin.ignore();
		getline(cin,p);
		
		
		if(p==pass)
		{
			return 1;
		}
		else
		{
			char temp1;
			cout<<"invalid pass"<<endl;
			cout<<"press 'y' to enter password again"<<endl;
			cin>>temp1;
			if(temp1=='y')
			{
			goto pass;}
			return 0;
		}
	}
	
};
int main()
{
	system("Color 70");
	char temp1,temp2;
	
	//there we have data of 400 students so 400 objects of stuednts are declered
	student s[400];
	// 30 staff objects are dealered
	staff stf[30];
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
//loading daTA OF SuTDENTS
	

	
	for(int id=399;id>=0;id--)
		{
			string a0,a1,string,a2,a3,a4,a5,a6;
			long b;
			int k;
			ifstream file("student.txt");
		
			
			
			for(int i=0;i<403;i++)
			{
			
			
			file>>k;
			file>>a0;//first name
			file>>a5;//second name
			file>>b;//payment
			file>>a1;//department
			file>>a2;//phone
			file>>a3;//E-mail address
			file>>a4;//PASSWORD
			file>>a6;//room no
			file>>string;
			
		
	if(k==id)
	{
	
		 s[id].set(a0,b,a1,a2,a3,a4,a5,a6);
		 break;
		 	}
		}
			file.close();
		
		}
	
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//loading data of staff
			ifstream file3("staff.txt");
		for(int id=30;id>0;id--)
		{
			string a0,a1,a2,a3,a4,a5,string;
			long b;
			int k,a6;
		
			for(int i=0;i<32;i++)
			{
			
			
			file3>>k;
			file3>>a0;//first name
			file3>>a5;//second name
			file3>>b;//payment
			file3>>a1;//department
			file3>>a2;//phone
			file3>>a3;//E-mail address
			file3>>a4;//PASSWORD
			file3>>string;
			if(k==id)
			{
						stf[id].set(a0,b,a1,a2,a3,a4,a5);
						break;
			}
			}
		
		}
			file3.close();
					

	// a superident and a clerk is declered
	suprident sup;
	clerk clk;
//*****************************************************************************************************************************************************************************************************************************************************************************
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------		
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
//from there the real project begen
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
	cout<< "        *****************************************************************************************" <<endl;
	cout<< "        *                                                                                       *" <<endl;
	cout<< "        *                                 Welcome to Hajvery Hostel                             *" <<endl;
	cout<< "        *                                                                                       *" <<endl;
	cout<< "        *****************************************************************************************" <<endl;
	cout<<"\n\n";
	cout<< "                +-------------------------------------------------------------------------+" <<endl;
	cout<< "                |               ||             ||           ||           ||               |"<<endl;
	cout<< "                |               ||             ||           ||           ||               |" <<endl;
	cout<< "                |               ||             ||           ||           ||               |" <<endl;
	cout<< "                |               ||_____________||           ||___________||               |" <<endl;
	cout<< "                |               ||_____________||     <>    ||___________||               |" <<endl;
	cout<< "                |               ||             ||           ||           ||               |" <<endl;
	cout<< "                |               ||             ||           ||           ||               |" <<endl;
	cout<< "                |               ||             ||           ||           ||               |" <<endl;
	cout<< "                |               ||             ||ajvery     ||           ||ostel         |" <<endl;
	cout<< "                +-------------------------------------------------------------------------+" <<endl;
	cout<<"\n\n\n\n\n\n\n\n\n\n press any key to countinue!";	
		getch();
		system("cls");
	mainmenu:
		system("Color 67");
	// a set of options is given to setect your relivent feild	
	cout<<endl<<"1.Students"<<endl<<"2.Clerk"<<endl<<"3.Supredient"<<endl<<"4.Staff"<<endl<<"5.Exit"<<endl;
	cout<<"Enter the number according to your need:"<<endl;
	cin>>temp1;
	system("cls");
	
	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	// if user select student
	if(temp1=='1')
	{cout<<"1.New Student"<<endl<<"2.Existing Student"<<endl<<"3.Main Menu"<<endl;
	 cout<<endl<<"Choose:";
	 cin>>temp1;
	 
	 system("cls");
	 
	 if(temp1=='3')//goto main menu
	 {
	 	goto mainmenu;
	 }
	 else if(temp1=='1')//for new student
	 {
	 	string name,phone,e_mail,department;
	 		cout<<"Enter name:";
			cin.ignore();
			getline(cin,name);
						
			cout<<"Enter mobile no:";
			getline(cin,phone);
			cout<<"Enter E-mail:";
			getline(cin,e_mail);
			cout<<"Enter job/department:";
			getline(cin,department);
			
	 	ofstream file("1newstu.txt",ios::app);
			
			
			file<<"Name:"<<name<<endl;
			file<<"E-mail:"<<e_mail<<endl;
			file<<"Department:"<<department<<endl;
			file<<"Mobile no:"<<phone<<endl;
			file<<"-------------------------------------------------------------------------------------------------"<<endl;
			
			file.close();

	 }
	 else if(temp1=='2')//for existing student
	 {
	 	int d;
	 	login1:
		cout<<"Enter your ID(1-399):";
	 	cin>>d;
	 	system("cls");
	 	
	 	if(d<401)
	 	{
		 cout<<"1.See details"<<endl<<"2.Change Password"<<endl<<"3.Main Menu"<<endl;
	 	cin>>temp1;
	 	system("cls");
	 	if(temp1=='1')//to see details
		 {
		 
	 	   if(s[d].login())
	 	  {
	 		s[d].getinfo();
		  }
 		}
 		
 		else if(temp1=='2')//to change password
 		{
 			s[d].change_pass();	
		 }
	   }
	   else if(temp1=='3')//to goto main menu
	   {
	   	goto mainmenu;
	   }
	   //if id is out of range
	   else
	   	   {
	   	cout<<"!!!!!!!!!!!!!!!!!!!  ID out of range  ......................................"<<endl;
	   	cout<<"\n\n\n\n\n\t\t\t\t Press any key !"<<endl;
	   	getch();
	   	system("cls");
		   goto login1;
	   }
	}
}
	 
	
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//if user select clerk
	else if(temp1=='2')
	{
		if(clk.login())
		{
			clerk:
		cout<<"1.Manage  student"<<endl<<"2.Manage  staff"<<endl<<"3.Allote room no to students"<<endl<<"4.Manage mess"<<endl<<"5.Change your password"<<"0.Main Menu"<<endl;
		cin>>temp1;
		system("cls");
		if(temp1=='1')//to mnage students
		{
			a1:
			int id;
			cout<<"Enter ID of student(1-399):"<<endl;
			cin>>id;
			if(id>=400||id<=0)
			{
	   		cout<<"!!!!!!!!!!!!!!!!!!!  ID out of range  ......................................"<<endl;
	   		cout<<"\n\n\n\n\n\t\t\t\t Press any key !"<<endl;
	   		getch();
	   		system("cls");
		   	goto a1;
	   		}
	  
			system("cls");
			cout<<"1.Add payment"<<endl<<"2.Subtract payment"<<endl<<"3.Show payment"<<endl<<"4.Add detalis"<<endl<<"5.Main Menu"<<endl;
			cin>>temp1;
			system("cls");
			if(temp1=='1')//add paymnet to students selected object
			{
				s[id].add_payment();
			}
			else if(temp1=='5')
			{
				goto mainmenu;
			}
			else if(temp1=='2')//to subtract payment from selected object
			{
			s[id].sub_payment();	
			}
			else if(temp1=='3')//to see payment of selected student object
			{
			cout<<"Payment of ID"<<id<<"is"<<s[id].getpay()<<endl;
			cout<<"\n\n\n\nPress any key to countinue!";
				getch();
				system("cls");
			}
			else if(temp1=='4')//add details to student object
			{
			s[id].setinfoc();	
			}
		}
		else if(temp1=='5')
		{
			clk.change_pass();
		}
		else if(temp1=='2')//to mange staff
		{
			a2:
			int id;
			cout<<"Enter ID of staff(1-29):"<<endl;
			cin>>id;
			if(id>=30||id<=0)
			{
	   		cout<<"!!!!!!!!!!!!!!!!!!!  ID out of range  ......................................"<<endl;
	   		cout<<"\n\n\n\n\n\t\t\t\t Press any key !"<<endl;
	   		getch();
	   		system("cls");
		   	goto a2;
	   		}
			system("cls");
			cout<<"1.Add payment"<<endl<<"2.Subtract payment"<<endl<<"3.Show payment"<<endl<<"4.Add detalis"<<endl<<"5.Mian Menu"<<endl;
			cin>>temp1;
			system("cls");
			if(temp1=='1')//add payment to selected staff 
			{
				stf[id].add_payment();
			}
			else if(temp1=='5')//to main menu
			{
				goto mainmenu;
			}
			else if(temp1=='2')//subtract payment to selected staff
			{
			stf[id].sub_payment();	
			}
			else if(temp1=='3')//see payment of staff
			{
			cout<<"payment of ID "<<id<<" is "<<stf[id].getpay()<<endl;	
			cout<<"\n\n\n\npress any key to countinue!";
				getch();
				system("cls");
			}else if(temp1=='4')//add detals of staff
			{
			stf[id].setinfoc();	
			}
		}
		else if(temp1=='3')//allot room to students
		{
			a4:
			int id;
			cout<<"Enter ID of student(1-399)";
			cin>>id;
			if(id>=400||id<=0)
			{
	   		cout<<"!!!!!!!!!!!!!!!!!!!  ID out of range  ......................................"<<endl;
	   		cout<<"\n\n\n\n\n\t\t\t\t Press any key !"<<endl;
	   		getch();
	   		system("cls");
		   	goto a4;
	   		}
			system("cls");
			cout<<"Enter alloted room no:";
			cin>>s[id].room;
		}
		else if(temp1=='4')//set mess bill equaly to every student
		{
			long a,b=0;
			a=clk.bill();
			for(int i=0;i<400;i++)
			{
				b=a+s[i].getpay();
				s[i].setpay(b);
			}
			system("cls");
		}
		else if(temp1=='0')//goto main menu
		{
			goto mainmenu;
		}
		else//if selection is invalid
		{
			cout<<"\n\n\n\n\t\t\t\tinvalid selection!!!";
		}
		goto clerk;
	}
	}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
// if user select supredent
	else if(temp1=='3')
	{
		if(sup.login())
		{
			sup:
			int id;
			cout<<"1.See details of student"<<endl<<"2.See details of staff "<<endl<<"3.change your password"<<endl<<"0.MainMenu"<<endl;
			cin>>temp1;
			system("cls");
			if(temp1=='1')//see deatails of students
			{
			a7:
				cout<<"Enter ID(1-399) :";
				cin>>id;
				if(id>=400||id<=0)
			{
	   		cout<<"!!!!!!!!!!!!!!!!!!!  ID out of range  ......................................"<<endl;
	   		cout<<"\n\n\n\n\n\t\t\t\t Press any key !"<<endl;
	   		getch();
	   		system("cls");
		   	goto a7;
	   		}
				s[id].getinfo();
				cout<<"\n\n\n\n\\n\nPress any key to countinue!";
				getch();
				
				system("cls");
			}
			else if(temp1=='2')//see deetails of staff
			{
				cout<<"Enter ID (1-29):";
				cin>>id;
				stf[id].getinfo();
				cout<<"\n\n\n\n\\n\nPress any key to countinue!";
				getch();
				system("cls");
			}
			else if(temp1=='0')
			{
				goto mainmenu;
			}
			else if(temp1=='3')
			{
				sup.change_pass();
			}
			else
			{
				cout<<"\n\n\n\n\n\nInvalid selection!!!!!"<<endl;
			}
		
			goto sup;
		}
	}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//if user select staff
	else if(temp1=='4')
	{
	
		cout<<"1.See details"<<endl<<"2.Change password"<<endl<<"3.Main Menu"<<endl;
		cin>>temp1;
		system("cls");
		//see details off staff
		if(temp1=='1')
		{
			a5:
			int temp1;
		  	cout<<"Enter your ID(1-29):"<<endl;
		  	cin>>temp1;
		  		if(temp1>=30||temp1<=0)
			{
	   		cout<<"!!!!!!!!!!!!!!!!!!!  ID out of range  ......................................"<<endl;
	   		cout<<"\n\n\n\n\n\t\t\t\t Press any key !"<<endl;
	   		getch();
	   		system("cls");
		   	goto a5;
	   		}
		  	if(stf[temp1].login())
		  	{
		  		stf[temp1].getinfo();
			}	
		}
		//change pass 
		if(temp1=='2')
		{
			a6:
			int temp1;
			cout<<"Enter your ID(1-29):";
			cin>>temp1;
				if(temp1>=30||temp1<=0)
			{
	   		cout<<"!!!!!!!!!!!!!!!!!!!  ID out of range  ......................................"<<endl;
	   		cout<<"\n\n\n\n\n\t\t\t\t Press any key !"<<endl;
	   		getch();
	   		system("cls");
		   	goto a6;
	   		}
	
		  	
		  		stf[temp1].change_pass();
				
			
			
		}
			
	}
	else if(temp1=='5')//exit from program
	{
		goto exit;
	}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
	else
	{
	   	cout<<"Invalid selection!!!!!!!!!!!!!\n\n\n\n\n\n";
		goto mainmenu;
	}
	
	b:
	cout<<"Press '0' to goto main menu or '1' to leave"<<endl;
	cin>>temp2;
	system("cls");
	if(temp2=='0')
	{
		goto mainmenu;
	}
	else if(temp2!='1')//if a invalid key is pressed
	{
		cout<<"Press a valid key!!!!"<<endl;
		goto b;
	}
	exit:
		cout<<"                     _______________________________________"<<endl;
		cout<<"                    |     ___            ____               |"<<endl;
		cout<<"                    |    |    |  \\   /  |                   |"<<endl;
		cout<<"                    |    |____|   \\ /   |____               |"<<endl;
		cout<<"                    |    |    |    /    |                   |"<<endl;
		cout<<"                    |    |____|   /     |____               |"<<endl;
		cout<<"                    |_______________________________________|"<<endl;



ofstream file7("student.txt");
ofstream file4("staff.txt");
}



	
	

