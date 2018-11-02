#include <utility>

//
// Created by roei on 29/10/18.
//

#ifndef BASE_ERROR_H
#define BASE_ERROR_H

#include <string>
#include <optional>

#include "Either.h"

namespace enki {
    template <typename T>
    class Error : public Either<std::string, T> {
    public:
        explicit Error(const std::string a) : msg(std::move(a)), Either<std::string, T>(&msg) {}
        explicit Error(const T* b) : Either<std::string, T>(b) {}

        virtual ~Error() {

        }

        bool is_error() const {
            return this->isLeft();
        }

        bool succeeded() const {
            return this->isRight();
        }

        const T* ok() const {
            return this->getRight();
        }

        const std::optional<T*> opt() const {
            if (succeeded()) {
                return std::optional(this->getRight());
            } else {
                return std::optional<const T*>();
            }
        }

        template <typename U>
        const Error<U> bind(const std::function<Error<U>(const T*)> &f) const {
            if (succeeded()) {
                return f(this->getRight());
            } else {
                return Error<U>(msg);
            }
        }

        const std::string &getMsg() const {
            return msg;
        }

    private:
        std::string msg;
    };
}

#endif //BASE_ERROR_H
