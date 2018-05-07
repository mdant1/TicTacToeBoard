/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PracticeTest, sanityCheck)
{
	TicTacToeBoard obj;
	ASSERT_TRUE( true );
}

TEST(TicTacToeBoardTest, PieceNotonBoard)
{
	TicTacToeBoard obj;
	ASSERT_EQ(obj.placePiece(8,9), Invalid);
}

TEST(TicTacToeBoardTest, XTurn)
{
	TicTacToeBoard obj;
	obj.placePiece(0,2);
	ASSERT_EQ(obj.toggleTurn(), X);
}

TEST(TicTacToeBoardTest, OTurn)
{
	TicTacToeBoard obj;
	ASSERT_EQ(obj.toggleTurn(), O);
}

TEST(TicTacToeBoardTest, EmptySpace)
{
	TicTacToeBoard obj;
	ASSERT_EQ(obj.getPiece(0, 0), Blank);
}

TEST(TicTacToeBoardTest, GameNotFinished)
{
	TicTacToeBoard obj;
	ASSERT_EQ(obj.getWinner(), Invalid);
}

TEST(TicTacToeBoardTest, WinnerXDiagonal1)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	obj.placePiece(1,2);
	obj.placePiece(1,1);
	obj.placePiece(0,2);
	obj.placePiece(2,2);
	ASSERT_EQ(obj.getWinner(), X);
}

TEST(TicTacToeBoardTest, WinnerXDiagonal2)
{
	TicTacToeBoard obj;
	obj.placePiece(1,1);
	obj.placePiece(0,0);
	obj.placePiece(0,2);
	obj.placePiece(0,1);
	obj.placePiece(2,0);
	ASSERT_EQ(obj.getWinner(), X);
}

TEST(TicTacToeBoardTest, WinnerXRow)
{
	TicTacToeBoard obj;
	obj.placePiece(1,1);
	obj.placePiece(0,1);
	obj.placePiece(1,0);
	obj.placePiece(0,0);
	obj.placePiece(1,2);
	ASSERT_EQ(obj.getWinner(), X);
}

TEST(TicTacToeBoardTest, WinnerXColumn)
{
	TicTacToeBoard obj;
	obj.placePiece(1,1);
	obj.placePiece(0,0);
	obj.placePiece(0,1);
	obj.placePiece(2,2);
	obj.placePiece(2,1);
	ASSERT_EQ(obj.getWinner(), X);
}

TEST(TicTacToeBoardTest, WinnerODiagonal1)
{
	TicTacToeBoard obj;
	obj.placePiece(0,1);
	obj.placePiece(0,0);
	obj.placePiece(1,2);
	obj.placePiece(1,1);
	obj.placePiece(2,0);
	obj.placePiece(2,2);
	ASSERT_EQ(obj.getWinner(), O);
}

TEST(TicTacToeBoardTest, WinnerODiagonal2)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	obj.placePiece(1,2);
	obj.placePiece(1,1);
	obj.placePiece(0,2);
	obj.placePiece(2,0);
	obj.placePiece(2,2);
	ASSERT_EQ(obj.getWinner(), O);
}

TEST(TicTacToeBoardTest, WinnerORow)
{
	TicTacToeBoard obj;
	obj.placePiece(1,1);
	obj.placePiece(0,0);
	obj.placePiece(2,2);
	obj.placePiece(0,1);
	obj.placePiece(2,0);
	obj.placePiece(0,2);
	ASSERT_EQ(obj.getWinner(), O);
}

TEST(TicTacToeBoardTest, WinnerOColumn)
{
	TicTacToeBoard obj;
	obj.placePiece(1,1);
	obj.placePiece(0,0);
	obj.placePiece(0,2);
	obj.placePiece(1,0);
	obj.placePiece(2,1);
	obj.placePiece(2,0);
	ASSERT_EQ(obj.getWinner(), O);
}

TEST(TicTacToeBoardTest, NoWinner)
{
	TicTacToeBoard obj;
	obj.placePiece(1,1);
	obj.placePiece(0,0);
	obj.placePiece(1,0);
	obj.placePiece(0,2);
	obj.placePiece(2,2);
	obj.placePiece(2,1);
	obj.placePiece(2,0);
	obj.placePiece(1,2);
	obj.placePiece(0,1);
	ASSERT_EQ(obj.getWinner(), Blank);
}

TEST(TicTacToeBoardTest, PlaceX)
{
	TicTacToeBoard obj;
	ASSERT_EQ(obj.placePiece(0,1), X);
}

TEST(TicTacToeBoardTest, PlaceO)
{
	TicTacToeBoard obj;
	obj.placePiece(0,1);
	ASSERT_EQ(obj.placePiece(0,0), O);
}

TEST(TicTacToeBoardTest, PieceAlreadyPlaced)
{
	TicTacToeBoard obj;
	obj.placePiece(0,1);
	ASSERT_EQ(obj.placePiece(0,1), X);
}