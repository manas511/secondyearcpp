#include <iostream>
#include <cmath>

#define PI 3.14159265

class Cartesian; 

class Polar {
public:
    double radius, angle; 

    Polar(double r = 0, double a = 0) : radius(r), angle(a) {}

    
    Polar(const Cartesian &c);

    void display() {
        std::cout << "Polar: Radius = " << radius << ", Angle = " << angle << "°" << std::endl;
    }
};

class Cartesian {
public:
    double x, y;

    Cartesian(double xVal = 0, double yVal = 0) : x(xVal), y(yVal) {}

    
    Cartesian(const Polar &p) {
        x = p.radius * cos(p.angle * PI / 180);
        y = p.radius * sin(p.angle * PI / 180);
    }

    void display() {
        std::cout << "Cartesian: x = " << x << ", y = " << y << std::endl;
    }
};


Polar::Polar(const Cartesian &c) {
    radius = sqrt(c.x * c.x + c.y * c.y);
    angle = atan2(c.y, c.x) * 180 / PI;
}

int main() {
    Polar p(10, 45);  
    Cartesian c = p;  

    p.display();
    c.display();

    Cartesian c2(3, 4);  
    Polar p2 = c2;       

    c2.display();
    p2.display();

    return 0;
}
