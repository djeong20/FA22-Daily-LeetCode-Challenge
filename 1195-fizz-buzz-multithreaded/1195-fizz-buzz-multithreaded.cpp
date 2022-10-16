class FizzBuzz {
private:
    int n;
    int curr;
    std::mutex _m;
    std::condition_variable _cv;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->curr = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (true) {
            std::unique_lock<std::mutex> lock(this->_m);
        
            while (this->curr <= this->n && !(this->curr % 3 == 0 && this->curr % 5 != 0)) {
                _cv.wait(lock);
            }
            if (this->n < this->curr) return;

            printFizz();

            this->curr += 1;

            lock.unlock();
            _cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (true) {
            std::unique_lock<std::mutex> lock(this->_m);

            while (this->curr <= this->n && !(this->curr % 3 != 0 && this->curr % 5 == 0)) {
                _cv.wait(lock);
            }
            if (this->n < this->curr) return;

            printBuzz();

            this->curr += 1;

            lock.unlock();
            _cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            std::unique_lock<std::mutex> lock(this->_m);

            while (this->curr <= this->n && !(this->curr % 3 == 0 && this->curr % 5 == 0)) {
                _cv.wait(lock);
            }
            if (this->n < this->curr) return;

            printFizzBuzz();

            this->curr += 1;

            lock.unlock();
            _cv.notify_all();  
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (true) {
            std::unique_lock<std::mutex> lock(this->_m);

            while (this->curr <= this->n && !(this->curr % 3 != 0 && this->curr % 5 != 0)) {
                _cv.wait(lock);
            }
            if (this->n < this->curr) return;

            printNumber(this->curr);

            this->curr += 1;

            lock.unlock();
            _cv.notify_all();
        }
    }
};