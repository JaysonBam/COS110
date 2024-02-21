#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "term.h"
#include "univariate.h"
#include "polynomial.h"
#include "linear.h"
#include "quadratic.h"
#include "bivariate.h"
#include "circle.h"
#include "ellipse.h"

template <typename T>
void printArray(const T* array, int size) {
    std::cout<<'[';
    for (int i = 0; i < size; ++i) {
        std::cout << array[i];
        if (i < size - 1) {
            std::cout << ",";
        }
    }
    std::cout<<']';
}

void termConstructor(){
    term t1;
    cout<<"Default con:      \t"<<~t1<<endl; 

    char base[] = {'x','a','x','b','c'};
    int  exp[]  = { 3 , 4 , 2 , -1, 0 };
    term t2(10,5,base,exp);
    cout<<"Parameterized con:\t"<<~t2<<endl;

    term t3(t2);
    cout<<"Copy con:         \t"<<~t3<<endl;

    term t4("-10*x^2*w^3*a^1");
    cout<<"String con:       \t"<<~t4<<endl;

    t1 = t3 = t4 = t4;
    cout<<"assignment op:    \t"<<~t1<<endl;

}

void termGetters(){
    term t("+8*x*x^1*x^0*x^-1*b");
    cout<<"For term:  \t"<<~t<<endl;
    int num = t.getNumVariables();
    cout<<"Num of var:\t"<<num<<endl;
    char* c = t.getVariables();
    cout<<"Variables: \t";
    printArray<char>(c,num);
    cout<<endl;
    cout<<"Degree:    \t"<<~t.getDegree()<<endl;
}

void testCompair(const term& t1,const term& t2){
    if (t1 == t2) cout<<~t1<< " = " <<~t2<<"\t\t";
    if (t1 < t2) cout<<~t1<< " < " <<~t2<<"\t\t";;
    if (t1 > t2) cout<<~t1<< " > " <<~t2<<"\t\t";;
    cout<<endl;
}

void termOperators() {
    std::string termText[] = {
        "10*x^2*w^3*a^1",
        "+8*x*x^1*x^0*x^-1",
        "1*x^2",
        "-x^2",
        "0*x^2",
        "+z^-3"
    };

    const int filesize = 6;
    term terms[filesize];

    for (int i = 0; i < filesize; i++) {
        std::istringstream iss(termText[i]);
        iss >> terms[i];
        std::cout << "Term " << i << " : " << ~terms[i] << "\t[" << terms[i].getDegree() << "]\n";
    }

    cout<<endl;

    cout<<"term0 * term1 = "<<~(terms[0]*terms[1])<<endl;
    term temp(terms[1]);
    temp *= terms[0];
    cout<<"term1 * term0 = "<<~temp<<endl;
    cout<<"term1 * term5 = "<<~(terms[1]*terms[5])<<endl;
    cout<<"term1 * term4 = "<<~(terms[1]*terms[4])<<endl;

    char vars[] = {'x','w'};
    int  vals[] = { 3 , 4 };
    cout<<endl<<"[1] For x = 3 amd w = 4"<<endl;
    for (int i = 0; i < filesize; i++)
        cout<<i<<":"<<~terms[i](vars,vals,2)<<endl;

    cout<<endl<<"[2] For x = 3 amd w = 4"<<endl;
    for (int i = 0; i < filesize; i++)
        cout<<i<<":"<<~terms[i]("x=3 w=4")<<endl;
        
    cout<<endl;
    testCompair(terms[0],terms[1]);
    testCompair(terms[2],terms[3]);
    testCompair(terms[2],terms[4]);
    testCompair(terms[4],terms[5]);
    testCompair(terms[4],terms[0]);
    testCompair(terms[0],terms[4]);

    cout<<endl;
    cout<<(terms[0])[terms[0].getVarIndex('w')]<<endl;
    cout<<(terms[0])[terms[0].getVarIndex('m')]<<endl;
    cout<<~!terms[0]<<endl;
}

void testTerm(){
    cout<<"Term constructor=================================\n";
    termConstructor();
    cout<<"Term getters=====================================\n";
    termGetters();
    cout<<"term operator====================================\n";
    termOperators();
}

