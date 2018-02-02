#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <fstream>

using namespace std;

#define NUM_OF_SEG_CSV 300//used for creating a csv file
char* CSV_PATH = "lab5.csv";

#define M 23//degree of the generalized polynomial
#define N M+1

double matrix[N][N+1];//norm system
double rootsOfSystem[N];

void setDisplay(){
    cout << std::scientific;
    std::cout.precision(4);
}

void printFullMatrix(const double (&matrix)[N][N+1]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout<< setfill(' ') << setw(10)<<matrix[i][j] << " ";
        }
        cout << setfill(' ')<< setw(14) << matrix[i][N]<<endl;
    }
}

void devideRow(int row, double denom, double (&a)[N][N+1]){
    for(int j = 0; j < N+1;j++){
        a[row][j] = a[row][j]/denom;
    }
}
void multAndSubtr(double multiplier, int multRow, int subtrahendRow, double (&a)[N][N+1]){
    double vect[N+1];
    for(int j = 0; j < N+1;j++){
        vect[j] = a[multRow][j]*multiplier;
    }
    for(int j = 0; j < N+1;j++){
        a[subtrahendRow][j]= a[subtrahendRow][j]-vect[j];
    }
}

void gaussianElimination(){
    double a[N][N+1];
    memcpy(a, matrix, sizeof(a));

    int counter = 0;

    for(int i = 0; i < N; i++){
        devideRow(i, a[i][i], a);
        for(int k = i+1; k < N;k++){
            multAndSubtr(a[k][i], i, k, a);
        }
    }

    rootsOfSystem[N-1] = a[N-1][N];
    for(int i = N-1; i > -1; i--){
        double sum = 0;
        for(int j = i+1; j < N; j++){
            sum+=a[i][j]*rootsOfSystem[j];
        }
        rootsOfSystem[i] = a[i][N] - sum;
    }
}
double phiIter(double x, double tMinusTwo, double tMinusOne){
    return 2*x*tMinusOne-tMinusTwo;
}

double integralF(double x){
    return 0.001 * std::exp(x+5) * cos(3*x);
}

double calcDegreeDiagonal(double x, int degreeDiagonal){
    double phiValue;
    if(degreeDiagonal == 0)
        phiValue = 1;
    else if(degreeDiagonal == 1)
        phiValue = x;
    else{
        double xMinusTwo = 1;
        double xMinusOne = x;
        for(int i = 2; i <= degreeDiagonal;i++ ){
            phiValue=phiIter(x, xMinusTwo, xMinusOne);
            xMinusTwo = xMinusOne;
            xMinusOne = phiValue;
        }
    }
    return phiValue;
}

double f(double x, int degreeCur, int degreeDiagonal, bool lsdMode){

    if(lsdMode){
        double sum = 0;
        for(int k = 0; k < N; k++){

            double phiValue;
            if(k == 0)
                phiValue = 1;
            else if(k == 1)
                phiValue = x;
            else{
                double xMinusTwo = 1;
                double xMinusOne = x;
                for(int i = 2; i <= k;i++ ){
                    phiValue=phiIter(x, xMinusTwo, xMinusOne);
                    xMinusTwo = xMinusOne;
                    xMinusOne = phiValue;
                }
            }

            sum+=rootsOfSystem[k]*phiValue; //* phi(k, x);
        }
        return std::pow(sum - integralF(x), 2);
    }

    double diagonalPhiValue = calcDegreeDiagonal(x, degreeDiagonal);
    if(degreeCur == N){
         return integralF(x)*diagonalPhiValue;
    }

    else
    {
        double phiValue;
        if(degreeCur == 0)
            phiValue = 1;
        else if(degreeCur == 1)
            phiValue = x;
        else{
            double xMinusTwo = 1;
            double xMinusOne = x;
            for(int i = 2; i <= degreeCur;i++ ){
                phiValue=phiIter(x, xMinusTwo, xMinusOne);
                xMinusTwo = xMinusOne;
                xMinusOne = phiValue;
            }
        }
        return phiValue * diagonalPhiValue;
    }
}
void simpsonsMethod(double n, double h, double &result, int degreeCur,int degreeDiagonal, bool lsdMode){

    double a = 0;
    double b = 7;

    double y0 = f(a, degreeCur, degreeDiagonal, lsdMode);
    double yn = f(b, degreeCur, degreeDiagonal, lsdMode);

    double sigma1 = 0;
    double sigma2 = 0;

    for(int i = 1;i <= n-1;i+=2){
        sigma1+=f(a+i*h, degreeCur, degreeDiagonal, lsdMode);
    }
    for(int i = 2;i <= n-2;i+=2){
        sigma2+=f(a+i*h, degreeCur, degreeDiagonal, lsdMode);
    }

    result = h*(y0 + yn + 4*sigma1 + 2*sigma2)/3;
}

