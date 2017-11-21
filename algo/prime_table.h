#ifndef PRIME_TABLE_H_
#define PRIME_TABLE_H_

#include <algorithm>

namespace algo {

    class PrimeTable {
    public:
        virtual ~PrimeTable() {}
        virtual bool IsPrime(int x) const = 0;
        virtual int NextPrime(int p) const = 0;
    };

    class OnlinePrimeTable : public PrimeTable {
    public:
        virtual bool IsPrime(int x) const {
            if (x <= 1) {
                return false;
            }

            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) {
                    return false;
                }
            }

            return true;
        }
        virtual int NextPrime(int p) const {
            for (int x = p + 1; x > 0; x++) {
                if (IsPrime(x)) {
                    return x;
                }
            }
            return -1;
        }
    };

    class OfflinePrimeTable : public PrimeTable {
    public:
        explicit OfflinePrimeTable(int size)
            : size_(size),
              prime_(new bool[size_ + 1]) 
        {
            ::std::fill(prime_, prime_ + size_, true);   // -O2, faster than memset
            prime_[0] = prime_[1] = false;

            for (int i = 2; i <= size_; i++) {
                if (!prime_[i]) {
                    continue;
                }
                for (int j = i * 2; j <= size_; j += i) {
                    prime_[j] = false;
                }
            }
        }

        ~OfflinePrimeTable() {
            delete[] prime_;
        }

        virtual bool IsPrime(int x) const {
            return (0 <= x && x <= size_ && prime_[x]);
        }
        virtual int NextPrime(int p) const {
            for (int x = p + 1; x <= size_; x++) {
                if (prime_[x]) {
                    return x;
                }
            }
            
            return -1;
        }

    private:
        const int size_;
        bool* const prime_;
    };
}
#endif /* PRIME_TABLE_H_ */