void uniConstructor(){
    polynomial* u1 = new univariate(5,'x');
    cout <<"default:"<< *u1;

    std::string termText[] = {
        "10*x^2*x^3*a^-1",
        "+8*x*x^1*x^0*x^-1",
        "1*x^2",
        "-x"
    };
    term** t = new term*[4];
    for (int i = 0; i < 4; i++) {
        t[i] = new term(termText[i].c_str());
    }
    //cout<<"m"<<__LINE__;
    polynomial* u2 = new univariate(t,4);
    cout <<"term array:"<< *u2;

    polynomial* u6 = new univariate(*t[0]);
    cout<<"term:"<<*u6;

    for (int i = 0; i < 4; i++) 
        delete t[i];
    delete[] t;

    polynomial* u3 = new univariate("x^2*x^2 + 2*x*x + 1 + x^-3");
    cout<<"string:"<<*u3;

    polynomial* u4 = new univariate(*u3);
    cout<<"copy poly:"<<*u4;

    univariate u("+ -c^2*c^2 + -2*c + -1");
    univariate ub("3");

    polynomial* u5 = new univariate(u);
    cout<<"copy univ:"<<*u5;

    ub = u;

    cout<<"assign:"<<ub;

    (*u6)[-1];
    delete u1;
    delete u2;
    delete u3;
    delete u4;
    delete u5;
    delete u6;

}

void uniGetters(){
    polynomial* p = new univariate("x^2*x^2 + 2*x*x + 1 + x^-3");
    term** t = p->getTerms();
    int n = p->getNumTerms();
    cout<<'[';
    for (int i(0); i < n; i++){
        cout<<(t[i]->operator~());
        if ( i < n-1)
            cout<<',';
    }
    cout<<"]\n";    
    delete p;
}

void uniOp(){
    univariate u1("x^4 - 2*x^2 + 6");
    univariate u2("2 + x^3 + 3*x - 2*x^2");
    univariate u3("x^2 - 4*x + 3");
    univariate u4("x - 1");
    univariate u5("0");

    polynomial* p1 = u1 + u2;
    polynomial* p2 = u1 * u2;
    polynomial* p3 = u1 - u2;
    polynomial* p4 = u1 * u5;

    cout << *p1;
    cout << *p2;
    cout << *p3;
    cout << *p4;

    delete p1;
    delete p2;
    delete p3;
    delete p4;

    univariate ua(u1);
    univariate ub(u1);
    univariate uc(u1);
    univariate ud(u1);

    ua += u2;
    ub *= u2;
    uc -= u2;
    ud *= u5;

    cout << endl;
    cout << ua;
    cout << ub;
    cout << uc;
    cout << ud;

    p1 = u1("x=2");
    cout<<*p1;
    char c[] = {'x'};
    int i[] = {0};
    p2 = u2(c,i,1);
    cout<<*p2;
    
    delete p1;
    delete p2;
}

void testUnivariate(){  
    cout<<"Univ constructor=================================\n";
    uniConstructor();
    cout<<"Univ getters=====================================\n";
    uniGetters();
    cout<<"Univ operator====================================\n";
    uniOp();
}


void linearConstructor(){
    polynomial* u1 = new linear('x');
    cout <<"default:"<< *u1;

    std::string termText[] = {
        "10*x^2*x^3*a^-1",
        "+8*x*x^1*x^0*x^-1",
        "1*x^2",
        "-x"
    };
    term** t = new term*[4];
    for (int i = 0; i < 4; i++) {
        t[i] = new term(termText[i].c_str());
    }
    //cout<<"m"<<__LINE__;
    polynomial* u2 = new linear(t,4);
    cout <<"term array:"<< *u2;

    polynomial* u6 = new linear(*t[0]);
    cout<<"term:"<<*u6;

    for (int i = 0; i < 4; i++) 
        delete t[i];
    delete[] t;

    polynomial* u3 = new linear("x^2*x^2 + 2*x*x + 1 + x^-3");
    cout<<"string:"<<*u3;

    polynomial* u4 = new linear(*u3);
    cout<<"copy poly:"<<*u4;

    linear u("+ -c^2*c^2 + -2*c + -1");
    linear ub("3");

    polynomial* u5 = new linear(u);
    cout<<"copy univ:"<<*u5;

    ub = u;

    cout<<"assign:"<<ub;

    (*u6)[-1];
    delete u1;
    delete u2;
    delete u3;
    delete u4;
    delete u5;
    delete u6;

}

