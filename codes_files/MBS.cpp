#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
#include<ctime>
#include <cstdlib> //this header for exit function
#define S 25
#define M 15 //Constant for Movie Listing
#define RED     "\033[31m"  // color red for displaying error messages
#define BLUE    "\033[34m"  
#define RESET   "\033[0m"   // to set the color back to default
#define GREEN   "\033[32m"  // color green for displaying successful messages for the system
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"  // color for improving visuals for headings


using namespace std;

struct Login
{	char name[15];
	char passwd[15];
	char  Phrase[15];	
};

// Define the structure for movie details
struct Details {
    string title;       // Movie title
    string synopsis;    // Movie synopsis 
    string genre;
    float rating;
    int showtimes[3];   // 3 movie showtimes
    string releaseDate;
};

// Define the structure for upcoming movie details
struct UpcomingMovieDetails {
    string title;       // Movie title
    string synopsis;    // Movie synopsis
    string genre;
    string releaseDate; // Release date with date, month, and year
};


struct SEATS
{
    char seats[15];
};



struct History
{
    char name1[15];
    char moviechosen1[30];
    char time1[10];
    int  Pticket1;
    float total1;
};



//Function Prototype for Login
void CreateNewUser(Login users[]); //Function to create new user
void LoginUser(Login users[]);// Function to login 
void ResetUser(Login users[]); //Function to Reset user password

// Function prototypes
void displayMovieList(const Details movies[]);
void filterMovies(const Details movies[]);
void displayUpcomingMovies();
bool backToMenu();  
void Display();

//Function prototype for User Profile
void ResetUserInfo(Login users[]);

//Function Prototype for Payment Processing
void Thanks (); // Function to display Thank you
void Choice(); // Function for the user to choose a choice on wether to continue with payment process or not
void Payment(); // Function for Payment Processing for Payment methods with similar outputs
void ConfirmPay(); //Fuction for Booking Confirmation

//Function Prototype for Booking Movie
string time();//function to hold time
void displayTakenSeats();//To check in the file seats that have been taken



  int main()
{ 
    //Log in Part
	struct Login users[30];
	
	//initialazation
	 
	int a, option, card, cvv, profile, view,  i, j;
	string space, exp;
		
	char username[15],password[15];
	
	
	while (true)
    {
        cout<<"\n__________________________________________"<<endl;
        cout<<"------------------------------------------"<<endl;
        cout<<"||  "<<CYAN<<"Hello welcome to TJH Movie system"<<RESET<<"   || \n"<<endl;
        cout<<"||  Please Select an option :           ||"<<endl;
        cout<<"||  Press 1 to create new user          ||"<<endl;
        cout<<"||  Press 2 to login to user account    ||"<<endl;
        cout<<"||  Press 3 to reset password           ||"<<endl;
        cout<<"||  Press 0 to exit                     ||"<< endl;
        cout<<"------------------------------------------"<<endl;
        cout<<"__________________________________________"<<endl;
        cout<<"Enter Option : ";
        cin>>a;
	 
        switch(a)
        { 
            case 1:
                CreateNewUser(users);
                break;
            case 2:
                LoginUser(users);
                break;
            case 3:
                ResetUser(users);
                break; 
            case 0:
                Thanks();
                return 0;  // exit the program
            default:
                cout<<RED<<"Invalid option please enter a correct option.\n"<<RESET<<endl;
                break;
        }
    }
}


