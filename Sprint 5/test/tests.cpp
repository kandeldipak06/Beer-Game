#include "gtest/gtest.h"
#include "../src/player.h"
#include "../src/playerinterface.h"
#include "../src/game.h"
#include "../src/instructor.h"
#include "../src/playerevent.h"
#include "../src/client/playerclient.h"

/** Tests for class Player  **/

TEST(playerTest, setPIdTest)
{
    Player p;
    p.setPId(1);
    EXPECT_EQ(p.getPId(), 1);
}

TEST(playerTest, getPIdTest)
{
    Player p;
    p.setPId(1);
    EXPECT_EQ(p.getPId(), 1);
}

TEST(playerTest, setRoleTest)
{
    Player p;
    p.setRole(1);
    EXPECT_EQ(p.getRole(), 1);
}

TEST(playerTest, getRoleTest)
{
    Player p;
    p.setRole(1);
    EXPECT_EQ(p.getRole(), 1);
}

TEST(playerTest, getInventoryTest)
{
    Player p;
    p.setInventory(6);
    EXPECT_EQ(p.getInventory(), 6);
}

TEST(playerTest, setInventoryTest)
{
    Player p;
    p.setInventory(6);
    EXPECT_EQ(p.getInventory(), 6);
}

TEST(playerTest, getBackorderTest)
{
    Player p;
    p.setBackorder(6);
    EXPECT_EQ(p.getBackorder(), 6);
}

TEST(playerTest, setBackorderTest)
{
    Player p;
    p.setBackorder(6);
    EXPECT_EQ(p.getBackorder(), 6);
}

TEST(playerTest, setIncomingOrderTest)
{
    Player p;
    p.setDemand(6);
    EXPECT_EQ(p.getDemand(), 6);
}

TEST(playerTest, getIncomingOrderTest)
{
    Player p;
    p.setDemand(6);
    EXPECT_EQ(p.getDemand(), 6);
}

TEST(playerTest, setIncomingShipmentTest)
{
    Player p;
    p.setIncomingShipment(1);
    EXPECT_EQ(p.getIncomingShipment(), 1);
}

TEST(playerTest, getIncomingShipmentTest)
{
    Player p;
    p.setIncomingShipment(1);
    EXPECT_EQ(p.getIncomingShipment(), 1);
}

TEST(playerTest, setOutgoingShipmentTest)
{
    Player p;
    p.setOutgoingShipment(1);
    EXPECT_EQ(p.getOutgoingShipment(), 1);
}

TEST(playerTest, getOutgoingShipmentTest)
{
    Player p;
    p.setOutgoingShipment(1);
    EXPECT_EQ(p.getOutgoingShipment(), 1);
}

TEST(playerTest, getCostTest)
{
    Player p;
    p.setOutgoingShipment(1);
    EXPECT_EQ(p.getOutgoingShipment(), 1);
}

TEST(playerTest, setCostTest)
{
    Player p;
    p.setOutgoingShipment(1);
    EXPECT_EQ(p.getOutgoingShipment(), 1);
}

TEST(playerTest, getTotalCostTest)
{
    Player p;
    EXPECT_EQ(p.getTotalCost(), 0);
}

TEST(playerTest, setTotalCostTest)
{
    Player p;
    p.setTotalCost(3);
    EXPECT_EQ(p.getTotalCost(), 3);
}

TEST(playerTest, isOrderReceivedTest)
{
    Player p;
    p.receiveOrder(5);
    EXPECT_EQ(p.isOrderReceived(), true);
}

TEST(playerTest, setOrderReceivedTest)
{
    Player p;
    p.receiveOrder(5);
    EXPECT_EQ(p.isOrderReceived(), true);
}

TEST(playerTest, isShipmentReceivedTest)
{
    Player p;
    p.receiveShipment(5);
    EXPECT_EQ(p.isShipmentReceived(), true);
}

TEST(playerTest, setShipmentReceivedTest)
{
    Player p;
    p.receiveShipment(5);
    EXPECT_EQ(p.isShipmentReceived(), true);
}

TEST(playerTest, setOrderPlacedTest)
{
    Player p;
    p.placeOrder(5);
    EXPECT_EQ(p.isOrderPlaced(), true);
}

