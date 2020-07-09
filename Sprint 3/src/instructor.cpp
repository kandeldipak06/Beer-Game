#include "include/instructor.h"
#include "include/game.h"

Instructor::Instructor(){
    instrId = 1;
	instrEmail = "default@abc.com";
	instrPassword = "00000";
}

Instructor::~Instructor(){
    for(int i = 0; i < (int)games.size(); i++){
        delete games[i];
    }
}


void Instructor::showGamesStatus(){
    /*
     *
     * code for custom game design, linking with UI needed
     *
    */

}

int Instructor::createGame(){
    Game *game_instance = new Game;
    games.push_back(game_instance);
    if(!games.size()){
        game_instance->setGId(instrId*10 + 1);
    }else{
        game_instance->setGId(games.back()->getGId()+1);
    }
    game_instance->setInstrId(instrId);
    game_instance->setPFactId(game_instance->getGId()*10 +1);
    game_instance->setPDistributorId(game_instance->getPFactId()+1);
    game_instance->setPWholesalerId(game_instance->getPDistributorId()+1);
    game_instance->setPRetailerId(game_instance->getPWholesalerId()+1);


    /*
     *
     * code for custom game design, linking with UI needed
     *
    */
    game_instance->setNumberOfPlayers(5);

    games.push_back(game_instance);
    return game_instance->getGId();
}

std::vector<int> Instructor::createGames(int numOfGames){
    std::vector<int> v;
    for(int i =0; i < numOfGames; i++){
        v.push_back(this->createGame());
    }
    return  v;
}

