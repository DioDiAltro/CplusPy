#ifndef typeTyple_h
#define typeTyple_h

#include <stdexcept>
#include <utility>

// Classe base per la tupla
template <typename... Types>
class Tuple;

// Specializzazione per la tupla vuota
template <>
class Tuple<> {
    public:
        // Funzione per 
        void get(std::size_t) const {
            throw std::out_of_range("Index out of range for Tuple.");

        }

};

// Specializzazione per la tupla con un solo elemento
template <typename Head, typename... Tail>
class Tuple<Head, Tail...> {
    private:
        Head head;
        Tuple<Tail...> tail;

    public:
        // Costruttore per la classe Tuple
        Tuple (const Head& h, const Tail&... t) : head(h), tail(t...) {}

        // Funzione per accedere a un elemento tramite indice
        // Funzione per accedere a un elemento tramite indice
        Head get(std::size_t Index) const {
            if (Index == 0)
                return head;  // Restituisce il primo elemento

            else if constexpr (sizeof...(Tail) > 0)
                return tail.get(Index - 1);  // Passa alla coda

            else 
                throw std::out_of_range("Index out of range for Tuple.");

            

        }

};

 

#endif  