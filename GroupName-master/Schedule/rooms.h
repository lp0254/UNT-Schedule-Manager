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
#ifndef ROOM_H
#define ROOM_H
	#include"room.h"
#endif

using namespace std;

class rooms
{
private:
	int RoomCnt;
public:
	room* roomArr;
	
	int addRoom(room myRoom)
	{
		srand(time(NULL));
		ofstream fout;
		fout.open("Room.txt", ios::app);
		string RoomString = myRoom.GetBuildingName() + "\t"  + LongToString(myRoom.GetRoomNumber()) + "\t" + LongToString(myRoom.GetCompacity()) + "\n";
		
		fout << RoomString;
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
	int runRoom()
	{
		char * word;
		FILE *fin = fopen("Room.txt", "r");
    		if (fin == NULL) 
		{
        			printf("Error opening input file\n");
        			return EXIT_FAILURE;
    		}

    		FILE *fout = fopen("Room.csv", "w");
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
