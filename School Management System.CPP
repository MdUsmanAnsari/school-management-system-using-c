
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<graphics.h>
#include<process.h>

FILE *file;

//Structure Declaration
struct moawwschool
{
  char name[26];
  char roll[3];
  char father[26];
  char clas[3];
  char gender[3];
  char city[26];
  char pincode[8];
  char mobile[11];
  char address[36];

}moa;

//Variable Declaration
int select=0;
int page=0;
long size=sizeof(moa);


// Function Declartion
void splash();
void splash1();
void splash2();
void loginPage();
void someerror();
void menu(int);
void menuLoading();
void admissionPage();
void showRecords();
void displayGraph();
void searchGraph();
void searchRecordName();
void searchRecordRoll();
void searchPopUp();
void searchPopUpselect(int);
void modifyRecord();
void textBox();
void InsertPopUp();
void deleteRecord();
void aboutdeveloper();
int gd=DETECT,gm;


void main()
{
  int keyh;//use up down left right
  initgraph(&gd,&gm,"..\\bgi");
  splash();
  menuLoading();
  menu(select);
  do
  {
    keyh=getch();
    if(keyh==80)// down
    {
    select++;
    if(select>=7)
    select=0;
    }
    if(keyh==72)
    {
     select--;
     if(select<0)
     select=6;
    }
    if(keyh==13)
    {
     if(select==0)
     {
     cleardevice();
     admissionPage();
     cleardevice();
     menuLoading();
     }
     else if(select==1)
     {
      cleardevice();
      showRecords();
      cleardevice();
      menuLoading();
     }
     else if(select==2)
     {
      searchPopUp();
      cleardevice();
      menuLoading();
     }
     else if(select==3)
     {
       cleardevice();
       modifyRecord();
       cleardevice();
       menuLoading();
     }
     else if(select==4)
     {
      cleardevice();
      deleteRecord();
      cleardevice();
      menuLoading();
     }
     else if(select==5)
     {
      cleardevice();
      aboutdeveloper();
      cleardevice();
      menuLoading();
     }
     else if(select==6)
     exit(0);
    }
   menu(select);

  }while(2);
}

			  // First Form Open Coding........
void splash()
{
  char keypress;
  setfillstyle(1,4);
  bar(0,0,getmaxx(),getmaxy());
  setcolor(15);
  settextstyle(5,HORIZ_DIR,4);
  textcolor(15);
  outtextxy(70,416,"Develop By :- Md.Usman Ansari");
  settextstyle(2,HORIZ_DIR,6);
  outtextxy(100,200,"Press [ Enter ] To Open School Managment System ");
  outtextxy(100,240," Press [ ESC ] To Exit School Managment System ");
  if((keypress=getch())==13)
  {
   splash2();
  }
  else if(keypress=='\033')
  exit(0);
  else
  splash();
}

		//starting screen coding

void splash1()
{
  char ar[][30]={"M","A","N"," ","O","F"," ","A","C","T","I","O","N"," ","W","O","R","L","D","W","I","D","E"};
  int x=getmaxx()/2,y=getmaxy()/2,x1=getmaxx()/2,y1=getmaxy()/2,i;

  while(!kbhit())
  {
   x=getmaxx()/2,y=getmaxy()/2,x1=getmaxx()/2,y1=getmaxy()/2,i;
   for(i=0;i<=4;i++)
  { sound(100+(x*i+100));
    cleardevice();
    setcolor(i);
    rectangle(x,y,x1,y1);
    setcolor(i+1);
    rectangle(x+6,y+6,x1-6,y1-6);
    x+=16;
    y+=12;
    x1-=16;
    y1-=12;
    outtextxy(260,400,"Press Any Key");
    delay(60);

  }
   for(i=0;i<=4;i++)
  {
    sound(100+(x*6));
    cleardevice();
    setcolor(i);
    rectangle(x,y,x1,y1);
    setcolor(i+1);
    rectangle(x+6,y+6,x1-6,y1-6);
    x-=16;
    y-=12;
    x1+=16;
    y1+=12;
    delay(60);

   outtextxy(220,400,"Press Any Key to Continue..");
  }
  }
  getch();
  nosound();
  x=getmaxx()/2,y=getmaxy()/2,x1=getmaxx()/2,y1=getmaxy()/2,i;

  settextstyle(16,0,4);
  for(i=0;i<20;i++)
  {
    cleardevice();
    setcolor(i);
    rectangle(x,y,x1,y1);
    setcolor(i+1);
    rectangle(x+6,y+6,x1-6,y1-6);
    x+=16;
    y+=12;
    x1-=16;
    y1-=12;
    delay(20);
  }
  x=0;
  for(i=0;i<200;i++)
  {
  setcolor(4);
  rectangle(130+i,60,310+i,100);
  delay(6);
  }
  for(i=0;i<13;i++)
  {
   setfillstyle(1,15);
   setcolor(15);
   outtextxy(160+x,72,ar[i]);
   bar(160,90,160+x+6,90);
   x+=26;
   delay(6);
  }
  for(i=0;i<30;i++)
  {
   setcolor(4);
   bar3d(130+i,100+i,130+i,60+i,1,0);
   delay(6);
  }
   for(i=0;i<320;i++)
  {
   setcolor(5);
   bar(160,100,160+i,130);
   delay(2);
  }
  for(i=0;i<30;i++)
  {
   setfillstyle(1,4);
   setcolor(15);
   bar3d(510-i,100+i,510-i,60+i,1,0);
   delay(6);
  }
   x=0;
   for(i=13;i<23;i++)
  {
   setcolor(4);
   outtextxy(200+x,110,ar[i]);
   bar(216,120,216+x+6,120);
   x+=26;
   delay(10);
  }
  for(i=60;i<160;i++)
  {
    setfillstyle(1,2);
    delay(5);              //green line
    bar(i,i-28,i,i);
  }
   for(i=0;i<322;i++)
  {
    setfillstyle(1,2);
    delay(5);
    bar(160,160,160+i,160);
  }
   for(i=0;i<100;i++)
  {
    setfillstyle(1,2);        ///green line
    delay(5);
    bar(480+i,133-i,480+i,160-i);
  }
  for(i=0;i<266;i++)
  {
    setfillstyle(1,2);        ///green lining
    delay(5);
    bar(60+i,30,60+i,30);
     bar(580-i,30,580-i,30);
  }

  char usman[][20]={"M","D",".","U","S","M","A","N"," ","A","N","S","A","R","I"};
  char moasc[][26]={"S","C","H","O","O","L"," ","M","A ","N","A","G","E","M","E","N","T"," ","S","Y","S","T","E","M"};
  int size=10;
  for(i=0;i<15;i++)
  {
   setcolor(12);
   settextstyle(2,0,6);
   outtextxy(170+size,140,usman[i]);
   size+=20;
   delay(16);
  }
   size=0;
   for(i=0;i<24;i++)
  {
   setcolor(14);
   settextstyle(2,0,6);
   outtextxy(90+size,34,moasc[i]);
   size+=20;
   delay(26);
  }

}
void splash2()
{
   char us[][26]={"M","D",".","U","S","M","A","N"," ","A","N","S","A","R","I"};
   char us1[][6]={"R","O","L","L"," ","N","O",".",":"," ","2","3","C","L","A","S","S"," ",":"," ","B","C","A","-","I","I","C","O","L","L","E","G","E"," ",":"," ","M","I","R","Z","A"," ","G","H","A","L","I","B"," ","C","O","L","L","E","G","E"," ","G","A","Y","A"};
   int i=0;
   int c=9,t=1,k=0,inc=0,inc1=0,inc3=0,inc2=0;
   char keypress;

    while(!kbhit())
   {
     l:
      if(t==1)
      splash1();
      t++;
      for(i=0;i<100;i++)
      {
      if(k<15){
      outtextxy(180+inc3,190,us[k++]);
      inc3+=13;
      delay(2);
      }
      if(i<12)
      {
      outtextxy(180+inc,220,us1[i]);
      inc+=10;
      }
      if(i>=12 && i<26)
      {
      outtextxy(180+inc1,250,us1[i]);
      inc1+=10;
      }
      if(i>25 && i<=60)
      {
      outtextxy(180+inc2,280,us1[i]);
      inc2+=10;
      }
      delay(3);
     }
     inc=inc1=inc2=inc3=0,i=0,k=0;
    for(i=-0;i<300;i++)
    {
      setcolor(c);
      rectangle(160,400,500,416);
      setfillstyle(1,c);
      bar(170+i,407,176+i,410);
      rectangle(15,11,getmaxx()-16,getmaxy()-12);
      delay(2);
     }


     for(i=0;i<100;i++)
     {
      setcolor(c+1);
      if(k<15){
      outtextxy(180+inc3,190,us[k++]);
      inc3+=13;
      delay(2);
      }
      if(i<12)
      {
      outtextxy(180+inc,220,us1[i]);
      inc+=10;
      }
      if(i>=12 && i<26)
      {
      outtextxy(180+inc1,250,us1[i]);
      inc1+=10;
      }
      if(i>25 && i<=60)
      {
      outtextxy(180+inc2,280,us1[i]);
      inc2+=10;
      }
      delay(3);
     }
     inc=inc1=inc2=inc3=0,i=0,k=0;

     for(i=-0;i<310;i++)
     {
      setcolor(c+1);
      rectangle(160,400,500,416);
      setfillstyle( 1,c+1);
      bar(480-i,407,486-i,410);
      rectangle(15,11,getmaxx()-16,getmaxy()-12);
      delay(2);
     }
    rectangle(9,5,getmaxx()-10,getmaxy()-6);
    if(c>=13)
    c=9;
    c+=2;
    setcolor(c);
    outtextxy(226,426,"Press Enter For Login.");
    }
    keypress=getch();
    if(keypress==13)
    {
     loginPage();
    }
    else if(keypress=='\033')
    exit(0);
    else
    goto l;

}


		      // Login Page Fuction Coding...............

