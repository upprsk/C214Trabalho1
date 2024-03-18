#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers.hpp>
#include <catch2/matchers/catch_matchers_exception.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

#include "lib.hpp"
#include "nlohmann/json.hpp"  // IWYU pragma: keep

class MockHorarioService : public lib::IHorarioService {
public:
    MockHorarioService(std::string const& s) : s{s} {}

    auto get_horario() -> std::string override { return s; }

private:
    std::string s;
};

TEST_CASE("sala 1", "[sucesso]") {
    nlohmann::json obj{
        {     "nomeDoProfessor",       "A"},
        {"horarioDeAtendimento",   "11:30"},
        {             "periodo", "noturno"},
        {                "sala",       "1"},
        {              "predio",     {"1"}},
    };

    lib::Something something{std::make_unique<MockHorarioService>(obj.dump())};

    auto value = something.get_atendimento("A");

    REQUIRE(value.nome == "A");
    REQUIRE(value.horario == "11:30");
    REQUIRE(value.periodo == "noturno");
    REQUIRE(value.sala == "1");
    REQUIRE(value.predio.size() == 1);
    REQUIRE(value.predio.at(0) == "1");
}

TEST_CASE("sala 2", "[sucesso]") {
    nlohmann::json obj{
        {     "nomeDoProfessor",       "A"},
        {"horarioDeAtendimento",   "11:30"},
        {             "periodo", "noturno"},
        {                "sala",       "2"},
        {              "predio",     {"1"}},
    };

    lib::Something something{std::make_unique<MockHorarioService>(obj.dump())};

    auto value = something.get_atendimento("A");

    REQUIRE(value.nome == "A");
    REQUIRE(value.horario == "11:30");
    REQUIRE(value.periodo == "noturno");
    REQUIRE(value.sala == "2");
    REQUIRE(value.predio.size() == 1);
    REQUIRE(value.predio.at(0) == "1");
}

TEST_CASE("sala 5", "[sucesso]") {
    nlohmann::json obj{
        {     "nomeDoProfessor",       "A"},
        {"horarioDeAtendimento",   "11:30"},
        {             "periodo", "noturno"},
        {                "sala",       "5"},
        {              "predio",     {"1"}},
    };

    lib::Something something{std::make_unique<MockHorarioService>(obj.dump())};

    auto value = something.get_atendimento("A");

    REQUIRE(value.nome == "A");
    REQUIRE(value.horario == "11:30");
    REQUIRE(value.periodo == "noturno");
    REQUIRE(value.sala == "5");
    REQUIRE(value.predio.size() == 1);
    REQUIRE(value.predio.at(0) == "1");
}

TEST_CASE("sala 6", "[sucesso]") {
    nlohmann::json obj{
        {     "nomeDoProfessor",       "A"},
        {"horarioDeAtendimento",   "11:30"},
        {             "periodo", "noturno"},
        {                "sala",       "6"},
        {              "predio",     {"2"}},
    };

    lib::Something something{std::make_unique<MockHorarioService>(obj.dump())};

    auto value = something.get_atendimento("A");

    REQUIRE(value.nome == "A");
    REQUIRE(value.horario == "11:30");
    REQUIRE(value.periodo == "noturno");
    REQUIRE(value.sala == "6");
    REQUIRE(value.predio.size() == 1);
    REQUIRE(value.predio.at(0) == "2");
}

TEST_CASE("sala 11", "[sucesso]") {
    nlohmann::json obj{
        {     "nomeDoProfessor",       "A"},
        {"horarioDeAtendimento",   "11:30"},
        {             "periodo", "noturno"},
        {                "sala",      "11"},
        {              "predio",     {"3"}},
    };

    lib::Something something{std::make_unique<MockHorarioService>(obj.dump())};

    auto value = something.get_atendimento("A");

    REQUIRE(value.nome == "A");
    REQUIRE(value.horario == "11:30");
    REQUIRE(value.periodo == "noturno");
    REQUIRE(value.sala == "11");
    REQUIRE(value.predio.size() == 1);
    REQUIRE(value.predio.at(0) == "3");
}

