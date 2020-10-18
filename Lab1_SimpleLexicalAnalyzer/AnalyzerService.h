#include <vector>
#include <string>

using namespace std;

class AnalyzerService {

	int mark[1000] = { 0 }, j = 0, aaa = 0;
	char buffer[15], b[30];

	//Vectors to store the tokens once they are categorized
	vector<string> keywords;
	vector<char>identifiers;
	vector<char>logicalOperators;
	vector<char>mathOperators;
	vector<string>numericaValues;
	vector<char>others;

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

	void findOtherChar(char fileChar) {
		char other[] = ",;\(){}[]'':";

		for(int i = 0; i < 12; ++i) {
			if (fileChar == other[i]) {
				int aa = fileChar;
				if (mark[aa] != 1) {
					others.push_back(fileChar);
					mark[aa] = 1;
				}
			}
		}
	}

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

	void printAll() {
		print("Keywords", keywords);
		print("Identifiers", identifiers);
		print("Math Operators", mathOperators);
		print("Logical Operators", logicalOperators);
		print("Numeric values", numericaValues);
		print("Others", others);
	}

};