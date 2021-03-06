#include "karthy_GomokuUniformRandomAgent.h"

karthy::GomokuUniformRandomAgent::GomokuUniformRandomAgent(GomokuPVE* gomokuGame)
{
	this->myPhysicalGame = gomokuGame;
	this->emptyBoxCount = 0;
}


karthy::GomokuUniformRandomAgent::~GomokuUniformRandomAgent()
{
}

karthy::Move karthy::GomokuUniformRandomAgent::takeTurn(void)
{
	Move result = NULL_MOVE;

	std::random_device randomDevice;  //Will be used to obtain a seed for the random number engine
	std::mt19937 generator(randomDevice()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> distributor(0, this->emptyBoxCount - 1);

	int selectedBoxOrder = distributor(generator);
	int emptyBoxOrder = 0;

	GomokuBoard& board = this->myPhysicalGame->board;

	for (uint8_t boxIndexX = 0; boxIndexX < board.colCount && result == NULL_MOVE; boxIndexX++)
	{
		for (uint8_t boxIndexY = 0; boxIndexY < board.rowCount && result == NULL_MOVE; boxIndexY++)
		{
			Index boxIndex = Index(boxIndexX, boxIndexY);
			if (board.getBoxStatus(boxIndex) == BoxStatus::HAVE_NO_STONE)
			{
				if (selectedBoxOrder == emptyBoxOrder)
				{
					result = (Move)boxIndex;
				}
				emptyBoxOrder++;
			}
		}
	}

	this->emptyBoxCount -= 2;
	return result;
}

void karthy::GomokuUniformRandomAgent::getReady(Player myPlayer)
{
	this->myPlayer = myPlayer;
	this->emptyBoxCount = this->myPhysicalGame->board.colCount*this->myPhysicalGame->board.rowCount - (uint16_t)myPlayer;
}
