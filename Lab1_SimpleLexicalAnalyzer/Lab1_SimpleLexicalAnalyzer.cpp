#include<stdlib.h>
#include<string.h>
#include<fstream>
#include <iostream>
#include<vector>
#include <ctype.h>

#include "AnalyzerService.h"

using namespace std;


int main() {
	ifstream fin("code_file.txt");
	char fileInput;

	//The analyzerService class where the analyzer operations are defined
	AnalyzerService analyzer;

	//Attempt to open the file
	if (!fin.is_open()) {
		cout << "Error while opening the file\n";
		exit(0);
	}

	while (!fin.eof()) {
		//The file contents
		fileInput = fin.get();

		//loop through the characters and categorize them accordingly
		
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