// END OF TESTING ANOTHER MAIN



	void CreateNewUser(Login users[])
{		int i=0;		//Holding data inside memory so that later on can be passed to file
		char name[15],passwd[15],Phrase[15];
		
			cin.ignore();
	     	cout<<"Enter new username : ";
	     	cin.getline(users[i].name,15);
	     	cout<<"Enter new password : ";
			cin.getline(users[i].passwd,15);
			cout<<"Enter safe phrase to help you reset your password : "<<endl;
			cin.getline(users[i].Phrase,15);
			
			ofstream write;
	     	write.open("Login_names.txt",ios_base::app);
		 //Writing the data inside the login_txt file for future refrence	
	     	write<<users[i].name<<endl;
	     	write<<users[i].passwd<<endl;
	     	write<<users[i].Phrase<<endl;
	     	write.close();
	     	cout<<GREEN<<"\nUser created successfully\n"<<RESET;
	     	//main();
	     	return;
};	




	void LoginUser(Login users[])
{		int i,j=0,profile,view,booking_option;
		char username[15],password[15];
		string timeselected,Timeconfirm;
	
		ifstream read;
		 read.open("Login_names.txt");
		 if(read.fail())
		cout<<RED<<"File not found"<<RESET;
		else
	 	{
		 for(i=0;i<S;i++)
		 {
			read.getline(users[i].name,15);
			read.getline(users[i].passwd,15);
			read.getline(users[i].Phrase,15);

		}
		   read.close();     
	   }

	  	cout<<"Enter username : ";
		 cin.ignore();
		 cin.getline(username,15);
		 cout<<"Enter password : ";
		 cin.getline(password,15);
		//Here thre is looping from the global variables
		for(i=0;i<S;i++)
		 {
		 if(strcmp (username,users[i].name)==0 && strcmp(password,users[i].passwd)==0)
		{
			 	cout<<GREEN<<"\nLogin Succsefully"<<RESET<<endl;
				 j=1; 
				cout<<CYAN<<"\nWELCOME TJH MOVIE BOOKING"<<RESET<<endl;
				cout<<"\t1.Book a movie"<<endl;
				cout<<"\t2.User profile"<<endl;
				cout<<"Please choose an option : ";
				do{
				
				cin>>booking_option;
				if(booking_option!=1 && booking_option!=2)
				cout<<RED<<"wrong option please re enter correct option\n"<<RESET<<endl;
				}while(booking_option!=1 && booking_option!=2);
				
				switch(booking_option)
				{
case 1:{
	
//Display Movies here

	 Display();
   
	struct SEATS table[S]; 

   	int Pticket, i, a,j, total, m = 0,movie,choice, card, cvv, number,option;
   	string space, exp, moviechosen;
  	char seatchosen[15];
   	bool seatTaken = false;

    cout << "\t\t_____________________________________________________" << endl;
    cout << "\t\t||                                                 ||" << endl;
    cout <<CYAN<< "\t\t||\t\tBOOKING TICKETS MENU               ||"<<RESET << endl;
    cout << "\t\t_____________________________________________________" << endl;
		
		
	cout<<"1.KongsiRaya\t\t2.KUNG FU\t\t3.Tilu Mulu\t\t4.Wira an Army\t\t5.Shaolin\n";
	cout<<"6.Kaithi\t\t7.Ada Hantu\t\t8.The eye\t\t9.Kancahna\t\t10.Mat Kilau\n";
	cout<<"11.Dragon\t\t12.Neru\t\t\t13.Sisu\t\t\t14.Courier\t\t15.Monkey Man\n\n";
    cout << "Please select a movie : ";
    cin >> movie;
do 
{
	if(movie <1 || movie > 15)
	cout<<RED<<"Please enter correct choice\n"<<RESET<<endl;
}while(movie <1 || movie > 15);
	
	switch(movie)
	{
		case 1:
			moviechosen="KongsiRaya";
		
			break;
		case 2:
			moviechosen="KUNG FU";
		
			break;
		case 3:
			moviechosen="Tilu Mulu";			
		
			break;
		case 4:
			moviechosen="Wira an Army";
		
			break;
		case 5:
			moviechosen="Shaolin";
		
			break;
		case 6:
			moviechosen="Kaithi";

			break;
		case 7:
			moviechosen="Ada Hantu";
	
			break;
		case 8:
			moviechosen="The eye";
			time();
			break;
		case 9:
			moviechosen="Kancahna";
		
			break;
		case 10:
		    moviechosen="Mat Kilau";
			time();
			break;
		case 11:
			moviechosen="Dragon";
		
			break;
		case 12:
			moviechosen="Neru";
			break;
		case 13:
			moviechosen="Sisu";
			break;
		case 14:
		    moviechosen="Courier";
			break;
		case 15:							
			moviechosen="Monkey Man";
			break;	
	}
	
	Timeconfirm=time();

    cout << "\n\nEnter the number of people booking tickets: ";
    cin >> Pticket;
    cin.ignore();
    
    do 
	{
        cout << "1.Adults\t\tRM:15" << endl;
        cout << "2.Students\t\tRM:10" << endl;
        cout << "3.Children\t\tRM:5\n" << endl;
        cout << "\n\nPlease choose ticket type : ";
        cin >> a;
        cin.ignore();
        if(a != 1 && a != 2 && a != 3)
            cout <<RED<< "Invalid option please re enter correct option :" <<RESET<< endl;
    } while(a != 1 && a != 2 && a != 3);

    switch(a)
    {
        case 1:
            total = (float)Pticket * 15;
            break;
        case 2:
            total = (float)Pticket * 10;
            break;
        case 3:
            total = (float)Pticket * 5;
            break;
    }

    cout << "Please choose from the following seats" << endl;
    cout << "\t\t|____                                                                        _________|" << endl;
    cout <<YELLOW<< "\t\t|____             S       C       R       E         E       N                _________|"<<RESET << endl;
    cout << "\t\t|____                                                                        _________|" << endl; 
    cout << "\t\t\tA \t\tB \t\tC \t\tD \t\tE " << endl;
    cout << "\t\t\tF \t\tG \t\tH \t\tI \t\tJ " << endl;
    cout << "\t\t\tK \t\tL \t\tM \t\tN \t\tO " << endl;
    cout << "\t\t\tP \t\tQ \t\tR \t\tS \t\tT " << endl;
    cout << "\t\t\tU \t\tV \t\tW \t\tX \t\tY " << endl;
    cout << "\n\n";
    //cout << "These seats are taken";
    displayTakenSeats();
    cout << "\n\n";
    cout << "Choose Seats for " << Pticket << " People" << endl;

    ifstream read;
    read.open("Seats_names.txt");
    if (read.fail()) {
        cout <<RED<< "File not found\n"<<RED;
    } else {
        for (i = 0; i < S; i++) {
            read.getline(table[i].seats, 15);
        }
    }

    for (int ticket = 0; ticket < Pticket; ticket++) {
        do {
            cout << "Choose Seat for Person " << ticket + 1 << ": ";
            cin >> seatchosen;
            seatTaken = false;
            for (i = 0; i < S; i++) {
                if (strcmp(seatchosen, table[i].seats) == 0) {
                    seatTaken = true;
                    break;
                }
            }
            if (seatTaken) {
                cout << "That seat has been taken. Please choose seats not taken." << endl;
                displayTakenSeats();
            }
        } while (seatTaken);

        ofstream write;
        write.open("Seats_names.txt", ios_base::app);
        if (write.fail()) {
            cout <<RED<< "Error opening file for writing." <<RESET<< endl;
        }
        write << seatchosen << endl;
        write.close();
        cout <<GREEN<< "Booking successfully for seat: " <<RESET<< seatchosen << endl;
    }

    sleep(2); //simulating delay
    cout<<"\n==================================\n";
	cout<<YELLOW<<"**\tPAYMENT PAGE\t\t**\n"<<RESET;
	
	do
	{
	cout<<"**\t\t\t\t**"<<endl;
	cout<<CYAN<<"**\tPayment Processing\t**\n"<<RESET<<endl;
	cout<<"**\t1. Credit / Debit Card\t**"<<endl;
	cout<<"**\t2. MAE by Maybank2u\t**"<<endl;
	cout<<"**\t3. Touch'n Go eWallet\t**"<<endl;
	cout<<"=================================="<<endl;
	cout<<"SELECT PAYMENT OPTION : ";
	cin>>option;
	
	
	if (option<1 || option>3)
	{
		cout<<RED<<"Invalid Option. Re-Enter Again."<<RESET<<endl;
	}
	
	} while (option<1 || option>3);
	
	switch (option)
	{
		case 1:
			cout<<"=================================="<<endl;
			cout<<"** 1. Credit / Debit Card\t**"<<endl;
			cout<<"\nEnter Card Number: ";
			cin>>card;
		    getline(cin, space);
			cout<<"\nEnter CVV Codes: ";
			cin>>cvv;
			
			cout<<"\nEnter expiration date: ";
			cin>>exp;
			cout<<"=================================="<<endl;
			
            //Entering the choice of the customer wheather to Continue with the process or to terminate
            cout<<"\n\nEnter 1 to Proceed 2 to exit: ";
			cin>>choice;
			
			if (choice==1)
			{
			// Booking confirmation
	        cout<<GREEN<<"Booking Confirmed\n"<<RESET<<endl;
	        cout<<CYAN<<"\nBooking confiramtion"<<RESET<<endl;
	        cout<<"\n---------------------------------------"<<endl;
	        cout<<"_______________________________________"<<endl;
	        cout<<"Movie chosen : "<<moviechosen<<endl;
	        cout<<"time chosen : "<<Timeconfirm<<endl;
	        cout<<"Total tickets : "<<Pticket<<endl;
	        cout<<"Total ammount : RM "<<total<<endl;
	        cout<<"\n";
	        
	        	ofstream bout("Booking_confirmation.txt", ios::app);
			if (!bout.is_open())
			{
    			cout << RED << "Error opening booking file.\n" << RESET;
			}
			else
			{
    			bout << username    << '\n';      // logged in user
    			bout << moviechosen << '\n';
    			bout << Timeconfirm << '\n';
    			bout << Pticket     << '\n';
    			bout << total       << '\n';
    			bout.close();
			}

			
			Thanks();
			break;
			
			}
			else 
			{
			cout<<RED<<"\nPayment Cancelled."<<RESET;
			Thanks();
			break;
			}	
		    
		
		case 2:
			//For Payment for the movie Booked 
            cout<<"\nEnter Phone number : ";
            cin>>number;
    
	        cout<<"\n\nConfirm Payment"<<endl;
			cout<<"\tPhone Number: \t\t"<<number<<endl;
			cout<<"\tNet Payment: \t\t"<<total<<endl;
			cout<<"\tPayment Details: \t"<<Pticket<<" Cinema Tickets"<<endl;
			cout<<"\tMerchant: \t\tTJH Cinemax"<<endl;
			cout<<"Enter Password: ";
			cin>>password; // Payment Method password
			
			cout<<"\n\nEnter 1 to Proceed 2 to exit: ";
			cin>>choice;
			if (choice==1)
			{
				// Summary of Transaction
	        cout<<GREEN<<"Booking Confirmed\n"<<RESET<<endl;
	        cout<<CYAN<<"\nBooking confiramtion"<<RESET<<endl;
	        cout<<"\n---------------------------------------"<<endl;
	        cout<<"_______________________________________"<<endl;
	        cout<<"Movie chosen : "<<moviechosen<<endl;
	        cout<<"time chosen : "<<Timeconfirm<<endl;
	        cout<<"Total tickets : "<<Pticket<<endl;
	        cout<<"Total ammount : RM "<<total<<endl;
			
			ofstream bout("Booking_confirmation.txt", ios::app);
			if (!bout.is_open())
			{
    			cout << RED << "Error opening booking file.\n" << RESET;
			}
			else
			{
    			bout << username    << '\n';      // logged in user
    			bout << moviechosen << '\n';
    			bout << Timeconfirm << '\n';
    			bout << Pticket     << '\n';
    			bout << total       << '\n';
    			bout.close();
			}
			
			Thanks();
			break; 
			}
			
			else 
			{
			cout<<RED<<"\nPayment Cancelled."<<RESET;
			Thanks();
			break;
			}
		
		
		
		case 3:
		    //For Payment for the movie Booked 
            cout<<"Enter Phone number: ";
            cin>>number;
    
	        cout<<"\n\nConfirm Payment"<<endl;
			cout<<"\tPhone Number: \t\t"<<number<<endl;
			cout<<"\tNet Payment: \t\t"<<total<<endl;
			cout<<"\tPayment Details: \t"<<Pticket<<" Cinema Tickets"<<endl;
			cout<<"\tMerchant: \t\tTJH Cinemax"<<endl;
			cout<<"Enter Password: ";
			cin>>password; // Payment Method password
			
			cout<<"\n\nEnter 1 to Proceed 2 to exit: ";
			cin>>choice;
			if (choice==1)
			{
				// Summary of Transaction
			cout<<endl;
			
	        cout<<GREEN<<"Booking Confirmed\n"<<RESET<<endl;
	        cout<<CYAN<<"\nBooking confiramtion"<<RESET<<endl;
	        cout<<"\n---------------------------------------"<<endl;
	        cout<<"_______________________________________"<<endl;
	        cout<<"Movie chosen: "<<moviechosen<<endl;
	        cout<<"time chosen : "<<Timeconfirm<<endl;
	        cout<<"Total tickets : "<<Pticket<<endl;
	        cout<<"Total ammount : RM "<<total<<endl;
	        
	        ofstream bout("Booking_confirmation.txt", ios::app);
			if (!bout.is_open())
			{
    			cout << RED << "Error opening booking file.\n" << RESET;
			}
			else
			{
    			bout << username    << '\n';      // logged in user
    			bout << moviechosen << '\n';
    			bout << Timeconfirm << '\n';
    			bout << Pticket     << '\n';
    			bout << total       << '\n';
    			bout.close();
			}
			
			
			Thanks();
			break;
			
			}
			else 
			{
			cout<<RED<<"\nPayment Cancelled."<<RESET;
			Thanks();
			}
			break;	
				
	}
      
      
	  break;
	       }// end of case one booking process choice
						
					     
				case 2:   
	           	{
		              do
	                 {
			 
	         	sleep(2); // Simulating a delay
	            cout<<CYAN<<"\nUSER PROFILE MANAGEMENT"<<RESET<<endl;
	            cout<<"************************************"<<endl; 
	            cout<<"\t1. View Profile"<<endl;
	            cout<<"\t2. Edit Profile"<<endl;
	            cout<<"************************************"<<endl;
	            cout<<"Select Choice (select 0 to Exit): ";
	            cin>>profile;
	
	
	if(profile == 1)
	{	
		
		    cout<<CYAN<<"\n\tUSER INFORMATION"<<RESET<<endl;
			cout<<"__________________________________"<<endl;
			cout<<"\n\tUsername :\t"<<users[i].name<<"\n\tPassword :\t"<<users[i].passwd<<"\n\tSafe Phrase :\t"<<users[i].Phrase<<endl;
			cout<<"__________________________________"<<endl;
		
    	
		//Login info viewed
		
		do
		{
			cout<<"\n\n**********************************"<<endl; 
		cout<<"\t1. View Past Booking   "<<endl;
	    cout<<"\t2. View upcoming shows "<<endl;
	    cout<<"**********************************"<<endl;
	    cout<<"Select Choice: ";
	    cin>>view;
	    
	    
if (view == 1)
{
    cout << CYAN << "\nPAST BOOKINGS" << RESET << endl;

    ifstream lead("Booking_confirmation.txt");
    if (!lead.is_open())
    {
        cout << "No booking history found.\n";
    }
    else
    {
        History rec;
        bool any = false;

        cout << "------------------------------------------------------------------\n";
		cout << "Name\tMovie\t\tTime\tTickets\tTotal(RM)\n";

        while (true)
        {
            string lineTickets, lineTotal;

            if (!lead.getline(rec.name1,         15)) break;
            if (!lead.getline(rec.moviechosen1,  30)) break;
            if (!lead.getline(rec.time1,         10)) break;
            if (!getline(lead, lineTickets))          break;
            if (!getline(lead, lineTotal))            break;

            rec.Pticket1 = atoi(lineTickets.c_str());
            rec.total1   = atof(lineTotal.c_str());

            // show only bookings for logged in user
            if (strcmp(rec.name1, username) == 0)
            {
                any = true;
                cout << rec.name1        << '\t'
                     << rec.moviechosen1 << '\t'
                     << rec.time1        << '\t'
                     << rec.Pticket1     << '\t'
                     << rec.total1       << endl;
            }
        }

        lead.close();

        if (!any)
        {
            cout << "No bookings stored for this user.\n";
        }
    }
}


		
		if (view ==2)
		{
			cout<<CYAN<<"\nUPCOMING MOVIES"<<RESET<<endl;
		    //take upcoming moviews from movie listing
		    displayUpcomingMovies();
		}
		if(!(view==1 || view==2))
	    cout<<RED<<"Incorrect Choice\n"<<RESET;
		}while(view<1 || view>2);
		
	}
	
	if(profile == 2)
	{
	   cout<<CYAN<<"\n\tEDIT PROFILE"<<RESET<<endl;

	   cout<<"**************************************"<<endl;
	   ResetUserInfo(users);
	   
	}
	
	if(!(profile==1 || profile==2 || profile==0))
	    cout<<RED<<"Incorrect Choice RE-Enter\n"<<RESET;
	if (profile==0)
	  Thanks(); break;
	  
	}while(profile<1 || profile>2);
						break;
					}
				}//end of switch
		}
		}
		if(j != 1)
		cout<<RED<<"Wrong password please try again !!!"<<RESET;
		
};



	void Display()
{
	Details movies[M] = 
	{
      	{"KongsiRaya", "A chef and a food TV show producer find themselves falling in love.", "Comedy", 3.0, {1000, 1500, 2100}, "2021"},
        {"Kung Fu", "Jackie Chan leads his team on a race around the world.", "\t\tComedy",        4.0, {1000, 1500, 2100}, "2022"},
        {"Tilu Mulu", "Chandran lies to boss that his mother is unwell and gets caught.", "Comedy", 1.0, {1000, 1500, 2100}, "2022"},
        {"Wira   ", "An army returns home and enters an underground match to protect family.", "Action", 3.0, {1000, 1500, 2100}, "2020"},
        {"Shaolin", "Andy Lau takes refuge at a Shaolin temple and learns arts from Jackie.", "Action", 4.0, {1000, 1500, 2100}, "2024"},
        {"Kaithi", "A convict tries to meet his daughter but his attempts are interrupted.", "Action", 5.0, {1000, 1500, 2100}, "2021"},
        {"Ada Hantu", "Aliff's unforgettable birthday celebration in an abandoned house.", "Horror", 2.0, {1000, 1500, 2100}, "2023"},
        {"The Eye", "Jessica is a corneal transplant that restores her sight at long last.", "Horror", 3.0, {1000, 1500, 2100}, "2022"},
        {"Kanchana", "3 spirits possess a timid man and start making him act like a woman.", "Horror", 4.0, {1000, 1500, 2100}, "2024"},
        {"Mat Kilau", "A legendary warrior leads people into a war to protect their home.", "Drama", 1.0, {1000, 1500, 2100}, "2024"},
        {"Dragon", "A martial arts master with a dark past wants to start a new life.", "Drama",  5.0, {1000, 1500, 2100}, "2021"},
        {"Neru"  , "A lawyer takes a challenging case of a blind girl with no evidence.",    "Drama", 2.0, {1000, 1500, 2100}, "2023"},
        {"Sisu", "Ex-soldier discovers gold in Lapland tries to loot into the city", "War",3.0, {1000, 1500, 2100}, "2022"},
        {"Courier", "Wyne is asked by a Russian source to help put end the Cuban Crisis", "War",4.0, {1000, 1500, 2100}, "2020"},
        {"Monkey Man", "A man unleashes a campaign of vengeance against the corrupt leaders.", "War",3.0, {1000, 1500,2100}, "2024"} 
    };

    //int action;
    
    bool stayInMenu = true;
    
    while (stayInMenu)
    {
        int action;

        cout << "\n\t\t---------------------------------------";
        cout << CYAN << "\n\t\t    TJH Movie Ticket Booking System" << RESET;
        cout << "\n\t\t---------------------------------------";
        cout << YELLOW << "\n\t\t\tWelcome User!" << RESET;
        cout << "\n\n\t\t\t<1> Movie Now Showing";
        cout << "\n\t\t\t<2> Filter Movies";
        cout << "\n\t\t\t<3> Upcoming Movies";
        cout << "\n\t\t\t<4> Book Movie";
        cout << "\n\t\t---------------------------------------";
        cout << "\n\nEnter Option: ";
        cin >> action;	

        switch (action)
        {
            case 1:
                displayMovieList(movies);
                stayInMenu = backToMenu();
                break;
            case 2:
                filterMovies(movies);
                stayInMenu = backToMenu();
                break;
            case 3:
                displayUpcomingMovies();
                stayInMenu = backToMenu();
                break;
            case 4:
                cout << CYAN << "\nBOOKING PAGE\n" << RESET;
                stayInMenu = false;   // leave Display and continue booking flow in LoginUser
                break;
            default:
                cout << RED << "Invalid option.\n" << RESET;
                break;
        }
    }
    
}



	void ResetUser(Login users[])
{	char phrase[15],user_name[15],passwd[15],New_Pass[15];
	int i,j=0,k=0;
	 	
	 	ifstream read;
		 read.open("Login_names.txt");
		if(read.fail())
		    cout<<RED<<"File not found"<<RESET;
		else
	 	{
		 for(i=0;i<S;i++)
		  {
			read.getline(users[i].name,15);
			read.getline(users[i].passwd,15);
			read.getline(users[i].Phrase,15);
		  }
	    }
		 read.close();   
	
		cout<<"Please enter username of forgotten password : "<<endl;
		cin.ignore();
		cin.getline(user_name,15);
		cout<<"Please enter safe Phrase to reset your Password : "<<endl;
	 	cin.getline(phrase,15);
	 	
	 
	 	for(i=0;i<S;i++)
	 		{
	 			if((strcmp (users[i].name,user_name) == 0) && (strcmp(users[i].Phrase,phrase) == 0))
	 				{
		 				cout<<GREEN<<"\nSafe phrase correct\n"<<RESET;
		 				j=1;
		 				k=i;
		 				cout<<"Enter New Password for   USER : "<<users[k].name<<"\t\t";
		 				cin.getline(users[k].passwd,15);
						
						ofstream write;
						write.open("Login_names.txt",ios_base::app);
						write<<users[i].name<<endl;
						write<<users[k].passwd<<endl;
						write<<users[i].Phrase<<endl;
						write.close();
						cout<<GREEN<<"\nPassword Reset successfully\n"<<RESET;break;
      				}
			}
	
			//main();
	
		if(j ==0)
			{
				cout<<RED<<"\nInorrect username or phrase!! please try again \n"<<RESET;
				//main();
			}
			
		return;
};



	void ResetUserInfo(Login users[])
{	char phrase[15],user_name[15],passwd[15],New_Pass[15];
	int i,j=0,k=0;
	 	
	 	ifstream read;
		 read.open("Login_names.txt");
		 if(read.fail())
		cout<<RED<<"File not found"<<RESET;
		else
	 	{
		 for(i=0;i<S;i++)
		  {
			read.getline(users[i].name,15);
			read.getline(users[i].passwd,15);
			read.getline(users[i].Phrase,15);
		  }
	    }
		   read.close();   
		cout<<"Enter Previous Username    : ";
		cin.ignore();
		cin.getline(user_name,15);
		cout<<"Enter Previous Safe Phrase : ";
	 	cin.getline(phrase,15);
	 	
	 
	 for(i=0;i<S;i++)
	 {
	 	if((strcmp (users[i].name,user_name) == 0) && (strcmp(users[i].Phrase,phrase) == 0))
	 	{
	 	 cout<<"**************************************"<<endl;
		 cout<<GREEN<<"\nCorrect Previous account Information\n"<<RESET<<"Enter New User Information"<<endl;
		 j=1;
		 k=i;
		 cout<<"\n**********************************"<<endl;
		 cout<<"Enter New Username :\t";
		 cin.getline(users[k].name, 15);
		 cout<<"Enter New Password :\t";
		 cin.getline(users[k].passwd,15);
		 cout<<"Enter New Phrase   :\t";
		 cin.getline(users[k].Phrase, 15);
		 cout<<"**********************************\n"<<endl;
		 
		ofstream write;
		write.open("Login_names.txt",ios_base::app);
		write<<users[k].name<<endl;
		write<<users[k].passwd<<endl;
		write<<users[k].Phrase<<endl;
		write.close();
		
		cout<<GREEN<<"Reset successfully"<<RESET;break;
      }
	}
	
	return; //main();
	
	if(j ==0)
	{
		cout<<RED<<"Inorrect username or phrase!! please try again \n"<<RESET;
		return; //main();
		
	}
};



	void Thanks() 
{
	cout<<CYAN<<"Thank you for using TJH Cinemax"<<RESET;
	cout<<"\n";
};




	string time()
{	int time;
	string confirm;
	cout<<"1.03:00\t\t2.18:00\t\t3.21:00\n";
	cout<<"Choose time for your movie : ";
	cin>>time;
	switch(time)
	{
		case 1:
			confirm="03:00";
			cout<<"\nTime selected confirmed"<<endl;
			break;
		case 2:
			confirm="18:00";
			cout<<"\nTime selected confirmed"<<endl;
			break;
	    case 3:
	    	confirm="21:00";
	    	cout<<"\nTime selected confirmed"<<endl;
			break;
	}
	return confirm;
};



	void displayTakenSeats() 
{
    ifstream read;
    read.open("Seats_names.txt");
    if (read.fail()) {
        cout <<RED<< "Error opening file for reading."<<RESET << endl;
    } else {
        string line;
        cout << "Seats already taken:" << endl;
        while (getline(read, line)) {
            cout << line << endl;
        }
    }
    read.close();
};



