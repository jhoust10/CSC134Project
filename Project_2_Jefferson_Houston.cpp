/*This program will calculate a user's computer
hardware capabilities and reccomend graphic settings*/ 

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std; 

int main ()
{
	ofstream outputFile;
	outputFile.open ("scores.txt");
	
	
	//to save user info and hold menu choice
int numOfcomp,  //number of computers
	choice,
	clockSpeed_graphics,
	clockSpeed_processor,
	numberOf_cores,
	multiplier;
	
double PERFORMANCE_SCORE; 
	
	//constants to hold the menu choice
const int Res_One = 1,
	RES_TWO = 2, 
	RES_THREE = 3, 
	RES_FOUR = 4;
	
string resolution,
quality,
title="Computer Hardware Graphics Quality Reommendation Tool";
	
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
	cout<<title<<endl<<endl;  //Title display
	
	//Loop for numOfComp
	for (int num=0; num < numOfcomp; num++)
	{
	
		   	 
		//This get user's clock speed speed
		cout<<"\n\ Please enter the clock speed <in Megahertz> of your graphics card: ";
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
				cin>>numberOf_cores;}

		//Reslotion menu displlay and choice
		cout<<"What is the resolution of your monitor?\n"
		<<"\t1. 1280 x 720\n"
		<<"\t2. 1920 x 1080\n"
		<<"\t3. 2560 x 1440\n"
		<<"\t4. 3840 x 2160\n"
		<<"Please select from the options above:";
		cin>>choice;
		
		//Adding multiplier value for resolution choice and assigning resolution value
		if (choice =1)
		{
		multiplier =1;
		resolution= "1280 x 720";}
		
		
		else if (choice =2)
		{
		multiplier = .75;
		resolution="1920 x 1080";}
		
		else if (choice = 3)
		{
		multiplier = .55;
		resolution="2560 x 1440";}
		
		
		else if(choice = 4)
		{
		multiplier= .35;
		resolution="3840 x 2160;";}
		
		
		else
		{
		cout<<"invalid Resolution menu choice. Program will terminate."<<endl; 
		return 0;}
	
	
	//Caluculating performance score
	PERFORMANCE_SCORE = ((5*clockSpeed_graphics)+(numberOf_cores*clockSpeed_processor))*multiplier;
	
	//Storing performance score to display later
	outputFile <<PERFORMANCE_SCORE; 
	
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

} //end of NumOfcomp loop

//Opening score.txt to read highest/lowest performance scores
ifstream inputFile;

inputFile.open ("scores.txt");

//Validating file opened
;
if(inputFile)
{
		int PERFORMANCE_SCORE,
			number,
			largest=0,
			lowest=0;
			
	while(inputFile>>PERFORMANCE_SCORE)
	{
		cout<<number<<endl;
	}
	
}
else 
{
	cout<<"Error reading performance scores";
	return ;
}

inputFile.close(); //Closing file


return 0; 
	

}
