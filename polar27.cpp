#include <iostream>
#include <cmath>
using namespace std;

class Polar {
private:
    double radius;
    double angle; // taking the angles in degree

public:
    // def constructor 
    Polar() {
        radius = 0;
        angle = 0;
    }
    
    Polar(double r, double a) {
        radius = r;
        angle = a;
    }

    void input() {
        cout << "Enter radius: ";
        cin >> radius;
        cout << "Enter angle (in degrees): ";
        cin >> angle;
    }

// here we are giving output
    void display() {
        cout << "Radius: " << radius << ", Angle: " << angle << " degrees" << endl;
    }
    
//adding the coordinate 
    Polar add(Polar p) {
        double x1 = radius * cos(angle * M_PI / 180);
        double y1 = radius * sin(angle * M_PI / 180);
        double x2 = p.radius * cos(p.angle * M_PI / 180);
        double y2 = p.radius * sin(p.angle * M_PI / 180);
        double x = x1 + x2;
        double y = y1 + y2;
        double r = sqrt(x * x + y * y);
        double a = atan2(y, x) * 180 / M_PI;
         return Polar(r, a);
    }
};

int main() {
    Polar p1, p2, p3;
    
    cout << "Enter first polar coordinate:" << endl;
    p1.input();
    
    cout << "Enter second polar coordinate:" << endl;
    p2.input();
    
    p3 = p1.add(p2);
    cout << "resulting Polar Coordinate: ";
    p3.display();
    return 0;
}
