#include <iostream>
#include <vector>
#include <string>
using namespace std;


class ScoreBoard {
public:
	static int score;
	static void increaseScore(int x);
	static void printScore();
	static void resetScore();
};
int ScoreBoard::score=0;
void ScoreBoard::increaseScore(int x) {
	score += x;
}
void ScoreBoard::printScore() {
	cout << "----------- SCORE BOARD ----------" << endl;
	cout << "Current Score: " << score << endl;
	cout << endl;
}
void ScoreBoard::resetScore() {
	score = 0;
}
int main() {
	ScoreBoard::increaseScore(10);
	ScoreBoard::increaseScore(5);
	ScoreBoard::increaseScore(8); 
	ScoreBoard::printScore();   
	ScoreBoard::resetScore();     
	ScoreBoard::printScore(); 
	return 0;
}