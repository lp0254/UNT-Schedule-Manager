#include<string> 
#include<fstream>
#include<cstdlib>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<ctime>
#include <sstream>
#include <stdbool.h>
#include<cstring>
#ifndef EVENT_H
#define EVENT_H
	#include"event.h"
#endif

using namespace std;

class events
{
private:
	int EventCnt;
public:
	event* eventArr;
	
	int addEvent(event myEvent)
	{
		srand(time(NULL));
		ofstream fout;
		fout.open("Event.txt", ios::app);
		string EventString = myEvent.GetEventName() + "\t" + LongToString(myEvent.GetStartTime()) + ":"+ LongToString(myEvent.GetStartMinute()) + "\t" + LongToString(myEvent.GetEndTime()) + ":"+ LongToString(myEvent.GetEndMinute()) + "\t"+ LongToString(myEvent.GetStartDate()) + "/"+ LongToString(myEvent.GetStartDay()) + "/"+ LongToString(myEvent.GetStartYear()) + "\t"+ LongToString(myEvent.GetEndDate()) + "/"+ LongToString(myEvent.GetEndDay()) + "/"+ LongToString(myEvent.GetEndYear()) + "\t"+ LongToString(myEvent.GetCompacity()) + "\n";
		
		fout << EventString;
		fout.close();
		return 1;
	}
	std::string LongToString(long number)
	{
	  std::ostringstream oss;

	  // Works just like cout
	  oss<< number;

	  // Return the underlying string
	  return oss.str();
	}
	
	int runEvent()
	{
		char * word;
		FILE *fin = fopen("Event.txt", "r");
    		if (fin == NULL) 
		{
        			printf("Error opening input file\n");
        			return EXIT_FAILURE;
    		}

    		FILE *fout = fopen("Event.csv", "w");
    		if (fout == NULL) 
		{
        			printf("Error opening output file\n");
        			return EXIT_FAILURE;
    		}
		
		char line[1000];
		while (fgets(line, sizeof line, fin) != NULL)
		{
        			bool first_word = true;
        			word = strtok(line, " \t\n");
        			while (word) 
			{
            			fprintf(fout, "%s%s", first_word ? "" : ",", word);
            			first_word = false;
            			word = strtok(NULL, " \t\n");
        			}
        			fprintf(fout, "\n");
    		}
		fclose(fout);
		fclose(fin);
		printf("File converted");
		return 0;

		
	}

};
