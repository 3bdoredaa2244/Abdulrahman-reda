            // AbdulRahmann Reda Muhammed Fahmy          G: 2 




#include<stdio.h>
#include<malloc.h>                                                  // 7.1
void main()
{


  Summ implements Runnable {

    int a;

     Summ(int a) {
        this.a = a;
    }

     void run() {
        addRondom();
    }

     void addRondom() {
        Random rand = new Random();
        int n = rand.nextInt(10) + 1;
        printif("number   generated  = " + n);
        synchronized (this) {
            a += n;
        }
    }
}






 static void main(String[] args) {
    int base = 0;

    Summ sum2 = new Summ(base);

    Thread t1 = new Thread(sum2);
    Thread t2 = new Thread(sum2);
    Thread t3 = new Thread(sum2);
    Thread t4 = new Thread(sum2);
    Thread t5 = new Thread(sum2);

    t1.start();
    t2.start();
    t3.start();
    t4.start();
    t5.start();

    try {
        t1.join();
        t2.join();
        t3.join();
        t4.join();
        t5.join();
    } catch (InterruptedException e) {
        e.printStackTrace();
    }

    System.out.print(" the final result   = " + sum2.a);
}