void loginPage()
{
clrscr();
int i,count=0;
FILE *lid;
char username[19];
char pass[19];
struct loginId                         // For Login Id Profile
{
 char password[18];
}ld;
char ans[]="ANSARI";

lid=fopen("LoginData.txt","rb");
if(lid==0)
{
  fclose(lid);
  lid=fopen("LoginData.txt","wb");
  fwrite(&ans,sizeof(ans),1,lid);
  fclose(lid);
}

char ch;

 setfillstyle(10,5);
 bar(0,0,getmaxx(),getmaxy());
 setcolor(14);
 settextstyle(6,HORIZ_DIR,3);
 outtextxy(66,10," S C H O O L  M A N A G E M E N T  S Y S T E M ");
 outtextxy(63,26,"================================ ");
 setfillstyle(1,4);
 bar(0,436,getmaxx(),getmaxy()-6);
 outtextxy(106,436," DEVELOP & DESGIN BY :- MD.USMAN ANSARI ");
 setfillstyle(1,12);
 bar(160,160,500,300);//For Login Area
 setcolor(15);
 line(160,160,500,160);
 setcolor(0);
 settextstyle(6,HORIZ_DIR,3);
 outtextxy(290,160," LOGIN ");
 setcolor(15);
 settextstyle(2,HORIZ_DIR,6);
 outtextxy(200,200,"User Name : ");
 outtextxy(200,240,"Password  : ");
 setfillstyle(1,0);
 bar(320,200,480,226);
 bar(320,240,480,266);
 for (i=0;i<13;i++)
 cprintf("\n\t\t\t");
 cprintf("  ");
 while(!kbhit())
 {
  setfillstyle(1,15);   //cursor point
  bar(322,222,332,224);
  setfillstyle(1,0);
  bar(322,222,332,224);
 }
 while((ch=getch())!=13)
 {
   if(ch==8 && count>=1)
   {
     setfillstyle(1,12);
     bar(160,270,500,300);
     printf("\b \b");
     count--;
   }
   else if(ch!=8 && count<=18)
   {
   printf("%c",ch);
   username[count++]=ch;
   }
   else if(count>18)
   {
   sound(600);
   outtextxy(170,270,"Max 18 Character For Username !! ");
   delay(66);
   nosound();
   }
 }
 username[count]='\0';
 setfillstyle(1,12);
 bar(160,270,500,300);
 cprintf("\n");
 for (i=0;i<count;i++)
 cprintf("\b");
 for (i=0;i<16;i++)
 cprintf("\t\t\t\t\t");
 count=0;

 while(!kbhit())
 {
  setfillstyle(1,15);
  bar(322,260,332,262);
  setfillstyle(1,0);
  bar(322,260,332,262);
 }

 while((ch=getch())!=13)
 {
   if(ch==8 && count>0)
   {
     setfillstyle(1,12);
     bar(160,270,500,300);
     count--;
     printf("\b \b");
   }
   else if(ch!=8 && count<=18)
   {
   printf("*");
   pass[count++]=ch;
   }
   else if(count>18)
   {
   sound(600);
   outtextxy(170,270,"Max 18 Character For Password !!");
   delay(106);
   nosound();
   }
 }
   char str1[18];
   pass[count]='\0';
   setfillstyle(1,12);
   bar(160,270,500,300);
  lid=fopen("LoginData.txt","rb");
  fread(&ld.password,sizeof(ld),1,lid);
  if(!((strcmpi(username,"USMAN")==0) && (strcmp(ld.password,pass)==0)))
  someerror();

}

void someerror()
{
  char key;
  int i;
  setfillstyle(1,9);
  for(i=160;i<getmaxy()-180;i++)
  {
   bar(160,160,getmaxx()-140,i);
   delay(2);
  }
  setfillstyle(1,2);
  setcolor(15);
  settextstyle(6,0,2);
  outtextxy(250,170," Access Denied !!");
  outtextxy(190,220," Press [ Enter ] to Login Page ");
  outtextxy(170,260," Press [ Esc ] to Close The Program");
  sound(600);
  while(!kbhit())
  {
   setcolor(12);
   rectangle(160,160,getmaxx()-140,getmaxy()-180);
   rectangle(0,0,getmaxx(),getmaxy());
   delay(100);
   setcolor(14);
   rectangle(160,160,getmaxx()-140,getmaxy()-180);
   rectangle(0,0,getmaxx(),getmaxy());
   delay(100);
   sound(666);
  }
 nosound();
  if((key=getch())==13)
  {
  nosound();
  loginPage();
  }
  else if(key=='\033')
  {
   nosound();
   exit(0);
  }
  else
  someerror();

}


void menuLoading()
{
  cleardevice();
  int i,x=150,y=100;
  setfillstyle(1,1);
  bar(0,0,getmaxx(),getmaxy());
  settextstyle(10,0,2);
  setcolor(14);
  outtextxy(200,10,"DASHBOARD");
  outtextxy(200,30,"==========");
  setfillstyle(1,7);
  for(i=0;i<300;i++)
  {
  bar(x,y,x+i,y+40);
  bar(x,y+50,x+i,y+90);
  bar(x,y+100,x+i,y+140);
  bar(x,y+150,x+i,y+190);
  bar(x,y+200,x+i,y+240);
  bar(x,y+250,x+i,y+290);
  bar(x,y+300,x+i,y+340);
  delay(3);
  }
}

		 //MENU CODING UP DOWN LEFT and RIGHT

