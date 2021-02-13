#include<iostream> 

class Ponto2D{
    
     public:
        Ponto2D(int xx = 0.0, int yy = 0.0):x(xx),y(yy){ };
        friend std::ostream& operator<< (std::ostream &op, const Ponto2D &p);
        Ponto2D& operator= (const Ponto2D &p);
        ~Ponto2D(){};

        inline double get_x(void) { return x; }
        inline double get_y(void) { return y; }
        inline void set (double nx, double ny) { x=nx; y=ny; }
    
    private:                
        double x;
        double y;
};

class Ponto3D: public Ponto2D{
    
    public:
        Ponto3D(double xx = 0.0, double yy = 0.0, double zz=0.0){

            xx = this->get_x();
            yy = this->get_y();
            zz = get_z();
        };

        friend std::ostream& operator<< (std::ostream &op, const Ponto3D &p);
        Ponto3D& operator= (const Ponto2D &p);
        
        inline void set(double nx = 0, double ny = 0, double nz=0) {};
        inline double get_z(void) {return z; }
            
    
    private:
        double z;
};   

class Box: public Ponto3D{

    public:
        Box(double largura=0.0, double altura=0.0, double profundidade = 0.0);
        Box(Ponto3D P1, Ponto3D P2, Ponto3D P3) {}

    private:

};

std::ostream& operator<< (std::ostream &op, const Ponto2D &p){
            op << std::endl;
            op << "x = " << p.x << std::endl;
            op << "y = " << p.y << std::endl;
            return op;
}

Ponto2D& Ponto2D::operator= (const Ponto2D &p){
    x = p.x;
    y = p.y;
    return *this;
}

