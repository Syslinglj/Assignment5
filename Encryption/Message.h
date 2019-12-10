#include <iostream>
#include <string>
using namespace std;

class Messages
{
protected:
	char content[1000];
	int encrypt;
	int numChar;

public:
	Messages();
	Messages(char c, int e, int n);
	int writeNormal(string filename, int var);
	int writeEncrypted(string filename, int var);
	int readEncrypted(string filename);
	int readNormal(string filename);
	friend ostream& operator<<(ostream& output, Messages& i);
};