#ifndef typeTuple_h
#define typeTuple_h

#include <utility>
#include <stdexcept>  // Per gestire eccezioni come out_of_range

// Classe base per la tupla
template <typename... Types>
class Tuple;

// Specializzazione per la tupla vuota
template <>
class Tuple<> {
public:
    // L'operatore [] per la tupla vuota lancia un'eccezione se chiamato
    auto operator[](std::size_t) -> void const {
        throw std::out_of_range("Index out of range for Tuple.");
    }
};

// Specializzazione per la tupla con almeno un elemento
template <typename Head, typename... Tail>
class Tuple<Head, Tail...> {
private:
    Head head;
    Tuple<Tail...> tail;

public:
    // Costruttore
    Tuple(const Head& h, const Tail&... t) : head(h), tail(t...) {}

    // L'operatore [] per accedere agli elementi della tupla
    decltype(head) operator[](std::size_t index) const {
        if (index == 0) {
            return head;  // Restituisce il primo elemento
        } else {
            return tail[index - 1];  // Passa alla coda (elementi successivi)
        }
    }
};

#endif
