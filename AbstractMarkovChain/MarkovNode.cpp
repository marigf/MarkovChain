//
//  MarkovNode.cpp
//  AbstractMarkovChain
//
//  Created by Anthony Bashi on 2014-06-24.
//  Copyright (c) 2014 Anthony Bashi. All rights reserved.
//

#include "MarkovNode.h"

MarkovNode::MarkovNode(){
    nexts = *new map<string,FreqNode>;
    content = *new string;
    last = false;
}

MarkovNode::MarkovNode(string initcontent)
{
    nexts = *new map<string,FreqNode>;
    content = initcontent;
    last = false;
}

//MarkovNode::~MarkovNode()
//{
//    delete &nexts;
//    delete &content;
//}

std::string MarkovNode::getContent()
{
    return content;
}

bool MarkovNode::getLast()
{
    return last;
}

void MarkovNode::markOneUp(MarkovNode* node)
{
    if(nexts.count(node->content)==0)
    {
        FreqNode newnode = *new FreqNode;
        newnode.node = node;
        newnode.weight = 1;
        nexts[node->content] = newnode;
    }
    else
    {
        nexts[node->content].weight++;
    }
}

MarkovNode* MarkovNode::getNextRandom()
{
    if(last)
    {
        return this;
    }
    int rnd = 0;
    int weightsum = 0;
    
    vector<string> randvect = *new vector<string>;
    map<string,FreqNode>::iterator iter;
    iter = nexts.begin();
    
    while(iter!=nexts.end()) //while iterator over nexts is good,
    {
        for(int i = 0;i<iter->second.weight;i++)
        {
            randvect.insert(randvect.begin(),iter->first);
        }
        weightsum += iter->second.weight; //Add to the sum of weights
        iter++;
    }
    
    rnd = rand()% weightsum;
    MarkovNode* bleh = nexts.at(randvect.at(rnd)).node;
    
    delete &randvect;
    
    return bleh;
    
}

map<string,FreqNode> MarkovNode::getNexts()
{
    return nexts;
}

void MarkovNode::setLast(bool truth)
{
    this->last = truth;
}