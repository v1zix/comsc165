#ifndef CARD_H
#define CARD_H
#include <string>

///<summary> 
///Card class used in representing a typical playing like one used in the game of Poker.
///</summary>
class Card
{
public:
	enum class Suit
	{
		CLUBS,
		DIAMONDS,
		HEARTS,
		SPADES
	};
	Card();
	Card(int num, Card::Suit suit);
	Card(int num, Card::Suit suit, std::string desc);
	~Card();
	Card::Suit getSuit();
	int getNumber();
	std::string getDescription();
	void setNumAndSuit(int num, Card::Suit suit);
	bool operator<(Card &rightCard);
	bool operator==(const Card &rightCard);
	bool operator!=(Card &rightCard);

private:
	Card::Suit m_suit;
	int m_number;
	std::string m_description;
	static std::string m_suitStrings[];
	static std::string m_numStrings[];
};

///<summary> 
/// Constructor for Card object. Uses default constructor.
///</summary>
///<returns> Nothing. </returns>
Card::Card()
{
}

///<summary>
///Constructor for Card object.
///</summary>
///<param name="num"> Value on the card. 9 - Jack, 10 - Queen, 11 - King, 12 - Ace. All numerical values are represented by value-2. </param>
///<param name="suit"> Suit of the card. </param>
///<returns> Nothing. </returns>
Card::Card(int num, Card::Suit suit)
{
	m_number = num;
	m_suit = suit;
	m_description = Card::m_numStrings[num] + " " + Card::m_suitStrings[static_cast<int>(suit)];
}

///<summary>
///Constructor for Card object.
///</summary>
///<param name="num"> Value on the card. 9 - Jack, 10 - Queen, 11 - King, 12 - Ace. All numerical values are represented by value-2. </param>
///<param name="suit"> Suit of the card. </param>
///<param name="desc"> Description of the card, using the card value and suit. (E.g., Spades Ace) </param>
///<returns> Nothing. </returns>
Card::Card(int num, Card::Suit suit, std::string desc)
{
	// Make this constructor just for when we read all the data back and repopulate the collection
	m_number = num;
	m_suit = suit;
	m_description = desc;
}

///<summary> Default destructor for Card class. No special actions taken. </summary>
///<returns> Nothing. </returns>
Card::~Card()
{
}

///<summary> Getter function for suit of the Card object. </summary>
///<returns> The suit of the Card using one of the values in Card::Suit. </returns>
inline Card::Suit Card::getSuit()
{
	return m_suit;
}

///<summary> Getter function for number of the Card object. </summary>
///<returns> An integer representing the card value. </returns>
inline int Card::getNumber()
{
	return m_number;
}

///<summary> Getter function for the description of the Card object. </summary>
///<returns> The description of the card (E.g., 'Spades Ace'). </returns>
inline std::string Card::getDescription()
{
	return m_description;
}

///<summary>
///Setter for Card object.
///</summary>
///<param name="num"> Value on the card. 9 - Jack, 10 - Queen, 11 - King, 12 - Ace. All numerical values are represented by value minus 2. </param>
///<param name="suit"> Suit of the card. </param>
///<returns> Nothing. </returns>
void Card::setNumAndSuit(int num, Card::Suit suit)
{
	m_number = num;
	m_suit = suit;
	m_description = Card::m_numStrings[num] + " " + Card::m_suitStrings[static_cast<int>(suit)];
}

///<summary> 
///Determines if a card to the left of the '<' symbol is of lower value than the card to the right.
///Suit priority from lowest to highest: Clubs, Diamonds, Hearts, Spades
///Card value priority from lowest to highest: 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace
///</summary>
///<param name="rightCard"> The card to the right of the '<' symbol. </param>
///<returns> True if the card to the left of the '<' symbol is of lower value than the card to the right, otherwise false. </returns>
bool Card::operator<(Card & rightCard)
{
	bool result = false;
	Card::Suit rightCardSuit = rightCard.getSuit();
	int rightCardNum = rightCard.getNumber();

	if (rightCardSuit < m_suit)
	{
		result = false;
	}
	else if (rightCardSuit == m_suit)
	{
		// In a standard 52 card deck you can't have duplicates so no need to check that condition
		if (m_number > rightCardNum)
		{
			result = false;
		}
		else
		{
			result = true;
		}
	}
	else
	{
		result = true;
	}
	return result;
}

///<summary> 
///Determines if a card to the left of the '==' symbol is equal to the card to the right.
///</summary>
///<param name="rightCard"> The card to the right of the '==' symbol. </param>
///<returns> True if both the left and right cards have the same number and suit, otherwise false. </returns>	
bool Card::operator==(const Card & rightCard)
{
	return (this->m_number == rightCard.m_number && this->m_suit == rightCard.m_suit);
}

///<summary> 
///Determines if a card to the left of the '!=' symbol is not equal to the card to the right.
///</summary>
///<param name="rightCard"> The card to the right of the '!=' symbol. </param>
///<returns> True if either the number or suit is different for the left and right card, otherwise false. </returns>
bool Card::operator!=(Card &rightCard)
{
	if (m_number != rightCard.getNumber() || m_suit != rightCard.getSuit())
	{
		return true;
	}
	return false;
}
// This suit array needs to stay in the same order as the Suit Public Enum
std::string Card::m_suitStrings[] = { "Clubs", "Diamonds", "Hearts", "Spades" };
std::string Card::m_numStrings[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };

#endif // !CARD_H