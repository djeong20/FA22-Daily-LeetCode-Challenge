#include <mutex>
#include <condition_variable>

class Foo {
private:
    bool firstProcessed;
    bool secondProcessed;
    std::mutex m;
    std::condition_variable cv;
    
public:
    Foo() {
        firstProcessed = false;
        secondProcessed = false;
    }

    void first(function<void()> printFirst) {
        std::unique_lock<std::mutex> lck(m);
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        firstProcessed = true;
        lck.unlock();
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lck(m);
        
        while (!firstProcessed) {
            cv.wait(lck);
        }
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        secondProcessed = true;
        lck.unlock();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lck(m);
        
        while (!secondProcessed) {
            cv.wait(lck);
        }
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        lck.unlock();
        cv.notify_all();
    }
};