TEST_CASE("sala 16", "[sucesso]") {
    nlohmann::json obj{
        {     "nomeDoProfessor",       "A"},
        {"horarioDeAtendimento",   "11:30"},
        {             "periodo", "noturno"},
        {                "sala",      "16"},
        {              "predio",     {"4"}},
    };

    lib::Something something{std::make_unique<MockHorarioService>(obj.dump())};

    auto value = something.get_atendimento("A");

    REQUIRE(value.nome == "A");
    REQUIRE(value.horario == "11:30");
    REQUIRE(value.periodo == "noturno");
    REQUIRE(value.sala == "16");
    REQUIRE(value.predio.size() == 1);
    REQUIRE(value.predio.at(0) == "4");
}

TEST_CASE("sala 99", "[sucesso]") {
    nlohmann::json obj{
        {     "nomeDoProfessor",       "A"},
        {"horarioDeAtendimento",   "11:30"},
        {             "periodo", "noturno"},
        {                "sala",      "99"},
        {              "predio",    {"20"}},
    };

    lib::Something something{std::make_unique<MockHorarioService>(obj.dump())};

    auto value = something.get_atendimento("A");

    REQUIRE(value.nome == "A");
    REQUIRE(value.horario == "11:30");
    REQUIRE(value.periodo == "noturno");
    REQUIRE(value.sala == "99");
    REQUIRE(value.predio.size() == 1);
    REQUIRE(value.predio.at(0) == "20");
}

TEST_CASE("Periodo diurno", "[sucesso]") {
    nlohmann::json obj{
        {     "nomeDoProfessor",      "A"},
        {"horarioDeAtendimento",  "11:30"},
        {             "periodo", "diurno"},
        {                "sala",     "16"},
        {              "predio",    {"4"}},
    };

    lib::Something something{std::make_unique<MockHorarioService>(obj.dump())};

    auto value = something.get_atendimento("A");

    REQUIRE(value.nome == "A");
    REQUIRE(value.horario == "11:30");
    REQUIRE(value.periodo == "diurno");
    REQUIRE(value.sala == "16");
    REQUIRE(value.predio.size() == 1);
    REQUIRE(value.predio.at(0) == "4");
}

TEST_CASE("Formato de horario", "[sucesso]") {
    nlohmann::json obj{
        {     "nomeDoProfessor",       "A"},
        {"horarioDeAtendimento",   "11:30"},
        {             "periodo", "noturno"},
        {                "sala",       "1"},
        {              "predio",     {"2"}},
    };

    lib::Something something{std::make_unique<MockHorarioService>(obj.dump())};

    auto value = something.get_atendimento("A");

    using namespace Catch::Matchers;

    REQUIRE_THAT(value.horario, Matches(R"(\d?\d:\d\d)"));
}

TEST_CASE("Formato de horario manha", "[sucesso]") {
    nlohmann::json obj{
        {     "nomeDoProfessor",       "A"},
        {"horarioDeAtendimento",    "9:30"},
        {             "periodo", "noturno"},
        {                "sala",       "1"},
        {              "predio",     {"2"}},
    };

    lib::Something something{std::make_unique<MockHorarioService>(obj.dump())};

    auto value = something.get_atendimento("A");

    using namespace Catch::Matchers;

    REQUIRE_THAT(value.horario, Matches(R"(\d?\d:\d\d)"));
}

// =============================================================================
// Testes de falhas
// =============================================================================

TEST_CASE("nome incorreto", "[falha]") {
    nlohmann::json obj{
        {     "nomeDoProfessor",       "B"},
        {"horarioDeAtendimento",   "11:30"},
        {             "periodo", "noturno"},
        {                "sala",      "11"},
        {              "predio",     {"3"}},
    };

    lib::Something something{std::make_unique<MockHorarioService>(obj.dump())};

    auto value = something.get_atendimento("A");

    REQUIRE(value.nome != "A");
}

TEST_CASE("sala 1 incorreta", "[falha]") {
    nlohmann::json obj{
        {     "nomeDoProfessor",       "A"},
        {"horarioDeAtendimento",   "11:30"},
        {             "periodo", "noturno"},
        {                "sala",       "1"},
        {              "predio",     {"2"}},
    };

    lib::Something something{std::make_unique<MockHorarioService>(obj.dump())};

    auto value = something.get_atendimento("A");

    REQUIRE(value.sala != "11");
    REQUIRE(value.predio.size() == 1);
    REQUIRE(value.predio.at(0) != "3");
}

