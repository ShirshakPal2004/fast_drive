#include "repositories/UserRepository.h"

#include <mysqlx/xdevapi.h>

UserRepository::UserRepository(DatabaseConnection& database)
    : database(database) {
}

bool UserRepository::emailExists(const std::string& email) {

    auto& session = database.getSession();

    auto schema = session.getSchema("fast_drive");

    auto result = schema
        .getTable("users")
        .select("id")
        .where("email = :email")
        .bind("email", email)
        .execute();

    return result.count() > 0;
}

User UserRepository::createUser(
    const std::string& name,
    const std::string& email,
    const std::string& passwordHash
) {

    auto& session = database.getSession();

    auto schema = session.getSchema("fast_drive");

    auto table = schema.getTable("users");

    table.insert(
        "name",
        "email",
        "password_hash"
    )
    .values(
        name,
        email,
        passwordHash
    )
    .execute();

    auto result = table
        .select("id, name, email, password_hash")
        .where("email = :email")
        .bind("email", email)
        .execute();

    auto row = result.fetchOne();

    User user;

    user.id = row[0].get<std::uint64_t>();
    user.name = row[1].get<std::string>();
    user.email = row[2].get<std::string>();
    user.passwordHash = row[3].get<std::string>();

    return user;
}

std::optional<User> UserRepository::findByEmail(
    const std::string& email
) {

    auto& session = database.getSession();

    auto schema = session.getSchema("fast_drive");

    auto result = schema
        .getTable("users")
        .select("id, name, email, password_hash")
        .where("email = :email")
        .bind("email", email)
        .execute();

    auto row = result.fetchOne();

    if (!row) {
        return std::nullopt;
    }

    User user;

    user.id = row[0].get<std::uint64_t>();
    user.name = row[1].get<std::string>();
    user.email = row[2].get<std::string>();
    user.passwordHash = row[3].get<std::string>();

    return user;
}
