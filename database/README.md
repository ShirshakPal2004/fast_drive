# Fast Drive Database

This directory contains the database schema, seed data, and future database migrations for Fast Drive.

## Database

MySQL

## Current Tables

### users

Stores registered user accounts.

### folders

Stores folder metadata and folder hierarchy.

### files

Stores file metadata and references to files stored on the filesystem.

## Schema

The initial database schema is available in:

`schema.sql`

## Storage Model

Fast Drive does not store uploaded files directly inside MySQL.

MySQL stores file metadata and the path to the physical file, while the actual files are stored separately in the application's storage directory.
