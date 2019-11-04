/// In the description of the task it is not said whether we want to check on the boarder (outline) of any of the figures, so we assume we check points only within the outlines and not on them
#include<iostream>
#include<cmath> // Cannot be used officially. There will be 2 solutions, one using it (intuitively) and one without using it
using namespace std;

const int Ax = 4, Ay = 2, r = 1;
const int Cx = -6, Cy = 2, Dx = -2, Dy = 2, Ex = -2, Ey = 5, Fx = -6, Fy = 5;
const int Gx = 0, Gy = -1, Hx = -2, Hy = -4, Ix = 6, Iy = -2;
/// All of the above points can be of type double, but by the image we have all the coordinates integers and therefore int was chosen

int main()
{
    double x, y;
    cin>>x>>y;

    /// Circle
    double dist = (x-Ax)*(x-Ax)+(y-Ay)*(y-Ay); /// In this case we get the distance squared
    if(dist<r*r) /// As we have the distance squared, we need to compare with the radius squared
    {
        cout<<"The point ("<<x<<", "<<y<<") is within the given circle k(A,r)"<<endl;
        return 0; /// With this, we terminate (exit) the program
    }

    /// Square
    if(x>Cx && x<Ex && y>Cy && y<Ey)
    {
        cout<<"The point ("<<x<<", "<<y<<") is within the given square CDEF"<<endl;
        return 0;
    }

    /// Triangle (Sol 1 - using sqrt())
    double GH, HI, IG, GP, HP, IP; /// We choose that P is the input point
    GH = sqrt((Hx-Gx)*(Hx-Gx) + (Hy-Gy)*(Hy-Gy));
    HI = sqrt((Ix-Hx)*(Ix-Hx) + (Iy-Hy)*(Iy-Hy));
    IG = sqrt((Gx-Ix)*(Gx-Ix) + (Gy-Iy)*(Gy-Iy));
    GP = sqrt((x-Gx)*(x-Gx) + (y-Gy)*(y-Gy));
    HP = sqrt((x-Hx)*(x-Hx) + (y-Hy)*(y-Hy));
    IP = sqrt((x-Ix)*(x-Ix) + (y-Iy)*(y-Iy));

    double p = (GH+HI+IG)/2, p1 = (GH+GP+HP)/2, p2 = (HI+HP+IP)/2, p3 = (IG+IP+GP)/2; /// Even faster we can use >>1 for faster division by 2 e.g. p = ( (GH+HI+IG)>>1 )
    double s = sqrt(p*(p-GH)*(p-HI)*(p-IG)), s1 = sqrt(p1*(p1-GH)*(p1-HP)*(p1-GP));
    double s2 = sqrt(p2*(p2-HI)*(p2-HP)*(p2-IP)), s3 = sqrt(p3*(p3-IG)*(p3-IP)*(p3-GP));

    if(s - (s1+s2+s3) < 0.001 && s - (s1+s2+s3) > -0.001) /// you can think of this as if(s == s1+s2+s3)... [1]
    {
        cout<<"The point ("<<x<<", "<<y<<") is within the given triangle GHI (sol 1)"<<endl;
        /// Usually we need return 0; here but to see that the 2nd method is working as well, we don't want our program to terminate
    }

    /// Triangle (Sol 2 - without sqrt())

    /* Formula:
        if our points of the triangle are (x1,y1), (x2, y2), (x3, y3), then the area of the triangle is:
            0.5 * (x1*(y2-y3)+x2*(y3-y1)+x3(y1-y2))
        N.B: This formula gives oriented area and so we have to get absolute value of the formula
    */

    s = (Gx*(Hy-Iy) + Hx*(Iy-Gy) + Ix*(Gy-Hy))/2; if(s<0)s=-s;
    s1 = (x*(Gy-Hy) + Gx*(Hy-y) + Hx*(y-Gy))/2; if(s1<0)s1=-s1;
    s2 = (x*(Hy-Iy) + Hx*(Iy-y) + Ix*(y-Hy))/2; if(s2<0)s2=-s2;
    s3 = (x*(Iy-Gy) + Ix*(Gy-y) + Gx*(y-Iy))/2; if(s3<0)s3=-s3;

    if(s - (s1+s2+s3) < 0.001 && s - (s1+s2+s3) > -0.001) /// you can think of this as if(s == s1+s2+s3)... [1]
    {
        cout<<"The point ("<<x<<", "<<y<<") is within the given triangle GHI (sol 2)"<<endl;
        return 0;
    }

    /// If all the upper cases have not been satisfied, then the program wouldn't be terminated and so we just output:

    cout<<"The point ("<<x<<", "<<y<<") is not within any of the given figures"<<endl;

    return 0;
}

/**
[1]: Using real numbers in c++ can give some small errors. You can try cout<<(0.1+0.2 == 0.3) and see that it gives us false when it obviously has to return true
this happens due to this that real numbers could be periodic in binary system and the compiler makes approximations. You can ask me for further info on this.
The trick with comparison of real number is to check if the 2 compared numbers are "close enough" from each other. E.g: cout<<(abs(0.1+0.2-0.3) < 0.00001),
where abs(x) gives us the absolute value of x and 0.00001 is the error we are willing to have (depends how precise answer we want).
*/