void menu(int select)
{
  setcolor(15);
  settextstyle(2,0,6);
  char ar[][30]={"Insert Student Record  >>","Display Student Record >>","Search Student Record  >>","Modify Student Record  >>","Delete Student Record  >>","About  >>","Exit >>"};
  int i,x=150,y=100,x1=450,y1=140;
  for(i=0;i<=6;i++)
  {
   if(i==select)
   setfillstyle(1,2);
   else
   setfillstyle(1,4);
   bar3d(x,y,x1,y1,1,1);
   outtextxy(x+50,y+10,ar[i]);
   y=y+50;
   y1=y1+50;
  }

}
		  // Inset Pop-Up Box Coding...............

void InsertPopUp()
{

  setcolor(15);
  int x=150,y=150,i;
  for(i=0;i<360;i++)
  {
   bar(x,y,x+i,y);
   delay(1);
  }
  for(i=0;i<200;i++)
  {
   bar(x+360,y,x+360,y+i);
   delay(1);
  }
  for(i=0;i<360;i++)
  {
   bar(510,350,510-i,350);
   delay(1);
  }
  for(i=0;i<200;i++)
  {
   bar(150,350-i,150,350);
   delay(1);
  }
  for(i=0;i<190;i++)
  {
   setfillstyle(1,12);
   bar3d(150,150,510,160+i,1,1);
   delay(2);
  }
  settextstyle(6,0,2);
  setcolor(14);
  outtextxy(260,160,"   WARNING !!");
  outtextxy(200,200,"The Roll No.is already exist ");
  outtextxy(220,260,"     Try Again");
  setfillstyle(1,4);
  setcolor(15);
  bar3d(300,346,340,320,1,0);
  settextstyle(2,0,6);
  outtextxy(312,322,"OK");

}

		     // Admission Form Coding...

