#include "karthy_Analyser.h"

using namespace karthy;

uint64_t karthy::GomokuSimpleAnalyzer::getNumWin(bool nameAgent)
{
	if (nameAgent == true)
	{
		return this->numWinAIAgent;
	}
	if (nameAgent == false)
	{
		return this->numWinAgent2;
	}
}