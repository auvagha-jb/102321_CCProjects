#include<stdlib.h>
#include<string.h>
#include<fstream>
#include <iostream>
#include<vector>
#include <ctype.h>

#include "LexicalAnalyzer.h"

using namespace std;


int main() {
	ifstream fin("code_file.txt");
	char fileInput;

	//The class where the analyzer operations are defined
	LexicalAnalyzer analyzer;

	//Open the file. Exit on error
	if (!fin.is_open()) {
		cout << "Error while opening the file\n";
		exit(0);
	}

	while (!fin.eof()) {
		//Get the file contents
		fileInput = fin.get();

		//Loop through the characters and categorize them accordingly
		
		//Others 
		analyzer.findOtherChar(fileInput);

		//Math operators
		analyzer.findMathOperator(fileInput);

		//Logical operators
		analyzer.findLogicalOperator(fileInput);

		//Numeric values
		analyzer.findNumericValue(fileInput);
			
		//Keywords and identifiers
		analyzer.findKeywordsAndIdentifiers(fileInput);
	}

	fin.close();

	//Print the output to console
	analyzer.printAll();

	return 0;
}
