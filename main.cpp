#include <QCoreApplication>
#include <iostream>
#include <QTimer>

#include <QRandomGenerator>
//using namespace std;
using std::cout, std::endl;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString str = "Hello";
    cout << "abc123" << endl;
    cout << str.toStdString().data() << endl;

    /*
     * double QRandomGenerator::bounded(double highest),
     * Generates one random double in the range between 0 (inclusive) and highest (exclusive).
     * This function is equivalent to and is implemented as: return generateDouble() * highest;
     *
     * double QRandomGenerator::generateDouble(),
     * Generates one random qreal in the canonical range [0, 1) (that is, inclusive of zero and exclusive of 1).
    */

    //test function
    //qreal yValue(0);
    qreal b1(0);
    int j(1);
    for(int i(0); i<1000; i++){
        //b1 = QRandomGenerator::global()->bounded(10 / (qreal) 7);
        //b1 = QRandomGenerator::global()->generateDouble() * ((qreal) 10 / (qreal) 7);
        b1 = (j + QRandomGenerator::global()->generateDouble()) * ((qreal) 10 / (qreal) 7);
        cout << b1 << "\t";
        if(i+1 % 10 ==0)
            cout << endl;
        if(b1 > 2.86){
            cout << "find > num";
            break;
        }
    }

    // test end

    //Add this, otherwise the Qt console program will not end automatically
    QTimer t;
    t.connect(&t, SIGNAL(timeout()), &a, SLOT(quit()));
    t.start(20);  // 20millisecond

    return a.exec();
}

