/*This program will calculate a user's computer
hardware capabilities and reccomend graphic settings*/ 

#include <iostream>
#include <iomanip>
#include <string>


using namespace std; 

void displayTitle();
string getResolution();
double getMultiplierValue(string);
double CalculatePerformanceScore(double, double, double, int);
string getRecommendedQuality (double);
void displayInformation (string, double, string, int, double, double);



int main ()
{
	
	//to save user info and hold menu choice
int numOfcomp,  //number of computers
	choice,
	clockSpeed_graphics,
	clockSpeed_processor,
	numberOf_cores,
	multiplier;
	
double PERFORMANCE_SCORE; /*score intializers to track highest and lowest scores*/
	  int lowScore=0; 
	  int highScore=0;
	  int count=0;

string resolution,
	   quality;
	
//This request the user for the number of computers.
cout<<"How many computers are being processed?:"; 
cin>>numOfcomp; 


//loop validation for number of computers
	while (numOfcomp <1)
		{
			cout<<"Invalid number of computers. please enter at least 1 computer:";
			cin>>numOfcomp;
		 } 
	cout<<endl<<endl;
	displayTitle();
	
	//Loop for numOfComp
	for (int num=0; num < numOfcomp; num++)
	{
	
		   	 
		//This get user's clock speed speed
		cout<<"\n Please enter the clock speed <in Megahertz> of your graphics card: ";
		cin>>clockSpeed_graphics;
			while (clockSpeed_graphics < 800||clockSpeed_graphics>2000) //validation loop for Graphics speed
			{
				cout<<"Invalid graphics card speed enter. Valid speed is between 800-2000."<<endl;
				cout<<"Please enter a valid speed:";
				cin>>clockSpeed_graphics;}
	 
		//This gets the user's processor speed
		cout<<"Please enter the clock speed <in Megahertz> of your processor: ";
		cin>>clockSpeed_processor; 
			while (clockSpeed_processor < 1000||clockSpeed_processor>5500) //Validation loop for CPU speed
			{
				cout<<"Invald processor speed entered. Valid speed is between  1000-5500."<<endl;
				cout<<"Please enter a valid speed:";
				cin>>clockSpeed_processor;
				}
		
		//This gets the user's number of cores
		cout<<"Please enter a valid  number of cores of your processor: ";
		cin>>numberOf_cores;
			while (numberOf_cores < 1||numberOf_cores>16)
			{
				cout<< "Invald number of cores entered. Valid number is between 1-16."<<endl;
				cout<<"Please enter a valid number:";
				cin>>numberOf_cores;
			}


resolution= getResolution();

multiplier=getMultiplierValue( resolution);

PERFORMANCE_SCORE= CalculatePerformanceScore( multiplier,clockSpeed_graphics, clockSpeed_graphics, numberOf_cores);

quality= getRecommendedQuality (PERFORMANCE_SCORE);

displayInformation (quality, PERFORMANCE_SCORE, resolution, numberOf_cores, clockSpeed_processor, clockSpeed_graphics);



	//calculating highest and lowest performance scores

if (highScore<PERFORMANCE_SCORE)

	{highScore=PERFORMANCE_SCORE;}
		
    
if (PERFORMANCE_SCORE<lowScore)
		{
		lowScore=PERFORMANCE_SCORE;}
		
if(count==0)
	{
		lowScore=PERFORMANCE_SCORE;
	}
		PERFORMANCE_SCORE=0;

0;
	


} //end of NumOfcomp loop




	cout<<"The highest performance score was:"<<highScore<<endl; 
	cout<<"The lowest performance score was:"<<lowScore<<endl;
	



return 0; 
	

}

void displayTitle ()
	{
		string title;
	title="Computer Hardware Graphics Quality Reommendation Tool";
	
	cout<<title;	
	}
	
string getResolution()
	{
	
string resolution;
int choice;

	//Reslotion menu displlay and choice
		cout<<"What is the resolution of your monitor?\n"
		<<"\t1. 1280 x 720\n"
		<<"\t2. 1920 x 1080\n"
		<<"\t3. 2560 x 1440\n"
		<<"\t4. 3840 x 2160\n"
		<<"Please select from the options above:";
		cin>>choice;
		
		//assigning resolution string
		if (choice =1)
		{
		resolution= "1280 x 720";}
		
		
		else if (choice =2)
		{
		resolution="1920 x 1080";}
		
		else if (choice = 3)
		{
		resolution="2560 x 1440";}
		
		
		else if(choice = 4)
		{
		resolution="3840 x 2160;";}
		
		
		else
		{
		cout<<"invalid Resolution menu choice. Program will terminate."<<endl; 
		return 0;}
			
	return resolution;
	}
	
double getMultiplierValue(string resolution)
	{
		double multiplier;
		
	
		if (resolution== "1280 x 720")
			{
				multiplier=1.00;
			}
		else if (resolution=="1920 x 1080")
			{
				multiplier=0.75;
			}
		else if (resolution=="2560 x 1440")
			{
				multiplier=0.55;
			}
		else if (resolution=="3840 x 2160;")
			{
				multiplier=0.35;
			}
		else(0); 
	
		return multiplier;
	}
	
double CalculatePerformanceScore (double multiplier, double clockSpeed_processor,double clockSpeed_graphics, int numberOf_cores)
	{
	double PERFORMANCE_SCORE;
	
		//Caluculating performance score
	PERFORMANCE_SCORE = ((5*clockSpeed_graphics)+(numberOf_cores*clockSpeed_processor))*multiplier;
	
	return PERFORMANCE_SCORE;
	}

string  getRecommendedQuality (double PERFORMANCE_SCORE) 
	{
		string quality;
			//processing recommendation based on perfomance score 
	if (PERFORMANCE_SCORE>17000)
		quality = "Ultra";
	
	else if (PERFORMANCE_SCORE<17000&& PERFORMANCE_SCORE>15000)
		quality = "High";
	
	else if (PERFORMANCE_SCORE<15000&&PERFORMANCE_SCORE>15000)	
		quality= "Medium";
	
	else if (PERFORMANCE_SCORE<13000&&PERFORMANCE_SCORE>11000)
		quality= "Low";
	
	else 
		quality= "unable to Play";
		
	return quality;
			
	}
	
void displayInformation (string quality, double PERFORMANCE_SCORE, string resolution, int numberOf_cores, double clockSpeed_processor, 
						 double clockSpeed_graphics)
	{
			
	//output display
	cout<<"\n\nComputer Hardware Graphic Quality Recommendation Tool\n\n";
	cout<<"GPU Clock Speed: "<<clockSpeed_graphics<<" MHz\n";
	cout<<"CPU Clock SPeed: "<<clockSpeed_processor<< " MHz\n";
	cout<<"Number of cores: "<<numberOf_cores<<endl;
	cout<<"Monitor Resolution: "<< resolution<<endl; 
	
	//setpreciosn for performance score
	cout<<fixed<<showpoint<<setprecision(2);
	
	//rest of menu display
	cout<<"Performance Score: "<<PERFORMANCE_SCORE<<endl; 
	cout<<"Recommended Graphics Quality: "<<quality<<endl;	
	} 
	
	
	