TEST_CASE("Formato de horario incorreto", "[falha]") {
    nlohmann::json obj{
        {     "nomeDoProfessor",       "A"},
        {"horarioDeAtendimento",   "11,30"},
        {             "periodo", "noturno"},
        {                "sala",       "1"},
        {              "predio",     {"1"}},
    };

    lib::Something something{std::make_unique<MockHorarioService>(obj.dump())};

    auto value = something.get_atendimento("A");

    using namespace Catch::Matchers;

    REQUIRE_THAT(value.horario, !Matches(R"(\d?\d:\d\d)"));
}

TEST_CASE("Array predio vazio", "[falha]") {
    nlohmann::json obj{
        {     "nomeDoProfessor",                     "A"},
        {"horarioDeAtendimento",                 "11:30"},
        {             "periodo",               "noturno"},
        {                "sala",                     "1"},
        {              "predio", nlohmann::json::array()},
    };

    lib::Something something{std::make_unique<MockHorarioService>(obj.dump())};

    auto value = something.get_atendimento("A");

    using namespace Catch::Matchers;

    REQUIRE(value.predio.size() != 1);
}

TEST_CASE("Array predio grande", "[falha]") {
    nlohmann::json obj{
        {     "nomeDoProfessor",        "A"},
        {"horarioDeAtendimento",    "11:30"},
        {             "periodo",  "noturno"},
        {                "sala",        "1"},
        {              "predio", {"1", "2"}},
    };

    lib::Something something{std::make_unique<MockHorarioService>(obj.dump())};

    auto value = something.get_atendimento("A");

    using namespace Catch::Matchers;

    REQUIRE(value.predio.size() != 1);
}

TEST_CASE("Periodo incorreto", "[falha]") {
    nlohmann::json obj{
        {     "nomeDoProfessor",      "A"},
        {"horarioDeAtendimento",  "11:30"},
        {             "periodo", "banana"},
        {                "sala",      "8"},
        {              "predio",    {"2"}},
    };

    lib::Something something{std::make_unique<MockHorarioService>(obj.dump())};

    auto value = something.get_atendimento("A");

    using namespace Catch::Matchers;

    REQUIRE(value.periodo != "noturno");
}

TEST_CASE("JSON invalido", "[falha]") {
    lib::Something something{std::make_unique<MockHorarioService>("{")};

    using namespace Catch::Matchers;

    REQUIRE_THROWS_MATCHES(
        something.get_atendimento("A"), nlohmann::json::parse_error,
        MessageMatches(StartsWith(
            "[json.exception.parse_error.101] parse error at line ")));
}

TEST_CASE("JSON tipos errados", "[falha]") {
    nlohmann::json obj{
        {     "nomeDoProfessor",       "A"},
        {"horarioDeAtendimento",      1130},
        {             "periodo", "noturno"},
        {                "sala",      "11"},
        {              "predio",     {"3"}},
    };

    lib::Something something{std::make_unique<MockHorarioService>(obj.dump())};

    using namespace Catch::Matchers;

    REQUIRE_THROWS_MATCHES(
        something.get_atendimento("A"), nlohmann::json::type_error,
        MessageMatches(StartsWith("[json.exception.type_error.302] type must "
                                  "be string, but is number")));
}

TEST_CASE("JSON incompleto", "[falha]") {
    nlohmann::json obj{
        {"nomeDoProfessor",       "A"},
        {        "periodo", "noturno"},
        {           "sala",      "11"},
        {         "predio",     {"3"}},
    };

    lib::Something something{std::make_unique<MockHorarioService>(obj.dump())};

    using namespace Catch::Matchers;

    REQUIRE_THROWS_MATCHES(
        something.get_atendimento("A"), nlohmann::json::type_error,
        MessageMatches(StartsWith("[json.exception.type_error.302] type must "
                                  "be string, but is null")));
}

TEST_CASE("JSON campos errados", "[falha]") {
    nlohmann::json obj{
        {     "nomeDoProfessor",       "A"},
        {"horarioDeAtendimento",   "11:30"},
        {             "Periodo", "noturno"},
        {                "sala",      "11"},
        {              "predio",     {"3"}},
    };

    lib::Something something{std::make_unique<MockHorarioService>(obj.dump())};

    using namespace Catch::Matchers;

    REQUIRE_THROWS_MATCHES(
        something.get_atendimento("A"), nlohmann::json::type_error,
        MessageMatches(StartsWith("[json.exception.type_error.302] type must "
                                  "be string, but is null")));
}
