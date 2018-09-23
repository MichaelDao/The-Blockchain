//
// Created by salad on 9/23/18.
//

#ifndef BLOCKCHAIN_BLOCKCHAIN_H
#define BLOCKCHAIN_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Block.h"

class Blockchain
{
public:
    Blockchain();

    // take in parameter bNew which is an object of Block class.
    void AddBlock(Block bNew);

private:
    uint32_t difficulty;
    vector<Block> vectorChain;

    // method signature
    Block GetLastBlock() const;
};

#endif //BLOCKCHAIN_BLOCKCHAIN_H
