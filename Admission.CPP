/****************************************************************************
                     PROJECT SCHOOL ADMISSION MANAGEMENT
****************************************************************************/

#include<constrea.h>
#include<fstream.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char admit='n';
int serial=0;

/****************************************************************************
                          CLASS USED IN THE PROJECT
****************************************************************************/

class stud
{
	int age,sno,clas;             //Age, Serial No and Class
   char name[30],addr[50],sec;   //Name, Address and Section
   public:
   	void getdata(int);         //Function to get the information
      void display();            //Function to display
      void modify();             //Function to modify
      void updatesno1()          //Function to Update Serial No
      {                          //Upon Deletion
      	sno-=1;
      }
		int getsno()               //Function to get Serial No
      {
      	return sno;
      }

}obj;

/****************************************************************************
                                CLASS FUNTIONS
****************************************************************************/

void stud::getdata(int y)
{
   age=y+5;
   sno=y*100+serial;
   clas=y;
   cout<<"\n\tEnter the name of your child: ";
   gets(name);
   cout<<"\n\tEnter the residential address: ";
   gets(addr);
   sec=(serial/6)+65;

}
void stud::display()
{
	cout<<"\n\tName: ";puts(name);
   cout<<"\tAddress: ";puts(addr);
   cout<<"\tClass: "<<clas<<endl;
   cout<<"\tSec: "<<sec<<endl;
   cout<<"\tAge: "<<age<<endl;
   cout<<"\tScholar No: "<<sno<<endl;
}
void stud::modify()
{
	cout<<"\n\tEnter new details.\n";
   char nm[30]=" ",add[50]=" ",Sec;
   int Clas;
   cout<<"\n\tNew Name: (Enter '.' to retain the old one): ";
   gets(nm);
   cout<<"\n\tNew Address: (Enter '.' to retain the old one): ";
   gets(add);
   cout<<"\n\tNew Section: (Enter '.' to retain the old one): ";
   cin>>Sec;
   cout<<"\n\tNew Class: (Enter '-1' to retain the old one): ";
   cin>>Clas;
   if(strcmp(nm,".")!=0)
   	strcpy(name,nm);
   if(strcmp(add,".")!=0)
   	strcpy(addr,add);
   if(Sec!='.')
   	sec=Sec;
   if(Clas!=-1)
   	{
      	clas=Clas;
      }
   age=clas+5;
}

/****************************************************************************
                                FUNTION DECLARATION
****************************************************************************/

void assign(int);
void form();
void search(int);
void modify_student(int);
void delete_student(int);
void displayall();
void displaysp(int);

/****************************************************************************
                                Beginning of Main()
****************************************************************************/

int main()
{
	int choice;
   cout<<"\n\n\n\n\n\n\n\n\t\t\t\tCOMPUTER SCIENCE PROJECT\n";
   cout<<"\n\t\t\t\tSCHOOL ADMISSION MANAGEMENT\n";
   cout<<"\n\t\t\t\tBY: UJJWAL JAIN\n";
   cout<<"\n\t\t\t\tCLASS: 12-D\n";
   cout<<"\n\t\t\t\tSCHOOL: THE SHISHUKUNJ INTERNATIONAL SCHOOL\n";
   cout<<"\n\n\t\t\t\tPress Any Key To Continue ....";
   getch();

   do
   {
      clrscr();
      cout<<"\n\n\t\tSCHOOL ADMISSION";
   	cout<<"\n\n\n\t\tMENU\n";
   	cout<<"\n\t\t1. New Admission \n";
   	cout<<"\n\t\t2. Search  Record \n";
   	cout<<"\n\t\t3. Modify  Record \n";
   	cout<<"\n\t\t4. Delete  Record \n";
      cout<<"\n\t\t5. Display Record \n";
   	cout<<"\n\t\t6. Exit \n";
   	cout<<"\n\t\tEnter your choice(1-6): ";
   	cin>>choice;
   	if(choice==1)
   	{
      	clrscr();
         cout<<"\n\tNEW ADMISSION\n";
      	form();
   	}
   	if(choice==2)
   	{
         clrscr();
         int x;
         cout<<"\n\tSEARCH RECORD";
         cout<<"\n\n\tEnter the Serial No of the student whose details"
   		<<" you want to search: ";
   		cin>>x;
         search(x);
		}
   	if(choice==3)
   	{
         clrscr();
         int x;
         cout<<"\n\tMODIFY RECORDS";
         cout<<"\n\n\tEnter the Serial No of the student whose details"
   		<<" you want to modify: ";
   		cin>>x;
         modify_student(x);
		}
   	if(choice==4)
   	{
         clrscr();
      	int Sno;
         cout<<"\n\tDELETE RECORD";
      	cout<<"\n\n\tEnter the Serial No to be deleted: ";
         cin>>Sno;
         delete_student(Sno);
      }
      if(choice==5)
      {
      	clrscr();
         int choice2,clas;
         cout<<"\n\t\tDISPLAY RECORDS";
         cout<<"\n\n\n\t\tMENU \n";
         cout<<"\n\t\t1. All Records \n";
         cout<<"\n\t\t2. Specific Class Records \n";
         cout<<"\n\t\tEnter your choice(1-2): ";
         cin>>choice2;
         clrscr();
         if(choice2==1)
         	displayall();
         if(choice2==2)
         {
            clrscr();
            cout<<"\n\tDISPLAY RECORDS";
         	cout<<"\n\n\tEnter the Class: ";
            cin>>clas;
            clrscr();
         	displaysp(clas);
      	}
      }
	}while(choice!=6);
   getch();
}

