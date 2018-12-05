//create database

#include<string> 
#include<fstream>
#include<cstdlib>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<ctime>
#include <sstream> 

using namespace std;
CreateDatabase();

CreateDatabase()
{
	String type;
	String name;
	String fname;
	ofstream database;
	cout<< "Select database type: "<< endl << "1. Course" << endl << "2. Classroom" << endl << "3. Event" << endl;
	cin >> type;
	cout << endl << "Enter the name of the database" << endl;
	cin >> name;
	fname = type + "-" + name + ".txt";
	database.open(fname);
	database.close(fname);
}