// Function to display the list of movies
	void displayMovieList(const Details movies[]) 
{
    cout << "-------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "Movie Title\tSynopsis\t\t\t\t\t\t\t\tGenre  \tRating\t Showtimes\tRelease Date\n";
    cout << "-------------------------------------------------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < M; ++i)
	{
        cout << i + 1 << ". " << movies[i].title << "\t" << movies[i].synopsis << "\t" << movies[i].genre << " \t "  
        << "(" << movies[i].rating << ")\t" << movies[i].showtimes[0] << "|" << movies[i].showtimes[1] << "|" << movies[i].showtimes[2] << "\t"
        << movies[i].releaseDate << endl;
    }
}




// Function to filter movies based on genre, release date, or rating
	void filterMovies(const Details movies[]) 
{
    // Variables to store user's filtering choices
    int option;
    string genre;
    string releaseDate;
    int rating;

    // Display filtering options
    cout << "\n\t\t--------------------------";
    cout <<CYAN<< "\n\t\t    Filter Movies"<<RESET;
    cout << "\n\t\t--------------------------";
    cout << "\n\n\t\t<1> Filter by Genre";
    cout << "\n\t\t<2> Filter by Release Date";
    cout << "\n\t\t<3> Filter by Rating";
    cout << "\n\t\tEnter Option: ";
    cin >> option;

    // Perform filtering based on user choice
    switch (option) 
	{
        case 1:
            cout<<CYAN << "\n\t\tGenre: "<<RESET;
            cout << "\n\t\t1. Comedy";
            cout << "\n\t\t2. Action";
            cout << "\n\t\t3. Horror";
            cout << "\n\t\t4. Drama";
            cout << "\n\t\t5. War";
            cout << "\n\t\tEnter Genre Option: ";
            cin >> option;
            switch (option) {
                case 1:
                    genre = "Comedy";
                    break;
                case 2:
                    genre = "Action";
                    break;
                case 3:
                    genre = "Horror";
                    break;
                case 4:
                    genre = "Drama";
                    break;
                case 5:
                    genre = "War";
                    break;
                default:
                    cout <<RED<< "Invalid Genre Option\n"<<RESET;
                    return;
            }
            cout << "\nMovies in " << genre << " genre:\n";
            for (int i = 0; i < M; ++i) {
                if (movies[i].genre == genre) {
                    cout << "- " << movies[i].title << endl;
                }
            }
            break;
        case 2:
            cout <<CYAN<< "\n\t\tRelease Date:"<<RESET;
            cout << "\n\t\t1. 2020";
            cout << "\n\t\t2. 2021";
            cout << "\n\t\t3. 2022";
            cout << "\n\t\t4. 2023";
            cout << "\n\t\t5. 2024";
            cout << "\n\t\tEnter Release Date Option: ";
            cin >> option;
            switch (option) {
                case 1:
                    releaseDate = "2020";
                    break;
                case 2:
                    releaseDate = "2021";
                    break;
                case 3:
                    releaseDate = "2022";
                    break;
                case 4:
                    releaseDate = "2023";
                    break;
                case 5:
                    releaseDate = "2024";
                    break;
                default:
                    cout <<RED<< "Invalid Release Date Option\n"<<RESET;
                    return;
            }
            cout << "\nMovies released in " << releaseDate << ":\n";
            for (int i = 0; i < M; ++i) {
                if (movies[i].releaseDate == releaseDate) {
                    cout << "- " << movies[i].title << endl;
                }
            }
            break;
        case 3:
            cout <<CYAN<< "\n\t\tRating:" <<RESET;
            cout << "\n\t\t1. 1";
            cout << "\n\t\t2. 2";
            cout << "\n\t\t3. 3";
            cout << "\n\t\t4. 4";
            cout << "\n\t\t5. 5";
            cout << "\n\t\tEnter Rating Option: ";
            cin >> rating;
            if (rating < 1 || rating > 5) {
                cout <<RED<< "Invalid Rating Option\n"<<RESET;
                return;
            }
            cout << "\nMovies with rating " << rating << ":\n";
            for (int i = 0; i < M; ++i) {
                if (movies[i].rating == rating) {
                    cout << "- " << movies[i].title << endl;
                }
            }
            break;
        default:
            cout <<RED<< "Invalid Option\n"<<RESET;
    }
    backToMenu();
};




