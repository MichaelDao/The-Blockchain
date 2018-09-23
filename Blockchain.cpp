//
// Created by salad on 9/23/18.
//

#include "Blockchain.h"

Blockchain::Blockchain() {
    // blocks gotta start somewhere
    _vChain.emplace_back(Block(0, "Genesis Block"));

    // making this easy by changing its numbers
    _nDifficulty = 5;
}

void Blockchain::AddBlock(Block bNew)
{
    // look at previous blocks hash
    bNew.sPreviousHash = _GetLastBlock().GetHash();

    // mine a block based on difficulty
    bNew.MineBlock(_nDifficulty);

    // complete procees of adding block to blockchain
    _vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const
{
    return _vChain.back();
}