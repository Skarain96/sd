#include "conio.h"  
#include <stdio.h>  
#include "iostream"  
#include <string.h>  
  
using namespace std;  
class A 
{ 
private: 
    int dim; 
    double *c; 
public: 
  
    A(int d=0,double *t=NULL) 
    { 
        dim=d; 
        c=t; 
    }; 
    int dimension()  
    { 
        return dim; 
    }; 
    void print()  
    { 
        cout << "Размерность вектора= " << dim << endl << "Координаты вектора: "; 
        for (int i=0;i<dim;i++) 
        { 
            cout << c[i] << ", " ; 
        } 
        cout << endl; 
    }; 
    double operator[] (size_t i)  
    { 
        return c[i]; 
    }; 
    const A operator+ (A&  right) const// ключевое слово const  
    { 
        if (dim==right.dimension()) { 
            double *f=new double[dim]; 
            for(int i=0;i<dim;i++) 
            { 
                f[i]=c[i]+right[i];          
            } 
            return A(dim,f); 
        } 
        else
        { 
            return A(); 
        }; 
    }; 
    ~A() { 
        cout<<"Destructor\n"; 
    }; 
    A& operator= (A& right) // Вид X& конструктора копирования используется когда необходимо изменить копируемый объект. 
    { 
        //проверка на самоприсваивание 
        if (this == &right)  
        { 
            return *this;// this - ключевое слово, обеспечивающее доступ к текущему экземпляру класса 
        } 
  
        //Код для операции присваивания 
        if (dim==right.dimension()) { 
            double *f=new double[dim]; 
            for(int i=0;i<dim;i++) 
            { 
                c[i]=right[i];           
            } 
            return A(dim,f); 
        } 
        else
        { 
            return A(); 
        }; 
    }    
}; 
  
void main(void)  
{ 
    setlocale(LC_ALL,"Russian"); 
    int n=0; 
      
    cout << "Введите размерность вектора: "; 
    cin >> n; 
    double *y=new double[n]; 
    A v1(n,y); 
    v1.print(); 
  
    getch(); 
}