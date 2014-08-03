//
//  MarkovNode.h
//  AbstractMarkovChain
//
//  Created by Anthony Bashi on 2014-06-24.
//  Copyright (c) 2014 Anthony Bashi. All rights reserved.
//

//This MarkovNode is made for the specific case of a wordwise chain

#ifndef __AbstractMarkovChain__MarkovNode__
#define __AbstractMarkovChain__MarkovNode__

#include <iostream>
#include <map>
#include <stdlib.h>
#include <string>
#include <vector>

#endif /* defined(__AbstractMarkovChain__MarkovNode__) */

using namespace std;

struct FreqNode;
class MarkovNode {

public:
    MarkovNode();
    MarkovNode(string);
    
//    ~MarkovNode();
    
    void markOneUp(MarkovNode* node);
    string getContent();
    MarkovNode* getNextRandom();
    map<string, FreqNode> getNexts();
    bool getLast();
    void setLast(bool);
private:
    map<string,FreqNode> nexts;
    string content;
    bool last;
};

struct FreqNode {
    int weight = 0;
    MarkovNode* node;
};