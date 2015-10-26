#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"

class Player
{
public:
    Player();
    Player(QString nick_name,bool fold = false);
private:
    QString nick_name;
    int unique_num;
    std::vector<Card> hand;
    bool fold;


};

#endif // PLAYER_H
