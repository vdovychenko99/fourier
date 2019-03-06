#include <stdio.h>
#include <math.h>

double aa(double k)
{
    double w = 2*3.14159265359/1e-3;
    return (2 / 1e-3) * (-0.000660) * coshl( k * w * 1e-3);
}

double bb(double k)
{
    double w = 2*3.14159265359/1e-3;
    return (2 / 1e-3) * (-0.000660) * sinhl( k * w * 1e-3);
}

double aak(double k)
{
    double sum;
    double w = 2*3.14159265359/1e-3;
    return (2 * (1e-3/200))/1e-3 * (-0.000660) * sinhl( k * w * 1e-3);
}

double area(double height)
{
    double area = 0;
    area += height * 0.001/200;
    return area;
}

int main() {
    float x, y, T = 1e-3, N = 200, h = T/N, k, a, b, pl, test; //coef[50] ;
    float coef = 0.00125;
    double PI = 3.14159265359;
    int I=1;
    double w = 2*PI/T;
    FILE *myfilex, *myfiley,*myfile, *ak, *bk;
    myfilex = fopen("myfilex.txt", "wt");
    myfiley = fopen("myfiley.txt", "wt");
    myfile = fopen("myfile.txt", "wt");
    ak = fopen("ak.txt", "wt");
    bk = fopen("bk.txt", "wt");
    x = 0;
    y = 0;
    pl = 0;

   while (x <= 0.001) {

       if (x<=0.00025) {
           y = 5 * x / 0.00025;
           printf("y = %f \n", y);
           fprintf(myfilex,"%.10f\n", x);
           fprintf(myfiley,"%.10f\n", y);
           fprintf(myfile,"%.10f %.10f \n", x, y);
           pl += area(y);
       }

       if ((x>0.00025)&&(x<=0.0005)) {
           y = 5 - 5 * (x - 0.00025) / 0.00025;
           printf("y = %f \n", y);
           fprintf(myfilex,"%.10f\n", x);
           fprintf(myfiley,"%.10f\n", y);
           fprintf(myfile,"%.10f %.10f \n", x, y);
           pl += area(y);
       }

       if ((x>0.0005)&&(x<=0.001)) {
            y = 6 * sin(2 * PI * x / 0.001);
            printf("y = %f \n", y);
            fprintf(myfilex,"%.10f\n", x);
            fprintf(myfiley,"%.10f\n", y);
           fprintf(myfile,"%.10f %.10f \n", x, y);
           pl += area(y);
       }

       x += 0.001/N;
   }

   int i = -1;
   while(i <2*N+1){
    fprintf(ak,"ak%d = %.10f\n",i, aak(i));
    fprintf(bk,"ak%d = %.10f\n",i, bb(i));
    i++;
   }


    printf("t = %f \n", T);
    printf("N = %f \n", N);
    printf("h = %f \n", h);
    printf("w = %f \n", w);
    printf("pl = %f \n", pl);
    printf("a0 = %f \n", aa(0));
    printf("a1 = %f \n", aa(1));
    printf("a5 = %f \n", aa(5));
    printf("b0 = %f \n", bb(0));
    printf("b1 = %f \n", bb(1));
    printf("b5 = %f \n", bb(5));
    // plot "E:/ProgrammingLab8/myfile.txt"
    printf("a5 = %f \n", aak(0));
    printf("a5 = %f \n", aak(1));
    printf("a5 = %f \n", aak(5));
    return 0;
}
