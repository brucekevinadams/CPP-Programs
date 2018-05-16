#include<iostream>
#include<vector>

using namespace std;

class Person {
	protected:
	string firstName;
	string lastName;
	int id;

	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}

	void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}

};

class Student:public Person{
	private:
		vector<int> testScores;  
        int numS;
        int score;
        int sum;
        double average;  
        char grade;

	public:
        Student(string first, string last, int id, vector<int> scores): Person(first,last,id) {
             this->testScores=scores;
             numS=testScores.size();
	   }

	char calculate() {

		for (int i = 0; i < numS; i++)
			sum += testScores[i];

		average = sum / numS;

		if (average >= 90 && average <= 100) {
			grade = 'O';
		} else if (average >= 80 && average <= 89) {
			grade = 'E';
		} else if (average >= 70 && average <= 79) {
			grade = 'A';
		} else if (average >= 55 && average <= 69) {
			grade = 'P';
		} else if (average >= 40 && average <= 54) {
			grade = 'D';
		} else {
			grade = 'T';
		}
		return grade;
	}

};

int main() {
	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}