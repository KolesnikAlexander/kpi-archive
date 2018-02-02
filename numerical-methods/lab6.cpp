#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

#define NUM_OF_SEG_CSV 500 //used for creating a csv file
char* CSV_PATH = "lab6.csv";

#define N 5 //number of polynomials
int a = 0;
int b = 7;

double xArray[N+1];
double fArray[N+1];
double h;
double matrix[N+1][N+2];

double cArray[N+1];
double dArray[N+1];
double bArray[N+1];

void setDisplay(){
    cout << std::scientific;
    std::cout.precision(2);
}

void printFullMatrix(const double (&matrix)[N+1][N+2]){
    for(int i = 0; i < N+1; i++){
        for(int j = 0; j < N+1; j++){
            printf("%.2f     ", matrix[i][j]);
        }
        cout << setfill(' ')<< setw(14);// << matrix[i][N+1]<<endl;
        printf("%.2f     \n", matrix[i][N+1]);
    }
}

void printArray(const double (&array)[N+1]){
    for(int i = 0; i < N+1; i++){
        cout<<array[i]<<endl;
    }
}

void devideRow(int row, double denom, double (&a)[N+1][N+2]){
    for(int j = 0; j < N+2;j++){
        a[row][j] = a[row][j]/denom;
    }
}
void multAndSubtr(double multiplier, int multRow, int subtrahendRow, double (&a)[N+1][N+2]){
    double vect[N+2];
    for(int j = 0; j < N+2;j++){
        vect[j] = a[multRow][j]*multiplier;
    }
    for(int j = 0; j < N+2;j++){
        a[subtrahendRow][j]= a[subtrahendRow][j]-vect[j];
    }
}
void gaussianElimination(){
    double a[N+1][N+2];
    memcpy(a, matrix, sizeof(a));

    int counter = 0;

    for(int i = 0; i < N; i++){
        devideRow(i, a[i][i], a);
        multAndSubtr(a[i+1][i], i, i+1, a);
    }

    cArray[N] = a[N][N+1];
    for(int i = N-1; i > -1; i--){
        cArray[i] = a[i][N+1] - a[i][i+1]*cArray[i+1];
    }

}
 double f(double x){
        return 0.001 * std::exp(x+5) * cos(3*x);
}
void fillXArray(){
    double h = (b-a)/(double)N;
    xArray[0] = a;
    xArray[N] = b;
    for(int i = 1; i < N; i++){
        xArray[i] = a+i*h;
    }
}

void fillH(){
    h = xArray[1] - xArray[0];
}
void fillFArray(){
    for(int i = 0; i < N+1; i++){
        fArray[i] = f(xArray[i]);
    }
}

void fillMatrix(){
    matrix[0][0] = 1;
    matrix[N][N] = 1;
    for(int i = 1; i <= N-1; i++){
        for(int j = 0; j < i-1; j++){
            matrix[i][j] = 0;
        }
        matrix[i][i-1] = h;
        matrix[i][i] = 4*h;
        matrix[i][i+1] = h;
        for(int j = i+2; j < N+1; j++){
            matrix[i][j] = 0;
        }
        matrix[i][N+1] = 6*((fArray[i+1] - fArray[i])-(fArray[i] - fArray[i-1]))/h;
    }
}

void fillCoefficients(){
    for(int i = 1; i < N+1; i++){
        dArray[i] = (cArray[i] - cArray[i-1])/h;
        bArray[i] = h*cArray[i]/2 -
                           h*h*dArray[i]/6+
                           (fArray[i] - fArray[i-1])/h;
    }
}

double s(int i, double x){ // spline value
    return fArray[i] + bArray[i]*(x-xArray[i])+
            cArray[i]/2*(x-xArray[i])*(x-xArray[i])+
            dArray[i]/6*(x-xArray[i])*(x-xArray[i])*(x-xArray[i]);
}

void makeCSV(){
    std::fstream file(CSV_PATH, std::ios::out); // | std::ios::app);
    if (!file){
        cerr<< "Failed to open a file"<<endl;
        return;
    }
      double step = (xArray[N]-xArray[0])/NUM_OF_SEG_CSV;
      for(int i = 1; i <= N; i++){
          double x = xArray[i-1];
          file<<x<<" "<<s(i, x)<<endl;
          x+=step;
          while(x < xArray[i]){
              file<<x<<" "<<s(i, x)<<endl;
              x+=step;
          }
      }
      file<<xArray[N]<<" "<<s(N, xArray[N])<<endl;
      file.close();

}

int main()
{
   memset(matrix,0,sizeof(matrix));
    setDisplay();

    fillXArray();
    fillH();
    fillFArray();
    fillMatrix();
    gaussianElimination();
    fillCoefficients();

    makeCSV();

    cout<<"Done"<<endl;
    cout<<"Number of polynomials: "<<N<<endl;
    cout<<"Сoordinates of the points are recorded in a file"<<endl;

    return 0;
}
