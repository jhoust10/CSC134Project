/*This program will calculate a user's computer
hardware capabilities and reccomend graphic settings*/ 

#include <iostream>
#include <iomanip>
#include <string>

using namespace std; 

int main ()
{
	//to save user info and hold menu choice
	int choice,
		clockSpeed_graphics,
		clockSpeed_processor,
		numberOf_cores;
	
	double PERFORMANCE_SCORE; 
	
	//constants to hold the menu choice
	const int Res_One = 1,
		  	  RES_TWO = 2, 
		      RES_THREE = 3, 
		      RES_FOUR = 4;
	
	string resolution,
			quality;
	
	
		   	 
	//This get user's clock speed speed
	cout<<"Please enter the clock speed <in Megahertz> of your graphics card: ";
	cin>>clockSpeed_graphics;
		if (clockSpeed_graphics <= 0)
			{
		cout<<"Invalid graphics card speed entered. Program will terminate."<<endl;
		return 0;}
	 
	//This gets the user's processor speed
	cout<<"Please enter the clock speed <in Megahertz> of your processor: ";
	cin>>clockSpeed_processor; 
		if (clockSpeed_processor <= 0)
			{
			cout<<"Invalid processor speed entered. Program will terminate."<<endl;
			return 0;}
		
	//This gets the user's number of cores
	cout<<"Please enter the number of cores of your processor: ";
		cin>>numberOf_cores;
		if (numberOf_cores <= 0)
			{
			cout<< "Invalid number of cores entered. Program will terminate."<<endl;
			return 0;}

	//Reslotion menu displlay and choice
	cout<<"What is the resolution of your monitor?\n"
	<<"\t1. 1280 x 720\n"
	<<"\t2. 1920 x 1080\n"
	<<"\t3. 2560 x 1440\n"
	<<"\t4. 3840 x 2160\n"
	<<"Please select from the options above:";
	cin>>choice;
	
	//Adding multiplier value for resolution choice and assigning resolution value
	if (choice ==1)
		{
		choice =1;
		resolution= "1280 x 720";
	}
	else if (choice ==2)
		{
		
		choice =.75;
		resolution="1920 x 1080";
	}
	else if (choice == 3)
		{
		choice =.55;
		resolution="2560 x 1440";
	}
	else if(choice == 4)
	{
		choice =.35;
		resolution="3840 x 2160;";
	}
	else
		cout<<"invalid Resolution menu choice. Program will terminate."<<endl; 
	
	//Caluculating performance score
	PERFORMANCE_SCORE = ((5*clockSpeed_graphics)+(numberOf_cores*clockSpeed_processor))*choice;
	
	//processing recommendation based on perfomance score 
	if (PERFORMANCE_SCORE>1700)
		{quality = "Ultra";
	}
	else if (PERFORMANCE_SCORE>1500&& PERFORMANCE_SCORE<=1700)
		{quality = "High";
	}
	else if (PERFORMANCE_SCORE>1300&&PERFORMANCE_SCORE<=1500)	
		{quality= "Medium";
	}
	else if (PERFORMANCE_SCORE>1100&&PERFORMANCE_SCORE<=13000)
		{quality= "Low";
	}
	else 
		{quality= "unable to Play";
	}
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
	
	return 0; 
	

}
