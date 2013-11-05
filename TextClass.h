#pragma once

#include <string>

using namespace std;

class TextClass
{
public:
	TextClass(void);
	~TextClass(void);

	//Voids
	void setMaxLines(int change);
	void setCurrentLine(int change);
	void setWidth(int change);
	void setHeight(int change);
	void setLine(string change,int whichLine);
	void setLine(string change);
	//
	//Ints
	int getMaxLines();
	int getCurrentLine();
	int getWidth();
	int getHeight();
	//
	//Bools

	//
	//Floats

	//
	//String
	string getCurrentLineText();
	string getLineText(int line);
	//

private:
	int maxLines;
	int currentLine;
	int width;
	int height;
	string lines[5];
};

