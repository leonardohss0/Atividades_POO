#include <bits/stdc++.h>
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

#include "ProfHorista.hpp"
#include "ProfIntegral.hpp"
#include "Universidade.hpp"

int main() {
    
    Universidade uni = Universidade();

    uni.addProfessor("Luiz", 7200.37); // Professor integral
    uni.addProfessor("Leonardo", 200, 45); // Professores horistas
    uni.addProfessor("Kyoshi", 160, 50); // Professores horistas
    
    uni.listaProf_Salario();
    std::cout << "TOTAL PAGO MENSALMENTE AOS PROFESSORES: " 
              << uni.totalPago() << std::endl;
}
