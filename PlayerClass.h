#pragma once

#include <string>

using namespace std;

class PlayerClass
{
public:
	PlayerClass(void);
	~ PlayerClass(void);

	//getters
	float getHacking();
	float getEncryption();
	float getDecryption();
	float getIntellegence();
	float getGatherIntel();
	float getTiming();
	float getSpeed();
	float getPrediction();
	float getTracking();
	float getHiding();
	//
	//setters
	void setAll(float change);
	void setHacking(float change);
	void setEncryption(float change);
	void setDecryption(float change);
	void setIntellegence(float change);
	void setGatherIntel(float change);
	void setTiming(float change);
	void setSpeed(float change);
	void setPrediction(float change);
	void setTracking(float change);
	void setHiding(float change);
	//
	//edits
	void editAll(float change);
	void editHacking(float change);
	void editEncryption(float change);
	void editDecryption(float change);
	void editIntellegence(float change);
	void editGatherIntel(float change);
	void editTiming(float change);
	void editSpeed(float change);
	void editPrediction(float change);
	void editTracking(float change);
	void editHiding(float change);
	//
private:
	float hacking;
	float encryption;
	float decryption;
	float intelligence;
	float gatherIntel;
	float timing;
	float speed;
	float prediction;
	float tracking;
	float hiding;
};

