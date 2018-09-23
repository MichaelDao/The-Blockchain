//
// Created by salad on 9/23/18.
//

#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H

#include <cstdint>
#include <iostream>
#include <sstream>

using namespace std;

class Block
{
public:
    string prevHash;

    // constructor takes paremeters index and data
    Block(uint32_t indexIn, const string &dataIn);

    // method signature specified
    string GetHash();

    // take in paremeter difficulty
    void MineBlock(uint32_t nDifficulty);

private:
    // all my private declarations
    uint32_t index;
    int64_t nonce;
    string data;
    string hash;
    time_t currentTime;

    // ensure hash cant be changed
    string CalculateHash() const;
};
#endif //BLOCKCHAIN_BLOCK_H