TEST(playerTest, isOrderPlacedTest)
{
    Player p;
    p.placeOrder(5);
    EXPECT_EQ(p.isOrderPlaced(), true);
}

TEST(playerTest, setShipmentPlacedTest)
{
    Player p;
    p.placeShipment(5);
    EXPECT_EQ(p.isShipmentPlaced(), true);
}

TEST(playerTest, isShipmentPlacedTest)
{
    Player p;
    p.placeShipment(5);
    EXPECT_EQ(p.isShipmentPlaced(), true);
}

TEST(playerTest, setDemandTest)
{
    Player p;
    p.setDemand(6);
    EXPECT_EQ(p.getDemand(), 6);
}

TEST(playerTest, getDemandTest)
{
    Player p;
    p.setDemand(6);
    EXPECT_EQ(p.getDemand(), 6);
}

TEST(playerTest, getGameTest)
{
    char appName[] = {'t', 'e', 's', 't'};
    char *testArgV[] = {appName};
    int testArgC = 1;

    QApplication *app = new QApplication(testArgC, testArgV);
    PlayerInterface *pi = new PlayerInterface();
    Game *game = new Game();
    pi->setGame(game);
    EXPECT_EQ(pi->getGame(), game);

    delete pi;
    delete game;
    delete app;
}

TEST(playerTest, setGameTest)
{
    char appName[] = {'t', 'e', 's', 't'};
    char *testArgV[] = {appName};
    int testArgC = 1;

    QApplication *app = new QApplication(testArgC, testArgV);
    PlayerInterface *pi = new PlayerInterface();
    Game *game = new Game();
    pi->setGame(game);
    EXPECT_EQ(pi->getGame(), game);

    delete pi;
    delete game;
    delete app;
}

//placeOrder should call Game's addOrder method
TEST(playerTest, placeOrderTest)
{
}

//placeOrder should call Game's addShipment method
TEST(playerTest, placeShipmentTest)
{
    // part of functional test: tests_game_logic.cpp
}

//getAvailableShipment returns the number of beers that are available for shipment to the next Player
TEST(playerTest, getAvailableShipmentTest)
{
    Player p;
    p.setDemand(12);
    p.setInventory(15);
    EXPECT_EQ(12, p.getAvailableShipment(12));
}

TEST(playerTest, receiveShipmentTest)
{
    Player p;
    p.receiveShipment(1);
    EXPECT_EQ(p.isShipmentReceived(), true);
}

TEST(playerTest, receiveOrderTest)
{
    Player p;
    p.receiveOrder(1);
    EXPECT_EQ(p.isOrderReceived(), true);
}

TEST(playerTest, decreaseInventoryTest)
{
    Player p;
    p.setInventory(6);
    p.decreaseInventory(2);
    EXPECT_EQ(p.getInventory(), 4);
}

TEST(playerTest, increaseInventoryTest)
{
    Player p;
    p.setInventory(6);
    p.increaseInventory(2);
    EXPECT_EQ(p.getInventory(), 8);
}

/** Tests for class Game **/

TEST(gameTest, setShipmentDelayTest)
{

    Game g;
    g.setShipmentDelay(3);
    EXPECT_EQ(3, g.getShipmentDelay());
}

TEST(gameTest, getShipmentDelayTest)
{

    Game g;
    g.setShipmentDelay(8);
    EXPECT_EQ(8, g.getShipmentDelay());
}

TEST(gameTest, setOrderDelayTest)
{

    Game g;
    g.setOrderDelay(3);
    EXPECT_EQ(3, g.getOrderDelay());
}

TEST(gameTest, getOrderDelayTest)
{

    Game g;
    g.setOrderDelay(10);
    EXPECT_EQ(10, g.getOrderDelay());
}

TEST(gameTest, setGIdTest)
{

    Game g;
    g.setGId(34);
    EXPECT_EQ(34, g.getGId());
}

TEST(gameTest, getGIdTest)
{

    Game g;
    g.setGId(6);
    EXPECT_EQ(6, g.getGId());
}

TEST(gameTest, setInstrIdTest)
{

    Game g;
    g.setInstrId(20);
    EXPECT_EQ(20, g.getInstrId());
}

