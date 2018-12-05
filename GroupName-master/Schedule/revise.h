//revise
#include<string> 
#include<fstream>
#include<cstdlib>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<ctime>
#include <sstream> 
#include <ofstream>
#include classy.h

using namespace std;

revise();

revise()
{
	String type;
	String name;
	String edit;
	int maxline = 0;
	int currentline;
	ofstream database;
	
	cout << "enter database type" << endl;
	cout << "Classroom" << endl;
	cout << "Course" << endl;
	cout << "Event" << endl;
	cin >> type;
	
	cout << endl << "enter name of database" << endl;
	cin >> name;
	
	fname = type + "-" + name + ".txt";
	database.open(fname);
	
	//prints the file with the line number on the left
	//e.x 0: first line of the file
	// 1: second line of the file
	while(!fname.eof())
	{
		cout<< maxline << ": " << fname.getline(maxline);
		maxline++;
	}
	cout << endl;
	
	//asking for the line number to edit and the string to replace the line with.
	cout << "Select wich line to edit: ";
	cin >> currentline;
	cout << endl;
	cout << "enter new line: ";
	cin >> edit;
	
	//goes to the selected line and replaces it with the new string.
	
	//goes to line
	
	
	//replaces line with edit
	
	
}