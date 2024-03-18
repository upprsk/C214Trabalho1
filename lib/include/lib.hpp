#pragma once

#include <memory>
#include <vector>

#include "common.hpp"

namespace lib {

class IHorarioService {
public:
    virtual auto get_horario() -> string = 0;
};

struct Horario {
    string              nome;
    string              horario;
    string              periodo;
    string              sala;
    std::vector<string> predio;
};

class Something {
public:
    Something(std::unique_ptr<IHorarioService> s) : service{std::move(s)} {}

    auto get_atendimento(string const& name) -> Horario;

private:
    std::unique_ptr<IHorarioService> service;
};

}  // namespace lib
