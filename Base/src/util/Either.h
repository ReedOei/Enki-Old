//
// Created by roei on 29/10/18.
//

#ifndef BASE_EITHER_H
#define BASE_EITHER_H

#include <functional>
#include <memory>

namespace enki {
    template <typename A, typename B>
    class Either {
    public:
        explicit Either(const A* a) : a(a), b(nullptr) {}
        explicit Either(const B* b) : a(nullptr), b(b) {}

        virtual ~Either() {

        }

        template <typename T>
        const T* either(const std::function<const T*(const A*)> &af, const std::function<const T*(const B*)> &bf) const {
            if (isRight()) {
                return af(getLeft());
            } else {
                return bf(getRight());
            }
        }

        const A* fromLeft(const A* a) const {
            if (this->a != nullptr) {
                return this->a;
            } else {
                return a;
            }
        }

        const B* fromRight(const B* b) const {
            if (this->b != nullptr) {
                return this->b;
            } else {
                return b;
            }
        }

        bool isLeft() const {
            return a != nullptr;
        }

        bool isRight() const {
            return b != nullptr;
        }

        const A* getLeft() const {
            return a;
        }

        const B* getRight() const {
            return b;
        }

        template <typename C, typename D>
        const Either<C, D> bimap(const std::function<const C*(const A*)> &l, const std::function<const D*(const B*)> &r) const {
            if (isLeft()) {
                return Either(l(a));
            } else {
                return Either(r(b));
            }
        }

        template <typename C>
        const Either<C, B> lmap(const std::function<const C*(const A*)> &l) {
            return bimap(l, [](auto x) { return x; });
        }

        template <typename D>
        const Either<A, D> rmap(const std::function<const D*(const B*)> &r) {
            return bimap([](auto x) { return x; }, r);
        }

    private:
        const A* a;
        const B* b;
    };
}

#endif //BASE_EITHER_H
