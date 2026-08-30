#include "repositories/SessionRepository.h"

#include <mysqlx/xdevapi.h>

SessionRepository::SessionRepository(
    DatabaseConnection& database
)
    : database(database) {
}

Session SessionRepository::createSession(
    std::uint64_t userId,
    const std::string& tokenHash
) {

    auto& session = database.getSession();

    auto schema = session.getSchema("fast_drive");

    auto table = schema.getTable("sessions");

    table.insert(
        "user_id",
        "token_hash",
        "expires_at"
    )
    .values(
        userId,
        tokenHash,
        mysqlx::expr(
            "DATE_ADD(NOW(), INTERVAL 7 DAY)"
        )
    )
    .execute();

    auto result = table
        .select(
            "id, user_id, token_hash, expires_at"
        )
        .where("token_hash = :token_hash")
        .bind("token_hash", tokenHash)
        .execute();

    auto row = result.fetchOne();

    Session resultSession;

    resultSession.id =
        row[0].get<std::uint64_t>();

    resultSession.userId =
        row[1].get<std::uint64_t>();

    resultSession.tokenHash =
        row[2].get<std::string>();

    resultSession.expiresAt =
        row[3].get<std::string>();

    return resultSession;
}

std::optional<Session>
SessionRepository::findValidSession(
    const std::string& tokenHash
) {

    auto& session = database.getSession();

    auto schema = session.getSchema("fast_drive");

    auto result = schema
        .getTable("sessions")
        .select(
            "id, user_id, token_hash, expires_at"
        )
        .where(
            "token_hash = :token_hash "
            "AND expires_at > NOW()"
        )
        .bind("token_hash", tokenHash)
        .execute();

    auto row = result.fetchOne();

    if (!row) {
        return std::nullopt;
    }

    Session resultSession;

    resultSession.id =
        row[0].get<std::uint64_t>();

    resultSession.userId =
        row[1].get<std::uint64_t>();

    resultSession.tokenHash =
        row[2].get<std::string>();

    resultSession.expiresAt =
        row[3].get<std::string>();

    return resultSession;
}

void SessionRepository::deleteSession(
    const std::string& tokenHash
) {

    auto& session = database.getSession();

    auto schema = session.getSchema("fast_drive");

    schema.getTable("sessions")
        .delete_()
        .where("token_hash = :token_hash")
        .bind("token_hash", tokenHash)
        .execute();
}
