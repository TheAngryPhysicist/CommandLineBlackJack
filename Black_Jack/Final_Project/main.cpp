/*This is the main file for a Blackjack game, which is accompanies by poker.h and poker.cpp*/
#include "poker.h"

using namespace std;

void start_message();
void game_message();
void Game();
int game_loop(Player &player, Player &dealer, Deck &deck);

int main() {
	Game();
	return 0;
}

void start_message() {
	cout << "What would you like to do?: " << endl;
	cout << "1 - Play game" << endl;
	cout << "2 - Quit." << endl;
}

void game_message() {

	cout << "What would you like to do?: " << endl;
	cout << "1 - Hit." << endl;
	cout << "2 - Stay." << endl;
}

void hand_message(Player player, Player dealer) {
	cout << "Player Hand: " << endl;
	player.show_hand();	
	cout << "Dealer top card:" << endl;
	dealer.dealer_show_hand();
}

int game_loop(Player &player, Player &dealer, Deck &deck) {
	int flag;
	int out_flag;
	hand_message(player, dealer);
	game_message();
	cin >> flag;
	if (flag == 1) {
		player.hit(deck.return_card());
		//cout << player.get_point_value() << endl;
		if (player.get_point_value() > 21)
			out_flag = 3;
		else
			out_flag = 1;
	}
	else if (flag == 2)
		out_flag = 2;
	else
		cout << "input must be a 1 or 2." << endl;
	return out_flag;
}
int dealer_loop(Player &player, Player &dealer, Deck &deck, int flag) {
	int out_flag = 0;
	if (flag == 0) {
		if (player.get_point_value() > dealer.get_point_value()) {
			dealer.hit(deck.return_card());
			if (dealer.get_point_value() > 21) {
				cout << "Dealer Busted, You win!" << endl;
				dealer.show_hand();
				out_flag = 2;
			}
			else
				out_flag = 1;
		}
		else if (player.get_point_value() < dealer.get_point_value()) {

			cout << "Dealer wins, You lose!" << endl;
			dealer.show_hand();
			out_flag = 2;
		}

	}
	else if (flag == 1) {
		cout << "Game Over." << endl;
		out_flag == 2;
	}
	else {
		cout << "Error in dealer loop" << endl;
		out_flag == 0;
	}
	return out_flag;

}

void Game() {
	int flag = 0;
	Deck deck;
	deck.create_deck();
	deck.shuffle_deck();
	
	Player player(deck.return_card(), deck.return_card());
	if (player.get_point_value() == 21) {
		cout << "You win!" << endl; 
		player.show_hand();
	}
	else {
		Player dealer(deck.return_card(), deck.return_card());

		while (true) {
			int gl = game_loop(player, dealer, deck);
			if (gl == 1)
				continue;
			else if (gl == 2)
				break;
			else if (gl == 3) {
				cout << "You busted!" << endl; 
				flag = 1; 
				break;
			}
		}
		while (true) {
			int dl = dealer_loop(player, dealer, deck, flag);
			if (dl == 1)
				continue;
			else if (dl == 2)
				break;
			else if (dl == 0)
				cout << "Error in dealer loop." << endl; break;
		}
	}
}