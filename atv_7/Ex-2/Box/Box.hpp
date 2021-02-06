#include "../../Ex-1/Ponto3D/Ponto3D.hpp"

class Box: public Ponto3D{
    public:
      Box(float largura=0.0, float profundidade=0.0, float altura=0.0);

      /*
        Considerando dois planos, cada um com 2 pontos. P2 e P1 estão no mesmo eixo y
        enquanto P1 e P5 estão no mesmo eixo x. P1 e P4 estao no mesmo eixo Z.
      */
      Box(Ponto3D &P1, Ponto3D &P2, Ponto3D &P4, Ponto3D &P5);

      float Area() const;
        
      float Volume () const;

    private:
      float largura, altura, profundidade;
};