#include "GameButtonGrid.h"



#include <QGridLayout>



GameButtonGrid::GameButtonGrid(QWidget *parent) :
	QWidget(parent)
{
	setStyleSheet("background-color: #bbada0");

	QGridLayout *layout = new QGridLayout();
	layout->setSpacing(12);
	setLayout(layout);

	for (Board::index_t r = 0, i = 0; r < Board::NumRows; r++)
	{
		for (Board::index_t c = 0; c < Board::NumCols; c++)
		{
			buttons[i] = new GameButton();
			buttons[i]->setSizePolicy(QSizePolicy::Expanding,
				QSizePolicy::Expanding);
			layout->addWidget(buttons[i], r, c);
			i++;
		}
	}

	NewGame();
}



void GameButtonGrid::NewGame()
{
	totalScore = 0;
	board.Clear();
	board.AddRandom();
	board.AddRandom();
	DisplayBoard();
}



void GameButtonGrid::ApplyMove(Board::Move move)
{
	Board::score_t score = board.Apply(move);
	if (score >= 0)
	{
		totalScore += score;
		board.AddRandom();
		DisplayBoard();
	}
}



Board::score_t GameButtonGrid::GetTotalScore() const
{
	return totalScore;
}



void GameButtonGrid::DisplayBoard()
{
	for (Board::index_t i = 0; i < Board::NumFields; i++)
		buttons[Board::NumFields - i - 1]->Set(board.GetField(i));
}
