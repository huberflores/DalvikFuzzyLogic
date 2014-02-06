#include "CentroidMethod.h"

namespace deffuzifyer {
    using variables::FuzzySet;
    using variables::LinguisticVariable;

    CentroidMethod::CentroidMethod() {
        InitializeInstanceFields();
        setList.clear();
        min = 0;
        max = 0;
        s = 10;
    }

    double CentroidMethod::getDefuzziedValue(LinguisticVariable *lv) {
        setList = lv->getSetList();
        max = lv->getMax();
        min = lv->getMin();
        double jump = (max - min) / s;
        double sumAreas = 0;
        double sumCont = 0;

        double areas[s];
        double values[s];
        for(int i = 0; i < s; i++){
            values[i] = 0;
            areas[i] = 0;
        }
        double flag = min + jump;
        for (int i = 0; i < s; i++) {
            for (std::vector<FuzzySet*>::const_iterator fs = setList.begin(); fs != setList.end(); ++fs) {
                areas[i] += ((*fs)->getClippedValue(flag));
            }
            values[i] += flag;
            flag += jump;
        }
        for (int i = 0; i < (sizeof(areas) / sizeof(*areas)); i++) {
            sumAreas += areas[i];
        }
        for (int i = 0; i < s; i++) {
            sumCont += (values[i] * areas[i]);
        }
        return sumCont / sumAreas;
    }

    void CentroidMethod::setSamplesPoints(int s) {
        this->s = s;
    }

    void CentroidMethod::InitializeInstanceFields() {
        min = 0;
        max = 0;
        s = 0;
    }
}