double calcIntegral(double relError, int degreeCur,int degreeDiagonal, bool lsdMode){
    double a = 0;
    double b = 7;

    int n = (int)(1/std::pow(relError, 1./4.));
    if((n % 2) != 0)
        n++;
    double h = (b-a)/n;
    double result;

    double integral0;
    double integral1;

    simpsonsMethod(n, h, integral1, degreeCur, degreeDiagonal, lsdMode);
    double rn;
    double delta;
    do{
        n*=2;
        h/=2;
        integral0 = integral1;
        simpsonsMethod(n, h, integral1, degreeCur, degreeDiagonal, lsdMode);
        delta = fabs(integral1 - integral0);
        rn = delta/(15);
        cout<<"n =  ";
        cout<<n<<endl;

    }while(fabs(integral0-integral1)/integral1 > relError*8);
    return integral1;
}

double lsdF(double x, const double (&xPrev)[N] ){
    return x;
}

void fillMatrix(double relError){
    for(int i = 0; i < N; i++ ){
        for(int j = 0; j < N+1; j++){
            printf("COEFICIENT %d %d\n",i,j);
            matrix[i][j] = calcIntegral(relError, j, i, false);
        }
    }
}

void printRoots(){
    for(int i = 0; i < N; i++){
        cout<<"     a"<<i<<"="<<rootsOfSystem[i]<<endl;
    }
}

void makeCSV(double a, double b){
    std::fstream file(CSV_PATH, std::ios::out);
    if (!file){
        cerr<< "Failed to open a file"<<endl;
        return;
    }
      double step = (b-a)/(double)NUM_OF_SEG_CSV;
      double x = a;
      while(x < b){
          double p = 0;
          double xMinusTwo = 1;
          double xMinusOne = x;
          p+=rootsOfSystem[0]*1;
          p+=rootsOfSystem[1]*x;
          double phiValue;
          for(int i = 2; i < N; i++){
              phiValue=phiIter(x, xMinusTwo, xMinusOne);
              xMinusTwo = xMinusOne;
              xMinusOne = phiValue;
              p+=rootsOfSystem[i]*phiValue;
          }
          file<<x<<" "<<p<<endl;
          x+=step;
      }
      file.close();

}

int main()
{
    double a = 0;
    double b = 7;
    double relError = 0.00000000000001;//0.00000000000001;

    setDisplay();

    fillMatrix(relError);
    printFullMatrix(matrix);
    gaussianElimination();

    cout<<endl<<"Calculation of the least squares deviation ..."<<endl;
    double integral = calcIntegral(0.00001, -1, -1, true);
    double lsd = std::pow(integral/(b-a), 1./2.);

    // INFO
    cout<<endl<<endl<<"RESULT "<<endl;
    cout<<"--------------- "<<endl;
    cout<<"M = "<<M<<endl;
    cout<<"Coefficients: "<<endl;
    printRoots();
    cout<<"Least squares deviation: "<<lsd<<endl;

    //CSV
    cout<<"Making csv..."<<endl;
    makeCSV(a,b);
    cout<<"Done"<<endl;

    char finish;
    cin >> finish;
    return 0;
}