void testLinear(){
    cout<<"Linear constructor===============================\n";
    linearConstructor();
    cout<<"Linear test======================================\n";
    linear l1("x");
    linear l2("x + 1");
    linear l3("-6*x + 9");
    linear l4("-6 + 9");
    linear l5("x^2 - 1");
    cout<<l1<<l2<<l3<<l4<<l5<<endl;

    l1 += l2;
    l2 *= l2;
    l3 *= l4;    
    cout<<l1<<l2<<l3<<endl;

    cout<<l1;
    l1.printRoots();
    cout<<l2;
    l2.printRoots();
    cout<<l3;
    l3.printRoots();
    cout<<l4;
    l4.printRoots();
    cout<<l5;
    l5.printRoots();
}

void QuadraticConstructor(){
    polynomial* u1 = new quadratic('x');
    cout <<"default:"<< *u1;

    std::string termText[] = {
        "10*x^2*x^3*a^-1",
        "+8*x*x^1*x^0*x^-1",
        "1*x^2",
        "-x"
    };
    term** t = new term*[4];
    for (int i = 0; i < 4; i++) {
        t[i] = new term(termText[i].c_str());
    }
    //cout<<"m"<<__LINE__;
    polynomial* u2 = new quadratic(t,4);
    cout <<"term array:"<< *u2;

    polynomial* u6 = new quadratic(*t[0]);
    cout<<"term:"<<*u6;

    for (int i = 0; i < 4; i++) 
        delete t[i];
    delete[] t;

    polynomial* u3 = new quadratic("x^2*x^2 + 2*x*x + 1 + x^-3");
    cout<<"string:"<<*u3;

    polynomial* u4 = new quadratic(*u3);
    cout<<"copy poly:"<<*u4;

    quadratic u("+ -c^2*c^2 + -2*c + -1");
    quadratic ub("3");

    polynomial* u5 = new quadratic(u);
    cout<<"copy univ:"<<*u5;

    ub = u;

    cout<<"assign:"<<ub;

    (*u6)[-1];
    delete u1;
    delete u2;
    delete u3;
    delete u4;
    delete u5;
    delete u6;

}

void testQuadratic(){
    cout<<"Linear constructor===============================\n";
    QuadraticConstructor();
    cout<<"Linear test======================================\n";
    quadratic l1("9*x^2");
    quadratic l2("x + 1");
    quadratic l3("-6*x + 9");
    quadratic l4("-6 + 9");
    quadratic l5("x^2 - 1");
    cout<<l1<<l2<<l3<<l4<<l5<<endl;

    l1 += l2;
    l2 *= l2;
    l3 *= l4;    
    cout<<l1<<l2<<l3<<endl;

    cout<<l1;
    l1.printRoots();
    cout<<l2;
    l2.printRoots();
    cout<<l3;
    l3.printRoots();
    cout<<l4;
    l4.printRoots();
    cout<<l5;
    l5.printRoots();
}

