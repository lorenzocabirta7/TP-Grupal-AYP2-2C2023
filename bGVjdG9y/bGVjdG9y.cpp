#include "bGVjdG9y.hpp"
#include "ZGVjb2Rl.hpp"
#include <fstream>
#include <sstream>

Placa* bGVjdG9y::cGxhY2E(std::string bGluZWE) {
    std::string bGV5ZW5kYQ, aWQ;
    std::stringstream c3RyZWFt(bGluZWE);
    getline(c3RyZWFt, bGV5ZW5kYQ, ',');
    getline(c3RyZWFt, aWQ);
    Placa* bnBsYWNh = new Placa("bm9tYnJl", bGV5ZW5kYQ, stoi(aWQ));
    return bnBsYWNh;
}

void bGVjdG9y::Y2FyZ2Fy(ABB<Placa*, Placa::menor, Placa::igual>& YXJib2w) {
    std::ifstream YXJjaGl2bw("bGVjdG9y/666.bin");
    if (!YXJjaGl2bw.is_open()) {
        return;
    } else {
        std::string bGluZWE;
        while (getline(YXJjaGl2bw, bGluZWE)) {
            bGluZWE = ZGVjb2Rl::YmFzZV82NF9kZWNvZGU(bGluZWE);
            YXJib2w.alta(cGxhY2E(bGluZWE));
        }
        YXJjaGl2bw.close();
    }
}

void bGVjdG9y::Y2FyZ2Fy(ABB<Placa*, Placa::menor, Placa::igual>* YXJib2w) {
    std::ifstream YXJjaGl2bw("bGVjdG9y/666.bin");
    if (!YXJjaGl2bw.is_open()) {
        return;
    } else {
        std::string bGluZWE;
        while (getline(YXJjaGl2bw, bGluZWE)) {
            YXJib2w->alta(cGxhY2E(bGluZWE));
        }
        YXJjaGl2bw.close();
    }
}