void admissionPage()
{
 setbkcolor(0);
 k://goto use
 char ch,count=0;
 cleardevice();
 clrscr();
 settextstyle(12,0,2);
 setfillstyle(1,4);
 bar(0,0,getmaxx(),getmaxy());
 setcolor(14);
 outtextxy(240,10,"STUDENT ADDMISSION");
 outtextxy(240,20,"------------------");
 int i,x=20,y=50;
 setfillstyle(1,15);
 setcolor(14);
 for(i=1;i<3;i++)
 {
   setfillstyle(1,0);
   bar3d(x+146,y,400,y+30,1,1);
   y=y+40;
 }
   bar3d(510,50,600,80,1,1); //roll no texxtbox
   bar3d(166,126,230,150,1,1); //class textbox
   bar3d(340,126,400,150,1,1); //gender textbox
   bar3d(166,170,400,200,1,1); //name of city
   bar3d(166,210,260,240,1,1); //Pincode
   bar3d(166,250,300,280,1,1); //Phone No.
   bar3d(166,290,400,340,1,1);
   setcolor(15);
   outtextxy(410,60,"Roll N0. : ");
   outtextxy(20,60,"Student's Name : ");
   outtextxy(26,100,"Father's Name : ");
   outtextxy(10,136,"Student's Class : ");
   outtextxy(240,136,"Gender(M/F): ");
   outtextxy(36,180,"Name of city : ");
   outtextxy(76,220,"Pincode : ");
   outtextxy(66,260,"Mob. No. : ");
   outtextxy(2,300,"Permament Address : ");
   setfillstyle(1,2);
   bar3d(0,360,getmaxx(),getmaxy(),1,1);

		  // Enter Student Name

 while(!kbhit())
 {
  setfillstyle(1,15);   //cursor point
  bar(170,68,178,70);
  setfillstyle(1,0);
  bar(170,68,178,70);
 }

 for(i=0;i<=3;i++)
 cprintf("\n");
 cprintf("                      ");

 while((ch=getch())!=13)
 {
   if(ch==8 && count>0)
   {
     setfillstyle(1,2);
     bar(200,400,450,450);
     count--;
     printf("\b \b");
   }
   else if(count>25)
   {
   sound(600);
   outtextxy(200,400,"Max 26 Character For Name !!");
   delay(106);
   nosound();
   }
   else if(ch!=8 && count<=25 && ch>64 && ch<91 || ch>96 && ch<123 || ch==32)
   {
   printf("%c",ch);
   moa.name[count++]=ch;
   }
   else
   {
   sound(600);
   delay(106);
   nosound();
    if(count==0)
    {
       while(!kbhit())
       {
	setfillstyle(1,15);   //cursor point
	bar(170,68,178,70);
       setfillstyle(1,0);
       bar(170,68,178,70);
       }
     }
   }

 }
 moa.name[count]='\0';

 setfillstyle(1,2);
 bar(200,400,450,450);
			   // Enter Roll Number
  while(!kbhit())
 {
  setfillstyle(1,15);   //cursor point
  bar(512,68,520,70);
  setfillstyle(1,0);
  bar(512,68,520,70);
 }
 for (i=0;i<count;i++)
 cprintf("\b");
 cprintf("                                          ");
 count=0;
 while((ch=getch())!=13)
 {
   if(ch==8 && count>0)
   {
     setfillstyle(1,2);
     bar(200,400,450,450);
     count--;
     printf("\b \b");
   }
   else if(ch!=8 && count<6 && ch>47 && ch<58 )
   {
   printf("%c",ch);
   moa.roll[count++]=ch;
   }
   else if(count>5)
   {
   sound(600);
   outtextxy(200,400,"Max 6 Digit For Roll Number !!");
   delay(106);
   nosound();
   }
    else
   {
   sound(600);
   delay(106);
   nosound();
    if(count==0)
    {
      while(!kbhit())
      {
	setfillstyle(1,15);   //cursor point
	bar(512,68,520,70);
	setfillstyle(1,0);
	bar(512,68,520,70);
      }
    }
   }
 }
 moa.roll[count]='\0';
 setfillstyle(1,2);
 bar(200,400,450,450);

		  //Father Name
 while(!kbhit())
 {
  setfillstyle(1,15);   //cursor point
  bar(170,110,178,112);
  setfillstyle(1,0);
  bar(170,110,178,112);
 }

 for(i=0;i<=count;i++)
 cprintf("\b");
 cprintf("\n");
 cprintf("                                       ");

 count=0;

 while((ch=getch())!=13)
 {
   if(ch==8 && count>0)
   {
     setfillstyle(1,2);
     bar(200,400,450,450);
     count--;
     printf("\b \b");
   }
   else if(count>25)
   {
   sound(600);
   outtextxy(200,400,"Max 26 Character For Father Name !!");
   delay(106);
   nosound();
   }
   else if(ch!=8 && count<=25 && ch>64 && ch<91 || ch>96 && ch<123 || ch==32)
   {
   printf("%c",ch);
   moa.father[count++]=ch;
   }
    else
   {
   sound(600);
   delay(106);
   nosound();
    if(count==0)
    {
      while(!kbhit())
     {
      setfillstyle(1,15);   //cursor point
      bar(170,110,178,112);
      setfillstyle(1,0);
      bar(170,110,178,112);
     }
    }
   }

 }
 moa.father[count]='\0';
 setfillstyle(1,2);
 bar(200,400,450,450);
			//Enter Class

 while(!kbhit())
 {
  setfillstyle(1,15);   //cursor point
  bar(170,144,178,146);
  setfillstyle(1,0);
  bar(170,144,178,146);
 }
 for (i=0;i<count;i++)
 cprintf("\b");
 cprintf("\n\n");
 cprintf("  ");
 count=0;
 while((ch=getch())!=13)
 {
   if(ch==8 && count>0)
   {
     setfillstyle(1,2);
     bar(200,400,450,450);
     count--;
     printf("\b \b");
   }
   else if(ch!=8 && count<1 && ch>47 && ch<58 )
   {
    printf("%c",ch);
    moa.clas[count++]=ch;
   }
   else if(count>0)
   {
   sound(600);
   outtextxy(200,400,"Max 1 Digit For Roll Number !!");
   delay(106);
   nosound();
   }
    else
   {
   sound(600);
   delay(106);
   nosound();
    if(count==0)
    {
     while(!kbhit())
     {
	setfillstyle(1,15);   //cursor point
	bar(170,144,178,146);
	setfillstyle(1,0);
	bar(170,144,178,146);
      }
    }
   }

 }
 moa.clas[count]='\0';
 setfillstyle(1,2);
 bar(200,400,450,450);

  struct moawwschool st;
  file=fopen("moawwsc.txt","rb");
  while(fread(&st,sizeof(st),1,file)==1)
  {
     if(strcmpi(st.clas,moa.clas)==0 && strcmpi(st.roll,moa.roll)==0)
     {
       InsertPopUp();
       fclose(file);
       getch();
       goto k;
     }
  }
     fclose(file);

	      //Enter Gender

  while(!kbhit())
 {
  setfillstyle(1,15);   //cursor point
  bar(350,144,356,146);
  setfillstyle(1,0);
  bar(350,144,356,146);
 }
 for (i=0;i<count;i++)
 cprintf("\b");
 cprintf("                     ");
 count=0;
 while((ch=getch())!=13)
 {
   if(ch==8 && count>0)
   {
     setfillstyle(1,2);
     bar(200,400,450,450);
     count--;
     printf("\b \b");
   }
   else if(ch!=8 && count<1 && ch==77 || ch==70 )
   {
    printf("%c",ch);
    moa.gender[count++]=ch;
   }
   else if(count>0)
   {
   sound(600);
   outtextxy(200,400,"Max 1 Char For Gender(M/F) !!");
   delay(106);
   nosound();
   }
    else
   {
   sound(600);
   delay(106);
   nosound();
    if(count==0)
    {
     while(!kbhit())
      {
       setfillstyle(1,15);   //cursor point
       bar(350,144,356,146);
       setfillstyle(1,0);
       bar(350,144,356,146);
      }
    }
   }

 }
 moa.gender[count]='\0';
 setfillstyle(1,2);
 bar(200,400,450,450);


	      //Enter Name of city

 while(!kbhit())
 {
  setfillstyle(1,15);   //cursor point
  bar(170,190,178,192);
  setfillstyle(1,0);
  bar(170,190,178,192);
 }


 for (i=0;i<count+23;i++)
 cprintf("\b");
 cprintf("\n\n\n");
 count=0;
 while((ch=getch())!=13)
 {
   if(ch==8 && count>0)
   {
     setfillstyle(1,2);
     bar(200,400,450,450);
     count--;
     printf("\b \b");
   }
    else if(count>25)
   {
   sound(600);
   outtextxy(200,400,"Max 26 Char For City Name !!");
   delay(106);
   nosound();
   }
   else if(ch!=8 && count<26 && ch>64 && ch<91 || ch>96 && ch<123 || ch==32 )
   {
    printf("%c",ch);
    moa.city[count++]=ch;
   }
    else
   {
   sound(600);
   delay(106);
   nosound();
    if(count==0)
    {
      while(!kbhit())
      {
       setfillstyle(1,15);   //cursor point
       bar(170,190,178,192);
       setfillstyle(1,0);
       bar(170,190,178,192);
      }
    }
   }
 }
 moa.city[count]='\0';
 setfillstyle(1,2);
 bar(200,400,450,450);
	      //Enter Pincode

 while(!kbhit())
 {
  setfillstyle(1,15);   //cursor point
  bar(170,236,178,234);
  setfillstyle(1,0);
  bar(170,236,178,234);
 }
 for (i=0;i<count;i++)
 cprintf("\b");
 cprintf("\n\n\n");
 count=0;
 while((ch=getch())!=13)
 {
   if(ch==8 && count>0)
   {
     setfillstyle(1,2);
     bar(200,400,450,450);
     count--;
     printf("\b \b");
   }
   else if(ch!=8 && count<8 && ch>47 && ch<58 )
   {
    printf("%c",ch);
    moa.pincode[count++]=ch;
   }
   else if(count>7)
   {
   sound(600);
   outtextxy(200,400,"Max 8 Digit For Roll Number !!");
   delay(106);
   nosound();
   }
   else
   {
    sound(500);
    delay(100);
    nosound();
    if(count==0)
    {
     while(!kbhit())
     {
	setfillstyle(1,15);   //cursor point
	bar(170,236,178,234);
	setfillstyle(1,0);
	bar(170,236,178,234);
     }
    }
   }
 }
 moa.pincode[count]='\0';
 setfillstyle(1,2);
 bar(200,400,450,450);

	      //Enter Mobile Number

 while(!kbhit())
 {
  setfillstyle(1,15);   //cursor point
  bar(170,270,178,272);
  setfillstyle(1,0);
  bar(170,270,178,272);
 }
 for (i=0;i<count;i++)
 cprintf("\b");
 cprintf("\n\n");
 count=0;
 while((ch=getch())!=13)
 {
   if(ch==8 && count>0)
   {
     setfillstyle(1,2);
     bar(200,400,450,450);
     count--;
     printf("\b \b");
   }
   else if(ch!=8 && count<10 && ch>47 && ch<58 )
   {
    printf("%c",ch);
    moa.mobile[count++]=ch;
   }
   else if(count>9)
   {
   sound(600);
   outtextxy(200,400,"Max 10 Digit For Mobile No.!!");
   delay(106);
   nosound();
   }
   else
   {
    sound(500);
    delay(100);
    nosound();
    if(count==0)
    {
     while(!kbhit())
     {
	setfillstyle(1,15);   //cursor point
	bar(170,270,178,272);
	setfillstyle(1,0);
	bar(170,270,178,272);
       }
    }
   }
 }
 moa.mobile[count]='\0';
 setfillstyle(1,2);
 bar(200,400,450,450);
		//Enter Address

 while(!kbhit())
 {
  setfillstyle(1,15);   //cursor point
  bar(170,304,178,306);
  setfillstyle(1,0);
  bar(170,304,178,306);
 }

 for(i=0;i<=count;i++)
 cprintf("\b");
 cprintf("\n\n\n");
 count=0;
 while((ch=getch())!=13)
 {
   if(ch==8 && count>0)
   {
     setfillstyle(1,2);
     bar(200,400,450,450);
     count--;
     printf("\b \b");
   }
   else if(count>27)
   {
   sound(600);
   outtextxy(200,400,"Max 20 Character For Address !!");
   delay(106);
   nosound();
   }
   else if(ch!=8 && count<28)
   {
   printf("%c",ch);
   moa.address[count++]=ch;
   }
  }
   moa.address[count]='\0';
   setfillstyle(1,2);
   bar(200,400,450,450);
   file=fopen("moawwsc.txt","ab");
   fwrite(&moa,sizeof(moa),1,file);
   fclose(file);
   outtextxy(200,420,"Add Record Sucessfully");
   getch();
}