TEST(gameTest, getInstrIdTest)
{

    Game g;
    g.setInstrId(2);
    EXPECT_EQ(2, g.getInstrId());
}

TEST(gameTest, setPFactIdTest)
{

    Game g;
    g.setPFactId(100);
    EXPECT_EQ(100, g.getPFactId());
}

TEST(gameTest, getPFactIdTest)
{

    Game g;
    g.setPFactId(1030);
    EXPECT_EQ(1030, g.getPFactId());
}

TEST(gameTest, getPDistributorIdTest)
{

    Game g;
    g.setPDistributorId(56);
    EXPECT_EQ(56, g.getPDistributorId());
}

TEST(gameTest, setPDistributorIdTest)
{

    Game g;
    g.setPDistributorId(45);
    EXPECT_EQ(45, g.getPDistributorId());
}

TEST(gameTest, getPWholesalerIdTest)
{

    Game g;
    g.setPWholesalerId(56);
    EXPECT_EQ(56, g.getPWholesalerId());
}

TEST(gameTest, setPWholesalerIdTest)
{

    Game g;
    g.setPWholesalerId(12);
    EXPECT_EQ(12, g.getPWholesalerId());
}

TEST(gameTest, setPRetailerIdTest)
{

    Game g;
    g.setPRetailerId(24);
    EXPECT_EQ(24, g.getPRetailerId());
}

TEST(gameTest, getPRetailerIdTest)
{

    Game g;
    g.setPRetailerId(24);
    EXPECT_EQ(24, g.getPRetailerId());
}

TEST(gameTest, generatePasswordsTest)
{
    Game g;
    g.setNumberOfPlayers(4);
    std::vector<std::string> result = g.generatePasswords();
    EXPECT_EQ(4, result.size());
}

TEST(gameTest, advanceWeekTest)
{

    Game g;
    int currweek = g.getCurrentWeek();
    EXPECT_EQ(currweek + 1, g.advanceWeek());
}

TEST(gameTest, setWeeksToBePlayedTest)
{

    Game g;
    g.setWeeksToBePlayed(2);
    EXPECT_EQ(2, g.getWeeksToBePlayed());
}

TEST(gameTest, getWeeksToBePlayedTest)
{

    Game g;
    EXPECT_EQ(26, g.getWeeksToBePlayed()); //checking default value
    g.setWeeksToBePlayed(2);
    EXPECT_EQ(2, g.getWeeksToBePlayed());
}

TEST(gameTest, setInfoCodeTest)
{

    Game g;
    g.setInfoCode(3);
    EXPECT_EQ(3, g.getInfoCode());
}

TEST(gameTest, getInfoCodeTest)
{

    Game g;
    g.setInfoCode(3);
    EXPECT_EQ(3, g.getInfoCode());
}

TEST(gameTest, setHoldingCostTest)
{

    Game g;
    g.setHoldingCost(6.3);
    EXPECT_EQ(6.3, g.getHoldingCost());
}

TEST(gameTest, getHoldingCostTest)
{

    Game g;
    EXPECT_EQ(0.5, g.getHoldingCost()); //checking default value
    g.setHoldingCost(9);
    EXPECT_EQ(9, g.getHoldingCost());
}

TEST(gameTest, setStartingInventoryTest)
{

    Game g;
    g.setStartingInventory(4);
    EXPECT_EQ(4, g.getStartingInventory());
}

TEST(gameTest, getStartingInventoryTest)
{

    Game g;
    EXPECT_EQ(12, g.getStartingInventory()); //checking default value
    g.setStartingInventory(14);
    EXPECT_EQ(14, g.getStartingInventory());
}

TEST(gameTest, getBackorderCostTest)
{

    Game g;
    g.setBackorderCost(5.7);
    EXPECT_EQ(5.7, g.getBackorderCost());
}

TEST(gameTest, getCurrentWeekTest)
{

    Game g;
    EXPECT_EQ(0, g.getCurrentWeek()); //checking default value
    g.setCurrentWeek(5);
    EXPECT_EQ(5, g.getCurrentWeek());
}

TEST(gameTest, setCurrentWeekTest)
{

    Game g;
    g.setCurrentWeek(1);
    EXPECT_EQ(1, g.getCurrentWeek());
}

