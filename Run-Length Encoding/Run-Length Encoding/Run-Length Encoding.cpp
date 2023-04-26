//mohamed hesham abdelfattah (201050108)
#include<iostream>
#include<fstream>
#include <string>
using namespace std;
int fileLength(fstream& f) {
	const auto begin = f.tellg();
	f.seekg(0, ios::end);
	const auto end = f.tellg();
	const auto fsize = (end - begin);
	f.close();
	return fsize;

}
void printfunction(char fs[15])
{
	//for geting file length
	fstream infile;
	infile.open("data.txt", ios::in);
	int fileSize = fileLength(infile);
	
	//(RLE)Implementation

	for (int i = 0; i < fileSize; i++)
	{ // Count occurrences
		int cnt = 1;
		while (i < fileSize - 1 && fs[i] == fs[i + 1])
		{
			cnt++;
			i++;
		}
		// Print the character and the count
		cout << " " << fs[i] << "\t\t" << cnt << '\n';
	}
} 
void main()
{
	//geting file length
	fstream infile;
	infile.open("data.txt", ios::in);
	int fileSize = fileLength(infile);


	infile.open("data.txt", ios::in );
	char *str = new char[fileSize+1];
	int i = 0;

	cout << "Character" << " frequency" << '\n';
	//geting the text into char array

	infile.unsetf(ios::skipws);

	while (!infile.eof())
	{
		infile >> str[i];
		i++;
	}
	printfunction(str);
		
	infile.close();
	system("pause");
	
}