/****************************************************************************
                                FUNTION DEFINITIONS
****************************************************************************/

void assign(int x)      //Function to the Class
{
   ifstream fi("Students.dat",ios::in);
   int Sno;
   int no=0,i=1;
   fi.seekg(0,ios::beg);
	while(fi.read((char*)&obj,sizeof(obj)))
	{
      Sno=obj.getsno();
      if((Sno/100)==x)
		{
      	no++;
      }
   }
      if(no<10)
      {
        	cout<<"\n\tSeat Available!!!\n\n\tDo you want to admit your child(y/n): ";
         cin>>admit;
         if(admit=='y'||admit=='Y')
         serial=no+1;
      }
      else
      	cout<<"\n\tNo Seat Available!!!";
		fi.close();
      clrscr();
}
void form()             //Fuction to Fill the Form
{
   ofstream fo("Students.dat",ios::app);
	int x,y;
   cout<<"\n\tEnter the age of the child: ";
   cin>>x;
   y=x-5;
   assign(y);
   if(admit=='y')
   {
      obj.getdata(y);
      fo.write((char*)&obj,sizeof(obj));
      clrscr();
      cout<<"\n\tNEW ADMISSION\n";
      cout<<"\n\tCongratulations your child has been granted admission in our school!\n";
      obj.display();
   }
   fo.close();
   getch();
}
void search(int n)      //Fuction for Searching
{
	ifstream fi("Students.dat",ios::in);
   char found='f';
   fi.seekg(ios::beg);
   while(!fi.eof())
   {
   	fi.read((char*)&obj,sizeof(obj));
      if(obj.getsno()==n)
      {
      	obj.display();
         found='t';
         break;
      }
   }
   if(found=='f')
   cout<<"\n\tRecord not found!!!\n";
   fi.close();
   getch();
}
void modify_student(int n)       //Fuction for Modifying
{
	fstream file("Students.dat",ios::in||ios::app);
   long pos;
   char found='f';
   file.seekg(0,ios::beg);
   while(!file.eof())
   {
   	pos=file.tellg();
      file.read((char*)&obj,sizeof(obj));
      if(obj.getsno()==n)
      {
      	obj.display();
         obj.modify();
         file.seekg(pos);
         file.write((char*)&obj,sizeof(obj));
         found='t';
         obj.display();
         break;
      }
   }
   if(found=='f')
   	cout<<"\n\tRecord not found!!!\n";
   file.close();
   getch();
}
void delete_student(int n)        //Fuction for Deleting
{
	stud st;
   char found='n';
	ifstream inFile;
	inFile.open("Students.dat",ios::in);
	if(!inFile)
	{
		cout<<"\n\tFile could not be open !! Press any Key...";
		getch();
		return;
	}
	ofstream outFile;
	outFile.open("Temp.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *)&st,sizeof(stud)))
	{
      if(st.getsno()==n)
      {
         st.display();
      	cout<<"\n\n\tRecord Deleted ..";
         found='y';
      }
		if(st.getsno()!=n)
		{
         if((st.getsno()>n)&&(st.getsno()<(n-(n%100)+100))&&((n%100)!=0))
         {
         	st.updatesno1();
         }
			outFile.write((char *)&st,sizeof(stud));
		}
	}
	outFile.close();
	inFile.close();
	remove("Students.dat");
	rename("Temp.dat","Students.dat");
   if(found=='n')
   {
   	cout<<"\n\n\tRecord Not Found...";
   }
	getch();
}
void displayall()                 //Fuction for Displaying
{
   stud st;
	ifstream inFile;
	inFile.open("Students.dat",ios::in);
	if(!inFile)
	{
		cout<<"\n\tFile could not be open !! Press any Key...";
		getch();
		return;
	}
   inFile.seekg(0,ios::beg);
	while(inFile.read((char *)&st,sizeof(stud)))
	{
   	st.display();
      cout<<"\n\n";
   }
   getch();
}
void displaysp(int n)             //Fuction for Displaying Specific Class
{
	stud st;
   int no=0;
	ifstream inFile;
	inFile.open("Students.dat",ios::in);
	if(!inFile)
	{
		cout<<"\n\tFile could not be open !! Press any Key...";
		getch();
		return;
	}
   inFile.seekg(0,ios::beg);
	while(inFile.read((char *)&st,sizeof(stud)))
	{
      if((st.getsno()/100)==n)
   	{
      	st.display();
      	cout<<"\n\n";
         no++;
      }
   }
   if(no==0)
   	cout<<"\n\tNo Records Found  !! Press any Key...";
   getch();
}

/****************************************************************************
                                END OF PROJECT
****************************************************************************/