TEST(gameTest, setOrdersToBeExecutedTest)
{
    Order o11, o12, o13, o21, o22, o23, o31, o32, o33;
    std::vector<Order> ordWeek1, ordWeek2, ordWeek3;
    ordWeek1 = {o11, o12, o13};
    ordWeek2 = {o21, o22, o23};
    ordWeek3 = {o31, o32, o33};
    std::map<int, std::vector<Order>> testlist = {{1, ordWeek1}, {2, ordWeek2}, {3, ordWeek3}};
    Game g;
    g.setOrdersToBeExecuted(testlist);
    EXPECT_EQ(3, g.getOrdersToBeExecuted().size());
}

TEST(gameTest, getOrdersToBeExecutedTest)
{
    Order o11, o12, o13, o14, o21, o22, o23, o24, o31, o32, o33, o34, o41, o42, o43, o44;
    std::vector<Order> ordWeek1, ordWeek2, ordWeek3, ordWeek4;
    ordWeek1 = {o11, o12, o13, o14};
    ordWeek2 = {o21, o22, o23, o24};
    ordWeek3 = {o31, o32, o33, o34};
    ordWeek4 = {o41, o42, o43, o44};
    std::map<int, std::vector<Order>> testlist = {{1, ordWeek1}, {2, ordWeek2}, {3, ordWeek3}, {4, ordWeek4}};
    Game g;
    g.setOrdersToBeExecuted(testlist);
    EXPECT_EQ(4, g.getOrdersToBeExecuted().size());
}

TEST(gameTest, setShipmentsToBeExecutedTest)
{
    Shipment o11, o12, o13, o21, o22, o23, o31, o32, o33;
    std::vector<Shipment> shipWeek1, shipWeek2, shipWeek3;
    shipWeek1 = {o11, o12, o13};
    shipWeek2 = {o21, o22, o23};
    shipWeek3 = {o31, o32, o33};
    std::map<int, std::vector<Shipment>> testlist = {{1, shipWeek1}, {2, shipWeek2}, {3, shipWeek3}};
    Game g;
    g.setShipmentsToBeExecuted(testlist);
    EXPECT_EQ(3, g.getShipmentsToBeExecuted().size());
}

TEST(gameTest, getShipmentsToBeExecutedTest)
{
    Shipment o11, o12, o13, o14, o21, o22, o23, o24, o31, o32, o33, o34, o41, o42, o43, o44;
    std::vector<Shipment> shipWeek1, shipWeek2, shipWeek3, shipWeek4;
    shipWeek1 = {o11, o12, o13, o14};
    shipWeek2 = {o21, o22, o23, o24};
    shipWeek3 = {o31, o32, o33, o34};
    shipWeek4 = {o41, o42, o43, o44};
    std::map<int, std::vector<Shipment>> testlist = {{1, shipWeek1}, {2, shipWeek2}, {3, shipWeek3}, {4, shipWeek4}};
    Game g;
    g.setShipmentsToBeExecuted(testlist);
    EXPECT_EQ(4, g.getShipmentsToBeExecuted().size());
}

TEST(gameTest, setPlayerInterfaceTest)
{
}

TEST(gameTest, setPlayersTest)
{
    Game g;
    Player p1, p2, p3, p4;
    p1.setPId(1);
    p2.setPId(2);
    p3.setPId(3);
    p4.setPId(4);
    std::vector<Player *> players_test;
    players_test.push_back(&p1);
    players_test.push_back(&p2);
    players_test.push_back(&p3);
    players_test.push_back(&p4);
    g.setPlayers(players_test);
    EXPECT_EQ(players_test, g.getPlayers());
}

TEST(gameTest, getPlayersTest)
{
    Game g;
    Player p1, p2, p3, p4;
    p1.setPId(1);
    p2.setPId(2);
    p3.setPId(3);
    p4.setPId(4);
    std::vector<Player *> players_test;
    players_test.push_back(&p1);
    players_test.push_back(&p2);
    players_test.push_back(&p3);
    players_test.push_back(&p4);
    g.setPlayers(players_test);
    EXPECT_EQ(players_test, g.getPlayers());
}

