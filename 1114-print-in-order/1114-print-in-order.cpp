class Foo {
private:
    std::mutex _q_m;
    std::condition_variable _cv;
    bool firstFinished = false;
    bool secondFinished = false;
public:
    Foo() {}

    void first(function<void()> printFirst) {
        std::unique_lock<std::mutex> lock(this->_q_m);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        firstFinished = true;
        lock.unlock();
        _cv.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(this->_q_m);
        
        while (!firstFinished) {
            _cv.wait(lock);
        }
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        secondFinished = true;
        lock.unlock();
        _cv.notify_all();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lock(this->_q_m);
        
        while (!secondFinished) {
            _cv.wait(lock);
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        lock.unlock();
    }
};