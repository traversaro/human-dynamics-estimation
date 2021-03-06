//
//  main.cpp
//  HumanForcesProvider
//
//  Created by Claudia Latella on 14/02/17.
//  Copyright © 2017 Claudia Latella. All rights reserved.
//

#include <yarp/os/LogStream.h>
#include <yarp/os/Network.h>
#include "HumanForcesProvider.h"


int main(int argc, char * argv[])
{
    // YARP setting
    yarp::os::Network yarp;
    if (!yarp::os::Network::checkNetwork(5.0))
    {
        yError() << " YARP server not available!";
        return EXIT_FAILURE;
    }

    // Configure ResourceFinder
    yarp::os::ResourceFinder &rf = yarp::os::ResourceFinder::getResourceFinderSingleton();
    rf.setVerbose(true);
    rf.setDefaultContext("HumanForcesProvider"); //when no parameters are given to the module this is the default context
    rf.setDefaultConfigFile("HumanForcesProvider.ini"); //default config file.ini
    rf.configure(argc, argv);
    
    // Configure the module
    HumanForcesProvider module;
    return module.runModule(rf);
}
