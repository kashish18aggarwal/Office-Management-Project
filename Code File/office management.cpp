#include <iostream>
#include<windows.h>
#include <conio.h>
#include<string>
#include<regex>
using namespace std;
class Student{
    private:
        char name[20], course[10];
        char grade;
        string roll;
        char attend;
        char lastAttend;
    public:
        //Student(){}   /// Default Constructer
        Student()
        {
            lastAttend=' ';
        }
        int  marks;
        void markAttend();
        void showAttend();
        void markLastAttend();
        void showLastAttend();
        void getinfo();
        void compute();
        string getRoll();
        void display();
        void evaluate();
};
/*void Student :: markLastAttendS(char s)
{
    lastAttend=s;
}*/
void Student:: markLastAttend()
{
    char c;
    cin>>c;
    lastAttend=c;
}
//void Student::showLastAttend()
void Student:: showLastAttend()
{
    cout<<lastAttend;
}
void Student :: markAttend()
{
    cin>>attend;
}
void Student:: showAttend()
{
    cout<<attend;
}
string Student:: getRoll()
{
    return roll;
}

void Student :: getinfo()
{
    cout<<"\n Enter Name: ";
    cin>>name;
    cout<<"\n Roll no: ";
    cin>>roll;
    cout<<"\n Enter Course: ";
    cin>>course;
   // cout<<"\n Enter Marks Obtained (out of 500): ";
    //cin>> marks;
}

void Student :: compute()
{
    int per;
    per = marks/5;
    if(per >= 80)
        grade = 'A';
    else if( (per < 80) && (per >= 60) )
        grade = 'B';
    else if( (per < 60) && (per >= 40) )
        grade = 'C';
    else
        grade = 'D';
}

void Student :: display()
{
    cout<<"\n Name: "<<name;
    cout<<"\t Roll no: "<<roll;
    cout<<"\t Course: "<<course;
    cout<<"\t Marks: "<<marks;
    cout<<"\t Grade: "<<grade;
}

void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);

}
bool passwordValid(string s)
{
    bool upper = false;
    bool lower = false;
    bool number = false;
    bool special = false;


    regex upperExp{ "[A-Z]+" };
    regex lowerExp{ "[a-z]+" };
    regex numberExp{ "[0-9]+" };
    regex specialExp{ "[@!?%$&#]+"};

    if(s.length() <= 8)
    { //too short!
        return false;
    }
    else
    {
        upper=regex_search(s, upperExp); //save the result, if the expression was found.
        lower=regex_search(s, lowerExp); //....
        number=regex_search(s, numberExp);
        special=regex_search(s, specialExp);
            //like: sum_of_positive_results = 1 + 0 + 1 + 1 (true/false as an integer)
        int res=upper+lower+number+special;

        if (res<4)
        { //not enough booleans were true!
            return false;
        }
        else
        {
            return true;
        }
    }

}
bool userValid(string s)
{
    bool upper = false;
    bool lower = false;
    bool number = false;
    bool special=false;
    regex upperExp{ "[A-Z]+" };
    regex lowerExp{ "[a-z]+" };
    regex numberExp{ "[0-9]+" };
    regex specialExp{ "[@!?%$&#]+"};
    upper=regex_search(s, upperExp);
    lower=regex_search(s, lowerExp);
   // number=regex_search(s, numberExp);
    //special=regex_search(s, specialExp);
   // if(special==true)
     //   return false;
    int res=upper+lower+number;
    if(res==2)
        return true;
    else
        return false;



}