// Function to display upcoming movies with additional details
	void displayUpcomingMovies()
{
    // Upcoming movies 
    UpcomingMovieDetails upcomingMovies[] = {
        {"Femme",   "Jules's targeted in a horrific homophobic attack and destroy his life.", "Thriller ", "15th April 2024"},
        {"Sting",   "Charlotte face the facts about her pet-and fight for family's survival.", "Horror", "	17th May 2024"},
        {"Breathe", "Mother and daughter, barely surviving in an oxygen-less world.", "	Action", "	30th June 2024"},
        {"Babes",   "Eden who becomes pregnant from a one-night-stand.", 	"		Comedy", "	5th July 2024"},
        {"Quiet",	"An american journalist who travels to Poland with her father.", "	Drama", "	1st Aug 2024"}
    };

    // Display upcoming movies with additional details
    cout << "-------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "Movie Title\tSynopsis\t\t\t\t\t\t\t\t\tGenre\t\tRelease Date\n";
    cout << "-------------------------------------------------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < 5; ++i) { // Assuming there are 5 upcoming movies
        cout << upcomingMovies[i].title << "\t\t" << upcomingMovies[i].synopsis << "\t\t" 
             << upcomingMovies[i].genre << "\t" << upcomingMovies[i].releaseDate << endl;
    }
};




// Function to display back to menu option
	bool backToMenu() 
{
    char choice;
    cout << "\n\nDo you want to go back to the main menu? (Y/N): ";
    cin >> choice;
    
    if (choice == 'Y' || choice == 'y') 
	{
        return true; //Display(); // Calls main function to display menu again
    } 
	else if (choice == 'N' || choice == 'n') 
	{
        cout << "Exiting program.\n";
        Thanks();
        return false; //exit(0); // terminate this program with a sucessful status
    } 
	else 
	{
        cout <<RED<< "Invalid choice. Exiting program.\n"<<RESET;
        exit(1); //terminate the program with an error exit status
    }
};
