#include "poker.h"

const std::string Card::get_suit() {
	switch (card_suit) {
	case 0: return "Hearts";
	case 1: return "Spades";
	case 2: return "Diamonds"; 
	case 3: return "Clubs";
	default: return "Hearts";
	}
}
const std::string Card::get_value() {
	switch (card_value) {
	case 0:  return "Ace";
	case 1:  return "Two";
	case 2:  return "Three";
	case 3:  return "Four";
	case 4:  return "Five";
	case 5:  return "Six";
	case 6:  return "Seven";
	case 7:  return "Eight";
	case 8:  return "Nine";
	case 9:  return "Ten";
	case 10:  return "Jack";
	case 11:  return "Queen";
	case 12:  return "King";
	default: return "Ace";
	}
}
const int Card::get_point_value() {
	switch (card_value) {
	case 0:  return 11;
	case 1:  return 2;
	case 2:  return 3;
	case 3:  return 4;
	case 4:  return 5;
	case 5:  return 6;
	case 6:  return 7;
	case 7:  return 8;
	case 8:  return 9;
	case 9:  return 10;
	case 10:  return 10;
	case 11:  return 10;
	case 12:  return 10;
	default: return 10;
	}
}
void Hand::get_all_cards() {
	list <Card> :: iterator it;
	for (it = card_list.begin(); it != card_list.end(); ++it)
		std::cout << it->get_value() << " of " << it->get_suit() << std::endl;
}

void Hand::get_dealer_card() {
	std::cout << card_list.front().get_value() << " of " << card_list.front().get_suit() << std::endl;

}

int Hand::ace_counter() {
	int total = 0;
	list <Card> ::iterator it;
	for (it = card_list.begin(); it != card_list.end(); ++it)
		if (it->get_value() == "Ace")
			total++;
	return total;
}

int Hand::get_point_value() {
	int total = 0;
	list <Card> ::iterator it;
	for (it = card_list.begin(); it != card_list.end(); ++it)
		total += it->get_point_value();
	int counter = Hand::ace_counter();
	while (total > 21) {
		if (counter > 0)
			total -= 10;
		else
			break;
	}
	return total;
}
void Deck::create_deck() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 13; ++j) {
			suit s = (suit)(i);
			value v = (value)(j);
			Card some_card(s, v);
			deck_list.push_back(some_card);
		}
	}
}

void Deck::print_deck() {
	list <Card> ::iterator it;
	for (it = deck_list.begin(); it != deck_list.end(); ++it)
		std::cout << it->get_suit() << ": " << it->get_value() << std::endl;
}
void Deck::deck_remove_card(Card rcard) {
	list <Card> ::iterator it;
	for (it = deck_list.begin(); it != deck_list.end(); ++it) {
	
		if (it->get_suit() == rcard.get_suit()) {
			if (it->get_value() == rcard.get_value()) {
				deck_list.erase(it);
				break;
			}
		}
	}

}
Card Deck::return_card() { 
	Card card = deck_list.front(); 
	deck_list.pop_front(); 
	return card;
}