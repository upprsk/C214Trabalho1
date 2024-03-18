#include "lib.hpp"

#include "nlohmann/json.hpp"

namespace lib {

auto Something::get_atendimento(string const& name) -> Horario {
    auto horario = nlohmann::json::parse(service->get_horario());

    return Horario{
        .nome = horario["nomeDoProfessor"].get<string>(),
        .horario = horario["horarioDeAtendimento"].get<string>(),
        .periodo = horario["periodo"].get<string>(),
        .sala = horario["sala"].get<string>(),
        .predio = horario["predio"],  // :)
    };
}
}  // namespace lib
