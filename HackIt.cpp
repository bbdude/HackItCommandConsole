// HackItProtoType.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TextClass.h"
#include "PlayerClass.h"
#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <msclr\marshal_cppstd.h>
#include <conio.h>
#include <algorithm>
#include <windows.h>
#include <sstream>
//#include <stdio.h>
//#include <sql.h>

using namespace std;
using namespace System;
using namespace System::Net;
using namespace System::Text;
//using namespace System::Data::Sql;
using namespace msclr::interop;

enum MENUCOMMANDS {CHECKMISSION,CHECKSTATS,FINDOTHERMEMBERS,TOPAGENTS,HELP,RETYPE,EXIT};

string getBetween(string input,string startFind,string endFind)
{
	std::string::size_type    start_position = 0;
	std::string::size_type    end_position = 0;
	start_position = input.find(startFind);
	end_position = input.find(endFind);
	
	return input.substr(start_position + 1, (end_position - start_position) -1);
}
string collectPassword()
{
	string pass = "";
	char currentKey = ' ';
	while (currentKey != 13)
	{
		currentKey = _getch();
		if ( currentKey == 127 || currentKey == 8)
			pass.substr(0, pass.size()-1);
		else
			pass += currentKey;
		for (int i = 0; i != pass.length();i++)
			cout << "*";
		system("cls");
		Sleep(20);
		

	}
	return pass;
}
string collectQuest()
{
	WebClient^ client = gcnew WebClient;
	String^ reply = client->DownloadString( "http://iigniteus.com/Logs/HackIt/quests" );
	System::String^ clrString = (reply);
	return marshal_as<std::string>(clrString);
}
string collectQuest(int line)
{
	WebClient^ client = gcnew WebClient;
	String^ reply = client->DownloadString( "http://iigniteus.com/Logs/HackIt/quests" );
	System::String^ clrString = (reply);
	string str = marshal_as<std::string>(clrString);
	str = getBetween(str,"|" + std::to_string(static_cast<long long>(line)),std::to_string(static_cast<long long>(line)) + "|");

	return str;
}
string decryptQuest(string &questLine,string &type,string &skillType,float &skillValue)
{
	//[Starting Quest](eCommand)<1>{a}
	string name;
	
	//Get the name
	name = getBetween(questLine,"[","]");	
	type = getBetween(questLine,"(",")");
	skillType = getBetween(questLine,"{","}");
	skillValue = (float)::atof(getBetween(questLine,"<",">").c_str());

	//cout << endl << name;
	//cout << endl << type;
	//cout << endl << skillType;
	//cout << endl << skillValue << endl;
	//Sleep(5000);

	return name;
}

MENUCOMMANDS returnMenuCommands (std::string & inString) {
	//CHECKMISSION,CHECKSTATS,FINDOTHERMEMBERS,TOPAGENTS,HELP,RETYPE};
	std::transform(inString.begin(), inString.end(), inString.begin(), ::tolower);
	Sleep(500);
	if (inString == "c" || inString == "checkmission" || inString == "check mission" || inString == "c mission" || inString == "mission" || inString == "checkmissions" || inString == "check missions" || inString == "c missions" || inString == "missions") return CHECKMISSION;
	else if (inString == "checkstats" || inString == "check stats" || inString == "c stats" || inString == "stats" || inString == "checkstat" || inString == "check stat" || inString == "c stat" || inString == "stat") return CHECKSTATS;
	else if (inString == "findothermembers" || inString == "find other members" || inString == "find members" || inString == "find" || inString == "members" || inString == "member") return FINDOTHERMEMBERS;
	else if (inString == "topagents" || inString == "top agents" || inString == "topagent" || inString == "top agent" || inString == "top" || inString == "agents" || inString == "agent") return TOPAGENTS;
	else if (inString == "help") return HELP;
	else if (inString == "exit" || inString == "close") return EXIT;
	else
	{
		return RETYPE;
	}
}

