/***********************************************************************
Tittle :     Silly Simple Math Tutor
programmer : Hazel kaliati
replit:https://replit.com/@HazelKaliati/Silly-simple-tutor-final-project#main.cpp
Description : This is a simple math tutor for young students.It loops multiple
times displaying different levels depending on the answers the user gets the
user gets a right. All the questions will be stored in a 2D vector and produce a
summary report at when the user quits
**********************************************************************/

#include <cctype>   //for characters
#include <ctime>    //for single parameter
#include <iomanip>  //need this for setw
#include <iostream> //to include the input/output stream library
#include <limits>   // numerical limits
#include <string>   ///for string variables
#include <vector>   //used to store evrery question to produce a report

using namespace std;

int main() {

  const int MAX_ATTEMPTS = 3;  // how many attempts the user gets per question
  const int RANGE_CHANGE = 10; // the range of numbers that can be used
  enum MathType { MT_ADD = 1, MT_SUB = 2, MT_MUL = 3, MT_DIV = 4 };
  MathType mathType = MT_ADD;
  vector<vector<int>> questions; // store vectors

  char mathSymbols = '?'; // +,-,*,

  string userName = "?";
  string userInput = "?";

  int currentLevel = 1;
  int currentRange = RANGE_CHANGE;
  int correctAnswer = 0;
  int tempNum = 0;
  int rightNum = 0;
  int leftNum = 0;
  int totalCorrect = 0;
  int totalIncorrect = 0;
  int userAnswer = 0;
  int attemptsLeft = 0;

  cout << "**********************************************************" << endl;
  cout << "*            The silly simple Math Tutor                 *" << endl;
  cout << "***********************************************************" << endl;
  cout << " " << endl;
  cout << "welcome to the Silly Simple Tutor!" << endl;
  cout << " " << endl;
  cout << "Math made easier for you! :)" << endl;
  cout << " " << endl;
  cout << "Fun math Facts : " << endl;
  cout << "     * Math teachers have problems." << endl;
  cout << "     * Math is the only subject that counts." << endl;
  cout << "     * If it seems easy you are doing it wrong." << endl;
  cout << "     * No calendars would exist without Math." << endl;
  cout << "     * Time is nonexistent without Math." << endl;
  cout << " " << endl;

  cout << "What is your name?";
  getline(cin, userName);

  cout << " " << endl;

  cout << "Welcome " << userName << " "
       << "to the Silly Simple Math Tutor!" << endl;

  do { // loop multiple times

    leftNum = rand() % currentRange + 1;
    rightNum = rand() % currentRange + 1;
    mathType =
        static_cast<MathType>(rand() % 4 + 1); // 1=add, 2=sub, 3=mult, 4 =div

    if (leftNum < rightNum) { // make sure the left number is always greater
                              // than  than the right number
      tempNum = leftNum;
      leftNum = rightNum;
      rightNum = tempNum;
    }

    switch (mathType) {
    case MT_ADD:
      mathSymbols = '+';
      correctAnswer = leftNum + rightNum;
      break;

    case MT_SUB:
      mathSymbols = '-';
      correctAnswer = leftNum - rightNum;
      break;

    case MT_MUL:
      mathSymbols = '*';
      correctAnswer = leftNum * rightNum;
      break;

    case MT_DIV: // logic is bit different because we want to avoid
                 // fractions/decimals//
      mathSymbols = '/';
      correctAnswer = leftNum;
      leftNum = leftNum * rightNum;
      break;

    default:
      cout << "invalid mathType " << mathType << endl;
      cout << "error -1" << endl;
      cout << "contact Hazel Kaliati" << endl;
      break;
    }

    cout << " " << endl;

    vector<int> row = {currentLevel, leftNum, mathSymbols, rightNum,
                       correctAnswer}; // store vectors

    for (int i = 1; i <= MAX_ATTEMPTS; i++) {
      cout << "["
           << "level #" << currentLevel << "] " << userName << " what is ";
      cout << leftNum << (mathSymbols) << rightNum << "? ";
      // This loop will give the user an option to aswer the question for each
      // and every level. If the user answrer is correct the user will move on
      // to the next level, if the answeris incorrect the user will get 3
      // aattempts. If the 3 attempts fail the user will level down.
      while (!(cin >> userAnswer)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\tInvalid input !" << endl;
        cout << "\tPlease enter a number:  ";
      }

      if (userAnswer == correctAnswer) {
        totalCorrect++;
        cout << "good job, you got it correct!" << endl;
        row.push_back(i); // storing attemmpts
        break;

      } else {
        cout << "you have"
             << " " << MAX_ATTEMPTS - i << " attempt(s) left" << endl;
        if (i == MAX_ATTEMPTS) {
          cout << " The correct answer is " << correctAnswer << endl;
          totalIncorrect++;
          row.push_back(4);
        }
      }
    }

    questions.push_back(row);

    if (totalCorrect == 3) {
      currentLevel++;
      currentRange += RANGE_CHANGE;
      totalCorrect = 0;
      totalIncorrect = 0;
      cout << " " << endl;
      cout << "Excellent!, you just leveled up to level " << currentLevel
           << " and your change is now between "
              "1 and "
           << currentRange << endl;

    } else if (totalIncorrect == 3 && currentLevel > 1) {
      currentLevel--;
      currentRange += RANGE_CHANGE;
      totalCorrect = 0;
      totalIncorrect = 0;
      cout << " " << endl;
      cout << " Oh no!, you just leveled down to level " << currentLevel
           << " and you range is "
              "now between 1 and "
           << currentRange << endl;
    }

    getline(cin, userInput);

    while (true) {
      cout << " " << endl;
      cout << "Do you want to continue (y=yes | n=no)? ";
      getline(cin, userInput);

      for (int i = 0; i < userInput.size(); i++) {
        userInput.at(i) = tolower(userInput.at(i));
      } // end of for loop to lower case's input

      if (userInput == "y" || userInput == "yes" || userInput == "n" ||
          userInput == "no") {
        break; // break out of the inner while loop
      } else {
        cout << "Invalid input, please try again." << endl;
        cout << endl;
      } // end of if (y, yes ,n, no)

    } // end of inner while loop to validate y, yes, n,no

  } while (userInput == "yes" || userInput == "y");

  cout << " " << endl;

  cout << "==================================================" << endl;
  cout << " " << endl;
  cout << "              Summary Report                    " << endl;
  cout << " " << endl;
  cout << "==================================================" << endl;
  cout << "Level             Question          Attempts      " << endl;
  cout << " " << endl;
  cout << "------  -------------------------- ---------------" << endl;

  totalCorrect = 0;
  totalIncorrect = 0;

  for (int i = 0; i < questions.size(); i++) { // used to display the report
    currentLevel = questions.at(i).at(0);
    leftNum = questions.at(i).at(1);
    mathSymbols = static_cast<char>(questions.at(i).at(2));
    rightNum = questions.at(i).at(3);
    correctAnswer = questions.at(i).at(4);
    attemptsLeft = questions.at(i).at(5);

    cout << "  " << setw(2) << right << currentLevel << "  "
         << "  " << setw(3) << right << leftNum << " "
         << " " << setw(2) << right << mathSymbols << " "
         << "  " << setw(2) << right << rightNum << "  " << setw(3) << right
         << "="
         << " "
         << " " << setw(2) << right << correctAnswer << "  ";

    if (attemptsLeft != 4) { // used to display attempts on report
      cout << "   " << attemptsLeft << endl;
      totalCorrect++;
    } else {
      cout << "   "
           << "Incorrect" << endl;
      totalIncorrect++;
    }
  }
  cout << " " << endl;
  cout << "  "
       << "Total questions: " << right << setw(5) << questions.size() << endl;
  cout << "  "
       << "Total correct  : " << right << setw(5) << totalCorrect << endl;
  cout << "  "
       << "Total InCorrect: " << right << setw(5) << totalIncorrect << endl;
  cout << "  "
       << "Average correct: " << right << setw(5)
       << (totalCorrect * 100) / questions.size() << "%" << endl;

  cout << " " << endl;
  cout << "Thank you for playing :)" << endl;
  cout << " " << endl;
  cout << "Goodbye ! " << endl;

  return 0;
}