TEST(gameTest, setConsumerDemandPerWeekTest)
{
    Game g;
    std::vector<int> cdpw = {4, 4, 4, 4, 4};
    g.setConsumerDemandPerWeek(cdpw);
    std::cout << "ConsumerDemandPerWeek" << std::endl;
    EXPECT_EQ(5, g.getConsumerDemandPerWeek().size());
}

TEST(gameTest, getConsumerDemandPerWeekTest)
{
    Game g;
    std::vector<int> cdpw = {4, 4, 4, 4, 4};
    g.setConsumerDemandPerWeek(cdpw);
    EXPECT_EQ(5, g.getConsumerDemandPerWeek().size());
}

TEST(gameTest, setBackorderCostTest)
{
    Game game;
    game.setBackorderCost(1);
    EXPECT_EQ(game.getBackorderCost(), 1);
}

TEST(gameTest, setFactoryDelayTest)
{
    Game game;
    game.setFactoryDelay(1);
    EXPECT_EQ(game.getFactoryDelay(), 1);
}

TEST(gameTest, getFactoryDelayTest)
{
    Game game;
    game.setFactoryDelay(1);
    EXPECT_EQ(game.getFactoryDelay(), 1);
}

TEST(gameTest, setNumberOfPlayersTest)
{
    Game g;
    g.setNumberOfPlayers(4);
    EXPECT_EQ(4, g.getNumberOfPlayers());
}

TEST(gameTest, getNumberOfPlayersTest)
{
    Game g;
    g.setNumberOfPlayers(4);
    EXPECT_EQ(4, g.getNumberOfPlayers());
}

TEST(gameTest, startGameTest)
{
    // part of functionality test; tests_game_logic.cpp
}

//In executeOrdersForCurrentWeek, the Order objects in the map ordersToBeExecuted are executed (the method
// executeOrder for each object is called)
TEST(gameTest, executeOrdersForCurrentWeekTest)
{
    Game g;
    g.setCurrentWeek(3);
    Order o11, o12, o13, o14, o21, o22, o23, o24, o31, o32, o33, o34, o41, o42, o43, o44;
    std::vector<Order> ordWeek1, ordWeek2, ordWeek3, ordWeek4;
    ordWeek1 = {o11, o12, o13, o14};
    ordWeek2 = {o21, o22, o23, o24};
    ordWeek3 = {o31, o32, o33, o34};
    ordWeek4 = {o41, o42, o43, o44};
    std::map<int, std::vector<Order>> testlist = {{1, ordWeek1}, {2, ordWeek2}, {3, ordWeek3}, {4, ordWeek4}};
    g.setOrdersToBeExecuted(testlist);
    int week = g.getCurrentWeek();
    EXPECT_EQ(4, testlist[week].size());
}

//In executeShipmentsForCurrentWeek, the Shipment objects in the map setShipmentsToBeExecuted are executed (the method
// executeShipment for each object is called)
TEST(gameTest, executeShipmentsForCurrentWeekTest)
{
    Game g;
    g.setCurrentWeek(3);
    Shipment o11, o12, o13, o14, o21, o22, o23, o24, o31, o32, o33, o34, o41, o42, o43, o44;
    std::vector<Shipment> shipWeek1, shipWeek2, shipWeek3, shipWeek4;
    shipWeek1 = {o11, o12, o13, o14};
    shipWeek2 = {o21, o22, o23, o24};
    shipWeek3 = {o31, o32, o33, o34};
    shipWeek4 = {o41, o42, o43, o44};
    std::map<int, std::vector<Shipment>> testlist = {{1, shipWeek1}, {2, shipWeek2}, {3, shipWeek3}, {4, shipWeek4}};
    g.setShipmentsToBeExecuted(testlist);
    int week = g.getCurrentWeek();
    EXPECT_EQ(4, testlist[week].size());
}

TEST(gameTest, updatePlayerInventoriesTest)
{
    // part of functionality test in test/tests_game_logic.cpp
}

TEST(gameTest, getConsumerOrderForWeekTest)
{
    Game g;
    g.startGame();
    EXPECT_EQ(g.getConsumerOrderForWeek(), 6); //defaultvalue
}

