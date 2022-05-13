#include "funciones.h"

bool enLista(const std::string & s, const std::vector<std::string> & v) {
    for (const auto & elem : v) {
        if (elem == s)
            return true;
    }
    return false;
}
