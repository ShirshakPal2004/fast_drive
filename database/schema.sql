CREATE DATABASE IF NOT EXISTS fast_drive;

USE fast_drive;

-- =========================================
-- Users
-- =========================================

CREATE TABLE users (
    id BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,

    name VARCHAR(100) NOT NULL,

    email VARCHAR(255) NOT NULL UNIQUE,

    password_hash VARCHAR(255) NOT NULL,

    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,

    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
        ON UPDATE CURRENT_TIMESTAMP
);


-- =========================================
-- Folders
-- =========================================

CREATE TABLE folders (
    id BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,

    owner_id BIGINT UNSIGNED NOT NULL,

    parent_folder_id BIGINT UNSIGNED NULL,

    name VARCHAR(255) NOT NULL,

    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,

    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
        ON UPDATE CURRENT_TIMESTAMP,

    CONSTRAINT fk_folders_owner
        FOREIGN KEY (owner_id)
        REFERENCES users(id)
        ON DELETE CASCADE,

    CONSTRAINT fk_folders_parent
        FOREIGN KEY (parent_folder_id)
        REFERENCES folders(id)
        ON DELETE CASCADE
);


-- =========================================
-- Files
-- =========================================

CREATE TABLE files (
    id BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,

    owner_id BIGINT UNSIGNED NOT NULL,

    parent_folder_id BIGINT UNSIGNED NULL,

    name VARCHAR(255) NOT NULL,

    storage_path VARCHAR(500) NOT NULL,

    mime_type VARCHAR(100),

    size BIGINT UNSIGNED NOT NULL DEFAULT 0,

    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,

    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
        ON UPDATE CURRENT_TIMESTAMP,

    CONSTRAINT fk_files_owner
        FOREIGN KEY (owner_id)
        REFERENCES users(id)
        ON DELETE CASCADE,

    CONSTRAINT fk_files_folder
        FOREIGN KEY (parent_folder_id)
        REFERENCES folders(id)
        ON DELETE CASCADE
);


-- =========================================
-- Indexes
-- =========================================

CREATE INDEX idx_folders_owner
    ON folders(owner_id);

CREATE INDEX idx_folders_parent
    ON folders(parent_folder_id);

CREATE INDEX idx_files_owner
    ON files(owner_id);

CREATE INDEX idx_files_parent
    ON files(parent_folder_id);


-- =========================================
-- Sessions
-- =========================================

CREATE TABLE sessions (
    id BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,

    user_id BIGINT UNSIGNED NOT NULL,

    token_hash CHAR(64) NOT NULL UNIQUE,

    expires_at TIMESTAMP NOT NULL,

    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,

    CONSTRAINT fk_sessions_user
        FOREIGN KEY (user_id)
        REFERENCES users(id)
        ON DELETE CASCADE
);

CREATE INDEX idx_sessions_user
    ON sessions(user_id);

CREATE INDEX idx_sessions_token
    ON sessions(token_hash);

CREATE INDEX idx_sessions_expiry
    ON sessions(expires_at);
