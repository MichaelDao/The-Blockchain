//
// Created by salad on 9/23/18.
//

#include "Block.h"
#include "sha256.h"

Block::Block(uint32_t indexIn, const string &dataIn) :
        index(indexIn), data(dataIn)
{
    nonce = -1;
    //set to current time
    currentTime = time(nullptr);
}

string Block::GetHash()
{
    return hash;
}

// lets make this rewarding for miners
void Block::MineBlock(uint32_t nDifficulty)
{
    // create array of characters with length greater than nDifficulty
    char cArray[nDifficulty + 1];

    // fill array with 0's
    for (uint32_t i = 0; i < nDifficulty; i++)
    {
        cArray[i] = '0';
    }

    // attach on a terminator at the end of the array
    cArray[nDifficulty] = '\0';
    string str(cArray);

    // keep looping until a match is found when the hash is calculated
    do
    {
        nonce++;
        hash = CalculateHash();
    } while (hash.substr(0, nDifficulty) != str);

    // send message to output buffer that block has been mined
    cout << "Block mined: " << hash << endl;
}

inline string Block::CalculateHash() const
{
    stringstream sStream;
    sStream << index << prevHash << currentTime << data << nonce;
    return sha256(sStream.str());
}