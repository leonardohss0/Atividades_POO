#ifndef FUNCAO_H
#define FUNCAO_H

class Funcao {
public:
    //funcao que obtem a integral da funcao pela regra do trapezio
    double getIntegral(double limiteInferior, double limiteSuperior, double intervalos) {

        double delta_x, result, b_menor, b_maior;

        delta_x = (limiteSuperior - limiteInferior) / intervalos;

        b_menor = limiteInferior;
        b_maior = limiteInferior + delta_x;

        for (int i = 0; i < intervalos; i++) {
            result += (((this->func(b_menor) + this->func(b_maior)) / 2) * delta_x);
            b_menor = b_maior;
            b_maior += delta_x;
        }

        return result;
    };

    // funcao virtual representando a funcao cuja integral deve ser calculada
    virtual double func(double input) = 0;

    // destrutor
};

#endif