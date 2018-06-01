#include <iostream>
#include <vector>

#include "block.h"

using namespace std;

int main(){

	cout << "Starting...\n";


	unsigned difficulty = 5;
	vector<Block> blockChain;


	Block *tempBlock = new Block("Genesis", "0");
	blockChain.push_back(*tempBlock);
	cout << "Attempting to mine block...\n";
	blockChain.at(0).mineBlock(difficulty);

	unsigned count = 0;

	while(1){

		Block *nextBlock = new Block(to_string(count), blockChain.at(count).hash);
		blockChain.push_back(*nextBlock);
		cout << "\n\nAttempting to mine block...\n";

		blockChain.at(count+1).mineBlock(difficulty);
		
		cout << "\n\tHash:          " << blockChain.at(count).hash << "\n\tPrevious Hash: " << blockChain.at(count).previousHash
		<< "\n\tNonce:         " << blockChain.at(count).nonce << "\n\tTimeStamp:     " << blockChain.at(count).timeStamp << "\n\tData:          "
		 << blockChain.at(count).data;

		count++;

	}

	return 0;
}