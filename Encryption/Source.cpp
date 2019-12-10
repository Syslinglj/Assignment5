#include <iostream>
#include <string>
#include "Message.h"
using namespace std;
//C:\\test.txt
int main()
{
	Messages myMessages;
	string directory = "";
	char input = 'o';
	int mod = 0;

	cout << " Would you like to (E)ncrypt a file, (D)ecrypt a file or (Q)uit." << endl;
	cin >> input;
	//begins loop until quit
	while (input != 'q' && input != 'Q')
	{
		if (input != 'e' && input != 'E')// looks for incorrect values entered and repeats
		{
			if (input != 'd' && input != 'D')
			{
				cout << "You entered an incorrect value." << endl;
				cout << "To encrypt a file type 'E', to decrypt a file type 'D', to quit type 'Q'." << endl;
				cin >> input;
			}
		}
		if (input == 'e' || input == 'E') // encrypts the txt file
		{
			cout << "Please enter the file directory location of the file you would like to encrypt. Must double ""\\"" symbols. " << endl;
			cin >> directory;
			cout << "Please enter a number to encrypt with." << endl;
			cin >> mod;
			myMessages.readNormal(directory);
			myMessages.writeEncrypted(directory, mod);
		}
		if (input == 'd' || input == 'D') // decrypts the txt file
		{
			cout << "Please enter the file directory location of the file you would like to decrypt. Must double ""\\"" symbols. " << endl;
			cin >> directory;
			cout << "Please enter the number the file was encrypted with." << endl;
			cin >> mod;
			myMessages.readEncrypted(directory);
			myMessages.writeNormal(directory, mod);
		}

		cout << " Would you like to (E)ncrypt a file, (D)ecrypt a file or (Q)uit." << endl;
		cin >> input;
	}
}
