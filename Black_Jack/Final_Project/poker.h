#ifndef POKER_H
#define POKER_H
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

enum suit { Hearts, Spades, Diamonds, Clubs, NONES };
enum value { Ace, two, three, four, five, six, seven, eight, nine, ten, Jack, Queen, King, NONEV };

template <class T > void listShuffle(list<T> &L)
{
	vector<T> V(L.begin(), L.end());
	shuffle(V.begin(), V.end(), mt19937{ std::random_device{}() });
	L.assign(V.begin(), V.end());
}

class Card {
	suit card_suit;
	value card_value;
public:
	Card(const suit s, const value v) : card_suit(s), card_value(v) {}
	const string get_suit();
	const string get_value();
	const int get_point_value();

};

class Hand {
	list <Card> card_list;

public:
	Hand(const Card c, const Card d) { card_list.push_back(c); card_list.push_back(d); }
	int get_size() { return card_list.size(); }
	int ace_counter();
	int get_point_value();
	void get_all_cards();
	void get_dealer_card();
	void hit(Card new_card) { card_list.push_back(new_card); }
	
};

class Deck {
	list <Card> deck_list;
public:
	Deck() {}
	void create_deck(); 
	void print_deck();
	void deck_remove_card(Card rcard);
	int get_size() { return deck_list.size(); }
	void shuffle_deck() { listShuffle(deck_list);; };
	Card return_card();

};

class Player {
	Hand Player_Hand;
public:
	Player(Hand new_hand) : Player_Hand(new_hand) {}
	Player(Card card_1, Card card_2) : Player_Hand(card_1, card_2) {}
	void show_hand() { Player_Hand.get_all_cards(); }
	void dealer_show_hand() { Player_Hand.get_dealer_card(); }
	void hit(Card new_card) { Player_Hand.hit(new_card); }
	int get_point_value() { return Player_Hand.get_point_value(); }
};
#endif POKER_H