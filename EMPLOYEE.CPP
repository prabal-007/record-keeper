#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
void addrec();  void updaterec();  void delrec();
void showrec(); void showallrec();
void box();
void display(char* []);
char *headmsg="headmessge";
char *footmsg="";
char *empmenu[10]={"Emp.No","Name","Age","City","","",""};//4
char *recordmenu[10]={                  //7
	      "1. Add new record.",
	      "2. Update record.",
	      "3. Delete a record.",
	      "4. Show a record.",
	      "5. Show all records.",
	      "6. Exit.",
	      "   Enter your choice? "
		  };
class emp
  {
    int empno;  //2
    char nm[20];  //20
    int age;     //2
    char city[20]; //20
    public:
   void setdata(int empno, char nm[], int age, char city[])
      {
       this->empno = empno;   strcpy(this->nm,  nm);
       this->age = age;       strcpy(this->city,city);

      } //end setdata()..
   void showempinfo()
      {
	clrscr();
	box();
	gotoxy(35,8);   cout<<empno  ;
	gotoxy(35,10);  cout<<nm ;
	gotoxy(35,12);  cout<<age ;
	gotoxy(35,14);  cout<<city ;
	display(empmenu);
      } //end show()..
    char* getnm()
       {
	 return nm;
       }
    int getage()
       {
	return age;
       }
    char* getcity()
       {
	return city;
       }
    int getempno()
      {
       return empno;
      }
    int checkduplicateempno(int no)
      {
	int flag=0; //no duplicate..
	fstream fs;
	fs.open("emp.dat",ios::in|ios::binary);
	 while( fs.read((char*)this,sizeof(this) ))
	 {
	     if(this->empno == no)
	      {
		flag=1; //yes duplicate found..
		break;
	      }//end if.
	 } //end while.
	  fs.close();
	  if(flag==0)
	     return 0;
	   else
	     return 1; //yes duplicate..

      } //end checkduplicateempno

  };

   void main()
   {
     int choice;
     clrscr();

     while(1)
     {
      getch(); clrscr();
      footmsg="";
      headmsg="||||| Employee Menu ||||| ";
      display(recordmenu); textcolor(WHITE);
      gotoxy(45,20);cin>>choice;

      switch(choice)
       {
	 case 1: addrec(); break;
	 case 2: updaterec(); break;
	 case 3: delrec(); break;
	 case 4: showrec(); break;
	 case 5: showallrec(); break;
	 case 6: gotoxy(20,22); cprintf("Exiting.."); getch();exit(0);
	 default: gotoxy(20,22); cprintf("Invalid choice..Renter Plz.");
       } //end switch...

     }//end terminator loop..

   } //end main..
    void display(char *str[])
     {
       gotoxy(20,8);   cout<<str[0]  ;
       gotoxy(20,10);  cout<<str[1] ;
       gotoxy(20,12);  cout<<str[2] ;
       gotoxy(20,14);  cout<<str[3] ;
       gotoxy(20,16);  cout<<str[4];
       gotoxy(20,18);  cout<<str[5];
       gotoxy(20,20);  cout<<str[6];
       box();
     } //end display........................

    void box()
     {
       gotoxy(20,5);   cout<<headmsg;
       gotoxy(20,22);  cprintf("%s",footmsg);

      //making of box.. 
      textcolor(2);   //GREEN
     gotoxy(18,3); cprintf("Ã|||||||||||||||||||||||||||||||||||||||||ÃÂ»");
       gotoxy(18,4); cout<<"Âº" ;                 gotoxy(60,4); cout<<"Âº" ;
       gotoxy(18,5); cout<<"Âº"  ;                gotoxy(60,5); cout<<"Âº";
       gotoxy(18,6); cout<<"Âº";                  gotoxy(60,6); cout<<"Âº";
     gotoxy(18,7); cprintf("Ã|||||||||||||||||||||||||||||||||||||||||||¹");
       gotoxy(18,8); cout<<"Âº";                  gotoxy(60,8); cout<<"Âº";
       gotoxy(18,9); cout<<"Âº";                  gotoxy(60,9); cout<<"Âº";
      gotoxy(18,10); cout<<"Âº";                 gotoxy(60,10); cout<<"Âº";
      gotoxy(18,11); cout<<"Âº";                 gotoxy(60,11); cout<<"Âº";
      gotoxy(18,12); cout<<"Âº";                 gotoxy(60,12); cout<<"Âº" ;
      gotoxy(18,13); cout<<"Âº";                 gotoxy(60,13); cout<<"Âº";
      gotoxy(18,14); cout<<"Âº";                 gotoxy(60,14); cout<<"Âº";
      gotoxy(18,15); cout<<"Âº";                 gotoxy(60,15); cout<<"Âº";
      gotoxy(18,16); cout<<"Âº";                 gotoxy(60,16); cout<<"Âº";
      gotoxy(18,17); cout<<"Âº";                 gotoxy(60,17); cout<<"Âº";
      gotoxy(18,18); cout<<"Âº";                 gotoxy(60,18); cout<<"Âº";
      gotoxy(18,19); cout<<"Âº";                 gotoxy(60,19); cout<<"Âº";
      gotoxy(18,20); cout<<"Âº";                 gotoxy(60,20); cout<<"Âº";
    gotoxy(18,21); cprintf("ÃŒ||||||||||||||||||||||||||||||||||||||||||¹");
      gotoxy(18,22); cout<<"Âº";                 gotoxy(60,22); cout<<"Âº";
      gotoxy(18,23); cout<<"Âº";                 gotoxy(60,23); cout<<"Âº";
    gotoxy(18,24); cprintf("ÃˆÃ|||||||||||||||||||||||||||||||||||||||||¼");
	textcolor(WHITE);
     } //end box...........................

   void addrec()
    {
     top:
     clrscr();
     emp e;
     int empno; char nm[20]; int age;char city[20];
       headmsg="ÃÃÃ  Add New Emp. Record  ÃÃÃ";
       display(empmenu);
       gotoxy(35,8);   cin>>empno  ;
       if(e.checkduplicateempno(empno) == 1)
	{
	 gotoxy(20,22); cout<<"EmpNo already exist..Renter";
	 getch();
	 goto top;
	}
       gotoxy(35,10);  fflush(stdin); gets(nm) ;
       gotoxy(35,12);  cin>>age ;
       gotoxy(35,14);  fflush(stdin);gets(city) ;

     e.setdata(empno,nm,age,city);
     fstream fs;
     fs.open("emp.dat",ios::binary|ios::app);
     fs.write((char*)&e,sizeof(emp) );
     fs.close();
     gotoxy(20,22); cprintf("Record Added Successfully.");
    }//end addrec()..........................
	 
	 
    void updaterec()
    {
      clrscr();
      int empno;
      int searchflag=0; //let item not found.
      //step 1 ask user
      headmsg="::Enter Empno to Update Record::";
      display(empmenu);
      gotoxy(35,8);cin>>empno;
      //step 2 open file in read mode to find empno record:
      fstream fs;
      fs.open("emp.dat",ios::in|ios::out|ios::binary);
      emp e;
      while(fs.eof() == 0 )
      {
	int loc = fs.tellg();
	fs.read( (char*)&e,sizeof(emp) )    ;
	if(e.getempno() == empno)
	 {
       searchflag=1; //found.
       //ask user to input nm,age,city..
       char nm[20]; int age; char city[20];
       gotoxy(35,10);  fflush(stdin); gets(nm) ;
       gotoxy(35,12);  cin>>age ;
       gotoxy(35,14);  fflush(stdin);gets(city) ;
       //update e object:
       e.setdata(empno,nm,age,city);
       // fs.seekp(-1*sizeof(emp),ios::cur);
       fs.seekp(loc); //even fs.seekg(loc) also works here..
       fs.write((char*)&e, sizeof(emp));
       break;
	 }//end if.............


      } //end while..
      fs.close(); //must close streams.. mandatory..

      if(searchflag == 1)
       {
		 //oldname, newname..
	 gotoxy(20,22); cprintf("Empno updated successfully");
       } //end if..
      else if(searchflag == 0)
      {
	gotoxy(20,22); cprintf("Given Empno Not Exist!!");
       }

    } //end updaterec()...


    void delrec()
     {
       clrscr();
       headmsg="::Enter EmpNo. To Delete Record::";
       display(empmenu);
       int searchflag=0; //if item not found.
       fstream fs;
       fs.open("emp.dat",ios::in|ios::binary);
       fstream fout;
       fout.open("temp.dat",ios::out|ios::binary);
       //in set app mode, del process wont work properly..
	    
	int empno;
       //cout<<"\n enter emp no: ";
       gotoxy(35,8); cin>>empno;
       emp e;
       while(fs.read((char*)&e, sizeof(emp)    ) )
	 {
	    if(e.getempno() == empno)
	      searchflag=1; //yes found.
	    else
	      fout.write((char*)&e, sizeof(emp));
	 } //end while...
	   // close the streams. mandatory..!!
	   fout.close(); fs.close();
	  if(searchflag == 1)
	    {
	      remove("emp.dat");
	      rename("temp.dat","emp.dat");
	      gotoxy(20,22); cprintf("Record deleted successfully..");
	    }
	   else
	     {  gotoxy(20,22); cprintf("Record Is Not Available..");  }


      } //end delrec()..

     void showrec()
      {
	clrscr();
	headmsg=":: Enter EmpNo. To Display Record ::";
	display(empmenu);
	int empno;
	gotoxy(35,8); cin>>empno;
	fstream fs;
	emp e;
	fs.open("emp.dat",ios::in|ios::binary);
	while(fs.read((char*)&e, sizeof(e)) )
	  {
	    if(empno == e.getempno() )
	     {
	      e.showempinfo();
	      fs.close();
	      return;
	      }//end if..

	  } //end while..
	  gotoxy(20,22); cprintf(" Given EmpNo. Not Exist!!");

       } //end showrec()..

      void showallrec()
       {
	clrscr();
	headmsg=":: Show All Records ::";
	int i=0;
	emp e;
	fstream fs;
	fs.open("emp.dat",ios::in|ios::binary);
       cout<<"\n tellg:"<<fs.tellg(); //0 ..   44..  88..   132
				     //  1st rec 2nd   3rd    4th rec..
      cout<<"\nsize of emp: "<<sizeof(emp);
	    //	 fs.seekg(44,ios::beg);// moves to 2nd rec..
  gotoxy(5,5);
  cprintf("Ã‰ÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÂ»");
  gotoxy(10,6);
  cout<<empmenu[0];
  gotoxy(30,6);
  cout<<empmenu[1];
  gotoxy(50,6);
  cout<<empmenu[2];
  gotoxy(70,6);
  cout<<empmenu[3];
  gotoxy(5,7);
  cout<<"ÃˆÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÃÂ¼"<<endl;
	while(fs.read((char*)&e,sizeof(emp)  ) )
	  {
      gotoxy(1,8+i); cout<<"loc"<<fs.tellg();
	    gotoxy(10,8+i);cout<<e.getempno();
	    gotoxy(30,8+i);cout<<e.getnm();
	    gotoxy(50,8+i);cout<<e.getage();
	    gotoxy(70,8+i);cout<<e.getcity();
	    i++;
	  } //end while..
       fs.close();
       if(i==0)
	 cout<<endl<<"None Records Found!!";
       else
	 cout<<endl<<"       There are Total "<<i<<" Records Available.";
  } //end showallrec()...

