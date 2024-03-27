// 栈内存内的循环队列
#include "_public.h"
int main()
{
    using ElemType = int;
    squeue<ElemType, 5> QQ;
    ElemType elem;

    cout << "元素(1,2,3)入队。\n";
    elem = 1;
    QQ.push(elem);
    elem = 2;
    QQ.push(elem);
    elem = 3;
    QQ.push(elem);

    cout << "队列的长度为: " << QQ.size() << endl;
    QQ.printQueue();

    elem = QQ.front();
    QQ.pop();
    cout << "出队的元素值为" << elem << endl;
    elem = QQ.front();
    QQ.pop();
    cout << "出队的元素值为" << elem << endl;

    cout << "队列的长度是" << QQ.size() << endl;
    QQ.printQueue();

    cout << "元素(11、12、13、14、15)入队.\n";
    elem = 11;
    QQ.push(elem);
    elem = 12;
    QQ.push(elem);
    elem = 13;
    QQ.push(elem);
    elem = 14;
    QQ.push(elem);
    elem = 15;
    QQ.push(elem);

    cout << "队列的长度是" << QQ.size() << endl;
    QQ.printQueue();
}