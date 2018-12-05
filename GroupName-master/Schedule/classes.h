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
#ifndef CLASSY_H
#define CLASSY_H
	#include"classy.h"
#endif

using namespace std;

class classes
{
private:
	int ClassCnt;
public:
	classy* classyArr;
	
	int addClass(classy myClass)
	{
		srand(time(NULL));
		ofstream fout;
		fout.open("Course.txt", ios::app);
		string ClassString = LongToString(myClass.GetCourseID()) + "\t" + myClass.GetClassName() + "\t" + myClass.GetCourseName() + "\t" + LongToString(myClass.GetStartTime()) + ":" + LongToString(myClass.GetStartMinute()) + "\t" + LongToString(myClass.GetEndTime()) + ":"+ LongToString(myClass.GetEndMinute()) + "\t" + LongToString(myClass.GetStartDate()) + "/" + LongToString(myClass.GetStartDay()) + "/" + LongToString(myClass.GetStartYear()) + "\t"+ LongToString(myClass.GetEndDate()) +"/"+ LongToString(myClass.GetEndDay()) + "/"+ LongToString(myClass.GetEndYear()) +"\t"+ LongToString(myClass.GetCompacity()) + "\n";
		
		fout << ClassString;
		fout.close();
		return myClass.GetCourseID();
	}
	std::string LongToString(long number)
	{
	  std::ostringstream oss;

	  // Works just like cout
	  oss<< number;

	  // Return the underlying string
	  return oss.str();
	}
	
	
	int runClass()
	{
		char * word;
		FILE *fin = fopen("Course.txt", "r");
    		if (fin == NULL) 
		{
        			printf("Error opening input file\n");
        			return EXIT_FAILURE;
    		}

    		FILE *fout = fopen("Course.csv", "w");
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
