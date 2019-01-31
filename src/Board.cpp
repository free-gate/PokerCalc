#include "Board.h"


//---------------------------------------------------------------------------------------------------------------------------
bool pushNewCardToBoard(unique_ptr< vector<Card> > & board_ptr, const Hand & heroHand, const Hand & oppHand, const Card & card)
{
    if (!board_ptr->empty())
    {
        if (brute_force_matching_cards(board_ptr, card))
            return false;
    }
//    deck.gen(board, heroHand, oppHand);
    if (card != heroHand.getCard1() && 
        card != heroHand.getCard2() && 
        card != oppHand.getCard1() && 
        card != oppHand.getCard2())
    {
        board_ptr->push_back(card);

        return true;
    }
    else
        return false;
}
//---------------------------------------------------------------------------------------------------------------------------
bool brute_force_matching_cards(const unique_ptr< vector<Card> > & board_ptr, const Card &card)
{
    if (!board_ptr->empty())
    {
        for (auto const & el : *board_ptr)
        {
            if (card == el)
                return true;
        }        
    }

    return false;
}