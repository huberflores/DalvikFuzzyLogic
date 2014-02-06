#pragma once

#include "modifier/FzSet.h"
#include "controller/BasicFuzzyController.h"
#include <string>


using namespace modifier;

using controller::BasicFuzzyController;
using controller::FuzzyOp;
using deffuzifyer::CentroidMethod;
using variables::LinguisticVariable;

class FuzzyLogicEngine {

    private:
        FzSet *speedSlow;
        FzSet *speedNormal;
        FzSet *speedFast;

        //CPU Load
        FzSet *loadLow;
        FzSet *loadNormal;
        FzSet *loadHigh;

        /// Cloud

        //Instance server
        FzSet *connectionsLow;
        FzSet *connectionsNormal;
        FzSet *connectionsHigh;

        //Offload Decision
        FzSet *remoteProcessing;
        FzSet *localProcessing;


    public:
        virtual void createVariables(BasicFuzzyController *bfc);
        virtual void createRules(BasicFuzzyController *bfc);
        virtual bool testFuzzy(int bandwidth, int cpu, int connections);
};
