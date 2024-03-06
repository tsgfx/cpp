// 共享内存内的循环队列
#include "_public.h"

int main()
{
    using ElemType = int;

    // 初始化共享内存
    int shmid = shmget(0x5005, sizeof(squeue<ElemType, 5>), 0640 | IPC_CREAT);
    if (shmid == -1)
    {
        cout << "shmget(0x5005) failed.\n";
        return -1;
    }

    // 把共享内存连接到当前进程的地址空间
    squeue<ElemType, 5> *QQ = (squeue<ElemType, 5> *)shmat(shmid, 0, 0);
    if (QQ == (void *)-1)
    {
        cout << "shmat() failed. \n";
        return -1;
    }

    // 初始化循环队列
    QQ->init();
    ElemType elem;
    cout << "元素（1、2、3）入队。\n";
    elem = 1;
    QQ->push(elem);
    elem = 2;
    QQ->push(elem);
    elem = 3;
    QQ->push(elem);

    cout << "队列的长度是" << QQ->size() << endl;
    QQ->printQueue();

    elem = QQ->front();
    QQ->pop();
    cout << "出队的元素值为" << elem << endl;
    elem = QQ->front();
    QQ->pop();
    cout << "出队的元素值为" << elem << endl;

    cout << "队列的长度是" << QQ->size() << endl;
    QQ->printQueue();

    cout << "元素（11、12、13、14、15）入队。\n";
    elem = 11;
    QQ->push(elem);
    elem = 12;
    QQ->push(elem);
    elem = 13;
    QQ->push(elem);
    elem = 14;
    QQ->push(elem);
    elem = 15;
    QQ->push(elem);

    cout << "队列的长度是" << QQ->size() << endl;
    QQ->printQueue();

    shmdt(QQ); //把共享内存从当前进程中分离
    //ipcs -m 查看共享内存
    //ipcrm -m shmid 删除指定共享内存
}