void drawBar()
{
	std::cout << "|*****************************|" << endl;
}
void collectStats(PlayerClass & player)
{
	system("cls");
	drawBar();
	cout << "Your Skills are:" << endl;
	cout << "*Hacking: " << player.getHacking() <<  endl;
	cout << "*Encryption: " << player.getEncryption() << endl;
	cout << "*Decryption: " << player.getDecryption() << endl;
	cout << "*Intelligence: " << player.getIntellegence() << endl;
	cout << "*Gather Intel: " << player.getGatherIntel() << endl;
	cout << "*Timing: " << player.getTiming() << endl;
	cout << "*Speed: " << player.getSpeed() << endl;
	cout << "*Prediction: " << player.getPrediction() << endl;
	cout << "*Tracking: " << player.getTracking() << endl;
	cout << "*Hiding: " << player.getHiding() << endl;
	drawBar();
	Sleep(5000);
}

int collectAllQuests(string &type,string &skillType,float &skillValue)
{
	string currentQuestName = "";
    std::ostringstream out;
	int index;
	int choice;
	do
	{
		choice = 0;
		index = 0;
		string currentQuestName = "";
		type = "N/A";
		skillType = "";
		skillValue = 0.0f;
		drawBar();
		while(currentQuestName != "Starting Quest" || index == 1)
		{
			out.str("");
			cout << "[" + to_string(static_cast<long long>(index)) + "]";
			if (index == 0)
				cout << "Return to menu";
			cout << currentQuestName;
			out << skillValue;
			cout << " [Type: " 
				+ type 
				+ "] [You will gain: " 
				+  out.str()
				+ "XP]" << endl;
			currentQuestName = " ";
			index++;
			currentQuestName = decryptQuest(collectQuest(index),type,skillType,skillValue);
		}
		cout << endl;
		drawBar();
		cout << "Select a quest: " << endl;
		cin >> choice;

		system("cls");
	}while(choice <= index);
	
	Sleep(500);

	return choice;
	
}

int main(array<System::String ^> ^args)
{
	//Console::WriteLine(L"Hello World");

	//First test username and password
	//collectPassword();

	//Accept them into the network of hackers

	//if this is the first time logging in then run the tutorial mission
	//else go into basic loop

		//1st option
		//do the starting mission and set all values to 1 after

		//2nd option
		//show menu full of missions stats ect that updates every min checking for new quests
		//std::cout << collectQuest() << endl;

	PlayerClass player;
	bool endMainLoop = false;
	bool firstTime = false;
	string commandReader;
	string password = "Dr@gonsBr3ath";
		string readPass = "HiCc0mm@nd";
	MENUCOMMANDS menuCommands;
	menuCommands;
	//Mission stuff
	//What type will the mission be
	string type = "";
	//If the mission is a certain type it may need you to decrypt or analyze something and this is the correct result
	string winCode = "";
	//What will you gain for the mission
	string skillType = "";
	//How much you gain in the skilltype of completion
	float skillValue = 0.0f;


	if (!firstTime)
		while(!endMainLoop)
		{
			Sleep(50);
			system("cls");
			drawBar();
			cout << "Welcome to the \"HackIt Command Console\"(HiCc)" << endl;
			cout << "[Check Missions]" << endl;
			cout << "[Check Stats]" << endl;
			cout << "[Find Other Members]" << endl;
			cout << "[Top Agents]" << endl;
			cout << "[Help]" << endl;
			drawBar();

			std::getline(cin,commandReader);


			switch (returnMenuCommands(commandReader))
			{
			case CHECKMISSION:
				system("cls");
				drawBar();
				cout << "Checking missions" << endl;
				//decryptQuest(collectQuest(2),type,skillType,skillValue);
				collectAllQuests(type,skillType,skillValue);
				drawBar();
				Sleep(500);
				break;
			case CHECKSTATS:
				system("cls");
				drawBar();
				cout << "Checking stats" << endl;
				drawBar();
				Sleep(500);
				collectStats(player);
				break;
			case FINDOTHERMEMBERS:
				system("cls");
				drawBar();
				cout << "Finding other members" << endl;
				drawBar();
				Sleep(500);
				break;
			case TOPAGENTS:
				system("cls");
				drawBar();
				cout << "Finding top agents" << endl;
				drawBar();
				Sleep(500);
				break;
			case HELP:
				system("cls");
				drawBar();
				cout << "Loading help" << endl;
				drawBar();
				Sleep(500);
				break;
			default:
				system("cls");
				drawBar();
				cout << "You typed something in wrong" << endl;
				drawBar();
				Sleep(500);
				break;
			}
		}
	//else
		//Do first mission




	
	return 0;





}