//
//  MarkovEngine.h
//  AbstractMarkovChain
//
//  Created by Anthony Bashi on 2014-06-24.
//  Copyright (c) 2014 Anthony Bashi. All rights reserved.
//

#ifndef __AbstractMarkovChain__MarkovEngine__
#define __AbstractMarkovChain__MarkovEngine__

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include "MarkovNode.h"

#endif /* defined(__AbstractMarkovChain__MarkovEngine__) */

using namespace std;

class MarkovEngine {
    

public:
    MarkovEngine();
    ~MarkovEngine();
    
    int analyse(string input); //For each word...
    string generatenewString();
    int getnumNodes();
private:
    map<string,MarkovNode> nodes;
    
};