void showRecords()
{
  int i=1,rc=0;
  char key;
  struct moawwschool sr[2];
  cleardevice();
  printf("\n");
  file=fopen("moawwsc.txt","rb");
  displayGraph();
  while(fread(&moa,sizeof(moa),1,file))
  {
	settextstyle(2,0,6);
	setcolor(15);
	outtextxy(200,6,"All STUDENT'S RECORD");
	outtextxy(200,16,"-------------------");
	settextstyle(12,0,6);
	outtextxy(10,40+rc,"Name : ");
	outtextxy(80,40+rc,moa.name);
	outtextxy(300,40+rc,"Father : " );
	outtextxy(380,40+rc,moa.father);
	outtextxy(10,70+rc,"Roll No. : ");
	outtextxy(120,70+rc,moa.roll);
	outtextxy(300,70+rc,"Class : ");
	outtextxy(380,70+rc,moa.clas);
	outtextxy(420,70+rc,"Gender : ");
	outtextxy(520,70+rc,moa.gender);
	outtextxy(10,100+rc,"City : ");
	outtextxy(80,100+rc,moa.city);
	outtextxy(300,100+rc,"Pincode :");
	outtextxy(400,100+rc,moa.pincode);
	outtextxy(10,130+rc,"Mob No. : ");
	outtextxy(100,130+rc,moa.mobile);
	outtextxy(300,130+rc,"Address : ");
	outtextxy(400,130+rc,moa.address);
	setcolor(14);
	outtextxy(10,getmaxy()-20,"Press Esc to Back Menu");
	outtextxy(360,getmaxy()-20,"Press [ Enter] to Next Page");
	rc+=140;
	i++;
	if(i>3)
	{
	 key=getch();
	 if(key=='\033')
	 return;
	 else if(key==13)
	 {
	  cleardevice();
	  displayGraph();
	  rc=0;
	  i=1;
	 }
	}
 }
  fclose(file);
  getch();
}
		    //Display Graphics coding
void displayGraph()
{
 int y=0,i;
 for(i=0;i<150;i++)
 {
 setfillstyle(1,1);
 bar(0,30,getmaxx(),30+y+i);
 setfillstyle(1,4);
 bar(0,170,getmaxx(),170+i);
 setfillstyle(1,2);
 bar(0,310,getmaxx(),300+i);
 delay(5);
 }
 for(i=0;i<getmaxx();i++)
 {
   setcolor(15);
   setfillstyle(1,12);
   bar3d(0,0,i,30,1,0); //Top Caption
   bar3d(0,450,i,476,1,0); //bottom Caption
 }
}

		    //Search Graph Coding....

void searchGraph()
{
  int i;
  setfillstyle(1,4);
  for(i=0;i<getmaxx();i++)
  bar3d(0,0,i,40,1,0);
  setfillstyle(1,12);
  for(i=0;i<getmaxy();i++)
  bar3d(0,40,getmaxx(),40+i,1,0);
  setfillstyle(1,0);
  for(i=0;i<220;i++)
  bar3d(150,6,150+i,36,1,0); //textbox of search

}


		   //Search on Name Coding Start

void searchRecordName()
{
 char name[26],flag=0,ch,key;
 int count=0,i=1,rc=0;
 clrscr();
 searchGraph();
 setfillstyle(1,1);
 bar(0,40,getmaxx(),getmaxy());
 settextstyle(2,0,4);
 outtextxy(6,12,"Enter Student's Name : ");
 while(!kbhit())
 {
  setfillstyle(1,15);   //cursor point
  bar(164,26,172,24);
  setfillstyle(1,0);
  bar(164,26,172,24);
 }
 cprintf("\n                    ");

 while((ch=getch())!=13)
 {
   if(ch==8 && count>0)
   {
     setfillstyle(1,4);
     bar(376,12,600,28);
     count--;
     printf("\b \b");
   }
   else if(count>25)
   {
   sound(600);
   outtextxy(380,16,"Max 26 Character For Name !!");
   delay(106);
   nosound();
   }
   else if(ch!=8 && count<=25 && ch>64 && ch<91 || ch>96 && ch<123 || ch==32)
   {
   printf("%c",ch);
   name[count++]=ch;
   }
   else
   {
    sound(500);
    delay(100);
    nosound();
    if(count==0)
    {
     while(!kbhit())
     {
      setfillstyle(1,15);   //cursor point
      bar(164,26,172,24);
      setfillstyle(1,0);
      bar(164,26,172,24);
     }
    }
   }

 }
 name[count]='\0';
 bar(376,12,600,28);

 file=fopen("moawwsc.txt","rb");
 while(fread(&moa,sizeof(moa),1,file)==1)
 {
   if(strcmpi(moa.name,name)==0)
   {
	setcolor(15);
	settextstyle(2,0,6);
	outtextxy(10,40+rc,"Name : ");
	outtextxy(80,40+rc,moa.name);
	outtextxy(300,40+rc,"Father : " );
	outtextxy(380,40+rc,moa.father);
	outtextxy(10,70+rc,"Roll No. : ");
	outtextxy(120,70+rc,moa.roll);
	outtextxy(300,70+rc,"Class : ");
	outtextxy(380,70+rc,moa.clas);
	outtextxy(420,70+rc,"Gender : ");
	outtextxy(520,70+rc,moa.gender);
	outtextxy(10,100+rc,"City : ");
	outtextxy(80,100+rc,moa.city);
	outtextxy(300,100+rc,"Pincode :");
	outtextxy(400,100+rc,moa.pincode);
	outtextxy(10,130+rc,"Address : ");
	outtextxy(100,130+rc,moa.address);
	setcolor(14);
	outtextxy(10,getmaxy()-30,"Press Esc to Back Menu");
	outtextxy(360,getmaxy()-30,"Press [ Enter] to Next Page");
	outtextxy(380,12,"Record Found Successfully");
	rc+=140;
	i++;
	if(i>3)
	{
	 key=getch();
	 if(key=='\033')
	 {
	  cleardevice();
	  menuLoading();
	 }
	 else if(key==13)
	 {
	  cleardevice();
	  setfillstyle(1,1);
	  bar(0,40,getmaxx(),getmaxy());
	  bar3d(0,40,getmaxx(),0,1,0);
	  outtextxy(20,10,"Name : ");
	  outtextxy(120,10,moa.name);
	  rc=0;
	  i=1;
	 }
	}
	flag=1;
    }
}
    if(flag==0)
    outtextxy(380,13,"Record Not Found");
    fclose(file);
    getch();
}

			//Search Record on Roll Coding.......