void biConstructor(){
    polynomial* u1 = new bivariate(5,'x','y');
    cout <<"default:"<< *u1;

    std::string termText[] = {
        "10*x^2*x^3*a^-1",
        "+8*x*x^1*x^0*x^-1",
        "1*x^2",
        "-x"
    };
    term** t = new term*[4];
    for (int i = 0; i < 4; i++) {
        t[i] = new term(termText[i].c_str());
    }
    //cout<<"m"<<__LINE__;
    polynomial* u2 = new bivariate(t,4);
    cout <<"term array:"<< *u2;

    polynomial* u6 = new bivariate(*t[0]);
    cout<<"term:"<<*u6;

    for (int i = 0; i < 4; i++) 
        delete t[i];
    delete[] t;

    polynomial* u3 = new bivariate("x^2*x^2 + 2*x*x + 1 + x^-3");
    cout<<"string:"<<*u3;

    polynomial* u4 = new bivariate(*u3);
    cout<<"copy poly:"<<*u4;

    bivariate u("+ -c^2*c^2 + -2*c + -1");
    bivariate ub("3");

    polynomial* u5 = new bivariate(u);
    cout<<"copy univ:"<<*u5;

    ub = u;

    cout<<"assign:"<<ub;

    (*u6)[-1];
    delete u1;
    delete u2;
    delete u3;
    delete u4;
    delete u5;
    delete u6;

}

void biGetters(){
    polynomial* p = new bivariate("x^2*x^2 + 2*x*x + 1 + x^-3");
    term** t = p->getTerms();
    int n = p->getNumTerms();
    cout<<'[';
    for (int i(0); i < n; i++){
        cout<<~(*t[i]);
        if ( i < n-1)
            cout<<',';
    }
    cout<<"]\n";    
    delete p;
}

void biOp(){
    bivariate u1("x^4 - 2*y*x^2 + 6");
    bivariate u2("2*y + x^3 + 3*x - 2*x*y^2");
    bivariate u3("x^2 - 4*x + 3");
    bivariate u4("x - 1");
    bivariate u5("0");

    polynomial* p1 = u1 + u2;
    polynomial* p2 = u1 * u2;
    polynomial* p3 = u1 - u2;
    polynomial* p4 = u1 * u5;

    cout << *p1;
    cout << *p2;
    cout << *p3;
    cout << *p4;

    delete p1;
    delete p2;
    delete p3;
    delete p4;

    bivariate ua(u1);
    bivariate ub(u1);
    bivariate uc(u1);
    bivariate ud(u1);

    ua += u2;
    ub *= u2;
    uc -= u2;
    ud *= u5;

    cout << endl;
    cout << ua;
    cout << ub;
    cout << uc;
    cout << ud;

    p1 = u1("x=2");
    cout<<*p1;
    char c[] = {'x'};
    int i[] = {0};
    p2 = u2(c,i,1);
    cout<<*p2;
    
    delete p1;
    delete p2;
}


void testBivariate(){
    cout<<"Biva constructor=================================\n";
    biConstructor();
    cout<<"Biva getters=====================================\n";
    biGetters();
    cout<<"Biva operator====================================\n";
    biOp();
}

void CircleConstructor(){
    polynomial* u1 = new circle('x','y');
    cout <<"default:"<< *u1;

    std::string termText[] = {
        "y^2",
        "x^2",
        "-6",
        "-9"
    };
    term** t = new term*[4];
    for (int i = 0; i < 4; i++) {
        t[i] = new term(termText[i].c_str());
    }
    //cout<<"m"<<__LINE__;
    polynomial* u2 = new circle(t,4);
    cout <<"term array:"<< *u2;

    polynomial* u6 = new circle(*t[0]);
    cout<<"term:"<<*u6;

    for (int i = 0; i < 4; i++) 
        delete t[i];
    delete[] t;

    polynomial* u3 = new circle("x^2*x^2 + 2*x*x + 1 + x^-3");
    cout<<"string:"<<*u3;

    polynomial* u4 = new circle(*u3);
    cout<<"copy poly:"<<*u4;

    circle u("+c^2* + *y^2 + -1");
    circle ub("3");

    polynomial* u5 = new circle(u);
    cout<<"copy univ:"<<*u5;

    ub = u;

    cout<<"assign:"<<ub;

    (*u6)[-1];
    delete u1;
    delete u2;
    delete u3;
    delete u4;
    delete u5;
    delete u6;

}

