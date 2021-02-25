#include <bits/stdc++.h>
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

#include "ProfHorista.hpp"
#include "ProfIntegral.hpp"

int main() {
    std::string name1 = "Luiz";
    std::string name2 = "Leonardo";
    ProfHorista prof1(name1, 160, 45);
    ProfIntegral prof2(name2, 7000);

    std::cout << prof1.getName() << " " << prof1.getSalario() << std::endl;
    std::cout << prof2.getName() << " " << prof2.getSalario() << std::endl;
}