void searchRecordRoll()
{
 cleardevice();
 char roll[26],flag=0,ch,key;
 int count=0,i=1,rc=0;
 clrscr();
 searchGraph();
 settextstyle(2,0,4);
 outtextxy(6,12,"Enter Student's Roll : ");
 while(!kbhit())
 {
  setfillstyle(1,15);   //cursor point
  bar(164,26,172,24);
  setfillstyle(1,0);
  bar(164,26,172,24);
 }
 cprintf("\n                    ");
 while((ch=getch())!=13)
 {
   if(ch==8 && count>0)
   {
     setfillstyle(1,4);
     bar(376,12,600,28);
     count--;
     printf("\b \b");
   }
   else if(ch!=8 && count<6 && ch>47 && ch<58 )
   {
   printf("%c",ch);
   roll[count++]=ch;
   }
   else if(count>5)
   {
   sound(600);
   outtextxy(380,13,"Max 6 Digit For Roll No. !!");
   delay(106);
   nosound();
   }
 }
  roll[count]='\0';
  bar(376,12,600,28);


 file=fopen("moawwsc.txt","rb");
 while(fread(&moa,sizeof(moa),1,file)==1)
 {
   if(strcmpi(moa.roll,roll)==0)
   {
	setcolor(15);
	settextstyle(2,0,6);
	outtextxy(10,40+rc,"Name : ");
	outtextxy(80,40+rc,moa.name);
	outtextxy(300,40+rc,"Father : " );
	outtextxy(380,40+rc,moa.father);
	outtextxy(10,70+rc,"Roll No. : ");
	outtextxy(120,70+rc,moa.roll);
	outtextxy(300,70+rc,"Class : ");
	outtextxy(380,70+rc,moa.clas);
	outtextxy(420,70+rc,"Gender : ");
	outtextxy(520,70+rc,moa.gender);
	outtextxy(10,100+rc,"City : ");
	outtextxy(80,100+rc,moa.city);
	outtextxy(300,100+rc,"Pincode :");
	outtextxy(400,100+rc,moa.pincode);
	outtextxy(10,130+rc,"Address : ");
	outtextxy(100,130+rc,moa.address);
	setcolor(14);
	outtextxy(10,getmaxy()-30,"Press Esc to Back Menu");
	outtextxy(360,getmaxy()-30,"Press [ Enter] to Next Page");
	outtextxy(380,12,"Record Found Successfully");
	rc+=140;
	i++;
	if(i>3)
	{
	 key=getch();
	 if(key=='\033')
	 {
	  cleardevice();
	  menuLoading();
	 }
	 else if(key==13)
	 {
	  cleardevice();
	  searchGraph();
	  rc=0;
	  i=1;
	 }
	}
	flag=1;
    }
}
    if(flag==0)
    outtextxy(380,13,"Record Not Found");
    fclose(file);
    getch();

}
			//Search Pop-Up Coding Start.......

void searchPopUp()
{

   int i,select=0;
   char keyh;
   setcolor(14);
   setfillstyle(1,6);
   for(i=0;i<=90;i++)
   {
   bar3d(150,200,450,200+i,1,2);
   delay(6);
   }
   setcolor(15);
   outtextxy(200,250,"Name");
   outtextxy(320,250,"Roll");
   setfillstyle(1,12);
   bar3d(160,210,280,280,1,0);
   bar3d(310,210,440,280,1,0);
   searchPopUpselect(select);
   do
  {
    keyh=getch();
    if(keyh==75)//left
    {
    select++;
    if(select>1)
    select=0;

    }
    if(keyh==77)//right
    {
     select--;
     if(select<0)
     select=1;
    }
    if(keyh==13)
    {
     if(select==0)
     {
      cleardevice();
      searchRecordName();
      cleardevice();
      menu(select);
      break;
     }
     else if(select==1)
     {
      cleardevice();
      searchRecordRoll();
      cleardevice();
      menu(select);
      break;
      }
    }
    if(keyh=='\033')
    {
      cleardevice();
      menu(select);
      break;
    }

    searchPopUpselect(select);
  }while(2);

}
void searchPopUpselect(int select)
{
  int i,x=160,y=210,x1=280,y1=280;
  setcolor(15);
  settextstyle(2,0,6);
  char ar[][30]={"Name ","Roll"};
  for(i=0;i<2;i++)
  {
   if(i==select)
   setfillstyle(1,4);
   else
   setfillstyle(1,2);
   bar3d(x,y,x1,y1,1,1);
   outtextxy(x+40,y+20,ar[i]);
   x=x+150;
   x1=x1+160;
  }
}
			 //Modify Field Coding
