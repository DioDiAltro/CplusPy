#ifndef CLikePy_h
#define CLikePy_h

#include <utility>

// Classe per la Lista
template <typename... Types>
class List;

// Specializzazione per una lista vuota
template <>
class List<> {};

// Specializzazione per una lista con più elementi 
template <typename Head, typename... Tail>
class List<Head, Tail...> {
    Head head;
    List<Tail...> tail;

public:
    List(Head& h, Tail&... t) : head(h), tail(t...) {}
};
#endif
    