// In addOrder, an object of class Order is created and put into the map setOrdersToBeExecuted
TEST(gameTest, addOrderTest)
{
    // Game g;
    // g.setCurrentWeek(2);
    // g.addOrder(2, 23);
    // std::map<int, std::vector<Order>> oe = g.getOrdersToBeExecuted();
    // std::vector<Order> o = oe[2];
    // EXPECT_EQ(1, o.size());
}

// In addShipment, an object of class Shipment is created and put into the map setShipmentsToBeExecuted
TEST(gameTest, addShipmentTest)
{
    // part of functionality test; tests_game_logic.cpp
}

TEST(gameTest, addPlayerTest)
{
    Game g;
    Player p1, p2, p3, p4;
    p1.setPId(1);
    p2.setPId(2);
    p3.setPId(3);
    p4.setPId(4);
    std::vector<Player *> players_test1;
    players_test1.push_back(&p1);
    players_test1.push_back(&p2);
    g.addPlayer(&p3);
    g.addPlayer(&p4);
    g.setPlayers(players_test1);
    EXPECT_EQ(players_test1, g.getPlayers());
}

TEST(gameTest, getDownstreamTest)
{
}

TEST(gameTest, getUpstreamTest)
{
}

/** Tests for class Instructor **/

TEST(instructorTest, setInstrEmailTest)
{

    Instructor i;
    i.setInstrEmail("hi.there@jacobs-university.de");
    EXPECT_EQ("hi.there@jacobs-university.de", i.getInstrEmail());
}

TEST(instructorTest, getInstrEmailTest)
{

    Instructor i;
    i.setInstrEmail("hi.again@jacobs-university.de");
    std::string email = "hi.again@jacobs-university.de";
    EXPECT_EQ(email, i.getInstrEmail());
}

TEST(instructorTest, setInstrPasswordTest)
{

    Instructor i;
    i.setInstrPassword("superstrongpassword");
    EXPECT_EQ("superstrongpassword", i.getInstrPassword());
}

TEST(instructorTest, getInstrPasswordTest)
{

    Instructor i;
    i.setInstrPassword("weakpassword");
    EXPECT_EQ("weakpassword", i.getInstrPassword());
}

TEST(instructorTest, setInstrIdTest)
{

    Instructor i;
    i.setInstrId(2020);
    EXPECT_EQ(2020, i.getInstrId());
}

TEST(instructorTest, getInstrIdTest)
{

    Instructor i;
    i.setInstrId(30);
    EXPECT_EQ(30, i.getInstrId());
}

TEST(instructorTest, setGamesTest)
{
    Instructor i;
    std::vector<Game> games;
    Game g1, g2, g3;
    games.push_back(g1);
    games.push_back(g2);
    games.push_back(g3);
    i.setGames(games);
    EXPECT_EQ(3, games.size());
}

TEST(instructorTest, getGamesTest)
{
    Instructor i;
    std::vector<Game> games;
    Game g1, g2, g3;
    games.push_back(g1);
    games.push_back(g2);
    games.push_back(g3);
    i.setGames(games);
    EXPECT_EQ(3, i.getGames().size());
}

TEST(instructorTest, showGamesStatusTest)
{
    Instructor i;
    Game g1, g2;
    g1.setCurrentWeek(5);
    g2.setCurrentWeek(5);
    g1.setWeeksToBePlayed(10);
    g2.setWeeksToBePlayed(10);
    std::vector<Game> g = {g1, g2};
    i.setGames(g);
    EXPECT_DEATH(i.showGamesStatus(), "Inactive");
}

TEST(instructorTest, createGameTest)
{
    Instructor i;
    std::vector<Game> games;
    Game g1, g2, g3;
    games.push_back(g1);
    games.push_back(g2);
    games.push_back(g3);
    i.setGames(games);
    Game g = i.createGame();
    EXPECT_EQ(4, g.getGId());
}

TEST(instructorTest, createGamesTest)
{
}

/** Tests for class PlayerEvent **/

TEST(playerEventTest, getEventIdTest)
{
    PlayerEvent ev;
    ev.setEventId(1);
    EXPECT_EQ(ev.getEventId(), 1);
}

TEST(playerEventTest, setEventIdTest)
{
    PlayerEvent ev;
    ev.setEventId(1);
    EXPECT_EQ(ev.getEventId(), 1);
}