int main()
{
    int n = 0,flag=0;
    char ch=' ';
    Student S[10];             // Creating Object.
    system("cls");

    /// Login
    string user;
    string pass;
    cout<<"Username: ";
    getline(cin,user);
    cout<<"Enter password: ";
    getline(cin,pass);

    if(userValid(user)==false)
    {
        cout<<"\n\nInvalid username\n\n";
        cout<<"\n\n Press Any Key to Exit ...\n\n";
        _getch();
        exit(0);
    }
    else
    if(passwordValid(pass)==false)
    {
        cout<<"\n\nInvalid password\n\n";
        cout<<"\n\n Press Any Key to Exit ...\n\n";
        _getch();
        exit(0);
    }
    else
    {
        cout<<"\n\nLogin successfully\n";
        cout<<"Press enter to continue";
        _getch();
        mainpage:
        system("cls");
        cout<<"\n\n\n\n\t\t\t-:WELCOME TO UIET:-\n\n\n";
        cout<<"1 Attendance\n";
        cout<<"2 result\n";
        cout<<"3 Fee Status\n";
        cout<<"0 exit\n";
        int l;
        cout<<"ENTER YOUR CHOICE: ";
        cin>>l;
        _getch();
        system("cls");
        switch(l)
        {
            case(1):
            {
                if(flag==0)
                {
                    while(ch != 'n')
                    {
                          // Getting Information.
                        gotoxy(25, 5);
                        cout<<"-: STUDENT INFORMATION :- \n";
                        cout<<"\n Entry No. :"<<n+1<<endl;
                        S[n].getinfo();
            //S[n].compute();              // Calculate Grade.
                        cout<<"\n Next Student (y/n): ";
                        cin>>ch;
                        n++;
                        system("cls");
                        flag=1;
                    }
                }

        ///   Attendence //////////////////////////////////


                cout<<"Mark ATTENDENCE\n\n";
                cout<<"Press enter to mark attendence\n\n";
                _getch();
                for(int i=0;i<n;i++)
                {
                    string first=S[i].getRoll();
                    cout<<first<<": ";
                    if(first[0]=='S')
                    {
                        S[i].markAttend();
                    }
                    else if(first[0]=='T')
                    {
                        char a;
                        S[i].markAttend();
                        cout<<"Do you want to mark yesterday's Attendence?(y/n) ";
                        cin>>a;
                        if(a=='y')
                            S[i].markLastAttend();
                    }
                }

                system("cls");
                cout<<"Today's Attendence\n\n";
                cout<<"Roll no\t\tToday's\t\tYesterday\n\n";
                for(int i=0;i<n;i++)
                {
                    cout<<S[i].getRoll()<<"\t\t";
                    S[i].showAttend();
                    cout<<"\t\t";
                    S[i].showLastAttend();
                    cout<<endl;
                }

                _getch();
                system("cls");
                break;
            }
            case(2):
            {
                if(flag==0)
                {
                    while(ch != 'n')
                    {
                        flag=1;             // Getting Information.
                        gotoxy(25, 5);
                        cout<<"-: STUDENT INFORMATION :- \n";
                        cout<<"\n Entry No. :"<<n+1<<endl;
                        S[n].getinfo();
                        cout<<"\n Next Student (y/n): ";
                        cin>>ch;
                        n++;
                        flag=1;
                        system("cls");
                    }
                }
    /// Marks

                cout<<"Enter marks of students: \n\n";
                for(int i=0;i<n;i++)
                {
                    string first=S[i].getRoll();
                    if(first[0]=='T')
                        continue;
                    else
                    {
                        cout<<S[i].getRoll()<<": ";
                        cin>>S[i].marks;
                        S[i].compute();
                        cout<<endl;
                    }
                }

    // Sorting.
                Student temp;
                for(int i=0; i<n; i++)
                {
                    for(int j=i; j<n; j++)
                    {
                        if(S[i].marks < S[j].marks)
                        {
                            temp = S[i];
                            S[i] = S[j];
                            S[j] = temp;
                        }
                    }
                }

                system("cls");
                gotoxy(25, 1);
                int k=0;
                cout<<"-: STUDENT'S REPORT :- ";      // Display Results.
                for(int i=0; i<n; i++)
                {
                    string first=S[i].getRoll();
                    if(first[0]=='T')
                        continue;
                    else
                    {
                        k=1;
                        cout<<"\n\n Student No.: "<<i+1;
                        S[i].display();
                    }
                }
    // Evaluation

                printf("\n\n\n\n\n");
                if(k==1)
                {
                    char c;
                    cout<<"Do you want to go for evaluation(y/n): ";
                    cin>>c;
                    cout<<"\n\n";
                    if(c=='n')
                    {}
                    else
                    {
                        system("cls");
                        SYSTEMTIME st;
                        GetSystemTime(&st);
                        if(st.wYear==2020&&st.wMonth==6&&st.wDay<20)
                        {
                            string rollno;
                            int u;
                            cout<<"Enter no of students who want to update marks: ";
                            cin>>u;
                            system("cls");
                            while(u--)
                            {
                                system("cls");
                                cout<<"Enter roll no:";
                                cin>>rollno;
                                int i,k=0;
                                for(i=0;i<10;i++)
                                {
                                    string r=S[i].getRoll();
                                    if(r.compare(rollno)==0)
                                    {
                                        k=1;
                                        break;
                                    }
                                }
                                if(k==0)
                                {
                                    cout<<"There is no student of this roll no in class";
                                    u++;
                                    cout<<"\n\n\nPress any key........"<<endl;
                                    _getch();
                                    continue;
                                }
                                int marks;
                                cout<<"What is the updated marks: ";
                                cin>>marks;
                                S[i].marks=marks;
                                cout<<"\n\nMarks has updated successfuly\n\n";
                                cout<<"Press any key........"<<endl;
                                _getch();
                                system("cls");
                            }
                            gotoxy(25, 1);
                            cout<<"-: STUDENT'S REPORT :- ";      // Display Results.
                            for(int i=0; i<n; i++)
                            {
                                string first=S[i].getRoll();
                                if(first[0]=='T')
                                    continue;
                                else
                                {
                                    cout<<"\n\n Student No.: "<<i+1;
                                    S[i].display();
                                }
                            }
                            printf("\n\n\n\n\n");
                        }
                        else
                        {
                            cout<<"\n\nSorry! Date of evaluation has crossed\n";
                        }
                    }
                }
            else
            {
                system("cls");
            }
            cout<<"Thanks";
            cout<<"\n\n Press Any Key to Exit ...\n\n";
            _getch();
            break;
        }
            case 3:
            {
                char ch;
                ch=' ';
                if(flag==0)
                {
                    while(ch != 'n')
                    {                   // Getting Information.
                        gotoxy(25, 5);
                        cout<<"-: STUDENT INFORMATION :- \n";
                        cout<<"\n Entry No. :"<<n+1<<endl;
                        S[n].getinfo();
            //S[n].compute();              // Calculate Grade.
                        cout<<"\n Next Student (y/n): ";
                        cin>>ch;
                        n++;
                        system("cls");
                        flag=1;
                    }
                }
                char a=' ';
                while(a!='n')
                {
                    system("cls");
                    SYSTEMTIME st;
                    GetSystemTime(&st);
                    int fine;
                    string rollno;
                    cout<<"Enter the roll no for which you want to check fee status:";
                    cin>>rollno;
                    int i,k=0;
                    for(i=0;i<10;i++)
                    {
                        string r=S[i].getRoll();
                        if(r.compare(rollno)==0)
                        {
                            k=1;
                            break;
                        }
                    }
                    if(k==0)
                    {
                        cout<<"There is no student of this roll no in class";
                        cout<<"\n\n\nPress any key........"<<endl;
                        _getch();
                    //continue;
                    }
                    char f;
                    cout<<"Has this student paid the fees?(y/n)";
                    cin>>f;
                    if(f=='y')
                    {
                        cout<<"Ok, fine\n\n";
                    }
                    else
                    {
                        cout<<"Last date of fee submission was 20 june 2020 \n";
                        if(st.wMonth==7)
                        {
                            fine=(10+st.wDay)*50;
                        }
                        else if(st.wMonth==6)
                        {
                            fine=(st.wDay-20)*50;
                        }
                        cout<<"You are fined "<<fine<<" rupees \n\n";
                    }
                    cout<<"Do you want to check more?(y/n) ";
                    cin>>a;
                }
                break;
            }
            case 0:
            {
                cout<<" you are successfully logout";
                exit(0);
                break;
            }
            default:
            {
                cout<<"sorry plz try again";
                break;
            }
        }
        goto mainpage;
    }
}

