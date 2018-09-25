/****************************
Name    : Swathi Prakasha
Wind Chill Calculator
****************************/

 
/***************************************************************************************************************
This is program to calculate windchill based on the formula 
windchill(F) = 35.74 + 0.6215*T - 35.75*V^0.16 + 0.4275*V^0.16,   where T is temprature, V is wind speed
and checks for the invalid inputs.
The program mainly have 2 functions along with the main function one to calculte and other to print the table 
******************************************************************************************************************/


#include<iostream>
#include<cmath>
#include<iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;
using std::string;



//Global Variable declaration
float highTemp=0,lowTemp=0,tempDecr=0,lowWind=0,highWind=0,windIncr=0;
float windChill=0.0;

//Function Prototypes
void PrintTable(float highTemp,float lowTemp,float tempDecr,float lowWind,float highWind,float windIncr);
float WindchillCalculator(float &T, float &V);


int main()
{

// the below code collects data from the user 
cout<<"Enter the temprature range high value(degrees F):"; 
cin>>highTemp;
cout<<"Enter temprature range low value(degrees F):";
cin>>lowTemp;
cout<<"Enter the  temprature decrement(degrees,F):";
cin>>tempDecr;
cout<<"Enter the wind speed  low value(mph):";
cin>>lowWind;
cout<<"Enter the wind speed high value(mph):";
cin>>highWind;
cout<<"Enter the wind speed increment(mph):";
cin>>windIncr;
cout<<endl;


/******************************************************************************
Error Handling
 The following if condition throws the error message for the 3 conditions 
1. Temprature range start with high value and go down
2. Wind speed range start with low and go up
3. Increment and decrement values should always be positive
*******************************************************************************/

if((lowTemp>highTemp) || (lowWind>highWind) || (tempDecr <= 0 || windIncr <= 0))
{
     cout<<"Invalid Input"<<endl;

	if(lowTemp>highTemp)
	{
  	    cout<<"Temp range should start with a high value and go down."<<endl<<endl;
	}
	
	if (lowWind>highWind)
	{
	    cout<<endl<<"Wind Speed ranges start with low value and go up."<<endl<<endl;
	}

	 if(tempDecr <= 0 || windIncr <=0)
	{     
		cout<<"Increment and decrement values should be positive."<<endl<<endl;
	}

		
   return 1;
}


//This following code calls the PrintTable() function, which in turn prints the table based on input
PrintTable(highTemp,lowTemp,tempDecr,lowWind,highWind, windIncr);

return 0;
}

/*********************************************************************************
This PrintTable() function prints the table based on the user input
In the following function, for loop is used to print the table contents

*********************************************************************************/

void PrintTable(float highTemp,float lowTemp,float tempDecr,float lowWind,float highWind,float windIncr)
{
 
	cout<<" Wind Chill Table"<<endl<<endl;
	cout<<" Air Temperature"<<endl;
  	cout<<setw(9)<<"(deg.F)"; 	

// The following for loop creates the table header
	for(float j=highTemp;j>=lowTemp;j-=tempDecr)
	{ 
  	  
	cout<<setw(9)<<fixed<<setprecision(3)<<j;
	}
	
	cout<<endl;
	
// The following for loop creates the header line
	for(float k=highTemp;k>=(lowTemp-tempDecr);k-=tempDecr)
	{
        char c ='-';	
	cout<<string(9,c);           
	}
	
	cout<<endl;
	cout<<setw(9)<<"Wind Speed"<<endl;
	cout<<setw(9)<<"(mph)"<<endl;


//The following code is to print the main contents of table 
     for(float i= lowWind; i<=highWind;i+=windIncr)
      { 
	
  	   cout<<setw(9)<<fixed<<setprecision(3)<<i;
	   cout<<"|";	

	for(float j=highTemp;j>=lowTemp;j-=tempDecr) 
	 
	  {	
	
		windChill= WindchillCalculator(j,i);
			
		cout<<setw(9)<<fixed<<setprecision(3)<<windChill;
         }

	
	cout<<endl;
       }

} // end of the PrintTable() function


/************************************************************************************
This function WindChillCalculator() caluates the windchill based on the given formula
An If condition included for handling the temp <=50 & air speed <=3
*************************************************************************************/

float WindchillCalculator(float &T,float &V)
{


        if (V<=3 ||T>=50)
		{
			windChill = T ;
		}
	else 
		windChill = 35.74 +( 0.6215*T) - (35.75*powf(V,0.16)) +( 0.4275*T*powf(V,0.16));
		
	return windChill;
}
