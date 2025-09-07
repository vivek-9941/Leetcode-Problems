class Foo {
    private int step =1;
    public Foo() {
        
    }

    public synchronized void first(Runnable printFirst) throws InterruptedException {
        while(step != 1){
            wait();
        }
        printFirst.run();
        step = 2;
        notifyAll();
        // printFirst.run() outputs "first". Do not change or remove this line.
    }

    public synchronized void second(Runnable printSecond) throws InterruptedException {
        while(step != 2){
            wait();
        }
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        step = 3;
        notifyAll();
    }

    public synchronized void third(Runnable printThird) throws InterruptedException {
        while(step != 3){
            wait();
        }

        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}