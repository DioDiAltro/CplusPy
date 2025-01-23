#ifndef TUPLE_H
#define TUPLE_H

#include <stdexcept>
#include <type_traits>
#include <utility>
#include <iostream>

// Dichiarazione anticipata del template
template <typename, typename...>
class TupleStorage;

// Caso base: un solo elemento
template <typename T>
class TupleStorage<T> {
public:
    T value;

    explicit TupleStorage(const T& val) : value(val) {}

    T& get(size_t index) {
        if (index == 0) return value;
        throw std::out_of_range("Indice fuori dai limiti!");
    }

    const T& get(size_t index) const {
        if (index == 0) return value;
        throw std::out_of_range("Indice fuori dai limiti!");
    }
};

// Caso ricorsivo con più elementi
template <typename Head, typename... Tail>
class TupleStorage<Head, Tail...> {
private:
    Head head;
    TupleStorage<Tail...> tail;

public:
    // Costruttore ricorsivo
    TupleStorage(const Head& h, const Tail&... t) 
        : head(h), tail(t...) {}

    // Versione non const
    auto& get(size_t index) {
        return index == 0 ? head : tail.get(index - 1);
    }

    // Versione const
    const auto& get(size_t index) const {
        return index == 0 ? head : tail.get(index - 1);
    }
};

// Classe Tuple: interfaccia utente
template <typename... Types>
class Tuple {
private:
    TupleStorage<Types...> storage;

public:
    // Costruttore
    Tuple(const Types&... args) : storage(args...) {}

    // Accesso agli elementi
    auto& get(size_t index) {
        return storage.get(index);
    }

    const auto& get(size_t index) const {
        return storage.get(index);
    }

    // Dimensione della tuple
    constexpr size_t size() const {
        return sizeof...(Types);
    }

    // Stampa della tuple
    friend std::ostream& operator<<(std::ostream& os, const Tuple& t) {
        os << "(";
        t.print_impl(os, std::index_sequence_for<Types...>{});
        os << ")";
        return os;
    }

private:
    // Helper per la stampa
    template<size_t... Indices>
    void print_impl(std::ostream& os, std::index_sequence<Indices...>) const {
        ((os << (Indices > 0 ? ", " : "") << get(Indices)), ...);
    }
};

// Funzione helper per creare tuple
template<typename... Types>
Tuple<std::decay_t<Types>...> make_tuple(Types&&... args) {
    return Tuple<std::decay_t<Types>...>(std::forward<Types>(args)...);
}

#endif // TUPLE_H