void modifyRecord()
{
 l:
 settextstyle(15,0,2);
 char ch,roll[6],clas[1];
 int count=0,flag=0;
 clrscr();
 cleardevice();
 searchGraph();
 setfillstyle(1,4);
 bar3d(0,0,getmaxx(),40,1,0);
 setfillstyle(1,0);
 bar3d(180,6,280,36,1,0);
 bar3d(290,6,350,36,1,0);
 outtextxy(10,16,"Enter Roll & Class :");



  while(!kbhit())
 {
  setfillstyle(1,15);   //cursor point
  bar(184,26,190,24);
  setfillstyle(1,0);
  bar(184,26,190,24);
 }
 cprintf("\n                          ");
 while((ch=getch())!=13)
 {
   if(ch==8 && count>0)
   {
     setfillstyle(1,4);
     bar(376,12,600,28);
     count--;
     printf("\b \b");
   }
   else if(ch!=8 && count<6 && ch>47 && ch<58 )
   {
   printf("%c",ch);
   roll[count++]=ch;
   }
   else if(count>5)
   {
   sound(600);
   outtextxy(380,13,"Max 6 Digit For Roll No. !!");
   delay(106);
   nosound();
   }
 }
  roll[count]='\0';
  setfillstyle(1,4);
  bar(376,12,600,28);
 while(!kbhit())
 {
  setfillstyle(1,15);   //cursor point
  bar(294,26,300,24);
  setfillstyle(1,0);
  bar(294,26,300,24);
 }
 int i;
 for (i=0;i<count;i++)
 cprintf("\b");
 cprintf("            ");
 count=0;
 while((ch=getch())!=13)
 {
   if(ch==8 && count>0)
   {
     setfillstyle(1,4);
     bar(376,12,600,28);
     count--;
     printf("\b \b");
   }
   else if(ch!=8 && count<1 && ch>47 && ch<58 )
   {
    printf("%c",ch);
    clas[count++]=ch;
   }
   else if(count>0)
   {
   sound(600);
   outtextxy(200,400,"Max 1 Digit For Clas !!");
   delay(106);

   nosound();
   }
 }
 clas[count]='\0';
 setfillstyle(1,4);
 bar(376,12,600,28);

 file=fopen("moawwsc.txt","rb+");
 while(fread(&moa,sizeof(moa),1,file)==1)
 {
   if(strcmpi(moa.roll,roll)==0 && strcmpi(moa.clas,clas)==0)
   {

       textBox();
       outtextxy(380,13,"Record Found Successfully");
       outtextxy(516,65,moa.roll);
       outtextxy(180,138,moa.clas);
	   // Enter Student Name

	while(!kbhit())
	{
	 setfillstyle(1,15);   //cursor point
	 bar(170,68,178,70);
	 setfillstyle(1,0);
	 bar(170,68,178,70);
	}

 for(i=0;i<=7;i++)
 cprintf("\b\b");
 cprintf("\n\n\n");

 count=0;
 while((ch=getch())!=13)
 {
   if(ch==8 && count>0)
   {
     setfillstyle(1,12);
     bar(200,400,450,450);
     count--;
     printf("\b \b");
   }
   else if(count>25)
   {
   sound(600);
   outtextxy(200,400,"Max 26 Character For Name !!");
   delay(106);
   nosound();
   }
   else if(ch!=8 && count<=25 && ch>64 && ch<91 || ch>96 && ch<123 || ch==32)
   {
   printf("%c",ch);
   moa.name[count++]=ch;
   }
   else
    {
    sound(600);
    delay(106);
    nosound();
     if(count==0)
     {
	while(!kbhit())
	{
	 setfillstyle(1,15);   //cursor point
	 bar(170,68,178,70);
	 setfillstyle(1,0);
	 bar(170,68,178,70);
	}
     }
    }

 }
 moa.name[count]='\0';
 setfillstyle(1,12);
 bar(200,400,450,450);
			   // Enter Roll Number

 for (i=0;i<count;i++)
 cprintf("\b");
 cprintf("                                          ");
 count=0;

		  //Father Name
 while(!kbhit())
 {
  setfillstyle(1,15);   //cursor point
  bar(170,110,178,112);
  setfillstyle(1,0);
  bar(170,110,178,112);
 }

 for(i=0;i<=count;i++)
 cprintf("\b");
 cprintf("\n");
 cprintf("                                       ");

 count=0;

 while((ch=getch())!=13)
 {
   if(ch==8 && count>0)
   {
     setfillstyle(1,12);
     bar(200,400,450,450);
     count--;
     printf("\b \b");
   }
   else if(count>25)
   {
   sound(600);
   outtextxy(200,400,"Max 26 Character For Name !!");
   delay(106);
   nosound();
   }
   else if(ch!=8 && count<=25 && ch>64 && ch<91 || ch>96 && ch<123 || ch==32)
   {
   printf("%c",ch);
   moa.father[count++]=ch;
   }
   else
   {
    sound(600);
    delay(106);
    nosound();
     if(count==0)
     {
       while(!kbhit())
      {
       setfillstyle(1,15);   //cursor point
       bar(170,110,178,112);
       setfillstyle(1,0);
       bar(170,110,178,112);
       }
     }

   }
 }
 moa.father[count]='\0';
 setfillstyle(1,12);
 bar(200,400,450,450);

	      //Enter Gender

  while(!kbhit())
 {
  setfillstyle(1,15);   //cursor point
  bar(350,144,356,146);
  setfillstyle(1,0);
  bar(350,144,356,146);
 }
 for (i=0;i<count;i++)
 cprintf("\b");
 cprintf("\n\n");
 cprintf("                       ");
 count=0;
 while((ch=getch())!=13)
 {
   if(ch==8 && count>0)
   {
     setfillstyle(1,12);
     bar(200,400,450,450);
     count--;
     printf("\b \b");
   }
   else if(ch!=8 && count<1 && ch==77 || ch==70 )
   {
    printf("%c",ch);
    moa.gender[count++]=ch;
   }
   else if(count>0)
   {
   sound(600);
   outtextxy(200,400,"Max 1 Char For Gender(M/F) !!");
   delay(106);
   nosound();
   }
   else
   {
     sound(600);
     delay(106);
     nosound();
     if(count==0)
     {
     while(!kbhit())
      {
       setfillstyle(1,15);   //cursor point
       bar(350,144,356,146);
       setfillstyle(1,0);
       bar(350,144,356,146);
      }
     }
   }
 }
 moa.gender[count]='\0';
 setfillstyle(1,12);
 bar(200,400,450,450);
	      //Enter Name of city

 while(!kbhit())
 {
  setfillstyle(1,15);   //cursor point
  bar(170,190,178,192);
  setfillstyle(1,0);
  bar(170,190,178,192);
 }


 for (i=0;i<count+23;i++)
 cprintf("\b");
 cprintf("\n\n\n");
 count=0;
 while((ch=getch())!=13)
 {
   if(ch==8 && count>0)
   {
     setfillstyle(1,12);
     bar(200,400,450,450);
     count--;
     printf("\b \b");
   }
    else if(count>25)
   {
   sound(600);
   outtextxy(200,400,"Max 26 Char For City Name !!");
   delay(106);
   nosound();
   }
   else if(ch!=8 && count<26 && ch>64 && ch<91 || ch>96 && ch<123 || ch==32 )
   {
    printf("%c",ch);
    moa.city[count++]=ch;
   }
   else
   {
    sound(600);
    delay(106);
    nosound();
    if(count==0)
    {
      while(!kbhit())
      {
       setfillstyle(1,15);   //cursor point
       bar(170,190,178,192);
       setfillstyle(1,0);
       bar(170,190,178,192);
      }
    }
   }
 }
 moa.city[count]='\0';
 setfillstyle(1,12);
 bar(200,400,450,450);
	      //Enter Pincode

 while(!kbhit())
 {
  setfillstyle(1,15);   //cursor point
  bar(170,236,178,234);
  setfillstyle(1,0);
  bar(170,236,178,234);
 }
 for (i=0;i<count;i++)
 cprintf("\b");
 cprintf("\n\n\n");
 cprintf("\b");
 count=0;
 while((ch=getch())!=13)
 {
   if(ch==8 && count>0)
   {
     setfillstyle(1,12);
     bar(200,400,450,450);
     count--;
     printf("\b \b");
   }
   else if(ch!=8 && count<8 && ch>47 && ch<58 )
   {
    printf("%c",ch);
    moa.pincode[count++]=ch;
   }
   else if(count>7)
   {
   sound(600);
   outtextxy(200,400,"Max 8 Digit For Roll Number !!");
   delay(106);
   nosound();
   }
   else
   {
    sound(500);
    delay(100);
    nosound();
    if(count==0)
    {
     while(!kbhit())
     {
	setfillstyle(1,15);   //cursor point
	bar(170,236,178,234);
	setfillstyle(1,0);
	bar(170,236,178,234);
     }
    }
   }
 }
 moa.pincode[count]='\0';
 setfillstyle(1,12);
 bar(200,400,450,450);

	      //Enter Mobile Number

 while(!kbhit())
 {
  setfillstyle(1,15);   //cursor point
  bar(170,270,178,272);
  setfillstyle(1,0);
  bar(170,270,178,272);
 }
 for (i=0;i<count;i++)
 cprintf("\b");
 cprintf("\n\n");
 count=0;
 while((ch=getch())!=13)
 {
   if(ch==8 && count>0)
   {
     setfillstyle(1,12);
     bar(200,400,450,450);
     count--;
     printf("\b \b");
   }
   else if(ch!=8 && count<10 && ch>47 && ch<58 )
   {
    printf("%c",ch);
    moa.mobile[count++]=ch;
   }
   else if(count>9)
   {
   sound(600);
   outtextxy(200,400,"Max 10 Digit For Mobile No.!!");
   delay(106);
   nosound();
   }
   else
   {
    sound(500);
    delay(100);
    nosound();
    if(count==0)
    {
     while(!kbhit())
     {
	setfillstyle(1,15);   //cursor point
	bar(170,270,178,272);
	setfillstyle(1,0);
	bar(170,270,178,272);
       }
    }
   }
 }
 moa.mobile[count]='\0';
 setfillstyle(1,12);
 bar(200,400,450,450);
		//Enter Address

 while(!kbhit())
 {
  setfillstyle(1,15);   //cursor point
  bar(170,304,178,306);
  setfillstyle(1,0);
  bar(170,304,178,306);
 }

 for(i=0;i<=count;i++)
 cprintf("\b");
 cprintf("\n\n\n ");
 count=0;
 while((ch=getch())!=13)
 {
   if(ch==8 && count>0)
   {
     setfillstyle(1,12);
     bar(200,400,450,450);
     count--;
     printf("\b \b");
   }
   else if(count>27)
   {
   sound(600);
   outtextxy(200,400,"Max 20 Character For Address !!");
   delay(106);
   nosound();
   }
   else if(ch!=8 && count<28)
   {
   printf("%c",ch);
   moa.address[count++]=ch;
   }
   }
   moa.address[count]='\0';
   setfillstyle(1,12);
   bar(200,400,450,450);
   fseek(file,-size,1);
   fwrite(&moa,sizeof(moa),1,file);
   flag=1;
   break;
   }  }
   setfillstyle(1,4);
   bar(376,12,600,28);
    setcolor(15);
    if(flag==0)
    outtextxy(380,13,"Record Not Found");
    else
    outtextxy(380,13,"Record Modified Successful");
    fclose(file);
    getch();
}

		      //textbox Coding Start
