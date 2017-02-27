
#include <iostream>
#include<stdlib.h>
#include <queue>
#include <cmath>
using namespace std;

//struct definition of team information
typedef struct team {
	char name;
	int number;
	int weight;

	//make sure sub amount less than 1
	//lager amount team give lightest player to the other
	friend bool operator <(team t1, team t2) {
		return t1.weight>t2.weight; //lighter priority
	}

}players;

//array record the number and weight

const int W = 5000;
const int N = 100;
int arr[N + 1][W + 1];

int maxWeight(int a, int b) {
	return a>b ? a : b;
}
int main()
{
	int pnum, pwgt;
	int sum = 0; //total weight
	cout << "please enter the amount of player:" << endl;
	cin >> pnum;

	cout << "please enter the weight of each player:" << endl;


	//new the players
	players *tPlayer = new players[pnum + 1];

	//initialize the team information

	for (int i = 1; i <= pnum; i++) {
		int w = 0;
		cin >> w; //weight
		//tPlayer[i].name = 'A';
		tPlayer[i].number = i;
		tPlayer[i].weight = w;
		tPlayer[i].name = 'B';
		sum += w;
	}
	int aver = sum / 2;

	//initialize the array first row and column
	for (int j = 0; j <= N; j++) arr[j][0] = 0;
	for (int j = 0; j <= W; j++) arr[0][j] = 0;

	for (int i = 1; i<=pnum; i++) {
		for (int j = 1; j<= aver; j++)
		{
			arr[i][j] = arr[i - 1][j];
			if (tPlayer[i].weight <= j) {
				arr[i][j] = maxWeight(arr[i][j], arr[i - 1][j - tPlayer[i].weight] + tPlayer[i].weight); //forum
			}
		}
	}
	//pick player of team a
	int rest = aver;
	for (int i = pnum; i >= 1; i--)
	{
		if ( rest>=tPlayer[i].weight )
		{
			if ((arr[i][rest] - arr[i - 1][rest - tPlayer[i].weight]) == tPlayer[i].weight)
			{
				tPlayer[i].name = 'A';
				rest = rest - tPlayer[i].weight;
			}
		}
	}
	//result after round one
	//for(int i=1;i<=pnum;i++){
	//     cout<<"team"<<tPlayer[i].name;
	//     cout<<"Number"<<tPlayer[i].number<<" "<<"Weight"<<tPlayer[i].weight<<endl;
	// }

	//new players
	priority_queue<team> teamA;
	priority_queue<team> teamB;

	//evaluate the team players
	for (int i = 1; i <= pnum; i++) {
		if (tPlayer[i].name == 'A') {
			teamA.push(tPlayer[i]);
		}
		else
			teamB.push(tPlayer[i]);
	}
	int countA = teamA.size();
	int countB = teamB.size();

	//make sure the sub less than 1
	while (abs(countA - countB)>1) {

		if (countA>countB)
		{
			teamB.push(teamA.top()); //give the lightest to B
			teamA.pop();
			countA--;
			countB++;
		}
		if (countA<countB)
		{
			teamA.push(teamB.top()); //give the lightest to A
			teamB.pop();
			countA++;
			countB--;
		}

	}
	int sumA = 0;
	cout << "team A" << endl;
	while (!teamA.empty()) {
		cout << "Number" << teamA.top().number << " " << "Weight" << teamA.top().weight << endl;
		sumA += teamA.top().weight;
		teamA.pop();
	}
	cout << "team A total weight" << sumA << endl;

	int sumB = 0;
	cout << "team B" << endl;
	while (!teamB.empty()) {
		cout << "Number" << teamB.top().number << " " << "Weight" << teamB.top().weight << endl;
		sumB += teamB.top().weight;
		teamB.pop();
	}
	cout << "team B total weight" << sumB << endl;

	cout << "The SUB of team A and B is:" << abs(sumA - sumB) << endl;

	delete[] tPlayer;
	system("pause");
	return 0;


}
