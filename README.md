# Fast Drive

A Google Drive-inspired file storage system built with **React, C++, and MySQL**.

Fast Drive is a full-stack software engineering project that provides users with a platform to upload, store, organize, download, and share files through a web-based interface.

---

## Tech Stack

### Frontend
- React
- HTML
- CSS
- JavaScript

### Backend
- C++
- Crow
- REST APIs

### Database
- MySQL

### Storage
- Local filesystem

### Development
- GitHub
- CMake

---

## Architecture


┌─────────────────────┐
│      React UI       │
│   HTML / CSS / JS   │
└──────────┬──────────┘
           │
           │ HTTP / REST API
           ▼
┌─────────────────────┐
│     C++ Backend     │
│                     │
│ Routes              │
│ Controllers         │
│ Services            │
│ Repositories        │
└───────┬───────┬─────┘
        │       │
        │       │
        ▼       ▼
   ┌────────┐ ┌──────────────┐
   │ MySQL  │ │ File Storage │
   │        │ │              │
   │Metadata│ │ Actual Files │
   └────────┘ └──────────────┘

   ## Planned Features
 User registration and login
 File upload
 File download
 File deletion
 File renaming
 Folder creation
 Nested folders
 Move files between folders
 File search
 File sharing
 File permissions
 Starred files
 Trash
 File metadata
 API validation
 Unit testing
 Docker support

## Project Structure

fast_drive/
│
├── frontend/       # React frontend
├── backend/        # C++ backend
├── database/       # MySQL schema and migrations
├── storage/        # Local file storage
├── docs/           # Architecture and API documentation
│
├── .gitignore
└── README.md

## Development

This project is being developed collaboratively by two developers using GitHub.

Development will follow feature-based branches and pull requests to keep the codebase organized and maintainable.

## Status

🚧 Currently under development


