#include "FuzzyLogicEngine.h"
#include "deffuzifyer/CentroidMethod.h"
#include "variables/LinguisticVariable.h"
#include "functions/TrapezoidalMembershipFunction.h"
#include "controller/FuzzyOp.h"
#include <exception>

using namespace controller;
using namespace variables;
using namespace std;

using controller::BasicFuzzyController;
using controller::FuzzyOp;
using deffuzifyer::CentroidMethod;
using functions::TrapezoidalMembershipFunction;
using modifier::FzSet;
using variables::LinguisticVariable;
using std::cout;

double positiveInfini = std::numeric_limits<double>::infinity();

int main(int argc, char **argv) {
    FuzzyLogicEngine *fle = new FuzzyLogicEngine();
    fle->testFuzzy(10,10,10);
}


void dump_map(const std::map<std::wstring, double>& map) {
  for ( std::map<std::wstring, double>::const_iterator it = map.begin(); it != map.end(); it++) {
    wcout << "Key: " << it->first << endl;
    cout.precision(15);
    cout << "Value: " << it->second <<endl;
  }
}

bool FuzzyLogicEngine::testFuzzy(int bandwidth, int cpu, int connections){
    BasicFuzzyController *bfc = new BasicFuzzyController();
    FuzzyLogicEngine *fle = new FuzzyLogicEngine();

    fle->createVariables(bfc);
    fle->createRules(bfc);

    //Here input to value is introduced
    bfc->fuzzify(L"BANDWIDTH", double(bandwidth));
    bfc->fuzzify(L"CPULOAD", double(cpu));
    bfc->fuzzify(L"CONNECTIONS", double(connections));

    CentroidMethod *cm = new CentroidMethod();
    cm->setSamplesPoints(10);
    bfc->setDefuzzifyerMethod(cm);

    //cout << L"Delegate with a grade of truth to2: ";
    dump_map(bfc->defuzzify(L"OFFLOAD"));
    return true;

}

void FuzzyLogicEngine::createVariables(BasicFuzzyController *bfc) {

    try {
        LinguisticVariable *mv1 = new LinguisticVariable(L"BANDWIDTH");
        speedSlow = mv1->addSet(L"Slow", new TrapezoidalMembershipFunction(double(0), double(5), double(11), double(16)));
        speedNormal = mv1->addSet(L"Normal", new TrapezoidalMembershipFunction(double(11), double(38), double(54), double(92)));
        speedFast = mv1->addSet(L"Fast", new TrapezoidalMembershipFunction(double(54), double(110), double(160), positiveInfini)); //trapezoidal case - right
        bfc->addVariable(mv1);

        LinguisticVariable *mv2 = new LinguisticVariable(L"CPULOAD");
        loadLow = mv2->addSet(L"CPU Low", new TrapezoidalMembershipFunction(double(0), double(9), double(18), double(36)));
        loadNormal = mv2->addSet(L"CPU Normal", new TrapezoidalMembershipFunction(double(27), double(45), double(54), double(72)));
        loadHigh = mv2->addSet(L"CPU High", new TrapezoidalMembershipFunction(double(63), double(81), double(90), positiveInfini));
        bfc->addVariable(mv2);

        LinguisticVariable *cv1 = new LinguisticVariable(L"CONNECTIONS");
        connectionsLow = cv1->addSet(L"Low concurrent users", new TrapezoidalMembershipFunction(double(0), double(12), double(24), double(48)));
        connectionsNormal = cv1->addSet(L"Normal concurrent users", new TrapezoidalMembershipFunction(double(36), double(60), double(72), double(96)));
        connectionsHigh = cv1->addSet(L"High concurrent users", new TrapezoidalMembershipFunction(double(84), double(108), double(120), double(132)));
        bfc->addVariable(cv1);

        LinguisticVariable *decision = new LinguisticVariable(L"OFFLOAD");
        localProcessing = decision->addSet(L"Local processing", new TrapezoidalMembershipFunction(double(0), double(12), double(24), double(48)));
        remoteProcessing = decision->addSet(L"Remote processing", new TrapezoidalMembershipFunction(double(36), double(60), double(72), double(84)));
        bfc->addVariable(decision);

    } catch (exception & e) {
        cout << "IllegalSetException"<< e.what();
    }
}

void FuzzyLogicEngine::createRules(BasicFuzzyController *bfc) {
    bfc->addRule(FuzzyOp::fuzzyAnd(speedSlow, loadLow), localProcessing);
    bfc->addRule(FuzzyOp::fuzzyAnd(speedSlow, loadNormal), localProcessing);
    bfc->addRule(FuzzyOp::fuzzyAnd(speedSlow, loadHigh), localProcessing);
    bfc->addRule(FuzzyOp::fuzzyAnd(speedNormal, loadLow), remoteProcessing);
    bfc->addRule(FuzzyOp::fuzzyAnd(speedNormal, loadNormal), remoteProcessing);
    bfc->addRule(FuzzyOp::fuzzyAnd(speedNormal, loadHigh), remoteProcessing);
    bfc->addRule(FuzzyOp::fuzzyAnd(speedFast, loadLow), remoteProcessing);
    bfc->addRule(FuzzyOp::fuzzyAnd(speedFast, loadNormal), remoteProcessing);
    bfc->addRule(FuzzyOp::fuzzyAnd(speedFast, loadHigh), remoteProcessing);
    bfc->addRule(FuzzyOp::fuzzyAnd(speedFast, loadLow), remoteProcessing);

    bfc->addRule(FuzzyOp::fuzzyAnd(speedSlow, connectionsLow), localProcessing);
    bfc->addRule(FuzzyOp::fuzzyAnd(speedNormal, connectionsNormal), remoteProcessing);
    bfc->addRule(FuzzyOp::fuzzyAnd(speedNormal, connectionsHigh), localProcessing);
    bfc->addRule(FuzzyOp::fuzzyAnd(speedFast, connectionsNormal), remoteProcessing);
    bfc->addRule(FuzzyOp::fuzzyAnd(speedFast, connectionsHigh), localProcessing);

}
