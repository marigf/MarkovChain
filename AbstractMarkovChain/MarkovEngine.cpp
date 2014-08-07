//
//  MarkovEngine.cpp
//  AbstractMarkovChain
//
//  Created by Anthony Bashi on 2014-06-24.
//  Copyright (c) 2014 Anthony Bashi. All rights reserved.
//

#include "MarkovEngine.h"

MarkovEngine::MarkovEngine()
{
    nodes = *new map<string,MarkovNode>;
    MarkovNode first = *new MarkovNode(*new string(""));
    nodes[""] = first;
}
MarkovEngine::~MarkovEngine()
{
    delete &nodes;
}

int MarkovEngine::analyse(string input)
{
    
    istringstream buf(input);
    istream_iterator<string> beg(buf), end;
    vector<string> tokens(beg, end);
    
    string prevword = "";
    
    for(auto& curword: tokens)
    {
        if (nodes.count(curword)==0)
        {

            
            MarkovNode newnode = *new MarkovNode(curword);
            if (curword.find(".")!=string::npos)
            {
                newnode.setLast(true);
            }
            else
            {
                newnode.setLast(false);
            }
            
            nodes[curword] = newnode;
        }
        
        if (prevword.find(".")!=string::npos)
        {
            nodes[""].markOneUp(&nodes[curword]);
        }
        
        nodes[prevword].markOneUp(&nodes[curword]);
        prevword = curword;
    }
    return 1;
}

string MarkovEngine::generatenewString()
{
    string toret = "";
    
    MarkovNode current = nodes[""];
    while(!current.getLast())
    {
        current = *current.getNextRandom();
        string toappend = current.getContent();
        toret.append(toappend + " ");
    }
    return toret;
}

int MarkovEngine::getnumNodes()
{
    return nodes.size();
}