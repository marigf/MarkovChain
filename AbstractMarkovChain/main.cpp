//
//  main.cpp
//  AbstractMarkovChain
//
//  Created by Anthony Bashi on 2014-06-24.
//  Copyright (c) 2014 Anthony Bashi. All rights reserved.
//

#include <iostream>
#include "MarkovEngine.h"
#include <ctime>

int main(int argc, const char * argv[])
{
    srand((int)time(NULL));
    MarkovEngine* engine = new MarkovEngine();
    string input;
    getline(cin,input);
    
    engine->analyse(input);
    
    cout << "Analysed!- stored " << engine->getnumNodes() << " nodes \n";
    
    string bleh = engine->generatenewString();
    cout << bleh;
    return 0;
}

