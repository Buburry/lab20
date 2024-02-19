#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string& filename, vector<string>& names, vector<int>& scores, vector<char>& grades) {
    ifstream file(filename);
    char format[] = "%[^:]: %d %d %d";

    string s;

    while (getline(file, s)) {
        char name[200];
        int score1, score2, score3;
    
        sscanf(s.c_str(), format, name, &score1, &score2, &score3);

        names.push_back(name);
        scores.push_back(score1 + score2 + score3);  // Assuming you want the total score
       
        char grade = score2grade(score1 + score2 + score3);
        grades.push_back(grade);
    }
}

void getCommand(string &command, string &key){

    cout << "Please input your command: ";
    cin >> command;
    cin.ignore();
    getline(cin, key);
}

void searchName(vector<std::string>& names, vector<int>& scores, vector<char>& grades, string key) {
    string Keyinthis = toUpperStr(key);    //แปลง key เป็นตัวใหญ่
    bool found = false;   //ตัวแปรเริ่มต้น

    for (size_t i = 0; i < names.size(); i++) {          //size_t คือ unsign int     
        string upperCaseName = toUpperStr(names[i]);    //แปลงค่าทุกตัวจนหมด

        if (upperCaseName.find(Keyinthis) != string::npos) {    // upperCaseName.find(Keyinthis) หาชื่อ key != string::npos คล้าย -1 คือหาจนกว่าจะไม่เจอ
    
            cout << "---------------------------------" << endl;
            cout << names[i] << "'s score = " << scores[i] << endl;        // ถ้าเจอชื่อจะเจออย่างอื่นด้วย
            cout << names[i] << "'s grade = " << grades[i] << endl;
            cout << "---------------------------------" << endl;
            found = true;
        }
    }

    if (!found) {
       
        cout << "---------------------------------" << endl;
        cout << "Cannot found." << endl;
        cout << "---------------------------------" << endl;
    }
}


void searchGrade(vector<string> &names, vector<int> &scores, vector<char> &grades, string key) {
    string Keyinthis = toUpperStr(key); // Convert search key to uppercase
    bool found = false;
    
    cout << "---------------------------------" << endl;
    
        for (size_t i = 0; i < names.size(); i++) {
            char upperCaseGrade = toupper(grades[i]);

            if (upperCaseGrade == Keyinthis[0]) { // Assuming Keyinthis is a single character
            
                cout << names[i] << " (" << scores[i] << ")" << endl;
            
                found = true;
            
            }
        }
    
        if (!found) {
        
            cout << "Cannot found." << endl;
        
        }
    
    cout << "---------------------------------" << endl;
}




int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}


#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename, vector<string>& names, vector<int>& scores, vector<char>& grades) {
    ifstream info(filename);
    
    string line;
    
    char name[100];
    
    int grade1, grade2, grade3;
    
    while(getline(info, line)) {
        sscanf(line.c_str(), "%[^:]: %d %d %d", name, &grade1, &grade2, &grade3);
        names.push_back(name);
        int gradesum = grade1 + grade2 + grade3;
        scores.push_back(gradesum);
        grades.push_back(score2grade(gradesum));
    }
}


void getCommand(string &command, string &key){
    string line;
    
    cout << "Please input your command: ";
    getline(cin, line);
    
    int space = line.find(' ');
    
    if (space == 0) {
        command = line;
        key = "";
    } else {

        command = line.substr(0, space);
        key = line.substr(space + 1);
        
    }

}



void searchName(vector<string> names, vector<int> scores, vector<char> grades, string key){
    vector<string> namu = names;
    for (auto& name : namu) {
        name = toUpperStr(name);
    }
    key = toUpperStr(key);
    unsigned int i = 0;
    while(i < names.size()){
        if(namu[i] == key){
           cout << "---------------------------------" << endl;
           cout << names[i] << "'s score = " << scores[i] << endl;
           cout << names[i] << "'s grade = " << grades[i] << endl;
            cout << "---------------------------------" << endl;
            break;
        }
        i++;
    }
    
    if(i == names.size()){
        cout << "---------------------------------" << endl;
        cout << "Cannot found." << endl;
        cout << "---------------------------------" << endl;
    }
}
    

void searchGrade(vector<string> &names, vector<int> &scores, vector<char> &grades, string key){

    key = toUpperStr(key);
    unsigned int i = 0;
    int count = 0;
    cout << "---------------------------------" << endl;
    
    while(i < grades.size()){
        if(grades[i] >= 'a' && grades[i] <= 'z'){
            grades[i] -= 32;
        }
        if(grades[i] == key[0]){

            cout << names[i] << " (" << scores[i] << ")" << endl;
            count += 1;
        }
        i++;
    }
    if(i == grades.size() && count == 0){
        cout << "Cannot found." << endl;
    }
    cout << "---------------------------------" << endl;
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}