TEST(playerEventTest, getGIdTest)
{
    PlayerEvent ev;
    ev.setGId(1);
    EXPECT_EQ(ev.getGId(), 1);
}

TEST(playerEventTest, setGIdTest)
{
    PlayerEvent ev;
    ev.setGId(1);
    EXPECT_EQ(ev.getGId(), 1);
}

TEST(playerEventTest, setNumberOfBeersTest)
{
    PlayerEvent ev;
    ev.setNumberOfBeers(1);
    EXPECT_EQ(ev.getNumberOfBeers(), 1);
}

TEST(playerEventTest, getNumberOfBeersTest)
{
    PlayerEvent ev;
    ev.setNumberOfBeers(1);
    EXPECT_EQ(ev.getNumberOfBeers(), 1);
}

TEST(playerEventTest, getOrderedInWeekTest)
{
    PlayerEvent ev;
    ev.setOrderedInWeek(1);
    EXPECT_EQ(ev.getOrderedInWeek(), 1);
}

TEST(playerEventTest, setOrderedInWeekTest)
{
    PlayerEvent ev;
    ev.setOrderedInWeek(1);
    EXPECT_EQ(ev.getOrderedInWeek(), 1);
}

TEST(playerEventTest, getShippedInWeekTest)
{
    PlayerEvent ev;
    ev.setShippedInWeek(1);
    EXPECT_EQ(ev.getShippedInWeek(), 1);
}

TEST(playerEventTest, setShippedInWeekTest)
{
    PlayerEvent ev;
    ev.setShippedInWeek(1);
    EXPECT_EQ(ev.getShippedInWeek(), 1);
}

TEST(playerEventTest, getReceiverTest)
{
    char appName[] = {'t', 'e', 's', 't'};
    char *testArgV[] = {appName};
    int testArgC = 1;

    QApplication *app = new QApplication(testArgC, testArgV);
    PlayerInterface *pi = new PlayerInterface();

    PlayerEvent ev;
    ev.setReceiver(pi);
    EXPECT_EQ(ev.getReceiver(), pi);

    delete pi;
    delete app;
}

TEST(playerEventTest, setReceiverTest)
{
    char appName[] = {'t', 'e', 's', 't'};
    char *testArgV[] = {appName};
    int testArgC = 1;

    QApplication *app = new QApplication(testArgC, testArgV);
    PlayerInterface *pi = new PlayerInterface();

    PlayerEvent ev;
    ev.setReceiver(pi);
    EXPECT_EQ(ev.getReceiver(), pi);

    delete pi;
    delete app;
}

TEST(playerEventTest, getToPlayerIdTest)
{
    PlayerEvent ev;
    ev.setToPlayerId(1);
    EXPECT_EQ(ev.getToPlayerId(), 1);
}

TEST(playerEventTest, setToPlayerIdTest)
{
    PlayerEvent ev;
    ev.setToPlayerId(1);
    EXPECT_EQ(ev.getToPlayerId(), 1);
}

TEST(playerEventTest, getFromPlayerIdTest)
{
    PlayerEvent ev;
    ev.setFromPlayerId(1);
    EXPECT_EQ(ev.getFromPlayerId(), 1);
}

TEST(playerEventTest, setFromPlayerIdTest)
{
    PlayerEvent ev;
    ev.setFromPlayerId(1);
    EXPECT_EQ(ev.getFromPlayerId(), 1);
}

/** Tests for class Shipment **/

TEST(shipmentTest, executeShipmentTest)
{
    // Shipment sp;
    // PlayerInterface p;
    // sp.setNumberOfBeers(20);
    // sp.setReceiver(&p);
    // sp.executeShipment();
    // EXPECT_EQ(20, p.getIncomingShipment());
}

/** Tests for class Order **/

TEST(orderTest, executeOrderTest)
{
    // Order od;
    // PlayerInterface p;
    // std::cout << "executeOrder" << std::endl;
    // Player ps;
    // ps.setPId(12);
    // p.setPlayer(&ps);
    // od.setNumberOfBeers(20);
    // od.setReceiver(&p);

    // od.executeOrder();
    // EXPECT_EQ(12, ps.getPId());
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