void testCircle(){
    cout<<"Circle constructor===============================\n";
    CircleConstructor();
    cout<<"Circle test======================================\n";
    circle l1("9*x^2 + 9*y^2 - 8");
    circle l2("7*x^2 + 7*y^2 + 4");
    circle l3("7*x^2 + 6*y^2 - 4");
    circle l4("-6 + 9");
    circle l5("x^2 - 1");
    cout<<l1<<l2<<l3<<l4<<l5<<endl;

    l1 += l2;
    l2 *= l2;
    l3 *= l4;    
    cout<<l1<<l2<<l3<<endl;

    cout<<l1;
    l1.printStats();
    cout<<l2;
    l2.printStats();
    cout<<l3;
    l3.printStats();
    cout<<l4;
    l4.printStats();
    cout<<l5;
    l5.printStats();
}

void EllipseConstructor(){
    polynomial* u1 = new ellipse('x','y');
    cout <<"default:"<< *u1;

    std::string termText[] = {
        "y^2",
        "x^2",
        "-6",
        "-9"
    };
    term** t = new term*[4];
    for (int i = 0; i < 4; i++) {
        t[i] = new term(termText[i].c_str());
    }
    //cout<<"m"<<__LINE__;
    polynomial* u2 = new ellipse(t,4);
    cout <<"term array:"<< *u2;

    polynomial* u6 = new ellipse(*t[0]);
    cout<<"term:"<<*u6;

    for (int i = 0; i < 4; i++) 
        delete t[i];
    delete[] t;

    polynomial* u3 = new ellipse("x^2*x^2 + 2*x*x + 1 + x^-3");
    cout<<"string:"<<*u3;

    polynomial* u4 = new ellipse(*u3);
    cout<<"copy poly:"<<*u4;

    ellipse u("+c^2* + *y^2 + -1");
    ellipse ub("3");

    polynomial* u5 = new ellipse(u);
    cout<<"copy univ:"<<*u5;

    ub = u;

    cout<<"assign:"<<ub;

    (*u6)[-1];
    delete u1;
    delete u2;
    delete u3;
    delete u4;
    delete u5;
    delete u6;

}

void testEllipse(){
    cout<<"Ellipse constructor===============================\n";
    EllipseConstructor();
    cout<<"Ellipse test======================================\n";
    ellipse l1("9*x^2 + 9*y^2 - 8");
    ellipse l2("7*x^2 + 7*y^2 + 4");
    ellipse l3("7*x^2 + 6*y^2 - 4");
    ellipse l4("-6 + 9");
    ellipse l5("x^2 - 1");
    cout<<l1<<l2<<l3<<l4<<l5<<endl;

    l1 += l2;
    l2 *= l2;    
    cout<<l1<<l2<<l3<<endl;

    cout<<l1;
    l1.printStats();
    cout<<l2;
    l2.printStats();
    cout<<l3;
    l3.printStats();
    cout<<l4;
    l4.printStats();
    cout<<l5;
    l5.printStats();
}

int main(){
    testTerm();
     testUnivariate();
    testLinear();
    testQuadratic();
    testBivariate();
    testCircle();
    testEllipse();
    // bivariate b1("x^2 + 5");
    // bivariate b2("-5");
    // bivariate b3("x^2 + 0");
    // bivariate b4("0");


    // b1+= b2;
    // b3-= b4;
    // cout << b1 << b2 << b3;
    // return 0;

    // term t1("6*x^4*y^2");
    // cout << t1;
    // cout << t1("x=0");

    // bivariate t2("6*x^4*y^2 + y^2 + 6*x + 8");
    // if (t2.isBivariate())
    //     cout << "True\n";
    // else
    //     cout << "False\n";
    // cout << t2;
    // polynomial* p = t2("x=0");
    // cout << *p;

    // univariate u("0");
    // std::istringstream iss("+x^3 + 7 + x");
    // iss >> u;
    // cout << u;

    // bivariate t2(3,'x','x');
    // cout << t2;
    // if (t2.isBivariate())
    //     cout << "True\n";
    // else
    //     cout << "False\n";

//     bivariate b1("2*b + a^2  + 5");
//    // bivariate b2("5");
//    // bivariate b3("x^2");
//     cout << b1;
//     cout << *b1("x=2 a=4");
   // cout << b1 << b2 << b3;


  //  b2+=b3;

  //  cout << b2;
}