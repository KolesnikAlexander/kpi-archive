#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>

using namespace std;

#define N 4

double taskMatrix[N][N+1] ={
    {2,    13,   16,     9,     /*=*/96},
    {4,     31,  18,    8,      /*=*/125},
    {18,    9,     36,     8,      /*=*/213},
    {20, 8, 7, 7, /*=*/130}
};
//diagonal coefficients greater than sum of other ones
double diagonalDominanceMatrix[N][N+1] ={
    {68,    -18,   22,     -6,     /*=*/302},
    {1,     7.75,  4.5,    2,      /*=*/31.25},
    {18,    9,     36,     8,      /*=*/213},
    {31212, 68391, 149634, 151980, /*=*/1098081}
};
void setDisplay(){
//    cout << std::scientific;
//    std::cout.precision(10);
}

void printFullMatrix(const double (&matrix)[N][N+1]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout<< setfill(' ') << setw(10)<<matrix[i][j];
        }
        cout << setfill(' ')<< setw(14) << matrix[i][N]<<endl;
    }
}
void printAlfaMatrix(const double (&matrix)[N][N+1]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N+1; j++){
            cout<< setfill(' ') << setw(10)<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void printVector(const double (&vector)[4]){
    for(int i = 0; i < N; i++){
            cout<<vector[i]<<endl;
    }
}
void printVector2(const double (&vector)[5]){
    for(int i = 0; i < N; i++){
            cout<<vector[i]<<endl;
    }
}

void createAlfa(const double (&matrix)[N][N+1], double (&alfa)[N][N+1]){
    for(int i = 0; i < N; i++){
        alfa[i][N] = matrix[i][N]/matrix[i][i]; //beta
        alfa[i][i] = 0; //diagonal element
        for(int j = 0; j < i;j++){
            alfa[i][j] = -matrix[i][j]/matrix[i][i];
        }
        for(int j = i+1; j < N;j++){
            alfa[i][j] = -matrix[i][j]/matrix[i][i];
        }
    }
}
double sumOfRow(int row, const double (&alfa)[N][N+1]){
    double sum = 0;
    for(int j = 0; j < N; j++){
        sum+=abs(alfa[row][j]);
    }

}
double calcQ(const double (&alfa)[N][N+1]){
    double max = sumOfRow(0, alfa);
    for(int i = 1; i < N; i++){
        double sum = sumOfRow(i, alfa);
        if(sum > max){
            max = sum;
        }
    }
    return max;
}

void iteration(const double (&xPrev)[N], const double (&alfa)[N][N+1],double (&xNext)[N]){
 for(int i = 0; i < N; i++){
     double sum = alfa[i][N];
     for(int j = 0; j < N; j++){
         sum += alfa[i][j] * xPrev[j];
     }
     xNext[i] = sum;
 }
}

double calcNorm( const double (&x)[N], const double (&xPrev)[N]){
    double difference[N];

    for(int i = 0; i < N; i++){
        difference[i] = x[i] - xPrev[i];
    }

    double max = abs(difference[0]);
    for(int i =1; i < N; i++){
        if(abs(difference[i]) > max)
            max = abs(difference[i]);
    }
    return max;
}

void directIter(){
    double eps = 0.01;
    double alfa[N][N+1]; //beta(i) = alfa(i,N)
       createAlfa(diagonalDominanceMatrix, alfa);

    double q;
        q = calcQ(alfa);

    double xPrev[N];
    //previous x is a free term of equation
    for(int i = 0; i < N; i++){
         xPrev[i]=alfa[i][N];
     }

    double xNext[N];

    cout<<"Alfa matrix"<<endl;
    cout<<"\t\t\t\t\t\t"<<"beta"<<endl;
    printFullMatrix(alfa);
    cout<<endl<<"q = "<<q<<endl<<endl;

    cout<<"X0: "<<endl;
    printVector(xPrev);

    cout <<"eps = "<<eps<<endl;

    int k = 0;
    double norm;
    do{
        k++;
        memcpy(xPrev, xNext, sizeof(xPrev));
        iteration(xPrev, alfa, xNext);

        norm = calcNorm(xNext, xPrev);
    }while(norm > abs(eps*(1-q)/q));

    cout<<"  Result"<<endl;
    cout<<"X: "<<endl;
    printVector(xNext);
    cout<<endl<<"k = "<<k<<endl;
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

void gaussJordanElimination(){
    double a[N][N+1];
    memcpy(a, taskMatrix, sizeof(a));

    int counter = 0;
    cout<<"Matrix("<<counter++<<")"<<endl;
    printFullMatrix(a);

    for(int i = 0; i < N; i++){
        devideRow(i, a[i][i], a);
        for(int k = i+1; k < N;k++){
            multAndSubtr(a[k][i], i, k, a);
            cout<<"Matrix("<<counter++<<")"<<endl;
            printFullMatrix(a);
        }
    }

    for(int i = N-1; i > -1; i--){
        for(int k = i-1; k > -1;k--){
            multAndSubtr(a[k][i], i, k, a);
            cout<<"Matrix("<<counter++<<")"<<endl;
            printFullMatrix(a);
        }
    }
}

int main()
{
    setDisplay();
    cout<<"Matrix with diagonal domination: "<<endl;
    printFullMatrix(diagonalDominanceMatrix);
    cout<<endl;

    cout<<" ||DIRECT ITERATION||"<<endl<<endl;
    directIter();
    cout<<" ||GAUSS-JORDAN ELIMINATION||"<<endl<<endl;
    gaussJordanElimination();

    return 0;
}
