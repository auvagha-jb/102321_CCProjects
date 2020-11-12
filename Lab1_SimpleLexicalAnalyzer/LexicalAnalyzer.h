#include <vector>
#include <string>

using namespace std;

class LexicalAnalyzer {

	int mark[1000] = { 0 }, j = 0, aaa = 0;
	char buffer[15], b[30];

	/**
		The characters contained in the file are looped through and tested to check if they match the given
		character
		The vectors are used to store the tokens once they are categorized 
	*/
	vector<string>keywords;
	vector<char>identifiers;
	vector<char>logicalOperators;
	vector<char>mathOperators;
	vector<string>numericaValues;
	vector<char>others;

	/**
		Takes an array of characters as an argument, 
		and returns 0 or 1 depending on whether the characters 
		match one of the keywords in the array 
	*/
	int isKeyword(char buffer[]) {
		char keywords[32][10] = {
			"auto","break","case","char","const","continue","default",
			"do","double","else","enum","extern","float","for","goto",
			"if","int","long","register","return","short","signed",
			"sizeof","static","struct","switch","typedef","union",
			"unsigned","void","volatile","while"
		};

		int i, flag = 0;

		for (i = 0; i < 32; ++i) {
			if (strcmp(keywords[i], buffer) == 0) {
				flag = 1;
				break;
			}
		}

		return flag;
	}

public:

	/**
		Takes character input and specifies determines if it falls into 
		the 'other' category i.e. characters that do not fall into any of the other 
		categories 
	*/
	void findOtherChar(char fileChar) {
		char other[] = ",;\(){}[]'':";

		for (int i = 0; i < 12; ++i) {
			if (fileChar == other[i]) {
				int aa = fileChar;
				if (mark[aa] != 1) {
					others.push_back(fileChar);
					mark[aa] = 1;
				}
			}
		}
	}

	/**
		Takes character input and determines if is a mathematical operator or not
	*/
	void findMathOperator(char fileChar) {
		char math_op[] = "+-*/=";

		for (int i = 0; i < sizeof(math_op); ++i) {
			if (fileChar == math_op[i]) {
				int aa = fileChar;
				if (mark[aa] != 1) {
					mathOperators.push_back(fileChar);
					mark[aa] = 1;
				}
			}
		}
	}

	/**
		Takes character input and determines if it is a logical operator
	*/
	void findLogicalOperator(char fileChar) {
		char logical_op[] = "><";
		for (int i = 0; i < sizeof(logical_op); ++i) {
			if (fileChar == logical_op[i]) {
				int aa = fileChar;
				if (mark[aa] != 1) {
					logicalOperators.push_back(fileChar);
					mark[aa] = 1;
				}
			}

		}
	}

	/**
		Takes character input and determines if it is a numerical value
	*/
	void findNumericValue(char fileChar) {
		if (fileChar == '0' || fileChar == '1' || fileChar == '2' || fileChar == '3' || fileChar == '4' || fileChar == '5' || fileChar == '6' || fileChar == '7' || fileChar == '8' || fileChar == '9' || fileChar == '.' || fileChar == ' ' || fileChar == '\n' || fileChar == ';') {
			if (fileChar == '0' || fileChar == '1' || fileChar == '2' || fileChar == '3' || fileChar == '4' || fileChar == '5' || fileChar == '6' || fileChar == '7' || fileChar == '8' || fileChar == '9' || fileChar == '.')
				b[aaa++] = fileChar;
			if ((fileChar == ' ' || fileChar == '\n' || fileChar == ';') && (aaa != 0)) {
				b[aaa] = '\0';
				aaa = 0;
				char arr[30];
				strcpy_s(arr, b);
				numericaValues.push_back(arr);
			}
		}
	}

	/**
		Takes character input and determines if it is either a keyword or identifier
	*/
	void findKeywordsAndIdentifiers(char fileChar) {
		if (isalnum(fileChar)) {
			buffer[j++] = fileChar;
		}

		else if ((fileChar == ' ' || fileChar == '\n') && (j != 0)) {
			buffer[j] = '\0';
			j = 0;

			if (isKeyword(buffer) == 1) {
				keywords.push_back(buffer);
			}
			else {

				if (buffer[0] >= 97 && buffer[0] <= 122) {
					if (mark[buffer[0] - 'a'] != 1) {
						identifiers.push_back(buffer[0]);
						mark[buffer[0] - 'a'] = 1;
					}

				}

			}

		}

	}

	/**
		Takes a vector of strings which contains the values to be printed to console 
		It also takes a string which describes what type of input the vector is 
	*/
	void print(string label, vector<string>vec) {
		cout << label << ": ";
		for (int f = 0;f < vec.size(); ++f) {
			if (f == vec.size() - 1) {
				cout << vec[f] << "\n";
			}
			else {
				cout << vec[f] << " ";
			}
		}
	}


	/**
		Takes a vector of characters which contains the values to be printed to console 
		It also takes a string which describes what type of input the vector is 
	*/
	void print(string label, vector<char>vec) {
		cout << label << ": ";
		for (int f = 0;f < vec.size(); ++f) {
			if (f == vec.size() - 1) {
				cout << vec[f] << "\n";
			}
			else {
				cout << vec[f] << " ";
			}
		}
	}

	/**
		Prints the contents of all vectors to the console line by line
	*/
	void printAll() {
		print("Keywords", keywords);
		print("Identifiers", identifiers);
		print("Math Operators", mathOperators);
		print("Logical Operators", logicalOperators);
		print("Numeric values", numericaValues);
		print("Others", others);
	}

};