void textBox()
{
 int i,x=20,y=50;
 settextstyle(12,0,2);
 setfillstyle(1,15);
 setcolor(14);
 for(i=1;i<3;i++)
 {
   setfillstyle(1,0);
   bar3d(x+146,y,400,y+30,1,1);
   y=y+40;
 }
   bar3d(510,50,600,80,1,1); //roll no texxtbox
   bar3d(166,126,230,150,1,1); //class textbox
   bar3d(340,126,400,150,1,1); //gender textbox
   bar3d(166,170,400,200,1,1); //name of city
   bar3d(166,210,260,240,1,1); //Pincode
   bar3d(166,250,300,280,1,1); //Phone No.
   bar3d(166,290,400,340,1,1);
   setcolor(15);
   outtextxy(410,60,"Roll N0. : ");
   outtextxy(20,60,"Student's Name : ");
   outtextxy(26,100,"Father's Name : ");
   outtextxy(10,136,"Student's Class : ");
   outtextxy(240,136,"Gender(M/F): ");
   outtextxy(36,180,"Name of city : ");
   outtextxy(76,220,"Pincode : ");
   outtextxy(66,260,"Mob. No. : ");
   outtextxy(2,300,"Permament Address : ");
}

			//Delete Record Coding Start.......
void deleteRecord()
{

 char ch,roll[6],clas[1];
 int count=0,flag=0,i=0;
 settextstyle(2,0,4);
 clrscr();
 cleardevice();
 //searchGraph();
 setfillstyle(1,4);
 bar3d(0,0,getmaxx(),40,1,0);
 setfillstyle(1,0);
 bar3d(180,6,280,36,1,0);
 bar3d(290,6,350,36,1,0);
 outtextxy(10,16,"Enter Roll & Class :");

  count=0;
  while(!kbhit())
 {
  setfillstyle(1,15);   //cursor point
  bar(184,26,190,24);
  setfillstyle(1,0);
  bar(184,26,190,24);
 }
 cprintf("\n                          ");
 while((ch=getch())!=13)
 {
   if(ch==8 && count>0)
   {
     setfillstyle(1,4);
     bar(376,12,600,28);
     count--;
     printf("\b \b");
   }
   else if(ch!=8 && count<6 && ch>47 && ch<58 )
   {
   printf("%c",ch);
   roll[count++]=ch;
   }
   else if(count>5)
   {
   sound(600);
   outtextxy(380,13,"Max 6 Digit For Roll No. !!");
   delay(106);
   nosound();
   }
 }
  roll[count]='\0';
  setfillstyle(1,4);
  bar(376,12,600,28);

 while(!kbhit())
 {
  setfillstyle(1,15);   //cursor point
  bar(294,26,300,24);
  setfillstyle(1,0);
  bar(294,26,300,24);
 }
 for (i=0;i<count;i++)
 cprintf("\b");
 cprintf("            ");
 count=0;
 while((ch=getch())!=13)
 {
   if(ch==8 && count>0)
   {
     setfillstyle(1,4);
     bar(376,12,600,28);
     count--;
     printf("\b \b");
   }
   else if(ch!=8 && count<1 && ch>47 && ch<58 )
   {
    printf("%c",ch);
    clas[count++]=ch;
   }
   else if(count>0)
   {
   sound(600);
   outtextxy(380,12,"Max 1 Digit For Clas !!");
   delay(106);
   nosound();
   }
 }
 clas[count]='\0';
 setfillstyle(1,4);
 bar(376,12,600,28);

 FILE *ftemp;
 file=fopen("moawwsc.txt","rb");
 ftemp=fopen("moawwtemp.txt","ab");
 while(fread(&moa,sizeof(moa),1,file)==1)
 {
   if(!(strcmpi(moa.roll,roll)==0 && strcmpi(moa.clas,clas)==0))
   {
   fwrite(&moa,sizeof(moa),1,ftemp);
   }
   else
   {
	outtextxy(380,12,"Record Found Successfully");
	setcolor(14);
	settextstyle(2,0,6);
	bar3d(220,120,400,150,1,0);
	outtextxy(230,130," Data Deleting...");
	setfillstyle(1,0);
	for(i=0;i<160;i++)
	{
	 bar3d(80,150,580,150+i,1,0);
	  delay(6);
	}
	setcolor(11);
	outtextxy(200,200,"Name : ");
	outtextxy(300,200,moa.name);
	delay(606);
	bar(100,166,560,280);	outtextxy(200,200,"Father : " );
	outtextxy(300,200,moa.father);
	delay(606);
	bar(100,166,560,280);	outtextxy(200,200,"Roll No. : ");
	outtextxy(300,200,moa.roll);
	delay(606);
	bar(100,166,560,280);	outtextxy(200,200,"Class : ");
	outtextxy(300,200,moa.clas);
	delay(606);
	bar(100,166,560,280);
	outtextxy(200,200,"Gender : ");
	outtextxy(300,200,moa.gender);
	delay(606);
	bar(100,166,560,280);	outtextxy(200,200,"City : ");
	outtextxy(300,200,moa.city);
	delay(606);
	bar(100,166,560,280);	outtextxy(200,200,"Pincode :");
	outtextxy(300,200,moa.pincode);
	delay(606);
	bar(100,166,560,280);	outtextxy(200,200,"Address : ");
	outtextxy(300,200,moa.address);
	delay(606);
	bar(100,166,560,280);
	flag=1;
	setcolor(14);
	bar3d(220,120,400,150,1,1);
	setcolor(2);
	delay(106);
	outtextxy(230,130,"  Data Deleted...");
	settextstyle(6,0,4);
	outtextxy(160,200,"Record Delete Successfully");
   }
 }

    if(flag==0)
    outtextxy(380,12,"Record Not Found");

   fclose(file);
   fclose(ftemp);
   remove("moawwsc.txt");
   rename("moawwtemp.txt","moawwsc.txt");
   getch();
}

		     //About of Developer Coding....
void aboutdeveloper()
{
  clrscr();
  cleardevice();
  setbkcolor(6);
  int i,sp=20;
  char ab[][18]={"A","B","O","U","T"," ","O","F"," ","D","E","V","E","L","O","P","E","R"};
  char ul[][18]={"-","-","-","-","-"," ","-","-"," ","-","-","-","-","-","-","-","-","-"};
  char usman[]={"I am Md.Usman Ansari I belong to Gaya city.I am study in under graduation from\n Mirza Ghalib College,Gaya\n\n COMING TO TECHNICAL SKILLS:-\n ----------------------------\n\t\t\t     I have knowladge on Photoshop,Visual Basic, C lang.\n Web-Designing.\n\n COMING TO MY HOBBIES:-\n ------------------------\n\t\t   I am very intrested in Martial Arts,Graphics Design and\n learn new technology daily.I will do physical workouts and Martial Arts\n training to be fit Myself.\n\n COMING TO STRENGHT:-\n -----------------------\n\t\t   Self motivated and very interested acceptance challenging.\n\n COMING TO WEAKNESS:-\n -----------------\n\t\t My weakness to much simple attitude on front of other people.\n\t\t\t\ <<< THAT'S ALL ABOUT ME >>>"};

  for(i=80;i<getmaxx()-100;i++)
  bar3d(80,20,i,60,1,0);
  settextstyle(1,0,3);
  setcolor(15);
  for(i=0;i<18;i++)
  {
   outtextxy(130+sp,20,ab[i]);
   outtextxy(130+sp,30,ul[i]);
   sp+=20;
   delay(36);
  }
   settextstyle(7,0,2);
   outtextxy(80,60,"FIRST A FAR THANKS TO ALMIGHTY ALLAH");
   outtextxy(80,70,"----------------------------------------");
   settextstyle(5,0,2);
   cprintf("\n\n\n\n\n\n\t");
  for(i=0;i<706;i++)
  {
   printf("%c",usman[i]);
   delay(16);
  }
   getch();
   setbkcolor(0);
}


