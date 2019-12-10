#include "Message.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

Messages::Messages()
{
	content[0] = 'a';
	encrypt = 0;
	numChar = 0;
}
Messages::Messages(char c, int e, int n)
{
	content[0] = c;
	encrypt = e;
	numChar = n;
}
int Messages::writeNormal(string filename, int var)
{
	ofstream outputFile;
	outputFile.open(filename, ios::trunc);
	if (!outputFile)
	{
		cout << "ERROR --- file could not open." << endl;
		return -2;
	}
	for (int i = 0; i < numChar; i++)
	{
		content[i] -= var;
		outputFile << content[i];
	}
	cout << "Content successfully decrypted." << endl;
	outputFile.close();
	return 0;
}
int Messages::readNormal(string filename)
{ 
	string norm;
	ifstream inputFile;
	inputFile.open(filename, ios::in);
	if (!inputFile)
	{
		cout << "ERROR --- file could not open." << endl;
		return -2;
	}
	while (!inputFile.eof())
	{
		getline(inputFile, norm);
		//cout << norm << endl;
	}
	strcpy_s(content, norm.c_str());
	numChar = strlen(content);
	inputFile.close();
	return 0;
}
int Messages::writeEncrypted(string filename, int var)
{
	ofstream outputFile;
	outputFile.open(filename, ios::trunc);
	if (!outputFile)
	{
		cout << "ERROR --- file could not open." << endl;
		return -2;
	}
	for (int i = 0; i < numChar; i++)
	{
		content[i] += var;
		outputFile << content[i];
	}
	cout << "Content successfully encrypted." << endl;
	outputFile.close();
	return 0;
}
int Messages::readEncrypted(string filename)
{
	string norm;
	ifstream inputFile;
	inputFile.open(filename, ios::in);
	if (!inputFile)
	{
		cout << "ERROR --- file could not open." << endl;
		return -2;
	}
	while (!inputFile.eof())
	{
		getline(inputFile, norm);
		//cout << norm << endl;
	}
	strcpy_s(content, norm.c_str());
	numChar = strlen(content);
	inputFile.close();
	return 0;
}
ostream& operator<<(ostream& output, Messages& i)
{
	output << " Begin Message: " << i.content << "End Message " << endl;
	return output;
}