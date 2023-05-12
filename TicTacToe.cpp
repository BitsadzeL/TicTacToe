#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void board(char playing_area[10])
{
	cout << endl;
	cout <<"		"<< playing_area[1] << "   " << playing_area[2] << "   " << playing_area[3] << endl;
	cout <<"		"<< endl;
	cout <<"		"<< playing_area[4] << "   " << playing_area[5] << "   " << playing_area[6] << endl;
	cout << endl;
	cout <<"		"<< playing_area[7] << "   " << playing_area[8] << "   " << playing_area[9] << endl;
	cout << endl;
}

int check_win(char playing_area[10])
{
	int result = 0;
	if (playing_area[1] == playing_area[2] && playing_area[2] == playing_area[3] && playing_area[3] == 'X')
	{
		cout << "Game over! player 1 won!" << endl;
		result = 1;

	}
	if (playing_area[4] == playing_area[5] && playing_area[5] == playing_area[6] && playing_area[6] == 'X')
	{
		cout << "Game over! player 1 won!" << endl;
		result = 1;
	}
	if (playing_area[7] == playing_area[8] && playing_area[8] == playing_area[9] && playing_area[9] == 'X')
	{
		cout << "Game over! player 1 won!" << endl;
		result = 1;
	}
	if (playing_area[1] == playing_area[4] && playing_area[4] == playing_area[7] && playing_area[7] == 'X')
	{
		cout << "Game over! player 1 won!" << endl;
		result = 1;
	}
	if (playing_area[2] == playing_area[5] && playing_area[5] == playing_area[8] && playing_area[8] == 'X')
	{
		cout << "Game over! player 1 won!" << endl;
		result = 1;
	}
	if (playing_area[3] == playing_area[6] && playing_area[6] == playing_area[9] && playing_area[9] == 'X')
	{
		cout << "Game over! player 1 won!" << endl;
		result = 1;
	}
	if (playing_area[1] == playing_area[5] && playing_area[5] == playing_area[9] && playing_area[9] == 'X')
	{
		cout << "Game over! player 1 won!" << endl;
		result = 1;
	}
	if (playing_area[3] == playing_area[5] && playing_area[5] == playing_area[7] && playing_area[7] == 'X')
	{
		cout << "Game over! player 1 won!" << endl;
		result = 1;
	}

	if (playing_area[1] == playing_area[2] && playing_area[2] == playing_area[3] && playing_area[3] == 'O')
	{
		cout << "Game over! player 2 won!" << endl;
		result = 1;
	}
	if (playing_area[4] == playing_area[5] && playing_area[5] == playing_area[6] && playing_area[6] == 'O')
	{
		cout << "Game over! player 2 won!" << endl;
		result = 1;
	}
	if (playing_area[7] == playing_area[8] && playing_area[8] == playing_area[9] && playing_area[9] == 'O')
	{
		cout << "Game over! player 2 won!" << endl;
		result = 1;
	}
	if (playing_area[1] == playing_area[4] && playing_area[4] == playing_area[7] && playing_area[7] == 'O')
	{
		cout << "Game over! player 2 won!" << endl;
		result = 1;
	}
	if (playing_area[2] == playing_area[5] && playing_area[5] == playing_area[8] && playing_area[8] == 'O')
	{
		cout << "Game over! player 2 won!" << endl;
		result = 1;
	}
	if (playing_area[3] == playing_area[6] && playing_area[6] == playing_area[9] && playing_area[9] == 'O')
	{
		cout << "Game over! player 2 won!" << endl;
		result = 1;
	}
	if (playing_area[1] == playing_area[5] && playing_area[5] == playing_area[9] && playing_area[9] == 'O')
	{
		cout << "Game over! player 2 won!" << endl;
		result = 1;
	}
	if (playing_area[3] == playing_area[5] && playing_area[5] == playing_area[7] && playing_area[7] == 'O')
	{
		cout << "Game over! player 2 won!" << endl;
		result = 1;
	}

	return result;
}

int check_draw(char playing_area[10])
{
	int draw = 0;
	if (playing_area[1] != '1' && playing_area[2] != '2' && playing_area[3] != '3' && playing_area[4] != '4' && playing_area[5] != '5'
		&& playing_area[6] != '6' && playing_area[7] != '7' && playing_area[8] != '8' && playing_area[9] != '9')
	{
		cout << "Game over! It's draw" << endl;
		draw = -1;
	}
	return draw;
}

void player_1_valid_check(char playing_area[10], int square)
{
	if (playing_area[square] != 'X' && playing_area[square] != 'O')
	{
		playing_area[square] = 'X';
	}
	else { cout << "Invalid move! You missed your turn" << endl; }
}

void player_2_valid_check(char playing_area[10], int square)
{
	if (playing_area[square] != 'X' && playing_area[square] != 'O')
	{
		playing_area[square] = 'O';
	}
	else { cout << "Invalid move! You missed your turn!" << endl; }
}


int main() {
	ofstream results("data.txt", fstream::app);
	string player_1_name, player_2_name;
	char playing_area[10] = { '0','1','2','3','4','5','6','7','8','9' };
	int square, result = -1, draw = 0;
	cout << "Enter names of players!" << endl;
	cin >> player_1_name >> player_2_name;
	cout << player_1_name << "-X" << " " << player_2_name << "-O" << endl;
	board(playing_area);
	while (true)
	{
		cout << player_1_name << "! Enter number of the square and I will place X for you" << endl;
		cin >> square;
		if (square > 9)
		{
			cout << "Too much! Enter again" << endl;
			cin >> square;
		}
		player_1_valid_check(playing_area, square);
		board(playing_area);
		draw = check_draw(playing_area);
		if (draw == -1)
		{
			results << "Players:" << player_1_name << " and " << player_2_name << "." << " Result:draw" << endl;
			break;
		}
		result = check_win(playing_area);
		if (result == 1)
		{
			results << "Players:" << player_1_name << " and " << player_2_name << "." << " Winner is " << player_1_name<<endl;
			break;
		}
		check_draw(playing_area);
		cout << player_2_name << "! Enter number of the square and I will place O for you" << endl;
		cin >> square;
		player_2_valid_check(playing_area, square);
		board(playing_area);
		draw = check_draw(playing_area);
		if (draw == -1)
		{
			results << "Players:" << player_1_name << " and " << player_2_name << "." << " Result:draw" << endl;
			break;
		}
		result = check_win(playing_area);
		if (result == 1)
		{
			results << "Players:" << player_1_name << " and " << player_2_name << "." << " Winner is " << player_2_name<<endl;
			break;
		}
		check_draw(playing_area);
	}
}

